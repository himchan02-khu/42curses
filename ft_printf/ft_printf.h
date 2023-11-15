/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:51:14 by hchoo             #+#    #+#             */
/*   Updated: 2023/11/16 02:30:25 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *arr, ...);
int	print_char(int val);
int	print_str(char *ptr);
int	print_address(void *ptr);
//int	print_percent(char c);
int	print_int(int val);
int	print_unsigned(int val);
int	print_16(unsigned int val, int sign);

#endif
