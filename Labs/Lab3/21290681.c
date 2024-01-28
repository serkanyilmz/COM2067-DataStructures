#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char songName[50];
	int songNumber;
	struct node* prev;
	struct node* next;

};
struct node* head = NULL;
struct node* tail = NULL;

int main(){
	char inp[50];
	int num=1;
	while (1){
		fgets(inp, sizeof(inp),stdin);	
		if (strcmp(inp,"-1\n")==0) break;
		struct node* new = (struct node*)malloc(sizeof(struct node));
		strcpy(new->songName, inp);
		new->songNumber=num;
		if (head==NULL){head=new;tail=new;}
		else {tail->next=new; new->prev=tail; tail=new;}
		num++;
	}
	char flag;
	int spaceNumber;
	scanf("%c %d ",&flag,&spaceNumber);
	if (flag=='B'){
		struct node* current = head;
		while(current!=NULL){
			if (current->songNumber%(spaceNumber+1)==1){
				printf("%s",current->songName);
			}
			current=current->next;
		}
	}
	else if (flag=='S'){
		struct node* current = tail;
		int div=tail->songNumber%(spaceNumber+1);
		while(current!=NULL){
			if (current->songNumber%(spaceNumber+1)==div){
				printf("%s",current->songName);
			}
			current=current->prev;
		}

	}
}
