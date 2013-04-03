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

#include "st_main.h"

//-----------------------------------------------------------------------------
// Globals:
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// Entry point:
//-----------------------------------------------------------------------------

int main(int argc, char *argv[])

{
    // Initializations:
    int i, f=0;

    // Parse command line options:
    struct option longopts[] = {
    { "files", required_argument,  NULL,  'f' },
    { 0, 0, 0, 0 }};

    while((i = getopt_long(argc, argv, "f", longopts, NULL)) != -1)

    {
        if (i == -1) break;

        switch(i)

        {
            case 'f': f = atoi(optarg);
                      break;
            default:  abort();
        }
    }

    return 0;
}
