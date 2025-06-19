#include<stdio.h>
#include<unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include<string.h>
#include<math.h>
int main(){
	char data[100];
	int data1[100],data2[100]={0},dl,r,c;
	int i=0;
	int k=0;
	int sd,cadl;
	WSADATA wsa;
        WSAStartup(MAKEWORD(2,2), &wsa);
	struct sockaddr_in sad,cad;
	sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	sad.sin_family=AF_INET;
	sad.sin_port=htons(9995);
	sad.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(sd,(struct sockaddr*)&sad,sizeof(sad));
	printf("enter the data:  ");
	scanf("%[^\n]",data);
	dl=strlen(data);
	while(1){
		if(pow(2,i)>=dl+i+1)break;
		i++;
	}
	r=i;
	printf("number of parity bits: %d",r);
	for(int j=0;j<dl;j++){
		data1[j]=data[j]-48;
	}
	for(int j=0;j<r;j++){
		int z=pow(2,j);
		data2[z]=999;
	}
	int m=0;
	for(int j=dl+r;j>=1;j--){
		if(data2[j]!=999){
		data2[j]=data1[m];
		m++;
		}
	}
	for(int j=0;j<r;j++){
		int z=pow(2,j);
		c=0;
		for(int h=z;h<=dl+r;h=z+k){
			for( k=h;j<h+z;k++){
					if(k<=dl+r){
						if(data2[k]!=999)c=c+data2[k];
					}	
			}
		
		}
	data2[z]=c%2;
	}
	printf("\ncodeward is: ");
	for(int d=dl+r;d>=1;d--)
       {
       printf("%d",data2[d]);
       }
	close(sd);
	WSACleanup();
}