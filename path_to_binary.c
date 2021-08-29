#include "includes/minishell.h"
#include "libft/libft.h"
// все возможные пути к бинарникам
// вызвать один раз до цикла парсинга строки
char	**get_path(void)
{
	char	**path;
	char	*tmp_path;
	int		i;

	tmp_path = getenv("PATH");
	path = ft_split(tmp_path, ':');
	i = 0;
	while (path[i])
	{
		path[i] = ft_join(path[i], "/"); 
		//ft_join - это в strjoin добавила очистку path[i], 
		//поскольку strjoin маллочит новую память под новое значение
		i++;
	}
	return (path);
}

static char **path_copy(char **path)
{
	char	**res;
	int		i;

	i = 0;
	while(path[i])
		i++;
	res = (char **)malloc(sizeof(char *) * (i + 1));
	if (!res)
		ft_error(1);
	i = 0;
	while(path[i])
	{
		res[i] = ft_strdup(path[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

//нахождение пути к бинарнику
		// char *p = test_path(path_binary, line); //возможна утечка, проверить после билтинов
		// if (p != NULL)
		// 	free(p);
		// free_2d_char(path_binary);
char	*test_path(char **path, char *cmd)
{
	int		i;
	int		fd;
	char	**tmp_path;
	char 	*res;

	tmp_path = path_copy(path);
	i = 0;
	while (tmp_path[i])
	{
		tmp_path[i] = ft_join(tmp_path[i], cmd);
		fd = open(tmp_path[i], O_RDONLY);
		if (fd != -1)
		{
			close(fd);
			res = ft_strdup(tmp_path[i]);
			free_2d_char(tmp_path);
			return (res);
		}
		i++;
	}
	ft_putstr(cmd);
	ft_putstr(": command not found\n");
	free_2d_char(tmp_path);
	return (NULL);
}
