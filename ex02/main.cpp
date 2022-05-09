/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:47:10 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/26 17:46:58 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <ctime>
# include <cstdlib>
# include <iostream>

Base	*generate(void)
{
	int	randInt;

	randInt = std::rand() % 3;
	if (randInt == 0)
	{
		return (new A());
	}
	if (randInt == 1)
	{
		return (new B());
	}
	return (new C());
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
	{
		std::cout << "A" << std::endl;
		return;
	}
	if (dynamic_cast<B *>(p) != NULL)
	{
		std::cout << "B" << std::endl;
		return;
	}
	if (dynamic_cast<C *>(p) != NULL)
	{
		std::cout << "C" << std::endl;
		return;
	}
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e) {}
	
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e) {}
}


int	main(void)
{
	Base	*p;
	srand(time(NULL));

	p = generate();
	identify(p);
	identify(*p);
	delete p;
	return (0);
}