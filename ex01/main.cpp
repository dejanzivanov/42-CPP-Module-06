/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:45:10 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/26 17:45:21 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>
#include "Data.hpp"

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data		*data;
	uintptr_t	serialized;
	Data		*deserialized;

	data = new Data();
	std::cout << "data ptr = " << data << std::endl;
	std::cout << "\t value = " << data->getValue() << std::endl;

	serialized = serialize(data);
	std::cout << "serialize(data ptr) = " << serialized << std::endl;

	deserialized = deserialize(serialized);
	std::cout << "deserialize(serialize(data ptr)) = " << deserialized << std::endl;
	std::cout << "\t value = " << deserialized->getValue() << std::endl;

	delete data;

	return 0;
}