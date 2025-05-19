# Create the full project file tree for ultimate_c_tool with the modules requested by the user.

import os

# Define the base directory for the project
base_dir = os.path.dirname(os.path.abspath(__file__))
base_dir = os.path.join(base_dir, "ultimate_c_tool")
# Create the base directory if it doesn't exist
os.makedirs(base_dir, exist_ok=True)
# Define the structure of the project
# Create the base directory for the project
os.makedirs(base_dir, exist_ok=True)
# Create the subdirectories for the project
os.makedirs(os.path.join(base_dir, "include"), exist_ok=True)
os.makedirs(os.path.join(base_dir, "src"), exist_ok=True)
# Create the main C file
with open(os.path.join(base_dir, "main.c"), 'w') as f:
    f.write("// Main C file\n")
# Create the Makefile
with open(os.path.join(base_dir, "Makefile"), 'w') as f:
    f.write("# Makefile for ultimate_c_tool\n")
    f.write("CC = gcc\n")
    f.write("CFLAGS = -Iinclude\n")
    f.write("SRC = src/main.c src/string_utils.c src/hash_utils.c src/memory_utils.c src/number_utils.c src/debug_utils.c src/file_utils.c src/thread_utils.c src/data_structures.c\n")
    f.write("OBJ = $(SRC:.c=.o)\n")
    f.write("TARGET = ultimate_c_tool\n")
    f.write("\n")
    f.write("all: $(TARGET)\n")
    f.write("\n")
    f.write("$(TARGET): $(OBJ)\n")
    f.write("\t$(CC) -o $@ $^\n")
    f.write("\n")
    f.write("clean:\n")
    f.write("\trm -f $(OBJ) $(TARGET)\n")
# Create the header files
header_files = [
    "string_utils.h",
    "hash_utils.h",
    "memory_utils.h",
    "number_utils.h",
    "debug_utils.h",
    "file_utils.h",
    "thread_utils.h",
    "data_structures.h"
]
for header in header_files:
    with open(os.path.join(base_dir, "include", header), 'w') as f:
        f.write("// Header file for {}\n".format(header))
# Create the source files
source_files = [
    "string_utils.c",
    "hash_utils.c",
    "memory_utils.c",
    "number_utils.c",
    "debug_utils.c",
    "file_utils.c",
    "thread_utils.c",
    "data_structures.c"
]
for source in source_files:
    with open(os.path.join(base_dir, "src", source), 'w') as f:
        f.write("// Source file for {}\n".format(source))
# Create the README file
with open(os.path.join(base_dir, "README.md"), 'w') as f:
    f.write("# Ultimate C Tool\n")
    f.write("This is a C tool that includes various utility functions.\n")
    f.write("\n## Structure\n")
    f.write("- `include/`: Header files\n")
    f.write("- `src/`: Source files\n")
    f.write("- `Makefile`: Build file\n")
    f.write("- `main.c`: Main entry point\n")
# Create the LICENSE file
with open(os.path.join(base_dir, "LICENSE"), 'w') as f:
    f.write("MIT License\n")
    f.write("\n")
    f.write("Copyright (c) 2023 Ultimate C Tool\n")
    f.write("\n")
    f.write("Permission is hereby granted, free of charge, to any person obtaining a copy\n")
    f.write("of this software and associated documentation files (the \"Software\"), to deal\n")
    f.write("in the Software without restriction, including without limitation the rights\n")
    f.write("to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n")
    f.write("copies of the Software, and to permit persons to whom the Software is\n")
    f.write("furnished to do so, subject to the following conditions:\n")
    f.write("\n")
    f.write("The above copyright notice and this permission notice shall be included in\n")
    f.write("all copies or substantial portions of the Software.\n")
    f.write("\n")
    f.write("THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n")
    f.write("IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n")
    f.write("FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n")
    f.write("AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n")
    f.write("LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n")
    f.write("OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN\n")
    f.write("THE SOFTWARE.\n")
