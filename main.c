/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: armolina <armolina@student.42madrid.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/06/04 04:44:52 by armolina          #+#    #+#             */
/*   Updated: 2024/06/04 04:44:52 by armolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Uso: %s nombre_del_archivo\n", argv[0]);
		return (EXIT_FAILURE);
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (EXIT_FAILURE);
	}

	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	return (EXIT_SUCCESS);
}
