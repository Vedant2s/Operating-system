#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
void asc(int a[],int n);
void dsc(int a[],int n);
int main(){
int n=5;
int a[5]={2,5,3,7,1};
pid_t pid;
pid=fork();
if(pid<0){
perror("Fork Error\n");
}
else if(pid==0){
printf("Child process is:%ld",(long)getpid());
}
else
{
printf("Parent process id:%ld",(long)getpid());
}
switch(pid){
	case  -1 :
       printf("\n Fork error\n");
       exit(-1);

	case 0:
       printf("\nChild executes.....\n");
       asc(a,n);
       exit(pid);
        
	default:
       wait(NULL);
       printf("\nParent executes.....");
       dsc(a,n);
       system("ps -elf");
       exit(pid);

	

}
return 0;
}
void asc(int a[],int n){
int i,j,temp;
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if(a[i]>a[j]){
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("\nArray sorted in ascending order is:\n");
for(i=0;i<n;i++)
printf("%d",a[i]);
printf("\n");
}
void dsc(int a[],int n){
int i,j,temp;
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if(a[i]<a[j]){
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("\nArray sorted in descending order is:\n");
for(i=0;i<n;i++)
printf("%d",a[i]);
printf("\n");
}
