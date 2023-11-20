/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:39:52 by larzuman          #+#    #+#             */
/*   Updated: 2021/11/06 15:39:54 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_intlen(int n)
{
	int			i;
	long long	t;

	i = 1;
	t = n;
	if (t < 0)
	{
		t *= -1;
		i++;
	}
	while (t >= 10)
	{
		t /= 10;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	nb;

	sign = 1;
	nb = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb * sign);
}

char	*ft_itoa(int n)
{
	int				idx;
	int				negative;
	unsigned int	positive_n;
	char			*value;

	if (n == 0)
		return (ft_strdup("0"));
	value = (char *)malloc(sizeof(char) * (ft_intlen(n) + 1));
	if (!(value))
		return (NULL);
	ft_memset(value, '\0', (ft_intlen(n) + 1));
	negative_positive (n, &negative, &positive_n);
	idx = 0;
	while (positive_n != 0)
	{
		value[idx++] = (positive_n % 10) + '0';
		positive_n = positive_n / 10;
	}
	if (negative)
		value[idx++] = '-';
	return (ft_strrev(value));
}

void	negative_positive(int number, int *negative, unsigned int *positive_n)
{
	if (number < 0)
		*negative = 1;
	else
		*negative = 0;
	if (number < 0)
		*positive_n = -number;
	else
		*positive_n = number;
}
