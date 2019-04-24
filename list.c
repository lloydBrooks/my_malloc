#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void add_to_list(Node *node, void* mem, int size, int free) {
    Node *new_node;
    new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->memory = mem;
    new_node->size = size;
    new_node->free = free;
    new_node->next = node->next;
    new_node->previous = node;
}

void delete_from_list(Node *list, void* node) {
   Node *curr;
   for (curr = list; curr != NULL; curr = curr->next) {
        if (curr->memory == node) {
            if (curr->previous == NULL)
                list = list->next; /* n is in the first node */
            else {
                curr->previous->next = curr->next; /* n is in some other node */
                curr->next->previous = curr->previous;
            }      
            break;
        }
    }
}

void merge_next(Node* list, void* node) {
    Node* curr;
    for(curr = list; curr != NULL; curr = curr->next) {
        if (curr->memory == node) {
            if (curr->free != 1) {
                printf("Warning: given node is in use!");
            } else if (curr->next == NULL) {
                printf("Error: given node doesn't have a next node to merge with!");
                exit(EXIT_FAILURE);
            } else if (curr->next->free != 1) {
                printf("Error: next node is in use!");
                exit(EXIT_FAILURE);
            } 
            break;
        }
    }
    curr->size = curr->size + curr->next->size;
    delete_from_list(list, curr->next->memory);
}