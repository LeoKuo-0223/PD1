#include <stdio.h>
#define N 500
#define swap(x, y) {int tmp = x; x = y; y = tmp;}

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int size;

int main(void)
{
    int array[N];
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    quicksort(array, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
void quicksort(int a[], int low, int high) {
    int middle;
    if(low>=high) return;
    middle = partition(a,low,high);
    quicksort(a,low,middle-1);
    quicksort(a,middle+1,high);
}

int partition(int a[], int low, int high) {
    int privot = a[high];
    int index=low;
    int start = low;
    
    while(low<high){
        
        if(a[low]<=privot){
            int tmp = a[index];
            a[index]=a[low];
            a[low]=tmp;
            index++;
        }
        low++;
    }
    int tmp = a[index];  
    a[index]=privot;
    a[high]=tmp;
    if(start!=0){
        for(int j=0;j<start;j++){
                printf("%d ",a[j]);
        }
    }
    printf("[");
    for(int k=start;k<=high;k++){
        if(k==index){
            printf(" *%d",a[k]);
        }else printf(" %d",a[k]);
    }
    printf(" ]");
    if(high<size-1){
        for(int j=high+1;j<size;j++){
            printf(" %d",a[j]);
        }
    }
    printf("\n");
    return index;
}