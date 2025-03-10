/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:28:14 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/27 14:08:39 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

# define RED "\033[31m"
# define RESET "\033[0m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"

# define CMD 0
# define EMPTY 1
# define ARG 2
# define PIPE 3
# define TRUNC 4
# define APPEND 5
# define INPUT 6
# define HEREDOC 8
# define END 9

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define ERROR 1
# define SUCCESS 0
# define IS_DIRECTORY 126
# define UNKNOWN_COMMAND 127

typedef struct s_token
{
	int					type;
	char				*str;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

typedef struct s_env
{
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_shell
{
	t_token	*token;
	t_list	*env;	
	char	*str;
	char	**cmd;
	t_list	*head;
	char	*objekt;
	char	*expansion;
	int		exit;
	int		count;
	int		in;
	int		out;
	int		pipein;
	int		pipeout;
	int		pids[256];
	int		fdin;
	int		fdout;
	int		flag;
	int		pipe;
	int		exit_status;
	int		fdhd[256];
	int		fds[256][2];
	int		cfd;
	int		sco;
}			t_shell;

typedef struct s_signals
{
	int		sigquit;
	int		sigint;
	pid_t	pid;
}				t_signals;

extern int	g_exit_status;

/*** Tool Functions ***/
int		quotes(char	*line);
int		get_env(t_shell *mini, char **envp);
int		is_builtin(t_token *token, t_shell *mini);
int		is_type(t_token *token, int type);
int		check_input(t_token *token);
void	reaper(void);
void	error(void);
void	free_lst(void *value);
void	free_env(t_shell *mini);
void	ft_free_arr(char **arr);
void	reset_std(t_shell *mini);
void	reset_fds(t_shell *mini);
void	close_fds(t_shell *mini);
void	free_token(t_token *token);
void	free_env_array(char **env_array);
void	delete_token(t_shell *mini, t_token *token);
void	restore_terminal(struct termios *oldt);
t_token	*find_cmd(t_token *token, int skip);
t_token	*prev_sep(t_token *start);
t_token	*next_sep(t_token *start);
t_token	*next_pipe(t_token *start);
t_token	*prev_pipe(t_token *start);
char	**env_to_array(t_list *env);
int		find_heredoc(t_token *cur);

/*** Parsing Functions ***/
int		connect(t_token *token);
int		check_quotes(char *str);
int		check_before(t_token *token);
int		expas(const char *name, t_shell *mini, char *result, int start);
char	*expansion(const char *name, t_list *env);
void	skip_dollar(char *str, char *result);
char	*get_input(t_shell *mini, t_token *token);
char	*space_sep(char *line);
char	*alloc_space(char *line);
char	*expa(char *str, t_shell *mini);
void	get_type(t_token *token);
void	ft_lstadd_back2(t_token **lst, t_token *new);
t_token	*skip_space(t_token *token, char *str);
t_token	*ft_lstnew2(char *content);
t_token	*parse(t_token *token, t_shell *mini);

/*** Execution Functions ***/
int		fork_command(t_shell *mini, int *count, int *pipefd);
int		pipe_command(int *pipefd);
int		error_message(char *path);
char	*find_dir(char *command, char *dir);
int		outredir(t_shell *mini, t_token *token, int type);
int		inredir(t_shell *mini, t_token *token, char *fname);
void	execute_cmd(t_shell *mini, t_token *token);
int		check_token(t_shell *mini, t_token *token, int *count);
int		inout_handle(t_shell *mini, t_token *start, int id);
char	**ftt_split(char const *s, char c);
size_t	ftt_countword(char const *s, char c);
char	**tok_to_str(t_token *start);
char	*split_path(const char *cmd, t_list *envp);
char	*herdocfile(t_shell *mini);
int		herdoc_file(t_shell *mini, t_token *s, t_token **cmd);
int		heredoc_handle(t_shell *mini, t_token *s, int id, t_token **cmd);
void	redirect_process(t_shell *mini, int index, int *pipefd);

/*** Builtin Functions ***/
int		ft_unset(t_shell *mini);
int		ft_cd(t_token *token, t_shell *mini);
int		ft_pwd(void);
int		ft_export(t_shell *mini);
int		strclen(char *str, const char c);
void	free_str(char **str);
int		ft_echo(t_token *token);
int		ft_env(t_list *env);
void	ft_exit(t_shell *mini);
void	here_doc(t_token *token, int *fd, t_shell *mini);
t_token	*skip_args(t_token *token);

/*** Signals ***/
void	set_child_signals(void);
void	restore_signals(void);
void	handle_signals(t_shell *mini);
void	silence_signals(void);
void	sigint_heredoc(int signal);
void	sigint(int signal);
void	sigint2(int signal);
void	sigquit(int signal, t_shell *mini, t_token *token);
void	sigquit2(int signal);
void	set_up(void);
void	restore(void);
void	sigquit_here(int signal, t_shell *mini);

#endif
