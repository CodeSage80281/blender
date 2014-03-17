/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version. 
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2008 Blender Foundation.
 * All rights reserved.
 *
 * 
 * Contributor(s): Blender Foundation
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file blender/editors/space_file/file_intern.h
 *  \ingroup spfile
 */

#ifndef __FILE_INTERN_H__
#define __FILE_INTERN_H__

#include "BLI_sys_types.h" /* for bool */

/* internal exports only */

struct ARegion;
struct ARegionType;
struct bContext;
struct SpaceFile;
struct ScrArea;

/* file_ops.c */
struct ARegion *file_buttons_region(struct ScrArea *sa);

/* file_draw.c */
#define TILE_BORDER_X (UI_UNIT_X / 4)
#define TILE_BORDER_Y (UI_UNIT_Y / 4)

/* ui geometry */
#define IMASEL_BUTTONS_HEIGHT (UI_UNIT_Y * 2)
#define IMASEL_BUTTONS_MARGIN (UI_UNIT_Y / 6)

void file_draw_buttons(const struct bContext *C, struct ARegion *ar);
void file_calc_previews(const struct bContext *C, struct ARegion *ar);
void file_draw_list(const struct bContext *C, struct ARegion *ar);

void file_draw_check_cb(struct bContext *C, void *arg1, void *arg2);
bool file_draw_check_exists(struct SpaceFile *sfile);

/* file_ops.h */
struct wmOperatorType;
struct wmOperator;
struct wmEvent;
void FILE_OT_highlight(struct wmOperatorType *ot);
void FILE_OT_select(struct wmOperatorType *ot);
void FILE_OT_select_all_toggle(struct wmOperatorType *ot);
void FILE_OT_select_border(struct wmOperatorType *ot);
void FILE_OT_select_bookmark(struct wmOperatorType *ot);
void FILE_OT_bookmark_add(struct wmOperatorType *ot);
void FILE_OT_bookmark_delete(struct wmOperatorType *ot);
void FILE_OT_reset_recent(struct wmOperatorType *ot);
void FILE_OT_hidedot(struct wmOperatorType *ot);
void FILE_OT_execute(struct wmOperatorType *ot);
void FILE_OT_cancel(struct wmOperatorType *ot);
void FILE_OT_parent(struct wmOperatorType *ot);
void FILE_OT_directory_new(struct wmOperatorType *ot);
void FILE_OT_previous(struct wmOperatorType *ot);
void FILE_OT_next(struct wmOperatorType *ot);
void FILE_OT_refresh(struct wmOperatorType *ot);
void FILE_OT_bookmark_toggle(struct wmOperatorType *ot);
void FILE_OT_filenum(struct wmOperatorType *ot);
void FILE_OT_delete(struct wmOperatorType *ot);
void FILE_OT_rename(struct wmOperatorType *ot);
void FILE_OT_smoothscroll(struct wmOperatorType *ot);

int file_exec(struct bContext *C, struct wmOperator *exec_op);
int file_cancel_exec(struct bContext *C, struct wmOperator *unused);
int file_parent_exec(struct bContext *C, struct wmOperator *unused);
int file_previous_exec(struct bContext *C, struct wmOperator *unused);
int file_next_exec(struct bContext *C, struct wmOperator *unused);
int file_directory_new_exec(struct bContext *C, struct wmOperator *unused);
int file_delete_exec(struct bContext *C, struct wmOperator *unused);

void file_directory_enter_handle(struct bContext *C, void *arg_unused, void *arg_but);
void file_filename_enter_handle(struct bContext *C, void *arg_unused, void *arg_but);

int file_highlight_set(struct SpaceFile *sfile, struct ARegion *ar, int mx, int my);

void file_sfile_to_operator(struct wmOperator *op, struct SpaceFile *sfile, char *filepath);
void file_operator_to_sfile(struct SpaceFile *sfile, struct wmOperator *op);


/* filesel.c */
float file_shorten_string(char *string, float w, int front);
float file_string_width(const char *str);

float file_font_pointsize(void);
void file_change_dir(struct bContext *C, int checkdir);
int file_select_match(struct SpaceFile *sfile, const char *pattern, char *matched_file);
int autocomplete_directory(struct bContext *C, char *str, void *arg_v);
int autocomplete_file(struct bContext *C, char *str, void *arg_v);

/* file_panels.c */
void file_panels_register(struct ARegionType *art);

#endif /* __FILE_INTERN_H__ */

