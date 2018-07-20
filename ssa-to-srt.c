#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool lineStartsWith( const char *s, const char *t ) {
  if( strncmp( s, t, strlen(t) ) == 0 )
    return 1;
  return 0;
}

const char* convertTimeStamp( char *s ) {
  char t[13] = {};
  char * result;
  result = malloc(sizeof(t));

  strcpy(t, s);
  if( t[8] == '.' ) {
    t[8] = ',';
  }
  t[11] = '0';
  strcpy(result, t);
  return result;
}
