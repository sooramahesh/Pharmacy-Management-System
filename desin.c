#include<stdio.h>
#include<string.h>
#include "bill.h"      
void design(int a)      
{
if(a==2)
{
printf("\t\t\t\t\t|===================================================================================|\n");
printf("\t\t\t\t\t|                                                                                   |\n");
printf("\t\t\t\t\t|                         ----**   RAMESH MEDICALS   **----                         |\n");
printf("\t\t\t\t\t|                  #2-882/2 , OPP:NEW BUSSTAND, HANAMKONDA , WARANGAL               |\n");
printf("\t\t\t\t\t|                               PHONE N0: 9876543210                                |\n");
printf("\t\t\t\t\t|                                                                                   |\n");
printf("\t\t\t\t\t|===================================================================================|\n\n\n");
}
else
{
printf("\t\t\t\t\t|========================================================================|\n");
printf("\t\t\t\t\t|                                                                        |\n");
printf("\t\t\t\t\t|                    ----------------------------------                  |\n");
printf("\t\t\t\t\t|                       PHARMACY MANAGEMENT SYSTEM                       |\n");
printf("\t\t\t\t\t|                    ----------------------------------                  |\n");
printf("\t\t\t\t\t|                                                                        |\n");
printf("\t\t\t\t\t|========================================================================|\n\n\n");
}
}
int date_converter(char a[])
{
int len,date=0,m=0,y=0,x=0,i;
len = strlen(a);
for(i=0; i<len; i++)
{
    if(a[i]>='0'&&a[i]<='9')
date = date * 10 + ( a[i] - '0' );
}
m=date%10000;
y=m%100;
m=m/100;
x=y*100+m;
return x;
}
void report(struct customers *cust)
{
char red[15];
int k=0,j;
float sales=0;
FILE *f1;
printf("\t\t\t\t\t\t\t\t\t* sales report *");
printf("\n\n\t\t\t\t\tEnter the date (DD/MM/YY) : ");
scanf("%s",red);
printf("\n\t\t\t\t\t");
for(j=0;j<74;j++)
printf("-");
printf("\n\t\t\t\t\t|%-5s|%-20s|%-10s|%-5s|%-15s|%-12s|\n","s.no.","Name","Gender","Age","Mobile.number","bill amount");
printf("\t\t\t\t\t");
for(j=0;j<74;j++)
printf("-");
f1=fopen("medicalbill.txt","r");
while(fscanf(f1,"%s%s%s%d%lld%f",cust->date,cust->name,cust->gender,&cust->age,&cust->number,&cust->expenses)!=EOF)
{
if(strcmp(red,cust->date)==0)
{
printf("\n\t\t\t\t\t|%-5d|%-20s|%-10s|%-5d|%-15lld|%-12.2f|\n",++k,cust->name,cust->gender,cust->age,cust->number,cust->expenses);
sales+=cust->expenses;
printf("\t\t\t\t\t");
for(j=0;j<74;j++)
printf("-");
}
}
printf("\n\t\t\t\t\tTotal sales of the day = %-10.2f",sales);
fclose(f1);
if(k==0){
system("cls");
design(1);
printf("\n\n\n\t\t\t\t\tSorry we dont have sales on that day");
}
printf("\n\n\t\t\t\t\t Enter anything to continue -> ");
getch();
}
 
