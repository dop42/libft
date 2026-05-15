NAME = utility_library.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INC_DIR = includes

SRCS = stdlib/string_to_int.c \
       stdlib/int_to_string.c \
       stdlib/allocate_zeroed.c \
       ctype/is_alpha.c \
       ctype/is_digit.c \
       ctype/is_alnum.c \
       ctype/is_ascii.c \
       ctype/is_printable.c \
       ctype/is_space.c \
       ctype/to_lower.c \
       ctype/to_upper.c \
       memory/set_memory.c \
       memory/zero_memory.c \
       memory/copy_memory.c \
       memory/move_memory.c \
       memory/compare_memory.c \
       memory/find_memory_byte.c \
       string/string_length.c \
       string/duplicate_string.c \
       string/substring.c \
       string/join_strings.c \
       string/trim_string.c \
       string/split_string.c \
       string/find_char.c \
       string/find_last_char.c \
       string/find_substring.c \
       string/compare_strings.c \
       string/copy_string.c \
       string/concat_string.c \
       string/iterate_string.c \
       string/map_string.c \
       io/write_char_fd.c \
       io/write_string_fd.c \
       io/write_line_fd.c \
       io/write_int_fd.c \
       io/write_console.c \
       io/get_next_line.c \
       printf/print_formatted.c \
       printf/print_char.c \
       printf/print_string.c \
       printf/print_int.c \
       printf/print_unsigned.c \
       printf/print_hex.c \
       printf/print_pointer.c \
       list/create_node.c \
       list/add_node_front.c \
       list/add_node_back.c \
       list/list_size.c \
       list/last_node.c \
       list/delete_node.c \
       list/clear_list.c \
       list/iterate_list.c \
       list/map_list.c \
       arena/create_arena.c \
       arena/arena_alloc.c \
       arena/arena_utils.c \
       extra/get_bit.c

SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS = $(SRCS:.c=.o)
HEADER = $(INC_DIR)/utility_library.h

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Building $(NAME)..."
	@ar -rsc $(NAME) $(OBJS)
	@echo "Done! $(NAME) is ready."

%.o: %.c $(HEADER)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@echo "Cleaning objects..."
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning library..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
