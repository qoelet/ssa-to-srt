#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool lineStartsWith( const char *s, const char *t ) {
  if( strncmp( s, t, strlen(t) ) == 0 )
    return 1;
  return 0;
}

void convertTimeStamp( char s[], char t[] ) {
  int i = 0;

  while( (t[i] = s[i]) != '\0' )
    ++i;

  if( t[7] == '.' ) {
    t[7] = ',';
  }
  t[10] = '0';
}

void stripFormatting( char s[], char t[] ) {
  int i = 0;
  int k = 0;
  int inFormatting = 0;

  while( s[i] != '\0' ) {
    if( s[i] == '{' ) {
      inFormatting = 1;
    }
    if( inFormatting == 0 ) {
      t[k] = s[i];
      ++k;
    }
    if( s[i] == '}' ) {
      inFormatting = 0;
    }
    ++i;
  }
  t[k] = '\0';
}
