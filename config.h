/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define MASTER_LEFT

#define TAPPING_TERM 150

#define AUTO_SHIFT_TIMEOUT 200
// #define NO_AUTO_SHIFT_SPECIAL

#define OLED_TIMEOUT 300000

#define MOON_LINE 1   // the line you want the moon to appear at
#define MOON_COLUMN 1 // the column you want the moon to appear at
#define ANIMATE_MOON_EVERY_N_FRAMES 25 // animate the moon every n frames

// Override OLED font with our custom one.
#if defined(OLED_FONT_H)
#    undef OLED_FONT_H
#    define OLED_FONT_H "keymaps/farefray/glcdfont.c"
#endif
