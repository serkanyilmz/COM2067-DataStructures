#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char name[50];
	int priority;
	struct node *next;
};

struct node *head=NULL;
struct node *curr=NULL;


void print (struct node * head){
	curr=head;
	while ( curr->next != NULL ) {
		printf("%s",curr->name);
		curr=curr->next;
	}printf("%s",curr->name);
}

struct node *push(char inp[], int priority, struct node *head){
	curr=head;
	struct node *new=malloc(sizeof(struct node));
	strcpy(new->name, inp);
	new->priority=priority;

	if (curr==NULL){
		head=new;
		new->next=NULL;
		return head;
	}

	if (head->priority>priority){new->next=curr;head=new; return head;}
	if (head->priority==priority && (strcmp(head->name, inp)>0) ) {new->next=head;head=new; return head;}
	while (curr->next!=NULL && curr->next->priority<priority) curr=curr->next;
	while (curr->next!=NULL && curr->next->priority==priority){
		if (strcmp(curr->next->name, inp)<0)curr=curr->next;
		else break;

	}
	new->next=curr->next;
	curr->next=new;
	return head;


}

int main(void){
	char inp[50];
	int priority;
	while ( strcmp( fgets(inp,sizeof(inp),stdin) , "-1\n") !=0){
		if ((strcmp(inp,"Annem\n")==0) || (strcmp(inp,"Babam\n")==0) ||(strcmp(inp,"Kardesim\n")==0)) priority=1;
		else if ((strcmp(inp,"Amcam\n")==0) || (strcmp(inp,"Teyzem\n")==0) || (strcmp(inp,"Dayim\n")==0) || (strcmp(inp,"Halam\n")==0)) priority=2;
		else if ((strcmp(inp,"Isyeri\n")==0) || (strcmp(inp,"Okul\n")==0)) priority=3;
		else if ((strcmp(inp,"Banka\n")==0) || (strcmp(inp,"Kargo\n")==0)) priority=5;
		else if ((strcmp(inp,"Reklam\n")==0)) priority=6;
		else priority=4;
		head=push(inp,priority, head);
	}
	print(head);
}
