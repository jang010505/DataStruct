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

void count_Parenthesis(char str[]){
	
	StackType s;
	
	init_stack(&s);
	
	int count = 0;
	
   for (int i = 0; str[i] != NULL; i++) {
      if (str[i] == '(') {
         ++count;
         push(&s, count);
         printf("%d ", count);
      }
      else if (str[i] == ')') {
         printf("%d ", pop(&s));
      }
 	}
}
int main() {
   char str[100];

   StackType s;

   printf("���� : ");
   scanf("%s", str);

   count_Parenthesis(str);
   return 0;
}