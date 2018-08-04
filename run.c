#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ssa-to-srt.h"

#define IN 1
#define OUT 0
#define TIMESTAMP 13
#define SUBTITLE 150

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
  char given[TIMESTAMP];
  char from[TIMESTAMP];
  char to[TIMESTAMP];
  char sub[SUBTITLE];
  char strippedSub[SUBTITLE];

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
        strncpy(given, token, TIMESTAMP); // start
        convertTimeStamp(given, from);
        token = strsep(&src, ",");
        strncpy(given, token, TIMESTAMP); // end
        convertTimeStamp(given, to);
        token = strsep(&src, ",");
        token = strsep(&src, ",");
        token = strsep(&src, ",");
        token = strsep(&src, ",");
        token = strsep(&src, ",");
        token = strsep(&src, ",");
        printf("%d\n0%s --> %s\n", count, from, to);

        token = multi_tok(src, "\\N");
        while( token != NULL ) {
          strncpy(sub, token, SUBTITLE);
          stripFormatting(sub, strippedSub);
          printf("%s\n", strippedSub);
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
