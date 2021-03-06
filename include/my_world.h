/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** my_world.h
*/

#ifndef MY_WORLD_H_

#define MY_WORLD_H_

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#include "game_object.h"

//An enum of each possible material a square can be.

#define full_opacity (sfColor){255, 255, 255, 255}
#define darker (sfColor){100, 100, 100, 255}

typedef enum tile_matter_e {
    GRASS,
    STONE,
    GRAVEL,
    SAND,
    SNOW,
    WATER
} tile_matter_t;



//Settings that are helpful for the map rendering and angles of sight.
//
//Can be altered by the player.

typedef struct presets_s {
    sfVector2i size;
    sfVector2i angles;
    sfVector2i rotation_speed;
    sfVector2i movement_speed;
} presets_t;



//A tile of the map

typedef struct tile_s {
    sfVertexArray *shape_drawer;
    sfShader *shader;
    sfRenderStates rstate;
    tile_matter_t matter_state;
} tile_t;



//linked list.

typedef struct map_linked_list_s {
    tile_t *tile;
    struct map_linked_list_s *next;
    struct map_linked_list_s *prev;
} map_linked_list_t;


typedef enum sides_e {
    TOP,
    LEFT,
    RIGHT,
    BOTTOM
} sides_t;

//The alterer of coordinates of the points in the map.
typedef struct map_formatter_s {
    presets_t map_settings;
    float **map_3d;
    sfVector2f **map_2d;
    tile_t **tile_map_2d;
    sfShader **shaders;
    sfTexture **textures;
    sfVertexArray *borders[8];
    sides_t view_side;
} map_formatter_t;


typedef struct mouse_tool_s {
    sfVector2f pos;
    sfVector2f click_pos;
    sfBool hold;
    sfBool click;
} mouse_tool_t;



typedef struct anchor_s {
    sfVector2f topleft;
    sfVector2f topright;
    sfVector2f bottomleft;
    sfVector2f bottomright;
} anchor_t;



typedef enum edit_mode_flag_e {
    VIEW_MODE = 1,
    TEXTURE_MODE = 2,
    PIXEL_MODE = 4
} edit_mode_flag_t;


typedef enum pixel_mode_flag_e {
    PIXEL_DRAW = 1,
    SPATULA_DRAW = 2,
} pixe_mode_flag_t;


typedef enum view_mode_e {
    VIEW_TEXTURE = 1,
    VIEW_LINE = 2,
    VIEW_PIN = 4,
    VIEW_ALL = 7
} view_mode_t;



typedef struct game_mode_s {
    unsigned edit_mode : 3;
    unsigned edit_repeat : 1;
    unsigned view_mode : 3;
    unsigned draw_mode : 2;
    tile_matter_t matter;
} game_mode_t;



//The window tool box.
typedef struct win_settings_s {
    sfRenderWindow *window;
    sfView *view;
    anchor_t anchor;
    sfVector2f size;
    sfVector2f scale;
    sfVideoMode video_mode;
    sfEvent event;
    game_mode_t mode;
    mouse_tool_t mouse_tool;
    sfMusic *main_track;
    sfBool paused;
    sfBool muted;
} win_settings_t;


typedef struct fps_assets_s {
    sfText *fps_drawer;
    sfClock *clock;
    sfFont *fps_font;
    size_t fps_counter;
} fps_assets_t;



typedef struct hud_s {
    fps_assets_t fps_assets;
    game_obj_t *slider;
    game_obj_t *save_button;
    game_obj_t *text_box;
    game_obj_t *sound_button;
    game_obj_t *florian;
} hud_t;

sfBool init_hud(hud_t *hud);


void window_actions(void);

sfBool my_world(win_settings_t *sets);

void usage(void);

void draw_fps(win_settings_t sets, fps_assets_t *fps_assets);

void update_view_side(map_formatter_t *ter);

void update_border(float **map, const sfVector2i size, const sfVector2i angles,
                    sfVertexArray *borders[7]);

void fill_vertex(const sfVector2f point, sfVertexArray *shape_drawer,
                    const sfVector2f tex_anchor);


/*
**                             ****************
**                             | Initializers |
**                             ****************
*/

sfShader **init_shaders(sfTexture **textures);
sfTexture **init_textures(void);
sfVector2f **init_map_2d(const sfVector2i map_size);
tile_t **init_tile_map_2d(const sfVector2i map_size, sfTexture **textures,
                            sfShader **shaders);
