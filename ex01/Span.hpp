/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 07:22:10 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/31 14:36:56 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <exception>
#include <iostream>

/*Develop a Span class that can store a maximum of N inetgers*/
class Span {
	public:	
		Span() : N(0) {}
		/*The parameterized constructor has a int argument*/
		/*represeenting the size of the container.*/
		Span(unsigned int n) : N(n) {}
		Span(const Span& other) : N(other.N), v(other.v){}
		virtual ~Span() {}
		
		Span& operator=(const Span& other) {
			if (this != &other) {
				N = other.N;
				v = other.v;
			}
			return *this;
		}
		
		void addNumber(int number);
		template <typename InputIterator>
		void addNumbers(InputIterator begin, InputIterator end) {
			if (std::distance(begin, end) > static_cast<int>(N - v.size()))
				throw std::out_of_range("Cannot add range, Span will exceed capacity.");
			v.insert(v.end(), begin, end);
		}
		int	shortestSpan();
		int longestSpan();
	private:
		unsigned int N;
		std::vector<int> v;
};

#endif