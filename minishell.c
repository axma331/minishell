#include "./includes/minishell.h"

t_cmds	*init_cmd(char **env) {
	t_cmds	*cmd;

	cmd = (t_cmds *)malloc(sizeof(t_cmds));
	if (!cmd)
		ft_error(1);
		cmd->env = env;		//указатель на копию переменных окружения
	cmd->args = (char **)malloc(sizeof(char *) * 2);
	if (!cmd->args)
		ft_error(1);
	cmd->args[0] = NULL;	//команда
	cmd->args[1] = NULL; 	//аргументы команды (массив будет увеличиваться при необходимости)	
	cmd->count_args = 0;	//количество аргументов команды, включая саму команду
	cmd->redir[0] = 0;		//наличие редиректа	
	cmd->redir[1] = 0;		//символ редиректа (см дефайны)
	cmd->pipe = 0;			//наличие пайпа (см cmd->next)
	cmd->infile = NULL; 	//имя входного файла
	cmd->outfile = NULL;	//имя выходного файла
	cmd->next = NULL;		//указатель на следующую команду при наличии пайп
	return (cmd);
}

int	main(int argc, char **argv, char **envp) {
	char	*line;
	char	**env;
	t_cmds	*cmd;

	g_exit = 0;
	env = get_env(envp); 		//копия переменных окружения
	// char **all_path = get_path();
	for (int i = 0; i < 3; i++) { //просто для проверки (должен быть бесконечного цикла)
		cmd = init_cmd(env);
		line = rl_gets();
		// parsing(line, cmd);    //Весь парсинг
		
		// signals();		
		// execution(cmd);
		// char *path = test_path(all_path, "ls");
		// printf("%s\n", path);

		free(line);
		free_cmd(cmd);
		// free(path);
	}
	clear_history();
	free_arr(env);
	// free_arr(all_path);
	
	// system("leaks minishell");
	// export MallocStackLogging=1  - in bash
	return (0);
}
