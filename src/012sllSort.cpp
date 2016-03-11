/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

struct node * createNode(int data) {
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

void insertNode(struct node **head, int data) {
	struct node *newnode = createNode(data);
	struct node *temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newnode;
}

void sll_012_sort(struct node *head){
	struct node *zero = NULL;
	struct node *one = NULL;
	struct node *two = NULL;
	struct node *node = head;
	while (node != NULL) {
		if (node->data == 0) {
			insertNode(&zero, 0);
		}
		else if (node->data == 1) {
			insertNode(&one, 1);
		}
		else {
			insertNode(&two, 2);
		}
		node = node->next;
	}
	head = zero;
	// 0's
	struct node *temp = zero;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	// 1's
	if (one != NULL) {
		temp->next = one;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	// 2's
	if (two != NULL) {
		temp->next = two;
	}
}