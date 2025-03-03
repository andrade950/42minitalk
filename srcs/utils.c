/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:13:33 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/03 18:42:15 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/minitalk.h"

void	cleanup(void)
{
	if (g_state.full_str)
		free(g_state.full_str);
	if (g_state.bits)
		free(g_state.bits);
	g_state.full_str = NULL;
	g_state.bits = NULL;
	g_state.bit_count = 0;
}

void	handle_sigint(int signum)
{
	(void)signum;
	cleanup();
	exit(0);
}

unsigned char	bin_to_ascii(char *str)
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
