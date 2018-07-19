# SSA to SRT converter

Sketch in progress.

```shell
$ gcc run.c ssa-to-srt.c -o run; ./run foo.ssa

#...

451
00:40:05.44 --> 0:40:07.11
{\an2}-See you tomorrow.
-Bye.

452
00:40:07.19 --> 0:40:09.32
{\an2}-See you tomorrow. Good night!
-Good night.

$ ./test.sh

..

1 tests, 2 assertions, 0 failures

Finished in 0.00003375 seconds (real) 0.00003340 seconds (proc)
```
