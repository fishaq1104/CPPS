CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Cat.cpp main.cpp AAnimal.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = ex02

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re