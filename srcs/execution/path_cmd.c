/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:10:35 by idvinov           #+#    #+#             */
/*   Updated: 2025/02/27 13:35:40 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_tmp(char **tmp);
static char	*split_path2(char **tmp, int i, const char *cmd);

int	error_message(char *path)
{
	DIR	*folder;
	int	fd;
	int	ret;

	fd = open(path, O_WRONLY);
	folder = opendir(path);
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(path, STDERR);
	if (ft_strchr(path, '/') == NULL)
		ft_putendl_fd(": command not found", STDERR);
	else if (fd == -1 && folder == NULL)
		ft_putendl_fd(": No such file or directory", STDERR);
	else if (fd == -1 && folder != NULL)
		ft_putendl_fd(": is a directory", STDERR);
	else if (fd != -1 && folder == NULL)
		ft_putendl_fd(": Permission denied", STDERR);
	if (ft_strchr(path, '/') == NULL || (fd == -1 && folder == NULL))
		ret = UNKNOWN_COMMAND;
	else
		ret = IS_DIRECTORY;
	if (folder)
		closedir(folder);
	close(fd);
	return (ret);
}

char	*split_path(const char *cmd, t_list *envp)
{
	char	*path;
	char	**tmp;
	int		i;

	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/') != NULL)
	{
		path = ft_strdup(cmd);
		return (path);
	}
	while (ft_strncmp(envp->value, "PATH", 4) != 0)
		envp = envp->next;
	tmp = ft_split(envp->value + 5, ':');
	i = -1;
	path = split_path2(tmp, i, cmd);
	free_tmp(tmp);
	return (path);
}

static char	*split_path2(char **tmp, int i, const char *cmd)
{
	char	*path_part;
	char	*path;

	i = -1;
	while (tmp[++i])
	{
		path_part = ft_strjoin(tmp[i], "/");
		path = ft_strjoin(path_part, cmd);
		free (path_part);
		if (access(path, F_OK) == 0)
		{
			return (path);
		}
		if (!tmp[i + 1])
		{
			free(path);
			return (NULL);
		}
		free (path);
	}
	if (path)
		free(path);
	return (NULL);
}

static void	free_tmp(char **tmp)
{
	int	i;

	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
}

char	**env_to_array(t_list *env)
{
	char	**env_array;
	t_list	*current;
	int		i;
	int		j;

	current = env;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	env_array = malloc((i + 1) * sizeof(char *));
	if (!env_array)
		return (NULL);
	current = env;
	j = 0;
	while (current)
	{
		env_array[j++] = ft_strdup(current->value);
		current = current->next;
	}
	env_array[i] = NULL;
	return (env_array);
}
