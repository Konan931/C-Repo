#ifndef LINKED_LIST_UTIL_H
#define LINKED_LIST_UTIL_H

#include <stddef.h>

typedef struct LinkedListNode {
    int value;
    struct LinkedListNode *next;
} LinkedListNode;

typedef struct LinkedList {
    LinkedListNode *head;
    size_t size;
} LinkedList;

LinkedList *create_linked_list(void);
void free_linked_list(LinkedList *list);
void add_to_linked_list(LinkedList *list, int value);
void insert_at_head(LinkedList *list, int value);
void insert_at_tail(LinkedList *list, int value);
int remove_from_linked_list(LinkedList *list, int value);
int find_in_linked_list(LinkedList *list, int value);
size_t linked_list_size(const LinkedList *list);
void clear_linked_list(LinkedList *list);
void print_linked_list(const LinkedList *list);

#endif