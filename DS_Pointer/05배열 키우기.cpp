	/*
* �迭 Ű���
	
	- �������� �Ҵ�� �迭�� ������ ������ ��� �� ū �迭�� �Ҵ��Ͽ� ����� �� �ִ�.

	int * array = (int *)malloc(4*sizeof(int));

	�迭 array�� ũ�Ⱑ ������ ��Ȳ�� �߻��Ѵ�.

	int *tmp = (int *)malloc(8*sizeof(int));
	int i;
	for (i=0; i<4; i++)
		tmp[i] = array[i];
	
	array = tmp;

	(example03-0.cpp ����)
	(example03-1.cpp ����)
	��*/