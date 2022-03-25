/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timetest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:01:40 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/03/25 19:51:46 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timetest.hpp"

Time::Time(int n)
{
	index = 0;
	max = n;
	t = new struct timeval[max];
}

Time::~Time(void)
{
	delete []t;
}

bool	Time::print(int a, int b, int format)
{
	long	ns, ms, s;
	if (a < index && b < index && a < b)
	{
		ns = (t[b].tv_sec - t[a].tv_sec) * NS + t[b].tv_usec - t[a].tv_usec;
		printf("timediff of(%d->%d)  ", a, b);
		if (format == NS)
			printf("NS:%ld\n", ns);
		else if (format >= MS)
		{
			ms = ns / 1000;
			ns = ns % 1000;
			printf("MS:%ld, NS:%ld\n", ms, ns);
		}
		else
		{
			ms = ns / 1000;
			ns = ns % 1000;
			s = ms / 1000;
			ms = ms % 1000;
			printf("S:%ld MS:%ld, NS:%ld\n", s, ms, ns);
		}
	}
	return (false);
}
void	Time::print_vector(vector<pair<int, int> >::iterator begin, vector<pair<int, int> >::iterator end, int format)
{
	while (begin != end)
	{
		print(begin->first, begin->second, format);
		++begin;
	}
}
bool	Time::shot(void)
{
	if (index < max)
		gettimeofday(t + index++, 0);
	else
		return (false);
	return (true);
}
