/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:30:32 by eerika            #+#    #+#             */
/*   Updated: 2021/10/11 15:37:19 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	error_export(char *err)
{
	write(STDOUT_FILENO, "minishell: export: `", 20);
	write(STDOUT_FILENO, err, ft_strlen(err) + 1);
	write(STDOUT_FILENO, "': not a valid identifier\n", 26);
}

void	error_unset(int nbr, char *err)
{
	g_exit = nbr;
	write(STDOUT_FILENO, "minishell: unset: ", 19);
	write(STDOUT_FILENO, err, ft_strlen(err) + 1);
	write(STDOUT_FILENO, ": not a valid identifier\n", 26);
}

void	error_exit(int nbr, char *err)
{
	g_exit = nbr;
	if (nbr == 255)
	{
		write(STDOUT_FILENO, "exit\nminishell: exit: ", 23);
		write(STDOUT_FILENO, err, ft_strlen(err) + 1);
		write(STDOUT_FILENO, ": numeric argument required\n", 29);
		exit(g_exit);
	}
	write(STDOUT_FILENO, "minishell: exit: too many arguments\n", 37);
}

void	ft_error(int err)
{
	if (err == 1)
		printf("Error: cannot allocate memory\n");
	exit(err);
}
