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
	word[5] = '\0';  // ���� '\0' �����ʴ´ٸ� �������� �Ͼ��??!

	printf("%s", word);
}