/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_library.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouta-g <lmouta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:48:18 by lm0uta            #+#    #+#             */
/*   Updated: 2026/02/19 12:08:25 by lmouta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_LIBRARY_H
# define UTILITY_LIBRARY_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define CONSOLE_COLOR_RESET "\033[0m"
# define CONSOLE_COLOR_DEBUG "\033[0;36m"
# define CONSOLE_COLOR_INFO "\033[0;34m"
# define CONSOLE_COLOR_WARN "\033[0;33m"
# define CONSOLE_COLOR_ERROR "\033[0;31m"
# define CONSOLE_COLOR_SUCCESS "\033[0;32m"

typedef enum e_console_type
{
	CONSOLE_DEBUG,
	CONSOLE_INFO,
	CONSOLE_WARN,
	CONSOLE_ERROR,
	CONSOLE_SUCCESS
}	t_console_type;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_arena
{
	unsigned char	*buffer;
	size_t			capacity;
	size_t			offset;
}	t_arena;

/**
 * is_alpha - checks if c is a letter
 * @c: character to check
 * Return: 1 if letter, 0 otherwise
 */
int				is_alpha(int c);
/**
 * is_digit - checks if c is a digit
 * @c: character to check
 * Return: 1 if digit, 0 otherwise
 */
int				is_digit(int c);
/**
 * is_alnum - checks if c is alphanumeric
 * @c: character to check
 * Return: 1 if alphanumeric, 0 otherwise
 */
int				is_alnum(int c);
/**
 * is_ascii - checks if c is ASCII
 * @c: character to check
 * Return: 1 if ASCII (0-127), 0 otherwise
 */
int				is_ascii(int c);
/**
 * is_printable - checks if c is printable
 * @c: character to check
 * Return: 1 if printable (32-126), 0 otherwise
 */
int				is_printable(int c);
/**
 * is_space - checks if c is whitespace
 * @c: character to check
 * Return: 1 if whitespace, 0 otherwise
 */
int				is_space(int c);
/**
 * to_lower - converts uppercase to lowercase
 * @c: character to convert
 * Return: lowercase char or c unchanged
 */
int				to_lower(int c);
/**
 * to_upper - converts lowercase to uppercase
 * @c: character to convert
 * Return: uppercase char or c unchanged
 */
int				to_upper(int c);
/**
 * string_to_int - converts string to int
 * @str: string to convert
 * Return: integer value
 */
int				string_to_int(const char *str);
/**
 * int_to_string - converts int to string
 * @n: integer to convert
 * Return: new allocated string or NULL
 */
char			*int_to_string(int n);

/**
 * string_length - calculates string length
 * @s: pointer to string
 * Return: number of chars before '\0', or 0 if s is NULL
 */
size_t			string_length(const char *s);
/**
 * duplicate_string - duplicates string
 * @s: string to duplicate
 * Return: new allocated string or NULL
 */
char			*duplicate_string(const char *s);
/**
 * substring - extracts substring from s
 * @s: source string
 * @start: start index
 * @len: max length
 * Return: new allocated substring or NULL
 */
char			*substring(char const *s, unsigned int start, size_t len);
/**
 * join_strings - joins two strings
 * @s1: first string
 * @s2: second string
 * Return: new allocated string or NULL
 */
char			*join_strings(char const *s1, char const *s2);
/**
 * trim_string - trims chars from set at start/end
 * @s1: string to trim
 * @set: chars to remove
 * Return: new trimmed string or NULL
 */
char			*trim_string(char const *s1, char const *set);
/**
 * find_char - finds first occurrence of c in s
 * @s: string to search
 * @c: character to find
 * Return: pointer to char or NULL
 */
char			*find_char(const char *s, int c);
/**
 * find_last_char - finds last occurrence of c in str
 * @str: string to search
 * @c: character to find
 * Return: pointer to char or NULL
 */
char			*find_last_char(const char *s, int c);
/**
 * find_substring - finds needle in haystack within len bytes
 * @haystack: string to search in
 * @needle: string to find
 * @len: max bytes to search
 * Return: pointer to match or NULL
 */
