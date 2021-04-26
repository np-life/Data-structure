#include<stdio.h>

int main()
{
	FILE* in_fp = fopen("input.txt", "r");
	FILE* out_fp = fopen("output.txt", "w");
	char buffer[100];
	while (fscanf(in_fp, "%s", buffer) != EOF)
		fprintf(out_fp, "%s ", buffer);
	
	fclose(in_fp);  // 파일 포인터가 가리키는 파일을 닫습니다.
	fclose(out_fp);

	return 0;
}