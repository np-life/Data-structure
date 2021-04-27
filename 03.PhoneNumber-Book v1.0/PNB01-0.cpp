#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CARACITY 100
#define BUFFER_SIZE	20

char* names[CARACITY];
char* numbers[CARACITY];
int n = 0;

void add();
//void find();
//void status();
//void remove();

int main()
{
	char command[BUFFER_SIZE];
	while (1) {
		printf("$ ");
		scanf("%s", command);

		if (strcmp(command, "add") == 0)
			add();
		//else if (strcmp(command, "find") == 0)
		//	find();
		//else if (strcmp(command, "status") == 0)
		//	status();
		//else if (strcmp(command, "delete") == 0)
		//	remove();
		//else if (strcmp(command, "exit") == 0)
		//	break;
	}
	return 0;
}

void add() {
	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
	scanf("%s", buf1);
	scanf("%s", buf2);

	names[n] = _strdup(buf1);
	numbers[n] = _strdup(buf2);
	n++;

	printf("%s was added successfully.\n", buf1);
}

