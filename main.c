#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <ctype.h>
#include <errno.h>
#include <assert.h>
#include <openssl/sha.h>
#include <openssl/md5.h>
#include <time.h>
#include "memory_utils.h"
#include "string_utils.h"
#include "hash_utils.h"
#include "number_utils.h"
#include "debug_utils.h"
#include "file_utils.h"
#include "thread_utils.h"
#include "data_structures.h"

int main(void) {
    printf("🧪 Welcome to the Ultimate C Toolset!\n");

    // Basic string test
    char source[128] = "Hello";
    safe_concat(source, " World", sizeof(source));
    printf("Concatenated string: %s\n", source);

    // String length test
    const char *test_str = "Ultimate C Tool";
    size_t length = string_length(test_str);
    printf("Length of '%s': %zu\n", test_str, length);
    // String copy test
    char dest[128];
    safe_copy(dest, test_str, sizeof(dest));
    printf("Copied string: %s\n", dest);
    // String compare test
    const char *str1 = "Hello";
    const char *str2 = "Hello";
    int cmp_result = string_compare(str1, str2);
    printf("Comparison of '%s' and '%s': %d\n", str1, str2, cmp_result);
    // String find test
    const char *haystack = "Ultimate C Tool";
    const char *needle = "C";
    const char *found = string_find(haystack, needle);
    if (found) {
        printf("Found '%s' in '%s' at position %ld\n", needle, haystack, found - haystack);
    } else {
        printf("'%s' not found in '%s'\n", needle, haystack);
    }
    // String split test
    const char *str_to_split = "Ultimate,C,Tool";
    char *tokens[10];
    int token_count = string_split(str_to_split, ',', tokens, 10);
    printf("Split '%s' into %d tokens:\n", str_to_split, token_count);
    for (int i = 0; i < token_count; i++) {
        printf("Token %d: %s\n", i, tokens[i]);
    }
    // String reverse test
    char str_to_reverse[128] = "Ultimate C Tool";
    string_reverse(str_to_reverse);
    printf("Reversed string: %s\n", str_to_reverse);
    // String to int test
    const char *int_str = "12345";
    int int_value = string_to_int(int_str);
    printf("String '%s' to int: %d\n", int_str, int_value);
    // Int to string test
    int int_to_str_value = 67890;
    char int_str_buffer[128];
    int_to_string(int_to_str_value, int_str_buffer, sizeof(int_str_buffer));
    printf("Int %d to string: %s\n", int_to_str_value, int_str_buffer);
    // String to float test
    const char *float_str = "123.45";
    float float_value = string_to_float(float_str);
    printf("String '%s' to float: %.2f\n", float_str, float_value);
    // Float to string test
    float float_to_str_value = 678.90;
    char float_str_buffer[128];
    float_to_string(float_to_str_value, float_str_buffer, sizeof(float_str_buffer));
    printf("Float %.2f to string: %s\n", float_to_str_value, float_str_buffer);
    // String to double test
    const char *double_str = "12345.6789";
    double double_value = string_to_double(double_str);
    printf("String '%s' to double: %.4f\n", double_str, double_value);
    // Double to string test
    double double_to_str_value = 67890.1234;
    char double_str_buffer[128];
    double_to_string(double_to_str_value, double_str_buffer, sizeof(double_str_buffer));
    printf("Double %.4f to string: %s\n", double_to_str_value, double_str_buffer);
    // String to boolean test
    const char *bool_str_true = "true";
    const char *bool_str_false = "false";
    int bool_value_true = string_to_bool(bool_str_true);
    int bool_value_false = string_to_bool(bool_str_false);
    printf("String '%s' to boolean: %d\n", bool_str_true, bool_value_true);
    printf("String '%s' to boolean: %d\n", bool_str_false, bool_value_false);
    // Boolean to string test
    int bool_to_str_value = 1;
    char bool_str_buffer[128];
    bool_to_string(bool_to_str_value, bool_str_buffer, sizeof(bool_str_buffer));
    printf("Boolean %d to string: %s\n", bool_to_str_value, bool_str_buffer);
    // String to char test
    const char *char_str = "A";
    char char_value = string_to_char(char_str);
    printf("String '%s' to char: %c\n", char_str, char_value);
    // Char to string test
    char char_to_str_value = 'B';
    char char_str_buffer[128];
    char_to_string(char_to_str_value, char_str_buffer, sizeof(char_str_buffer));
    printf("Char '%c' to string: %s\n", char_to_str_value, char_str_buffer);

    // String to date test
    const char *date_str = "2023-10-01";
    struct tm date_value;
    if (!string_to_date(date_str, &date_value)) {
        fprintf(stderr, "Failed to convert string to date\n");
        return 1;
    }
    printf("String '%s' to date: %04d-%02d-%02d\n", date_str, date_value.tm_year + 1900, date_value.tm_mon + 1, date_value.tm_mday);
    // Date to string test
    struct tm date_to_str_value = {0};
    date_to_str_value.tm_year = 2023 - 1900;
    date_to_str_value.tm_mon = 9; // October
    date_to_str_value.tm_mday = 1;
    char date_str_buffer[128];
    date_to_string(date_to_str_value, date_str_buffer, sizeof(date_str_buffer));
    printf("Date %04d-%02d-%02d to string: %s\n", date_to_str_value.tm_year + 1900, date_to_str_value.tm_mon + 1, date_to_str_value.tm_mday, date_str_buffer);
    // String to time test
    const char *time_str = "12:34:56";
    struct tm time_value;
    if (!string_to_time(time_str, &time_value)) {
        fprintf(stderr, "Failed to convert string to time\n");
        return 1;
    }
    printf("String '%s' to time: %02d:%02d:%02d\n", time_str, time_value.tm_hour, time_value.tm_min, time_value.tm_sec);
    // Time to string test
    struct tm time_to_str_value = {0};
    time_to_str_value.tm_hour = 12;
    time_to_str_value.tm_min = 34;
    time_to_str_value.tm_sec = 56;
    char time_str_buffer[128];
    time_to_string(time_to_str_value, time_str_buffer, sizeof(time_str_buffer));
    printf("Time %02d:%02d:%02d to string: %s\n", time_to_str_value.tm_hour, time_to_str_value.tm_min, time_to_str_value.tm_sec, time_str_buffer);
    // String to hex test
    const char *hex_str = "FF";
    unsigned int hex_value = string_to_hex(hex_str);
    printf("String '%s' to hex: %X\n", hex_str, hex_value);
    // Hex to string test
    unsigned int hex_to_str_value = 0xFF;
    char hex_str_buffer[128];
    hex_to_string(hex_to_str_value, hex_str_buffer, sizeof(hex_str_buffer));
    printf("Hex %X to string: %s\n", hex_to_str_value, hex_str_buffer);
    // String to binary test
    const char *binary_str = "1101";
    unsigned int binary_value = string_to_binary(binary_str);
    printf("String '%s' to binary: %u\n", binary_str, binary_value);
    // Binary to string test
    unsigned int binary_to_str_value = 0b1101;
    char binary_str_buffer[128];
    binary_to_string(binary_to_str_value, binary_str_buffer, sizeof(binary_str_buffer));
    printf("Binary %u to string: %s\n", binary_to_str_value, binary_str_buffer);
    // String to base64 test
    const char *base64_str = "SGVsbG8gV29ybGQ=";
    char *base64_value = string_to_base64(base64_str);
    printf("String '%s' to base64: %s\n", base64_str, base64_value);
    // Base64 to string test
    const char *base64_to_str_value = "Hello World";
    char *base64_str_buffer = base64_to_string(base64_to_str_value);
    printf("Base64 '%s' to string: %s\n", base64_to_str_value, base64_str_buffer);
    // Base64 encode test
    const char *base64_encode_str = "Hello World";
    char *base64_encoded = base64_encode(base64_encode_str);
    printf("Base64 encode '%s': %s\n", base64_encode_str, base64_encoded);
    // Base64 decode test
    const char *base64_decode_str = "SGVsbG8gV29ybGQ=";
    char *base64_decoded = base64_decode(base64_decode_str);
    printf("Base64 decode '%s': %s\n", base64_decode_str, base64_decoded);
    // Base64 URL encode test
    const char *base64_url_encode_str = "Hello World";
    char *base64_url_encoded = base64_url_encode(base64_url_encode_str);
    printf("Base64 URL encode '%s': %s\n", base64_url_encode_str, base64_url_encoded);
    // Base64 URL decode test
    const char *base64_url_decode_str = "SGVsbG8gV29ybGQ=";
    char *base64_url_decoded = base64_url_decode(base64_url_decode_str);
    printf("Base64 URL decode '%s': %s\n", base64_url_decode_str, base64_url_decoded);
    // Base64 URL safe encode test
    const char *base64_url_safe_encode_str = "Hello World";
    char *base64_url_safe_encoded = base64_url_safe_encode(base64_url_safe_encode_str);
    printf("Base64 URL safe encode '%s': %s\n", base64_url_safe_encode_str, base64_url_safe_encoded);
    // Base64 URL safe decode test
    const char *base64_url_safe_decode_str = "SGVsbG8gV29ybGQ=";
    char *base64_url_safe_decoded = base64_url_safe_decode(base64_url_safe_decode_str);
    printf("Base64 URL safe decode '%s': %s\n", base64_url_safe_decode_str, base64_url_safe_decoded);
    
    // Test number utilities
    printf("Hexadecimal of 255: ");
    print_hex(255);
    printf("Octal of 255: ");
    print_octal(255);
    printf("Binary of 255: ");
    print_binary(255);
    printf("Decimal of 255: ");
    print_decimal(255);
    printf("Decimal to binary of 255: ");
    print_decimal_to_binary(255);
    printf("Decimal to hexadecimal of 255: ");
    print_decimal_to_hexadecimal(255);
    printf("Decimal to octal of 255: ");
    print_decimal_to_octal(255);
    printf("Decimal to string of 255: ");
    char decimal_str[128];
    decimal_to_string(255, decimal_str, sizeof(decimal_str));
    printf("%s\n", decimal_str);
    printf("Hexadecimal to decimal of 0xFF: ");
    int hex_to_decimal_result = hex_to_decimal(0xFF);
    printf("%d\n", hex_to_decimal);
    printf("Octal to decimal of 0377: ");
    int octal_to_decimal_result = octal_to_decimal(0377);
    printf("%d\n", octal_to_decimal);
    printf("Binary to decimal of 0b11111111: ");
    int binary_to_decimal_result = binary_to_decimal(0b11111111);
    printf("%d\n", binary_to_decimal);
    printf("Decimal to hexadecimal of 255: ");
    char decimal_to_hex[128];
    decimal_to_hexadecimal(255, decimal_to_hex, sizeof(decimal_to_hex));
    printf("%s\n", decimal_to_hex);
    printf("Decimal to octal of 255: ");
    char decimal_to_oct[128];
    decimal_to_octal(255, decimal_to_oct, sizeof(decimal_to_oct));
    printf("%s\n", decimal_to_oct);
    printf("Decimal to binary of 255: ");
    char decimal_to_bin[128];
    decimal_to_binary(255, decimal_to_bin, sizeof(decimal_to_bin));
    printf("%s\n", decimal_to_bin);
    printf("Decimal to string of 255: ");
    char decimal_to_str[128];
    decimal_to_string(255, decimal_to_str, sizeof(decimal_to_str));
    printf("%s\n", decimal_to_str);
    printf("Decimal to float of 255: ");
    float decimal_to_float_value = decimal_to_float(255);
    printf("%.2f\n", decimal_to_float_value);
    printf("Decimal to double of 255: ");
    double decimal_to_double_value = decimal_to_double(255);
    printf("%.2f\n", decimal_to_double_value);
    printf("Decimal to char of 255: ");
    char decimal_to_char_value = decimal_to_char(255);
    printf("%c\n", decimal_to_char_value);
    printf("Decimal to boolean of 255: ");
    int decimal_to_bool_value = decimal_to_boolean(255);
    printf("%d\n", decimal_to_bool_value);
    printf("Decimal to date of 255: ");
    struct tm decimal_to_date_value;
    if (!decimal_to_date(255, &decimal_to_date_value)) {
        fprintf(stderr, "Failed to convert decimal to date\n");
        return 1;
    }
    printf("%04d-%02d-%02d\n", decimal_to_date_value.tm_year + 1900, decimal_to_date_value.tm_mon + 1, decimal_to_date_value.tm_mday);
    printf("Decimal to time of 255: ");
    struct tm decimal_to_time_value;
    if (!decimal_to_time(255, &decimal_to_time_value)) {
        fprintf(stderr, "Failed to convert decimal to time\n");
        return 1;
    }
    // Convert decimal to time
    decimal_to_time_value.tm_hour = 255 / 3600;
    decimal_to_time_value.tm_min = (255 % 3600) / 60;
    decimal_to_time_value.tm_sec = 255 % 60;
    // Adjust for overflow
    if (decimal_to_time_value.tm_hour >= 24) {
        decimal_to_time_value.tm_hour %= 24;
    }
    if (decimal_to_time_value.tm_min >= 60) {
        decimal_to_time_value.tm_min %= 60;
    }
    if (decimal_to_time_value.tm_sec >= 60) {
        decimal_to_time_value.tm_sec %= 60;
    }
    // Print the time
    // Print time in HH:MM:SS format

    printf("%02d:%02d:%02d\n", decimal_to_time_value.tm_hour, decimal_to_time_value.tm_min, decimal_to_time_value.tm_sec);
    printf("Decimal to base64 of 255: ");
    char decimal_to_base64_value[128];
    decimal_to_base64(255, decimal_to_base64_value, sizeof(decimal_to_base64_value));
    printf("%s\n", decimal_to_base64_value);
    printf("Decimal to base64 URL of 255: ");
    char decimal_to_base64_url_value[128];
    decimal_to_base64_url(255, decimal_to_base64_url_value, sizeof(decimal_to_base64_url_value));
    printf("%s\n", decimal_to_base64_url_value);
    printf("Decimal to base64 URL safe of 255: ");
    char decimal_to_base64_url_safe_value[128];
    decimal_to_base64_url_safe(255, decimal_to_base64_url_safe_value, sizeof(decimal_to_base64_url_safe_value));
    printf("%s\n", decimal_to_base64_url_safe_value);
    printf("Decimal to base64 URL safe decode of 255: ");
    char decimal_to_base64_url_safe_decode_value[128];
    decimal_to_base64_url_safe_decode(255, decimal_to_base64_url_safe_decode_value, sizeof(decimal_to_base64_url_safe_decode_value));
    printf("%s\n", decimal_to_base64_url_safe_decode_value);
    printf("Decimal to base64 URL safe encode of 255: ");
    char decimal_to_base64_url_safe_encode_value[128];
    decimal_to_base64_url_safe_encode(255, decimal_to_base64_url_safe_encode_value, sizeof(decimal_to_base64_url_safe_encode_value));
    printf("%s\n", decimal_to_base64_url_safe_encode_value);
    printf("Decimal to base64 URL safe encode of 255: ");
   
   // Test hash utilities
    const char *data = "Hello, world!";
    unsigned long hash = hash_djb2(data);
    printf("Hash of '%s' (DJB2): %lu\n", data, hash);
    unsigned long hash = hash_sdbm(data);
    printf("Hash of '%s' (SDBM): %lu\n", data, hash);
    unsigned long hash = hash_elf(data);
    printf("Hash of '%s' (ELF): %lu\n", data, hash);
    unsigned long hash = hash_fnv(data);
    printf("Hash of '%s' (FNV): %lu\n", data, hash);
    unsigned long hash = hash_jenkins(data);
    printf("Hash of '%s' (Jenkins): %lu\n", data, hash);
    unsigned long hash = hash_murmur(data);
    printf("Hash of '%s' (Murmur): %lu\n", data, hash);
    unsigned long hash = hash_crc32(data);
    printf("Hash of '%s' (CRC32): %lu\n", data, hash);

    // Hash test
    const char *text = "ultimate_test";
    unsigned long hash = djb2(text);
    printf("Hash of '%s' (djb2): %lu\n", text, hash);

    // Hash test with SHA256
    const char *sha256_text = "ultimate_test_sha256";
    unsigned char sha256_hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)sha256_text, strlen(sha256_text), sha256_hash);
    printf("SHA256 hash of '%s': ", sha256_text);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", sha256_hash[i]);
    }
    printf("\n");
    // Hash test with MD5
    const char *md5_text = "ultimate_test_md5";
    unsigned char md5_hash[MD5_DIGEST_LENGTH];
    MD5((unsigned char *)md5_text, strlen(md5_text), md5_hash);
    printf("MD5 hash of '%s': ", md5_text);
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", md5_hash[i]);
    }
    printf("\n");
    // Hash test with SHA1
    const char *sha1_text = "ultimate_test_sha1";
    unsigned char sha1_hash[SHA_DIGEST_LENGTH];
    SHA1((unsigned char *)sha1_text, strlen(sha1_text), sha1_hash);
    printf("SHA1 hash of '%s': ", sha1_text);
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        printf("%02x", sha1_hash[i]);
    }
    printf("\n");

    // Allocate and free
    char *buffer = malloc_safe(64);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    // Use the buffer
    strcpy(buffer, "Hello, Ultimate C Tool!");
    strcpy(buffer, "Temporary buffer for memory test");
    printf("Buffer: %s\n", buffer);
    hex_dump(buffer, strlen(buffer));
    free_debug(buffer, "test-buffer");

    // Leak demo
    simulate_leak();

    // Memory leak detection
    char *leak = malloc(128);
    if (leak == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Test memory utilities
    char *buffer = malloc_safe(64);
    strcpy(buffer, "Temporary buffer for memory test");
    printf("Buffer: %s\n", buffer);
    hex_dump(buffer, strlen(buffer));
    free_debug(buffer, "test-buffer");

    // Use the leak
    strcpy(leak, "This is a memory leak test");
    printf("Leak test: %s\n", leak);
    // Simulate a memory leak
    // free(leak); // Uncomment to avoid leak
    // Memory leak detection
    if (detect_memory_leak()) {
        printf("Memory leak detected!\n");
    } else {
        printf("No memory leak detected.\n");
    }
    
    // Memory usage
    size_t used_memory = get_used_memory();
    printf("Used memory: %zu bytes\n", used_memory);
    // Memory usage with leak
    size_t used_memory_with_leak = get_used_memory_with_leak();
    printf("Used memory with leak: %zu bytes\n", used_memory_with_leak);
    // Memory usage with leak detection
    size_t used_memory_with_leak_detection = get_used_memory_with_leak_detection();
    printf("Used memory with leak detection: %zu bytes\n", used_memory_with_leak_detection);
    // Memory usage with leak detection and simulation
    size_t used_memory_with_leak_detection_simulation = get_used_memory_with_leak_detection_simulation();
    printf("Used memory with leak detection and simulation: %zu bytes\n", used_memory_with_leak_detection_simulation);

    // Test file utilities
    const char *filename = "testfile.txt";
    const char *content = "This is a test file for file operations!";
    write_file(filename, content);
    char *file_content = read_file(filename);
    if (file_content == NULL) {
        fprintf(stderr, "Failed to read file\n");
        return 1;
    }
    printf("File Content: %s\n", file_content);
    // Append to file
    const char *append_content = " Appending more content.";
    append_to_file(filename, append_content);
    file_content = read_file(filename);
    if (file_content == NULL) {
        fprintf(stderr, "Failed to read file after append\n");
        return 1;
    }
    printf("File Content after append: %s\n", file_content);
    free(file_content);

    // Test data structures
    printf("Creating linked list...\n");
    LinkedList *list = create_linked_list();
    printf("Linked list created.\n");
    // Add elements to linked list
    for (int i = 0; i < 5; i++) {
        add_to_linked_list(list, i);
    }
    printf("Added elements to linked list.\n");
    // Print linked list
        printf("Linked list elements: ");
    print_linked_list(list); // Returns void without printing
    printf("List size: %zu\n", linked_list_size(list)); // Assuming you have a function to get the size
    // Free linked list
    free_linked_list(list);
    printf("Linked list freed.\n");

    // Create stack

    printf("Creating stack...\n");
    Stack *stack = create_stack(10); // Assuming the function requires an initial size of 10
    printf("Stack created.\n");
    // Push elements to stack
    for (int i = 0; i < 5; i++) {
        push_stack(stack, i);
    }
    printf("Pushed elements to stack.\n");
    // Pop elements from stack
    printf("Popped elements from stack: ");
    for (int i = 0; i < 5; i++) {
        int value = pop_stack(stack);
        printf("%d ", value);
    }
    printf("\n");
    // Check if stack is empty
    if (is_stack_empty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
    // Check stack size
    printf("Stack size: %zu\n", stack_size(stack)); // Assuming you have a function to get the size
    // Peek at the top element
    int top_value = peek_stack(stack);
    printf("Top element of stack: %d\n", top_value);
    // Clear stack
    clear_stack(stack);
    printf("Stack cleared.\n");
    // Check if stack is empty after clearing
    if (is_stack_empty(stack)) {
        printf("Stack is empty after clearing.\n");
    } else {
        printf("Stack is not empty after clearing.\n");
    }
    // Resize stack
    resize_stack(stack, 20); // Assuming the function requires a new size of 20
    printf("Stack resized to 20.\n");
    // Check stack size after resizing
        // Check stack size after resizing
    printf("Stack size after resizing: %zu\n", stack_size(stack)); // Assuming you have a function to get the size
    
    // Push more elements to stack
    for (int i = 5; i < 10; i++) {
        push_stack(stack, i);
        printf("Pushed %d to stack. Current stack: ", i);
        print_stack(stack);
    }
    printf("All additional elements pushed.\n");
    
    // Print stack elements
    printf("Final stack elements: ");
    print_stack(stack);
    
    // Check if stack is full
    if (is_stack_full(stack)) {
        printf("Stack is full.\n");
    } else {
        printf("Stack is not full.\n");
    }
    
    // Pop all elements and print after each pop
    printf("Popping all elements:\n");
    while (!is_stack_empty(stack)) {
        int value = pop_stack(stack);
        printf("Popped %d, stack now: ", value);
        print_stack(stack);
    }
    
    // Free stack
    printf("Stack before free (should be empty): ");
    print_stack(stack);
    free_stack(stack);
    printf("Stack freed.\n");
    
    // Test threading utilities
    printf("Creating thread...\n");
    create_thread();

    // Wait for thread to finish
    wait_for_thread();
    printf("Thread finished.\n");
    // Test thread creation
    printf("Creating thread...\n");
    create_thread();
    printf("Thread created.\n");
    
    // Test mutex
    printf("Creating mutex...\n");
    create_mutex();
    printf("Mutex created.\n");
    // Lock mutex
    lock_mutex();
    printf("Mutex locked.\n");
    // Unlock mutex
    unlock_mutex();
    printf("Mutex unlocked.\n");
    // Destroy mutex
    destroy_mutex();
    printf("Mutex destroyed.\n");
    // Test semaphore
    printf("Creating semaphore...\n");
    create_semaphore();
    printf("Semaphore created.\n");
    // Wait on semaphore
    wait_semaphore();
    printf("Semaphore waited.\n");
    // Signal semaphore
    signal_semaphore();
    printf("Semaphore signaled.\n");
    // Destroy semaphore
    destroy_semaphore();
    printf("Semaphore destroyed.\n");
    // Test condition variable
    printf("Creating condition variable...\n");
    create_condition_variable();
    printf("Condition variable created.\n");
    // Wait on condition variable
    wait_condition_variable();
    printf("Condition variable waited.\n");
    // Signal condition variable
    signal_condition_variable();
    printf("Condition variable signaled.\n");
    // Destroy condition variable
    destroy_condition_variable();
    printf("Condition variable destroyed.\n");
    // Test atomic operations
    printf("Performing atomic operations...\n");
    atomic_increment();
    printf("Atomic increment performed.\n");

    return 0;
}
