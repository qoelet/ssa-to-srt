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
