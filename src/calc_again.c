/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_again.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawasche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 11:29:45 by mawasche          #+#    #+#             */
/*   Updated: 2017/08/17 14:49:12 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_place(t_env *env)
{
	env->light->solution_point.x = env->cam.pos.x + env->cam.pixel.x *\
								   env->tmp.solution;
	env->light->solution_point.y = env->cam.pos.y + env->cam.pixel.y *\
								   env->tmp.solution;
	env->light->solution_point.z = env->cam.pos.z + env->cam.pixel.z *\
								   env->tmp.solution;
}

void	ft_light_vect(t_env *env, int mode)
{
	env->light->light_vect.x = env->light->pos.x - env->light->solution_point.x;
	env->light->light_vect.y = env->light->pos.y - env->light->solution_point.y;
	env->light->light_vect.z = env->light->pos.z - env->light->solution_point.z;
	if (mode == 0)
		env->light->light_vect = ft_normalize(env->light->light_vect);
}

t_vect	ft_inv_vect(t_vect vect)
{
	t_vect	new;

	new.x = -vect.x;
	new.y = -vect.y;
	new.z = -vect.z;
	return (new);
}
