/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:42:47 by jungslee          #+#    #+#             */
/*   Updated: 2024/10/11 23:13:23 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : arrayIndex(0), contactCount(0)
{
}

PhoneBook::~PhoneBook()
{
}

bool	PhoneBook::isWhiteSpaceOnly(std::string input)
{
	int	 i = 0;
	
	while (input[i] != '\0')
	{
		if (!std::isspace(input[i]))
			return false;
		i++;
	}
	return true;
}

std::string	PhoneBook::getInput(std::string prompt) 
{
	std::string content;

	std::cout << prompt << std::endl;
	do
	{
		std::getline(std::cin, content);
		if (std::cin.eof())
			exit(0);
	} while (isWhiteSpaceOnly(content));
	return (content);
}

void	PhoneBook::Add()
{
	std::string	input;
	int			i = this->arrayIndex;

	input = getInput("이름 : ");
	this->contact[i].setFirstName(input);

	input = getInput("성 : ");
	this->contact[i].setLastName(input);

	input = getInput("별명 : ");
	this->contact[i].setNickName(input);

	input = getInput("전화번호 : ");
	this->contact[i].setPhoneNumber(input);

	input = getInput("비밀 : ");
	this->contact[i].setDarkestSecret(input);

	std::cin.clear();
	if (this->arrayIndex == MAX_ARRAY_INDEX)
		this->arrayIndex = 0;
	else
		this->arrayIndex++;
	if (this->contactCount < MAX_CONTACT_NUM)
		this->contactCount++;
}

void	PhoneBook::Exit()
{
	exit(0);
}

void	PhoneBook::printContact(int idx, std::string first, std::string last, std::string nickname)
{
	if (idx == 0)
		std::cout << "|" << std::setfill(' ') << std::setw(PRINT_WIDTH) << "INDEX";
	else
		std::cout << "|" << std::setfill(' ') << std::setw(PRINT_WIDTH) << idx;
	std::cout << "|" << std::setfill(' ') << std::setw(PRINT_WIDTH) << first;
	std::cout << "|" << std::setfill(' ') << std::setw(PRINT_WIDTH) << last;
	std::cout << "|" << std::setfill(' ') << std::setw(PRINT_WIDTH) << nickname;
	std::cout << "|" << std::endl;
}

void	PhoneBook::Search()
{
	std::string firstName;
	std::string lastName;
	std::string nickName;

	printContact(0, "FIRST NAME", "LAST NAME", "NICKNAME");
	for (int i = 0; i < MAX_CONTACT_NUM; i++)
	{
		firstName = this->contact[i].getFirstName();
		if (firstName.length() > PRINT_WIDTH)
			firstName = firstName.substr(0, PRINT_WIDTH - 1) + ".";
		lastName = this->contact[i].getLastName();
		if (lastName.length() > PRINT_WIDTH)
			lastName = lastName.substr(0, PRINT_WIDTH - 1) + ".";
		nickName = this->contact[i].getNickName();
		if (nickName.length() > PRINT_WIDTH)
			nickName = nickName.substr(0, PRINT_WIDTH - 1) + ".";
		printContact(i + 1, firstName, lastName, nickName);
	}

	if (this->contactCount == 0)
	{
		std::cout << "아직 입력한 전화번호가 없습니다. " << std::endl;
		return ;
	}
	std::string num = PhoneBook::getInput("열람할 연락처의 인덱스를 입력해주세요.");
	const char *toChar = num.c_str();
	int input = atoi(toChar);
	while (!(1 <= input && input <= 8))
		num = PhoneBook::getInput("올바른 인덱스 번호를 입력해주세요.");
	if (this->contactCount < MAX_CONTACT_NUM && input > this->arrayIndex)
		std::cout << "해당 인덱스에 연락처가 입력되지 않았습니다." << std::endl;
	else
	{
		std::cout << "fist name : " << this->contact[input - 1].getFirstName() << std::endl;
		std::cout << "last name : " << this->contact[input - 1].getLastName() << std::endl;
		std::cout << "nickname : " << this->contact[input - 1].getNickName() << std::endl;
		std::cout << "phone number : " << this->contact[input - 1].getPhoneNumber() << std::endl;
		std::cout << "darkest secret : " << this->contact[input - 1].getDarkestSecret() << std::endl;
	}
}

void	PhoneBook::Run()
{
	std::string command;
	
	std::cout << "------------------------My Phone Book------------------------" << std::endl;
	while (!std::cin.eof())
	{
		command = PhoneBook::getInput("MENU : ADD / SEARCH / EXIT");
		if (command == "ADD")
			this->Add();
		else if (command == "SEARCH")
			this->Search();
		else if (command == "EXIT")
			this->Exit();
		else
		{
			std::cout << "명령어가 유효하지 않습니다. 다시 입력해주세요. " << std::endl;
			continue ;
		}
	}
}