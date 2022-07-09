#include<stdio.h>

void q_sort(int *num, int l, int r){
	if( l >= r){
		return ;
	}
	int temp = num[l];
	int ll = l, rr = r;

	while(ll < rr){
		while(ll < rr && num[rr] >= temp){
			rr--;
		}
		if(ll < rr){
			num[ll] = num[rr];
		}
		while(ll < rr && num[ll] <= temp){
			ll++;
		}
		if(ll < rr){
			num[rr] = num[ll];
		}
	}
	num[ll] = temp;
	q_sort(num, l, ll-1);
	q_sort(num, ll + 1, r);	
	 
}

int main(){
	int n = 0;
	int array[25] = {0};
	while(n<10){
		scanf("%d", &array[n]);
		n++;
	}
	q_sort(array,0 , n-1); 


	for(int i = 0; i < n; i++ ){
		printf("%d ",array[i]);
	}
	
	
} 
