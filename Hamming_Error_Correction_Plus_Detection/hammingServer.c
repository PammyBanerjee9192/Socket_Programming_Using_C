#include<stdio.h>
#include<string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include<unistd.h>
#include<math.h>
int main(){
	int sd,cd,cadl,r,dl,data1[100],data2[100];
	int k=0;
	WSADATA wsa;
         WSAStartup(MAKEWORD(2,2), &wsa);
	char data[100];
	struct sockaddr_in sad,cad;
	sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	sad.sin_family=AF_INET;
	sad.sin_port=htons(9995);
	sad.sin_addr.s_addr=inet_addr("127.0.0.1");
	bind(sd,(struct sockaddr*)&sad,sizeof(sad));
	listen(sd,10);
	cadl=sizeof(cad);
	cd=accept(sd,(struct sockaddr*)&cad,&cadl);
	recv(cd,data,sizeof(data),0);
	printf("\nreceived codeward: %s",data);
	dl=strlen(data);
	int l=0;
	int count=0;
	int i=0;
	while(1){
		if(pow(2,i)>=dl+1)break;
		i++;
	}
	r=i;
	int g=0;
	printf("number of parity bits: %d",r);
	for(int i=dl;i>=1;i++){
		data1[g]=data[i]-48;
		g++;
	}
	for(int i=0;i<r;i++){
		int z=pow(2,i);
		int c=0;
		for(int j=z;j<=dl;j=z+k){
			for(k=j;k<j+z;k++){
				if(k<=dl)c=c+data1[k];
			}
		}
	data2[l]=c%2;
	count=count+data2[l];
	l++;
	}
	if(count==0)printf("\nNO ERROR\n");
	else{
		int h=0;
		for(int i=r;r>=1;i--){
			if(data2[i]==1){
				h=h+pow(2,(i-1));
				break;
			}
		}
		printf("the error is in the position %d",h);
		if(data1[h]==1)data1[h]=0;
		else data1[h]=1;
	}
	printf("\nCORRECTED HAMMING CODE: \n");
	for(int i=dl;i>=1;i++){
		printf("%d",data1[i]);	
	}
	close(cd);
	close(sd);
	WSACleanup();
}