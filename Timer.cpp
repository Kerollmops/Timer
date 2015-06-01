/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 15:33:18 by crenault          #+#    #+#             */
/*   Updated: 2015/06/01 12:06:51 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Timer.hpp"

Timer::Timer()
	: _startMark(0), _stopMark(0), _pausedMark(0),
		_running(false), _paused(false) {

	//
}

Timer::Timer(Timer const &src) {

	*this = src;
}

Timer::~Timer() {

	//
}

Timer				&Timer::operator=(Timer const &rhs) {

	this->_startMark = rhs._startMark;
	this->_stopMark = rhs._stopMark;
	this->_paused = rhs._paused;
	this->_running = rhs._running;
	this->_paused = rhs._paused;
	return *this;
}

suseconds_t			Timer::_get_ticks() {

	struct timeval	tmp;

	gettimeofday(&tmp, NULL);
	return tmp.tv_usec + (tmp.tv_sec * 1000000);
}

void				Timer::start() {

	this->_startMark = Timer::_get_ticks();
	this->_stopMark = 0;
	this->_pausedMark = 0;
	this->_running = true;
	this->_paused = false;
}

void				Timer::pause() {

	if (this->_running == false || this->_paused == true)
		return ;

	this->_pausedMark = Timer::_get_ticks() - (this->_startMark);

	this->_running = false;
	this->_paused = true;
}

void				Timer::unpause() {

	if (this->_paused == false || this->_running == true)
		return ;

	this->_startMark = Timer::_get_ticks() - this->_pausedMark;
	this->_pausedMark = 0;

	this->_running = true;
	this->_paused = false;
}

bool				Timer::is_running() const {

	return this->_running;
}

bool				Timer::is_paused() const {

	return this->_paused;
}

suseconds_t			Timer::delta_us() const {

	if (this->_running == true)
		return Timer::_get_ticks() - this->_startMark;

	if (this->_paused == true)
		return this->_pausedMark;

	// Something went wrong here
	if (this->_startMark == 0)
		return 0;

	return (this->_pausedMark) - (this->_startMark);
}

suseconds_t			Timer::delta_ms() const {

	return this->delta_us() / 1000;
}

suseconds_t			Timer::delta_s() const {

	return this->delta_ms() / 1000;
}

std::string			Timer::str(void) const {

	std::stringstream		ss;

	ss	<< "Timer "
		<< ((this->_running) ? "running" : "paused")
		<< ": " << this->delta_us() << "ms";
	return ss.str();
}

std::ostream	&operator<<(std::ostream &o, Timer const &rhs) {

	o << rhs.str();
	return o;
}
