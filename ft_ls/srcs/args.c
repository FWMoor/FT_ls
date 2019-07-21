/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:08:19 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/21 15:11:14 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			sort_args(char **args)
{
	int			i;
	char		*temp;

	i = 0;
	while ((args[i] != NULL) && (args[i + 1] != NULL))
	{
		if (ft_strcmp(args[i], args[i + 1]) < 0 ||
				ft_strcmp(args[i], args[i + 1]) == 0)
			i++;
		else
		{
			temp = args[i];
			args[i] = args[i + 1];
			args[i + 1] = temp;
		}
	}
}

int				check_arg(int ac, int flags, char **args)
{
	int			i;
	int			check;

	i = 0;
	check = 0;
	while (args[i] != NULL)
	{
		if (ac > 2)
		{
			if (args[i][0] != '/')
				ft_putstr("./");
			ft_printf("%s:\n", args[i]);
		}
		ft_ls(args[i++], flags);
		if (i + 1 < ac)
			ft_putchar('\n');
		check = 1;
	}
	return (check);
}

int				add_args(char **args, int ac, char **av)
{
	int			i;
	int			j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if ((av[i][0] == '-') && (ft_strlen(av[i]) > 1) && (av[i][1] != '-'))
			i++;
		else if (av[i][0] == '-' && av[i][1] == '-')
		{
			i++;
			break ;
		}
		else
			break ;
	}
	while (i < ac)
		args[j++] = av[i++];
	args[j] = NULL;
	sort_args(args);
	return (j);
}

char		acl_print(char *path)
{
	int		xattrs;
	acl_t	acl;

	xattrs = (int)listxattr(path, NULL, 1, XATTR_NOFOLLOW);
	if (xattrs > 0)
		return ('@');
	else
	{
		acl = acl_get_file(path, ACL_TYPE_EXTENDED);
		if (acl != NULL)
			return ('+');
		else
			return (' ');
	}
}
