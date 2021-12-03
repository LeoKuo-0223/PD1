#include<stdio.h>
// #define N 5000
void preorder(int a[],int index);
void inorder(int a[],int index);
void postorder(int a[],int index);
void visit();
int n;

int main () {
    int traversalmode;
    // int array[N];
    scanf("%d",&traversalmode);
    scanf("%d",&n);
    int array[n+1];
    for(int i=1;i<n+1;i++){
        scanf("%d",&array[i]);
    }
    if(traversalmode==0) preorder(array,1);
    else if(traversalmode==1) inorder(array,1);
    else postorder(array,1);
    return 0;
}
void visit(int a[],int currentIndex){
    printf("%d ",a[currentIndex]);
}
void preorder(int a[],int index){
    if(index<=n){
        visit(a,index);
        preorder(a,index*2);
        preorder(a,index*2+1);
    }
}
void inorder(int a[],int index){
    if(index<=n){
        inorder(a,index*2);
        visit(a,index);
        inorder(a,index*2+1);
    }
}
void postorder(int a[],int index){
    if(index<=n){
        postorder(a,index*2);
        postorder(a,index*2+1);
        visit(a,index);
        
    }
}
