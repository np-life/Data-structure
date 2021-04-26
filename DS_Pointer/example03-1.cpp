#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	// int* array = (int*)malloc(4 * sizeof(int));  // 16바이트를 할당.
	int array[4];
	
	array[0] = 1;
	array[1] = 2;
	*(array + 2) = 3;

	int* tmp = (int*)malloc(8 * sizeof(int));
	int i;
	for (i = 0; i < 4; i++)
		tmp[i] = array[i];


	array = tmp;  // 왜 오류가 나는지를 이해하자! (포인터변수가 아닌 배열로 선언된 시작주소는 포인터처럼 쓸수는 있지만 편집은 불가능하다!) 

	array[4] = 4;
	array[5] = 5;

	printf("%d", array[5]);
}