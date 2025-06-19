#include<stdio.h>
#include<unistd.h>
#include <arpa/inet.h>
#include<string.h>
int main(){
	int sd,cadl,flag;
	struct sockaddr_in sad,cad;
	char str[100],str2[100],s1[10]={'0'},s2[10]={'1'},ch,ch2;
	int c=0,count=0;
	sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	sad.sin_family=AF_INET;
	sad.sin_port=htons(9995);
	sad.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(sd,(struct sockaddr*)&sad,sizeof(sad));
	printf("enter the message: ");
	gets(str);
	printf("message: ");
	puts(str);
	while(str[c]!='\0'){
		if(str[c]=='1')count++;
		c++;
	}	
	printf("enter choice :\n1.enter e for even parity \n2.enter o for odd parity \n");
	scanf("%c",&ch);
	getchar();
	switch(ch){
		case 'e':
				if(count%2==0)strcat(str,s1);
				else strcat(str,s2);
				printf("updated message: %s\n",str);
				break;
		case 'o':
				if(count%2==0)strcat(str,s2);
				else strcat(str,s1);
				printf("updated message: %s\n",str);
				break;
		}
	printf("do you want to modify the codeward? \n 1.enter y for yes \n 2.n for no\n");
	scanf("%c",&ch2);
	switch(ch2){
		case 'y':
				printf("codeward is : %s --->you can modify it(only one bit is preferred)\n",str);
				printf("enter the modified codeward: ");
				scanf("%s[^\n]",str2);
				printf("\nmodified codeward is: %s",str2);
				send(sd,str2,sizeof(str2),0);
				break;
		case 'n':
				printf("original codeward is sent to the server side: %s",str);
				send(sd,str,sizeof(str),0);
				break;
	}
	close(sd);
}