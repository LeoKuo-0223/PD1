#include <stdio.h>
#include <stdlib.h>

// Enumrations
enum orb_type{
    O_UNSET = -1,
    O_RED = 17, O_BLUE = 1, O_GREEN = 6, O_YELLOW = 24,
    O_FLOAT = 5, O_CLONE = 2, O_EXPAND = 4, O_DYSON = 3
};

// Structure Declairation
struct node_t{
    struct node_t *next;
    enum orb_type orb;
};

struct head_t{
    struct node_t *head;
    int count;
    enum orb_type orb;
};

// Function Prototypes
struct head_t *alloc_list_heads(int size);              // Allocate memory for array of list heads
void init_head_arr(struct head_t *arr, int size);       // Initialize array of linked-lists
void print_magic_circle(struct head_t *arr, int size);  // Print the structure of magic circle
void insert_next(struct head_t *arr, int size, const char c);  // Insert the next orb onto the magic circle

// Main Function
int main(){
    int size;       // Size of center ring
    int count;      // Number of stem orbs will be put;

    // Allocate ring
    scanf("%d%d%*c", &size, &count);
    struct head_t *center_ring = alloc_list_heads(size);

    // Read and set ring
    init_head_arr(center_ring, size);

    // Place the orbs
    for(int i = 0; i < count; ++i){
        insert_next(center_ring, size, getchar());
    }

    // Print magic circle configuration
    print_magic_circle(center_ring, size);
    return 0;
}

// Function Definitions
void print_magic_circle(struct head_t *arr, int size){
    if(!arr){
        return;
    }

    for(int i = 0; i < size; ++i){
        // Print center orb
        printf("CO_%c", arr[i].orb + 'A');

        // Print stem
        struct node_t *cur = arr[i].head;
        while(cur){
            printf(" -> %c", 'A' + cur->orb);
            cur = cur->next;
        }
        if(i + 1 < size) putchar('\n');
    }

    return;
}

// Allocate memory for array of list heads
struct head_t *alloc_list_heads(int size){
    return NULL;
}

// Read input and Initialize array of linked-lists
void init_head_arr(struct head_t *arr, int size){
    return;
}

// Insert the next orb onto the magic circle
void insert_next(struct head_t *arr, int size, const char c){
    return;
}