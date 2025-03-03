/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:56:01 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/03 16:02:01 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static void	send_msg(int pid, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

static char	*str_to_bin(char *str, size_t i, size_t j)
{
	char	*bin;
	int		c;
	int		bits;

	i = ft_strlen(str);
	bin = ft_calloc(i * 8 + 1, sizeof(char));
	if (bin == NULL)
		return (NULL);
	while (i > 0)
	{
		c = str[i - 1];
		bits = 8;
		while (bits > 0)
		{
			if (c % 2 == 1)
				bin[ft_strlen(str) * 8 - j -1] = '1';
			else
				bin[ft_strlen(str) * 8 - j -1] = '0';
			c /= 2;
			j++;
			bits--;
		}
		i--;
	}
	return (bin);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*bits;

	if (ac != 3)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	bits = str_to_bin(av[2], 0, 0);
	if (bits == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	send_msg(pid, bits);
	free(bits);
	return (0);
}
