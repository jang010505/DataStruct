#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 1000

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType *q) {
	q->rear = -1;
	q->front = -1;
}

int is_full(QueueType *q) {
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

int is_empty(QueueType *q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(QueueType *q, int item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;
}

element dequeue(QueueType *q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	element item = q->data[++(q->front)];
	return item;
}

element front(QueueType *q){
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int size(QueueType *q){
   return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
