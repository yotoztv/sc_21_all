/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:50:46 by dlucio            #+#    #+#             */
/*   Updated: 2020/08/01 22:17:18 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_check
{
	int zero;
	int minus;
	int width;
	int point;
	int precision;
	int count;
	int dopminus;
}				t_check;

int				ft_strlen(char *str);
char			*ft_strdup(const char *s1);
char			*ft_itoa_m(int n);
char			*ft_itoa_p(int n);
char			*ft_itoa(int n);
int				ft_isdigit(int c);
int				ft_isascii(int c);
t_check			init_check(t_check check);
int				is_spec(char c);
t_check			parser_flag(t_check check, char *str, va_list argv);
char			back_char(int hex, int x);
char			*ft_itoa_hex(unsigned int n, int x);
int				conv_hex(t_check check, va_list argv);
int				conv_hex_xm(t_check check, va_list argv);
char			*ft_itoa_point(size_t n, int x);
int				conv_point(t_check check, va_list argv);
char			*ft_itoa_unsign(unsigned int n);
int				conv_unsign(t_check check, va_list argv);
int				conv_procent(t_check check);
int				conv_digital(t_check check, va_list argv);
int				conv_str(t_check check, va_list argv);
int				conv_char(t_check check, va_list argv);
void			print_width(int size, char c);
void			ft_putstr_fd(char *str, int fd);
int				edit_print(char *str, t_check check);
int				convers_spec(char spec, va_list argv, t_check check);
int				ft_printf(const char *str, ...);
int				edit_print_p(char *str, t_check check);
int				edit_print_str(char *str, t_check check);
char			*ft_strnew(size_t size);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strjoin(char const *s1, char *s2);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strchr(const char *s, int c);
char			*find_min(char *str, t_check check);
int				edit_print_di(char *str, t_check check);
void			ft_convertion(t_check *check);
int				edit_print_char(int chint, t_check check);
int				flag_of_digital(int num, t_check *check);
#endif
