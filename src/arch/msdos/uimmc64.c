/*
 * uimc64.c - MMC64 UI interface for MS-DOS.
 *
 * Written by
 *  Marco van den Heuvel <blackystardust68@yahoo.com>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */

#include "vice.h"

#include <stdio.h>

#include "resources.h"
#include "tui.h"
#include "tuimenu.h"
#include "uimmc64.h"


TUI_MENU_DEFINE_TOGGLE(MMC64)
TUI_MENU_DEFINE_RADIO(MMC64_revision)
TUI_MENU_DEFINE_TOGGLE(MMC64_flashjumper)
TUI_MENU_DEFINE_TOGGLE(MMC64_bios_write)
TUI_MENU_DEFINE_TOGGLE(MMC64_RO)

static TUI_MENU_CALLBACK(mmc64_bios_name_callback)
{
    char s[256];
    const char *v;

    if (been_activated) {

        *s = '\0';

        if (tui_input_string("Change MMC64 BIOS image name",
                             "New image name:", s, 255) == -1)
            return NULL;

        if (*s == '\0')
            return NULL;

        resources_set_string("MMC64BIOSfilename", s);
    }

    resources_get_string("MMC64BIOSfilename", &v);
    return v;
}

static TUI_MENU_CALLBACK(mmc64_image_name_callback)
{
    char s[256];
    const char *v;

    if (been_activated) {

        *s = '\0';

        if (tui_input_string("Change MMC64 MMC/SD image name",
                             "New image name:", s, 255) == -1)
            return NULL;

        if (*s == '\0')
            return NULL;

        resources_set_string("MMC64imagefilename", s);
    }

    resources_get_string("MMC64imagefilename", &v);
    return v;
}

static TUI_MENU_CALLBACK(mmc64_revision_submenu_callback)
{
    int value;
    static char s[100];

    resources_get_int("MMC64_revision", &value);
    sprintf(s, "%s",(value) ? "Rev B" : "Rev A");
    return s;
}

static tui_menu_item_def_t mmc64_revision_submenu[] = {
    { "Rev _A", NULL, radio_MMC64_revision_callback,
      (void *)0, 7, TUI_MENU_BEH_CLOSE, NULL, NULL },
    { "Rev _B", NULL, radio_MMC64_revision_callback,
      (void *)1, 7, TUI_MENU_BEH_CLOSE, NULL, NULL },
    { NULL }
};

static tui_menu_item_def_t mmc64_menu_items[] = {
    { "_Enable MMC64:", "Emulate MMC64",
      toggle_MMC64_callback, NULL, 3,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "_MMC64 Revision:", "Select the MMC64 Revision",
      mmc64_revision_submenu_callback, NULL, 7,
      TUI_MENU_BEH_CONTINUE, mmc64_revision_submenu,
      "MMC64 Revision" },
    { "Enable MMC64 _flashjumper:", "Enable MMC64 flashjumper",
      toggle_MMC64_flashjumper_callback, NULL, 3,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Save MMC64 _BIOS when changed:", "Enable MMC64 BIOS save when changed",
      toggle_MMC64_bios_write_callback, NULL, 3,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "MMC64 B_IOS file:", "Select the MMC64 BIOS file",
      mmc64_bios_name_callback, NULL, 20,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "MMC64 image _read-only:", "Enable MMC64 MMC/SD image read-only",
      toggle_MMC64_RO_callback, NULL, 3,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "MMC64 i_mage file:", "Select the MMC64 MMC/SD image file",
      mmc64_image_name_callback, NULL, 20,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { NULL }
};

void uimmc64_init(struct tui_menu *parent_submenu)
{
    tui_menu_t ui_mmc64_submenu;

    ui_mmc64_submenu = tui_menu_create("MMC64 settings", 1);

    tui_menu_add(ui_mmc64_submenu, mmc64_menu_items);

    tui_menu_add_submenu(parent_submenu, "_MMC64 settings...",
                         "MMC64 settings",
                         ui_mmc64_submenu, NULL, 0,
                         TUI_MENU_BEH_CONTINUE);
}
