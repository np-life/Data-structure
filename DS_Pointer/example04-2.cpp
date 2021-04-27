#include<stdio.h>

int main()
{
	FILE* fp = fopen("input.txt", "r"); // 파일을 오픈하고 파일 포인터가 해당 파일을 가리킵니다.
	char buffer[100];
	while (fscanf(fp, "%s", buffer) != EOF)
		printf("%s ", buffer); // while 조건문에서 파일 포인터 위치의 문자열을 buffer로 읽어오고 읽어지면 buffer를 출력. (반복)
	fclose(fp);  // 파일 포인터가 가리키는 파일을 닫습니다.

	return 0;
}