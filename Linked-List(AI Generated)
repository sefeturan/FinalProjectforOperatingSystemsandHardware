#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    int id;
    struct Block* next;
} Block;

Block* free_list = NULL;

/* Initialize free blocks */
void init_free_list(int n) {
    for (int i = 0; i < n; i++) {
        Block* new_block = (Block*)malloc(sizeof(Block));
        new_block->id = i;
        new_block->next = free_list;
        free_list = new_block;
    }
}

/* Allocate one block */
Block* allocate_block() {
    if (free_list == NULL) return NULL;

    Block* block = free_list;
    free_list = free_list->next;
    block->next = NULL;

    return block;
}

/* Free block */
void free_block(Block* block) {
    block->next = free_list;
    free_list = block;
}

int main() {
    init_free_list(5);

    Block* b1 = allocate_block();
    printf("Allocated block: %d\n", b1->id);

    free_block(b1);
    printf("Block freed\n");

    return 0;
}
