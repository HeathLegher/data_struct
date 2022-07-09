#include<stdio.h>


int swap(int *a, int *b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
int bubble_sort(int *a, int n){
	for(int i = 0 ; i < n - 1; i++){
		bool flag = 0;
		for(int j = n - 1 ; j >= i; j-- ){
			if(a[j - 1] > a[j]){
				swap(&a[j - 1], &a[j]); 
				flag = 1;
			}
			
		}
		if(flag == 0){
			break;
		}
	}
}

int main(){
	int n = 0;
	int array[25] = {0};
	while(n<10){
		scanf("%d", &array[n]);
		n++;
	}
	bubble_sort(array, n); 

	for(int i = 0; i < n; i++ ){
		printf("%d ",array[i]);
	}
	
	
} 
