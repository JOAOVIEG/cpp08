/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:30:31 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/30 11:07:12 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include "easyfind.tpp"

class NotFoundException : public std::exception {
	NotFoundException() {}
	NotFoundException(const NotFoundException& other) {
		(void)other;
	}
	virtual ~NotFoundException() throw() {}
	
	NotFoundException& operator=(const NotFoundException& other) {
		(void)other;
		return *this;
	}
	
	const char* what() const throw() { return "Element not found.";}
};

template <typename T>
typename T::iterator easyfind(T& container, int value);
#endif