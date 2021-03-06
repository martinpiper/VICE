/*
 * mikroass.h - Cartridge handling, Mikro Assembler cart.
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

#ifndef _MIKROASS_H
#define _MIKROASS_H

#include <stdio.h>

#include "types.h"

extern BYTE REGPARM1 mikroass_io1_read(WORD addr);
extern BYTE REGPARM1 mikroass_io2_read(WORD addr);

extern void mikroass_config_init(void);
extern void mikroass_config_setup(BYTE *rawcart);
extern int mikroass_crt_attach(FILE *fd, BYTE *rawcart);
extern void mikroass_detach(void);

#endif
