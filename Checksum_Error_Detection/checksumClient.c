#include<stdio.h>
#include<string.h>
#include<math.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include<unistd.h>
int main(){
	char data[100],data1[100];
	int sum[100],sl,dl,c,k,t;
	int sd,cadl;
	WSADATA wsa;
	WSAStartup(MAKEWORD(2,2), &wsa);
	struct sockaddr_in sad,cad;
	sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	sad.sin_family=AF_INET;
	sad.sin_port=htons(9995);
	sad.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(sd,(struct sockaddr*)&sad,sizeof(sad));
	printf("enter the data: ");
	scanf("%s[^\n]",data);
	dl=strlen(data);
	while(1){
		printf("enter the segment length: ");
	        scanf("%d",&sl);
		int j=0;
		for(int i=1;i<=sl/2;i++){
			if(pow(2,i)==sl){
					j=1;
					break;
				}
		}
		if(j==1)break;
		else printf("segment length must be in power of 2");
	}
if(dl%sl!=0){
	int i=sl-(dl%sl);
	for(int j=0;j<i;j++)data1[i]='0';
	strcat(data1,data);
	strcpy(data,data1);
	dl=dl+i;
	}
for(int i=0;i<sl;i++)sum[i]=0;
for(int i=dl;i>0;i=i-sl){
		c=0;
		k=sl-1;
		for(int j=i-1;j>=i-sl;j--){
			t=(sum[k]+(data[j]-48)+c);
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
	printf("checksum:  ");
	int l=0;
	for(l=0;l<sl;l++){
		if(sum[l]==1)sum[l]=0;
		else sum[l]=1;
		printf("%d",sum[l]);
		data[dl+l]=sum[l]+48;	
	}
	data[dl+l]='\0';
	printf("\nencoded data: %s",data);
	send(sd,data,sizeof(data),0);
	close(sd);
	WSACleanup();
}