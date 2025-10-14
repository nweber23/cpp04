MAKEFLAGS	= -s

CPP			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++17

NAME		= animal

SRCS		= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

OBJS_DIR	= objs
OBJS		= $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@printf '\033[32mExecutable %s created.\033[0m\n' "$(NAME)"

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CPP) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)
	@printf '\033[31mRemoved %s\033[0m\n' "$(OBJS_DIR)"

fclean: clean
	rm -f $(NAME)
	@printf '\033[31mRemoved %s\033[0m\n' "$(NAME)"

re:
	$(MAKE) fclean
	$(MAKE) all

party:
	@curl parrot.live

.PHONY: all clean fclean re party