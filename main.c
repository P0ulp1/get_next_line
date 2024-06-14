/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:23:55 by phautena          #+#    #+#             */
/*   Updated: 2024/06/13 15:56:36 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_atoi(const char *nptr);

/*int	main(void)
{
	int	fd;
	
	fd = open("readme.txt", O_RDONLY);
	printf("[+] Line: %s", get_next_line(fd));
	printf("[+] Line: %s", get_next_line(fd));
	printf("[+] Line: %s", get_next_line(fd));
	return (0);
}*/

int	main(int argc, char *argv[])
{
	int	i;
	int	fd;
	char *line;

	line = NULL;

	if (argc != 3)
		printf("[-] Usage: ./a.out <file.txt> <n_line>");
	else
	{
		fd = open(argv[1], O_RDONLY);
		i = ft_atoi(argv[2]);
		while (i-- > 0)
			{
				line = get_next_line(fd);
				printf("[+] Line: %s", line);
				free(line);
			}
		close(fd);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	neg;

	i = 0;
	result = 0;
	neg = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * neg);
}
