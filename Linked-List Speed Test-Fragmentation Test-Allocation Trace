#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DISK_SIZE 32

typedef struct Block {
    int index;
    struct Block* next;
} Block;

int disk[DISK_SIZE];
Block* head = NULL;

void initDisk() {
    for(int i = 0; i < DISK_SIZE; i++)
        disk[i] = 0;
    head = NULL;
}

int listAllocate(int size) {
    int count = 0;
    Block* first = NULL;
    Block* last = NULL;

    for(int i = 0; i < DISK_SIZE; i++) {
        if(disk[i] == 0) {
            if(first == NULL)
                first = (Block*)malloc(sizeof(Block));

            disk[i] = 1;
            Block* node = (Block*)malloc(sizeof(Block));
            node->index = i;
            node->next = NULL;

            if(last != NULL)
                last->next = node;
            else
                head = node;

            last = node;
            count++;

            if(count == size)
                return i;
        }
    }
    return -1;
}

void listFree() {
    Block* temp = head;
    while(temp != NULL) {
        disk[temp->index] = 0;
        Block* del = temp;
        temp = temp->next;
        free(del);
    }
    head = NULL;
}

void printDisk() {
    for(int i = 0; i < DISK_SIZE; i++)
        printf("%d ", disk[i]);
    printf("\n");
}

int main() {
    clock_t start, end;
    initDisk();

    // SPEED TEST
    start = clock();
    for(int i = 0; i < 100; i++) {
        listAllocate(2);
        listFree();
    }
    end = clock();
    printf("Linked List speed time: %lf\n", (double)(end-start));

    // FRAGMENTATION TEST
    for(int i = 0; i < 20; i++)
        listAllocate(rand()%3 + 1);

    listFree();
    int big = listAllocate(12);

    if(big == -1)
        printf("Linked list big allocation failed\n");
    else
        printf("Linked list big allocation success\n");

    // ALLOCATION TRACE
    initDisk();
    int seq[] = {2,3,5,2,4,6,1,3,5,2,4,3,2,1,5};
    for(int i = 0; i < 15; i++) {
        listAllocate(seq[i]);
        printDisk();
    }

    return 0;
}
