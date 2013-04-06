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

#ifndef _ST_CBUF_
#define _ST_CBUF_

//-----------------------------------------------------------------------------
// Includes:
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <pthread.h>

//-----------------------------------------------------------------------------
// Typedefs:
//-----------------------------------------------------------------------------

typedef struct {

    char      name[128];
    pthread_t thread;

} ELEM, *PELEM;

typedef struct {

    int   size;
    int   start;
    int   count;
    PELEM elems;

} CBUF, *PCBUF;

//-----------------------------------------------------------------------------
// Prototypes:
//-----------------------------------------------------------------------------

void st_cbuf_new(PCBUF cb, int size);
void st_cbuf_write(PCBUF cb, PELEM elem);

//-----------------------------------------------------------------------------
// End of include guard:
//-----------------------------------------------------------------------------

#endif
