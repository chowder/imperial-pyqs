#include "../stamp.h"
#include "solution.h"
#include <cctype>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

int leading_zeros(const char* digest, int count)
{
  return !isxdigit(digest[0]) ? -1    :
           (digest[0] != '0') ? count :
                                leading_zeros(digest+1, count+1);
}


bool file_to_SHA1_digest(const char* filename, char* digest)
{
  // attempt to open file
  ifstream in (filename);
  if (in.fail())
    return strcpy(digest, "error"), false;
  // read file
  char a;
  string msg_body;
  while (in.get(a), !in.eof())
    msg_body += a;
  // return digest
  return text_to_SHA1_digest(msg_body.c_str(), digest), true;
}


bool make_header(const char* recipient, const char* filename, char* header)
{
  char msg_digest[41], hdr_digest[41];
  int count = 0;
  file_to_SHA1_digest(filename, msg_digest);
  // create skeleton header (without count)
  string hdr = string(recipient) + ":" + string(msg_digest) + ":";
  // add count to it
  text_to_SHA1_digest((hdr + to_string(count++)).c_str(), hdr_digest);

  while (leading_zeros(hdr_digest) < 5){
    if (count > 10000000)
      return header[0] = '\0', false;
    else
      text_to_SHA1_digest((hdr + to_string(count++)).c_str(), hdr_digest);
  }
  return strcpy(header, (hdr + to_string(count++)).c_str()), true;
}


MessageStatus check_header(
  const char* address, const char* header, const char* filename
){
  string hdr = header;
  // check if there are 3 fields
  if (count(hdr.begin(), hdr.end(), ':') != 2)
    return INVALID_HEADER;

  // check if recipient matches
  string hdr_addr = hdr.substr(0, hdr.find(':'));
  if (strcmp(address, hdr_addr.c_str()) != 0)
    return WRONG_RECIPIENT;

  // check if message digest checks out
  string given_digest = hdr.substr(hdr.find(':')+1, 40); // SHA1 hash length
  char actual_digest[41];
  if (!file_to_SHA1_digest(filename, actual_digest) ||
      strcmp(actual_digest, given_digest.c_str()) != 0)
    return INVALID_MESSAGE_DIGEST;

  // check if header (as a digest) checks out
  char digest[41];
  text_to_SHA1_digest(header, digest);
  if (leading_zeros(digest) < 5)
    return INVALID_HEADER_DIGEST;

  // all good :)
  return VALID_EMAIL;
}
