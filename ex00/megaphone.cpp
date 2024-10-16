/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:05:00 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/16 16:25:28 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define MEGAPHONE_DEFAULT "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

static void	megaphoneStr(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		str[i] = std::toupper(str[i]);
	std::cout << str;
}

int main(int argc, char **argv) {
	if (argc < 2)
		std::cout << MEGAPHONE_DEFAULT;
	else
		for (int i = 1; i < argc; i++)
			megaphoneStr(argv[i]);
	std::cout << std::endl;
	return (0);
}
