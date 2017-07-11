/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:03:11 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/11 15:06:35 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_base_tab(t_env *env)
{
	if ((env->sdl.tset[TINTER] = SDL_CreateTexture(env->sdl.rend, \
			SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIDTHS, \
			HEIGHT)) == NULL)
		ft_error_sdl();
	SDL_SetRenderTarget(env->sdl.rend, env->sdl.tset[TINTER]);
	env->sdl.tset[TIMG] = ft_img_to_tex(env, "img/attributes.bmp");
	SDL_RenderCopy(env->sdl.rend, env->sdl.tset[TIMG], NULL, NULL);
	SDL_DestroyTexture(env->sdl.tset[TIMG]);
	ft_base_text(env);
	SDL_SetRenderTarget(env->sdl.rend, NULL);
}

void	ft_base_text(t_env *env)
{
	int		i;
	int		max;
	char	*name;

	name = NULL;
	i = 0;
	max = (env->set.obj[3]->finished == 0) ? 11 : 17;
	while (i <= max)
	{
		name = (i == 1) ? ft_freestrjoin("Increment :  ", \
				ft_itoa(env->set.inc), 2) : name;
		name = (i == 2) ? ft_strdup("x2") : name;
		name = (i == 3) ? ft_strdup("/2") : name;
		name = (i == 4) ? ft_freestrjoin("Radius :  ", \
				ft_itoa(env->set.obj[3]->radius), 2) : name;
		name = (i == 5) ? ft_strdup("+") : name;
		name = (i == 6) ? ft_strdup("-") : name;
		name = (i == 7) ? ft_freestrjoin("Angle :  ", \
				ft_itoa(env->set.obj[3]->angle), 2) : name;
		name = (i == 8) ? ft_strdup("+") : name;
		name = (i == 9) ? ft_strdup("-") : name;
		if (i == 10)
		{
			name = (env->set.obj[3]->finished == 0) ? \
				ft_strdup("Object : Not Finished") : \
				ft_strdup("Object : Finished");
		}
		if (i == 11)
		{
			name == (env->set.obj[3]->finished == 0) ? ft_strdup("Finished") : \
				ft_strdup("Not Finished");
		}
		if (max == 17)
		{
			name = (i == 12) ? ft_freestrjoin("Min : ", \
				ft_itoa(env->obj[3]->fin[0], 2)) : name;
			name = (i == 13) ? ft_strdup("+") : name;	
			name = (i == 14) ? ft_strdup("-") : name;	
		}
	}
}
