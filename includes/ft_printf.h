/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nheo <nheo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:09:01 by nheo              #+#    #+#             */
/*   Updated: 2022/03/09 13:09:04 by nheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

char	*ft_based_num(int n, int base);
char	*ft_based_num_pointer(long n, int base);
char	*ft_itoa_unsigned(int n);
int		fp_addr(int type, long value);
int		fp_value(int type, long value);
int		ft_printf(const char *format, ...);

#endif
