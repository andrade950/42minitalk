/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrade <andrade@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:55:47 by joaomart          #+#    #+#             */
/*   Updated: 2025/02/28 19:19:27 by andrade          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static char	*full_str = NULL;
static char	*bits = NULL;

static void	handle_exit(int signum)
{
	(void)signum;
	if (full_str)
		free(full_str);
	if (bits)
		free(bits);
	exit(0);
}

static unsigned char	bin_to_ascii(char *str)
{
	int				power;
	unsigned char	c;
	size_t			i;

	power = 1;
	c = 0;
	i = ft_strlen(str) - 1;
	while (i + 1 != 0)
	{
		c += power * (str[i] - '0');
		power *= 2;
		i--;
	}
	return (c);
}

static char	*append_c(char *start, char c)
{
	size_t	len;
	char	*temp;

	len = ft_strlen(start);
	temp = malloc(len + 2);
	if (!temp)
	{
		free(start);
		return (NULL);
	}
	ft_memcpy(temp, start, len);
	temp[len] = c;
	temp[len + 1] = '\0';
	free(start);
	return (temp);
}

static void	print_str()
{
	char	c;

	c = bin_to_ascii(bits);
	free(bits);
	bits = NULL;
	full_str = append_c(full_str, c);
	if (c == '\0')
	{
		ft_putendl_fd(full_str, 1);
		free(full_str);
		full_str = NULL;
	}
}

static void	append_bit(int signum)
{
	static int	bit_count;

	bit_count++;
	if (full_str == NULL)
		full_str = ft_strdup("");
	if (bits == NULL)
	{
		bits = ft_strdup("");
		bit_count = 1;
	}
	if (signum == SIGUSR2)
		bits = append_c(bits, '0');
	else
		bits = append_c(bits, '1');
	if (bit_count == 8)
		print_str();
}

int	main(void)
{
	ft_printf("Server PID: %u\n", getpid());
	signal(SIGUSR1, append_bit);
	signal(SIGUSR2, append_bit);
	signal(SIGINT, handle_exit);
	while (1)
		pause();
	return (0);
}
