	/*
* 전화번호부 v1.0 실행 (PNB01-0.cpp)

	프로그램을 실행하면 화면에 프롬프트($)를 출력하고 사용자의 명령을 기다린다.

	$ add John 01077772222   새로운 사람을 추가한다.

	$ find Henry	이름으로 전화번호를 검색한다.

	$ status	전화번호부에 저장된 모든 사람을 출력한다.

	$ delete Jim	전화번호부에서 삭제한다.

	$ exit	프로그램을 종료한다.

	이름이 존재하지않는 경우엔 적절한 메세지를 출력하게하고 
	명령을 수행하면 이때도 적절한 메세지를 출력시키자.


* 자료구조.
	
	이 프로그램이 내부적으로 저장해야되는 데이터를 명확하게 인식. - 이름과 전화번호.
	가장 기본적인 접근 방법. - 두개의 문자열 포인터 배열. names numbers





+ C언어에서 메모리 레이아웃
	
	stack 지역변수

	heap 동적으로 할당된 메모리 (malloc)
	data section 전역변수
	code 
	
	*/