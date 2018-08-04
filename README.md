# SSA to SRT converter

A simple SSA to good old fashioned SRT converter.

## Motivation

1. Watching movies on the PS4 requires subtitles in simple SRT files
2. I ~~suck at~~ want to learn some basic C programming

## Install & usage

```shell
$ ./install.sh
ssa-to-srt is installed to ~/.local/bin

$ ssa-to-srt foo.ssa

#...
628
00:36:02,160 --> 0:36:03,370
Of course! Any time.

629
00:36:03,450 --> 0:36:04,950
-Thank you.
-Any time.
```

## Running the test

```shell
$ ./test.sh

...

2 tests, 3 assertions, 0 failures

Finished in 0.00003124 seconds (real) 0.00003088 seconds (proc)
```
