#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH 80

void usage(void)
{
  // your usage dialogue
  // information
  exit (8);
}

int main(int argc, char *argv[])
{
  char *fnamePtr = NULL;
  char *lnamePtr = NULL;
  printf("Program name: %s\n", argv[0]);

  if(2 > argc)
  {
    printf("Type: %s -h\n", argv[0]);
    printf("To get usage dialogue\n\n");
  }


  while ((argc > 1) && (argv[1][0] == '-'))
  {
    switch (argv[1][1])
    {
    // your parser 
     case <key> :
       // some function
        break;

      default:
        printf("Wrong Argument: %s\n", argv[1]);
        usage();
    }
    ++argv;
    --argc;
  }

  // read first name
  if (fnamePtr == NULL)
  {
     // if not set ask user
  }
  // read last name
  if (lnamePtr == NULL)
  {
     // if not set ask user
  }

  printf("\nHello %s your name is: %s %s\n", fnamePtr, fnamePtr, lnamePtr);

  return EXIT_SUCCESS;
}
