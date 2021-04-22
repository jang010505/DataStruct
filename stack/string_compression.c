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

element peek(StackType *s){
	if(is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)];
}

void string_compression(char str[]){
	char new_str[100];
	StackType s;
	init_stack(&s);
	int len = 0;
	for(int i = 0; i < strlen(str); i++){
		char ch = str[i];
		if(is_empty(&s) == 0 && ch != peek(&s)){
			char top = peek(&s);
			int cnt = 0;
			while(!is_empty(&s)){
				cnt++;
				pop(&s);
			}
			char num_str[100];
			sprintf(num_str, "%d", cnt);
			for(int i = 0; i < strlen(num_str); i++)
				new_str[len++] = num_str[i];
			new_str[len++] = top;
		}
		push(&s, ch);
	}
	if(is_empty(&s) == 0){
		char top = peek(&s);
		int cnt = 0;
		while(!is_empty(&s)){
			cnt++;
			pop(&s);
		}
		char num_str[100];
		sprintf(num_str, "%d", cnt);
		for(int i = 0; i < strlen(num_str); i++)
			new_str[len++] = num_str[i];
		new_str[len++] = top;
	}
	printf("%s", new_str);
}

int main(){
	char str[100];
	char new_str[100];
	int new_str_len = 0;
	scanf("%s", str);
	for(int i = 0; i <strlen(str); i++){
		if(('a'<= str[i] && str[i] <= 'z'))
			new_str[new_str_len++] = str[i];
		else if(('A'<= str[i] && str[i] <= 'Z'))
			new_str[new_str_len++] = str[i] + 32;
	}
	string_compression(new_str);
	return 0;
}