char			*find_substring(const char *haystack,
					const char *needle, size_t len);
/**
 * compare_strings - compares n chars of two strings
 * @s1: first string
 * @s2: second string
 * @n: max chars to compare
 * Return: difference or 0 if equal
 */
int				compare_strings(const char *s1, const char *s2, size_t n);
/**
 * copy_string - copies src to dst with size limit
 * @dst: destination buffer
 * @src: source string
 * @dstsize: size of dst buffer
 * Return: length of src
 */
size_t			copy_string(char *dst, const char *src, size_t dstsize);
/**
 * concat_string - concatenates src to dst with size limit
 * @dst: destination buffer
 * @src: source string
 * @dstsize: size of dst buffer
 * Return: total length attempted
 */
size_t			concat_string(char *dst, const char *src, size_t dstsize);
/**
 * iterate_string - applies f to each char with index
 * @s: string to iterate
 * @f: function to apply
 */
void			iterate_string(char *s, void (*f)(unsigned int, char *));
/**
 * map_string - applies f to each char, returns new string
 * @s: source string
 * @f: function to apply
 * Return: new string or NULL
 */
char			*map_string(char const *s, char (*f)(unsigned int, char));
/**
 * split_string - splits string by delimiter
 * @s: string to split
 * @c: delimiter char
 * Return: array of strings or NULL
 */
char			**split_string(char const *s, char c);

/**
 * zero_memory - sets memory to zero
 * @b: pointer to memory
 * @len: number of bytes
 */
void			zero_memory(void *b, size_t len);
/**
 * set_memory - fills memory with byte c
 * @b: pointer to memory
 * @c: byte value to set
 * @len: number of bytes
 * Return: pointer to b
 */
void			*set_memory(void *b, int c, size_t len);
/**
 * copy_memory - copies memory (no overlap)
 * @dst: destination
 * @src: source
 * @len: number of bytes
 * Return: pointer to dst
 */
void			*copy_memory(void *dst, const void *src, size_t len);
/**
 * move_memory - copies memory (handles overlap)
 * @dest: destination
 * @src: source
 * @n: number of bytes
 * Return: pointer to dest
 */
void			*move_memory(void *dst, const void *src, size_t len);
/**
 * find_memory_byte - finds byte in memory
 * @s: memory to search
 * @c: byte to find
 * @n: number of bytes to search
 * Return: pointer to byte or NULL
 */
void			*find_memory_byte(const void *s, int c, size_t n);
/**
 * compare_memory - compares memory
 * @s1: first memory block
 * @s2: second memory block
 * @n: number of bytes
 * Return: difference or 0 if equal
 */
int				compare_memory(const void *s1, const void *s2, size_t len);
/**
 * allocate_zeroed - allocates and zeroes memory
 * @count: number of elements
 * @size: size of each element
 * Return: pointer to memory or NULL
 */
void			*allocate_zeroed(size_t count, size_t size);
/**
 * get_bit - returns the value of a specific bit in an integer
 * @num: the number from which to extract the bit
 * @bit: position of the bit to get (starting from the right, 0-based)
 * Return: 0 or 1, returns 0 for an invalid bit index
 */
int				get_bit(int num, int bit);

/**
 * write_char_fd - writes char to fd
 * @c: character to write
 * @fd: file descriptor
 */
void			write_char_fd(char c, int fd);
/**
 * write_string_fd - writes string to fd
 * @s: string to write
 * @fd: file descriptor
 */
void			write_string_fd(char *s, int fd);
/**
 * write_line_fd - writes string + newline to fd
 * @s: string to write
 * @fd: file descriptor
 */
void			write_line_fd(char *s, int fd);
/**
 * write_int_fd - writes integer to fd
 * @n: integer to write
 * @fd: file descriptor
 */
void			write_int_fd(int n, int fd);
/**
 * write_console - writes a colored log prefix and a formatted message
 * @type: console log type
 * @format: printf-style message format
 * Return: number of bytes written, or -1 on error
 */
