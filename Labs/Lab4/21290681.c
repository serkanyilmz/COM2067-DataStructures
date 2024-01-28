#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
	char data[50];
	struct stack* next;
};
struct stack* top=NULL;

struct stack* push(struct stack* top, char data[50]){
	if (top==NULL){
		struct stack *new= malloc(sizeof(struct stack));
		strcpy(new->data, data);
		return new;
	}else{
		struct stack *new= malloc(sizeof(struct stack));
		strcpy(new->data, data);
		new->next=top;
		return new;
	}
}

struct stack* pop(struct stack* top){
	if (top->next==NULL){
		top=NULL;
		return NULL;
		
	}else{
		struct stack *nex= top->next;
		top = NULL;
		top=nex;
		return top;
	}
}

int main(void){

//printing error
int errorgiven=0;
void error(char* key){printf("error <%s>\n",key);errorgiven=1;}


char input[10000];
fgets(input, sizeof(input), stdin) != NULL;

const char *startTag = "<";
const char *endTag = ">";
const char *start=input;
const char *end=NULL;

while((start=strstr(start,startTag))!=NULL){
	end= strstr(start,endTag);
	size_t len=end-start-1;
	char *key= (char*)malloc(len+1);
	strncpy(key,start+1,len);
	key[len]='\0';
	//opening tag
	if (key[0]!='/') {
		top=push(top,key);	
	}
	//closing tag
	else{
		//if the tag which is not opened is closed
		if (top==NULL) {error(key);break;}
		//closing the last opened tag
		else if (strcmp(key+1, top->data)==0){
			top=pop(top);
		}
		//not matching closed tag
		else{error(top->data);break;}
	}
	start=end;
}


if (errorgiven==0){
	//if ther is opened tag which is not closed
	if (top!=NULL) error(top->data);
	else printf("correct\n");
}
}
