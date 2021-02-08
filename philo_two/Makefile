#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PHILO_ONE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

NAME = philo_two

SOURCE_FILES =	main.c\
				$(TABLE_INITIATION)\
				$(SIMULATION)\
				$(SAYING)\
				$(UTILS)

SRC =	$(addprefix src/, $(SOURCE_FILES))

##############################  TABLE INITIATION  ##############################

TABLE_INITIATION_FILES = init_table.c\
						 parse_arguments.c\
						 init_forks.c\
						 init_msgs.c\
						 init_philos.c\
						 init_tracking.c\
						 put_forks_to_philos.c

TABLE_INITIATION = $(addprefix table_initiation/, $(TABLE_INITIATION_FILES))

################################################################################

##############################     SIMULATION     ##############################

SIMULATION_FILES = start_simulation.c\
				   $(LIVE)\
				   track.c

#-----------------------------       LIVE         ------------------------------

LIVE_FILE = live.c\
			forks.c

LIVE = $(addprefix live/, $(LIVE_FILE))

#-------------------------------------------------------------------------------

SIMULATION = $(addprefix simulation/, $(SIMULATION_FILES))

################################################################################

##############################       SAYING       ##############################

SAYING_FILES = saying.c\
			   print.c

SAYING = $(addprefix saying/, $(SAYING_FILES))

################################################################################


##############################       UTILS        ##############################

UTILS_FILES = ft_strlen.c\
			  ft_memcmp.c\
			  ft_atoi.c\
			  ft_putchar_fd.c\
			  ft_putstr_fd.c\
			  ft_putnbr_fd.c\
			  ft_strdup.c\
			  get_time.c\
			  ft_mssleep.c

UTILS = $(addprefix utils/, $(UTILS_FILES))

################################################################################

###################################  OBJ     ###################################

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SEGINFOFLAG = -fsanitize=address
INCLD = include/

.c.o:
	$(CC) -I$(INCLD) -c $< -o $(<:.c=.o)

################################################################################

#############################  MANDATORY COMMANDS  #############################

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean	all

################################################################################

###############################  BONUS COMMANDS  ##############################

debug: $(OBJ)
	$(CC) $(SEGINFOFLAG) $(OBJ) -o $(NAME)

SHELL = /bin/zsh
norm:
	norminette -R CheckForbiddenSourceHeader **/*.c
	norminette -R CheckForbiddenSourceHeader **/*.h

################################################################################

.PHONY: all debug clean fclean re norm

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
