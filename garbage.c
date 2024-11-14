#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    int size;
    int is_free;           // 1 if the block is free, 0 if allocated
    struct Block *prev;
    struct Block *next;
} Block;

Block *head = NULL;

// Function to create a new memory block
Block *create_block(int size) {
    Block *block = (Block *)malloc(sizeof(Block));
    block->size = size;
    block->is_free = 1;    // Initially free
    block->prev = block->next = NULL;
    return block;
}

// Initialize memory with given total size
void initialize_memory(int total_size) {
    head = create_block(total_size);
    printf("Initialized memory with %d units.\n", total_size);
}

// Allocate memory of the given size
Block *allocate_memory(int size) {
    Block *current = head;

    // Find a free block with enough size
    while (current != NULL) {
        if (current->is_free && current->size >= size) {
            // If the block is larger, split it
            if (current->size > size) {
                Block *new_block = create_block(current->size - size);
                new_block->next = current->next;
                new_block->prev = current;
                if (current->next) current->next->prev = new_block;
                current->next = new_block;
                current->size = size;
            }
            current->is_free = 0;
            printf("Allocated %d units.\n", size);
            return current;
        }
        current = current->next;
    }

    printf("Not enough memory to allocate %d units.\n", size);
    return NULL;
}

// Free a given block of memory
void free_memory(Block *block) {
    if (block == NULL) return;
    block->is_free = 1;
    printf("Freed %d units.\n", block->size);
}

// Garbage collector to consolidate adjacent free blocks
void garbage_collector() {
    Block *current = head;
    while (current != NULL && current->next != NULL) {
        if (current->is_free && current->next->is_free) {
            // Merge current block with the next block
            current->size += current->next->size;
            Block *to_free = current->next;
            current->next = to_free->next;
            if (to_free->next) to_free->next->prev = current;
            free(to_free);
            printf("Consolidated free blocks.\n");
        } else {
            current = current->next;
        }
    }
}

// Print the current memory layout
void print_memory_layout() {
    Block *current = head;
    printf("Memory Layout:\n");
    while (current != NULL) {
        printf("[%d units, %s] -> ", current->size, current->is_free ? "Free" : "Allocated");
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    initialize_memory(100);

    Block *block1 = allocate_memory(20);
    Block *block2 = allocate_memory(30);
    Block *block3 = allocate_memory(10);

    print_memory_layout();

    free_memory(block1);
    free_memory(block3);

    print_memory_layout();

    garbage_collector();

    print_memory_layout();

    return 0;
}
