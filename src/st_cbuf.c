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
// Includes:
//-----------------------------------------------------------------------------

#include "st_cbuf.h"

//-----------------------------------------------------------------------------
// st_cbuf_new:
//-----------------------------------------------------------------------------

void st_cbuf_new(PCBUF cb, int size)

{
    cb->size  = size;
    cb->start = 0;
    cb->count = 0;
    cb->elems = (PELEM)calloc(cb->size, sizeof(ELEM));
}

//-----------------------------------------------------------------------------
// st_cbuf_write:
//-----------------------------------------------------------------------------

void st_cbuf_write(PCBUF cb, PELEM elem)

{
    int end = (cb->start + cb->count) % cb->size;

    if(cb->count == cb->size) {
        cb->start = (cb->start + 1) % cb->size;
        pthread_cancel(cb->elems[end].thread);
    }
    else ++ cb->count;
    cb->elems[end] = *elem;
}
