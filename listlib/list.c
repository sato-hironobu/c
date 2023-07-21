#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

/***********************************************
*
* list  +-> node  +-> node  +-> ...   +-> node
*       |         |         |         |   ^
* head -+   next -+   next -+   ...  -+   |
*                                         |
* last -----------------------------------+
*
************************************************/

void L_init(Lptr lptr) {
	
	lptr->head = NULL;
	lptr->last = NULL;
	lptr->length = 0;
}

void L_append(Lptr lptr, int val) {

	Node *new = (Node *) malloc (sizeof(Node));

	new->val = val;
	new->next = NULL;
	if(lptr->head == NULL) {
		lptr->head = lptr->last = new;
		new->prev = NULL;
	} else {
		lptr->last->next = new;
		new->prev = lptr->last;
		lptr->last = new;
	}

	lptr->length++;

}

void L_pop(Lptr lptr, int index) {

	int i;
	Node *np;

	np = lptr->head;
	for (i = 0; i < index; i++) {
		if (np->next == NULL) {
			printf("L_pop: Index out of range.\n");
			exit(1);
		}
		np = np->next;
	}

	if (np->prev == NULL) {
		lptr->head = np->next;
		np->next->prev = NULL;
	} else if (np->next == NULL) {
		np->prev->next = NULL;
		lptr->last = np->prev;
	} else {
		np->prev->next = np->next;
		np->next->prev = np->prev;
	}
	free(np);

	lptr->length--;
}

int L_indexof(Lptr lptr, int val) {

	Node *np = lptr->head;
	int index = 0;
	
	if (np->val == val) {
		return index;
	}
	while (np->next != NULL) {
		np = np->next;
		index++;
		if (np->val == val) {
			return index;
		}
	}
	
	printf("L_indexof: No such value.\n");
	exit(1);
}

void L_clear(Lptr lptr) {
	
	Node *np = lptr->last;
	while (np->prev != NULL) {
		np = np->prev;
		free(np->next);
	}
	free(lptr->head);
	lptr->head = NULL;
	lptr->last = NULL;
	lptr->length = 0;
	
	#ifdef DEBUG
	printf("L_clear: done.\n");
	#endif
}

int L_get(Lptr lptr, int index) {

	if (index < 0 || index >= lptr->length) {
		printf("L_get: Index out of range.\n");
		exit(1);
	}

	int i;
	Node *np;

	np = lptr->head;
	for (i = 0; i < index; i++) {
		np = np->next;
	}

	return np->val;
}

int L_randomchoice(Lptr lptr) {

	if (lptr->length <= 0) {
		printf("L_randomchoice: empty list.\n");
		exit(1);
	}

	int len;
	int i;
	int val;

	i = rand() % lptr->length;
	val = L_get(lptr, i);
	return val;
}

void L_print(Lptr lptr) {

	Node *np = lptr->head;
	int i;
	
	printf("length = %d\n", lptr->length);
	while (np->next != NULL) {
		printf("[%d]", np->val);
		np = np->next;
	}
	printf("[%d]\n", np->val);
	
}