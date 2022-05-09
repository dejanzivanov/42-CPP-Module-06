/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:05:50 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/25 00:35:53 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convertor.hpp"


static bool isOutOfRange(double value, int type)
{
	if (type == Convertor::floatType)
	{
		return (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max());
	}
	if (type == Convertor::integerType)
	{
		return (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max());
	}
	if (type == Convertor::characterType)
	{
		return (value < 0 || value > std::numeric_limits<char>::max());
	}
	return true;	
}

Convertor::Convertor(void) : _turnToChar(false), _turnToInt(false), _turnToFloat(false), _turnToDouble(false),
_characterValue(0), _integerValue(0), _floatValue(0.0f), _doubleValue(0.0), _isAtRangeInt(false), _range(""), _stringError(false), _outOfRange(false)
{
	return;
}

Convertor::Convertor(const char *value) : _turnToChar(false), _turnToInt(false), _turnToFloat(false), _turnToDouble(false),
_characterValue(0), _integerValue(0), _floatValue(0.0f), _doubleValue(0.0), _isAtRangeInt(false), _range(""), _stringError(false), _outOfRange(false)
{
	int type;
	convertorFunction convert[4] = {&Convertor::_convertFromCharacter, &Convertor::_convertFromInteger, &Convertor::_convertFromFloat, &Convertor::_convertFromDouble};
	
	if(_isAtRange(value))
	{
		return;
	}
	
	type = _getType(value);
	if(type == Convertor::errorType)
	{
		_stringError = true;
	}
	else
	{
		(this->*(convert[type]))(value);
	}
}

Convertor::Convertor(const Convertor &convertor)
{
	*this = convertor;
}

Convertor::~Convertor()
{
	return;
}

Convertor &Convertor::operator=(const Convertor &convertor)
{
	(void)convertor;
	return (*this);
}

std::ostream &operator<<(std::ostream &outputStream, const Convertor &convertor)
{
	if(convertor.getOutOfRange())
	{
		outputStream << "Error: value is out of range" << std::endl;
	}
	else if(convertor.getStringError())
	{
		outputStream << "Error: unrecognized format" << std::endl; 
	}
	else
	{
		convertor.outputCharacter(outputStream);
		convertor.outputInteger(outputStream);
		convertor.outputFloat(outputStream);
		convertor.outputDouble(outputStream);
	}
	return outputStream;
}

void Convertor::outputCharacter(std::ostream &outputStream) const
{
	outputStream << "char: ";
	
	if(!_turnToChar)
	{
		outputStream << "not possible" << std::endl;
		return;
	}
	if(_characterValue > 31 && _characterValue < 127)
	{
		outputStream << "'" << _characterValue << "'" << std::endl;
	}
	else
	{
		outputStream << "it is not possible to be displayed" << std::endl;
	}
}

void Convertor::outputInteger(std::ostream &outputStream) const
{
	outputStream << "int: ";
	if(!_turnToInt)
	{
		outputStream << "not possible" << std::endl;
		return;
	}
	outputStream << _integerValue << std::endl;
}

void Convertor::outputFloat(std::ostream &outputStream) const
{
	outputStream << "float: ";
	if (!_turnToFloat)
	{
		outputStream << "not possible" << std::endl;
		return; 
	}
	if(_isAtRangeInt)
	{
		outputStream << _range << "f" << std::endl;
	}
	else
	{
		outputStream.precision(1);
		outputStream << std::fixed << _floatValue << "f" << std::endl;	
	}
}

void Convertor::outputDouble(std::ostream &outputStream) const
{
	outputStream << "double: ";
	if (!_turnToDouble)
	{
		outputStream << "not possible" << std::endl;
		return; 
	}
	if (_isAtRangeInt)
	{
		outputStream << _range << std::endl;
	}
	else
	{
		outputStream.precision(1);
		outputStream << std::fixed << _doubleValue << std::endl;	
	}
}

bool Convertor::_isAtRange(const char *value)
{
	const std::string range[4] = {"inf", "+inf", "-inf", "nan"};

	for(int i = 0; i < 4; i++)
	{
		if(value == range[i] || value == (range[i] + "f"))
		{
			_isAtRangeInt = true;
			_range = range[i];
			if(i == 1)
			{
				_range = range[0];
			}
			_turnToFloat = true;
			_turnToDouble = true;
			return true;
		}
	}
	return false;
}

