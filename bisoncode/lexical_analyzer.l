%{
#include "parser.tab.h"
int yycolumn = 1;

/*
* This structure is used to store location of the current token
* So that when a syntax error occures we can tell where has it occurred
*/
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;

%}
%option yylineno


%%
";"			return semi_colon;

","			return comma;

"'"			return quote;

"("			return left_parenthesis;

")"			return right_parenthesis;

"="			return equal ;

"."			return dot;

"create"		return create;

"table"			return table;

"select"		return select_t;

"delete"		return delete;

"from"			return from;

"where" 		return where;

"insert"		return insert;

"into"			return into;

"integer"		return data_type;

"varchar(".[0-9]*.")"	return data_type;

"char(".[0-9]*.")"	return data_type;

"decimal(".[0-9]*.")"	return data_type;

"decimal(".[0-9]*.",".[0-9]*.")"	return data_type;

"in" 			return in;

"values"		return values;

"update"		return update;

"set"			return set;

"drop"			return drop;
	
"column"		return column;

"add"			return add;

"modify"		return modify;

"not"			return not;

"null"			return null;

"primary"		return primary;

"key"			return key;

"*"			return identifier;

"alter"			return alter;

[0-9][0-9]*		return integer;

[_a-zA-Z][_a-zA-Z0-9]*	return identifier;

[ \t]			;
[\n]			{yycolumn = 1;}

.			printf("Unexpected Character\n");

%%

int yywrap(void)
{
	return 1;   /*this function is used when multiple input file is taken*/
}

