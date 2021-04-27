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
	int ch, i = 0;  // getchar()의 리턴 타입은 int 입니다.

	while ((ch = getchar()) != '\n')  // getchar() 표준 라이브러리 함수, 한문자씩 읽어서 ch에 반환.
		if (i < limit)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}
 