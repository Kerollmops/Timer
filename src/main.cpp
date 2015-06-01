/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 18:34:38 by crenault          #+#    #+#             */
/*   Updated: 2015/06/01 18:39:50 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Timer.hpp"
#include <unistd.h>

int					main(void) {

	Timer			timerA;
	Timer			timerB;

	// display
	std::cout << timerA << std::endl;
	std::cout << timerB << std::endl;

	// start
	timerA.start();
	timerB.start();

	// wait
	std::cout << "wait 200 000us" << std::endl;
	usleep(200000);

	// display
	std::cout << timerA << std::endl;
	std::cout << timerB << std::endl;

	// pause timerB
	std::cout << "pause timerB" << std::endl;
	timerB.pause();

	// wait
	std::cout << "wait 200 000us" << std::endl;
	usleep(200000);

	// display
	std::cout << timerA << std::endl;
	std::cout << timerB << std::endl;

	// restart timerB
	std::cout << "unpause timerB" << std::endl;
	timerB.unpause();

	// display
	std::cout << timerA << std::endl;
	std::cout << timerB << std::endl;
	return 0;
}
