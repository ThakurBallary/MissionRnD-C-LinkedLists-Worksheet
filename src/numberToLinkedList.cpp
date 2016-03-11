/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

void insertAtHead(struct node **head, int n) {
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	newnode->num = n;
	if (*head == NULL){
		newnode->next = NULL;
	}
	else {
		newnode->next = *head;
	}
	*head = newnode;
}

struct node * numberToLinkedList(int N) {
	struct node *head = NULL;
	if (N == 0) {
		insertAtHead(&head, 0);
	}
	else {
		if (N < 0) {
			N *= -1;  
		}
		while (N > 0) {
			insertAtHead(&head, N % 10);
			N /= 10;
		}
	}
	return head;
}