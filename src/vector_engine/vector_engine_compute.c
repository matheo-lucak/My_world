/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Vector engine for vector computation.
*/

#include <math.h>
#include <SFML/System/Vector2.h>
#include "my.h"

sfVector2f vec_add(sfVector2f vec1, sfVector2f vec2)
{
    sfVector2f res;

    res.x = vec1.x + vec2.x;
    res.y = vec1.y + vec2.y;
    return (res);
}

sfVector2f vec_sub(sfVector2f vec1, sfVector2f vec2)
{
    sfVector2f res;

    res.x = vec1.x - vec2.x;
    res.y = vec1.y - vec2.y;
    return (res);
}

sfVector2f vec_mult(sfVector2f vec1, float coeff)
{
    sfVector2f res;

    res.x = vec1.x * coeff;
    res.y = vec1.y * coeff;
    return (res);
}

sfVector2f vec_div(sfVector2f vec1, float coeff)
{
    sfVector2f res;

    if (coeff == 0)
        return ((sfVector2f){0, 0});
    res.x = vec1.x / coeff;
    res.y = vec1.y / coeff;
    return (res);
}