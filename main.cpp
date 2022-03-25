/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:17:06 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/03/25 19:49:01 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timetest.hpp"

int	main(void)
{
	Time	t(3);
	vector<pair<int, int> >	way(5);
	int	i;

	t.shot();
	while (i < 1000000000)
		++i;
	t.shot();
	while (i < 1000000)
		++i;
	t.shot();
	way[0] = (make_pair(0, 1));
	way[1] = (make_pair(1, 2));
	way[2] = (make_pair(0, 1));
	t.print_vector(way.begin(), way.end(), NS);
}
