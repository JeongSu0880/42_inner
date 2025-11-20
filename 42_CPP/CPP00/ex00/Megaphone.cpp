/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:58:21 by jungslee          #+#    #+#             */
/*   Updated: 2024/09/24 22:01:27 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
	int	i = 1;
	int	j = 0;
	char c;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				c = argv[i][j];
				std::cout << static_cast<char>(std::toupper(c));
				j++;
			}
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