bool Convertor::getOutOfRange(void) const
{
	return _outOfRange;
}

bool Convertor::getStringError(void) const
{
	return _stringError;
}

int Convertor::_getType(const char *value)
{
	int		i;
	bool	isInteger = true;
	bool	isFloat = false;
	bool	noNumeric = true;

	i = 0;
	if (value[0] && value[1] == '\0' && (value[i] < '0' || value[i] > '9'))
	{
		return Convertor::characterType;
	}
	if (value[i] == '-' || value[i] == '+')
	{
		i++;
	}
	while (value[i] && value[i] >= '0' && value[i] <= '9')
	{
		i++;
		noNumeric = false;
	}
	if (value[i] == '.')
	{
		isInteger = false;
		i++;
		while (value[i] && value[i] >= '0' && value[i] <= '9')
		{
			noNumeric = false;
			i++;
		}
	}
	if (value[i] == 'f')
	{
		isFloat = true;
		i++;
	}
	if (value[i] || noNumeric || (isFloat && isInteger))
	{
		return Convertor::errorType;
	}
	if (isFloat)
	{
		return Convertor::floatType;
	}
	if (isInteger)
	{
		return Convertor::integerType;
	}

	return Convertor::doubleType;
}

void Convertor::_convertFromCharacter(const char *value)
{
	_characterValue = value[0];
	_turnToChar = true;
	_integerValue = static_cast<int>(_characterValue);
	_turnToInt = true;
	_floatValue = static_cast<float>(_characterValue);
	_turnToFloat = true;
	_doubleValue = static_cast<double>(_characterValue);
	_turnToDouble = true;
}

void Convertor::_convertFromInteger(const char *value)
{
	if ((strlen(value) == 10 && strcmp(value, "2147483647") > 0) || (value[0] == '-' && strlen(value) == 11 && strcmp(value + 1, "2147483648") > 0)
	|| (value[0] == '+' && strlen(value) == 11 && strcmp(value + 1, "2147483647") > 0))
	{
		_outOfRange = true;
		return ;
	}
	_integerValue = atoi(value);
	_turnToInt = true;
	_floatValue = static_cast<float>(_integerValue);
	_turnToFloat = true;
	_doubleValue = static_cast<double>(_integerValue);
	_turnToDouble = true;
	if(!isOutOfRange(_doubleValue, Convertor::characterType))
	{
		_characterValue = static_cast<char>(_integerValue);
		_turnToChar = true;
	}
}

void Convertor::_convertFromFloat(const char *value)
{
	char	*end = NULL;

	_floatValue =  std::strtof(value, &end);
	if (value == end)
	{
		_stringError = true;
		return ;
	}
	if (errno == ERANGE)
	{
		_outOfRange = true;
		return ;
	}
	_turnToFloat = true;
	_doubleValue = static_cast<double>(_floatValue);
	_turnToDouble = true;
	if (!isOutOfRange(_doubleValue, Convertor::integerType))
	{
		_integerValue = static_cast<int>(_floatValue);
		_turnToInt = true;
	}
	if (!isOutOfRange(_doubleValue, Convertor::characterType))
	{
		_characterValue = static_cast<char>(_floatValue);
		_turnToChar = true;
	}
}

void Convertor::_convertFromDouble(const char *value)
{
	char	*end;

	_doubleValue = std::strtod(value, &end);
	if (value == end)
	{
		_stringError = true;
		return ;
	}
	if (errno == ERANGE)
	{
		_outOfRange = true;
		return ;
	}
	_turnToDouble = true;
	if (!isOutOfRange(_doubleValue, Convertor::floatType))
	{
		_floatValue =  static_cast<float>(_doubleValue);
		_turnToFloat = true;
	}
	if (!isOutOfRange(_doubleValue, Convertor::integerType))
	{
		_integerValue = static_cast<int>(_floatValue);
		_turnToInt = true;
	}
	if (!isOutOfRange(_doubleValue, Convertor::characterType))
	{
		_characterValue = static_cast<char>(_floatValue);
		_turnToChar = true;
	}
}