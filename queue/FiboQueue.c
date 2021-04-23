#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef int element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element front(QueueType *q){
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int size(QueueType *q){
   return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

int FiboQueue(QueueType *q, int n){
	if(n == 0)
		return dequeue(q);
	else{
		int op1 = dequeue(q);
		int op2 = front(q);
		enqueue(q, op1 + op2);
		return FiboQueue(q, n-1);
	}
}

int main(){
	QueueType q;
	init_queue(&q);
	int n;
	scanf("%d", &n);
	enqueue(&q, 0);
	enqueue(&q, 1);
	printf("%d", FiboQueue(&q, n));
	return 0;
}
