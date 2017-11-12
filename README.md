# vbaud — Virtually limit the bit/baud rate of your terminal

[This file](vbaud.c) provides a slow-down as you would have had on a real
terminal connected over a serial link. This is useful for
displaying VT100 animated movies as they were meant to be
watched. You can think of it as a rate-limited version of `cat`.

```sh
% make vbaud     # or: cc -o vbaud vbaud.c
% gzip -dc animation.vt.gz | ./vbaud 9600
```
(There probably is no need to turn on compiler optimizations)

Enjoy!

## History

* 2017-11-12 This is `git`-repacked code I wrote for https://ftp.nice.ch/NiCE/vt100.anims/ in 2013
that turned out to be buggy.
