/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:05:30 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/24 12:31:14 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTOR_HPP
# define CONVERTOR_HPP
# include <iostream>
# include <cstdlib>
# include <cerrno>
# include <limits>
# include <cstring>

class Convertor
{
	private:
		bool	_turnToChar;
		bool	_turnToInt;
		bool	_turnToFloat;
		bool	_turnToDouble;

		char	_characterValue;
		int		_integerValue;
		float	_floatValue;
		double	_doubleValue;

		int		_isAtRangeInt;
		std::string _range;
		bool	_stringError;
		bool	_outOfRange;

		Convertor(void);
		Convertor(const Convertor &convertor);
		Convertor &operator=(const Convertor &conversion);
		
		bool	_isAtRange(const char *value);
		int		_getType(const char *value);
		
		void	_convertFromCharacter(const char *value);
		void	_convertFromInteger(const char *value);
		void	_convertFromFloat(const char *value);
		void	_convertFromDouble(const char *value);
	
	public:
		Convertor(const char *value);
		virtual ~Convertor();

		void	outputCharacter(std::ostream &outputStream = std::cout) const;
		void	outputInteger(std::ostream &outputStream = std::cout) const;
		void	outputFloat(std::ostream &outputStream = std::cout) const;
		void	outputDouble(std::ostream &outputStream = std::cout) const;
		bool	getOutOfRange(void) const;
		bool	getStringError(void) const;
		
		static const int characterType = 0;
		static const int integerType = 1;
		static const int floatType = 2;
		static const int doubleType = 3;
		static const int errorType = 4;
};

std::ostream &operator<<(std::ostream &outputStream, const Convertor &convertor);

typedef void (Convertor::*convertorFunction)(const char *);

#endif