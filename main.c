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
#include <limits.h>
#include <float.h>
#include <assert.h>
#include <signal.h>
#include <stdarg.h>
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

    // --- String Manipulation ---
    printf("\n=== String Manipulation ===\n");
    const char *str1 = "Hello";
    const char *str2 = "World";
    char *concat = string_concat(str1, str2);
    printf("Concatenated string: %s\n", concat);
    char *upper = string_to_upper(str1);
    printf("Uppercase string: %s\n", upper);
    char *trimmed = string_trim("   Trim me!   ");
    printf("Trimmed string: '%s'\n", trimmed);
    char *found = string_find("Find me in this string!", "me");
    if (found) {
        printf("Found substring: '%s'\n", found);
    } else {
        printf("Substring not found!\n");
    }

    printf("Is '123' numeric? %s\n", string_is_numeric("123") ? "Yes" : "No");
    printf("Is 'abc' alpha? %s\n", string_is_alpha("abc") ? "Yes" : "No");
    printf("Is '123abc' alphanumeric? %s\n", string_is_alphanumeric("123abc") ? "Yes" : "No");
    printf("Is '   ' empty or whitespace? %s\n", string_is_empty_or_whitespace("   ") ? "Yes" : "No");
    printf("Is 'HELLO' uppercase? %s\n", string_is_upper("HELLO") ? "Yes" : "No");
    printf("Is 'hello' lowercase? %s\n", string_is_lower("hello") ? "Yes" : "No");
    printf("Is '   ' empty? %s\n", string_is_empty("   ") ? "Yes" : "No");
    printf("Is 'H2O' alphanumeric? %s\n", string_is_alphanumeric("H2O") ? "Yes" : "No");
    printf("Is 'H2O' alpha? %s\n", string_is_alpha("H2O") ? "Yes" : "No");
    printf("Is 'H2O' numeric? %s\n", string_is_numeric("H2O") ? "Yes" : "No");
    printf("Is 'H2O' empty? %s\n", string_is_empty("H2O") ? "Yes" : "No");
    printf("Is 'H2O' empty or whitespace? %s\n", string_is_empty_or_whitespace("H2O") ? "Yes" : "No");

    // --- Hex/Octal Utils ---
    printf("\n=== Hex/Octal Utils ===\n");
    char hexbuf[32], octbuf[32];

    // int zu Hex/Octal
    int_to_hex(255, hexbuf, sizeof(hexbuf));
    int_to_octal(255, octbuf, sizeof(octbuf));
    printf("255 in hex: %s, in octal: %s\n", hexbuf, octbuf);

    // Dezimal zu Hex/Octal
    decimal_to_hex(123456, hexbuf, sizeof(hexbuf));
    decimal_to_octal(123456, octbuf, sizeof(octbuf));
    printf("123456 in hex: %s, in octal: %s\n", hexbuf, octbuf);

    // Hex/Octal zu Dezimal
    printf("Hex 'FF' to decimal: %d\n", hex_to_decimal("FF"));
    printf("Octal '377' to decimal: %d\n", octal_to_decimal("377"));
    printf("Binary '11111111' to decimal: %d\n", binary_to_decimal("11111111"));

    // Hex zu ASCII und zurück
    char *ascii = hex_to_ascii("48656c6c6f21");
    printf("Hex to ASCII: %s\n", ascii);
    char *hex = ascii_to_hex("Hello!");
    printf("ASCII to Hex: %s\n", hex);
    free(ascii);
    free(hex);

    // Hex zu Binär-String
    char *bin = hex_to_binary("FF");
    printf("Hex 'FF' to binary: %s\n", bin);
    free(bin);

    // Hex zu verschiedene Typen
    printf("Hex 'FF' to int: %d\n", hex_to_binary_int("FF"));
    printf("Hex 'FF' to unsigned int: %u\n", hex_to_binary_uint("FF"));
    printf("Hex 'FF' to long: %ld\n", hex_to_binary_long("FF"));
    printf("Hex 'FF' to unsigned long: %lu\n", hex_to_binary_ulong("FF"));
    printf("Hex 'FF' to int8_t: %d\n", hex_to_binary_int8("FF"));
    printf("Hex 'FF' to uint8_t: %u\n", hex_to_binary_uint8("FF"));

    char hexbuf2[16], octbuf2[32];

    // int zu Hex/Octal
    int_to_hex(255, hexbuf2, sizeof(hexbuf2));
    int_to_octal(255, octbuf2, sizeof(octbuf2));
    printf("255 in hex: %s, in octal: %s\n", hexbuf2, octbuf2);

    // Dezimal zu Hex/Octal
    decimal_to_hex(123456, hexbuf2, sizeof(hexbuf2));
    decimal_to_octal(123456, octbuf2, sizeof(octbuf2));
    printf("123456 in hex: %s, in octal: %s\n", hexbuf2, octbuf2);

    // Hex/Octal zu Dezimal
    printf("Hex 'FF' to decimal: %d\n", hex_to_decimal("FF"));
    printf("Octal '377' to decimal: %d\n", octal_to_decimal("377"));
    printf("Binary '11111111' to decimal: %d\n", binary_to_decimal("11111111"));

    // Hex zu ASCII und zurück
    char *ascii2 = hex_to_ascii("48656c6c6f21");
    printf("Hex to ASCII: %s\n", ascii2);
    char *hex2 = ascii_to_hex("Hello!");
    printf("ASCII to Hex: %s\n", hex2);
    free(ascii2);
    free(hex2);

    // Hex zu Binär-String
    char *bin2 = hex_to_binary("FF");
    printf("Hex 'FF' to binary: %s\n", bin2);
    free(bin2);

    // --- Linked List Utils ---
    printf("\n=== Linked List Utils ===\n");
    LinkedList *ll = create_linked_list();
    for (int i = 0; i < 5; ++i) {
        add_to_linked_list(ll, i);
    }
    printf("Linked List contents: ");
    print_linked_list(ll);
    printf("List size: %zu\n", linked_list_size(ll));
    printf("Removing 2 from list.\n");
    remove_from_linked_list(ll, 2);
    print_linked_list(ll);
    printf("Inserting 99 at head.\n");
    insert_at_head(ll, 99);
    print_linked_list(ll);
    printf("Inserting 88 at tail.\n");
    insert_at_tail(ll, 88);
    print_linked_list(ll);
    printf("Searching for 3: %s\n", find_in_linked_list(ll, 3) ? "Found" : "Not found");
    printf("Clearing list...\n");
    clear_linked_list(ll);
    free_linked_list(ll);
    printf("Linked List cleared.\n");
    printf("Linked List freed.\n");

    // --- Memory Management ---
    printf("\n=== Memory Management ===\n");
    char *dynamic_str = malloc_safe(50);
    strcpy(dynamic_str, "Dynamic memory management!");
    printf("Dynamic string: %s\n", dynamic_str);
    free_debug(dynamic_str, "dynamic_str");
    char *static_str = "Static memory management!";
    printf("Static string: %s\n", static_str);
    // static_str = realloc(static_str, 100); // Fehler: static_str ist nicht modifizierbar
    // printf("Reallocated static string: %s\n", static_str); // Fehler: static_str ist nicht modifizierbar
    // static_str = "New static string"; // Fehler: static_str ist nicht modifizierbar
    // printf("Reallocated static string: %s\n", static_str); // Fehler: static_str ist nicht modifizierbar
    // static_str = malloc_safe(100); // Fehler: static_str ist nicht modifizierbar


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
    printf("SHA256 of 'test': ");
    for (int i = 0; i < 8; ++i) printf("%02x", sha_out[i]);
    printf("...\n");

	// Decode and encode in Base64
	const char *base64_str = "SGVsbG8gV29ybGQh"; // Base64 encoded "Hello World!"
	char *decoded_str = base64_decode(base64_str);
	printf("Base64 decoded: %s\n", decoded_str);
	char *encoded_str = base64_encode(decoded_str);
	printf("Base64 encoded: %s\n", encoded_str);
	free(decoded_str);
	free(encoded_str);

    // 1. C-Nerd: Pointer-Magie
    const char *ptr_joke = "char **argv = &argc;";
    printf("C Pointer Magic: %s\n", ptr_joke);
    printf("Is it alpha? %s\n", string_is_alpha(ptr_joke) ? "Yes" : "No, but it's a classic segfault!");

    // 2. Zauberkunst: Unsichtbarer String
    const char *cloak = "   \t\n";
    printf("Casting 'Cloak of Invisibility'... Is string empty or whitespace? %s\n",
           string_is_empty_or_whitespace(cloak) ? "Invisible!" : "Still visible!");

    // 3. Astronomie: Sternnamen prüfen
    const char *star = "Betelgeuse";
    printf("Star name: %s, is it uppercase? %s\n", star, string_is_upper(star) ? "YES" : "no, but it's a red supergiant!");

    // 4. Chemie: Summenformel
    const char *water = "H2O";
    printf("Is '%s' alphanumeric? %s\n", water, string_is_alphanumeric(water) ? "Yes, and essential for life!" : "No!");

    // 5. Quantenphysik: Schrödingers String
    const char *schrodinger = NULL;
    printf("Is Schrödinger's string null? %s\n", string_is_null(schrodinger) ? "Dead and alive!" : "Observed!");

    // 6. Philosophie: Cogito ergo sum
    const char *descartes = "Cogito ergo sum";
    printf("Philosophy check: Does the string contain 'sum'? %s\n",
           string_contains(descartes, "sum") ? "I think, therefore I am!" : "I doubt, therefore I am not!");

    // 7. Neurowissenschaften: Synapsen-Trim
    const char *brain = "   Neuron   ";
	char *trimmed_brain = string_trim(brain);

	if (trimmed_brain == NULL) {
		printf("Trimmed neuron is NULL!\n");
	} else {
		printf("Trimmed neuron: '%s'\n", trimmed_brain);
		printf("Is trimmed neuron empty? %s\n", string_is_empty(trimmed_brain) ? "Yes, it's a blank slate!" : "No, it's still there!");
		printf("Is trimmed neuron alphanumeric? %s\n", string_is_alphanumeric(trimmed_brain) ? "Yes, it's a genius!" : "No, it's a blank slate!");
		if (string_is_empty(trimmed_brain)) {
			printf("Trimmed neuron is empty!\n");
		} else {
			printf("Trimmed neuron is not empty!\n");
		}
		free(trimmed_brain);
	}

    free(trimmed_brain);

    // 8. Geisteswissenschaften: Ist "Hermeneutik" alphabetisch?
    const char *hermeneutik = "Hermeneutik";
    printf("Is '%s' alpha? %s\n", hermeneutik, string_is_alpha(hermeneutik) ? "Yes, interpret that!" : "No!");

    // 9. Astrophysik: Schwarzes Loch
    const char *blackhole = "";
    printf("Black hole string is empty? %s\n", string_is_empty(blackhole) ? "Yes, nothing escapes!" : "No, information paradox!");

    // 10. Zauberspruch: String in Großbuchstaben
    const char *spell = "alohomora";
    char *shout = string_to_upper(spell);
    printf("Wizard shouts: %s!\n", shout);
    free(shout);

    // 11. Quantenphysik: Superpositions-Check
    const char *superpos = "0 1";
    printf("Is '%s' numeric? %s\n", superpos, string_is_numeric(superpos) ? "Definite state!" : "Superposition!");

    // 12. Informatik: Ist "Turing" ein Palindrom?
    const char *turing = "Turing";
    printf("Is '%s' a palindrome? %s\n", turing, "Ask Alan in the afterlife!");

    // 13. Philosophie: Leerer String = Tabula Rasa?
    const char *tabula = "";
    printf("Is Tabula Rasa empty? %s\n", string_is_empty(tabula) ? "Yes, ready for knowledge!" : "No, already written!");

    // 14. Biologie: DNA-Check
    const char *dna = "ATCG";
    printf("Is '%s' alpha? %s\n", dna, string_is_alpha(dna) ? "Yes, pure genetic code!" : "No, mutation detected!");

    // 15. Tech-Milliardär: Musk vs. Bezos
    const char *musk = "Musk";
    const char *bezos = "Bezos";
    char *duel = string_concat(musk, bezos);
    printf("If Musk and Bezos merged: %s (the richest string!)\n", duel);
    free(duel);


    // 16. Mathematik: Pi-Check
    const char *pi = "3.14159";
    printf("Is '%s' numeric? %s\n", pi, string_is_numeric(pi) ? "Yes, it's irrational!" : "No, it's a circle!");
    // 17. Informatik: String-Suchalgorithmus
    const char *haystack = "IT is cool!";
    const char *needle = "cool";
    char *found_needle = string_find(haystack, needle);
    if (found_needle) {
        printf("Found '%s' in '%s'\n", needle, haystack);
    } else {
        printf("'%s' not found in '%s'\n", needle, haystack);
    }
    // 18. Philosophie: Ist 'Cogito ergo sum' ein Palindrom?

    // Beispiel 1: Rückgabewert ist int (Check-Funktion)
    const char *s1 = "42";
    int is_num = string_is_numeric(s1); // Rückgabewert: 1 (true) oder 0 (false)
    printf("Is '%s' numeric? %s (Rückgabewert: %d)\n", s1, is_num ? "Yes" : "No", is_num);

    // Beispiel 2: Rückgabewert ist Pointer (neuer String, muss freigegeben werden)
    const char *s2 = "magic";
    char *upper_magic = string_to_upper(s2); // Rückgabewert: Pointer auf neuen String
    printf("Uppercase: %s\n", upper_magic);
    free(upper_magic); // Speicher wieder freigeben!

    // Beispiel 3: SAFE-Variante (Ergebnis per Pointer)
    int result;
    string_is_alpha(s2); // klassische Variante
    string_is_alpha_safe(s2, &result); // SAFE-Variante, schreibt Ergebnis in result
    printf("Is '%s' alpha (SAFE)? %s (Rückgabewert: %d)\n", s2, result ? "Yes" : "No", result);

    // Beispiel 4: String-Manipulation mit Rückgabe
    const char *s3 = "   neuron   ";
    char *trimmed_neuron = string_trim(s3); // Rückgabewert: Pointer auf neuen String
    printf("Trimmed: '%s'\n", trimmed_neuron);
    free(trimmed_neuron);

    // Beispiel 5: String-Konkatenation
    char *combo = string_concat("Elon", "Musk");
    printf("Combo: %s\n", combo);
    free(combo);

    // Beispiel 6: String-Suche
    const char *sentence = "Cogito ergo sum";
    char *found_cog = string_find(sentence, "sum");
    if (found_cog)
        printf("Found 'sum' at position: %ld\n", found_cog - sentence);
    else
        printf("'sum' not found\n");

    printf("\nAll demos finished!\n");
    return 0;
}