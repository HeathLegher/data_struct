#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
	int *data;
	int size, top, cmp;
}stack;

stack *initStack(int cmp){
	stack *s = (stack *)malloc(sizeof(stack));
	s->data = (int *)malloc(sizeof(int) * cmp);
	s->cmp = cmp;
	s->size = 0;
	s->top = -1;
	return s;
}

void deleteStack(stack *s){
	free(s->data);
	free(s);
}

void getTop(stack *s){
	printf("the top :%d\n",s->top);	
}

void pushStack(stack *s, int val){
	if(s->size == s->cmp){
		s->cmp *= 2;
		s->data = (int *)realloc(s->data, sizeof(int) * s->cmp); 
		printf("exp!\n");
	}
	
	s->data[s->size] = val;
	s->top = s->data[s->size];
	s->size++;
}

int top(stack *s){
	if(s->size == 0){
		s->top = -1;
		return 0;
	}
	s->size--;
	s->top = s->data[s->size - 1];
	return 1;
}

void showStack(stack *s){
	int a = s->size;
	while(a--){
		printf("%d ",s->data[a]);
	}
	printf("\n");
}

int main(){
	stack *s = initStack(3);
	int a,val;
	while(1){
		scanf("%d", &a);
	if(a == 1){
		scanf("%d",&val);
		pushStack(s ,val );
	}
	else if(a == 2){
		top(s);
	}
	else if(a == 3){
		getTop(s);
		continue;
	}
	else{
		deleteStack(s);
	}
	showStack(s);
	printf("---------------------------------------------\n");
	}
	return 0;
}















