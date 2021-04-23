#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;

typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType *s){
	s->top = -1;
}

int is_empty(StackType *s){
	return s->top == -1;
}

int is_full(StackType *s){
	return s->top == (MAX_STACK_SIZE - 1);
}

void push(StackType *s, element item){
	if(is_full(s)){
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

element pop(StackType *s){
	if(is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

element peek(StackType *s){
	if(is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[(s->top)];
}

int size(StackType *s){
	return s->top + 1;
}

void StackQueue(StackType *s1, StackType *s2, int tmp,  int target){
	if(tmp == 1){
		push(s1, target);
	}
	else{
		if(is_empty(s2)){
			int l = size(s1);
			for(int i = 0; i < l; i++)
				push(s2, pop(s1));
		}
		else
			printf("%d ", pop(s2)); 
	}
}

int main(){
	StackType s1;
	StackType s2;
	init_stack(&s1);
	init_stack(&s2);
	StackQueue(&s1, &s2, 1, 5);
	StackQueue(&s1, &s2, 1, 4);
	StackQueue(&s1, &s2, 1, 2);
	StackQueue(&s1, &s2, 1, 1);
	StackQueue(&s1, &s2, 0, 0);
	StackQueue(&s1, &s2, 0, 0);
	StackQueue(&s1, &s2, 0, 0);
	StackQueue(&s1, &s2, 0, 0);
	StackQueue(&s1, &s2, 0, 0);
	return 0;
}
