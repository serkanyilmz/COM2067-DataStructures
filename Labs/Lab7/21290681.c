#include <stdio.h>
#include <stdlib.h>

struct Node{
	int number;
	int balance_factor;
	int height;
	struct Node *left;
	struct Node *right;
};

struct Node *head=NULL;
struct Node *curr=NULL;
struct Node *parent=NULL;
struct Node *parentofparent=NULL;

int max(int a, int b){if (a>b){return a;} return b;}

int height(struct Node* node){
	if (node == NULL) {return 0;}
	return node->height;
}


void update(struct Node* node){
	if (node==NULL) return;
	update(node->left);
	update(node->right);
	node->height = max(height (node->left) , height (node->right))+1;
	node->balance_factor= height (node->left) - height (node->right);
	return;
}

struct Node* newNode(int number){ 
	struct Node *new= malloc(sizeof(struct Node));
	new -> left = NULL;
	new -> right = NULL;
	new -> number = number;
	new -> balance_factor = 0;
	new -> height = 1;
	return new;
}

struct Node *rightRotate(struct Node *node){ 
	struct Node *newhead = node->left; 
    	struct Node *hold = newhead->right; 
    	newhead->right = node; 
    	node->left = hold; 
    	return newhead; 
} 
  
struct Node *leftRotate(struct Node *node){ 
    	struct Node *newhead = node->right; 
    	struct Node *hold = newhead->left; 
    	newhead->left = node; 
    	node->right = hold;
    	return newhead; 
} 
  
int getBalance(struct Node *N){ 
	update(head);
    	if (N == NULL) 
        	return 0; 
    	return N->balance_factor; 
} 
  

struct Node* insert(struct Node* node, int number){ 
    	if (node == NULL) 
        	return(newNode(number)); 
  
    	if (number < node->number) 
        	node->left  = insert(node->left, number); 
    	else if (number > node->number) 
        	node->right = insert(node->right, number); 
  
    	int balance = getBalance(node); 
	if (balance > 1){
		if (number < node->left->number) return rightRotate(node); 
		if (number > node->left->number){ 
			node->left =  leftRotate(node->left); 
			return rightRotate(node); 
		} 
	}
	else if (balance < -1){
		if (number > node->right->number) return leftRotate(node); 
		if (number < node->right->number){ 
			node->right = rightRotate(node->right); 
			return leftRotate(node); 
		} 
	} 
	return node; 
}



int lay(struct Node *node,int x){
	if (node==NULL) return 0;
	int flag=0;
	if (x==1){
		if (node->left!=NULL){ 
			printf("%d (%d L) (%d B) ", node->left->number, node->number, node->left->balance_factor);
			flag=1;
		}
		if (node->right!=NULL){ 
			printf("%d (%d R) (%d B) ", node->right->number, node->number, node->right->balance_factor);
			flag=1;
		}
	return flag;
	}
	else {int a = lay(node->left,x-1); int b=lay(node->right,x-1); return (a||b);}
}

void layerprint(struct Node *node){
	printf("\n%d (%d B) ", head->number, head->balance_factor);

	int layerflag=1;
	int layerno=1;
	while (layerflag){
		printf("\n");
		layerflag = lay(node,layerno);
		layerno++;
	}
}

void orderprint(struct Node *node){
	if (node==NULL) return;
	orderprint(node->left);
	printf("%d\n", node->number);
	orderprint(node->right);
}

int main(void){
int  number;
while (1){
	scanf("%d ", &number);
	if (number==-1) break;
	head=insert(head,number);

}
	update(head);
	orderprint(head);
	layerprint(head);
}
