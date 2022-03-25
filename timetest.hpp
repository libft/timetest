/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timetest.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:53:53 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/03/25 19:30:38 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMETEST_HPP

# define TIMETEST_HPP

#include <sys/time.h>
#include <stdio.h>
#include <utility>
#include <vector>

#define S 1
#define MS 1000
#define NS 1000 * 1000
using namespace std;
class Time
{
	public:
	Time(int n);
	~Time(void);
	bool	print(int a, int b, int format);
	void	print_vector(vector<pair<int, int> >::iterator begin, vector<pair<int, int> >::iterator end, int format);
	bool	shot(void);
	private:
	struct timeval	*t;
	int	index;
	int	max;
};
#endif
