/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:54:51 by okamotoyayo       #+#    #+#             */
/*   Updated: 2025/10/03 14:02:20 by okamotoyayo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (*s1 && *s2 && (*s1 == *s2))
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
	else if (ft_strcmp(argv[0], "cd") == 0)
		return (builtin_cd(argv));
	else if (ft_strcmp(argv[0], "pwd") == 0)
		return (builtin_pwd());
	else if (ft_strcmp(argv[0], "export") == 0)
		return (builtin_export(argv));
	else if (ft_strcmp(argv[0], "unset") == 0)
		return (builtin_unset(argv));
	else if (ft_strcmp(argv[0], "env") == 0)
		return (builtin_env());
	else if (ft_strcmp(argv[0], "exit") == 0)
		return (builtin_exit(argv));
	else
		return (0);
}

int	check_n_option(char *opt)
{
	int i;
	i = 1;
	if (!opt)
		return (0);
	
}

int	builtin_echo(char **argv)
{
	while (*argv && )
}
