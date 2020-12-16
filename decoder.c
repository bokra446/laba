#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
char* imutablestrip(const char* str){
	char* q = (char*)malloc(strlen(str)*sizeof(char));
	strcpy(q,str);
	unsigned int i,j;
	for (i=j=0;i<strlen(str);i++){
		if (str[i]!=' '){
				q[j++]=str[i];
		}
	}
	q[j]='\0';
	return q;
}
int main(){
char s[]="  H i  " ;
/*mutablestrip(s);
printf("%s\n",s);*/
char* l=imutablestrip(s);
printf("%s\n", l);
/*char* g="jj";
char* j=g;
printf("%s\n",j);*/
return 0;
}