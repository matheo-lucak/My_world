/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_game_object_param
*/

#include "my.h"
#include "game_object.h"

sfBool set_texture(game_obj_t *obj, char *buffer)
{
    char **parsed_buffer = NULL;

    parsed_buffer = my_str_to_word_array(buffer, " :;", 1);
    if (!parsed_buffer || !obj)
        return (sfFalse);
    if (my_arrlen((void **)parsed_buffer) != 2) {
        my_free_arr(parsed_buffer);
        return (sfFalse);
    }
    obj->texture = sfTexture_createFromFile(parsed_buffer[1], NULL);
    my_free_arr(parsed_buffer);
    if (!(obj->texture))
        return (sfFalse);
    return (sfTrue);
}

sfBool set_frame_nb(game_obj_t *obj, char *buffer)
{
    char **parsed_buffer = NULL;

    parsed_buffer = my_str_to_word_array(buffer, " :;", 1);
    if (!parsed_buffer || !obj ||
        my_strncmp(parsed_buffer[0], "frame_nb", 8))
        return (sfFalse);
    if (my_arrlen((void **)parsed_buffer) != 2) {
        my_free_arr(parsed_buffer);
        return (sfFalse);
    }
    obj->frame_nb = my_getnbr(parsed_buffer[1]);
    my_free_arr(parsed_buffer);
    if (!(obj->frame_nb))
        return (sfFalse);
    return (sfTrue);
}

sfBool set_view_box(game_obj_t *obj)
{
    sfVector2u size = (sfVector2u){0, 0};

    if (!obj || !obj->texture || !(obj->frame_nb))
        return (sfFalse);
    size = sfTexture_getSize(obj->texture);
    obj->view_box.left = 0;
    obj->view_box.top = 0;
    obj->view_box.width = size.x / obj->frame_nb;
    obj->view_box.height = size.y;
    return (sfTrue);
}

sfBool set_sprite(game_obj_t *obj)
{
    if (!obj || !(obj->texture))
        return (sfFalse);
    obj->sprite = sfSprite_create();
    if (!(obj->sprite))
        return (sfFalse);
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setTextureRect(obj->sprite, obj->view_box);
    return (sfTrue);
}