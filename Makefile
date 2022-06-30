NAME=libunicorn

SRC_PATH = ./src/

SRC_NAME = \
	runner/uni_runner_add_suite.c\
	runner/uni_runner_new.c\
	runner/uni_runner_run.c\
	suite/uni_suite_add_test.c\
	suite/uni_suite_new.c\
	suite/uni_suite_run.c\
	test/uni_test_new.c\
	test/uni_test_run.c\
	reporter/uni_view_result.c\
	reporter/xml/uni_xml_reporter.c\
	reporter/xml/uni_xml_suite.c\
	reporter/xml/uni_xml_test.c

OBJ_PATH=./obj/
INC_PATH=./include

INC_NAME=libft.h
INC = $(addprefix -I, $(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

LIB_NAME = $(NAME).a
LIB_PATH = ./
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

CC = gcc
CFLAGS = -Wall -Wextra -Ofast -Os

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

#### Compilation
all: $(NAME)

$(NAME): $(OBJ) $(LIB)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $(INC) -o $@ $<

$(LIB):
	@echo "Compiling $(NAME)..."
	@ar rc $@ $(OBJ)
	@ranlib $@


#### Cleanup rules
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)

re: fclean all

# test: re
# 	@echo "Testing $(NAME)..."
# 	@make -C tests
# 	@echo ""
# 	@./tests/test

.PHONY: all clean fclean re
