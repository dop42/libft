# libft

<p>
  <img src="https://img.shields.io/badge/language-C-00599C?style=flat-square&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/output-libft.a-4c1?style=flat-square" alt="libft.a">
  <img src="https://img.shields.io/badge/flags--Wall%20--Wextra%20--Werror-4c1?style=flat-square" alt="Flags">
</p>

*This project has been created as part of the 42 curriculum by lmouta-g (dop42).*

---

## Description

This project is a reusable C utility library based on the 42 library exercise,
with explicit function and file names.

It contains helpers for:

- character checks and conversions;
- memory and string handling;
- linked lists, output helpers, formatted printing, and line reading;
- fixed-size arena allocation.

The goal is to keep the library readable when reused in later projects.

## Moulinette

This refactor is no longer designed to pass the 42 moulinette. As I move
forward in the curriculum, this library changes with my needs: I optimize parts
of it, change internal structures, and add new helpers when they become useful
for later projects.

---

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

---

## Structure

```text
includes/libft.h
src/ctype     character checks and conversions
src/stdlib    conversions and general helpers
src/string    string handling
src/memory    memory handling
src/io        output helpers and get_next_line
src/list      linked lists
src/printf    formatted printing
src/arena     fixed-size arena allocation
src/extra     additional helpers
```

---

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

---

## Used by

- [**minishell**](https://github.com/dop42/minishell) — a Unix shell in C.