int				write_console(t_console_type type, const char *format, ...);
/**
 * print_formatted - prints formatted output to stdout
 * @format: format string
 * Return: number of bytes written
 */
int				print_formatted(const char *format, ...);
/**
 * print_char - writes one character to stdout
 * @c: character to write
 * Return: number of bytes written
 */
int				print_char(char c);
/**
 * print_string - writes a string to stdout
 * @str: string to write
 * Return: number of bytes written
 */
int				print_string(char *str);
/**
 * print_int - writes a signed integer to stdout
 * @n: number to write
 * Return: number of bytes written
 */
int				print_int(int n);
/**
 * print_unsigned - writes an unsigned integer to stdout
 * @n: number to write
 * Return: number of bytes written
 */
int				print_unsigned(unsigned int n);
/**
 * print_hex - writes an unsigned number in hexadecimal
 * @form: hexadecimal letter case selector
 * @nbr: number to write
 * Return: number of bytes written
 */
int				print_hex(char form, unsigned long long nbr);
/**
 * print_pointer - writes a pointer to stdout
 * @ptr: pointer value
 * Return: number of bytes written
 */
int				print_pointer(unsigned long long ptr);

/**
 * create_node - creates new list node
 * @content: content for the node
 * Return: new node or NULL
 */
t_list			*create_node(void *content);
/**
 * add_node_front - adds node at list start
 * @lst: pointer to list head
 * @new_node: node to add
 */
void			add_node_front(t_list **lst, t_list *new_node);
/**
 * list_size - counts list nodes
 * @lst: list head
 * Return: number of nodes
 */
int				list_size(t_list *lst);
/**
 * last_node - returns last node
 * @lst: list head
 * Return: last node or NULL
 */
t_list			*last_node(t_list *lst);
/**
 * add_node_back - adds node at list end
 * @lst: pointer to list head
 * @new_node: node to add
 */
void			add_node_back(t_list **lst, t_list *new_node);
/**
 * delete_node - deletes one node
 * @lst: node to delete
 * @del: function to delete content
 */
void			delete_node(t_list *lst, void (*del)(void *));
/**
 * clear_list - deletes entire list
 * @lst: pointer to list head
 * @del: function to delete content
 */
void			clear_list(t_list **lst, void (*del)(void *));
/**
 * iterate_list - applies f to each node content
 * @lst: list head
 * @f: function to apply
 */
void			iterate_list(t_list *lst, void (*f)(void *));
/**
 * map_list - creates new list by applying f
 * @lst: source list
 * @f: function to apply
 * @del: function to delete on error
 * Return: new list or NULL
 */
t_list			*map_list(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/**
 * get_next_line - reads a line from file descriptor
 * @fd: file descriptor to read from
 * Return: line read or NULL if EOF/error
 */
char			*get_next_line(int fd);

/**
 * create_arena - creates a fixed-size arena allocator
 * @capacity: number of bytes owned by the arena
 * Return: arena or NULL
 */
t_arena			*create_arena(size_t capacity);
/**
 * destroy_arena - frees an arena and its backing buffer
 * @arena: arena to destroy
 */
void			destroy_arena(t_arena *arena);
/**
 * reset_arena - marks every arena allocation as reusable
 * @arena: arena to reset
 */
void			reset_arena(t_arena *arena);
/**
 * arena_alloc - allocates aligned memory from the arena
 * @arena: arena to allocate from
 * @size: requested byte count
 * Return: allocated memory or NULL
 */
void			*arena_alloc(t_arena *arena, size_t size);
/**
 * arena_zalloc - allocates zeroed aligned memory from the arena
 * @arena: arena to allocate from
 * @size: requested byte count
 * Return: allocated memory or NULL
 */
void			*arena_zalloc(t_arena *arena, size_t size);
/**
 * arena_remaining - returns the number of bytes still available
 * @arena: arena to inspect
 * Return: remaining bytes
 */
size_t			arena_remaining(const t_arena *arena);

#endif
