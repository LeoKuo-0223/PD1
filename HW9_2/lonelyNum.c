#include <stdio.h>
#include<stdbool.h>

int n;

bool finish=false;
void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);
void lonely(int array[],int remain);
bool check(int array[], int i,int j,int a);
int main(){
    int lonelyNumIndex;
    scanf("%d",&n);
    int lonelyarray[n];
    for(int i=0;i<n;i++){
        scanf("%d",&lonelyarray[i]);
    }
    quicksort(lonelyarray,0,n-1);
    for(int i=0;i<n;i++){
        if(finish==false){
            lonelyNumIndex=i;
            int temparray[n-1];
            int count=0;
            for(int j=0;j<n;j++){
                if(j!=lonelyNumIndex){
                    temparray[count]=lonelyarray[j];
                    count++;
                }
            }
            lonely(temparray,n-1);
        }else break;
    }
    printf("%d",lonelyarray[lonelyNumIndex]);

}

void lonely(int array[],int remain){
    if(remain==0){
        finish=true;
        return;
    }else{
        int a=remain-1;
        int previousI=0;
        int previousJ=0;
        for(int i=0;i<remain-1;i++){
            if(array[i]!=previousI){
                previousI=array[i];
                previousJ=0;
                for(int j=i+1;j<remain-1;j++){
                    if(array[j]!=previousJ){
                        previousJ=array[j];
                        bool answer = check(array,i,j,a);
                        if(answer == true){
                            int temparray[remain-3];
                            int count=0;
                            for(int k=0;k<remain;k++){
                                if(k!=i && k!=j){
                                    temparray[count]=array[k];
                                    count++;
                                }
                            }
                            lonely(temparray,remain-3);
                        }
                    }

                }
            }

        }
    }
}

bool check(int array[], int i,int j,int a){
    int sum=(array[i]+array[j]);
    if(sum==array[a]) {
        return true;
    }else return false;
}

void quicksort(int a[], int low,int high){
int middle;
if (low >= high) return;
middle = split(a, low, high);
quicksort(a, low, middle - 1);
quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high)
{
int part_element = a[low];
for (;;) {
while (low < high && part_element <= a[high])
high--;
if (low >= high) break;
a[low++] = a[high];
while (low < high && a[low] <= part_element)
low++;
if (low >= high) break;
a[high--] = a[low];
}
a[high] = part_element;
return high;
}