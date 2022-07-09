#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	node *next;
}node;

typedef struct queue{
	node *head;
	int size;
};

queue *initQueue(){
	queue *q = (queue *)malloc(sizeof(queue));
	q->head = (node *)malloc(sizeof(node));
	q->head->next = q->head;
	q->head->data = -1;
	q->size = 0;
	return q;
}

void deleteQueue(queue *q){
	node *n = q->head;
	while(n){
		node *t = n->next;
		free(n);
		n = t;
	}	
	free(q);
}

int getTop(queue *q){
	printf("the top is %d\n",q->head->next->data);
	return q->head->next->data;
}

void push(queue *q, int val){
	node *n = (node *)malloc(sizeof(node));
	n->next = q->head->next;
	n->data = -1;
	q->head->data = val;
	q->head->next = n;
	q->head = n;
	q->size++; 
}

int top(queue *q){
	node *n = q->head->next;
	int res = n->data;
	
	q->head->next = q->head->next->next;
	free(n);
	q->size--;
	return res;
}

void show(queue *q){
	node *n = q->head->next;
	while(n->data != -1){
		printf("%d ",n->data);
		n = n->next;
	}
	printf("\n");
}


int main(){
	
		queue *q = initQueue();
	int a,val;
	while(1){
		scanf("%d", &a);
	if(a == 1){
		scanf("%d",&val);
		push(q ,val );
	}
	else if(a == 2){
		top(q);
	}
	else if(a == 3){
		getTop(q);
	}
	else{
		deleteQueue(q);
	}
	show(q);
	printf("---------------------------------------------\n");
	}
	return 0;
} 




















