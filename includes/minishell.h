#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
 #include <sys/stat.h> 
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"

#define PROMPT "bigSmile> "
#define TRUE 1
#define GREAT 1
#define LESS 2
#define GREATGREAT 3
#define LESSLESS 4

int		g_exit;

typedef struct s_cmds
{
	char			**env; 	
	char			**args;		
	int				count_args;
	int				pipe;
	int				redir[2];
	char			*infile;
	char			*outfile;
	struct s_cmds	*next;
}	t_cmds;

char	*rl_gets (void);
char 	**get_env(char **envp);
char	**get_path(void);
char	*test_path(char **path, char *cmd);
void	ft_error(int err);
void	free_2d_char(char **str);
void 	free_arr(char **arr);

#endif