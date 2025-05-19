
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

typedef struct {
    int *array;
    size_t size;
    size_t capacity;
} Stack;

Stack* create_stack(size_t capacity);
void push_stack(Stack *stack, int value);
void resize_stack(Stack *stack, size_t new_capacity);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(const Stack *stack);
int is_empty(const Stack *stack);
int is_full(const Stack *stack);
void clear_stack(Stack *stack);
void free_stack(Stack *stack);


// Add your data structure definitions here



// Definition of LinkedList structure

typedef struct LinkedList {

    int value;

    struct LinkedList *next;

} LinkedList;



// Function prototypes for linked list operations

LinkedList *create_linked_list();

void add_to_linked_list(LinkedList *list, int value);

void print_linked_list(LinkedList *list);

void free_linked_list(LinkedList *list);


#endif
