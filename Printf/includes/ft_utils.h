/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:08:10 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/16 14:24:27 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_uitoa_base(unsigned int n, char *base);
char	*ft_ultoa_base(unsigned long n, char *base);
int		write_char(char c);
int		write_str(char *str);
int		write_int(int n);
int		write_uint(unsigned int n);
int		write_hexa(unsigned long n, char x);
