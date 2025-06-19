#include<stdio.h>
#include<string.h>
#include <arpa/inet..h>
#include<unistd.h>
int main()
{
int sd,cd,cad1;
struct sockaddr_in sad,cad;
int dl,divl,i,j;
char div[50],ch,data[50],data1[50],data2[50];
sd=socket(AF_INET,SOCK_STREAM,0);
sad.sin_family=AF_INET;
sad.sin_port=htons(9422);
sad.sin_addr.s_addr=inet_addr("127.0.0.1");
bind(sd,(struct sockaddr *)&sad,sizeof(sad));
listen(sd,10);
cad1=sizeof(cad);
cd=accept(sd,(struct sockaddr *)&cad,&cad1);
recv(cd,data,sizeof(data),0);
printf("the received codeword id: %s",data);
printf("Do you want to modified the codeword :\n1.enter y for yes\n2.enter n for no.");
scanf("%c",&ch);
if(ch=='n'){
dl=strlen(data);
printf("\nEnter coefficients of generator polynomial:");
scanf("%s",div);
divl=strlen(div);
strcpy(data1,data);
for(i=0;i<dl-(divl-1);i++)
{
if(data[i]=='1')
{
for(j=0;j<divl;j++)
{
if(data[i+j]==div[j])
data[i+j]='0';
else
data[i+j]='1';
}
}
}
j=0;
for(i=dl-(divl-1);i<dl;i++)
j=j+data[i]-48;
if(j==0)
{
printf("\nOriginal data receive\n");
printf("\n Actual data : ");
for(i=0;i<dl-(divl-1);i++)
printf("%c ",data1[i]);

}
else{
printf("\n data recv wrong \n");
}
}
if(ch=='y'){
printf("enter the modified codeword: ");
scanf("%s",data2);
dl=strlen(data2);
printf("\nEnter coefficients of generator polynomial:");
scanf("%s",div);
divl=strlen(div);
strcpy(data1,data2);
for(i=0;i<dl-(divl-1);i++)
{
if(data2[i]=='1')
{
for(j=0;j<divl;j++)
{
if(data2[i+j]==div[j])
data2[i+j]='0';
else
data2[i+j]='1';
}
}
}
j=0;
for(i=dl-(divl-1);i<dl;i++)
j=j+data2[i]-48;
if(j==0)
{
printf("\nOriginal data receive\n");
printf("\n Actual data : ");
for(i=0;i<dl-(divl-1);i++)
printf("%c ",data1[i]);
}
else{
printf("\n data recv wrong \n");
}
}
close(cd);
close(sd);
}