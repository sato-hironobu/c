/* INCLUDE FILES */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../listlib/list.h"

/* CONSTANTS */
#define TRUE		1
#define FALSE		0
#define CORRECT		1
#define WRONG		0

/* EXTERN VARIABLES */
static int ANSWER			= -1;
static int FIRST_CHOICE		= -1;
static int HINT				= -1;
static int SECOND_CHOICE	= -1;
static int CHANGE			= -1;
static int RESULT			= -1;

/* FUNCTION PROTOTYPES */
void	montyhall(int);
void	print_result(void);

/* function main */
int main(int argc, char *argv[]) {

	srand((unsigned int) time(NULL));

	int doors;
	int i;

	if (argc > 1) {
		doors = atoi(argv[1]) ;
		doors = doors < 3 ? 3 : doors;
	} else {
		doors = 3;
	}
	
	printf("%d doors monty hall problem\n", doors);

	CHANGE = TRUE;
	
	for (i = 0; i < 10; i++) {
		montyhall(doors);
		print_result();
	}

	return 0;
}

/* function print_result */
void print_result(void) {

	printf("=========================================\n");
	printf("answer       : %d\n", ANSWER);
	printf("first choice : %d\n", FIRST_CHOICE);
	printf("hint         : %d\n", HINT);
	printf("change       : %s\n", CHANGE ? "True" : "False");
	printf("second choice: %d\n", SECOND_CHOICE);
	printf("result       : ");
	printf(RESULT ? "Correct!\n" : "Wrong...\n");
	printf("=========================================\n");

}

/* function montyhall */
void montyhall(int doors) {

	List door_list;
	int i;
	
	// Initialize the door list
	L_init(&door_list);
	for (i = 0; i < doors; i++) {
		L_append(&door_list, i);
	}
	
	// Determine ANSWER & FIRST_CHOICE
	ANSWER = rand() % doors;
	FIRST_CHOICE = rand() % doors;
	
	// HINT will be chosen from doors not equal to neither ANSWER nor FIRST_CHOICE
	L_pop(&door_list, L_indexof(&door_list, ANSWER));
	if (ANSWER != FIRST_CHOICE) {
		L_pop(&door_list, L_indexof(&door_list, FIRST_CHOICE));
	}
	HINT = L_randomchoice(&door_list);
	
	// Initialize door list (to determine the next choice)
	L_clear(&door_list);
	for (i = 0; i < doors; i++) {
		L_append(&door_list, i);
	}
	
	// Determine the SECOND_CHOICE
	if (CHANGE) {
		L_pop(&door_list, L_indexof(&door_list, FIRST_CHOICE));
		L_pop(&door_list, L_indexof(&door_list, HINT));
		SECOND_CHOICE = L_randomchoice(&door_list);
	} else {
		SECOND_CHOICE = FIRST_CHOICE;
	}
	
	// RESULT
	RESULT = (ANSWER == SECOND_CHOICE) ? CORRECT : WRONG;
	
	return;

}

	
