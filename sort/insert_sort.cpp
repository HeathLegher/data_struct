#include<stdio.h>


int swap(int *a, int *b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
void sort(int *num, int n){
 int i, j, low, high, mid, key;
    for (i = 1; i < n; i++)
    {
        // �жϵ�ǰ�����Ƿ���Ҫ���в���
        if (num[i - 1] > num[i])
        {
            // ��ȡ��Ҫ���������
            key = num[i];
            // ��ʼ���ҷ�ΧΪ [0, i-1]������
            low = 0;
            high = i - 1;
            // �����۰�����㷨���Ҳ����λ��
            while (low <= high)
            {
                // ��ȡ�м��±�
                mid = (low + high) / 2;
                if (key <= num[mid])
                {
                    // ���keyС���м�ֵ������С���ҷ�Χ����������
                    high = mid - 1;
                }
                else
                {
                    // ���key�����м�ֵ������С���ҷ�Χ����������
                    low = mid + 1;
                }
            }
            // �������
            for ( j = i - 1; j >= high + 1; j--)
            {
                num[j + 1] = num[j];
            }
            // ��������
            num[high + 1] = key;
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
	sort(array, n); 




	for(int i = 0; i < n; i++ ){
		printf("%d ",array[i]);
	}
	
	
} 
