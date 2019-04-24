#include <stdio.h>

typedef struct node_tag {
   void* memory;
   int size;
   int free;
   struct node_tag* next;
   struct node_tag* previous;
} Node;


/* 
 * Adds new node to list after the given Node 
 */ 
void add_to_list(Node* node, void* mem, int size, int free);

/*
 * Remove node from the list
 */
void delete_from_list(Node* list, void* node);

/*
 * Merges the given node with its next. Removes the next node and 
 * updates the size and removes the next node form the list.
 */
void merge_next(Node* list, void* node);