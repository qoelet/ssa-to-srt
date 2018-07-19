#include <stdbool.h>
#include <string.h>

bool lineStartsWith( const char *s, const char *t ) {
  if( strncmp( s, t, strlen(t) ) == 0 )
    return 1;
  return 0;
}
