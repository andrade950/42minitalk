/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:56:06 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/03 18:54:23 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/include/ft_printf.h"
# include "utils.h"
# include <signal.h>

typedef struct s_state
{
	char	*full_str;
	char	*bits;
	int		bit_count;
}			t_state;

extern t_state	g_state;

#endif
