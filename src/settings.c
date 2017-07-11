/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 12:54:04 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/26 14:51:33 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_settings(t_env *env)
{
	if (env->set.tab == INTERFACE)
		ft_interface(env);
	else if (env->set.tab == OBJECTS)
		ft_s_objects(env);
	else if (env->set.tab == ATTRIBUTES)
		ft_attributes(env);
	else if (env->set.tab == POSTAB)
		ft_pos_tab(env);
	else if (env->set.tab == DIRTAB)
		ft_dir_tab(env);
	else if (env->set.tab == COLTAB)
		ft_col_tab(env);
}
