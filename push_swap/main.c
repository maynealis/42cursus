/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:42:53 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/28 15:52:19 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	check_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == 0) // TODO: also check for real 0
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	
	return (0);
}
