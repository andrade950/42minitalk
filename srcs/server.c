/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:55:47 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/03 18:54:21 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include "../inc/utils.h"

t_state	g_state = {NULL, NULL, 0};

static char	*append_c(char *start, char c)
{
	size_t	len;
	char	*temp;

	if (!start)
		return (NULL);
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

static void	append_to_full_str(char c)
{
	char	*new_full_str;

	if (!g_state.full_str)
		g_state.full_str = ft_strdup("");
	new_full_str = append_c(g_state.full_str, c);
	if (new_full_str)
		g_state.full_str = new_full_str;
	else
	{
		if (g_state.full_str)
			free(g_state.full_str);
		g_state.full_str = NULL;
	}
}

static void	print_str(char **bits)
{
	char	c;

	if (!bits || !*bits)
		return ;
	c = bin_to_ascii(*bits);
	append_to_full_str(c);
	if (c == '\0' && g_state.full_str)
	{
		ft_putendl_fd(g_state.full_str, 1);
		free(g_state.full_str);
		g_state.full_str = NULL;
	}
	free(*bits);
	*bits = NULL;
}

static void	append_bit(int signum)
{
	if (!g_state.bits)
	{
		g_state.bits = ft_strdup("");
		g_state.bit_count = 0;
	}
	if (signum == SIGUSR2)
		g_state.bits = append_c(g_state.bits, '0');
	else
		g_state.bits = append_c(g_state.bits, '1');
	if (!g_state.bits)
	{
		cleanup();
		return ;
	}
	g_state.bit_count++;
	if (g_state.bit_count == 8)
	{
		print_str(&g_state.bits);
		g_state.bit_count = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, append_bit);
	signal(SIGUSR2, append_bit);
	signal(SIGINT, handle_sigint);
	ft_printf("Server PID: %u\n", getpid());
	while (1)
		pause();
	return (0);
}
