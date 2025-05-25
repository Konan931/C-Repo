#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include "../include/string_utils.h"

int main(void) {
    printf("== String Utils Tests ==\n");

    // Test string_length
    printf("Length of 'Hello': %zu\n", string_length("Hello"));

    // Test string_to_int, string_to_float, string_to_double
    printf("String to int: %d\n", string_to_int("123"));
    printf("String to float: %f\n", string_to_float("3.14"));
    printf("String to double: %lf\n", string_to_double("2.71828"));

    // Test int_to_string, float_to_string, double_to_string
    char buf[32];
    int_to_string(456, buf, sizeof(buf));
    printf("Int to string: %s\n", buf);
    float_to_string(1.23f, buf, sizeof(buf));
    printf("Float to string: %s\n", buf);
    double_to_string(4.56, buf, sizeof(buf));
    printf("Double to string: %s\n", buf);

    // Test string manipulation
    char *copy = string_copy("CopyMe");
    printf("Copy: %s\n", copy);
    free(copy);

    char *concat = string_concat("Hello", "World");
    printf("Concat: %s\n", concat);
    free(concat);

    char *substr = string_substring("Substring", 3, 4);
    printf("Substring: %s\n", substr);
    free(substr);

    char *lower = string_to_lower("ABC");
    printf("To lower: %s\n", lower);
    free(lower);

    char *upper = string_to_upper("abc");
    printf("To upper: %s\n", upper);
    free(upper);

    char *trimmed = string_trim("   trim me   ");
    printf("Trimmed: '%s'\n", trimmed);
    free(trimmed);

    char *replaced = string_replace("foo bar foo", "foo", "baz");
    printf("Replaced: %s\n", replaced);
    free(replaced);

    // Test string split
    size_t count = 0;
    char **parts = string_split("a,b,c", ",", &count);
    printf("Split: ");
    for (size_t i = 0; i < count; ++i) {
        printf("'%s' ", parts[i]);
        free(parts[i]);
    }
    printf("\n");
    free(parts);

    // Test search & compare
    printf("Find 'bar' in 'foobar': %s\n", string_find("foobar", "bar"));
    printf("Compare 'abc' and 'abc': %d\n", string_compare("abc", "abc"));
    printf("Compare case-insensitive 'AbC' and 'aBc': %d\n", string_compare_case_insensitive("AbC", "aBc"));
    printf("Starts with 'foo': %d\n", string_starts_with("foobar", "foo"));
    printf("Ends with 'bar': %d\n", string_ends_with("foobar", "bar"));
    printf("Contains 'oo': %d\n", string_contains("foobar", "oo"));

    // Test checks
    printf("Is empty: %d\n", string_is_empty(""));
    printf("Is null: %d\n", string_is_null(NULL));
    printf("Is not null: %d\n", string_is_not_null("x"));
    printf("Is not empty: %d\n", string_is_not_empty("x"));
    printf("Is empty or whitespace: %d\n", string_is_empty_or_whitespace("   "));
    printf("Is numeric: %d\n", string_is_numeric("12345"));
    printf("Is alpha: %d\n", string_is_alpha("abc"));
    printf("Is alphanumeric: %d\n", string_is_alphanumeric("abc123"));
    printf("Is space: %d\n", string_is_space("   "));
    printf("Is digit: %d\n", string_is_digit("123"));
    printf("Is lower: %d\n", string_is_lower("abc"));
    printf("Is upper: %d\n", string_is_upper("ABC"));
    printf("Is printable: %d\n", string_is_printable("abc"));
    printf("Is control: %d\n", string_is_control("\n"));
    printf("Is graph: %d\n", string_is_graph("abc"));
    printf("Is blank: %d\n", string_is_blank(" \t"));
    printf("Is punct: %d\n", string_is_punct("!.,"));
    printf("Is title: %d\n", string_is_title("Hello World"));
    printf("Is title case: %d\n", string_is_title_case("Hello World"));

    printf("All string_utils tests done!\n");
    return 0;
}// Test file for test_string_utils.c
