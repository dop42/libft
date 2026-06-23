*This project has been created as partof the 42 curriculum by lmouta-g (dop42).*

## Description

This project is a reusable C utility library based on the 42 library exercise,
with explicit function and file names.

It contains helpers for:

- character checks and conversions;
- memory and string handling;
- linked lists, output helpers, formatted printing, and line reading.
- fixed-size arena allocation.

The goal is to keep the library readable when reused in later projects.

## Moulinette

This refactor is no longer designed to pass the 42 moulinette. As I move
forward in the curriculum, this library changes with my needs: I optimize parts
of it, change internal structures, and add new helpers when they become useful
for later projects.

## Instructions

### Compilation

```bash
make
```

Useful rules:

```bash
make clean
make fclean
make re
```

The build creates:

```text
libft.a
```

### Usage

Include the header:

```c
#include "libft.h"
```

Compile with the static library:

```bash
cc main.c libft.a -I includes
```

## Structure

```text
includes/libft.h
src/ctype
src/stdlib
src/string
src/memory
src/io
src/list
src/printf
src/arena
src/extra
```

## Naming

The public API uses descriptive names.

Examples:

```text
string_length
duplicate_string
string_to_int
print_formatted
create_node
copy_memory
get_next_line
create_arena
arena_alloc
arena_zalloc
destroy_arena
```

## Credits

The arena allocator was inspired by Axel Margo's arena-lib: https://github.com/Axel-Margo/arena-lib.
