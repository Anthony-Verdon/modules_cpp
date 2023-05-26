/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:51:04 by averdon           #+#    #+#             */
/*   Updated: 2023/03/14 18:20:58 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include <string>

struct	s_Data
{
	int		nb_person;
	std::string informations;
}	typedef Data;

class Serializer
{
	 public:
		static uintptr_t	serialize(Data *ptr);
		static Data		*deserialize(uintptr_t raw);
	 private:
		Serializer();
		~Serializer();
		Serializer (const Serializer &copy);
		Serializer &operator=(const Serializer&);
};

#endif
