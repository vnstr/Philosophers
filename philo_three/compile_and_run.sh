#!/bin/sh

#nobody die

#	make && ./philo_three 5 800 200 200

#nobody die, 7 times eat
	make && ./philo_three 5 800 200 200 7

#nobody die, 8 times eat
#	make && ./philo_three 4 800 200 200 2

#nobody die
#	make && ./philo_three 4 410 200 200

#should die
#	make && ./philo_three 4 310 200 100

#check rigth die-time (correct in 1500ms)
#	make && ./philo_three 2 1500 2000 2000
