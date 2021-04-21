#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element;

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
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

element pop(StackType *s){
	if(is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

int palindrome(char str[]){
	char pop_str[100];
	StackType s;
	for(int i = 0; i < strlen(str); i++)
		push(&s, str[i]);
	for(int i = 0; i < strlen(str); i++)
		pop_str[i] = pop(&s);
	if(!strcmp(str, pop_str))
		return 1;
	else
		return 0;
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
