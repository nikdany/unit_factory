/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <exam@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 10:18:10 by exam              #+#    #+#             */
/*   Updated: 2019/06/04 10:48:14 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_brackets(char *str, int n)
{
	char	tmp[n];

	n = 0;
	while (*str)
	{
		if (*str == '(' || *str == '[' || *str == '{')
			tmp[n++] = *str;
		if ((*str == ')' || *str == ']' || *str == '}'))
		{
			n--;
			if (!((*str == ')' && tmp[n] == '(')
				|| (*str == ']' && tmp[n] == '[')
				|| (*str == '}' && tmp[n] == '{')))
				return (0);
		}
		str++;
	}
	return (n > 0 ? 0 : 1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		len;

	i = 1;
	len = 0;
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
