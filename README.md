# C Utility Experiments

A personal C programming repository for exploring language fundamentals, utility functions, memory management, data structures, and lower-level programming.

It started as a collection of exercises and gradually grew into a larger experimental toolset. **This is primarily a learning repository, not a production-ready library.**

## What's inside

The `include/` and `src/` directories contain examples and utilities in several areas:

| Module | Topics |
| --- | --- |
| `string_utils` | String manipulation, conversion, and validation |
| `number_utils`, `math_utils` | Number properties and mathematical operations |
| `hash_utils` | Hashing experiments |
| `hex_octal_utils` | Numeral systems and binary/hexadecimal conversions |
| `file_utils` | Basic file operations |
| `memory_utils` | Memory allocation and ownership exercises |
| `linked_list_util`, `data_structures` | Linked lists and basic data structures |
| `thread_utils` | POSIX thread experiments |
| `debug_utils` | Diagnostics and debugging helpers |
| `crypto_utils` | Experiments with cryptographic APIs and OpenSSL |

`main.c` contains the combined demonstrations. Additional historical experiments and generated scaffolds are stored under `python_structure/`.

## Building

The existing Makefile uses GCC, POSIX threads, and OpenSSL development libraries.

```bash
make
# Run the resulting demo only in a disposable/test environment.
make clean
```

**Known limitations:** Some demonstrations still need memory-safety review, including a potential double-free in `main.c`. A successful build does not mean that all examples are safe to execute or correct on every platform. Compilation and runtime behavior have not been freshly verified as part of this README update.

## Learning and contributions

The code is intentionally exploratory. Some modules are further along than others, and their interfaces, error handling, and ownership rules are not yet consistent.

Areas to work on include:

- Fixing memory-management issues and clarifying ownership.
- Adding focused unit tests and edge-case coverage.
- Strengthening input validation and error handling.
- Separating reusable utilities from one-off demonstrations.
- Documenting function contracts and improving portability.
- Removing generated object files and binaries from version control.

Suggestions, bug reports, test cases, and small, reviewable contributions are welcome. The goal is to learn how things work — including why they sometimes don't.
