/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:37:34 by tamsibesson       #+#    #+#             */
/*   Updated: 2022/06/24 00:03:38 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freetab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	**get_path(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH", 4))
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

int	cmd_with_path(char *cmd)
{
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
	{
		if (access(cmd, F_OK) == 0)
			return (1);
		else
		{
			ft_putstr_fd("no such file or directory: ", 2);
			ft_putstr_fd(cmd, 2);
			ft_putstr_fd("\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	int		i;
	char	*cmd_path;
	char	*add_slash;
	char	**path;

	i = 0;
	if (cmd_with_path(cmd))
		return (cmd);
	path = get_path(envp);
	if (!path)
		return (cmd);
	while (path[i])
	{
		add_slash = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(add_slash, cmd);
		free(add_slash);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	freetab(path);
	return (cmd);
}
