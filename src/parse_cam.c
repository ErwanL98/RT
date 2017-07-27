/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:30:02 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/27 10:59:59 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_fill_cam(t_env *env)
{
	int		i;
	char	**sp;

	sp = env->parse.split;
	i = -1;
	if (ft_strequ(sp[0], "position") == 1 && env->parse.type == CAM)
		ft_pos_cam(env, i);
	else if (ft_strequ(sp[0], "angles") == 1 && env->parse.type == CAM)
	{
		env->check.direction = 1;
		while (sp[++i])
		{
			if (ft_strequ(sp[i], "x") == 1 && (i + 2) <= env->parse.tablen)
				env->cam.angles.x = ft_atoi(sp[i + 2]);
			if (ft_strequ(sp[i], "y") == 1 && (i + 2) <= env->parse.tablen)
				env->cam.angles.y = ft_atoi(sp[i + 2]);
			if (ft_strequ(sp[i], "z") == 1 && (i + 2) <= env->parse.tablen)
				env->cam.angles.z = ft_atoi(sp[i + 2]);
		}
	}
}

void	ft_pos_cam(t_env *env, int i)
{
	env->check.position = 1;
	while (env->parse.split[++i])
	{
		if (ft_strequ(env->parse.split[i], "x") == 1 && (i + 2) \
				<= env->parse.tablen)
			env->cam.pos.x = \
						(double)(ft_atoi(env->parse.split[i + 2]));
		if (ft_strequ(env->parse.split[i], "y") == 1 && (i + 2) \
				<= env->parse.tablen)
			env->cam.pos.y = \
						(double)(ft_atoi(env->parse.split[i + 2]));
		if (ft_strequ(env->parse.split[i], "z") == 1 && (i + 2) \
				<= env->parse.tablen)
			env->cam.pos.z = \
						(double)(ft_atoi(env->parse.split[i + 2]));
	}
}
