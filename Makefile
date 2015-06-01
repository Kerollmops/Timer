# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenault <crenault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/01 12:08:28 by crenault          #+#    #+#              #
#    Updated: 2015/06/01 12:10:39 by crenault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# submodules
SUBMODULES =

# compiler
CC = clang++
# file type
FT = cpp
# flags
FLAGS = -Wall -Wextra -Werror
FLAGS += -std=c++1y -stdlib=libc++
FLAGS += -O3
# binary flags (add libraries)
BIN_FLAGS = $(FLAGS) $(FT_FLAGS)
# executable
NAME = libtimer.a

# to compile files
SRC = Timer.cpp
# header files
HDR = include/Timer.hpp
# objects files
OBJS = $(SRC:.$(FT)=.o)

# main rule
all: $(NAME)

# rebuild your bin
re: fclean $(NAME)

# reclone submodule and rebuild
rere: ffclean $(NAME)

$(NAME): $(SUBMODULES) $(OBJS)
	@ar rc $@ $(OBJS)
	@ranlib $@
	@echo $@ "updated!"

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
