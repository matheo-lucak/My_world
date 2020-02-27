/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** window_update
*/
#include "my_world.h"
#include "input_handling.h"
#include "map_update.h"

void window_update(win_settings_t *win_settings,
                map_formatter_t *terraformer, fps_assets_t *resources_fps)
{
    //win_settings.size = sfRenderWindow_getSize(win_settings.window);
        update_mouse_tool(win_settings);
        control_camera_view(*win_settings, terraformer->map_settings,
                            resources_fps);
        if (control_angle_view(&(terraformer->map_settings)) ||
            win_settings->mouse_tool.hold) {
            update_map_2d(terraformer);
            update_tile_map_2d(terraformer);
        }
        draw_tile_map_2d(*win_settings, terraformer);
}