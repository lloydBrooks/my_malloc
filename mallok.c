#include <stdio.h>
#include <stdlib.h>

#include "mallok.h"
#include "list.h"

#define FREE 1
#define IN_USE 0

static Node* heap;

void create_pool(int size) {
    void* p = malloc(size);
    Node *new_node;
    new_node = malloc(sizeof(Node));
    new_node->memory = p;
    new_node->size = size;
    new_node->free = FREE;
    new_node->next = NULL;
    new_node->previous = NULL;
    
    heap = new_node;
}

void* my_malloc(int size) {
    Node* curr;
    for (curr = heap; curr != NULL; curr = curr->next) {
        if (curr->free = FREE) {
            if (curr->size == size) {
                break;
            } else if (curr->size > size) {
                add_to_list(curr, curr->memory + size, curr->size - size, FREE);
                curr->size = size;
                break;
            }
        }
    }
    if (curr == NULL) {
        return NULL;
    }
    curr->free = IN_USE;
    return curr->memory;
}

void my_free(void* block) {
    Node* curr;
    for(curr = heap; curr != NULL && curr->memory != block; curr = curr->next) {
    }
    if (curr == NULL) {
        return;
    }
    curr->free = FREE;
    if (curr->next != NULL && curr->next->free == FREE) {
        merge_next(heap, curr->memory);
    } 
    if (curr->previous != NULL && curr->previous->free == FREE) {
        merge_next(heap, curr->previous->memory);
    }
}