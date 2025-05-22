#include "../include/linked_list_util.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList *create_linked_list(void) {
    LinkedList *list = malloc(sizeof(LinkedList));
    if (!list) return NULL;
    list->head = NULL;
    list->size = 0;
    return list;
}

void free_linked_list(LinkedList *list) {
    if (!list) return;
    clear_linked_list(list);
    free(list);
}

void add_to_linked_list(LinkedList *list, int value) {
    insert_at_tail(list, value);
}

void insert_at_head(LinkedList *list, int value) {
    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    if (!node) return;
    node->value = value;
    node->next = list->head;
    list->head = node;
    list->size++;
}

void insert_at_tail(LinkedList *list, int value) {
    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    if (!node) return;
    node->value = value;
    node->next = NULL;
    if (!list->head) {
        list->head = node;
    } else {
        LinkedListNode *cur = list->head;
        while (cur->next) cur = cur->next;
        cur->next = node;
    }
    list->size++;
}

int remove_from_linked_list(LinkedList *list, int value) {
    if (!list->head) return 0;
    LinkedListNode *cur = list->head, *prev = NULL;
    while (cur) {
        if (cur->value == value) {
            if (prev) prev->next = cur->next;
            else list->head = cur->next;
            free(cur);
            list->size--;
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}

int find_in_linked_list(LinkedList *list, int value) {
    LinkedListNode *cur = list->head;
    while (cur) {
        if (cur->value == value) return 1;
        cur = cur->next;
    }
    return 0;
}

size_t linked_list_size(const LinkedList *list) {
    return list ? list->size : 0;
}

void clear_linked_list(LinkedList *list) {
    LinkedListNode *cur = list->head;
    while (cur) {
        LinkedListNode *next = cur->next;
        free(cur);
        cur = next;
    }
    list->head = NULL;
    list->size = 0;
}

void print_linked_list(const LinkedList *list) {
    const LinkedListNode *cur = list->head;
    printf("[");
    while (cur) {
        printf("%d", cur->value);
        if (cur->next) printf(" -> ");
        cur = cur->next;
    }
    printf("]\n");
}