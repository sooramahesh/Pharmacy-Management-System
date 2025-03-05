//save this file as bill.h 
#ifndef BILL_H
#define BILL_H
struct customers {
	char name[20];
	int age;
	char gender[10];
	long long int number;
	float expenses;
	char date[15];
};
struct medicine
{
	char medname[20];
	char address[20];
	char box[20];
	int quantity;
	char mdate[10];
	char edate[10];
	float price;
};
void updater();
void deleter();
void sorter();
void update();
void see(int);
void search();
void display();
void design(int);
void edit();
void bill_updater();
void new_date();
void customer();
void customer_details();
void management();
void name_sorter();
extern void report(struct customers *cust);
void show_expiry();
int date_converter(char []);
#endif
