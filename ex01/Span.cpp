/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 07:22:06 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/31 14:40:32 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>
/*member function to add a single Number to the Span*/
/*It will be used in order to fill it*/
/*Trhows exception if inserting a new element when*/
/*there are N elements already*/
void Span::addNumber(int number) {
	if (v.size() > N)
		throw std::out_of_range("Span is full");
	v.push_back(number);
}

/*find out the shortest span (or distance) between all the */
/*numbers stored, and return it.*/
/*If there are no numbers stored,or only one, throw an exception.*/
int	Span::shortestSpan() {
	if (v.size() < 2) {
		throw std::logic_error("Not enough numbers to find a span.");
	}
	
	int min = std::numeric_limits<int>::max();
	std::vector<int> sorted = v;
	std::sort(sorted.begin(), sorted.end());
	for (std::vector<int>::iterator it = sorted.begin() + 1; it != sorted.end(); ++it) {
		int span = *it - *(it - 1);
		if (span < min)
			min = span;
	}
	return min;
}

/*find out the shortest span (or distance) between all the */
/*numbers stored, and return it.*/
/*If there are no numbers stored,or only one, throw an exception.*/
int Span::longestSpan() {
	if (v.size() < 2) {
		throw std::logic_error("Not enough numbers to find a span.");
	}
	std::vector<int>::iterator min = std::min_element(v.begin(), v.end());
	std::vector<int>::iterator max = std::max_element(v.begin(), v.end());
	
	return (*max - *min);
}