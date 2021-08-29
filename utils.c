#include "./includes/minishell.h"

void	ft_error(int err) {
	if (err == 1)
		printf("Error: cannot allocate memory\n");
	exit(err);
}

void	free_2d_char(char **str) {
	int	i;

	i = 0;
	if (str)
	{
		while(str[i])
		{
			free(str[i]);
			i++;
		}
	}
	free(str);	
}

void	free_cmd(t_cmds *cmd) {
	free_2d_char(cmd->args);
	free(cmd);
}

void free_arr(char **arr) {
	int i = 0;

	if (arr)
		while (arr[i]) {
			free(arr[i]);
			i++;	
		}
	if (arr)
		free(arr);
}