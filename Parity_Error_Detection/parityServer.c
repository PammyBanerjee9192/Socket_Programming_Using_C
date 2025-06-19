#include<stdio.h>
#include<unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include<string.h>
int main(){
int sd,cd,cadl;
WSADATA wsa;
WSAStartup(MAKEWORD(2,2), &wsa);
struct sockaddr_in sad,cad;
char str[100],ch;
int c=0,count=0;
sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
sad.sin_family=AF_INET;
sad.sin_port=htons(9995);
sad.sin_addr.s_addr=inet_addr("127.0.0.1");

bind(sd,(struct sockaddr*)&sad,sizeof(sad));
listen(sd,10);

cadl=sizeof(cad);
cd=accept(sd,(struct sockaddr*)&cad,&cadl);

recv(cd,str,sizeof(str),0);
while(str[c]!='\0'){
		if(str[c]=='1')count++;
		c++;
	}	

printf("enter choice :\n1.enter e for even parity\n2.enter o for odd parity\n ");
	scanf("%c",&ch);
	switch(ch){
		case 'e':
				if(count%2==0)printf("no error");
				else printf("error");
				break;
		case 'o':
				if(count%2==0)printf("error");
				else printf("no error");
				break;
		}
close(cd);
close(sd);
WSACleanup();
}