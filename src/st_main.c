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

CBUF cbuf;
char path[128];

//-----------------------------------------------------------------------------
// W_Tail:
//-----------------------------------------------------------------------------

void *W_Tail(void *arg)

{
    // Variables:
    int ifd;//, wd;
    //int id = (int)(intptr_t)arg;

    printf("%s", path);
    // Setup the notify watch:
    if((ifd = inotify_init()) < 0) MyDBG(end0);
    //if((wd = inotify_add_watch(ifd, cbuf.elems[id].name, IN_CREATE)) < 0) MyDBG(end1);

    // Do something:
    //pthread_t tid = pthread_self();
    //while(1){printf("[%li]:%d %s\n", (unsigned long int)tid, id, cbuf.elems[id].name); sleep(5);}

    // Return on error:
    //end1: close(ifd);
    end0: pthread_exit(NULL);
}

//-----------------------------------------------------------------------------
// Entry point:
//-----------------------------------------------------------------------------

int main(int argc, char *argv[])

{
    // Variables:
    int i,j,k,fd,wd,len;
    char buf[EVENT_BUF_LEN];
    struct inotify_event *event;
    ELEM elem;

    // Arguments:
    j = atoi(argv[1]);
    strcpy(path, argv[2]);

    // Setup the notify watch:
    if((fd = inotify_init()) < 0) MyDBG(end0);
    if((wd = inotify_add_watch(fd, path, IN_CREATE)) < 0) MyDBG(end1);

    // Initialize the circular buffer:
    st_cbuf_new(&cbuf, j);

    // Main loop:
    while(1) {

        // Blocking read:
        i=0; if((len = read(fd, buf, EVENT_BUF_LEN)) < 0) MyDBG(end2);

        // Incoming:
        while(i<len) {

            // Get one event:
            event = (struct inotify_event *) &buf[i];
            i += EVENT_SIZE + event->len;
            if(event->mask & IN_ISDIR) continue;

            // New file: create a thread and add it to the queue:
            k = (cbuf.start + cbuf.count) % cbuf.size;
            if(pthread_create(&elem.thread, NULL, W_Tail, (void *)(intptr_t) k) != 0) MyDBG(end2);
            strcpy(elem.name, event->name); st_cbuf_write(&cbuf, k, &elem);
        }

        // Print the current window of files:
        for(k=0; k<j; k++) { printf("Slot [%d]: %s\n", k, cbuf.elems[k].name); } printf("\n");
    }

    // Return on error:
    end2: inotify_rm_watch(fd, wd);
    end1: close(fd);
    end0: return -1;
}
