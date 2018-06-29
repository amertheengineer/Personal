#include <stdio.h>
#include "read_line.h"

/***************************************************************
 * read_line: Skips leading white-space characers, then reads  *
 * the remainder of the input line and stores it in str.       *
 * Truncate the line if its length exceeds n. Returns the      *
 * number of characters stored.                                *
 * ************************************************************/

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;

   }
   str[i] = '\0';
   return i;
 }
