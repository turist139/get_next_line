*This project has been created as part of the 42 curriculum by gganzha*

# get_next_line

## Description
`get_next_line` is a core project in the 42 curriculum. The goal is to write a function that reads from a file descriptor and returns one line at a time, complete with its terminating newline.  
This project introduces the vital concept of **static variables** in C, teaching how to maintain state and preserve data between consecutive function calls. It also heavily reinforces dynamic memory allocation, buffer management, and the rigorous prevention of memory leaks.

## Key Concepts
The function successfully handles reading text by mastering the following areas:

- **Static Variables:** Using a persistent variable to "stash" data read from the buffer that belongs to the *next* line, keeping it safe until the function is called again.
- **Buffer Management:** Reading data in chunks based on an arbitrary `BUFFER_SIZE` defined at compile time, which could be as small as 1 or as large as 10,000.
- **Memory Management:** Carefully allocating (`malloc`) memory for the line and stash, and ensuring older states are properly destroyed (`free`) to guarantee absolutely zero memory leaks.
- **File Descriptors (fd):** Handling input seamlessly, whether it comes from a standard text file or standard input (stdin).

## Architecture
To comply with the strict Norminette rules, the project is divided into specific files without the use of a Makefile (as per standard `get_next_line` requirements):
- `get_next_line.c`: Contains the main loop, the reading logic, the line extraction, and the stash cleanup.
- `get_next_line_utils.c`: Contains the necessary custom string manipulation functions (e.g., `ft_strlen`, `ft_strchr`, and a customized, leak-free `ft_strjoin`).
- `get_next_line.h`: The header file containing all function prototypes and the fallback `BUFFER_SIZE` macro.

## Instructions

To compile the function for testing, you must compile the source files alongside your own `main.c` file. Use the `-D` flag to define the `BUFFER_SIZE` during compilation.

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_test

This will generate the `gnl_test` executable.

**Running and Testing:**
- Execute the program: `./gnl_test`
- Test for memory leaks using Valgrind: `valgrind --leak-check=full ./gnl_test`

*(Note: It is the responsibility of the calling function (your main) to `free()` the string returned by `get_next_line`.)*

## Resources

**References**
- Linux Man Pages: The primary reference for the allowed standard functions (`man 2 read`, `man 3 malloc`, `man 3 free`).

**AI Usage**
AI tools (specifically Gemini) were utilized during the development of this project for:
- Researching the mechanics of static variables, buffer manipulation, and the nuances of the `read()` system call.
- Generating edge-case tests (like empty files, files without newlines, and massive buffer sizes) to ensure complete memory safety.
- Drafting this README file.