#include <stdlib.h>
#include <stdio.h>

int		ft_wlen(char *s)
{
	int		l;

	l = 0;
	while (s[l] != '\0' && (s[l] != ' ' || s[l] != '\n' || s[l] != '\t'))
		l++;
	return (l);
}


int		ft_wnbr(char *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j++;
		if (s[j])
		{
			while (s[j] != ' ' && s[j] != '\n' && s[j] != '\t' && s[j] != '\0')
				j++;
			i++;
		}
	}
	return (i);
}

char		**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 0;
	k = 0;
	if (!(split = malloc(sizeof(char *) * (ft_wnbr(str) + 1))))
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		j = 0;
		if (!(split[k] = malloc(sizeof(char) * ft_wlen(str + i))))
			return (NULL);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
			split[k][j++] = str[i++];
		while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
			i++;
		split[k][j] = '\0';
		printf("%d %s\n", k, split[k]);
		k++;
	}
	split[k] = NULL;
	printf("%d %s\n", k, split[k]);
	return (split);
}

int		main(int argc, char **argv)
{
	char	**test;
	int		i = -1;

	if (argc == 2)
	{
		printf("***start of split***\n");
		test = ft_split(argv[1]);
		printf("==== result ====\n");
		while (test[++i] != NULL)
			printf("%d %s\n", i, test[i]);
		// while (test[i] == NULL)
		// 	printf("%d %s\n", i, test[i++]);
		return (printf("***end of split***\n"));
	}

	return (printf("wrone number of arguments\n"));
}
