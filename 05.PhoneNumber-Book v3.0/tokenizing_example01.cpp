#include <stdio.h>
#include <string.h>

int main() {
	char str[] = "now # is the time # to start preparing ### for the exam#";
	char delim[] = "#";
	char* token;

	token = strtok(str, delim);

	while (token != NULL) {
		printf("next token is: %s:%d\n", token, strlen(token));
		token = strtok(NULL, delim);
	}
	return 0;
}

//result
//next token is : now:4
//next token is : is the time : 13
//next token is : to start preparing : 20
//next token is : for the exam : 13