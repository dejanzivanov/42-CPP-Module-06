/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:36:41 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/26 00:45:44 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data
{
	private:
		int	_value;

		Data(const Data &data);
		Data	&operator=(const Data &data);
		
	public:
		Data(void);
		virtual ~Data();

		int	getValue(void) const;
};

# endif