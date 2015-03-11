#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* function for checking same characters with substring and text 
   this function return index that is next to the last index that match between
   text and substring */
int match(char *sub, char *txt)
{
  int index;
  int j=0;
  char s;
  while(1)
    {
      s=txt[j];
      if(sub=='\0')
	break;
      if(txt[j] != sub[j])
	break;
      j++;
    }
  index = j;
  return index;
}
const char * getDoubleString(char *s){
  char *buffer = (char *)malloc (strlen(s)*2+1);
  strcpy(buffer,s);
  s++;
  int index=0;
  /* send substring of text input to check overlap character */
  while(s[0] != '\0')
    {
      char *txt = buffer;
      char *sub = s;
      int tmp = match(sub,txt);
      if(tmp > index)
	index = tmp;
      s++;
    }
  /* if there are some substrings match partially with the text(a word you input) concatenation buffer with rest of that text by shift beginning of the text equal index value,index value return from function match. */
  if(index > 0 )
    {
      strcat(buffer,buffer+index);
      return buffer;
    }
  strcat(buffer,buffer);
  return buffer;
}

int main()
{
  char s[100];
  printf("Enter string\n");
  scanf("%s",s);
  printf("%s\n",getDoubleString(s)); 
  return 0;
}
