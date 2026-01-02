#include <stdio.h>

#define TOTAL_BLOCKS 20

int diskUsed[TOTAL_BLOCKS] = {0};
int nextBlock[TOTAL_BLOCKS];

// initialize linked list structure
void setupList() {
    for (int i = 0; i < TOTAL_BLOCKS; i++) {
        nextBlock[i] = -1;
    }
}

// allocate blocks without need of consecutive space
int listAllocate(int size) {
    int first = -1;
    int prev = -1;
    int allocated = 0;

    for (int i = 0; i < TOTAL_BLOCKS && allocated < size; i++) {
        if (diskUsed[i] == 0) {
            diskUsed[i] = 1;
            if (first == -1) {
                first = i;
            }
            if (prev != -1) {
                nextBlock[prev] = i;
            }
            prev = i;
            allocated++;
        }
    }

    if (allocated < size) {
        return -1; // not enough blocks
    }

    nextBlock[prev] = -1; // end of file
    return first;
}

// free linked blocks
void listFree(int start) {
    int current = start;
    while (current != -1) {
        int temp = nextBlock[current];
        diskUsed[current] = 0;
        nextBlock[current] = -1;
        current = temp;
    }
}

void printListDisk() {
    printf("Disk state: ");
    for (int i = 0; i < TOTAL_BLOCKS; i++) {
        printf("%d ", diskUsed[i]);
    }
    printf("\n");
}

int main() {
    int startBlock;

    setupList();

    startBlock = listAllocate(5);
    if (startBlock != -1) {
        printf("File starts at block %d\n", startBlock);
    } else {
        printf("Allocation not possible\n");
    }

    printListDisk();

    listFree(startBlock);
    printf("File deleted\n");
    printListDisk();

    return 0;
}
