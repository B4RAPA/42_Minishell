/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:08:03 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/27 13:57:03 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	heredoc_call(t_shell *mini, t_token *s, t_token **cmd);

void	here_doc(t_token *token, int *fd, t_shell *mini)
{
	char	*input;

	if (ft_strncmp(token->str, "<<", 2) != 0)
		token = token->next;
	while (1)
	{
		input = get_next_line(STDIN_FILENO);
		if (input == NULL || !input)
		{
			sigquit(SIGQUIT, mini, mini->token);
		}
		if (!input || (ft_strlen(input) > 1 && \
			ft_strncmp(input, token->next->str, ft_strlen(input) - 1) == 0))
		{
			free(input);
			break ;
		}
		ft_putstr_fd(input, *fd);
		free (input);
	}
	free_token(mini->token);
	free_env(mini);
}

int	find_heredoc(t_token *cur)
{
	t_token	*temp;

	temp = prev_pipe(cur);
	while (temp && temp->type != PIPE)
	{
		if (temp->type == HEREDOC)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	heredoc_handle(t_shell *mini, t_token *s, int id, t_token **cmd)
{
	t_token	*temp;
	int		i;

	(void)id;
	i = 0;
	temp = prev_pipe(s);
	while (temp)
	{
		if (i == 0 && is_type(temp, HEREDOC))
		{
			i = heredoc_call(mini, temp, cmd);
			if (i == -1)
				continue ;
		}
		if (i == -1)
			return (-1);
		temp = temp->next;
	}
	if (i == -1)
		return (-1);
	return (0);
}

static int	heredoc_call(t_shell *mini, t_token *s, t_token **cmd)
{
	char	*temp;
	int		pid;

	if (ft_strncmp(s->str, "<<", 2) == 0 && !s->next)
	{
		write(2, "bash: argument missing\n", 24);
		return (-1);
	}
	herdoc_file(mini, s, cmd);
	pid = fork();
	if (!pid)
	{
		set_child_signals();
		here_doc(s, &mini->fdhd[mini->sco], mini);
		temp = herdocfile(mini);
		free(temp);
		exit(1);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(mini->fdhd[mini->sco]);
	}
	return (0);
}
