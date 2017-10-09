#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  // TODO: Fill this!
  int SIZE = strlen(command);
  int count = 0;
  char *s = (char*)malloc(100 * sizeof(char));
  (*argv) = (char **)malloc(100 * sizeof(char *));
  (*argv)[count] = (char*)malloc(100 * sizeof(char));
  strcpy(s, command);
  char *ptr = strtok(s, "' ',\n,\t ");
 
 if(ptr == NULL)
  {  
     strcpy((*argv)[count],"");
     count++;}
  while (ptr != NULL)
  {
   /* if ( strcmp(ptr,"..") == 0)
    {
      strcpy((*argv)[count++],".");
      (*argv)[count] = (char*)malloc(100*sizeof(char));
      strcpy((*argv)[count++],".");
      (*argv)[count] = (char*)malloc(100*sizeof(char));
      ptr = strtok(NULL, "' ',\n,\t ");
    }*/
    strcpy((*argv)[count], ptr);
    ++count;
    (*argv)[count] = (char*)malloc(100 * sizeof(char));
    ptr = strtok(NULL, "' ',\n,\t ");
  }
  *argc = count;
}

