#ifndef SPELL_SOLUTION_H
#define SPELL_SOLUTION_H

#define RESET NULL

int frequency(const char* target);

int edit_distance(const char* a, const char* b);

int edit_distance(
  const char* a, const char* b, int i, int j, char cache[MAX_LENGTH][MAX_LENGTH]
);

bool spell_correct(const char* word, char* fixed);

int edit_distance_bonus(const char* a, const char* b, bool reset = true);

#endif
