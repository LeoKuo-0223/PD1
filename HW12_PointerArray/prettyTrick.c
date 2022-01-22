#include <stdio.h>
#include <stdint.h>
#include <assert.h>

// Function Declairation 
void sort_pointers(int **ptr_arr, int *arr, int size);

// Main Function
int main(){
    // Read length of array
    int N;
    scanf("%d", &N);
    
    // Read entries of array, starting from idx = 0, also store a copy
    int arr[N], backup[N];
    for(int i = 0; i < N; ++i){
        scanf("%d", &arr[i]);
        backup[i] = arr[i];
    }

    // Sort the pointers of arr[] into ptr_arr[]
    int *ptr_arr[N];
    sort_pointers(ptr_arr, arr, N);

    // Check if arr[] is unchanged
    for(int i = 0; i < N; ++i){
        assert(arr[i] == backup[i]);
    }

    // Check if all entry of ptr_arr[] are pointers of arr[] entries
    for(int i = 0; i < N; ++i){
        assert((ptr_arr[i] >= arr) && (ptr_arr[i] < &arr[N]));
    } 

    // Check if value pointed by pointers in ptr_arr[] are in descending order
    for(int i = 0; i < N - 1; ++i){
        assert(*ptr_arr[i] >= *ptr_arr[i + 1]);
    }

    // Check if address of every arr[] entries appears in ptr_arr[]
    uintptr_t a = (uintptr_t)arr, b = (uintptr_t)ptr_arr[0];
    for(int i = 1; i < N; ++i){
        a ^= (uintptr_t)&arr[i];
        b ^= (uintptr_t)ptr_arr[i];
    }
    assert(a == b);

    // Success if program runs until here.
    printf("All test passed successfully! :)\n");
    return 0;
}

void sort_pointers(int **ptr_arr, int *arr, int size)
{
    int max=0;
    int *max_address;
    int max_index;
	for(int i=0;i<size;i++){
     ptr_arr[i] = arr;
     arr++;
    }
    for(int i=0;i<size;i++){
        max=*ptr_arr[i];
        max_address = ptr_arr[i];
        max_index=i;
        for(int j=i+1;j<size;j++){
            if(*ptr_arr[j]>max){
                max=*ptr_arr[j];
                max_address = ptr_arr[j];
                max_index=j;
            }
        }
        int *tmp;//記得將兩個值交換位置，避免再次找到重複的值
        tmp = ptr_arr[i];
        ptr_arr[i] = max_address;
        ptr_arr[max_index] = tmp;
    }
    
    
}