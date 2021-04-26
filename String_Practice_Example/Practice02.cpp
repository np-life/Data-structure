// Practice02.cpp - 압축하기.
// 
// 공백문자들이 문장의 앞, 중간, 뒤에 포함되어 있다.
// 문장의 앞과 뒤에 붙은 공백문자들은 제거하고 
// 단어 사이에 두 개 이상의 연속된 공백문자들은 하나의 공백 문자로 대체하라.


// 문제풀이
// 
// 출력용 배열을 할당 받고 제일 최근에 받아쓴 문자상태를 기억. 초기상태는 공백.
// 공백문자가 아닌 문자가 나올때까지 읽다가 최초의 문자가 나오면 
// 출력용 배열에 해당 문자를 쓰고 상태를 문자로 변경.
// 상태가 문자이면서 다음 문자가 문자면 출력용 배열에 쓰고
// 상태가 문자이면서 다음 문자가 공백이면 상태를 공백으로 바꾸고 출력용 배열에 쓰고
// 상태가 공백이면서 다음 문자가 공백이면 패스.
// 상태가 공백이면서 다음 문자가 문자면 상태를 문자로 변경하고 출력용 배열에 쓰고.
// 다음 문자를 확인할때마다 해당 문자가 \0인지 확인하고 만약에 \0이면 종료합니다.

// 강의풀이

#include <stdio.h>
#include <ctype.h> // isspace 함수 제공.

int read_line_with_compression(char compressed[], int limit);

int main()
{
	char line[80];
	while (1)
	{
		printf("$ ");
		int length = read_line_with_compression(line, 80);
		printf("%s:%d\n", line, length);
	}
	return 0;
}

int read_line_with_compression(char compressed[], int limit)
{
	int ch, i = 0;
	while ((ch = getchar()) != '\n')
	{
		if (i < limit - 1 && (!isspace(ch) || i > 0 && !isspace(compressed[i - 1])))
			compressed[i++] = ch;
	}
	if (i > 0 && isspace(compressed[i - 1]))
		i--;
	compressed[i] = '\0';
	return i;
}