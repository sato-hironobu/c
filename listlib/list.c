#include <stdlib.h>
#include "list.h"

static Node *head = NULL;
static Node *last = NULL;
static int len = 0;

Node *L_append(int val) {

	Node *new = (Node *) malloc (sizeof(Node));

	new->val = val;
	new->next = NULL;
	if(!head) {
		head = last = new;
		new->prev = NULL;
	} else {
		last->next = new;
		new->prev = last;
		last = new;
	}

	len++;

	return new;
}

void L_pop(int index) {

	int i;
	Node *np;

	np = head;
	for (i = 0; i < index; i++) {
		if (np->next == NULL) {
			printf("L_pop: Index out of range\n");
			return;
		}
		np = np->next;
	}

	np->prev->next = np->next;
	np->next->prev = np->prev;
	free(np);

	len--;
}

Node *L_indexof(int val) {

	Node *np = head;
	while (np->val != val) {
		np = np->next;
	}

	return np;
}

int L_length(void) {

	return len;
}

void L_clear(void) {
	
	Node *np = last;
	while (np->prev) {
		np = np->prev;
		free(np->next);
	}
	free(head->next);
	head = NULL;
}

int L_get(int index) {

	int i;
	Node *np;

	np = head;
	for (i = 0; i < index; i++) {
		np = np->next;
	}

	return np->val;
}

int L_randomchoice(void) {

	srand((unsigned int) time(NULL));

	int len;
	int rind;
	int val;

	if (len <= 0) {
		printf("L_randomchoice: empty list\n");
		exit(1);
	}

	len = length();
	rind = rand() % len;
	val = L_get(rind);
	return val;
}
