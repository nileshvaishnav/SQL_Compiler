#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


/*
* This macro saves the stack_top in a temporary variable
* and updates latest non-terminal's production number
* so if a production is not sastisfied stack_top is again reset
* by other macro RESET_STACK_TOP
*/
#define SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(x)  int temp_stack_top = stack_top; \
					stack[stack_top - 1].production_no = x


/*
* This macro inserts the next non-terminal which will be 
* explored into stack and increaments stack_top
*/
#define INSERT_INTO_STACK(NON_TERMINAL) stack[stack_top].function = #NON_TERMINAL, stack_top++
										

/*
* As mentioned in first macro this mecro resets the stack_top
* to perviously stored stack_top
*/
#define RESET_STACK_TOP()	(stack_top = temp_stack_top,false)


// Keeps track of how many tokens have been traversed
int total_tokens_visited = 0;

// Used for error detection and error handling 
int eflag=0, errorf=0;

// This varialbe will have value of expected token in case of an error
char *expected ;

// next points to a current token to be compared with expected token
token *next;


void error_detect(bool);

/*
* Structure of a stack element
* function = the text of a non-terminal
* prod_rule = array of tokens or non-terminals(as strings) of a production
* production_size = # of strings in prod_rule
* nont-size = # of non-terminals
* productions_no = contains which production of a non-terminal is stored
* ind_nont = indexes of the non-terminals in a production
*/
typedef struct stack_elem
{
	char *function;
	char **prod_rule;
	int production_size;
	int nont_size;
	int production_no;
	int *ind_nont;
}stack_elem;


// Stack comtaing each production
stack_elem stack[5000];
// Stack top where the next non-terminal will be inserted
int stack_top = 0;



/*
* Stores all productions to a files to be used for 
* sentential form generation
*/
void print(stack_elem stack[]){
	//printf("\nNon-Terminal\tProduction_No.\n");
	FILE *write_productios = fopen("production.txt","w");
	if (write_productios == NULL)
	{
		printf("Error openning file to write production to a file for sentential form generation.\n");
		return ;
	}
	for (int i = 0; i < stack_top; ++i)
	{
		fprintf(write_productios, "%-16s\t",stack[i].function);
		for(int j = 0; j< stack[i].production_size;j++){
			fprintf(write_productios, "%s ",stack[i].prod_rule[j]);		
		}
		fprintf(write_productios, "\n");
	}
	return ;
}


int main(){

	token t = yylex();
	next = &token_list[0];
	int temp_stack_top = -1;
	

	INSERT_INTO_STACK(start_);

	bool temp = start_();
	if (errorf == 0)
	{
		printf("Input is correct.\n");
		print(stack);
	}
	
	return 0;
}

/*
* Matching an input token with expected token
*/
bool term(int tok){
	int x = next->token_class;
	bool r;
	if (x == tok)
	{
		r = true;
		total_tokens_visited++;
	}
	else{
		expected = tokentype[tok-1];
		r = false;
	}
	next++;
	
	return r;
}

/*
* Funtion fro start symbol
*/
bool start_(){
	eflag=0;
	if (total_tokens_visited == token_ptr)
	{
		stack[stack_top - 1].production_no = 0; 		// Production_no = 0 means epsilon production
		stack[stack_top - 1].production_size = 0;
		return true;
	}
	token *save = next;
	int temp_int = total_tokens_visited;
	bool res = (next = save,start_1())
		|| (total_tokens_visited = temp_int ,next = save, start_2())
		|| (total_tokens_visited = temp_int ,next = save, start_3())
		|| (total_tokens_visited = temp_int ,next = save, start_4())
		|| (total_tokens_visited = temp_int ,next = save, start_5())
		|| (total_tokens_visited = temp_int ,next = save, start_6())
		|| (total_tokens_visited = temp_int ,next = save, start_7())
		|| (total_tokens_visited = temp_int ,next = save, start_8())
		|| (total_tokens_visited = temp_int ,next = save, start_9())	
		|| (total_tokens_visited = temp_int ,next = save, start_10())
		|| (total_tokens_visited = temp_int ,next = save, start_11())
		|| (total_tokens_visited = temp_int ,next = save, start_12())	
		|| (total_tokens_visited = temp_int ,next = save, start_13())
		|| (total_tokens_visited = temp_int ,next = save, start_14())
		;

	if(res==false && total_tokens_visited < token_ptr){
		expected = "start symbol";
		error_detect(res);
		return true;
		
	}
	if(total_tokens_visited == token_ptr)
		return true;
	return res;
	
}

