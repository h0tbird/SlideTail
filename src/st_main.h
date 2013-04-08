/******************************************************************************
* Copyright (C) 2013 Marc Villacorta Morera
*
* Authors: Marc Villacorta Morera <marc.villacorta@gmail.com>
*
* This file is part of SlideTail.
*
* SlideTail is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* SlideTail is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with SlideTail. If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

//-----------------------------------------------------------------------------
// Include guard:
//-----------------------------------------------------------------------------

#ifndef _ST_
#define _ST_

//-----------------------------------------------------------------------------
// Includes:
//-----------------------------------------------------------------------------

#define _GNU_SOURCE
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <errno.h>
#include <pthread.h>
#include "st_cbuf.h"

//-----------------------------------------------------------------------------
// Defines:
//-----------------------------------------------------------------------------

#define MyDBG(x) do {printf("(%d) %s:%d\n", errno, __FILE__, __LINE__); goto x;} while (0)
#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define EVENT_BUF_LEN ( 1024 * ( EVENT_SIZE + 16 ) )
#define INOTAIL_WATCH_MASK (IN_MODIFY|IN_DELETE_SELF|IN_MOVE_SELF|IN_UNMOUNT|IN_CREATE)

//-----------------------------------------------------------------------------
// Typedefs:
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// End of include guard:
//-----------------------------------------------------------------------------

#endif
