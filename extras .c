/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:53:47 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/18 16:53:48 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// handling of /
// void	expa(char *str, t_list *env, char *result)
// {
// 	int	i;
// 	int	start;
// 	int	k;
// 	int	s_quotes;

// 	ft_vars(&k, &i, &start, &s_quotes);
// 	if (!str)
// 		return ;
// 	while (str[i])
// 	{
// 		if (i >= 1 && str[i - 1] && str[i - 1] != '\"' && str[i] == '\'')
// 			s_quotes = !s_quotes;
// 		// if (str[i] == '\\' && str[i + 1] == '$')
// 		// 	result[start++] = str[++i];
// 		else if (str[i] == '$' && !s_quotes)
// 			handle_dollar(str, env, result, &i, &start);
// 		else
// 			result[start++] = str[i];
// 		i++;
// 	}
// 	result[start] = '\0';
// }

//  && (!s[i - 1]) || (s[i - 1] && s[i - 1] != '\\'))

// && (!s[i - 1] || (s[i - 1] && s[i - 1] != '\\')
//&& (!s[start - 1] || (s[start - 1] && s[start - 1] != '\\'))