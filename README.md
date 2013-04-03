slidetail
=========

Concurrently tails a fixed-width sliding-window of the last 'n' files created in a given directory.
Inotify is used to monitor the directory activity.

        :                       :                       :
    file03.log              file04.log              file05.log
    file04.log |1           file05.log |1           file06.log |1
    file05.log |2           file06.log |2           file07.log |2
    file06.log |3           file07.log |3           file08.log |3
    file07.log |---> ···    file08.log |---> ···    file09.log |---> ··· (stdout)
    file08.log |5           file09.log |5           file10.log |5
    file09.log |6           file10.log |6           file11.log |6
    file10.log |n           file11.log |n           file12.log |n

    ----------------------------- time ---------------------------------->
