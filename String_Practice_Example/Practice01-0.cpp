// 프로그램을 실행하면 화면에 프롬프트($)와 한칸의 공백문자를 출력하고 사용자의 입력을 기다린다.
// 문장을 입력하고 리턴 키를 킨다.
//리턴을 제외하고 입력한 문장을 그대로 출력하고 입력한 문장의 길이를 출력한다.
// 공백문자도 포함하여 카운트한다.
// 문장의 앞뒤에 붙은 공백까지 그대로 출력해야 한다.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char buffer[40];

	while (1) {
		printf("$ ");
		// 1번째 방법.
		//gets_s(buffer); // 라인단위의 문자열을 입력받는 함수 gets_s()
		// 
		// 2번째 방법.
		fgets(buffer, 10, stdin);  // 결과? 문자수+1, \n 문자까지 계산!, 해결책? 버퍼의 마지막글자를 임의로 변경 \0
		buffer[strlen(buffer) - 1] = '\0';  // 하지만 문제는 계속 존재합니다. 버퍼 사이즈 보다 입력이 커버리면 남아버리고 이것은 버그.
		
		printf("%s:%d\n", buffer, strlen(buffer));
	}
}

// 3번째 방법. 내가 직접 read_line 함수를 만들어서 사용. (Practice01-3.cpp) 