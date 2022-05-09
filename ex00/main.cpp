/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:43:30 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/24 12:31:21 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convertor.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of argument, please use './programName value' format" << std::endl;
		return 1;	
	}
	Convertor convertor(argv[1]);
	std::cout << convertor;
}