#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "desin.c"
#include "bill.h"

int nummed=0,ash=0;
int i,n,j,date=0;
char newdate[15];
struct medicine med[100];
struct medicine mahi;
struct medicine bill[20];
struct customers cust;
FILE *f1;
void main()
{
	char ch;
	f1=fopen("medical.txt","r");
for(i=0;fscanf(f1,"%s%s%s%d%s%s%f",med[i].medname,med[i].address,med[i].box,&med[i].quantity,med[i].mdate,med[i].edate,&med[i].price)!=EOF;i++);
	nummed=i;
	fclose(f1);
	
	new_date();
	start:
	design(1);
	printf("\n\n\n\t\t\t\t\t List of options");
	printf("\n\t\t\t\t\t1.customer's usage");
printf("\n\t\t\t\t\t2.mangement usage\n\t\t\t\t\t3.Exit\n");
	printf("\n\n\n\t\t\t\t\tenter the option :  ");
	scanf(" %c",&ch);
	switch(ch)
	{
		case '1':system("cls");
		design(1);customer();
		break;
		case '2':system("cls");management();
		break;
		case '3':system("cls");design(1);goto end;
	}
	system("cls");
	goto start;
end: printf("\t\t\t\t\tTask has completed........\n\n\n\n\n\n\n\n\n\n"); 
}
void expdel(char b[])
{
	f1=fopen("expiredmedical.txt","a");
	fprintf(f1,"%-15s\t%-15s\t%-15s\t%-10d\t%-10s\t%-10s\t%-10.2f\n",mahi.medname,mahi.address,mahi.box,mahi.quantity,mahi.mdate,mahi.edate,mahi.price);
	fclose(f1);
	int i,j;
	for(i=0;i<nummed;i++)
	{
		if(strcmp(med[i].medname,b)==0)
		{
			for(j=i;j<nummed;j++)
			{
				med[j]=med[j+1];
			}
			nummed--;
			break;
		}
	}
}

