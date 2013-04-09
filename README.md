#SlideTail 0.0.1 (devel)

Concurrently tails a fixed-width sliding-window of the last 'n' files created in a given directory.
Inotify is used to monitor the directory and file activity.
It creates one fork per watched directory and one thread per watched file within that directory.
It also supports resume of a previously stopped tailing session.
Output might be redirected to stdout or syslog.
Can run as a commandline tool or in the background as a daemon.

##Usage examples
**stdout**

    ./stail \
    -w 5:/var/log/app1/:stdout \
    -w 3:/var/log/app2/:stdout \
    -w 2:/var/log/app3/:stdout

**syslog**

    ./stail \
    -w 3:/var/log/app1/:syslog1.demo.lan:514 \
    -w 3:/var/log/app2/:syslog1.demo.lan:515 \
    -w 3:/var/log/app3/:syslog2.demo.lan:514

##Design
**Diagram**

        :                       :                       :
    file03.log              file04.log              file05.log
    file04.log |1           file05.log |1           file06.log |1
    file05.log |2           file06.log |2           file07.log |2
    file06.log |3           file07.log |3           file08.log |3
    file07.log |---> ···    file08.log |---> ···    file09.log |---> ··· (stdout/syslog)
    file08.log |5           file09.log |5           file10.log |5
    file09.log |6           file10.log |6           file11.log |6
    file10.log |n           file11.log |n           file12.log |n

    ----------------------------- time ---------------------------------->
