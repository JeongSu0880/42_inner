/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:01:01 by jungslee          #+#    #+#             */
/*   Updated: 2024/10/11 23:11:14 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

#define PRINT_WIDTH 10
#define MAX_CONTACT_NUM 8
#define MAX_ARRAY_INDEX 7
#define MIN_ARRAY_INDEX 0
#define TRUE 1
#define FALSE 0

class PhoneBook
{
	private:
		Contact 	contact[MAX_CONTACT_NUM];
		int			arrayIndex;
		int			contactCount;

		std::string	getInput(std::string prompt);
		bool		isWhiteSpaceOnly(std::string input);	
		void		printContact(int idx, std::string first, std::string last, std::string nickname);
		void		Add();
		void		Search();
		void		Exit();

	public:
		PhoneBook();
		~PhoneBook();
	
		void		Run();
};
