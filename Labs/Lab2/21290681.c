#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct intersectedNode {
    int data;
    int index1;
    int index2;
    struct intersectedNode *next;
};

struct intersectedNode* intersected_nodes(struct node *list1, struct node *list2) {
    struct intersectedNode* result = NULL;
    struct intersectedNode* tail = NULL;
    int index1 = 0;
    int index2 = 0;

	
    while (list1 != NULL) {
        struct node* temp2 = list2;
        index2 = 0;

        while (temp2 != NULL) {
            if (list1->data == temp2->data) {
                struct intersectedNode* newNode = (struct intersectedNode*)malloc(sizeof(struct intersectedNode));
                newNode->data = list1->data;
                newNode->index1 = index1 ; 
                newNode->index2 = index2 +1; 
                newNode->next = NULL;

                if (result == NULL) {
                    result = newNode;
                    tail = result;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
            }

            temp2 = temp2->next;
            index2++;
        }

        list1 = list1->next;
        index1++;
    }

    return result;
}


void printIntersectedNodes(struct intersectedNode* list) {
    while (list != NULL) {
        printf("%d %d %d\n", list->data, list->index1, list->index2);
        list = list->next;
    }
}



int main() {
    struct node* list1 = NULL;
    struct node* list2 = NULL;
    int data;

    while (1) {
        scanf("%d", &data);
        if (data == -1)
            break;

        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = list1;
        list1 = newNode;
    }

    while (1) {
        scanf("%d", &data);
        if (data == -1)
            break;

        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = list2;
        list2 = newNode;
    }

    struct intersectedNode* result = intersected_nodes(list2, list1);

    if (result != NULL) {
        printIntersectedNodes(result);
    } else {
        printf("-1\n");
    }}
