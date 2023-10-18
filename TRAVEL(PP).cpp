#include<bits/stdc++.h>
using namespace std;

class Package
{
	int Country;
	int Duration;
	int Package_price;
	public:
		void Display();
		friend class Customer;
		Package()
		{
			
		}
		Package(int country, int dur, int price)
		{
			Country = country;
			Duration = dur;
			Package_price = price;
		}
};

class Customer
{
	public:
		char Name[60]; 
		int Mobile;
		char Email[30];
		int j;
		Customer()
		{
			
		}
		void booking(Package x)
		{
			cout<<" Enter Name: ";
            cin>>Name;
            cout<<" Enter Mobile Number: ";
            cin>>Mobile;
            cout<<" Enter Email ID: ";
            cin>>Email;
            cout<<endl;
			x.Display();
		}
		void bill(int Country, int Duration, int Price)
		{
			Package x;
			int total = Price*Duration;
			cout<<" The total cost for the trip is: "<<total<<endl;
		}
		void cancel();
};

class details : public Customer
{
	public:
		int i;
		void record();
}Cust[200];

inline void Package::Display()
{
	Customer x;
	string ctry[] = {"Australia", "France", "Switzerland", "Singapore", "Canada", "Japan"};
	int price[] = {10000, 9000, 7500, 7000, 9500, 8000};
	cout.fill(' ');
	cout<<setiosflags(ios::left)<<setw(8)<<" S.No"<<setw(15)<<"Country"<<"Price per day"<<endl;
	for(int i = 0; i < 6; i++)
	{
		cout<<"  "<<setw(6)<<i+1<<setw(18)<<ctry[i]<<price[i]<<endl;
	}
	cout<<" Enter number corresponding to the desired country: ";
    cin>>Country;
    cout<<" Enter days of stay: ";
    cin>>Duration;
    cout<<" Booking successful!"<<endl;
    int i = Country - 1;
    x.bill(Country, Duration, price[i]);
}

 void details::record()
{
	for(j=0; Cust[j].Mobile != '\0';j++)
	{
		cout<<"The Name of Customer "<<j+1<<": "<<Cust[j].Name<<endl;
		cout<<"The Mobile number of Customer "<<j+1<<": "<<Cust[j].Mobile<<endl;
		cout<<"The Email of Customer "<<j+1<<": "<<Cust[j].Email<<endl;
	}
}

inline void Customer::cancel()
{
	int i;
	int x;
	cout<<" Enter Customer number of the booking you wish to cancel: ";
	cin>>x;
	for(i=x;i<j;i++)
	{
		Cust[i-1]=Cust[i];
		strcpy(Cust[i].Name, "");  
		Cust[i].Mobile = 0;       
		strcpy(Cust[i].Email, "");	
	}
	cout<<"Cancellation Done!"<<endl;
		
}

int main()
{
	int counter;
	Package x;
	int choice, j=0;
	LOOP: cout<<resetiosflags(ios::left)<<endl<<setfill('*')<<setw(18)<<"SYMBI AGENCY"<<setw(6)<<""<<endl;
	cout<<"\n Select the action you wish to perform: "<<endl;
	cout<<" 1. Book a ticket"<<endl<<" 2. View Records"<<endl<<" 3. Cancel Booking"<<endl<<" 4. Exit"<<endl;
	cout<<" Enter you choice: ";
	cin>>choice;
	switch (choice)
		{
			case 1:
				Cust[j].booking(x);
				j++;
				goto LOOP;
				break;
			case 2:
				Cust[j].record();
				cout<<"number of customers: "<<j;
				goto LOOP;
				break;
			case 3:
				Cust[j].cancel();
				j--;
				goto LOOP;
				break;
			case 4:
			{
				exit(0);
				break;
			}
			default:
				cout<<"\n Invaid Input!";
				cout<<"\n Please enter a number between 1 and 4!"<<endl;
				goto LOOP;
		}
}
