# SSA to SRT converter

Sketch in progress...

```shell
$ gcc run.c ssa-to-srt.c -o run; ./run foo.ssa

#...
628
00:36:02,160 --> 0:36:03,370
Of course! Any time.

629
00:36:03,450 --> 0:36:04,950
-Thank you.
-Any time.

$ ./test.sh

...

2 tests, 3 assertions, 0 failures

Finished in 0.00003124 seconds (real) 0.00003088 seconds (proc)
```

## Motivation

1. Watching movies on the PS4 requires subtitles in `.srt` format
2. I suck at C
