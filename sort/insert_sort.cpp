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
        // 判断当前数据是否需要进行插入
        if (num[i - 1] > num[i])
        {
            // 获取需要插入的数据
            key = num[i];
            // 初始查找范围为 [0, i-1]（有序）
            low = 0;
            high = i - 1;
            // 进行折半二分算法查找插入的位置
            while (low <= high)
            {
                // 获取中间下标
                mid = (low + high) / 2;
                if (key <= num[mid])
                {
                    // 如果key小于中间值，则缩小查找范围到左子序列
                    high = mid - 1;
                }
                else
                {
                    // 如果key大于中间值，则缩小查找范围到右子序列
                    low = mid + 1;
                }
            }
            // 整体后移
            for ( j = i - 1; j >= high + 1; j--)
            {
                num[j + 1] = num[j];
            }
            // 插入数据
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