void new_date()
{
	int  i,y,m,x=0,l;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(cust.date,"%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, (tm.tm_year + 1900)%100);
	x=date_converter(cust.date);
	for(i=0;i<nummed;i++)
	{
		l=date_converter(med[i].edate);
		if(l<=x)
		{
			mahi=med[i];
			expdel(med[i].medname);
			i=-1;
		}
	}
	updater();
}

void show_expiry()
{
	int i=0,j;
	printf("\n\t\t\t\t\tExpired medicines are :\n");
	printf("\n\t\t\t\t\t");
	for(j=0;j<83;j++)
			printf("-");
	printf("\n\t\t\t\t\t|%-5s|%-20s|%-10s|%-5s|%-8s|%-10s|%-10s|%-6s|\n","s.no.","med_name","address","box","quantity","Mfg date","exp date","price");
	printf("\t\t\t\t\t");
		for(j=0;j<83;j++)
			printf("-");
	f1=fopen("expiredmedical.txt","r");
	while(fscanf(f1,"%s%s%s%d%s%s%f",mahi.medname,mahi.address,mahi.box,&mahi.quantity,mahi.mdate,mahi.edate,&mahi.price)!=EOF)
	{
		printf("\n\t\t\t\t\t|%-5d|%-20s|%-10s|%-5s|%-8d|%-10s|%-10s|%-6.2f|\n",++i,mahi.medname,mahi.address,mahi.box,mahi.quantity,mahi.mdate,mahi.edate,mahi.price);
		printf("\t\t\t\t\t");
		for(j=0;j<83;j++)
			printf("-");
	}
	fclose(f1);
	printf("\n\n\t\t\t\t\t Enter anything to continue -> ");
	getch();
}

void customer_details()
{
	printf("\n\n\n\t\t\t\t\tENTER THE CUSTOMER DETAILS :\n\n ");
	printf("\n\t\t\t\t\tNAME : ");
	scanf("%s",cust.name);
	printf("\n\t\t\t\t\tAGE : ");
	scanf("%d",&cust.age);
	printf("\n\t\t\t\t\tCONTACT NO : ");
	scanf("%lld",&cust.number);
	printf("\n\t\t\t\t\tGENDER(M/F) : ");
	scanf(" %s",cust.gender);
	ash=0;
	system("cls");
}
void customer()
{
	customer_details();
	char n;
	do
	{
	design(1);
	printf("\n\n\t\t\t\t\t\t\t\t    * CUSTOMER SECTION *");
	printf("\n\n\t\t\t\t\t List of customer options");
	printf("\n\n\t\t\t\t\t1.search customer medicine\n\t\t\t\t\t2.print bill\n\t\t\t\t\t3.Go back\n");
	printf("\n\n\n\t\t\t\t\tenter the option :  ");
	scanf(" %c",&n);
	switch(n)
	{
		case '1':system("cls");search();
		break;
		case '2':system("cls");display();
		break;
		case '3':goto deadend;
	}
	system("cls");
	}while(1);
	deadend:printf("");
	updater();
	if(cust.expenses!=0)
	{
		bill_updater();
	}
}
void management()
{
	char n;
	do
	{
	design(1);
	printf("\n\n\t\t\t\t\t\t\t\t  * MANAGEMENT SECTION *");
	printf("\n\n\n\t\t\t\t\t List of management options");
	printf("\n\n\t\t\t\t\t1.add new medicine\n\t\t\t\t\t2.see list");
	printf("\n\t\t\t\t\t3.delete a specic medicine\n\t\t\t\t\t4.sort by expire date\n\t\t\t\t\t5.sort by medicine name");
	printf("\n\t\t\t\t\t6.edit any medicine details\n\t\t\t\t\t7.Expired medicine details\n\t\t\t\t\t8.Sales report\n\t\t\t\t\t9.Go back\n");
	printf("\n\n\n\t\t\t\t\tenter the option :  ");
	scanf(" %c",&n);	
	switch(n)
	{
		case '1':system("cls");design(1);
		update();
		break;
		case '2':system("cls");design(1);
		see(1);
		break;
		case '3':system("cls");design(1);
		deleter();
		break;
		case '4':system("cls");design(1);
		sorter();
		break;
		case '5':system("cls");design(1);
		name_sorter();
		break;
		case '6':system("cls");design(1);
		edit();
		break;
		case '7':system("cls");design(1);
		show_expiry();
		break;
		case '8':system("cls");design(1);
		report(&cust);
		break;
		case '9':goto back;
	}	
	system("cls");
	}while(1);
	back: printf("");
	updater();
}

void search()
{
	design(1);
	printf("\t\t\t\t\tHere is a list of medicines in our store\n\t\t\t\t\t");
	for(i=1;i<=nummed;i++)
	{
		printf("%-20s\t",med[i-1].medname);
		if(i%4==0)
		printf("\n\t\t\t\t\t");
	}
	printf("\n\t\t\t\t\tEnter the Medicines Customer required \n\n");
	char b[20];
	int ch;
	int flag=0,p,k,x,bil=-0,lil=-0;
	do{
	p=0;
	printf("\t\t\t\t\tEnter the Medicine name : ");
	scanf("%s",b);
	for(i=0;i<ash;i++)
	{
		if(strcmp(bill[i].medname,b)==0)
		{
			bil=i;
			for(j=0;j<nummed;j++)
			{
				if(strcmp(med[j].medname,b)==0)
				{
					lil=j;
					p=1;
					break;
				}
			}
			break;
		}
	}
	if(p==1)
	{	
		printf("\t\t\t\t\tEnter quantity to update  : ");
		scanf("%d",&x);
		bill[bil].quantity+=x;
		if(x>med[lil].quantity)
		{
		printf("\n\t\t\t\t\tSorry !  We dont have enough quantity");
		printf("\n\t\t\t\t\tWe only have ->  %d  <- units left\n",med[lil].quantity);
		bill[bil].quantity-=x;
		}
		else
		{
		med[lil].quantity=med[lil].quantity-x;
		}
	}
	else
	{
	flag=0;
	for(i=0;i<nummed;i++)
	{
		k=5;
		k=strcmp(b,med[i].medname);
		if(k==0)
		{
			bill[ash]=med[i];
			printf("\t\t\t\t\tEnter quantity : ");
			scanf("%d",&bill[ash].quantity);
			if(bill[ash].quantity>med[i].quantity)
			{
			printf("\n\t\t\t\t\tSorry !  We dont have enough quantity");
			printf("\n\t\t\t\t\tWe only have ->  %d  <- units left\n",med[i].quantity);
			bill[ash].quantity=0;
			}
			else
			{
			med[i].quantity=med[i].quantity-bill[ash].quantity;
			ash++;
			}
			flag=2;
			break;
		}
	}
	if(flag!=2)
	printf("\n\t\t\t\t\t medicine not available\n");
	}
	printf("\n\n\t\t\t\t\tEnter 1 to add another medicine :");
	scanf("%d",&ch);
	}while(ch==1);
}
void display()
{
	int t=0;
	float d=0;
	time_t T = time(NULL);
	struct tm tm = *localtime(&T);
	design(2);
	//printf("\n\t\t\t\t\tCUSTOMER DETAILS  ->\n\n");
	printf("\t\t\t\t\t\t\t\t\t* CASH BILL *\n");
	printf("\n\t\t\t\t\tNAME : %-15s",cust.name);
	printf("\t\tAGE : %-10d",cust.age);
	printf("\t\tGENDER : %-10s",cust.gender);
	printf("\n\n\t\t\t\t\tCONTACT NO : %-15lld",cust.number);
	printf("\tBILL DATE : %02d-%02d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	printf("\t\tBILLED TIME:%02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
	cust.expenses=0;
	printf("\n\t\t\t\t\t");
	for(j=0;j<82;j++)
			printf("-");
	printf("\n\t\t\t\t\t|%-5s|%-30s|%-10s|%-10s|%-10s|%-10s|\n","s.no.","med_name","exp date","quantity","rate","Amount");
	for(i=0;i<ash;i++)
	{
		if(bill[i].quantity!=0)
		{
		printf("\t\t\t\t\t");
		for(j=0;j<82;j++)
			printf("-");
		printf("\n\t\t\t\t\t|%-5d|%-30s|%-10s|%-10d|%-10.2f|%-10.2f|\n",++t,bill[i].medname,bill[i].edate,bill[i].quantity,bill[i].price,(float)(bill[i].quantity*bill[i].price));
		}
	}
	printf("\t\t\t\t\t");
	for(j=0;j<82;j++)
			printf("-");
	for(j=0;j<ash;j++)
		cust.expenses+=bill[j].price*bill[j].quantity;
	printf("\n\n\t\t\t\t\tGROSS AMOUNT: %-10.2f",cust.expenses);
	if(cust.expenses>=1000)
	d=cust.expenses*5/100;
	printf("\n\t\t\t\t\tDISCOUNT : %-10.2f",d);
	cust.expenses-=d;
	printf("\n\t\t\t\t\tNet Payable  Amount: %-10.2f",cust.expenses);
	printf("\n\n\t\t\t\t\t\t\t\t\t HAVE A SPEEDY RECOVERY ");
	printf("\n\n\t\t\t\t\tEnter anything to continue -> ");
	getch();
}
void update()
{
		printf("\n\t\t\t\t\t\tENTER  MEDICINE  DETAILS\n");
		printf("\t\t\t\t\tEnter medicine name:  ");
		scanf("%s",med[nummed].medname);
		
		printf("\t\t\t\t\tEnter medicine address: ");
		scanf("%s",med[nummed].address);
		
		printf("\t\t\t\t\tEnter medicine box:  ");
		scanf("%s",med[nummed].box);
		
		printf("\t\t\t\t\tEnter medicine quantity: ");
		scanf("%d",&med[nummed].quantity);
		
		printf("\t\t\t\t\tEnter medicine manufacturing date (MM/YY) : ");
		scanf("%s",med[nummed].mdate);
		
		printf("\t\t\t\t\tEnter medicine expiry date (MM/YY) : ");
		scanf("%s",med[nummed].edate);
		
		printf("\t\t\t\t\tEnter medicine price:  ");
		scanf("%f",&med[nummed].price);
		
		nummed++;
	printf("\t\t\t\t\tMedicine added sucessfully");
	updater();
	printf("\n\n\t\t\t\t\t Enter anything to continue -> ");
	getch();
}
void see(int bts)
{
	if(bts==1)
	printf("\t\t\t\t\tMedicines available in our store:");
	if(bts==2)
	printf("\t\t\t\t\tMedicines sorted according to expiry date:");
	if(bts==3)
	printf("\t\t\t\t\tMedicines sorted according to alphabetical order:");
	printf("\n\t\t\t\t\t");
	for(j=0;j<83;j++)
			printf("-");
	printf("\n\t\t\t\t\t|%-5s|%-20s|%-10s|%-5s|%-8s|%-10s|%-10s|%-6s|\n","s.no.","med_name","address","box","quantity","Mfg date","exp date","price");
	for(i=0;i<nummed;i++)
	{
		printf("\t\t\t\t\t");
		for(j=0;j<83;j++)
			printf("-");
		printf("\n\t\t\t\t\t|%-5d|%-20s|%-10s|%-5s|%-8d|%-10s|%-10s|%-6.2f|\n",i+1,med[i].medname,med[i].address,med[i].box,med[i].quantity,med[i].mdate,med[i].edate,med[i].price);
	}
	printf("\t\t\t\t\t");
	for(j=0;j<83;j++)
			printf("-");
	printf("\n\n\t\t\t\t\t Enter anything to continue -> ");
	getch();
}

void deleter()
{
	char b[10];
	int check=0;
	printf("\t\t\t\t\tHere is a list of medicines in our store\n\t\t\t\t\t");
	for(i=1;i<=nummed;i++)
	{
		printf("%-20s\t",med[i-1].medname);
		if(i%4==0)
		printf("\n\t\t\t\t\t");
	}
	printf("\n\n\n\t\t\t\t\tEnter the medicine to delete: ");
	scanf("%s",b);
	for(i=0;i<nummed;i++)
	{
		if(strcmp(med[i].medname,b)==0)
		{
			for(j=i;j<nummed;j++)
			{
				med[j]=med[j+1];
			}
			nummed--;
			check=1;
			printf("\n\t\t\t\t\tMedicine sucessfully deleted");
			break;
		}
	}
	if(check==0)
	{
		printf("\n\t\t\t\t\tMedicine not available in our store");
	}	
	printf("\n\n\t\t\t\t\t Enter anything to continue -> ");
	getch();
}

void edit()
{
	char b[20];
	int p=0;
	printf("\t\t\t\t\tHere is a list of medicines in our store\n\t\t\t\t\t");
	for(i=1;i<=nummed;i++)
	{
		printf("%-20s\t",med[i-1].medname);
		if(i%4==0)
		printf("\n\t\t\t\t\t");
	}
	printf("\n\n\t\t\t\t\tEnter the Medicine name to edit : ");
	scanf("%s",b);
	for(i=0;i<nummed;i++)
	{
		if(strcmp(med[i].medname,b)==0)
		{
			printf("\t\t\t\t\tThe medicine details :\n\t\t\t\t\t");
			for(j=0;j<77;j++)
			printf("-");
			printf("\n\t\t\t\t\t|%-20s|%-10s|%-5s|%-8s|%-10s|%-10s|%-6s|\n","med_name","address","box","quantity","Mfg date","exp date","price");
			printf("\t\t\t\t\t");
			for(j=0;j<77;j++)
				printf("-");
			printf("\n\t\t\t\t\t|%-20s|%-10s|%-5s|%-8d|%-10s|%-10s|%-6.2f|\n",med[i].medname,med[i].address,med[i].box,med[i].quantity,med[i].mdate,med[i].edate,med[i].price);
		printf("\t\t\t\t\t");
		for(j=0;j<77;j++)
		printf("-");
		printf("\n\t\t\t\t\tEnter the updates\n");
		printf("\t\t\t\t\tEnter medicine name:  ");
		scanf("%s",med[i].medname);
		
		printf("\t\t\t\t\tEnter medicine address: ");
		scanf("%s",med[i].address);
		
		printf("\t\t\t\t\tEnter medicine box:  ");
		scanf("%s",med[i].box);
		
		printf("\t\t\t\t\tEnter medicine quantity: ");
		scanf("%d",&med[i].quantity);
		
		printf("\t\t\t\t\tEnter medicine manufacturing date (MM/YY) : ");
		scanf("%s",med[i].mdate);
		
		printf("\t\t\t\t\tEnter medicine expiry date (MM/YY) : ");
		scanf("%s",med[i].edate);
		
		printf("\t\t\t\t\tEnter medicine price:  ");
		scanf("%f",&med[i].price);
		p=1;
		break;
		}
	}
	if(p==0)
	printf("\n\t\t\t\t\tMedicine not available in our store");
	printf("\n\n\t\t\t\t\t Enter anything to continue -> ");
	getch();
}

void updater()
{
	f1=fopen("medical.txt","w");
	for(i=0;i<nummed;i++)
	{
		if(med[i].quantity<=0)
		{
			continue;
		}
	fprintf(f1,"%-15s\t%-15s\t%-15s\t%-10d\t%-10s\t%-10s\t%-10.2f\n",med[i].medname,med[i].address,med[i].box,med[i].quantity,med[i].mdate,med[i].edate,med[i].price);
	}
	fclose(f1);
	f1=fopen("medical.txt","r");
	for(i=0;fscanf(f1,"%s%s%s%d%s%s%f",
	med[i].medname,med[i].address,med[i].box,&med[i].quantity,med[i].mdate,med[i].edate,&med[i].price)!=EOF;i++);
	nummed=i;
	fclose(f1);
}

void bill_updater()
{
	f1=fopen("medicalbill.txt","a");
	fprintf(f1,"\n%-15s\t%-20s\t%-5s\t%-5d\t%-15lld\t%-10.2f",cust.date,cust.name,cust.gender,cust.age,cust.number,cust.expenses);
	fclose(f1);
}

void sorter()
{
	struct medicine tab;
	int m,y,x[nummed],p;
	for(i=0;i<nummed;i++)
	x[i]=date_converter(med[i].edate);
	for(i=0;i<nummed;i++)
	for(j=i+1;j<nummed;j++)
	if(x[i]>x[j])
	{
		p = x[i];
		tab=med[i];
		x[i] = x[j];
		med[i]=med[j];
		x[j] = p;
		med[j]=tab;
	}
	see(2);
}

void name_sorter()
{
	struct medicine tab;
	for(i=0;i<nummed;i++)
	for(j=i+1;j<nummed;j++)
	if(strcmp(med[i].medname,med[j].medname)>0)
	{
		tab=med[i];
		med[i]=med[j];
		med[j]=tab;
	}
	printf("\n");
	see(3);
}