sfBool init_win_settings(win_settings_t *sets);
sfBool init_terraformer(map_formatter_t *ter, size_t seed);
sfBool init_game_structures(map_formatter_t *ter, hud_t *hud);
sfBool init_hud(hud_t *hud);
sfBool init_resources_fps(fps_assets_t *fps_assets);

//Save all the map data into a new_file
//Overwrite the file if it already exists
//Returns True in case of success
//Returns False in case of error
sfBool save_map(map_formatter_t ter, char *file_name);

//Returns a float ** representing 3D map
//Returns NULL in case of error
sfBool open_map(map_formatter_t *ter, char *file_name);


/*
**                                  ******************
**                                  | Main game loop |
**                                  ******************
*/

void game_view_update(win_settings_t *sets, map_formatter_t *ter, hud_t *hud);

void draw_hud(win_settings_t *sets, map_formatter_t *ter, hud_t *hud);

void draw_florian_the_toucan(win_settings_t *sets, game_obj_t *florian);

sfBool florian_the_toucan_wants_to_speak(win_settings_t *sets,
                                            game_obj_t *florian, int do_close);

void draw_edit_button(win_settings_t *sets, game_obj_t *slider,
                                            const float x_offset);

void draw_sound_button(win_settings_t *sets, game_obj_t *sound_button);

void draw_text_box(win_settings_t *sets, map_formatter_t *ter,
                    game_obj_t *save_button, game_obj_t *text_box);

void draw_save_button(win_settings_t *sets, game_obj_t *save_button);

void draw_texture_bar(win_settings_t *sets, map_formatter_t ter,
                                game_obj_t *slider, float x_offset);

void draw_view_button(win_settings_t *sets, game_obj_t *slider,
                        const float x_offset);

void draw_slider_button(win_settings_t *sets, map_formatter_t ter,
                        game_obj_t *slider, const float x_offset);

void draw_slider(win_settings_t *sets, map_formatter_t ter,
                    game_obj_t *slider);

//Updates window settings such as
//
// Size
// Anchor
// Mouse settings

void draw_game_object(win_settings_t sets, game_obj_t *obj);

void update_window_settings(win_settings_t *sets);
sfBool game_state_checker(sfRenderWindow *window, sfEvent *event,
                            sfBool *goback_menu);
void draw_tile_map_2d(win_settings_t *sets, map_formatter_t *ter);
void draw_circle(win_settings_t *sets, map_formatter_t *ter,
                    const sfVector2i pos);
void magnet_number(float *nb, const float offset,
                    const int acc, const float magnet);


/*
**                                 ******************
**                                 | Edit mode tool |
**                                 ******************
*/

//Updates mode with new flag such as
//  VIEW_MODE
//  TEXTURE_MOD
//  PIXEL_MOD
void change_edit_mode(game_mode_t *mode, edit_mode_flag_t flag);

//Checks flags such as
//  VIEW_MODE
//  TEXTURE_MOD
//  PIXEL_MOD
sfBool is_edit_mode(game_mode_t mode, edit_mode_flag_t flag);
void set_view_mode(game_mode_t *mode, view_mode_t flag);
void unset_view_mode(game_mode_t *mode, view_mode_t flag);
sfBool is_view_mode(game_mode_t mode, view_mode_t flag);


/*
**                                    ************
**                                    | Free'ers |
**                                    ************
*/

void free_array(void **array, const int size);
void free_textures_array(sfTexture **textures);
void free_shaders_array(sfShader **shaders);
void free_win_settings(win_settings_t sets);
void free_terraformer(map_formatter_t *ter);
void free_map_list(map_linked_list_t **head);
void free_tile_map_2d(tile_t **tile_map_2d, sfVector2i size);
void free_game_structures(map_formatter_t *ter,  hud_t *hud);
void free_resources_fps(fps_assets_t *fps_assets);

int get_randomnb(int min, int max);

void rotate_up(presets_t *map_settings, sfBool *changed);
void rotate_down(presets_t *map_settings, sfBool *changed);
void rotate_left(presets_t *map_settings, sfBool *changed);
void rotate_right(presets_t *map_settings, sfBool *changed);

sfVector2f transl_up(const sfVector2i mv_speed, const sfVector2f coeff);
sfVector2f transl_down(const sfVector2i mv_speed, const sfVector2f coeff);
sfVector2f transl_left(const sfVector2i mv_speed, const sfVector2f coeff);
sfVector2f transl_right(const sfVector2i mv_speed, const sfVector2f coeff);

#endif /* MY_WORLD_H_ */