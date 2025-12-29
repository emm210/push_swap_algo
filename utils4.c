#include "push_swap.h"
static int	count_tokens(int argc, char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**split;

	count = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j])
			j++;
		count += j;
		free_split(split);
		i++;
	}
	return (count);
}

static void	fill_tokens(int argc, char **argv, char **res)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 1;
	k = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			res[k++] = split[j];
			j++;
		}
		free(split);
		i++;
	}
	res[k] = NULL;
}

char	**get_numbers(int argc, char **argv)
{
	char	**res;
	int		count;

	count = count_tokens(argc, argv);
	if (count <= 0)
		error_exit();
	res = malloc(sizeof(char *) * (count + 1));
	if (!res)
		error_exit();
	fill_tokens(argc, argv, res);
	return (res);
}
