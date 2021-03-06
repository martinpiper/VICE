/*
 * vsidui.c - Implementation of the C64-specific part of the UI.
 *
 * Written by
 *  Dag Lem <resid@nimrod.no>
 * based on c64ui.c written by
 *  Ettore Perazzoli <ettore@comm2000.it>
 *  Andr� Fachat <fachat@physik.tu-chemnitz.de>
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

#define VSIDUI 1

#include <stdio.h>
#include <stdlib.h>

#include "attach.h"
#include "c64mem.h"
#include "c64ui.h"
#include "icon.h"
#include "lib.h"
#include "log.h"
#include "machine.h"
#include "psid.h"
#include "resources.h"
#include "uicommands.h"
#include "uimenu.h"
#include "uisettings.h"
#include "uisid.h"
#include "uisound.h"
#include "videoarch.h"
#include "vsync.h"
#include "vsidui.h"
#include "vsiduiunix.h"

extern struct ui_menu_entry_s sid_submenu[];

/* FIXME: sid menus need to be handled differently, but still need to 
   figure out the right way. */

#if 0
UI_MENU_DEFINE_RADIO(SidStereoAddressStart)

static ui_menu_entry_t set_sid_stereo_address_d4xx_submenu[] = {
    { "*$D420", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd420, NULL },
    { "*$D440", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd440, NULL },
    { "*$D460", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd460, NULL },
    { "*$D480", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd480, NULL },
    { "*$D4A0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd4a0, NULL },
    { "*$D4C0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd4c0, NULL },
    { "*$D4E0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd4e0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_stereo_address_d5xx_submenu[] = {
    { "*$D500", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd500, NULL },
    { "*$D520", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd520, NULL },
    { "*$D540", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd540, NULL },
    { "*$D560", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd560, NULL },
    { "*$D580", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd580, NULL },
    { "*$D5A0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd5a0, NULL },
    { "*$D5C0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd5c0, NULL },
    { "*$D5E0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd5e0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_stereo_address_d6xx_submenu[] = {
    { "*$D600", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd600, NULL },
    { "*$D620", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd620, NULL },
    { "*$D640", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd640, NULL },
    { "*$D660", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd660, NULL },
    { "*$D680", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd680, NULL },
    { "*$D6A0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd6a0, NULL },
    { "*$D6C0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd6c0, NULL },
    { "*$D6E0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd6e0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_stereo_address_d7xx_submenu[] = {
    { "*$D700", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd700, NULL },
    { "*$D720", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd720, NULL },
    { "*$D740", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd740, NULL },
    { "*$D760", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd760, NULL },
    { "*$D780", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd780, NULL },
    { "*$D7A0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd7a0, NULL },
    { "*$D7C0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd7c0, NULL },
    { "*$D7E0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xd7e0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_stereo_address_dexx_submenu[] = {
    { "*$DE00", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xde00, NULL },
    { "*$DE20", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xde20, NULL },
    { "*$DE40", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xde40, NULL },
    { "*$DE60", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xde60, NULL },
    { "*$DE80", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xde80, NULL },
    { "*$DEA0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xdea0, NULL },
    { "*$DEC0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xdec0, NULL },
    { "*$DEE0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xdee0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_stereo_address_dfxx_submenu[] = {
    { "*$DF00", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xdf00, NULL },
    { "*$DF20", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xdf20, NULL },
    { "*$DF40", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xdf40, NULL },
    { "*$DF60", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xdf60, NULL },
    { "*$DF80", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xdf80, NULL },
    { "*$DFA0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xdfa0, NULL },
    { "*$DFC0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xdfc0, NULL },
    { "*$DFE0", (ui_callback_t)radio_SidStereoAddressStart,
      (ui_callback_data_t)0xdfe0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_stereo_address_submenu[] = {
    { "$D4xx",
      NULL, NULL, set_sid_stereo_address_d4xx_submenu },
    { "$D5xx",
      NULL, NULL, set_sid_stereo_address_d5xx_submenu },
    { "$D6xx",
      NULL, NULL, set_sid_stereo_address_d6xx_submenu },
    { "$D7xx",
      NULL, NULL, set_sid_stereo_address_d7xx_submenu },
    { "$DExx",
      NULL, NULL, set_sid_stereo_address_dexx_submenu },
    { "$DFxx",
      NULL, NULL, set_sid_stereo_address_dfxx_submenu },
    { NULL }
};

UI_MENU_DEFINE_TOGGLE(SidStereo)
UI_MENU_DEFINE_TOGGLE(SidFilters)

ui_menu_entry_t sid_submenu[] = {
    { N_("SID engine"),
      NULL, NULL, sid_engine_submenu },
    { "--" },
    { N_("*Second SID"),
      (ui_callback_t)toggle_SidStereo, NULL, NULL },
    { N_("*Second SID base address"),
      NULL, NULL, set_sid_stereo_address_submenu },
    { "--" },
    { N_("*Emulate filters"),
      (ui_callback_t)toggle_SidFilters, NULL, NULL },
    { N_("Chip model"),
      NULL, NULL, sid_model_submenu },
#ifdef HAVE_RESID
    { "--" },
    { N_("reSID sampling method"),
      NULL, NULL, sid_resid_sampling_submenu },
    { N_("reSID resampling passband..."),
      (ui_callback_t)set_sid_resid_passband, NULL, NULL },
#endif
    { NULL },
};
#endif

static log_t vsid_log = LOG_ERR;
static void vsid_create_menus(void);

/* ------------------------------------------------------------------------- */

UI_MENU_DEFINE_RADIO(PSIDTune)

static ui_menu_entry_t ui_tune_menu[] = {
  { N_("Tunes"),
    NULL, NULL, NULL },
  { NULL }
};

static UI_CALLBACK(psid_load)
{
    char *filename;
    ui_button_t button;

    filename = ui_select_file(_("Load PSID file"), NULL, 0, 0, NULL,
                              "*.[psPS]*", &button, 0, NULL);

    vsync_suspend_speed_eval();

    switch (button) {
      case UI_BUTTON_OK:
        if (machine_autodetect_psid(filename) < 0) {
          log_error(vsid_log, _("`%s' is not a valid PSID file."), filename);
          return;
        }
        psid_init_driver();
        machine_play_psid(0);
        machine_trigger_reset(MACHINE_RESET_MODE_SOFT);
        vsid_create_menus();
        break;
      default:
        /* Do nothing special.  */
        break;
    }
    if (filename != NULL)
       lib_free(filename);
}

#if 0
static UI_CALLBACK(psid_tune)
{
    int tune = *((int *)UI_MENU_CB_PARAM);
    machine_play_psid(tune);
    vsync_suspend_speed_eval();
    machine_trigger_reset(MACHINE_RESET_MODE_SOFT);
}
#endif

static ui_menu_entry_t ui_load_commands_menu[] = {
  { N_("Load PSID file..."),
    (ui_callback_t)psid_load, NULL, NULL,
    KEYSYM_l, UI_HOTMOD_META },
  { NULL }
};


/* ------------------------------------------------------------------------- */

UI_MENU_DEFINE_RADIO(MachineVideoStandard)

static ui_menu_entry_t set_video_standard_submenu_vsid[] = {
    { N_("*PAL-G"), (ui_callback_t)radio_MachineVideoStandard,
      (ui_callback_data_t)MACHINE_SYNC_PAL, NULL },
    { N_("*NTSC-M"), (ui_callback_t)radio_MachineVideoStandard,
      (ui_callback_data_t)MACHINE_SYNC_NTSC, NULL },
    { N_("*Old NTSC-M"), (ui_callback_t)radio_MachineVideoStandard,
      (ui_callback_data_t)MACHINE_SYNC_NTSCOLD, NULL },
    { NULL }
};

/*
UI_MENU_DEFINE_RADIO(SoundBufferSize)

static ui_menu_entry_t set_sound_buffer_size_submenu_vsid[] = {
  { N_("*3.00 sec"), (ui_callback_t)radio_SoundBufferSize,
    (ui_callback_data_t)3000, NULL },
  { N_("*1.00 sec"), (ui_callback_t)radio_SoundBufferSize,
    (ui_callback_data_t)1000, NULL },
  { N_("*0.50 sec"), (ui_callback_t)radio_SoundBufferSize,
    (ui_callback_data_t)500, NULL },
  { N_("*0.10 sec"), (ui_callback_t)radio_SoundBufferSize,
    (ui_callback_data_t)100, NULL },
  { NULL }
};
*/
/*
UI_MENU_DEFINE_TOGGLE(Sound)
static ui_menu_entry_t sound_settings_submenu_vsid[] = {
  { N_("*Enable sound playback"),
    (ui_callback_t)toggle_Sound, NULL, NULL },
  { "--" },
  { N_("Sample rate"),
    NULL, NULL, set_sound_sample_rate_submenu },
  { N_("Buffer size"),
    NULL, NULL, set_sound_buffer_size_submenu_vsid },
  { N_("Oversample"),
    NULL, NULL, set_sound_oversample_submenu },
  { NULL },
};
*/
static ui_menu_entry_t ui_sound_settings_menu_vsid[] = {
  { N_("Sound settings"),
    NULL, NULL, sound_settings_submenu },
  { NULL }
};

UI_MENU_DEFINE_TOGGLE(PSIDKeepEnv)

static ui_menu_entry_t psid_menu[] = {
  { N_("*Override PSID settings"),
    (ui_callback_t)toggle_PSIDKeepEnv, NULL, NULL },
  { N_("SID settings"),
    NULL, NULL, sid_submenu },
  { N_("Video standard"),
    NULL, NULL, set_video_standard_submenu_vsid },
  { NULL }
};

static ui_menu_entry_t vsidui_left_menu[] = {
  { "",
    NULL, NULL, ui_load_commands_menu },
  { "",
    NULL, NULL, ui_tune_menu },
  { "--",
    NULL, NULL, ui_tool_commands_menu },
  { "--",
    NULL, NULL, ui_help_commands_menu },
  { "--",
    NULL, NULL, ui_run_commands_menu },
  { "--",
    NULL, NULL, ui_exit_commands_menu },
  { NULL }
};

static ui_menu_entry_t vsidui_right_menu[] = {
  { "",
    NULL, NULL, ui_sound_settings_menu_vsid },
  { "--",
    NULL, NULL, psid_menu },
  { NULL }
};

#ifdef USE_GNOMEUI
static ui_menu_entry_t vsidui_file_menu[] = {
  { "",
    NULL, NULL, ui_load_commands_menu },
  { "",
    NULL, NULL, ui_tune_menu },
  { "--",
    NULL, NULL, ui_tool_commands_menu },
  { "--",
    NULL, NULL, ui_help_commands_menu },
  { "--",
    NULL, NULL, ui_run_commands_menu },
  { "--",
    NULL, NULL, ui_exit_commands_menu },
  { NULL }
};

static ui_menu_entry_t vsidui_settings_menu[] = {
  { "",
    NULL, NULL, ui_sound_settings_menu_vsid },
  { "--",
    NULL, NULL, psid_menu },
  { NULL }
};

static ui_menu_entry_t vsidui_top_menu[] = {
  { N_("File"),
    NULL, NULL, vsidui_file_menu },
  { N_("Settings"),
    NULL, NULL, vsidui_settings_menu },
  { NULL }
};
#endif	/* USE_GNOMEUI */

/* ------------------------------------------------------------------------- */

extern int num_checkmark_menu_items;

static void vsid_create_menus(void)
{
    static ui_menu_entry_t tune_menu[256];
    static int tunes = 0;
    int default_tune;
    int i;
    char *buf;

    buf = lib_stralloc(_("*Default Tune"));

    /* Free previously allocated memory. */
    for (i = 0; i <= tunes; i++) {
        lib_free(tune_menu[i].string);
    }

    /* Get number of tunes in current PSID. */
    tunes = psid_tunes(&default_tune);

    /* Build tune menu. */
    for (i = 0; i <= tunes; i++) {
        tune_menu[i].string =
            (ui_callback_data_t)lib_stralloc(buf);
        tune_menu[i].callback =
            (ui_callback_t) radio_PSIDTune;
        tune_menu[i].callback_data =
            (ui_callback_data_t) i;
        tune_menu[i].sub_menu = NULL;
        tune_menu[i].hotkey_keysym = i < 10 ? KEYSYM_0 + i : 0;
        tune_menu[i].hotkey_modifier =
            (ui_hotkey_modifier_t) i < 10 ? UI_HOTMOD_META : 0;
        lib_free(buf);
        buf = lib_msprintf(_("*Tune %d"), i + 1);
    }

    lib_free(buf);

    tune_menu[i].string =
        (ui_callback_data_t) NULL;

    ui_tune_menu[0].sub_menu = tune_menu;

    num_checkmark_menu_items = 0;

    ui_set_left_menu(vsidui_left_menu);

    ui_set_right_menu(vsidui_right_menu);

#ifdef USE_GNOMEUI
    ui_set_topmenu(vsidui_top_menu);
#endif

    ui_update_menus();
}

int vsid_ui_init(void)
{
    int res;
    video_canvas_t canvas;

    res = ui_open_canvas_window(&canvas, _("VSID: The SID Emulator"), 300, 
				100, 0);
    if (res < 0)
        return -1;
    
    /* FIXME: There might be a separte vsid icon.  */
    ui_set_application_icon(c64_icon_data);

    vsid_create_menus();
#ifdef LATER
    ui_set_topmenu();
#endif

    return 0;
}

void vsid_ui_display_name(const char *name)
{
    log_message(LOG_DEFAULT, "Name: %s", name);
    ui_vsid_setpsid(name);
}

void vsid_ui_display_author(const char *author)
{
    log_message(LOG_DEFAULT, "Author: %s", author);
    ui_vsid_setauthor(author);
}

void vsid_ui_display_copyright(const char *copyright)
{
    log_message(LOG_DEFAULT, "Copyright: %s", copyright);
    ui_vsid_setcopyright(copyright);
}

void vsid_ui_display_sync(int sync)
{
    char buf[50];
    sprintf(buf, "Using %s sync",
	    sync == MACHINE_SYNC_PAL ? "PAL" : "NTSC");
    log_message(LOG_DEFAULT, buf);
    ui_vsid_setsync(buf);
}

void vsid_ui_display_sid_model(int model)
{
    log_message(LOG_DEFAULT, "Using %s emulation",
		model == 0 ? "MOS6581" : "MOS8580");
    ui_vsid_setmodel(model == 0 ? "MOS6581" : "MOS8580");
}

void vsid_ui_set_default_tune(int nr)
{
    log_message(LOG_DEFAULT, "Default tune: %i", nr);
}

void vsid_ui_display_tune_nr(int nr)
{
    log_message(LOG_DEFAULT, "Playing tune: %i", nr);
    ui_vsid_settune(nr);
}

void vsid_ui_display_nr_of_tunes(int count)
{
    log_message(LOG_DEFAULT, "Number of tunes: %i", count);
}

void vsid_ui_display_time(unsigned int sec)
{
}

void vsid_ui_display_irqtype(const char *irq)
{
    log_message(LOG_DEFAULT, "Using %s interrupt", irq);
    ui_vsid_setirq(irq);
}

void vsid_ui_close(void)
{
}
