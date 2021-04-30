#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char* data;  // 데이터 필드.
	struct node* next;  // 링크 필드.
};
typedef struct node Node;
Node* head = NULL;

int main() 
{
	head = (Node*)malloc(sizeof(Node));
	head->data = "Tuesday";
	head->next = NULL;

	Node * q = (Node*)malloc(sizeof(Node));
	q->data = "Thursday";
	q->next = NULL;
	head->next = q;

	q = (Node*)malloc(sizeof(Node));
	q->data = "Monday";
	q->next = head;
	head = q;

	Node* p = head;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}
}