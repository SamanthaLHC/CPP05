NAME = bureaucrat

CXX = c++
CXXFLAGS = -MMD -g3 -Wall -Wextra -Werror -std=c++98


INCLUDE = -I./includes

SRCS_PATH = ./srcs/
OBJ_PATH = ./objs/

SRCS = $(addprefix $(SRCS_PATH), \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		Intern.cpp \
		main.cpp)

OBJS	= $(SRCS:$(SRCS_PATH)%.cpp=$(OBJ_PATH)%.o)
DEPS	= $(SRCS:$(SRCS_PATH)%.cpp=$(OBJ_PATH)%.d)

all: $(NAME)

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

$(OBJ_PATH)%.o: $(SRCS_PATH)%.cpp
	mkdir -p $(OBJ_PATH)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -rf ${OBJS} ${DEPS}

fclean: clean
	rm -rf ${NAME}
	rm -rf ${OBJ_PATH}
	rm -f *_shrubbery

re: fclean
	
	make all

grind: ${NAME}
		valgrind ./$(NAME)

run: $(NAME)
	./$(NAME)

.PHONY: clean fclean re grind run

-include ${DEPS}