#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
  int count,start;
  FILE *fp;
  char c;
  if(argc!=2)
    {
    printf("Usage:./a.out Filename\n");
        exit(1);
    }
  fp=fopen(argv[1],"r");
  if(fp==NULL)
  {
    printf("Open Failed Or the File Not Exist!\n");
    exit(1);
  }
  fseek(fp,0,SEEK_SET);
  start=1;  //0-单词开始  1-不是开头
  count=0;
  while(feof(fp)==0)
  {
    fread(&c,1,1,fp);
    if(c==' ' && start==1)
    {
      start=1;
    }
    else if(c!=' ' && start==1)
    {
      start=0;
      count++;
    }
    else if(c==' ' && start==0)
    {
      start=1;
    }
  }
  printf("单词数为%d\n",count);
  return 1;
}
