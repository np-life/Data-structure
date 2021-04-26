#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 20

int read_line(char str[], int limit);

int main()
{
	int len;
	char buffer[40];

	while (1) {
		printf("$ ");
		len = read_line(buffer, BUFFER_SIZE);
		printf("%s:%d\n", buffer, len);
	}
}

int read_line(char str[], int limit) {
	int ch, i = 0;  // getchar()�� ���� Ÿ���� int �Դϴ�.

	while ((ch = getchar()) != '\n')  // getchar() ǥ�� ���̺귯�� �Լ�, �ѹ��ھ� �о ch�� ��ȯ.
		if (i < limit)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}
 