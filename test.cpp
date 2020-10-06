#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int isLetter(char c){
	if(c>='0'&&c<='9') return 1;
	if(c>='a'&&c<='z') return 1;
	if(c>='A'&&c<='Z') return 1;
	return 0;
}
int legal(char c){
	if(isLetter(c)||c=='+'||c=='*'||c==','||c=='('||c==')'||c==':')return 1;
	return 0;
}
int main(char *argv[]){
	char s[1000],d[50];
	int flag=0; 
	FILE * fp;
    fp = fopen (argv[0], "r");
	while(fscanf(fp,"%s",s)!=EOF){
		for(int i=0;s[i]!='\0';){
			flag=0;
			strncpy(d, s+i, 5);
			d[5]='\0';
			if(legal(s[i+5])&&!isLetter(s[i+5])&&strcmp(d,"BEGIN")==0){
				printf("Begin\n");
				i+=5;	
				flag=1;
			}
			strncpy(d, s+i, 3);
			d[3]='\0';
			if(legal(s[i+3])&&!isLetter(s[i+3])&&strcmp(d,"END")==0){
				printf("End\n");
				i+=3;	
				flag=1;
			}
			if(legal(s[i+3])&&!isLetter(s[i+3])&&strcmp(d,"FOR")==0){
				printf("For\n");
				i+=3;	
				flag=1;
			}
			strncpy(d, s+i, 2);
			d[2]='\0';
			if(legal(s[i+2])&&!isLetter(s[i+2])&&strcmp(d,"IF")==0){
				printf("If\n");
				i+=2;	
				flag=1;
			}
			strncpy(d, s+i, 4);
			d[4]='\0';
			if(legal(s[i+4])&&!isLetter(s[i+4])&&strcmp(d,"THEN")==0){
				printf("Then\n");
				i+=4;
				flag=1;
			}
			if(legal(s[i+4])&&!isLetter(s[i+4])&&strcmp(d,"ELSE")==0){
				printf("Else\n");
				i+=4;
				flag=1;
			}
			if(s[i]=='+'){
				printf("Plus\n");
				i++;
				flag=1;
			}
			if(s[i]=='*'){
				printf("Star\n");
				i++;
				flag=1;
			}
			if(s[i]==','){
				printf("Comma\n");
				i++;
				flag=1;
			}
			if(s[i]=='('){
				printf("LParenthesis\n");
				i++;
				flag=1;
			}
			if(s[i]==')'){
				printf("RParenthesis\n");
				i++;
				flag=1;
			}
			if(s[i]==':'){
				if(s[i+1]==':'){
					printf("Assign\n");
					i+=2;
				}
				else{
					printf("Colon\n");
					i++;
				}
				flag=1;
			}
			if(isdigit(s[i])){
				printf("Int(%d)\n",atoi(s+i));
				while(isdigit(s[i])) i++;
				flag=1;
			}
			if(isalpha(s[i])){
				char ss[100];
				int j=0;
				while(isLetter(s[i])){
					ss[j++]=s[i++];
				}
				ss[j]='\0';
				printf("Ident(%s)\n",ss);
				flag=1;
			}
			if(flag==0) return 0;
		}
	}
} 
