/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:01:01 by chlimous          #+#    #+#             */
/*   Updated: 2024/09/15 03:13:30 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <math.h>

static int	get_sign(const char **nptr)
{
	if (**nptr == '-')
	{
		++(*nptr);
		return (-1);
	}
	else if (**nptr == '+')
		++(*nptr);
	return (1);
}

static double	get_value(const char **nptr, double *decimal_factor)
{
	double	res;
	int		is_decimal;

	res = 0.0;
	is_decimal = 0;
	while (**nptr)
	{
		if (ft_isdigit(**nptr))
		{
			res = res * 10.0 + ft_ascii_to_nb(**nptr);
			if (is_decimal)
				*decimal_factor *= 10.0;
		}
		else if (**nptr == '.' && !is_decimal)
			is_decimal = 1;
		else
			break ;
		++(*nptr);
	}
	return (res);
}

static double	calculate_exponent(double res, unsigned int exponent, \
		int exp_sign)
{
	while (exponent > 0)
	{
		if (exp_sign == 1)
			res *= 10.0;
		else if (exp_sign == -1)
			res /= 10.0;
		--exponent;
	}
	return (res);
}

static double	get_exponent(const char **nptr, double res)
{
	int				exp_sign;
	unsigned int	exponent;

	if (**nptr == 'e' || **nptr == 'E')
	{
		++(*nptr);
		exp_sign = get_sign(nptr);
		exponent = 0;
		while (ft_isdigit(**nptr))
		{
			if (exponent > INT_MAX / 10 && exp_sign == 1)
				return (INFINITY);
			else if (exponent > INT_MAX / 10 && exp_sign == -1)
				return (0);
			exponent = exponent * 10 + ft_ascii_to_nb(**nptr);
			++(*nptr);
		}
		res = calculate_exponent(res, exponent, exp_sign);
	}
	return (res);
}

double	ft_atof(const char *nptr)
{
	double	res;
	int		sign;
	double	decimal_factor;

	decimal_factor = 1.0;
	while (ft_isspace(*nptr))
		++nptr;
	sign = get_sign(&nptr);
	res = get_value(&nptr, &decimal_factor);
	res = get_exponent(&nptr, res);
	return (res / decimal_factor * sign);
}
