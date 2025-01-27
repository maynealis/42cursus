#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char	**free_arr(char **arr)
{
	int	i;
	int	a = 0b011101;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

int	count_words(char *str, char separator)
{
	int		n_words;
	size_t i;

	n_words = 0;
	if (str[0] != separator)
		n_words++;
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] != separator && str[i - 1] == separator)
			n_words++;
		i++;
	}
	return (n_words);
}

char	*create_word(char *str, char separator, size_t *ini, char **arr)
{
	size_t	start;
	char	*word;
	size_t	i;

	start = *ini;
	while (str[*ini] != separator && str[*ini] != '\0')
		(*ini)++;
	word = (char *)malloc((*ini - start + 1) * sizeof(char));
	if (word == NULL)
	{
		free_arr(arr);
		return (NULL);
	}
	i = 0;
	while (i + start < *ini)
	{
		word[i] = str[i + start];
		i++;
	}
	word[i] = '\0';
	
	return (word);
}

char	**ft_split(char *str, char separator)
{
	int		total_words;
	int		c_word;
	char	**arr;
	size_t	i;

	total_words = count_words(str, separator);
	arr = (char **)malloc((total_words + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr[total_words] = NULL;
	i = 0;
	c_word = -1;
	while (str[i] != '\0')
	{
		if ((i == 0 && str[i] != separator) || (str[i] != separator && str[i - 1] == separator))
			arr[++c_word] = create_word(str, separator, &i, arr);
		else
			i++;
	}
	return (arr);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);

	int	n_words = count_words(argv[1], ' ');
	printf("number of words: %d\n", n_words);
	
	char	**arr = ft_split(argv[1], ' ');
	int i = 0;
	while (i < n_words)
	{
		printf("word %i: %s\n", i, arr[i]);
		i++;
	}

	return(0);
}

