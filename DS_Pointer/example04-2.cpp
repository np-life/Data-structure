#include<stdio.h>

int main()
{
	FILE* fp = fopen("input.txt", "r"); // ������ �����ϰ� ���� �����Ͱ� �ش� ������ ����ŵ�ϴ�.
	char buffer[100];
	while (fscanf(fp, "%s", buffer) != EOF)
		printf("%s ", buffer); // while ���ǹ����� ���� ������ ��ġ�� ���ڿ��� buffer�� �о���� �о����� buffer�� ���. (�ݺ�)
	fclose(fp);  // ���� �����Ͱ� ����Ű�� ������ �ݽ��ϴ�.

	return 0;
}