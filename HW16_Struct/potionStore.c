#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    unsigned char hour;
    unsigned char minute;
} hm_t;

typedef struct {
    const char *item_name;
    unsigned cost;
    unsigned cnt;
} item_t;

typedef struct {
    unsigned order_id;
    hm_t pick_up_time;
    unsigned total_cost;
    unsigned item_cnt;
    item_t *items;
} order_t;

const item_t avaliable_items[] = {
    {"Prod_A",  10},
    {"Prod_B",  20},
    {"Prod_C",  15},
    {"Prod_D",  30},
    {"Prod_E",  50},
    {"Prod_F",  60},
    {"Prod_G",  75},
    {"Prod_H",   5},
    {"Prod_I",  25},
    {"Prod_J",  80},
    {"Prod_K", 100},
    {"Prod_L",  90},
    {"Prod_M",  45},
    {"Prod_N",  40},
    {"Prod_O",  85},
};

const unsigned avaliable_item_cnt = 15;
#define MAX_ORDER_CNT 1024

unsigned fetch_orders(order_t orders[]);
void sum_total_costs(order_t orders[], unsigned order_cnt);
void reorder(order_t orders[], unsigned order_cnt);
void print_result(order_t orders[], unsigned order_cnt);
void clean_up(order_t orders[], unsigned order_cnt);

int main()
{
    order_t orders[MAX_ORDER_CNT];
    unsigned order_cnt = fetch_orders(orders);
    sum_total_costs(orders, order_cnt);
    reorder(orders, order_cnt);
    print_result(orders, order_cnt);
    clean_up(orders, order_cnt);
    return 0;
}

unsigned fetch_orders(order_t orders[])
{
    unsigned order_cnt;
    scanf("%u", &order_cnt);

    // Prepare the orders.
    order_t *curr = orders;
    for (unsigned i = 0; i < order_cnt; i++, curr++) {
        hm_t *curr_pu = &(curr->pick_up_time);
        scanf("%u %hhu:%hhu %u",
                                &(curr->order_id),
                                &(curr_pu->hour),
                                &(curr_pu->minute),
                                &(curr->item_cnt));
        // printf("minutes: |%u|\n",curr_pu->minute);
        // Create a variable length array with malloc.
        item_t *curr_items = curr->items = malloc(sizeof(item_t) * curr->item_cnt);
        for (unsigned j = 0; j < curr->item_cnt; j++) {
            char item_name[32];
            scanf("%s", item_name);
            for (unsigned k = 0; k < avaliable_item_cnt; k++) {
                if (!strcmp(item_name, avaliable_items[k].item_name)) {
                    // Copy the memory content from avaliable_items to curr_items.
                    curr_items[j] = avaliable_items[k];
                    break;
                }
            }
            scanf("%u", &(curr_items[j].cnt));
        }
    }
    return order_cnt;
}

void print_result(order_t orders[], unsigned order_cnt)
{
    for (unsigned i = 0; i < order_cnt; i++) {
        printf("#%u %u\n", orders[i].order_id, orders[i].total_cost);
    }
}

void clean_up(order_t orders[], unsigned order_cnt)
{
    for (unsigned i = 0; i < order_cnt; i++) {
        free(orders[i].items);
    }
}


void sum_total_costs(order_t orders[], unsigned order_cnt)
{
    for(int i=0;i<order_cnt;i++){
        unsigned total=0;
        for(int j=0;j<orders[i].item_cnt;j++){
            total+=(orders[i].items[j].cost)*orders[i].items[j].cnt;
        }
        orders[i].total_cost=total;
    }
}

void reorder(order_t orders[], unsigned order_cnt)
{
    
    for(int i=0;i<order_cnt;i++){
        order_t tmp;
        unsigned hour_i = (unsigned)(orders[i].pick_up_time.hour);
        // printf("test: %u\n",hour_i);
        unsigned min_i = (unsigned)(orders[i].pick_up_time.minute);
        // printf("min: %u\n",min_i);
        unsigned minOrder_Index=i;
        for(int j=i;j<order_cnt;j++){
            unsigned hour_j = (unsigned)(orders[j].pick_up_time.hour);
            unsigned min_j = (unsigned)(orders[j].pick_up_time.minute);
            if(hour_j<(unsigned)orders[minOrder_Index].pick_up_time.hour){
                minOrder_Index=j;
            }else if(hour_j==(unsigned)orders[minOrder_Index].pick_up_time.hour){
                if(min_j<(unsigned)orders[minOrder_Index].pick_up_time.minute) minOrder_Index=j;
            }else{
                continue;
            }
        }
        tmp=orders[i];
        orders[i] = orders[minOrder_Index];
        orders[minOrder_Index] = tmp;

    }
}