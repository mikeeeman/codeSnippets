#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[50];
  int height;
} PERSON;

void flushStdin(void);

int main(void){
  const char *fname = "file.txt";
  PERSON arr1[5], arr2[5];
  FILE *fp;
  int idx, persNum;
  fp = fopen(fname, "wb");
  
  printf("Enter number of person: ");
  scanf("%d",&persNum);
  flushStdin();

  for(idx=0; idx<persNum; ++idx)
  {
    fflush(stdin);
    printf("Enter name: ");
    fgets(arr1[idx].name, sizeof(arr1[idx].name), stdin);
    printf("Enter height: "); 
    scanf("%d",&arr1[idx].height);
    flushStdin();
  }
  
  fwrite(arr1,sizeof(arr1),1,fp);
  fclose(fp);
  
  fp = fopen(fname,"rb");
  fread(arr2,sizeof(arr2),1,fp);
  printf("\n");
  for(idx=0; idx<persNum; ++idx)
  {
     printf(" Name: %s Height: %d\n",arr2[idx].name,arr2[idx].height);
  }
  fclose(fp);
}

void flushStdin(void)
{
  int c;
  while((c = getchar()) != '\n' && c != EOF)
    /* discard */ ;
}
