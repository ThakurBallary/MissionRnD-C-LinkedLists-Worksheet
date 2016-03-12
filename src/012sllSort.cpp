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

void sll_012_sort(struct node *head){
	int zeros = 0, ones = 0, twos = 0;
	struct node *node = head;
	while (node != NULL) {
		if (node->data == 0) {
			zeros++;
		}
		else if (node->data == 1) {
			ones++;
		}
		else {
			twos++;
		}
		node = node->next;
	}
	node = head;
	// 0's
	while (zeros) {
		node->data = 0;
		node = node->next;
		zeros--;
	}
	// 1's
	while (ones) {
		node->data = 1;
		node = node->next;
		ones--;
	}
	// 2's
	while (twos) {
		node->data = 2;
		node  = node->next;
		twos--;
	}
}