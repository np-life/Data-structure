#include <stdio.h>

int calculate_sum(int array[]);

int main() {
	int sum, i, average;
	int num[10];

	for (i = 0; i < 10; i++)
		scanf("%d", &num[i]);
	// vs 2013 ���ʹ� scanf unsafe ���� ���� �߻��� _CRT_SECURE_NO_WARNINGS �� ����մϴ�. 
	// ������Ʈ �Ӽ� C/C++ ��ó���� �߰�.

	sum = calculate_sum(num);
	// ����� num���� �Ѱ��ذ� �迭�� ���۵Ǵ°� ���� �ּҸ� �Ѱ��ذ�����.

	average = sum / 10;
	printf("%d\n", average);
	return 0;
}

int calculate_sum(int array[])  // ���� int array[] ��� int *array ��� �Ű������� �൵ ��Ȯ�� ���� ���� �մϴ�.
{
	int sum, i;
	sum = 0;
	for (i = 0; i < 10; i++)
		sum = sum + array[i];  // instead of array[i],  *(array+i) �� ���� ������ �մϴ�..
	return sum;
}