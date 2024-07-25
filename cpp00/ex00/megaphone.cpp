/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:24:09 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/28 17:32:32 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; argv[i]; ++i)
	{
		std::string s = argv[i];
		
		for (int j = 0; j < (int)s.size(); ++j)
			s[j] = std::toupper(s[j]);
		std::cout << s;
	}
	std::cout << std::endl;
	return (0);
}