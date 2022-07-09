#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	node *next;
}node;

typedef struct stack{
	node *head;
	int size, top;
}stack;

node *newNode(int val){
	node *n = (node *)malloc(sizeof(node));
	n->val = val;
	n->next = NULL;
	return n; 
}

stack *initStack(){
	stack *s = (stack *)malloc(sizeof(stack));
	s->head = (node *)malloc(sizeof(node));
	s->head->val = -1;
	s->head->next = NULL;
	s->size = 0;
	s->top = 0;
	return s;
}

void deleteStack(stack *s){
	node *t1 = s->head;
	while(t1){
		node *t2 = t1->next;
		free(t1);
		t1 = t2;
	}
	free(s);
}

void getTop(stack *s){
	printf("%d\n",s->top);
}

void pushStack(stack *s, int val){
	node *n = newNode(val);
	n->next = s->head->next;
	s->head->next = n;
	s->size++;
	s->top = s->head->next->val;
}

void top(stack *s){
	node *n;
	n = s->head->next;
	s->head->next = s->head->next->next;
	s->top = s->head->next->val;
	free(n);
}


void showStack(stack *s){

	node *n = s->head;
	while(n->next){
		n = n->next;
		printf("%d ", n->val);
	}
	printf("\n");
}

int main(){
	stack *s = initStack();
	int a,val;
	while(1){
		scanf("%d", &a);
	if(a == 1){
		scanf("%d",&val);
		pushStack(s ,val );
		showStack(s);
	}
	else if(a == 2){
		top(s);
		showStack(s);
	}
	else if(a == 3){
		getTop(s);
	}
	
	else{
		deleteStack(s);

	}
	printf("---------------------------------------------\n");
	}
	return 0;
}

