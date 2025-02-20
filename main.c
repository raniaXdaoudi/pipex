/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:19:35 by radaoudi          #+#    #+#             */
/*   Updated: 2022/06/24 00:37:02 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(char *arg, char **envp)
{
	char	**cmd;

	if (!arg[0])
	{
		ft_putstr_fd(": permission denied:\n", 2);
		exit(EXIT_FAILURE);
	}
	cmd = ft_split(arg, ' ');
	if (!cmd[0])
	{
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		freetab(cmd);
		exit(EXIT_FAILURE);
	}
	execve(get_cmd_path(cmd[0], envp), cmd, envp);
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	freetab(cmd);
	exit(EXIT_FAILURE);
}

static void	exec_first_cmd(int *pipefd, int *fd, char **av, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (perror("fork"));
	if (pid == 0)
	{
		fd[0] = open(av[1], O_RDONLY);
		if (fd[0] < 0)
			return (perror(av[1]));
		close(pipefd[0]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		exec_cmd(av[2], envp);
	}
}

static void	exec_last_cmd(int *pipefd, int *fd, char **av, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (perror("fork"));
	if (pid == 0)
	{
		fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd[1] < 0)
			return (perror(av[4]));
		close(pipefd[1]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		exec_cmd(av[3], envp);
	}
}

static void	pipex(char **av, char **envp)
{
	int	pipefd[2];
	int	fd[2];
	int	status;

	if (pipe(pipefd) < 0)
		return (perror(NULL));
	exec_first_cmd(pipefd, fd, av, envp);
	exec_last_cmd(pipefd, fd, av, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}

int	main(int ac, char **av, char **envp)
{
	if (ac != 5)
	{
		ft_putstr_fd("usage: ./pipex [file1] [cmd1] [cmd2] [file2]\n", 2);
		return (1);
	}
	pipex(av, envp);
	return (0);
}
