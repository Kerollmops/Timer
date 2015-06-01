/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 15:32:48 by crenault          #+#    #+#             */
/*   Updated: 2015/06/01 15:07:33 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_HPP
# define TIMER_HPP

# include <iostream>
# include <sstream>
# include <sys/time.h>

class Timer {

public:
	/**
	 * @brief Empty contructor
	 * @details The timer is paused at the creation,
	 * call start() to launch it
	 */
	Timer(void);
	/**
	 * @brief Copy constructor
	 * @details The timer construct will have all the properties
	 * of the copied timer (paused, start tick, ...)
	 *
	 * @param src The timer to copy
	 */
	Timer(Timer const &src);
	/**
	 * @brief Destructor
	 * @details Will simply destruct the object
	 * and all its properties
	 */
	virtual ~Timer(void);
	/**
	 * @brief Equal operator
	 * @details Will be called when = is used:
	 * timerA = timerB
	 *
	 * @param rhs The right-hand-side object (timerB)
	 */
	Timer				&operator=(Timer const &rhs);

	/**
	 * @brief set a starting point in time
	 * @details If called multiple times, will restart
	 */
	void				start(void);

	/**
	 * @brief Temporarily stops the timer
	 * @details It will pause the timer
	 */
	void				pause(void);

	/**
	 * @brief Restart the timer if it was paused
	 * @details If you had called pause() before,
	 * it will unPause your timer
	 */
	void				unpause(void);

	// tells if the timer is running
	/**
	 * @brief tells if the timer is running
	 * @details If pause() had been called it will return false,
	 * otherwise it will return true
	 * @return true or false if timer running or not
	 */
	bool				is_running(void) const;

	/**
	 * @brief tells if the timer is paused
	 * @details Will return true if pause() had been called,
	 * false otherwise
	 * @return true or false if timer paused or not
	 */
	bool				is_paused(void) const;

	/**
	 * @brief Get time from start in nanoseconds
	 * @details will return the difference between start
	 * and know in nanoseconds
	 * @return A structure defined in sys/time.h
	 */
	suseconds_t			delta_us(void) const;

	/**
	 * @brief get time from start in milliseconds
	 * @details will return the difference between start
	 * and know in milliseconds
	 * @return A structure defined in sys/time.h
	 */
	suseconds_t			delta_ms(void) const;

	/**
	 * @brief get time from start in seconds
	 * @details will return the difference between start
	 * and know in seconds
	 * @return A structure defined in sys/time.h
	 */
	suseconds_t			delta_s(void) const;

	/**
	 * @brief Create a summary of the timer
	 * @details Simple std::string with some information on the timer
	 * @return Standard string
	 */
	std::string			str(void) const;

private:
	static suseconds_t	_get_ticks(void);

	suseconds_t			_startMark;
	suseconds_t			_stopMark;
	suseconds_t			_pausedMark;

	bool				_running;
	bool				_paused;

};

/**
 * @brief Outstream operator
 * @details Will be called when << operator
 * in a stringstream is used, will simply call str()
 * and put the string in the stream
 *
 * @param out The string stream in question
 * @param timer The timer object put after the << operator
 */
std::ostream		&operator<<(std::ostream &out, Timer const &timer);

#endif
