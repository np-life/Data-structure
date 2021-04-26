#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100

int main() {
	char word[10];
	word[0] = 'h';
	word[1] = 'e';
	word[2] = 'l';
	word[3] = 'l';
	word[4] = 'o';
	word[5] = '\0';  // 만약 '\0' 쓰지않는다면 무슨일이 일어날까??!

	printf("%s", word);
}