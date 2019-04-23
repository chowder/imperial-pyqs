#ifndef STAMP_SOLUTION_H
#define STAMP_SOLUTION_H

#include "../stamp.h"

int leading_zeros(const char* digest, int count = 0);

bool file_to_SHA1_digest(const char* filename, char* digest);

bool make_header(const char* recipient, const char* filename, char* header);

MessageStatus check_header(
  const char* address, const char* header, const char* filename
);


#endif
