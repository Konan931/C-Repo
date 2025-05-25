#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <assert.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <stdarg.h>
#include "../include/string_utils.h"
#include "../include/hash_utils.h"
#include "../include/data_structures.h"
#include "../include/number_utils.h"
#include "../include/debug_utils.h"
#include "../include/file_utils.h"
#include "../include/thread_utils.h"
/* #include "../include/crypto_utils.h" */
/* #include "../include/hex_octal_utils.h" */
/* #include "../include/linked_list_util.h" */
#include "../include/memory_utils.h"


// Funktionsprototypen der einzelnen Tests
int test_string_utils(void);
int test_hash_utils(void);
int test_data_structures(void);
// ...weitere...

int main(void) {
    printf("== Gesamttest aller Module ==\n");
    test_string_utils();
    test_hash_utils();
    test_data_structures();
	test_number_utils();
	test_debug_utils();
	test_file_utils();
	test_thread_utils();
	// test_crypto_utils();
	// test_hex_octal_utils();
	// test_linked_list_util();
	test_memory_utils();
	// ...weitere Tests aufrufen...

    // ...weitere...
    printf("== Alle Tests abgeschlossen ==\n");
    return 0;
}