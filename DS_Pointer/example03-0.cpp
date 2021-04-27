#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int *array = (int*)malloc(4 * sizeof(int));  // 16바이트를 할당.
	array[0] = 1;
	array[1] = 2;
	*(array + 2) = 3;

	int* tmp = (int*)malloc(8 * sizeof(int));
	int i;
	for (i = 0; i < 4; i++)
		tmp[i] = array[i];


	// 하지만 내생각엔 기존에 array가 가지고있던 주소공간을 먼저좀 할당을 풀어주는게 좋아보이는데. - 쓰레기 공간이 발생!
	array = tmp;

	array[4] = 4;
	array[5] = 5;

	printf("%d", array[5]);
}