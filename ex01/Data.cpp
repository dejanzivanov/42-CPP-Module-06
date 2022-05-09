/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:36:39 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/26 01:32:11 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : _value(1337)
{
	return;
}

Data::Data(const Data &data)
{
	*this = data;
}

Data::~Data()
{
	return;
}

Data	&Data::operator=(const Data &data)
{
	if (this != &data)
		this->_value = data._value;
	return *this;
}

int	Data::getValue(void) const
{
	return _value;
}