# Create the test directory
os.makedirs(os.path.join(base_dir, "test"), exist_ok=True)
# Create the test files
test_files = [
    "test_string_utils.c",
    "test_hash_utils.c",
    "test_memory_utils.c",
    "test_number_utils.c",
    "test_debug_utils.c",
    "test_file_utils.c",
    "test_thread_utils.c",
    "test_data_structures.c"
]
for test in test_files:
    with open(os.path.join(base_dir, "test", test), 'w') as f:
        f.write("// Test file for {}\n".format(test))
# Create the test Makefile
with open(os.path.join(base_dir, "test", "Makefile"), 'w') as f:
    f.write("# Makefile for tests\n")
    f.write("CC = gcc\n")
    f.write("CFLAGS = -I../include\n")
    f.write("SRC = test_string_utils.c test_hash_utils.c test_memory_utils.c test_number_utils.c test_debug_utils.c test_file_utils.c test_thread_utils.c test_data_structures.c\n")
    f.write("OBJ = $(SRC:.c=.o)\n")
    f.write("TARGET = test_ultimate_c_tool\n")
    f.write("\n")
    f.write("all: $(TARGET)\n")
    f.write("\n")
    f.write("$(TARGET): $(OBJ)\n")
    f.write("\t$(CC) -o $@ $^\n")
    f.write("\n")
    f.write("clean:\n")
    f.write("\trm -f $(OBJ) $(TARGET)\n")
# Create the test README file
with open(os.path.join(base_dir, "test", "README.md"), 'w') as f:
    f.write("# Ultimate C Tool Tests\n")
    f.write("This directory contains tests for the Ultimate C Tool.\n")
    f.write("\n## Structure\n")
    f.write("- `Makefile`: Build file for tests\n")
    f.write("- `test_*.c`: Test files\n")
# Create the test LICENSE file
with open(os.path.join(base_dir, "test", "LICENSE"), 'w') as f:
    f.write("MIT License\n")
    f.write("\n")
    f.write("Copyright (c) 2023 Ultimate C Tool\n")
    f.write("\n")
    f.write("Permission is hereby granted, free of charge, to any person obtaining a copy\n")
    f.write("of this software and associated documentation files (the \"Software\"), to deal\n")
    f.write("in the Software without restriction, including without limitation the rights\n")
    f.write("to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n")
    f.write("copies of the Software, and to permit persons to whom the Software is\n")
    f.write("furnished to do so, subject to the following conditions:\n")
    f.write("\n")
    f.write("The above copyright notice and this permission notice shall be included in\n")
    f.write("all copies or substantial portions of the Software.\n")
    f.write("\n")
    f.write("THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n")
    f.write("IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n")
    f.write("FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n")
    f.write("AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n")
    f.write("LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n")
    f.write("OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN\n")
    f.write("THE SOFTWARE.\n")
# Create the test data directory
os.makedirs(os.path.join(base_dir, "test", "data"), exist_ok=True)
# Create the test data files
test_data_files = [
    "test_data1.txt",
    "test_data2.txt",
    "test_data3.txt"
]
for test_data in test_data_files:
    with open(os.path.join(base_dir, "test", "data", test_data), 'w') as f:
        f.write("// Test data file for {}\n".format(test_data))
# Create the test data README file
with open(os.path.join(base_dir, "test", "data", "README.md"), 'w') as f:
    f.write("# Test Data for Ultimate C Tool\n")
    f.write("This directory contains test data files for the Ultimate C Tool.\n")
    f.write("\n## Structure\n")
    f.write("- `test_data1.txt`: Test data file 1\n")
    f.write("- `test_data2.txt`: Test data file 2\n")
    f.write("- `test_data3.txt`: Test data file 3\n")
