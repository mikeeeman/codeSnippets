#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(void){
  const char *fileName = "studDatabase.txt";
  char name[50];
  int marks, idx, studNum;
  FILE *fp;
   
  printf("Enter number of students: ");
  scanf("%d",&studNum);
  
  fp = fopen(fileName,"a");
  if(fp == NULL){
     perror("Error!");
     exit(EXIT_FAILURE);
  }  
  for(idx=0; idx<studNum; ++idx)
  {
    printf("For student%d\nEnter name: ",idx+1);
    scanf("%s",name);
    printf("Enter marks: ");
    scanf("%d",&marks);
    fprintf(fp,"\nName: %s \nMarks=%d \n",name,marks);
   }
   fclose(fp);
   return EXIT_SUCCESS;
}
