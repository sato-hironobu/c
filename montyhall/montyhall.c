#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	int doors;

	srand((unsigned int) time(NULL));

	if (argc > 1) {
		doors = atoi(argv[1]) ;
		doors = doors < 3 ? 3 : doors;
	} else {
		doors = 3;
	}

	montyhall(doors);

	return 0;
}

int montyhall(int doors) {

	int answer;
	int first_choice;
	int hint;
	int second_choice;
	int result;

	answer = random()

}

	
