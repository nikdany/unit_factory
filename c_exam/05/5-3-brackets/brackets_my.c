/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:50:01 by mdanylch          #+#    #+#             */
/*   Updated: 2019/06/03 13:50:09 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_brackets(char *s, int len)
{
	char	tmp[len];

	len = 0;
	while (*s)
	{
		if (*s == '(' || *s == '{' || *s == '[')
			tmp[len++] = *s;
		if (*s == ')' || *s == '}' || *s == ']')
		{
			len--;
			if (!((tmp[len] == '[' && *s == ']') 
				|| (tmp[len] == '{' && *s == '}')
				|| (tmp[len] == '(' && *s == ')')))
							return (0);
		}
		s++;
	}
	return (1);
}

int				main(int argc, char **argv)
{
	int		len;
	int		i;

	len = 0;
	i = 1;
	if (argc == 1)
		return (write(1, "\n", 1));
	while (i < argc)
	{
		while (argv[i][len])
			len++;
		if (ft_brackets(argv[i++], len + 1))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
	}
	return (0);
}


// int				main()
// {
// 	if (check_brackets("{[(0 + 0) + 1 - 2()(1 + 1)](3*(-1)){()}})"))
// 		write(1, "OK\n", 3);
// 	else
// 		write(1, "Error\n", 6);
// 	return (0);
// }
