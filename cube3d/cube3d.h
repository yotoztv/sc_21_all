/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:30:31 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 20:30:34 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <math.h>
# include "mlx_dylib/mlx.h"
# include <fcntl.h>

typedef struct	s_par
{
	char		**map;
	char		*line;
	char		*longline;
	int			fd;
	int			plx;
	int			ply;
	float		dplx;
	float		dply;
	char		plsun;
	int			pl_pov;
	int			plazimt;
	int			rez_grz;
	int			rez_vrt;
	int			rez_grz_max;
	int			rez_vrt_max;
	float		view;
	int			ih;
	float		angle;
	float		delta;
	float		st_angle;
	float		crossx;
	float		crossy;
	float		cross_x0;
	float		cross_y0;
	int			wall_nswe;
	float		hw_wall;
	float		a_wall;
	float		z_wall;
	float		st;
	float		st_cos;
	float		st_sin;
	float		pl_step;
	float		pl_step_l;
	float		len;
	int			erka;
	float		alpha;
	float		beta;
	float		omega;
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_back;
	int			len_img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*way_tx1;
	void		*img_tx1;
	char		*ardr_tx1;
	int			img_w_tx1;
	int			img_h_tx1;
	int			bits_per_p_tx_1;
	int			line_len_tx_1;
	int			endian_tx1;
	char		*rel_path_tx1;
	char		*way_tx2;
	void		*img_tx2;
	char		*ardr_tx2;
	int			img_w_tx2;
	int			img_h_tx2;
	int			bits_per_p_tx_2;
	int			line_len_tx_2;
	int			endian_tx2;
	char		*rel_path_tx2;
	char		*way_tx3;
	void		*img_tx3;
	char		*ardr_tx3;
	int			img_w_tx3;
	int			img_h_tx3;
	int			bits_per_p_tx_3;
	int			line_len_tx_3;
	int			endian_tx3;
	char		*rel_path_tx3;
	char		*way_tx4;
	void		*img_tx4;
	char		*ardr_tx4;
	int			img_w_tx4;
	int			img_h_tx4;
	int			bits_per_p_tx_4;
	int			line_len_tx_4;
	int			endian_tx4;
	char		*rel_path_tx4;
	char		*way_txb;
	void		*img_txb;
	char		*ardr_txb;
	int			img_w_txb;
	int			img_h_txb;
	int			bits_per_p_tx_b;
	int			line_len_tx_b;
	int			endian_txb;
	char		*rel_path_txb;
	char		*way_txf;
	void		*img_txf;
	char		*ardr_txf;
	int			img_w_txf;
	int			img_h_txf;
	int			bits_per_p_tx_f;
	int			line_len_tx_f;
	int			endian_txf;
	char		*rel_path_txf;
	int			xp;
	int			yp;
	int			color;
	int			color_cell;
	int			color_floor;
	int			h_x_color;
	int			h_y_color;
	int			high_wall;
	int			next_ray_y;
	int			tx_pix_sz;
	float		len_sp1[100];
	float		w_sp1[100];
	float		h_sp1[100];
	float		cross_x_sp1[100];
	float		cross_y_sp1[100];
	int			detect_x_sp1[100];
	int			current_sp_x;
	int			current_sp_y;
	int			sp_type[10];
	int			s_id;
	float		feta[100];
	int			x_s_x;
	int			h_s_y;
	int			xmap_start;
	int			ymap_start;
	int			ymap_last;
	int			i;
	char		str_rezult[100];
	int			color_rezult;
	int			j8;
	int			i8;
	int			k8;
	int			kik8;
	int			r_c;
	int			g_c;
	int			b_c;
	int			save_bmp;
	int			color_888;
	int			y55;
	int			a_25;
	int			z_25;
	int			h55;

}				t_par;

void			get_num_col_c_sp(t_par *par, int x_s_x, int h_s_y);
void			find_possition_h_s_y(t_par *par);
int				find_possition_h_s_x(t_par *par);
void			draw_next_sp(t_par *par);
void			draw_sprite(t_par *par);
void			find_feta(t_par *par);
void			check_repeat(t_par *par);
void			save_sp(t_par *par);
char			*ft_strnew(size_t size);
int				*ft_strnew_int(size_t size);
int				cross_sqrt(float x, float y, float x_new, float y_new);
float			coord_rotate_x(float x, float y, float feta);
float			coord_rotate_y(float x, float y, float feta);
int				find_cross_sqrt(t_par *par);
int				screen_to_bmp(t_par *par);
int				exit_simple(t_par *par);
void			paint_back(t_par par);
void			paint_round_black(t_par par);
void			key_act_2(t_par *par, int keycode);
int				key_act(int keycode, t_par *par);
t_par			draw_raws(t_par par);
t_par			draw_3d(t_par par);
int				check_top_wall(t_par par);
t_par			closed_map_2(t_par par);
int				check_string_space(t_par par);
t_par			closed_map(t_par par);
t_par			check_valid_map(t_par par);
void			exit_program_zero(t_par par, char *mess);
t_par			find_start_map(t_par par);
t_par			init_i8_j8_k8_kik8(t_par par);
t_par			find_rezolution_2(t_par par);
t_par			find_rezolution(t_par par);
int				rgbtoint(t_par par);
t_par			find_floor_color_3(t_par par, int color);
t_par			find_floor_color_2(t_par par);
t_par			find_floor_color(t_par par, char c);
t_par			find_textures_3(t_par par);
t_par			find_textures_2(t_par par);
t_par			find_textures(t_par par, char *str);
int				check_second_sp(t_par par, char c);
t_par			texture_list(t_par par);
t_par			check_trash(t_par par);
int				check_1_0_2_7(char c);
int				check_round(t_par par);
void			my_mlx_pixel_put(t_par *par, int x, int y, int color);
t_par			load_tx_2(t_par par);
t_par			load_tx_1(t_par par);
t_par			corect_rez(t_par par);
t_par			to_go(t_par par);
size_t			ft_strlen_ch(const char *str);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strjoin_fr(char const *s1, char const *s2);
int				root_n(char *root);
char			*save_line(char *root);
char			*save_root(char *root);
int				get_next_line(int fd, char **line);
void			get_num_col(t_par *par);
void			find_possition_h_y(t_par *par);
void			find_possition_h_x(t_par *par);
void			find_color(t_par *par);
void			draw_next_ray(t_par *par);
t_par			pl_step_left(t_par par);
t_par			pl_step_forw(t_par par);
void			n_0_s_1_w_2_e_3_b_4(t_par *par);
void			cross_wall_2(t_par *par);
void			cross_wall(t_par *par);
void			find_cross(t_par *par);
t_par			parser_plsun(t_par par);
t_par			init_pl(t_par par);
t_par			parser_pl(t_par par);
t_par			parser_map(t_par par);
void			exit_program_img(void);

#endif
