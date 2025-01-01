CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Fixed.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = ex01

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