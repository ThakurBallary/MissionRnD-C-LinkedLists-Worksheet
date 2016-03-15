/*

Use MainLinkedLists1 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Do not write same add,display function in every CppFile .VS throws an error if two files
have some functions with same signature.
You can either change the signature in each file by using add1,display2 like that or 
keep a common header file which has functions for handling common tasks for debugging
like displaying and include that header file in each Problem file .

Only jump into this lesson after you did all specified functions in Tutorial Lesson.

Objectives of C-LinkedLists-1 Lesson:

->Add/Delete/Display nodes in SLL
->Manipulate Links in SLL
->Handling SLL which have nodes of more than one data field


*/


//Do not edit below Header Files
#include <stdio.h>
#include "FunctionHeadersLinkedLists1.h"
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

struct node * tcreateNode(int data) {
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

void tinsertNode(struct node **head, int data) {
	struct node *newnode = tcreateNode(data);
	struct node *temp = *head;
	if (*head == NULL) {
		*head = newnode;
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

void display(struct node **head){
	struct node *temp = *head;
	while (temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int main(){
	struct node *head = NULL;
	int num_array[5] = { 5, 3, 1, 2, 4 };
	int i, len = 5;
	for (i = 0; i<len; i++) {
		tinsertNode(&head, num_array[i]);
	}
	display(&head);
	head = sortLinkedList(head);
	printf("\n");
	display(&head);
	
		
	//Test numberToLinkedList
	/*
	int num = 1234;
	struct node *head = numberToLinkedList(num);
	*/
	
	//Test 012SortSll
	// sll_012_sort(head);

	//Test twodigitLinkedList
	// printf("\n%d", convert_sll_2digit_to_int(head)); 

	//Test removeEveryKthNode
	// head = removeEveryKthNode(head, 9);

	//Test sortLinkedList
	// head = sortLinkedList(head);
	
	
	return 0;
}