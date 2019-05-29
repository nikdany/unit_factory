/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:56:15 by exam              #+#    #+#             */
/*   Updated: 2019/05/14 17:24:22 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char    *ft_go(int len, int nbr, char *s, char *end)
{
    int        i;
    int        n;
    char    *str;
    
    i = 1;
    n = nbr;
    while ((n = n / 10) > 0)
        i++;
    n = ((nbr % 10) == 1 && i == 1) ? 1 : 0;
    str = malloc(i + len + (6 - n) + 1);
    while (n < 7)
    {
        str[len + i] = end[n];
        n++;
        len++;
    }
    n = i;
    while (i-- > 0)
    {
        str[i] = nbr % 10 + '0';
        nbr = nbr / 10;
    }
    while (s[++i])
        str[n++] = s[i];
    return (str);
}

char    *moment(unsigned int n)
{
    if (n >= 2592000)
        return (ft_go(6, (n / 2592000), " month", "s ago."));
    else if (n >= 86400)
        return (ft_go(4, (n / 86400), " day", "s ago."));
    else if (n >= 3600)
        return (ft_go(5, (n / 3600), " hour", "s ago."));
    else if (n >= 60)
        return (ft_go(7, (n / 60), " minute", "s ago."));
    else
        return (ft_go(7, n, " second", "s ago."));
}

int        main()
{
    printf("%s\n", moment(3600));
    printf("%s\n", moment(3600*11));
    printf("%s\n", moment(3600*21));
    printf("%s\n", moment(3600*24*30*111));
    return (0);
}
