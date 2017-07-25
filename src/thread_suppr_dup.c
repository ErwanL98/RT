/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_suppr_dup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:59:50 by gauffret          #+#    #+#             */
/*   Updated: 2017/07/24 14:59:51 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	suppr_dup_obj(t_obj *src)
{
	t_obj	*link;
	t_obj	*del;

	link = src;
	while (link)
	{
		del = link;
		link = link->next;
		//link->prev = NULL;
		del->next = NULL;
		if (del)
		{
			free(del);
			del = NULL;
		}
	}
}

void	suppr_dup_light(t_light *src)
{
	t_light	*link;
	t_light	*del;

	link = src;
	while (link)
	{
		del = link;
		link = link->next;
		del->next = NULL;
		free(del);
		del = NULL;
	}
}

void	suppr_dup_tmp(t_tmp src)
{
	suppr_dup_obj(src.current);
}

void	suppr_dup_set(t_set src)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (src.obj[i])
			suppr_dup_obj(src.obj[i]);
	}
}

void	thread_suppr_dup(t_env *env)
{
	//suppr_dup_set(env->set);
	//suppr_dup_tmp(env->tmp);
	suppr_dup_obj(env->obj);
	suppr_dup_light(env->light);
	//dest->sdl.format = src->sdl.format ?
	//dest->sdl.pixels = src->sdl.pixels ?
	if (env)
	{
		free(env);
		env = NULL;
	}
}
