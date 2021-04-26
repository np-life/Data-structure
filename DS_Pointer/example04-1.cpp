#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100

int main() {
	
	char *words[100];   // 배열의 타입이란 각 배열칸에 저장되는 데이터의 타입입니다.
	int n = 0;			// 따라서 word는 각 문자열의 시작주소를 갖기때문에 (char *) 이어야 합니다.
	char buffer[BUFFER_SIZE];

	for (int n = 0; n < 4; n++)
	{
		scanf("%s", buffer);
		words[n] = _strdup(buffer);  // _strdup는 새로운 공간을 할당받아 복사하고 주소를 반환한다.
	}

	for (int i = 0; i < 4; i++)
		printf("%s\n", words[i]);
}