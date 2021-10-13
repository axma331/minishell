/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <feschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:45:45 by eerika            #+#    #+#             */
/*   Updated: 2021/10/11 16:27:00 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	env_cmd(t_cmds *cmd)
{
	int	i;

	i = -1;
	if (cmd->args[1])
	{
		g_exit = 127;
		write(1, "minishell: ", 12);
		write(1, cmd->args[1], ft_strlen(cmd->args[1]));
		write(1, ": No such file or directory", 28);
	}
	else
	{
		while (cmd->env[++i])
			if (ft_strchr(cmd->env[i], '='))
				printf("%s\n", cmd->env[i]);
		g_exit = 0;
	}
}
