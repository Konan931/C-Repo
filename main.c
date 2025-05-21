#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include "string_utils.h"
#include "hash_utils.h"
#include "number_utils.h"
#include "debug_utils.h"
#include "file_utils.h"
#include "thread_utils.h"
#include "data_structures.h"
#include "crypto_utils.h"
#include "hex_octal_utils.h"
#include "linked_list_util.h"
#include "memory_utils.h"
//         cur = cur->next;
void *thread_func(void *arg) {
    (void)arg; // Mark parameter as used
    trace("Thread is running!");
    printf("Thread finished!\n");
    return NULL;
}

int main(void) {
    printf("🧪 Welcome to the Ultimate C Toolset Demo!\n\n");

    // --- Memory Utils ---
    printf("=== Memory Utils ===\n");
    char *mem = malloc_safe(64);
    strcpy(mem, "Memory allocated and copied!");
    printf("Allocated memory: %s\n", mem);
    hex_dump(mem, strlen(mem));
    free_debug(mem, "mem");

    // --- String Utils ---
    printf("\n=== String Utils ===\n");
    const char *num_str = "12345";
    int num = string_to_int(num_str);
    float fnum = string_to_float("3.1415");
    double dnum = string_to_double("2.7182818");
    char buf[32];
    int_to_string(num, buf, sizeof(buf));
    printf("String to int: %d, int to string: %s\n", num, buf);
    float_to_string(fnum, buf, sizeof(buf));
    printf("Float to string: %s\n", buf);
    double_to_string(dnum, buf, sizeof(buf));
    printf("Double to string: %s\n", buf);
    printf("Length of 'Hello World': %zu\n", string_length("Hello World"));

    // --- Hash Utils ---
    printf("\n=== Hash Utils ===\n");
    char simple[16];
    simple_hash("abc", simple, sizeof(simple));
    printf("Simple hash of 'abc': ");
    hex_dump(simple, sizeof(simple));

    // --- Number Utils ---
    printf("\n=== Number Utils ===\n");
    int a = 42, b = 56;
    printf("%d is %sprime\n", a, is_prime(a) ? "" : "not ");
    printf("GCD of %d and %d: %d\n", a, b, gcd(a, b));

    // --- Debug Utils ---
    printf("\n=== Debug Utils ===\n");
    trace("This is a trace message!");

    // --- File Utils ---
    printf("\n=== File Utils ===\n");
    const char *filename = "main.c";
    printf("Does '%s' exist? %s\n", filename, file_exists(filename) ? "Yes" : "No");
    printf("Size of '%s': %zu bytes\n", filename, file_size(filename));

    // --- Thread Utils ---
    printf("\n=== Thread Utils ===\n");
    printf("Starting a thread...\n");
    start_thread(thread_func, NULL);

    // --- Data Structures (IntArray) ---
    printf("\n=== Data Structures: IntArray ===\n");
    IntArray arr;
    int_array_init(&arr, 5);
    for (int i = 0; i < arr.size; ++i) arr.data[i] = i * 10;
    printf("IntArray contents: ");
    for (int i = 0; i < arr.size; ++i) printf("%d ", arr.data[i]);
    printf("\n");
    int_array_free(&arr);

    // --- Data Structures (LinkedList) ---
    printf("\n=== Data Structures: LinkedList ===\n");
    LinkedList *list = create_linked_list();
    printf("Adding elements to linked list: ");
    for (int i = 1; i <= 5; ++i) {
        add_to_linked_list(list, i * 100);
        printf("%d ", i * 100);
    }
    printf("\nCurrent list: ");
    print_linked_list(list);
    printf("List size: %zu\n", linked_list_size(list));
    printf("Inserting 999 at head.\n");
    insert_at_head(list, 999);
    print_linked_list(list);
    printf("Inserting 888 at tail.\n");
    insert_at_tail(list, 888);
    print_linked_list(list);
    printf("Removing 300 from list.\n");
    remove_from_linked_list(list, 300);
    print_linked_list(list);
    printf("Searching for 400: %s\n", find_in_linked_list(list, 400) ? "Found" : "Not found");
    printf("Clearing list...\n");
    clear_linked_list(list);
    print_linked_list(list);
    free_linked_list(list);

    // --- Crypto Utils ---
    printf("\n=== Crypto Utils ===\n");
    unsigned char sha_out[32];
    if (sha256_hash("test", sha_out, sizeof(sha_out))) {
        printf("SHA256 of 'test': ");
        for (int i = 0; i < 8; ++i) printf("%02x", sha_out[i]);
        printf("...\n");
    } else {
        printf("SHA256 failed!\n");
    }

    // --- Hex/Octal Utils ---
    printf("\n=== Hex/Octal Utils ===\n");
    char hexbuf[16], octbuf[16];
    int_to_hex(255, hexbuf, sizeof(hexbuf));
    int_to_octal(255, octbuf, sizeof(octbuf));
    printf("255 in hex: %s, in octal: %s\n", hexbuf, octbuf);

    printf("\nAll demos finished!\n");
    return 0;
}