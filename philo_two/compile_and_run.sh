#!/bin/sh

	#make && ./philo_two 4 1000 25 50 10

#nobody die
	make && ./philo_two 5 800 200 200

#each philos must eat 7 times
#	make && ./philo_two 5 800 200 200 7

#nobody die
#	make && ./philo_two 4 410 200 200

#philos should die
#	make && ./philo_two 4 310 200 100

#check rigth die-time (correct in 1500ms)
#	make && ./philo_two 200 1500 500 2000

#check rigth die-time (correct in 1500ms)
#	make && ./philo_two 2 1500 2000 2000