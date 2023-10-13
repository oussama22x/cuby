#ifndef FILE_H
# define FILE_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include "get_line/get_next_line.h"
#include <mlx.h>
typedef struct s_textr
{
    char *NO;
    char *SO;
    char *WE;
    char *EA;
    char *color_f;
    char *color_c;
} t_textr;
typedef struct s_all
{
    char **map;
    void *mlx;
    void *win;
    int player_angel;
    int fd;
    int y;
    int x;
    int x_of_map;
    int y_of_map;
} t_all;
void get_map(t_all **all, int fd);
int check_errors(char **map);
void init_txters(t_textr **txtr, t_all *all);
int all_in_one(t_all **all, t_textr **txtr,  char **argv);
void init_all(t_all **all);
#endif