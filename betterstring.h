#ifndef BETTERSTRING_H
#define BETTERSTRING_H

#include <stddef.h>

typedef struct {
  char* content;
  size_t len;
  size_t cap;
} BetterString;

void bs_init(BetterString* bs);
void bs_init_from(BetterString* bs, const char* str);
void bs_free(BetterString* bs);
void bs_append(BetterString* bs, char character);
void bs_pushstr(BetterString* bs, const char* str);

#endif
