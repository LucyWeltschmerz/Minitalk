/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:41:41 by larzuman          #+#    #+#             */
/*   Updated: 2021/11/04 16:41:44 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*add_char(char *str, unsigned int byte)
{
	char	*ptr;
	int		i;

	i = ft_strlen(str);
	ptr = malloc(i + 2);
	i--;
	while (i >= 0)
	{
		ptr[i] = str[i];
		i--;
	}
	ptr[ft_strlen(str)] = byte;
	ptr[ft_strlen(str) + 1] = '\0';
	if (str)
		free(str);
	return (ptr);
}

char	*ft_strrev(char *str)
{
	int	i;
	int	size;
	int	t;

	i = 0;
	size = ft_strlen(str);
	while (str[i] != 0 && i < size / 2)
	{
		t = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = t;
		i++;
	}
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen((char *)str) + 1 ));
	if (!(ptr))
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)str + i) = c;
		i++;
	}
	return (str);
}
