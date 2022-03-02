/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/23 21:56:46 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "signal.h"

int g_dochka;

typedef	struct		s_par
{
	int				i;
	int				fd[2];
	int				stdin;
	int				stdout;
	char			**env;
	char			**str;
	char			**str_based;
	char			**str_next_zap;
	char			**str_na;
	char			**copy_str;
	char			**time_str;
	char			*file_name;
	int				rid_type;
	int				flag;
	unsigned char	code_of_error;
	unsigned char	code_of_error_2;
	unsigned char	dollar;
	int				mm_i;
	int				mm_i2;
	int				flag_psz;
	char			*tmp;
	char			**mtrx_paths;
	char			*str_path;
	char			*e_path;
	int				flag_zero;
	char			**del_str;
	pid_t			pid;
	int				pars_fl;
}					t_par;

char				**parsing(char *line, t_par *par);
int					check_symbol_echo(char c);
char				**sorting(char **str, int start, int size);
int					ft_command(t_par *par, int j, char *line);
void				ft_main_par(t_par *par, char *line);
void				write_special_dollar(t_par *par, char c, int j);
char				*define_str(t_par *par, int j, int *i);
void				in_quotes(int *j, int *i, char *line, t_par *par);
int					size_of_mas_par_str(char *line);
void				in_double_quotes(int *i, char *line, t_par *par, int *j);
void				no_in_quotes(int *j, int *i, char *line, t_par *par);
void				end_of_double_quotes(char *line, int *i, int *j,
					t_par *par);
void				skip_space(char *line, int *i, t_par *par, int *j);
int					check_prew_more(t_par *par, int j, char **environ);
char				*start_value_ex(int *k, int *i, t_par *par, int *j);
int					parcer_unset(t_par *par, int j, int *p);
void				cd_without_arg(char *home_str, t_par *par, int j);
int					check_dot(char *argt);
int					check_prew(t_par *par, int j);
void				change_var(char **environ, int *n, int *flag, char *str);
void				export_gen(char *arg, t_par *par);
int					check_more_variable(t_par *par, char **environ, int j);
char				**my_export(t_par *par);
char				**export_out(t_par *par, int w, int flag);
void				print_symbol(t_par *par, char c, int j, int *i);
void				change_line(t_par *par, char *str, int j);
int					ft_if_sort(char **str, int start, int end);
void				write_error_inf(char *str, t_par *par);
void				change_two(char **s1, char **s2);
char				*ft_find_name(char *str);
void				write_space(int j, int num);
char				**add_line(t_par *par, char *str);
void				left_base(int *flag);
int					check_valid(t_par *par, int *j, int *i);
int					check_end_word(char c);
int					check_dollar(char c, char d);
void				no_var_in_env(int flag, char **environ, int *n,
					char *str);
int					count_unset(t_par *par);
int					check_command(char c);
int					check_symbol(char c);
void				change_value(t_par *par, int j, int p, int i);
void				in_quotes_count(int *count, int *i, int *flag, char *line);
int					check_option(t_par *par, int *j, int *flag, int *i);
void				check_option_start(t_par *par, int *j, int *i, int *flag);
void				in_one_quotes_count(int *count, int *i, int *flag,
					char *line);
void				in_double_quotes_count(int *count, int *i, int *flag,
					char *line);
void				open_dollar(int *i, t_par *par, int *j);
void				open_dollar_ex(int *i, t_par *par, int *j, char **str2);
void				no_in_quotes_count(int *count, int *i, int *flag,
					char *line);
int					check_no_quotes(char c);
int					count_del_lines(t_par *par, int flag, int k);
void				new_line(t_par *par, int *j);
void				my_unset(t_par *par);
int					basic_count(char **str, int l);
char				*ft_strjoin_mod(char *s1, char c);
void				value_of_var(t_par *par);
int					check_option(t_par *par, int *j, int *flag, int *i);
void				na_echo(t_par *par);
int					find_str(char *str1, char *str2);
char				*new_line_of_environ(char *str);
void				free_mas(char **mas);

int					count_of_str(t_par *par);
int					parcer_of_export(t_par *par, int j);
char				**my_export(t_par *par);
void				na_show_env(t_par *par);
void				new_line_exp(t_par *par, int j, char *str2);
int					ft_strnstr_mod(char *haystack, char *needle, size_t len);

void				qt_comands(t_par *par);
void				my_cd(t_par *par);

char				*ft_strjoin_and_free(char *s1, char *s2);

void				preview();
void				qt_comands(t_par *par);
void				my_cd(t_par *par);
void				write_error_cd(char *argt, t_par *par);
char				*find_home(t_par *par);
void				change_oldpwd(t_par *par, int j);
int					ft_strnstr_mod(char *haystack, char *needle, size_t len);
void				ctrl_sl();
t_par				init_start(t_par par);
void				parser_simple_z_2(t_par *par);
void				parser_simple_z(char *line, t_par *par);
int					print_syntax(t_par *par);
int					check_in_sintax(t_par *par);
t_par				init_start(t_par par);
t_par				copy_env(char **env, t_par par);
void				pars_simp_22(t_par *par, int *status);
void				pars_simp_33(t_par *par, int *status);
void				parser_simple(t_par *par);
void				qt_close_fds(t_par	*par);
void				qt_open_close(t_par *par);
char				**next_point_riderect(char **str, t_par *par);
void				qt_riderect (t_par *par);
void				calc_mm_i(t_par *par);
char				**copy_mtrx_x(t_par *par);
char				**copy_mtrx(char **mass);
char				*find_path(t_par *par);
char				*find_pwd_path(t_par *par);
void				my_execve_2(t_par *par);
void				exec_pid(t_par *par);
void				my_execve(t_par	*par);
char				**next_point_pipe(char **str);
char				**next_point_zap(t_par *par);
void				my_exit(t_par *par);
void				my_pwd(t_par *par);
int					is_str_num(char *str);
int					is_point(char *str);
int					is_pipe(char *str);
int					is_riderects(char *str, t_par *par);
void				free_mas(char **mas);
void				show_time_str(char **mtrx);
void				ft_free_mtrx(char **trash);
int					get_next_line(char **line);
void				ctrl_c();
void				qt_open_close(t_par *par);
char				*ft_strjoin_mod_free(char *s1, char s2);
void				find_name_of_var(char *str, int *flag, int *i);
void				show_time_str(char **mtrx);

#endif