bool start_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 2;
	stack[stack_top-1].nont_size = 2;
	stack[stack_top-1].prod_rule = (char **)malloc(2*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "create_s";
	stack[stack_top-1].prod_rule[1] = "start_";
	stack[stack_top-1].ind_nont = (int *)malloc(2*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	stack[stack_top-1].ind_nont[1] = 1;
	return ((INSERT_INTO_STACK(create_s),create_s())
	&& 
	(INSERT_INTO_STACK(start_),start_()))
	|| (stack_top = temp_stack_top,false)
	;
}

bool start_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2);
	stack[stack_top-1].production_size = 2;
	stack[stack_top-1].nont_size = 2;
	stack[stack_top-1].prod_rule = (char **)malloc(2*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "select_s";
	stack[stack_top-1].prod_rule[1] = "start_";
	stack[stack_top-1].ind_nont = (int *)malloc(2*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	stack[stack_top-1].ind_nont[1] = 1;
	return ((INSERT_INTO_STACK(select_s),select_s())
	&& 
	(INSERT_INTO_STACK(start_),start_()))
	|| (stack_top = temp_stack_top,false) 
	;
	
}	

bool start_3(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(3);
	stack[stack_top-1].production_size = 2;
	stack[stack_top-1].nont_size = 2;
	stack[stack_top-1].prod_rule = (char **)malloc(2*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "insert_s";
	stack[stack_top-1].prod_rule[1] = "start_";
	stack[stack_top-1].ind_nont = (int *)malloc(2*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	stack[stack_top-1].ind_nont[1] = 1;
	return ((INSERT_INTO_STACK(insert_s),insert_s())
	&& 
	(INSERT_INTO_STACK(start_),start_()))
	|| (stack_top = temp_stack_top,false) ;
}

bool start_4(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(4);
	stack[stack_top-1].production_size = 2;
	stack[stack_top-1].nont_size = 2;
	stack[stack_top-1].prod_rule = (char **)malloc(2*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "update_s";
	stack[stack_top-1].prod_rule[1] = "start_";
	stack[stack_top-1].ind_nont = (int *)malloc(2*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	stack[stack_top-1].ind_nont[1] = 1;
	return ((INSERT_INTO_STACK(update_s),update_s())
		&& (INSERT_INTO_STACK(start_),start_()))
		|| RESET_STACK_TOP()
		;
}

bool start_5(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(5);
	stack[stack_top-1].production_size = 2;
	stack[stack_top-1].nont_size = 2;
	stack[stack_top-1].prod_rule = (char **)malloc(2*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "delete_s";
	stack[stack_top-1].prod_rule[1] = "start_";
	stack[stack_top-1].ind_nont = (int *)malloc(2*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	stack[stack_top-1].ind_nont[1] = 1;
	return ((INSERT_INTO_STACK(delete_s),delete_s())
		&& (INSERT_INTO_STACK(start_),start_()))
		|| RESET_STACK_TOP()
		;
}

bool start_6(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(6);
	stack[stack_top-1].production_size = 2;
	stack[stack_top-1].nont_size = 2;
	stack[stack_top-1].prod_rule = (char **)malloc(2*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "drop_s";
	stack[stack_top-1].prod_rule[1] = "start_";
	stack[stack_top-1].ind_nont = (int *)malloc(2*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	stack[stack_top-1].ind_nont[1] = 1;
	return ((INSERT_INTO_STACK(drop_s),drop_s())
		&& (INSERT_INTO_STACK(start_),start_()))
		|| RESET_STACK_TOP()
		;
}

bool start_7(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(7);
	stack[stack_top-1].production_size = 2;
	stack[stack_top-1].nont_size = 2;
	stack[stack_top-1].prod_rule = (char **)malloc(2*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "alter_s";
	stack[stack_top-1].prod_rule[1] = "start_";
	stack[stack_top-1].ind_nont = (int *)malloc(2*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	stack[stack_top-1].ind_nont[1] = 1;
	return ((INSERT_INTO_STACK(alter_s),alter_s())
		&& (INSERT_INTO_STACK(start_),start_()))
		|| RESET_STACK_TOP()
		;
}

bool start_8(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(8);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "create_s";
	
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	
	return (INSERT_INTO_STACK(create_s),create_s())
		|| RESET_STACK_TOP()
		;
}	

bool start_9(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(9);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 1;	
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "select_s";
	
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	return (INSERT_INTO_STACK(select_s),select_s())
		|| RESET_STACK_TOP()
		;
}

bool start_10(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(10);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "insert_s";
	
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	return (INSERT_INTO_STACK(insert_s),insert_s())
		|| RESET_STACK_TOP()
		;
}

bool start_11(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(11);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "update_s";
	
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	return (INSERT_INTO_STACK(update_s),update_s())
		|| RESET_STACK_TOP()
		;
}

bool start_12(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(12);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "delete_s";
	
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	return (INSERT_INTO_STACK(delete_s),delete_s())
		|| RESET_STACK_TOP()
		;
}

bool start_13(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(13);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "drop_s";
	
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	return (INSERT_INTO_STACK(drop_s),drop_s())
		|| RESET_STACK_TOP()
		;
}

bool start_14(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(14);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "alter_s";
	
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	return (INSERT_INTO_STACK(alter_s),alter_s())
		|| RESET_STACK_TOP()
		;
}


/*
* If error occures then skip some token untill we find a start
* token(select_t,create,update,insert,drop,delete,alter)for a query and then agian call start_()
*/
void error_detect(bool res){
	next--;
	if(next->token_text == NULL){
		next--;
	}
	printf("Error: Expected '%s' near '%s' in line No. %d\n", expected, next->token_text,next->line_no);
	eflag =0 ;
	//next++;
	errorf =1;

	// Skipping untill we find a start token
	/*while(next->token_class != create && next->token_class != select_t && next->token_class != insert && next->token_class != delete && next->token_class != update && next->token_class != drop && next->token_class != alter && total_tokens_visited < token_ptr){*/
	while(next->token_class != semi_colon && total_tokens_visited < token_ptr){
		
		next++;
		total_tokens_visited++;
	}
	if(total_tokens_visited < token_ptr){
		next++;
		total_tokens_visited++;
	}
	start_();
	
}

bool create_s(){
	
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 7;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(7*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "create";
	stack[stack_top-1].prod_rule[1] = "table";
	stack[stack_top-1].prod_rule[2] = "identifier";
	stack[stack_top-1].prod_rule[3] = "left_parenthesis";
	stack[stack_top-1].prod_rule[4] = "column_def";
	stack[stack_top-1].prod_rule[5] = "right_parenthesis";
	stack[stack_top-1].prod_rule[6] = "semi_colon";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 4;
	
	bool res =  ((term(create)) 
		&& (eflag=1,term(table)) 
		&& (term(identifier))
		&& (term(left_parenthesis)) 
		&& (INSERT_INTO_STACK(column_def),column_def()) 
		&& (term(right_parenthesis)) 
		&& (term(semi_colon)))
		|| (stack_top = temp_stack_top,false)
		;

	if(res == false && eflag == 1 ){
		error_detect(res);
		return true;
	}
	return res;
	
}

bool column_def(){
	token *save = next;
	int temp_int = total_tokens_visited;
	return ((next = save,total_tokens_visited = temp_int , column_def_1())
		|| (next = save,total_tokens_visited = temp_int , column_def_2())
		|| (next = save,total_tokens_visited = temp_int , column_def_3()));
}

bool column_def_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 5;
	stack[stack_top-1].nont_size = 2;
	stack[stack_top-1].prod_rule = (char **)malloc(5*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="identifier";
	stack[stack_top-1].prod_rule[1] ="data_type";
	stack[stack_top-1].prod_rule[2] ="constraints";
	stack[stack_top-1].prod_rule[3] ="comma";
	stack[stack_top-1].prod_rule[4] ="column_def";
	stack[stack_top-1].ind_nont = (int *)malloc(2*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 2;
	stack[stack_top-1].ind_nont[1] = 4;
	return (term(identifier) 
		&& term(data_type) 
		&& (INSERT_INTO_STACK(constraints),constraints()) 
		&& term(comma) 
		&& (INSERT_INTO_STACK(column_def),column_def()))
		|| (stack_top = temp_stack_top,false)
		;
}
bool column_def_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2);
	stack[stack_top-1].production_size = 3;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(3*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="identifier";
	stack[stack_top-1].prod_rule[1] ="data_type";
	stack[stack_top-1].prod_rule[2] ="constraints";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 2;
	return (term(identifier) 
		&& term(data_type) 
		&& (INSERT_INTO_STACK(constraints),constraints()))
		|| (stack_top = temp_stack_top,false)
		;
}

bool column_def_3(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(3);
	stack[stack_top-1].production_size = 2;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(2*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="identifier";
	stack[stack_top-1].prod_rule[1] ="data_type";
	stack[stack_top-1].ind_nont = NULL;
	return (term(identifier) 
		&& term(data_type))
		|| (stack_top = temp_stack_top,false)
		;
}


bool constraints(){
	int temp_int = total_tokens_visited;
	token *save = next;
	return (next = save,total_tokens_visited = temp_int , constraints_1())
		|| (next = save,total_tokens_visited = temp_int , constraints_2())
		|| (next = save,total_tokens_visited = temp_int , constraints_3())
		|| (next = save,total_tokens_visited = temp_int , constraints_4());
}

bool constraints_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 4;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(4*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="not";
	stack[stack_top-1].prod_rule[1] ="null";
	stack[stack_top-1].prod_rule[2] ="primary";
	stack[stack_top-1].prod_rule[3] ="key";
	stack[stack_top-1].ind_nont = NULL;
	return (term(not) && term(null) && term(primary) && term(key))
		|| (stack_top = temp_stack_top,false)
		;
}

bool constraints_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2);
	stack[stack_top-1].production_size = 3;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(3*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="null";
	stack[stack_top-1].prod_rule[1] ="primary";
	stack[stack_top-1].prod_rule[2] ="key";
	stack[stack_top-1].ind_nont = NULL;
	return (term(null) && term(primary) && term(key))
		|| (stack_top = temp_stack_top,false)
		;
}

bool constraints_3(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(3);
	stack[stack_top-1].production_size = 2;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(2*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="primary";
	stack[stack_top-1].prod_rule[1] ="key";
	stack[stack_top-1].ind_nont = NULL;
	return (term(primary) && term(key))
		|| (stack_top = temp_stack_top,false)
		;
}

bool constraints_4(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(4);
	stack[stack_top-1].production_size = 2;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(2*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="not";
	stack[stack_top-1].prod_rule[1] ="null";
	stack[stack_top-1].ind_nont = NULL;
	return (term(not) && term(null))
		|| (stack_top = temp_stack_top,false)
		;
}

bool constraints_5(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(5);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="null";
	stack[stack_top-1].ind_nont = NULL;
	return (term(null))
		|| (stack_top = temp_stack_top,false)
		;
}

bool select_s(){
	//eflag = 0;
	int temp_int = total_tokens_visited;
	token *save = next;
	bool res =  (next = save,total_tokens_visited = temp_int , select_s_2())
		|| (next = save,total_tokens_visited = temp_int , select_s_1())
		;

	if(res == false && eflag == 1 ){
		error_detect(res);
		return true;
	}
	return res;
}

bool select_s_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 3;
	stack[stack_top-1].nont_size = 2;
	stack[stack_top-1].prod_rule = (char **)malloc(3*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="select_s1";
	stack[stack_top-1].prod_rule[1] ="where_";
	stack[stack_top-1].prod_rule[2] ="semi_colon";
	stack[stack_top-1].ind_nont = (int *)malloc(2*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	stack[stack_top-1].ind_nont[1] = 1;
	return ((INSERT_INTO_STACK(select_s1),select_s1())
		&& (INSERT_INTO_STACK(where_),where_()) 
		&& term(semi_colon))
		|| (stack_top = temp_stack_top,false)
		;
}

bool select_s_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2);
	stack[stack_top-1].production_size = 2;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(2*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="select_s1";
	stack[stack_top-1].prod_rule[1] ="semi_colon";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	return ((INSERT_INTO_STACK(select_s1),select_s1())  
		&& term(semi_colon))
		|| (stack_top = temp_stack_top,false)
		;
}

bool select_recur(){
	//eflag = 0;
	int temp_int = total_tokens_visited;
	token *save = next;
	return	 (next = save,total_tokens_visited = temp_int , select_s_3())
		|| (next = save,total_tokens_visited = temp_int , select_s_4())
		;

}

bool select_s_3(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(3);
	stack[stack_top-1].production_size = 2;
	stack[stack_top-1].nont_size = 2;
	stack[stack_top-1].prod_rule = (char **)malloc(2*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="select_s1";
	stack[stack_top-1].prod_rule[1] ="where_";
	stack[stack_top-1].ind_nont = (int *)malloc(2*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	stack[stack_top-1].ind_nont[1] = 1;
	return ((INSERT_INTO_STACK(select_s1),select_s1())  
		&& (INSERT_INTO_STACK(where_),where_()))
		|| (stack_top = temp_stack_top,false)
		;
}

bool select_s_4(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(4);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="select_s1";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	return INSERT_INTO_STACK(select_s1),select_s1()
		|| (stack_top = temp_stack_top,false)
		;
}

bool select_s1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 4;
	stack[stack_top-1].nont_size = 2;
	stack[stack_top-1].prod_rule = (char **)malloc(4*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="select_t";
	stack[stack_top-1].prod_rule[1] ="multi_col";
	stack[stack_top-1].prod_rule[2] ="from";
	stack[stack_top-1].prod_rule[3] ="multi_col";
	stack[stack_top-1].ind_nont = (int *)malloc(2*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 1;
	stack[stack_top-1].ind_nont[1] = 3;
	return (term(select_t) 
		&& (eflag=1, INSERT_INTO_STACK(multi_col),multi_col()) 
		&& term(from) 
		&& (INSERT_INTO_STACK(multi_col),multi_col()))
		|| (stack_top = temp_stack_top,false)
		;
}

bool multi_col(){
	int temp_int = total_tokens_visited;
	token *save = next;
	return (next = save,total_tokens_visited = temp_int , multi_col_1())
		|| (next = save,total_tokens_visited = temp_int , multi_col_2())
		;
}

bool multi_col_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 3;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(3*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="identifier";
	stack[stack_top-1].prod_rule[1] ="comma";
	stack[stack_top-1].prod_rule[2] ="multi_col";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 2;
	return (term(identifier) 
		&& term(comma) 
		&& (INSERT_INTO_STACK(multi_col),multi_col()))
		|| (stack_top = temp_stack_top,false)
		;
}

bool multi_col_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="identifier";
	stack[stack_top-1].ind_nont = NULL;
	return term(identifier);
}

bool where_(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 4;
	stack[stack_top-1].nont_size = 2;
	stack[stack_top-1].prod_rule = (char **)malloc(4*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="where";
	stack[stack_top-1].prod_rule[1] ="identifier";
	stack[stack_top-1].prod_rule[2] ="op";
	stack[stack_top-1].prod_rule[3] ="where_1";
	stack[stack_top-1].ind_nont = (int *)malloc(2*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 2;
	stack[stack_top-1].ind_nont[1] = 3;
	return (term(where) 
		&& term(identifier) 
		&& (INSERT_INTO_STACK(op),op()) 
		&& (INSERT_INTO_STACK(where_1),where_1()))
		|| (stack_top = temp_stack_top,false)
		;
}

bool op(){
	int temp_int = total_tokens_visited;
	token *save = next;
	return (next = save,total_tokens_visited = temp_int , op_1())
		|| (next = save,total_tokens_visited = temp_int , op_2())
		;
}

bool op_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="equal";
	stack[stack_top-1].ind_nont = NULL;
	return term(equal);
}

bool op_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="in";
	stack[stack_top-1].ind_nont = NULL;
	return term(in);
}

bool where_1(){
	int temp_int = total_tokens_visited;
	token *save = next;
	return (next = save,total_tokens_visited = temp_int , where_1_1())
		|| (next = save,total_tokens_visited = temp_int , where_1_2())
		|| (next = save,total_tokens_visited = temp_int , where_1_3())
		;
}

bool where_1_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="integer";
	stack[stack_top-1].ind_nont = NULL;
	return term(integer);
}

bool where_1_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="identifier";
	stack[stack_top-1].ind_nont = NULL;
	return term(identifier);
}

bool where_1_3(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(3);
	stack[stack_top-1].production_size = 3;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(3*sizeof(char *));
	stack[stack_top-1].prod_rule[0] ="left_parenthesis";
	stack[stack_top-1].prod_rule[1] ="select_recur";
	stack[stack_top-1].prod_rule[2] ="right_parenthesis";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 1;
	return (term(left_parenthesis) 
		&& (INSERT_INTO_STACK(select_recur),select_recur()) 
		&& term(right_parenthesis))
		|| (stack_top = temp_stack_top,false)
		;
}

bool insert_s(){

	int temp_int = total_tokens_visited;
	token *save = next;
	bool res =  (next = save,total_tokens_visited = temp_int , insert_s_2())
		|| (next = save,total_tokens_visited = temp_int , insert_s_1())
		;

	if(res == false && eflag == 1 ){
		error_detect(res);
		return true;
	}
	return res;
}

bool insert_s_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1) ;
	stack[stack_top-1].production_size = 7;
	stack[stack_top-1].nont_size = 2;
	stack[stack_top-1].prod_rule = (char **)malloc(7*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "insert";
	stack[stack_top-1].prod_rule[1] = "into";
	stack[stack_top-1].prod_rule[2] = "identifier";
	stack[stack_top-1].prod_rule[3] = "left_parenthesis";
	stack[stack_top-1].prod_rule[4] = "identifier";
	stack[stack_top-1].prod_rule[5] = "insert_s2";
	stack[stack_top-1].prod_rule[6] = "insert_s1";
	stack[stack_top-1].ind_nont = (int *)malloc(2*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 5;
	stack[stack_top-1].ind_nont[1] = 6;
	bool res =  (term(insert) 
		&& (eflag = 1,term(into) )
		&& term(identifier) 
		&& term(left_parenthesis) 
		&& term(identifier) 
		&& (INSERT_INTO_STACK(insert_s2),insert_s2()) 
		&& (INSERT_INTO_STACK(insert_s1),insert_s1()))
		|| (stack_top = temp_stack_top,false)
		;

	
	return res;
}

bool insert_s_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2) ;
	stack[stack_top-1].production_size = 4;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(4*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "insert";
	stack[stack_top-1].prod_rule[1] = "into";
	stack[stack_top-1].prod_rule[2] = "identifier";
	stack[stack_top-1].prod_rule[3] = "insert_s1";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 3;
	return (term(insert) 
		&& (eflag=1,term(into)) 
		&& term(identifier) 
		&& (INSERT_INTO_STACK(insert_s1),insert_s1()))
		|| (stack_top = temp_stack_top,false)
		;
}

bool insert_s1(){
	int temp_int = total_tokens_visited;
	token *save = next;
	return (next = save,total_tokens_visited = temp_int , insert_s1_1())
		|| (next = save,total_tokens_visited = temp_int , insert_s1_2())
		;
}

bool insert_s1_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1) ;
	stack[stack_top-1].production_size = 2;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(2*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "select_s";
	stack[stack_top-1].prod_rule[1] = "semi_colon";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	return (INSERT_INTO_STACK(select_s),select_recur())
		&& term(semi_colon)
		|| (stack_top = temp_stack_top,false)
		;
}

bool insert_s1_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2) ;
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "values_s";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	return (INSERT_INTO_STACK(values_s),values_s())
		|| (stack_top = temp_stack_top,false)
		;
}

bool insert_s2(){
	int temp_int = total_tokens_visited;
	token *save = next;
	return (next = save,total_tokens_visited = temp_int , insert_s2_1())
		|| (next = save,total_tokens_visited = temp_int , insert_s2_2())
		;
}

bool insert_s2_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1) ;
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "right_parenthesis";
	stack[stack_top-1].ind_nont = NULL;
	return term(right_parenthesis)
		|| (stack_top = temp_stack_top,false)
		;
}

bool insert_s2_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2) ;
	stack[stack_top-1].production_size = 3;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(3*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "comma";
	stack[stack_top-1].prod_rule[1] = "identifier";
	stack[stack_top-1].prod_rule[2] = "insert_s2";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 2;
	return (term(comma) 
		&& term(identifier) 
		&& (INSERT_INTO_STACK(insert_s2),insert_s2()))
		|| (stack_top = temp_stack_top,false)
		;
}

bool values_s(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1) ;
	stack[stack_top-1].production_size = 5;
	stack[stack_top-1].nont_size = 2;
	stack[stack_top-1].prod_rule = (char **)malloc(5*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "values";
	stack[stack_top-1].prod_rule[1] = "left_parenthesis";
	stack[stack_top-1].prod_rule[2] = "identifier";
	stack[stack_top-1].prod_rule[3] = "values_s1";
	stack[stack_top-1].prod_rule[4] = "values_s2";
	stack[stack_top-1].ind_nont = (int *)malloc(2*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 3;
	stack[stack_top-1].ind_nont[1] = 4;
	bool res =  (term(values) 
		&& term(left_parenthesis) 
		&& term(identifier)  
		&& (INSERT_INTO_STACK(values_s1),values_s1()) 
		&& (INSERT_INTO_STACK(values_s2),values_s2()))
		|| (stack_top = temp_stack_top,false)
		;
	
	return res;	
}

bool values_s1(){
	int temp_int = total_tokens_visited;
	token *save = next;
	return (next = save ,total_tokens_visited = temp_int ,values_s1_1() )
		||  (next = save,total_tokens_visited = temp_int , values_s1_2())
		;
}	

bool values_s1_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1) ;
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "right_parenthesis";
	stack[stack_top-1].ind_nont = NULL;
	return term(right_parenthesis)
		|| (stack_top = temp_stack_top,false)
		;
}

bool values_s1_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2) ;
	stack[stack_top-1].production_size = 3;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(3*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "comma";
	stack[stack_top-1].prod_rule[1] = "identifier";
	stack[stack_top-1].prod_rule[2] = "values_s1";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 2;
	return (term(comma) 
		&& term(identifier) 
		&& (INSERT_INTO_STACK(values_s1),values_s1())) 
		|| (stack_top = temp_stack_top,false)
		;
}

bool values_s2(){
	int temp_int = total_tokens_visited;
	token *save = next;
	return (next = save ,total_tokens_visited = temp_int ,values_s2_1() )
		||  (next = save,total_tokens_visited = temp_int , values_s2_2())
		;
}

bool values_s2_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1) ;
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "semi_colon";
	stack[stack_top-1].ind_nont = NULL;
	return term(semi_colon)
		|| (stack_top = temp_stack_top,false)
		;
}

bool values_s2_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2) ;
	stack[stack_top-1].production_size = 5;
	stack[stack_top-1].nont_size = 2;
	stack[stack_top-1].prod_rule = (char **)malloc(5*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "comma";
	stack[stack_top-1].prod_rule[1] = "left_parenthesis";
	stack[stack_top-1].prod_rule[2] = "identifier";
	stack[stack_top-1].prod_rule[3] = "values_s1";
	stack[stack_top-1].prod_rule[4] = "values_s2";
	stack[stack_top-1].ind_nont = (int *)malloc(2*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 3;
	stack[stack_top-1].ind_nont[1] = 4;
	return (term(comma) 
		&& term(left_parenthesis) 
		&& term(identifier) 
		&& (INSERT_INTO_STACK(values_s1),values_s1()) 
		&& (INSERT_INTO_STACK(values_s2),values_s2()))
		|| (stack_top = temp_stack_top,false)
		;
}

bool update_s(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 7;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(7*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "update";
	stack[stack_top-1].prod_rule[1] = "identifier";
	stack[stack_top-1].prod_rule[2] = "set";
	stack[stack_top-1].prod_rule[3] = "identifier";
	stack[stack_top-1].prod_rule[4] = "equal";
	stack[stack_top-1].prod_rule[5] = "identifier";
	stack[stack_top-1].prod_rule[6] = "update_s1";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 6;
	bool res =  (term(update) 
		&& (eflag=1,term(identifier)) 
		&& term(set) 
		&& term(identifier) 
		&& term(equal) 
		&& term(identifier) 
		&& (INSERT_INTO_STACK(update_s1),update_s1()))
		|| RESET_STACK_TOP()
		;

	if(res == false && eflag == 1 ){
		error_detect(res);
		return true;
	}

	return res;
}

bool update_s1(){
	int temp_int = total_tokens_visited;
	token *save = next;
	return (next = save ,total_tokens_visited = temp_int ,update_s1_1() )
		||  (next = save,total_tokens_visited = temp_int , update_s1_2())
		;
}

bool update_s1_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "semi_colon";
	stack[stack_top-1].ind_nont = NULL;
	return term(semi_colon)
		|| RESET_STACK_TOP()
		;
}

bool update_s1_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2);
	stack[stack_top-1].production_size = 2;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(2*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "where_";
	stack[stack_top-1].prod_rule[1] = "semi_colon";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	return ((INSERT_INTO_STACK(where_),where_()) 
		&& term(semi_colon))
		|| RESET_STACK_TOP()
		;
}

bool delete_s(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 4;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(4*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "delete";
	stack[stack_top-1].prod_rule[1] = "from";
	stack[stack_top-1].prod_rule[2] = "identifier";
	stack[stack_top-1].prod_rule[3] = "update_s1";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 3;
	bool res =  (term(delete) 
		&& (eflag=1,term(from)) 
		&& term(identifier) 
		&& (INSERT_INTO_STACK(update_s1),update_s1()))
		|| RESET_STACK_TOP()
		;

	if(res == false && eflag == 1 ){
		error_detect(res);
		return true;
	}

	return res;
}

bool drop_s(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 4;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(4*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "drop";
	stack[stack_top-1].prod_rule[1] = "table";
	stack[stack_top-1].prod_rule[2] = "identifier";
	stack[stack_top-1].prod_rule[3] = "semi_colon";
	stack[stack_top-1].ind_nont = NULL;
	bool res =  (term(drop) 
		&& (eflag=1,term(table)) 
		&& term(identifier) 
		&& term(semi_colon))
		|| RESET_STACK_TOP()
		;

	if(res == false && eflag == 1){
		error_detect(res);
		return true;
	}

	return res;
}

bool alter_s(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 4;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(4*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "alter";
	stack[stack_top-1].prod_rule[1] = "table";
	stack[stack_top-1].prod_rule[2] = "identifier";
	stack[stack_top-1].prod_rule[3] = "alter_s1";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 3;
	int temp = 0;
	bool res =  (term(alter) 
		&& (temp=1,term(table)) 
		&& term(identifier) 
		&& (INSERT_INTO_STACK(alter_s1),alter_s1()))
		|| RESET_STACK_TOP()
		;

	if(res == false && eflag == 1){
		error_detect(res);
		return true;
	}
	if(res == false && eflag == 0 &&  temp==1 ){
		error_detect(res);
		return true;
	}
	
	return res;
}

bool alter_s1(){
	int temp_int = total_tokens_visited;
	token *save = next;
	return (next = save ,total_tokens_visited = temp_int ,alter_s1_1() )
	||  (next = save,total_tokens_visited = temp_int , alter_s1_2())
	|| (next = save ,total_tokens_visited = temp_int , alter_s1_3());
}

bool alter_s1_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "alter_d";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	return (INSERT_INTO_STACK(alter_d),alter_d())
		|| RESET_STACK_TOP()
		;
}

bool alter_s1_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "alter_a";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	return (INSERT_INTO_STACK(alter_a),alter_a())
		|| RESET_STACK_TOP()
		;
}

bool alter_s1_3(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(3);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "alter_m";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 0;
	return (INSERT_INTO_STACK(alter_m),alter_m())
		|| RESET_STACK_TOP()
		;
}
bool alter_d(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 3;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(3*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "drop";
	stack[stack_top-1].prod_rule[1] = "identifier";
	stack[stack_top-1].prod_rule[2] = "alter_d1";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 2;
	bool res = (term(drop) 
		&& (eflag=1,term(identifier)) 
		&& (INSERT_INTO_STACK(alter_d1),alter_d1()))
		|| RESET_STACK_TOP()
		;
	if(res == false && eflag == 1 ){
			error_detect(res);
			return true;
		}
	
	return res;
}

bool alter_d1(){
	int temp_int = total_tokens_visited;
	token *save = next;
	return (next = save ,total_tokens_visited = temp_int ,alter_d1_1() )
		||  (next = save,total_tokens_visited = temp_int , alter_d1_2())
		;
}

bool alter_d1_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "semi_colon";
	stack[stack_top-1].ind_nont = NULL;
	return term(semi_colon)
		|| RESET_STACK_TOP()
		;
}

bool alter_d1_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2);
	stack[stack_top-1].production_size = 2;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(2*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "comma";
	stack[stack_top-1].prod_rule[1] = "alter_d";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 1;
	return (term(comma) 
		&& (INSERT_INTO_STACK(alter_d),alter_d()))
		|| RESET_STACK_TOP()
		;
}

bool alter_a(){
	int temp_int = total_tokens_visited;
	token *save = next;
	bool res = (next = save ,total_tokens_visited = temp_int ,alter_a_f1())
		||  (next = save, total_tokens_visited = temp_int ,alter_a_f2())
		;
	
	if(res == false && eflag == 1){
			error_detect(res);
			return true;
		}
	
	return res;

}


bool alter_a_f1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 5;
	stack[stack_top-1].nont_size = 2;
	stack[stack_top-1].prod_rule = (char **)malloc(5*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "add";
	stack[stack_top-1].prod_rule[1] = "identifier";
	stack[stack_top-1].prod_rule[2] = "data_type";
	stack[stack_top-1].prod_rule[3] = "constraints";
	stack[stack_top-1].prod_rule[4] = "alter_a1";
	stack[stack_top-1].ind_nont = (int *)malloc(2*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 3;
	stack[stack_top-1].ind_nont[1] = 4;
	bool res = (term(add) 
		&& (eflag=1,term(identifier))
		&& term(data_type) 
		&& (INSERT_INTO_STACK(constraints),constraints()) 
		&& (INSERT_INTO_STACK(alter_a1),alter_a1()))
		|| RESET_STACK_TOP()
		;
	return res;
}

bool alter_a_f2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2);
	stack[stack_top-1].production_size = 4;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(4*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "add";
	stack[stack_top-1].prod_rule[1] = "identifier";
	stack[stack_top-1].prod_rule[2] = "data_type";
	stack[stack_top-1].prod_rule[3] = "alter_a1";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 3;
	bool res =  (term(add) 
		&& (eflag=1,term(identifier)) 
		&& term(data_type)  
		&& (INSERT_INTO_STACK(alter_a1),alter_a1()))
		|| RESET_STACK_TOP()
		;
	return res;
}

bool alter_a1(){
	int temp_int = total_tokens_visited;
	token *save = next;
	return (next = save ,total_tokens_visited = temp_int ,alter_a1_1() )
		||  (next = save,total_tokens_visited = temp_int , alter_a1_2())
		;
}

bool alter_a1_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 1;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(1*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "semi_colon";
	stack[stack_top-1].ind_nont = NULL;
	return term(semi_colon)
		|| RESET_STACK_TOP()
		;
}

bool alter_a1_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2);
	stack[stack_top-1].production_size = 2;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(2*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "comma";
	stack[stack_top-1].prod_rule[1] = "alter_a";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 1;
	return (term(comma) 
		&& (INSERT_INTO_STACK(alter_a),alter_a()))
		|| RESET_STACK_TOP()
		;
}

bool alter_m(){
	int temp_int = total_tokens_visited;
	token *save = next;
	bool res = (next = save ,total_tokens_visited = temp_int ,alter_m_1() )
		||  (next = save,total_tokens_visited = temp_int , alter_m_2())
		;

	if(res == false && eflag == 1 ){
			error_detect(res);
			return true;
		}
	
	return res;
}

bool alter_m_1(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(1);
	stack[stack_top-1].production_size = 5;
	stack[stack_top-1].nont_size = 1;
	stack[stack_top-1].prod_rule = (char **)malloc(5*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "modify";
	stack[stack_top-1].prod_rule[1] = "identifier";
	stack[stack_top-1].prod_rule[2] = "data_type";
	stack[stack_top-1].prod_rule[3] = "constraints";
	stack[stack_top-1].prod_rule[4] = "semi_colon";
	stack[stack_top-1].ind_nont = (int *)malloc(1*sizeof(int));
	stack[stack_top-1].ind_nont[0] = 3;
	bool res = (term(modify) 
		&& (eflag = 1,term(identifier)) 
		&& term(data_type) 
		&& (INSERT_INTO_STACK(constraints),constraints()) 
		&& term(semi_colon))
		|| RESET_STACK_TOP()
		;
	return res;
}

bool alter_m_2(){
	SAVE_STACK_TOP_AND_UPDATE_PRODUCTION_NO(2);
	stack[stack_top-1].production_size = 4;
	stack[stack_top-1].nont_size = 0;
	stack[stack_top-1].prod_rule = (char **)malloc(4*sizeof(char *));
	stack[stack_top-1].prod_rule[0] = "modify";
	stack[stack_top-1].prod_rule[1] = "identifier";
	stack[stack_top-1].prod_rule[2] = "data_type";
	stack[stack_top-1].prod_rule[3] = "semi_colon";
	stack[stack_top-1].ind_nont = NULL;
	bool res = (term(modify) 
		&& (eflag = 1,term(identifier)) 
		&& term(data_type) 
		&& term(semi_colon))
		|| RESET_STACK_TOP()
		;
	return res;
}
