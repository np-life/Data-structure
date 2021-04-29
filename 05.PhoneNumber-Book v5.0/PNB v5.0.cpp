#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INIT_CAPACITY 100
#define BUFFER_SIZE	50

typedef struct person {
	char* name;
	char* number;
	char* email;
	char* group;
} Person;

void init();
int read_line(FILE* fp, char str[], int n);
void load(char* fileName);
void save(char* fileName);
int compose_name(char str[], int limit);
void add(char* name, char* number, char* email, char* group);
void reallocate();
void find(char* name);
int search(char* name);
void remove(char* name);
void release_person(Person* p);
void status();
void handle_add(char* name);
void print_person(Person* p);

Person ** directory;
int capacity;
int n;

int noway;

int main()
{
	
	char command_line[BUFFER_SIZE];
	char* command, * argument;
	char name_str[BUFFER_SIZE];

	init();
	while (1) {
		printf("$ ");
		if (read_line(stdin, command_line, BUFFER_SIZE) <= 0)
			continue;
		command = strtok(command_line, " ");

		if (strcmp(command, "read") == 0) {
			argument = strtok(NULL, " ");
			if (argument == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			load(argument);
		}
		else if (strcmp(command, "save") == 0) {
			argument = strtok(NULL, " ");
			if (strcmp(argument, "as") != 0) {
				printf("Invalid arguments.\n");
				continue;
			}
			argument = strtok(NULL, " ");
			if (argument == NULL) {
				printf("Invalid argument.\n");
				continue;
			}
			save(argument);
		}
		else if (strcmp(command, "add") == 0) {
			if (compose_name(name_str, BUFFER_SIZE) <= 0) {
				printf("Name required.\n");
				continue;
			}
			printf("%s\n", name_str);
			handle_add(name_str);
		}
		else if (strcmp(command, "find") == 0) {
			if (compose_name(name_str, BUFFER_SIZE) <= 0) {
				printf("Name required.\n");
				continue;
			}
			find(name_str);
		}
		else if (strcmp(command, "status") == 0) {
			status();
		}
		else if (strcmp(command, "delete") == 0) {
			if (compose_name(name_str, BUFFER_SIZE) <= 0) {
				printf("Invalid arguments.\n");
				continue;
			}
			remove(name_str);
		}
		else if (strcmp(command, "exit") == 0) {
			break;
		}
	}

	return 0;
}

void init() {
	directory = (Person**)malloc(INIT_CAPACITY * sizeof(Person*));
	capacity = INIT_CAPACITY;
	n = 0;
}
int read_line(FILE* fp, char str[], int n)
{
	int ch, i = 0;

	while ((ch = fgetc(fp)) != '\n' && ch != EOF)
		if (i < n)
			str[i++] = ch;

	str[i] = '\0';
	return i;
}
void load(char* fileName) {
	char buffer[BUFFER_SIZE];
	char* name, * number, * email, * group;
	char* token;
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}
	while (1) {
		if (read_line(fp, buffer, BUFFER_SIZE) <= 0)
			break;
		
		name = strtok(buffer, "#");

		token = strtok(NULL, "#");
		if (strcmp(token, " ") == 0)
			number = NULL;
		else
			number = _strdup(token);
		
		token = strtok(NULL, "#");
		if (strcmp(token, " ") == 0)
			email = NULL;
		else
			email = _strdup(token);
		
		token = strtok(NULL, "#");
		if (strcmp(token, " ") == 0)
			group = NULL;
		else
			group = _strdup(token);
		
		add(_strdup(name), number, email, group);
	}
	fclose(fp);
}
void save(char* fileName) {
	int i;
	FILE* fp = fopen(fileName, "w");
	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}
	for (i = 0; i < n; i++) {
		fprintf(fp, "%s#", directory[i]->name);
		fprintf(fp, "%s#", directory[i]->number);
		fprintf(fp, "%s#", directory[i]->email);
		fprintf(fp, "%s#\n", directory[i]->group);
	}
	fclose(fp);
}
int compose_name(char str[], int limit) {
	char* ptr;
	int length = 0;

	ptr = strtok(NULL, " ");
	if (ptr == NULL)
		return 0;
	strcpy(str, ptr);
	printf("%s\n", str);
	length += strlen(ptr);

	while ((ptr = strtok(NULL, " ")) != NULL) {
		if (length + strlen(ptr) + 1 < limit) {
			str[length++] = ' ';
			str[length] = '\0';
			strcat(str, ptr);
			length += strlen(ptr);
		}
	}
	return length;
}
void add(char* name, char* number, char* email, char* group) {
	if (n >= capacity)
		reallocate();

	int i = n - 1;
	while (i >= 0 && strcmp(directory[i]->name, name) > 0) {
		directory[i + 1] = directory[i];
		i--;
	}
	//char* Name = (char*)malloc(sizeof(char));
	directory[i + 1] = (Person*)malloc(sizeof(Person));

	directory[i + 1]->name = name;
	directory[i + 1]->number = number;
	directory[i + 1]->email = email;
	directory[i + 1]->group = group;

	printf("%s ", directory[i + 1]->name);
	printf("%s ", directory[i + 1]->number);
	printf("%s ", directory[i + 1]->email);
	printf("%s\n", directory[i + 1]->group);
	n++;
}
void reallocate() {
	capacity *= 2;
	Person ** tmp = (Person **)malloc(capacity * sizeof(Person *));
	if (tmp != NULL){
		for (int i = 0; i < n; i++)
			tmp[i] = directory[i];
		free(directory);
		directory = tmp;
	}
}
void find(char* name) {
	int index = search(name);
	if (index == -1)
		printf("No person named '%s' exists.\n", name);
	else
		print_person(directory[index]);
}
int search(char* name) {
	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(name, directory[i]->name) == 0)
			return i;
	}
	return -1;
}
void remove(char* name) {
	int i = search(name);
	printf("%d\n", i);
	if (i == -1) {
		printf("No person named '%s' exists.\n", name);
		return;
	}

	Person* p = directory[i];
	for (int j = i; j < n - 1; j++)
		directory[j] = directory[j + 1];
	n--;
	release_person(p);
	printf("'%s' was deleted successfully. \n", name);
}
void release_person(Person* p) {
	free(p->name); // ���⼭ ����.
	if (p->number != NULL) free(p->number);
	if (p->email != NULL) free(p->email);
	if (p->group != NULL) free(p->group);
	free(p);
}
void status() {
	int i;
	for (i = 0; i < n; i++)
		print_person(directory[i]);
	printf("Total %d persons.\n", n);
}
void handle_add(char* name) {
	char number[BUFFER_SIZE], email[BUFFER_SIZE], group[BUFFER_SIZE];
	char * _name, * _number, * _email, * _group;

	printf("    Phone: ");
	read_line(stdin, number, BUFFER_SIZE);
	if (strlen(number) > 0)
		_number = _strdup(number);
	else
		_number = NULL;
	printf("    Email: ");
	read_line(stdin, email, BUFFER_SIZE);
	if (strlen(number) > 0)
		_email = _strdup(email);
	else
		_email = NULL;
	printf("    Group: ");
	read_line(stdin, group, BUFFER_SIZE);
	if (strlen(number) > 0)
		_group = _strdup(group);
	else
		_group = NULL;
	add(_strdup(name), _number, _email, _group);
}
void print_person(Person *p)
{
	printf("%s:\n", p->name);
	printf("    Phone: %s\n", p->number);
	printf("    Email: %s\n", p->email);
	printf("    Group: %s\n", p->group);
}
