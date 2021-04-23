#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef char element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
 
void init_deque(DequeType *q)
{
	q->front = q->rear = 0;
}

int is_empty(DequeType *q)
{
	return (q->front == q->rear);
}

int is_full(DequeType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void add_rear(DequeType *q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element delete_front(DequeType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element get_front(DequeType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType *q, element val)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType *q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[q->rear];
}

int size(DequeType *dq){
   return (dq->rear - dq->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

int palindrome(char str[]){
	DequeType dq;
	init_deque(&dq);
	int l = strlen(str);
	for(int i = 0; i < l; i++)
		add_front(&dq, str[i]);
	for(int i = 0; i < l / 2; i++){
		char op1 = delete_front(&dq);
		char op2 = delete_rear(&dq);
		if(op1 != op2)
			return 0;
	}
	return 1;
}

int main(){
	char str[100];
	scanf("%s", str);
	int new_str_len = 0;
	char new_str[100];
	for(int i = 0; i <strlen(str); i++){
		if(('a'<= str[i] && str[i] <= 'z'))
			new_str[new_str_len++] = str[i] - 32;
		else if(('A'<= str[i] && str[i] <= 'Z'))
			new_str[new_str_len++] = str[i];
	}
	if(palindrome(new_str))
		printf("회문 O");
	else
		printf("회문 X");
	return 0;
}
