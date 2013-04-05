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
// Entry point: ./ftail 5 /tmp/randlog
//-----------------------------------------------------------------------------

int main(int argc, char *argv[])

{
    int i, n, fd, wd, len;
    char path[256];
    char buf[EVENT_BUF_LEN];
    struct inotify_event *event;

    n = atoi(argv[1]);
    strcpy(path, argv[2]);

    printf("Window width: %d\n", n);
    printf("Directori to watch: %s\n", path);

    if ((fd = inotify_init()) < 0) MyDBG(end0);
    if ((wd = inotify_add_watch(fd, path, IN_CREATE)) < 0) MyDBG(end1);

    while(1) {

        i=0; if ((len = read(fd, buf, EVENT_BUF_LEN)) < 0) MyDBG(end2);

        while (i < len) {
            event = (struct inotify_event *) &buf[i];
            i += EVENT_SIZE + event->len;
            if (!(event->mask & IN_ISDIR)) printf("New file: %s\n", event->name);
        }
    }

    // Return on success:
    inotify_rm_watch(fd, wd);
    close(fd);
    return 0;

    // Return on error:
    end2: inotify_rm_watch(fd, wd);
    end1: close(fd);
    end0: return -1;
}
