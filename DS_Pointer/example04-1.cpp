#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100

int main() {
	
	char *words[100];   // �迭�� Ÿ���̶� �� �迭ĭ�� ����Ǵ� �������� Ÿ���Դϴ�.
	int n = 0;			// ���� word�� �� ���ڿ��� �����ּҸ� ���⶧���� (char *) �̾�� �մϴ�.
	char buffer[BUFFER_SIZE];

	for (int n = 0; n < 4; n++)
	{
		scanf("%s", buffer);
		words[n] = _strdup(buffer);  // _strdup�� ���ο� ������ �Ҵ�޾� �����ϰ� �ּҸ� ��ȯ�Ѵ�.
	}

	for (int i = 0; i < 4; i++)
		printf("%s\n", words[i]);
}