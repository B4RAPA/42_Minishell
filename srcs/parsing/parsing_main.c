/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:02:59 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/19 13:59:30 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*alloc_space(char *line)
{
	int		count;
	int		i;
	char	*str;

	count = 0;
	i = 0;
	str = NULL;
	while (line[i])
	{
		if ((line[i] == '>' && (line[i] && line[i + 1] == '>')) \
			|| (line[i] == '<' && (line[i] && line[i + 1] == '<')))
		{
			count += 3;
			i++;
		}
		else if ((line[i] == '<' ) || (line[i] == '>' ) || (line[i] == '|'))
			count += 2;
		i++;
	}
	str = malloc(sizeof(char) * (ft_strlen(line) + count * 2 + 5));
	if (!str)
		exit(EXIT_FAILURE);
	return (str);
}

char	*space_sep(char *line)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	j = 0;
	str = alloc_space(line);
	while (line[i])
	{
		if (((line[i] == '>') || (line[i] == '<') || (line[i] == '|')))
		{
			str[j++] = ' ';
			str[j++] = line[i++];
			if (((line[i - 1] && line[i - 1] == '>') && line[i] == '>') \
				|| ((line[i - 1] && line[i - 1] == '<') && line[i] == '<'))
				str[j++] = line[i++];
			str[j++] = ' ';
		}
		else
			str[j++] = line[i++];
	}
	str[j] = '\0';
	return (str);
}

int	check_quotes(char *str)
{
	char	*line;

	line = str;
	if (quotes(line) == -1 || quotes(line) == 0)
		return (quotes(line));
	ft_putstr_fd("Error. Unclosed quotes.", 2);
	return (1);
}

t_token	*parse(t_token *token, t_shell *mini)
{
	char	*line;
	char	*str;
	char	*line1;

	signal(SIGINT, sigint);
	line = get_input(mini, token);
	line1 = NULL;
	if (check_quotes(line) != -2)
	{
		line1 = expa(line, mini);
		if (line1)
		{
			free (line);
			line = line1;
		}
	}
	else if (check_quotes(line) == 2 || check_quotes(line) == 1)
		return (token);
	str = space_sep(line);
	free(line);
	token = skip_space(token, str);
	if (connect(token) == -1)
		return (token);
	get_type(token);
	return (token);
}
