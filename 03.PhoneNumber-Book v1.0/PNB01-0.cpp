#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CARACITY 100
#define BUFFER_SIZE	20

char* names[CARACITY];
char* numbers[CARACITY];
int n = 0;

void add();
void find();
void status();
void remove();

int main()
{
	char command[BUFFER_SIZE];
	while (1) {
		printf("$ ");
		scanf("%s", command);

		if (strcmp(command, "add") == 0)
			add();
		else if (strcmp(command, "find") == 0)
			find();
		else if (strcmp(command, "status") == 0)
			status();
		else if (strcmp(command, "delete") == 0)
			remove();
		else if (strcmp(command, "exit") == 0)
			break;
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

void find() {
	char buf[BUFFER_SIZE];
	scanf("%s", buf);

	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(buf, names[i]) == 0) {
			printf("%s\n", numbers[i]);
			return;
		}
	}
	printf("No person named '%s' exists.\n", buf);
}

void status() {
	int i;
	for (i = 0; i < n; i++)
		printf("%s   %s\n", names[i], numbers[i]);
	printf("Total %d persons.\n", n);
}

void remove() { // name ��ġ�� �����ϰ� ���� ������ name�� ������ ��ġ�� �����մϴ�.
	char buf[BUFFER_SIZE];
	scanf("%s", buf);

	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(buf, names[i]) == 0) {
			names[i] = names[n - 1];
			numbers[i] = numbers[n - 1];
			n--;
			printf("'%s' was deleted successfully. \n", buf);
			return;
		}
	}
	printf("No person named '%s' exists. \n", buf);
}