/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:30:31 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/30 16:18:01 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

class NotFoundException : public std::exception {
	public:
		NotFoundException() {}
		NotFoundException(const NotFoundException& other) {
			(void)other;
		}
		virtual ~NotFoundException() throw() {}
		
		NotFoundException& operator=(const NotFoundException& other) {
			(void)other;
			return *this;
		}
		
		const char* what() const throw() { return "Element not found:";}
};

template <typename T>
typename T::iterator easyfind(T& container, int value);
#include "easyfind.tpp"
#endif