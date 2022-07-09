#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
	int *data;
	int front, rear, size, cmp;
}queue;

queue *initQueue(int cmp){
	queue *q = (queue *)malloc(sizeof(queue));
	q->data = (int *)malloc(sizeof(int) * cmp);
	q->cmp = cmp;
	q->size = 0;
	q->front = 0;
	q->rear = 0;
	return q;
} 

void deleteQueue(queue *q){
	free(q->data);
	free(q);
}

int getTop(queue *q){
	if(q->size == 0){
		return 0;	
	}
	printf("the top is:%d\n", q->data[q->front]);
	return q->data[q->front];
}

void push(queue *q, int val){
	if(q->size + 1 == q->cmp){
		
		int *t = (int *)malloc(sizeof(int) * q->cmp * 2) ;
		for(int i = 0;i < q->size; i++){
			*(t+i) = q->data[(q->front + i) % q->cmp];
		}
		free(q->data); 
		q->data = t;
		q->front = 0;
		q->rear = q->front + q->size;
		q->cmp *= 2; 
		printf("exp!\n"); 
	}
	
	
	q->data[q->rear] = val;
	q->rear++;
	if(q->rear == q->cmp){
		q->rear = 0;
	}

	q->size++;
} 

int top(queue *q){
	if(q->size == 0 ){
		return 0;
	}
	q->front++;
	if(q->front == q->cmp){
		q->front = 0;
	}
	q->size--;
	return 1;
}

void show(queue *q){

	for(int t = q->front; t<q->front + q->size; t++){
		printf("%d ",q->data[t % q->cmp]);
	}
	printf("\n");
}

int main(){
	
		queue *q = initQueue(3);
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







