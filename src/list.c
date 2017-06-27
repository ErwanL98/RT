/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:08:14 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/27 14:18:29 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_obj	*ft_fill_obj(t_env *env)
{
	t_obj		*obj;

	obj = NULL;
	if ((obj = (t_obj *)malloc(sizeof(t_obj))) == NULL)
		ft_error();
	obj->type = env->parse.type_obj;
	obj->radius = env->tmp.radius;
	obj->angle = env->tmp.angle;
	obj->pos.x = env->tmp.pos.x;
	obj->pos.y = env->tmp.pos.y;
	obj->pos.z = env->tmp.pos.z;
	obj->angles.x = env->tmp.angles.x;
	obj->angles.y = env->tmp.angles.y;
	obj->angles.z = env->tmp.angles.z;
	obj->angles.h = env->tmp.angles.h;
	obj->color.red = env->tmp.color.red;
	obj->color.green = env->tmp.color.green;
	obj->color.blue = env->tmp.color.blue;
	obj->tex = env->tmp.tex;
	obj->tile.red = env->tmp.tile.red;
	obj->tile.green = env->tmp.tile.green;
	obj->tile.blue = env->tmp.tile.blue;
	obj->tile.w = env->tmp.tile.w;
	obj->ref = env->tmp.ref;
	obj->next = NULL;
	obj->prev = env->tmp_obj;
	return (obj);
}

t_light	*ft_fill_light(t_env *env)
{
	t_light	*light;

	light = NULL;
	if ((light = (t_light *)malloc(sizeof(t_light))) == NULL)
		ft_error();
	light->type = env->parse.type_light;
	light->pos.x = env->tmp.pos.x;
	light->pos.y = env->tmp.pos.y;
	light->pos.z = env->tmp.pos.z;
	light->dir.x = env->tmp.angles.x;
	light->dir.y = env->tmp.angles.y;
	light->dir.z = env->tmp.angles.z;
	light->color.red = env->tmp.color.red;
	light->color.green = env->tmp.color.green;
	light->color.blue = env->tmp.color.blue;
	light->next = NULL;
	light->prev = env->tmp_light;
	return (light);
}

void	ft_add_elem_obj(t_env *env)
{
	t_obj	*tmp;
	t_obj	*obj;

	tmp = env->set.obj[3];
	while (tmp->next)
		tmp = tmp->next;
	if ((obj = (t_obj *)malloc(sizeof(t_obj))) == NULL)
		ft_error();
	tmp->next = obj;
	obj->type = env->set.obj[3]->type;;
	obj->radius = env->set.obj[3]->radius;
	obj->angle = env->set.obj[3]->angle;
	obj->pos.x = env->set.obj[3]->pos.x;
	obj->pos.y = env->set.obj[3]->pos.y;
	obj->pos.z = env->set.obj[3]->pos.z;
	obj->angles.x = env->set.obj[3]->angles.x;
	obj->angles.y = env->set.obj[3]->angles.y;
	obj->angles.z = env->set.obj[3]->angles.z;
	obj->angles.h = env->set.obj[3]->angles.h;
	obj->color.red = env->set.obj[3]->color.red;
	obj->color.green = env->set.obj[3]->color.green;
	obj->color.blue = env->set.obj[3]->color.blue;
	obj->tex = env->set.obj[3]->tex;
	obj->tile.red = env->set.obj[3]->tile.red;
	obj->tile.green = env->set.obj[3]->tile.green;
	obj->tile.blue =env->set.obj[3]->tile.blue;
	obj->tile.w = env->set.obj[3]->tile.w;
	obj->ref = env->set.obj[3]->ref;
	obj->next = NULL;
	obj->prev = tmp;
}

// DELETE TEST NOT WORKING
void	ft_delete_elem_obj(t_env *env)
{
	t_obj	*start;
	t_obj	*tmp;
	int		i;

	tmp = NULL;
	start = env->obj;
	if (env->set.obj[3]->next == NULL)
	{
		tmp = env->set.obj[3]->prev;
		tmp->next = NULL;
		free(env->set.obj[3]);
	}
	else if (env->set.id_o == 1)
	{
		env->obj = env->obj->next;
		tmp = env->obj->prev;
		free(tmp);
	}
	else
	{
		i = 1;
		while (start)
		{
			if (i == env->set.id_o)
			{
				tmp = env->set.obj[3]->next;
				start = tmp;
				free(env->set.obj[3]);
			}
			i++;
			start = start->next;
		}
	}
}
