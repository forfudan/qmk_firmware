/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* Tap-hold tuning for the LT() keys on Esc and Space. */
#define TAPPING_TERM 135

/* Resolve a tap-hold key as a hold as soon as another key is pressed. */
#define HOLD_ON_OTHER_KEY_PRESS

/* Replaces the removed TAPPING_FORCE_HOLD: never auto-repeat the tap
 * keycode when a tap-hold key is held again right after a tap. */
#define QUICK_TAP_TERM 0
