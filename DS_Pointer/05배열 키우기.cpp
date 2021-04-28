	/*
* 배열 키우기
	
	- 동적으로 할당된 배열은 공간이 부족할 경우 더 큰 배열을 할당하여 사용할 수 있다.

	int * array = (int *)malloc(4*sizeof(int));

	배열 array의 크기가 부족한 상황이 발생한다.

	int *tmp = (int *)malloc(8*sizeof(int));
	int i;
	for (i=0; i<4; i++)
		tmp[i] = array[i];
	
	array = tmp;

	(example03-0.cpp 참조)
	(example03-1.cpp 참조)
	ㅇ*/