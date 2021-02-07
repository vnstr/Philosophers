#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PHILO_ONE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

NAME = philo_one

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
						 init_trackings.c\
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

UTILS_FILES = get_time.c\
			  ft_mssleep.c

UTILS = $(addprefix utils/, $(UTILS_FILES))

################################################################################

###################################  LIBS  #####################################

LIBFT_DIR = src/libft/
LIBS = $(LIBFT_DIR)libft.a

################################################################################

###################################  OBJ     ###################################

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SEGINFOFLAG = -fsanitize=address
INCLD = include/

.c.o:
	$(CC) -I$(INCLD) -c $< -o $(<:.c=.o)
	@#$(CC) $(CFLAGS) -I$(INCLD) -c $< -o $(<:.c=.o)

################################################################################

#############################  MANDATORY COMMANDS  #############################

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@#$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re:	fclean	all

################################################################################

###############################  BONUS COMMANDS  ##############################

debug: $(OBJ)
	#make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(SEGINFOFLAG) $(LIBS) $(OBJ) -o $(NAME)

SHELL = /bin/zsh
norm:
	norminette -R CheckForbiddenSourceHeader **/*.c
	norminette -R CheckForbiddenSourceHeader **/*.h

################################################################################

.PHONY: all debug clean fclean re norm

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
