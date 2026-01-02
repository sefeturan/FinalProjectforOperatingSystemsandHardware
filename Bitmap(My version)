#include <stdio.h>

#define DISK_SIZE 20

// bitmap array: 0 means free block, 1 means used block
int diskMap[DISK_SIZE] = {0};

// function to print current disk state
void showDisk() {
    int i;
    printf("Disk status: ");
    for (i = 0; i < DISK_SIZE; i++) {
        printf("%d ", diskMap[i]);
    }
    printf("\n");
}

// allocate consecutive blocks using bitmap logic
int bitmapAllocate(int neededSize) {
    int count = 0;
    int startIndex = -1;

    for (int i = 0; i < DISK_SIZE; i++) {
        if (diskMap[i] == 0) {
            if (count == 0) {
                startIndex = i;
            }
            count++;
            if (count == neededSize) {
                // mark blocks as used
                for (int j = startIndex; j < startIndex + neededSize; j++) {
                    diskMap[j] = 1;
                }
                return startIndex;
            }
        } else {
            count = 0; // reset counter if used block found
        }
    }
    return -1; // not enough space
}

// free blocks in bitmap
void bitmapFree(int start, int size) {
    for (int i = start; i < start + size; i++) {
        diskMap[i] = 0;
    }
}

int main() {
    int pos;

    pos = bitmapAllocate(4);
    if (pos != -1) {
        printf("Allocated at block %d\n", pos);
    } else {
        printf("Allocation failed\n");
    }

    showDisk();

    bitmapFree(pos, 4);
    printf("Blocks freed\n");
    showDisk();

    return 0;
}
