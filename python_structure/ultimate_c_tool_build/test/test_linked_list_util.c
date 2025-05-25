#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list_util.h"

int main(void) {
    printf("== Linked List Util Tests ==\n");

    LinkedList *list = create_linked_list();
    if (!list) {
        printf("Failed to create linked list!\n");
        return 1;
    }

    // Add elements
    add_to_linked_list(list, 10);
    add_to_linked_list(list, 20);
    insert_at_head(list, 5);
    insert_at_tail(list, 30);
    print_linked_list(list);

    // Find elements
    printf("Find 20: %d\n", find_in_linked_list(list, 20));
    printf("Find 99: %d\n", find_in_linked_list(list, 99));

    // Remove elements
    printf("Remove 10: %d\n", remove_from_linked_list(list, 10));
    printf("Remove 99: %d\n", remove_from_linked_list(list, 99));
    print_linked_list(list);

    // Size
    printf("List size: %zu\n", linked_list_size(list));

    // Clear and free
    clear_linked_list(list);
    print_linked_list(list);
    free_linked_list(list);

    printf("All linked_list_util tests done!\n");
    return 0;
}