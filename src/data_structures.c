#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "data_structures.h"

// Create a stack with a given capacity
Stack* create_stack(size_t capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->size = 0;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

void print_stack(const Stack *stack) {
    for (size_t i = 0; i < stack->size; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Push an element onto the stack
void push(Stack *stack, int value) {
    if (stack->size < stack->capacity) {
        stack->array[stack->size++] = value;
    } else {
        printf("Stack overflow\n");
    }
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (stack->size > 0) {
        return stack->array[--stack->size];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

// Peek the top element of the stack
int peek(const Stack *stack) {
    if (stack->size > 0) {
        return stack->array[stack->size - 1];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

void print_stack(const Stack *stack) {
    for (size_t i = 0; i < stack->size; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Free the stack
void free_stack(Stack *stack) {
    free(stack->array);
    free(stack);
}

// Create a new linked list

LinkedList *create_linked_list() {

    return NULL; // Start with an empty list

}



// Add a value to the linked list

void add_to_linked_list(LinkedList *list, int value) {

    LinkedList *new_node = malloc(sizeof(LinkedList));

    if (!new_node) {

        fprintf(stderr, "Memory allocation failed\n");

        exit(1);

    }

    new_node->value = value;

    new_node->next = NULL;



    if (!list) {

        list = new_node;

    } else {

        LinkedList *current = list;

        while (current->next) {

            current = current->next;

        }

        current->next = new_node;

    }

}



// Print the linked list

void print_linked_list(LinkedList *list) {

    LinkedList *current = list;

    while (current) {

        printf("%d ", current->value);

        current = current->next;

    }

    printf("\n");

}



// Free the linked list

void free_linked_list(LinkedList *list) {

    LinkedList *current = list;

    while (current) {

        LinkedList *next = current->next;

        free(current);

        current = next;

    }

}

