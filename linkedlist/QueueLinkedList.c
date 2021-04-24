#include <stdio.h>
#include <malloc.h>

typedef int element;

typedef struct QueueNode {
	element data;
	struct QueueNode *link;
} QueueNode;

typedef struct {
	QueueNode *front, *rear;
} LinkedQueueType;

void enqueue(LinkedQueueType *q, element data)
{
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;
	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp;
	}
}

element dequeue(LinkedQueueType *q)
{
	QueueNode *temp =q-> front;
	element data;
	if (is_empty(q)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		data = temp->data;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		return data;
	}
}

