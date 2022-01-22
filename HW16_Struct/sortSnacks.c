#include<stdio.h>
#include<stdlib.h>

struct snack
{
    int id;
    int price;
    int weight;
    double value;
};

int cmp(const void *a, const void *b);
void sort_snacks(struct snack snacks[], int n);

int main() {
    int n;
    struct snack snacks[100];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        snacks[i].id = i+1;
        scanf("%d %d", &snacks[i].price, &snacks[i].weight);
    }
    sort_snacks(snacks, n);
    for(int i=0; i<n; i++) {
        printf("%d %.2f\n", snacks[i].id, snacks[i].value);
    }
    return 0;
}

void sort_snacks(struct snack snacks[], int n) {
    for(int i=0;i<n;i++){
        double value=(double)snacks[i].weight/(double)snacks[i].price;
        snacks[i].value=value;
    }
    qsort (snacks, n, sizeof(struct snack), cmp);
}

int cmp(const void *a, const void *b) {
    struct snack *a_tmp = (struct snack*)a;
    struct snack *b_tmp = (struct snack*)b;
    double compare=b_tmp->value-a_tmp->value;
    if(compare==0){
        int cmp_price=a_tmp->price-b_tmp->price;
        if(cmp_price==0){
            return a_tmp->id-b_tmp->id;
        }
        return cmp_price;
    }else if(compare<0){
        return -1;
    }else if(compare>0){
        return 1;
    }
}