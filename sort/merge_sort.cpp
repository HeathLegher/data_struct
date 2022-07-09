#include<stdio.h>

void m_sort(int *num, int l, int r, int *temp){
	if(l >= r){
		return ;
	}
	int mid = (l +r) / 2;
	m_sort(num, l, mid, temp);
	m_sort(num, mid + 1, r, temp);
	int p1 = l, p2 = mid + 1, n = r - l + 1;
	for( int i = 0; i < n; i++){
		if(p2 > r || p1 <= mid && num[p1] <= num[p2]){
			temp[i] = num[p1];
			p1++;
		}else{
			temp[i] = num[p2];
			p2++;
		}
	}
	for( int i = 0, j = l; i < n ;i++, j++){
		num[j] = temp[i];
	}
	
}


int main(){
	int n,num[105],temp[105];
	scanf("%d",&n);
	for( int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}	
	m_sort(num, 0, n-1, temp);
	for(int i = 0; i < n; i++){
		printf("%d ",num[i]);
	}
} 