# Create the test data LICENSE file
with open(os.path.join(base_dir, "test", "data", "LICENSE"), 'w') as f:
    f.write("MIT License\n")
    f.write("\n")
    f.write("Copyright (c) 2023 Ultimate C Tool\n")
    f.write("\n")
    f.write("Permission is hereby granted, free of charge, to any person obtaining a copy\n")
    f.write("of this software and associated documentation files (the \"Software\"), to deal\n")
    f.write("in the Software without restriction, including without limitation the rights\n")
    f.write("to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n")
    f.write("copies of the Software, and to permit persons to whom the Software is\n")
    f.write("furnished to do so, subject to the following conditions:\n")
    f.write("\n")
    f.write("The above copyright notice and this permission notice shall be included in\n")
    f.write("all copies or substantial portions of the Software.\n")
    f.write("\n")
    f.write("THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n")
    f.write("IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n")
    f.write("FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n")
    f.write("AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n")
    f.write("LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n")
    f.write("OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN\n")
    f.write("THE SOFTWARE.\n")
# Create the test data Makefile
with open(os.path.join(base_dir, "test", "data", "Makefile"), 'w') as f:
    f.write("# Makefile for test data\n")
    f.write("CC = gcc\n")
    f.write("CFLAGS = -I../../include\n")
    f.write("SRC = test_data1.txt test_data2.txt test_data3.txt\n")
    f.write("OBJ = $(SRC:.txt=.o)\n")
    f.write("TARGET = test_data_ultimate_c_tool\n")
    f.write("\n")
    f.write("all: $(TARGET)\n")
    f.write("\n")
    f.write("$(TARGET): $(OBJ)\n")
    f.write("\t$(CC) -o $@ $^\n")
    f.write("\n")
    f.write("clean:\n")
    f.write("\trm -f $(OBJ) $(TARGET)\n")
# Create the test data README file
with open(os.path.join(base_dir, "test", "data", "README.md"), 'w') as f:
    f.write("# Test Data for Ultimate C Tool\n")
    f.write("This directory contains test data files for the Ultimate C Tool.\n")
    f.write("\n## Structure\n")
    f.write("- `Makefile`: Build file for test data\n")
    f.write("- `test_data1.txt`: Test data file 1\n")
    f.write("- `test_data2.txt`: Test data file 2\n")
    f.write("- `test_data3.txt`: Test data file 3\n")
# Create the test data LICENSE file
with open(os.path.join(base_dir, "test", "data", "LICENSE"), 'w') as f:
    f.write("MIT License\n")
    f.write("\n")
    f.write("Copyright (c) 2023 Ultimate C Tool\n")
    f.write("\n")
    f.write("Permission is hereby granted, free of charge, to any person obtaining a copy\n")
    f.write("of this software and associated documentation files (the \"Software\"), to deal\n")
    f.write("in the Software without restriction, including without limitation the rights\n")
    f.write("to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n")
    f.write("copies of the Software, and to permit persons to whom the Software is\n")
    f.write("furnished to do so, subject to the following conditions:\n")
    f.write("\n")
    f.write("The above copyright notice and this permission notice shall be included in\n")
    f.write("all copies or substantial portions of the Software.\n")
    f.write("\n")
    f.write("THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n")
    f.write("IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n")
    f.write("FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n")
    f.write("AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n")
    f.write("LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n")
    f.write("OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN\n")
    f.write("THE SOFTWARE.\n")

# Define the full structure of the project
project_structure = {
    "ultimate_c_tool": {
        "Makefile": "",
        "main.c": "",
        "include": {
            "string_utils.h": "",
            "hash_utils.h": "",
            "memory_utils.h": "",
            "number_utils.h": "",
            "debug_utils.h": "",
            "file_utils.h": "",
            "thread_utils.h": "",
            "data_structures.h": "",
        },
        "src": {
            "string_utils.c": "",
            "hash_utils.c": "",
            "memory_utils.c": "",
            "number_utils.c": "",
            "debug_utils.c": "",
            "file_utils.c": "",
            "thread_utils.c": "",
            "data_structures.c": "",
        }
    }
}

# Function to create directories and files
def create_structure(base_path, structure):
    for name, content in structure.items():
        path = os.path.join(base_path, name)
        if isinstance(content, dict):
            os.makedirs(path, exist_ok=True)
            create_structure(path, content)
        else:
            with open(path, 'w') as f:
                f.write(content)

# Create the full structure

create_structure(base_dir, project_structure)

"/mnt/data/ultimate_c_tool"
