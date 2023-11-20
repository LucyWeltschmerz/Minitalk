/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:35:15 by larzuman          #+#    #+#             */
/*   Updated: 2021/11/04 22:35:41 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	char			*str;
	int				bits;
	unsigned int	byte;
	int				end;
}				t_data;

int		ft_strlen(char *str);
int		ft_atoi(const char *str);
char	*add_char(char *str, unsigned int byte);
char	*ft_itoa(int n);
void	negative_positive(int number, int *negative, unsigned int *positive_n);
char	*ft_strrev(char *str);
char	*ft_strdup(const char *str);
void	*ft_memset(void *str, int c, size_t n);

#endif
