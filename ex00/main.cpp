/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:30:23 by joaocard          #+#    #+#             */
/*   Updated: 2024/07/30 16:26:40 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <sstream>

int main()
{
	std::string a;
	std::string q;
	int n;
	int elem;
	
	std::cout << "Enter number of quests: " << std::endl;
	getline(std::cin, q);
	std::stringstream ss(q);
	ss >> n;

	int arr1[] = {1, 5 , 8 , 3, 10};
	int arr2[] = {5, 8, 6, 9, 2, 7};
	int arr3[] = {4, 7, 1, 8, 3, 9};
	
	std::vector<int> v(arr1, arr1 + (sizeof(arr1) / sizeof(int)));
	std::list<int> lst(arr2, arr2 + (sizeof(arr2) / sizeof(int)));
	std::deque<int> dq(arr3, arr3 + (sizeof(arr3) / sizeof(int)));

	for(int i = 0; i < n ; ++i) {
		std::cout << "Enter an element to look for: " << std::endl;
		getline(std::cin, a);
		std::stringstream ss(a);
		ss >> elem;
		
		try {
			std::vector<int>::iterator vitr = easyfind(v, elem);
			std::cout << "Found in vector: " << *vitr << std::endl;
		} catch (const NotFoundException& e) {
			std::cerr << e.what() << " in vector" << std::endl;
		}		
	
		try {
			std::list<int>::iterator litr = easyfind(lst, elem);
			std::cout << "Found in list: " << *litr << std::endl;
		} catch (const NotFoundException& e) {
			std::cerr << e.what() << " in list" << std::endl;
		}

		try {
			std::deque<int>::iterator qitr = easyfind(dq, elem);
			std::cout << "Found in deque: " << *qitr << std::endl;
		} catch (const NotFoundException& e) {
			std::cerr << e.what() << " in deque" << std::endl;
		}
	}
	return 0;
}
