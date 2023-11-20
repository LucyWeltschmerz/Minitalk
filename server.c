/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:42:20 by larzuman          #+#    #+#             */
/*   Updated: 2021/11/04 16:42:27 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_data	g_data;

int	*init_arr(int *a)
{
	int	i;
	int	nbr;

	nbr = 1;
	i = 7;
	a = malloc(sizeof(int) * 8 );
	while (i >= 0)
	{
		if (i == 7)
			nbr = 1;
		else
			nbr *= 2;
		a[i] = nbr;
		i--;
	}
	return (a);
}

static	void	handle_signal(int sig)
{
	int	i;
	int	*arr;

	arr = NULL;
	arr = init_arr(arr);
	i = 0;
	if (sig == SIGUSR1)
		i = 1;
	g_data.byte += i * arr[g_data.bits];
	g_data.bits++;
	if (g_data.bits == 8)
	{
		if (g_data.byte == 0)
			g_data.end = 1;
		g_data.str = add_char(g_data.str, g_data.byte);
		g_data.bits = 0;
		g_data.byte = 0;
	}
	free(arr);
}

void	init(void)
{
	g_data.str = NULL;
	g_data.bits = 0;
	g_data.byte = 0;
	g_data.end = 0;
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1, "Server is running: ", 19);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	init();
	while (1)
	{
		if (g_data.end)
		{
			write(1, g_data.str, ft_strlen(g_data.str));
			write(1, "\n", 1);
			free(g_data.str);
			init();
		}
	}
	return (0);
}
