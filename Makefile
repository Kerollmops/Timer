# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenault <crenault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/01 12:08:28 by crenault          #+#    #+#              #
#    Updated: 2015/06/01 18:47:44 by crenault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Timer
TIMER_FOLD = .
TIMER_LIB = $(TIMER_FOLD)/libtimer.a
TIMER_FLAGS = -L$(TIMER_FOLD) -ltimer

# submodules
SUBMODULES =

# libraries
LIBRARIES =

# compiler
CC = clang++
# file type
FT = cpp
# flags
FLAGS = -Wall -Wextra -Werror
FLAGS += -std=c++1y -stdlib=libc++
FLAGS += -O3
# binary flags (add libraries)
BIN_FLAGS = $(FLAGS) $(TIMER_FLAGS)
# executable
NAME = libtimer.a

# to compile files
SRC = src/Timer.cpp
# header files
HDR = include/Timer.hpp
# objects files
OBJS = $(SRC:.$(FT)=.o)

# tests to compile files
SRC_TEST = src/main.cpp
# header files
HDR_TEST =
# objects files
OBJS_TEST = $(SRC_TEST:.$(FT)=.o)

# main rule
all: $(NAME)

# rebuild your bin
re: fclean $(NAME)

# reclone submodule and rebuild
rere: ffclean $(NAME)

# compile lib
$(NAME): $(SUBMODULES) $(OBJS)
	@ar rc $@ $(OBJS)
	@ranlib $@
	@echo $@ "updated!"

# compile test bin
test: $(NAME) $(OBJS_TEST)
	@$(CC) -o $@ $(OBJS_TEST) $(BIN_FLAGS)
	@echo $@ "updated!"
	@echo "Now, you can launch" $@ "!"

# making o files
%.o: %.$(FT) $(HDR)
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo $< "updated!"

# submodules
$(SUBMODULES):
	@git submodule init
	@git submodule update
	@echo $@ "updated!"

#
.PHONY: clean fclean ffclean

# clean o files
clean:
	@rm -rf $(OBJS)

# clean submodules
cleansubs:

# clean exec file and library
fclean: clean
	@rm -rf $(NAME)

# get empty and clean repo (without libs)
ffclean: fclean cleansubs
