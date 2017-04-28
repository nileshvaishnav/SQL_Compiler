#include <stdio.h>
#include <string.h>
#include <stdbool.h>


/*
* Integers defined for each token
*/
#define create 1
#define select_t 2
#define from 3
#define where 4
#define insert 5
#define in 6
#define values 7
#define update 8
#define set 9
#define delete 10
#define drop 11
#define alter 12
#define modify 13
#define add 14
#define identifier 15
#define data_type 16
#define integer 17
#define not 18
#define primary 19
#define left_parenthesis 20
#define right_parenthesis 21
#define equal 22
#define comma 23
#define semi_colon 24
#define dot 25
#define quote 26
#define table 27
#define into 28
#define column 29
#define null 30
#define key 31


/*
* Structure for a token
*/
typedef struct token{
	int token_class;
	char *token_text;
	int line_no;
} token;

token yylex();
int yylineno();  //returns the line numner of config.in
char* yytext();
token token_list[5000];
int token_ptr;
extern char *tokentype[];
/*
* Function definations for functions used in Recursive Descent parsing
*/
bool alter_a_f1();
bool alter_a_f2();
bool alter_a1_1();
bool alter_a1_2();
bool alter_a1();
bool alter_a();
bool alter_s();
bool alter_d1_1();
bool alter_d1_2();
bool alter_d1();
bool alter_d();
bool alter_m_1();
bool alter_m_2();
bool alter_m();
bool alter_s1();
bool column_def_1();
bool column_def_2();
bool column_def_3();
bool column_def();
bool constraints_1();
bool constraints_2();
bool constraints_3();
bool constraints_4();
bool constraints_5();
bool constraints();
bool create_s();
bool delete_s();
bool drop_s();
bool insert_s_1();
bool insert_s_2();
bool insert_s1_1();
bool insert_s1_2();
bool insert_s1();
bool insert_s2_1();
bool insert_s2_2();
bool insert_s2();
bool insert_s();
bool multi_col_1();
bool multi_col_2();
bool multi_col();
bool op_1();
bool op_2();
bool op();
bool select_s_1();
bool select_s_2();
bool select_s_3();
bool select_s_4();
bool select_s1();
bool select_s();
bool start_10();
bool start_11();
bool start_12();
bool start_13();
bool start_14();
bool start_1();
bool start_2();
bool start_3();
bool start_4();
bool start_5();
bool start_6();
bool start_7();
bool start_8();
bool start_9();
bool start_();
bool term(int tok);
bool update_s();
bool update_s1_1();
bool update_s1_2();
bool update_s1();
bool values_s1_1();
bool values_s1_2();
bool values_s1();
bool values_s2_1();
bool values_s2_2();
bool values_s2();
bool values_s();
bool where_1_1();
bool where_1_2();
bool where_1_3();
bool where_1();
bool where_();
bool alter_s1_1();
bool alter_s1_2();
bool alter_s1_3();
