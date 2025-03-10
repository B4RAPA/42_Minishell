/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:09:13 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/27 15:44:01 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_vars(int *i, int *start, int *s_quotes)
{
	*s_quotes = 0;
	*i = 0;
	*start = 0;
}

char	*expansion(const char *name, t_list *env)
{
	size_t	len;

	len = ft_strlen(name);
	while (env)
	{
		if (ft_strncmp(env->value, name, len) == 0 \
			&& env->value[len] == '=')
			return (env->value + len + 1);
		env = env->next;
	}
	return (NULL);
}

int	expas(const char *name, t_shell *mini, char *result, int start)
{
	char	*value;
	int		status;

	status = mini->exit_status;
	value = expansion(name, mini->env);
	if (!ft_strncmp(name, "?", 2))
	{
		if (g_exit_status != -100)
			status = g_exit_status;
		value = ft_itoa(status);
	}
	if (value)
	{
		while (*value)
		{
			result[start] = *value++;
			start++;
		}
		return (start);
	}
	return (start);
}

int	handle_dollar(char *str, t_shell *mini, char *result, int *i)
{
	char	name[100];
	int		k;
	int		start;	

	start = 0;
	if (*result)
		start = ft_strlen(result);
	k = 0;
	if (str[*i + 1] && !ft_strncmp(&str[*i + 1], "?", 1) && k == 0)
	{
		name[k++] = str[++(*i)];
		name[k] = '\0';
		(*i)++;
		return (expas(name, mini, result, start));
	}
	while (str[*i + 1] && (ft_isalpha(str[*i + 1])))
		name[k++] = str[++(*i)];
	name[k] = '\0';
	(*i)++;
	return (expas(name, mini, result, start));
}

char	*expa(char *str, t_shell *mini)
{
	int		i;
	int		start;
	int		s_quotes;
	char	*result;

	ft_vars(&i, &start, &s_quotes);
	result = ft_calloc(sizeof(char), 500);
	if (!str || !result)
		return (NULL);
	while (str[i])
	{
		if (i > 0 && (str[i - 1] != '\"' || s_quotes) && str[i] == '\'')
			s_quotes = !s_quotes;
		else if (str[i] == '$' && !s_quotes && str[i + 1])
		{
			start = handle_dollar(str, mini, result, &i);
			continue ;
		}
		result[start++] = str[i++];
	}
	result[start] = '\0';
	return (result);
}
