/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 07:22:02 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/31 14:50:34 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "Tests for addNumbers." << std::endl;
	int array[] = {6, 3, 17, 9, 11};
	
	/*cppreference: template<class InputIt>
		constexpr vector(InputIt first, InputIt last, const Allocator& = Allocator());*/
	/*this is the point of the exercise!!*/
	std::vector<int> v(array, array + (sizeof(array) / sizeof(int)));
	
	Span spn(5);
	spn.addNumbers(v.begin(), v.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}