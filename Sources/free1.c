/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:10:50 by ayassir           #+#    #+#             */
/*   Updated: 2023/01/14 15:31:45 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	exit_with_error(char *str)
{
	free(str);
	ft_putendl_fd("Error : Invalid map", 2);
	exit (1);
}

void	free_and_close(t_store *var)
{
	free (var->line);
	close (var->fd);
}
