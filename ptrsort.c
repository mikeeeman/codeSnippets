#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 25

int getLines(char *lines[]);
void sort(char *p[], int n, int sortType);
void printStrings(char *p[], int n);
int alpha(char *p1, char *p2);
int reverse(char *p1, char *p2);

char *lines[MAXLINES];

int main( void )
{
  int numberOfLines, sortType;

  // Read in the lines from the keyboard.

  numberOfLines = getLines(lines);

  if ( numberOfLines < 0 )
  {
    puts("Memory allocation error");
    exit(-1);
  }

  puts("Enter 0 for reverse order sort, 1 for alphabetical:" );
  scanf("%d", &sortType);

  sort(lines, numberOfLines, sortType);
  printStrings(lines, numberOfLines);
  return 0;
}

int getLines(char *lines[])
{
  int n = 0;
  char buffer[80];  // Temporary storage for each line.

  puts("Enter one line at time; enter a blank when done.");

  while (n < MAXLINES && fgets(buffer, 80, stdin) != 0 && buffer[0] != '\n' && buffer[0] != EOF)
  {
    if ((lines[n] = (char *)malloc(strlen(buffer)+1)) == NULL)
      return -1;
    strcpy( lines[n++], buffer );
  }
  return n;

} // End of getLines()

void sort(char *p[], int n, int sortType)
{
  int a, b;
  char *x;

  // The pointer to function.
  int (*compare)(char *s1, char *s2);

  // Initialize the pointer to point to the proper comparison
  // function depending on the argument sort_type.
  compare = (sortType) ? reverse : alpha;

  for (a = 1; a < n; a++)
  {
    for (b = 0; b < n-1; b++)
    {
      if (compare(p[b], p[b+1]) > 0)
      {
        x = p[b];
        p[b] = p[b+1];
        p[b+1] = x;
      }
    }
  }
}// end of sort()

void printStrings(char *p[], int n)
{
  int count;

  for (count = 0; count < n; count++)
    printf("%s\n", p[count]);
}

int alpha(char *p1, char *p2)
{
  // Alphabetical comparison.
  return(strcmp(p2, p1));
}

int reverse(char *p1, char *p2)
{
  // Reverse alphabetical comparison.
  return(strcmp(p1, p2));
}
