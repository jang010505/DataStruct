#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef int element;

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
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element delete_front(DequeType *q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element get_front(DequeType *q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType *q, element val)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType *q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType *q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[q->rear];
}