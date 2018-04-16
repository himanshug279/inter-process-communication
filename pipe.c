#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>
#include<string.h>
void case_changer(char buffer3[100]);

void case_changer(char buffer3[100])
{
     int j=0;
     int length=strlen(buffer3);
     for(j=0;j<length;j++)
     {
         if((buffer3[j]>=A)&&(buffer3[j]<=Z))
             buffer3[j]=strlwr(buffer3[j]);
         else 
              buffer3[j]=strupr(buffer3[j]);  
     }
     printf("%d",buffer3);            
}
int main()
{
       int size;
       int pd[2];
       pipe(pd);  
       char buffer[100];
       wite(1,"PLEASE ENTER THE INPUT = ",25);
       size=read(0,buffer,100);
       printf("YOUT INPUT IS = %s",buffer);
       pid_t p;
       p=fork();
       if(p>0)
       { 
             close(pd[0]);
             write(pd[1],buffer,1000);    
       }     
       else
       {
             close(pd[1]);
             char buffer2[100];
             strcpy(buffer2,buffer);
             int data = read(pd[0],buffer2,100);  
             case_changer(buffer2);   
       } 
      return 0;
}
