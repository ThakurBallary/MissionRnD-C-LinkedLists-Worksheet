/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	struct node *temp = head;
	if (temp == NULL) {
		return NULL;
	}
	while (temp->next != NULL) {
		struct node *fp = temp->next;
		while (fp != NULL) {
			if (temp->num > fp->num) {
				int t = temp->num;
				temp->num = fp->num;
				fp->num = t;
			}
			fp = fp->next;
		}
		temp = temp->next;
	}
	return head;
}