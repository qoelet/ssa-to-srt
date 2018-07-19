#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ssa-to-srt.h"

#define IN 1
#define OUT 0

// Lifted from: https://stackoverflow.com/questions/29788983/split-char-string-with-multi-character-delimiter-in-c
char *multi_tok(char *input, char *delimiter) {
    static char *string;
    if (input != NULL)
        string = input;

    if (string == NULL)
        return string;

    char *end = strstr(string, delimiter);
    if (end == NULL) {
        char *temp = string;
        string = NULL;
        return temp;
    }

    char *temp = string;

    *end = '\0';
    string = end + strlen(delimiter);
    return temp;
}

int main( int argc, char* argv[] ) {
  char const* const fileName = argv[1];
  FILE* file = fopen(fileName, "r");
  char line[256];

  int count;
  int state;
  char* token;
  char* src;
  char* tmp;
  char *sel[2];
  char **sub;

  state = OUT;
  count = 1;

  while( fgets(line, sizeof(line), file) ) {
    if( lineStartsWith(line, "[Events]") ) {
      state = IN;
      continue;
    }

    if( state == IN ) {
      if( lineStartsWith(line, "Dialogue") ) {
        src = strdup(line);
        tmp = src;

        // TODO: Parse format information
        // Assumes SSA dialogue has format:
        // Layer, Start, End, Style, Actor, MarginL, MarginR, MarginV, Effect, Text
        token = strsep(&src, ",");
        token = strsep(&src, ",");
        // TODO: Parse out microseconds, replace '.' with ','
        sel[0] = token; // start
        token = strsep(&src, ",");
        sel[1] = token; // end
        token = strsep(&src, ",");
        token = strsep(&src, ",");
        token = strsep(&src, ",");
        token = strsep(&src, ",");
        token = strsep(&src, ",");
        token = strsep(&src, ",");
        printf("%d\n0%s --> %s\n", count, sel[0], sel[1]);

        token = multi_tok(src, "\\N");
        while( token != NULL ) {
          printf("%s\n", token);
          token = multi_tok(NULL, "\\N");
        }
        count++;
        free(tmp);
      }
    }
  }

  fclose(file);
  return 0;
}
