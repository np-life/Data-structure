#include <stdio.h>

int calculate_sum(int array[]);

int main() {
	int sum, i, average;
	int num[10];

	for (i = 0; i < 10; i++)
		scanf("%d", &num[i]);
	// vs 2013 부터는 scanf unsafe 관련 오류 발생시 _CRT_SECURE_NO_WARNINGS 을 사용합니다. 
	// 프로젝트 속성 C/C++ 전처리기 추가.

	sum = calculate_sum(num);
	// 사실은 num으로 넘겨준건 배열이 시작되는곳 시작 주소를 넘겨준것이죠.

	average = sum / 10;
	printf("%d\n", average);
	return 0;
}

int calculate_sum(int array[])  // 따라서 int array[] 대신 int *array 라고 매개변수를 줘도 정확히 같은 일을 합니다.
{
	int sum, i;
	sum = 0;
	for (i = 0; i < 10; i++)
		sum = sum + array[i];  // instead of array[i],  *(array+i) 와 같은 동작을 합니다..
	return sum;
}