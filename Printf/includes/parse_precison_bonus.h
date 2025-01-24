/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precison_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:27:26 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/23 16:21:14 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_PRECISION_BONUS_H
# define PARSE_PRECISION_BONUS_H

# include "libft.h"
# include "flags_manager.h"

char	*parse_precision_num(char *num, t_flags flags);
char	*parse_precision_str(char *str, t_flags flags);

#endif
