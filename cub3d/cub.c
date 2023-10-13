#include "file.h"
void init_all(t_all **all)
{
    (*all)->x = 0;
    (*all)->y = 0;
    (*all)->x_of_map = 0;
    (*all)->y_of_map = 0;;
    (*all)->player_angel = 0;
    (*all)->map = NULL;
}
void count_x_y_of_the_map(t_all **all)
{
    while((*all)->map[(*all)->y_of_map])
    {
        (*all)->x_of_map = 0;
        while ((*all)->map[(*all)->y_of_map][(*all)->x_of_map])
            (*all)->x_of_map++;
        (*all)->y_of_map++;
    }
}
int updatemap(t_all *all)
{
    char **updated_map;
    int x; 
    int i;
    int len;

    len = 0;
    i = 0;  
    x = 0;
    len = ft_strlen(all->map[0]);
    while(all->map[i])
    {
        x = 0;
        while (all->map[i][x])
            x++;
        if(x > len)
            len = x;
        i++;
    }
    return(len);
}


void fix_map(t_all **all, int len)
{
    char **new_map;
    int i;
    int x;
    i = 0;
    x = 0; 
    
    new_map =  calloc(sizeof(char *) ,  (*all)->y_of_map + 1);
    while(i <  (*all)->y_of_map)
    {
        new_map[i] = calloc(sizeof(char) , len + 1);
        i++;
    }
    i = 0;
    while(i < (*all)->y_of_map)
    {
        strcpy(new_map[i], (*all)->map[i]);
        i++;
    }
    new_map[i] = NULL;
    (*all)->map = new_map;
}
int check_for_valid_map(char **map)
{
    int i;
    int x;
    i = 0;
    x = 0;
    if(ft_strchr(map[0], '0'))
    {
        printf("unvalid ;)\n");
        return -1;
    }
    while(map[i])
    {
        x = 0;
        while (map[i][x])
        {
            if(map[i][x] == '0')
            {
                if(map[i - 1][x] == '\0' || map[i + 1][x] == '\0' || map[i - 1][x] == ' ' || map[i + 1][x] == ' ')
                {
                    printf("unvalid ;)\n");
                    return(-1);
                }
                if(map[i][x - 1] == '\0' ||map[i][x + 1] == '\0' || map[i][x - 1] == ' ' ||map[i][x + 1] == ' ')
                {
                    printf("unvalid :)\n");
                    return(-1);
                }
            }
            x++;
        }
        i++;
    }
     if(ft_strchr(map[i - 1], '0'))
    {
        printf("unvalid ;)\n");
        return -1;
    }
    return(0);
}
int main(int argc, char *argv[])
{
    t_all *all;
    t_textr *txtr;
    int len;
   if (all_in_one(&all, &txtr, argv) == -1)
        return(0);
    len = updatemap(all);
    count_x_y_of_the_map(&all);
    fix_map(&all, len);
    if(check_for_valid_map(all->map) == -1)
        return(-1);
    return(0);
}

