/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:54:51 by okamotoyayo       #+#    #+#             */
/*   Updated: 2025/10/03 23:29:21 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>


int	builtin_echo(char **argv);

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	else if (ft_strcmp(cmd, "env") == 0)
		return (1);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	else
		return (0);
}

int	exec_builtin(char **argv)
{
	if (ft_strcmp(argv[0], "echo") == 0)
		return (builtin_echo(argv));
	// else if (ft_strcmp(argv[0], "cd") == 0)
	// 	return (builtin_cd(argv));
	// else if (ft_strcmp(argv[0], "pwd") == 0)
	// 	return (builtin_pwd());
	// else if (ft_strcmp(argv[0], "export") == 0)
	// 	return (builtin_export(argv));
	// else if (ft_strcmp(argv[0], "unset") == 0)
	// 	return (builtin_unset(argv));
	// else if (ft_strcmp(argv[0], "env") == 0)
	// 	return (builtin_env());
	// else if (ft_strcmp(argv[0], "exit") == 0)
	// 	return (builtin_exit(argv));
	else
		return (0);
}

int	check_n_option(char *opt)
{
	int	i;

	i = 1;
	if (!opt || opt[0] != '-')
		return (0);
	while (opt[i])
	{
		if (opt[i] != 'n')
			return (0);
		i++;
	}
	if (i == 1)
		return (0);
	return (1);
}

int	builtin_echo(char **argv)
{
	int	newline;
	int	is_first;
	int	i;

	newline = 1;
	is_first = 1;
	i = 1;
	while (argv[i] && check_n_option(argv[i]))
	{
		newline = 0;
		i++;
	}
	while (argv[i])
	{
		if (!is_first)
			ft_putstr_fd(" ", STDOUT_FILENO);
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		is_first = 0;
		i++;
	}
	if (newline)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc > 1)
		builtin_echo(argv);
	return (0);
}