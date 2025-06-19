#include<stdio.h>
#include<unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include<string.h>
#include<math.h>
int main(){
	int sd,cd,cadl,dl,sl,c,k,t,sum[100];
	struct sockaddr_in sad,cad;
	char str[100];
	WSADATA wsa;
	WSAStartup(MAKEWORD(2,2), &wsa);
	sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	sad.sin_family=AF_INET;
	sad.sin_port=htons(9995);
	sad.sin_addr.s_addr=inet_addr("127.0.0.1");
	bind(sd,(struct sockaddr*)&sad,sizeof(sad));
	listen(sd,10);
	cadl=sizeof(cad);
	cd=accept(sd,(struct sockaddr*)&cad,&cadl);
	int recv_len = recv(cd, str, sizeof(str) - 1, 0);
        str[recv_len] = '\0'; // null terminate
	printf("received data:  %s",str);
	dl=strlen(str);
	while(1){
		int j=0;
		printf("\nenter the segment length: ");
		scanf("%d",&sl);
		for(int i=1;i<=sl/2;i++){
			if(pow(2,i)==sl){
				j=1;
				break;
			}
		}
		if(j==1)break;
		else printf("\nsegment length must be in power of 2");
	}
	for(int s=0;s<sl;s++)sum[s]=0;
	for(int i=dl;i>0;i=i-sl){
		c=0;
		k=sl-1;
		for(int j=i-1;j>=i-sl;j--){
			t=(sum[k]+(str[j]-48)+c);
			sum[k]=t%2;
			c=t/2;
			k--;
		}
		if(c==1){
			for(int j=sl-1;j>=0;j--){
				t=sum[j]+c;
				sum[j]=t%2;
				c=t/2;
			}
		}

	}
	printf("\ncalculated checksum:  ");
	for(int i=0;i<sl;i++){
		if(sum[i]==0)sum[i]=1;
		else sum[i]=0;
		printf("%d",sum[i]);
	}
	int flag=0;
	for(int i=0;i<sl;i++){
		if(sum[i]!=0){flag=1;break;}
	}
	if(flag==1)printf("\nwrong message received\n");
	else {
		printf("\nactual message received\n");
		for(int i=0;i<dl-sl;i++){
			printf("%c",str[i]);
		}
	}
	close(cd);
	close(sd);
	WSACleanup();
}