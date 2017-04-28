%{
int yylex();
void yyerror(char *s);
#include <stdio.h>
#include<stdlib.h>
#include "parser.tab.h"
extern char *yytext;
%}

%locations

%start start_

%token create
%token select_t
%token from
%token where
%token insert
%token in
%token values
%token update
%token set
%token delete
%token drop
%token alter
%token modify
%token add
%token identifier
%token data_type
%token integer
%token not
%token primary
%token left_parenthesis
%token right_parenthesis
%token equal
%token comma
%token semi_colon
%token dot
%token quote
%token table
%token into
%token column
%token null
%token key

%%

/*description of grammar*/

start_	: create_s start_		{;}
	| select_s start_		{;}
	| insert_s start_		{;}
	| update_s start_		{;}
	| delete_s start_		{;}
	| drop_s start_		{;}
	| alter_s start_		{;}	
	| create_s		{;}
	| select_s 		{;}
	| insert_s 		{;}
	| update_s 		{;}
	| delete_s 		{;}
	| drop_s 		{;}
	| alter_s		{;}
	;

create_s : create table identifier left_parenthesis column_def right_parenthesis semi_colon  {;}
          ;

column_def : identifier data_type constraints comma column_def  {;}
	| identifier data_type constraints			{;}
	| identifier data_type					{;}
	;

constraints : not null primary key    {;}
	| null primary key           {;}
	| primary key      {;}
	| not null	{;} 
	| null	{;}	
  	;

select_s : select_s1 where_ semi_colon		{;}
	| select_s1 semi_colon 		{;}
	;

select_s1 : select_t multi_col from multi_col	{;}
	;
multi_col : identifier comma multi_col		{;}
	| identifier				{;}
	;

where_ : where identifier op where_1	{;}
	;

op :      equal	{;}
	| in    {;}
	;

where_1 : integer 	{;}
	| identifier 	{;}
	| left_parenthesis select_recur right_parenthesis	{;}
	;

select_recur : select_s1 where_		{;}
	| select_s1			{;}
	;
		

insert_s : insert into identifier insert_s1						{;} 
	| insert into identifier left_parenthesis identifier insert_s2 insert_s1 	{;}
	;

insert_s1 : select_recur semi_colon	{;}
	| values_s			{;}
	;

insert_s2 : right_parenthesis			{;}
	  | comma identifier insert_s2 		{;}
	  ;

values_s : values left_parenthesis identifier values_s1 values_s2	{;}
	;

values_s1 : right_parenthesis 		{;}
	| comma identifier values_s1    {;}
	;

values_s2 : semi_colon 		{;}
	| comma left_parenthesis identifier values_s1 values_s2		{;}
	;

update_s : update identifier set identifier equal identifier update_s1	{;}
	;

update_s1 : semi_colon 		{;}
	| where_  semi_colon	{;}
	;

delete_s : delete from identifier update_s1	{;}
	;

drop_s : drop table identifier semi_colon	{;}
	;
	
alter_s : alter table identifier alter_s1	{;}
	;

alter_s1 : alter_d 	{;}
	| alter_a 	{;}
	| alter_m	{;}
	;

alter_d : drop identifier alter_d1	{;}
	;

alter_d1 : semi_colon 		{;}
	| comma alter_d		{;}
	;

alter_a : add identifier data_type constraints alter_a1		{;}
	| add identifier data_type alter_a1		{;}	
	;

alter_a1 : semi_colon	     {;}
	| comma alter_a      {;}
	;

alter_m : modify identifier data_type constraints semi_colon    {;}
	| modify identifier data_type semi_colon    {;}
	;
		

%%

int main(void){

	return yyparse();
}

void yyerror(char *s){
	fprintf(stderr,"%s in line_no.:%d near token '%s' (at column_no.:%d)\n",s,yylloc.first_line,yytext,yylloc.first_column);
}
	
