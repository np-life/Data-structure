#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	// int* array = (int*)malloc(4 * sizeof(int));  // 16����Ʈ�� �Ҵ�.
	int array[4];
	
	array[0] = 1;
	array[1] = 2;
	*(array + 2) = 3;

	int* tmp = (int*)malloc(8 * sizeof(int));
	int i;
	for (i = 0; i < 4; i++)
		tmp[i] = array[i];


	array = tmp;  // �� ������ �������� ��������! (�����ͺ����� �ƴ� �迭�� ����� �����ּҴ� ������ó�� ������ ������ ������ �Ұ����ϴ�!) 

	array[4] = 4;
	array[5] = 5;

	printf("%d", array[5]);
}