#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "betterstring.h"

#define VERIFY_PTR(ptr) assert(ptr != NULL)

void bs_init(BetterString* bs) {
  VERIFY_PTR(bs);

  bs->len = 0; 
  bs->cap = 1;
  bs->content = calloc(bs->cap, sizeof(char));

  // Null terminate the string so it safe to use
  bs->content[bs->len] = 0;
}

void bs_init_from(BetterString* bs, const char* str) {
  VERIFY_PTR(bs);
  VERIFY_PTR(str);

  bs->len = strlen(str);
  bs->cap = bs->len + 1;
  bs->content = calloc(bs->cap, sizeof(char));
  strncpy(bs->content, str, bs->len);

  // Null terminate the string so it safe to use
  bs->content[bs->len] = 0;
}

void bs_free(BetterString* bs) {
  free(bs->content);
}

void bs_append(BetterString* bs, char character) {
  VERIFY_PTR(bs);
  
  bs->len += 1;
  bs->cap = bs->len + 1;
  bs->content = realloc(bs->content, sizeof(char) * bs->cap);
  bs->content[bs->len - 1] = character;

  // Null terminate the string so it safe to use
  bs->content[bs->len] = 0;
}

void bs_pushstr(BetterString* bs, const char* str) {
  VERIFY_PTR(bs);
  VERIFY_PTR(str);

  size_t new_str_len = strlen(str);
  size_t old_len = bs->len;

  bs->len += new_str_len;
  bs->cap = bs->len + 1;
  bs->content = realloc(bs->content, sizeof(char) * bs->cap);
  
  // Fill the end of the array with the new string
  memcpy(bs->content + old_len, str, new_str_len);

  // Null terminate the string so it safe to use
  bs->content[bs->len] = 0;
}
