#include <stdio.h>
#include <stdlib.h>

struct student{
	int schoolno;
	int grade;
	struct student *left;
	struct student *right;
};

struct student *head=NULL;
struct student *curr=NULL;

void orderprint(struct student *std){
	if (std==NULL) return;
	orderprint(std->left);
	printf("%d %d\n", std->schoolno, std->grade);
	orderprint(std->right);
}

int lay(struct student *std,int x){
	if (std==NULL) return 0;
	int flag=0;
	if (x==1){
		if (std->left!=NULL){ 
			printf("%d %d (%d L) ", std->left->schoolno, std->left->grade, std->grade);flag=1;
		}
		if (std->right!=NULL){ 
			printf("%d %d (%d R) ", std->right->schoolno, std->right->grade, std->grade);flag=1;
		}
	return flag;
	}
	else {int a = lay(std->left,x-1); int b=lay(std->right,x-1); return (a||b);}
}

void layerprint(struct student *std){
	printf("%d %d", head->schoolno, head->grade);

	int layerflag=1;
	int layerno=1;
	while (layerflag){
		printf("\n");
		layerflag = lay(std,layerno);
		layerno++;
	}
}

int main(void){
int schoolno, grade;
while (1){
	scanf("%d %d ",&schoolno, &grade);
	if (schoolno==-1) break;

	struct student *new= malloc(sizeof(struct student));
	new -> schoolno = schoolno; 
	new -> grade = grade;
	new -> left = NULL;
	new -> right = NULL;

	if (head == NULL) {head = new; continue;}
	
	curr=head;
	while (1){
		if (grade <= curr->grade){
			if (curr->left == NULL) break;
			curr = curr->left;
			continue;
		}else{
			if (curr->right == NULL) break;
			curr = curr->right;
			continue;
		}
	}
	if (grade <= curr->grade) curr->left = new;	
	else curr->right = new;		
}
orderprint(head);
printf("\n");
layerprint(head);


}
