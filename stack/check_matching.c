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

int check_matching(char *str){
	StackType s;
	init_stack(&s);
	int n = strlen(str);
	for(int i = 0; i < n; i++){
		char ch = str[i];
		switch(ch){
			case '(':
			case '[':
			case '{':
				push(&s, ch);
				break;
			case ')':
			case ']':
			case '}':
				if(is_empty(&s))
					return 0;
				else{
					char op_ch = pop(&s);
					if((op_ch == '(' && ch != ')') || (op_ch == '[' && ch != ']') || (op_ch == '{' && ch != '}'))
						return 0;
					break;
				}
		}
	}
	if(is_empty(&s))
		return 1;
	else
		return 0;
}

int main(){
	char s[100];
	scanf("%s", s);
	if(check_matching(s))
		printf("괄호 검사 성공");
	else
		printf("괄호 검사 실패"); 
}
