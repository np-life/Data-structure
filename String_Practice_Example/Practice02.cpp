// Practice02.cpp - �����ϱ�.
// 
// ���鹮�ڵ��� ������ ��, �߰�, �ڿ� ���ԵǾ� �ִ�.
// ������ �հ� �ڿ� ���� ���鹮�ڵ��� �����ϰ� 
// �ܾ� ���̿� �� �� �̻��� ���ӵ� ���鹮�ڵ��� �ϳ��� ���� ���ڷ� ��ü�϶�.


// ����Ǯ��
// 
// ��¿� �迭�� �Ҵ� �ް� ���� �ֱٿ� �޾ƾ� ���ڻ��¸� ���. �ʱ���´� ����.
// ���鹮�ڰ� �ƴ� ���ڰ� ���ö����� �дٰ� ������ ���ڰ� ������ 
// ��¿� �迭�� �ش� ���ڸ� ���� ���¸� ���ڷ� ����.
// ���°� �����̸鼭 ���� ���ڰ� ���ڸ� ��¿� �迭�� ����
// ���°� �����̸鼭 ���� ���ڰ� �����̸� ���¸� �������� �ٲٰ� ��¿� �迭�� ����
// ���°� �����̸鼭 ���� ���ڰ� �����̸� �н�.
// ���°� �����̸鼭 ���� ���ڰ� ���ڸ� ���¸� ���ڷ� �����ϰ� ��¿� �迭�� ����.
// ���� ���ڸ� Ȯ���Ҷ����� �ش� ���ڰ� \0���� Ȯ���ϰ� ���࿡ \0�̸� �����մϴ�.

// ����Ǯ��

#include <stdio.h>
#include <ctype.h> // isspace �Լ� ����.

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