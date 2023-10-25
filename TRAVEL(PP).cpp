#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

int BookNum = 0; //Variable to count the number of bookings.
class Package
{
	//Details of the package.
	public:
	char Country[40];
	int CNo;
	int Duration;
	int Package_price;
		void Display();
		friend class Customer;
		Package()
		{
			
		}
};

class Customer
{
	//Details of the Customer.
	public:
		char FName[60]; 
		char LName[60];
		string Mobile;
		char Email[30];
		int j;
		Customer()
		{
			
		}
		
		//Personal details and contact info to initiate booking process.
		void booking(Package x)
		{
			cout<<" Enter First Name: ";
            cin>>FName;
            cout<<" Enter Last Name: ";
            cin>>LName;
            mob: cout<<" Enter Mobile Number: ";
            cin>>Mobile;
            //Condition for validity if indian mobile numbers only.
            if (Mobile.length() != 10)
            {
            	cout<<" Please enter valid a mobile number!"<<endl;
            	goto mob;
			}
            cout<<" Enter Email ID: ";
            cin>>Email;	
		}
		
		//Calcualating the total package cost of the trip
		void bill(int cno, int duration, int price)
		{
			int total = price*duration;
			cout<<" The total cost for the trip is: "<<total<<endl<<endl;
			cout<<" PRESS ANY KEY TO RETURN TO MENU ";
			getch();
			system("CLS");
		}
		void cancel();
};

//class details is inherited from Customer and Package classes
class details : public Customer,public Package
{
	public:
		void record();
		friend ostream &operator<<(ostream &out, details &x);
}Cust[200]; //Maximum 200 bookings possible

//ostream overloading to print the customer details
ostream &operator<<(ostream &out, details &x)
{
	out<<endl;
	out<<" Name: "<<x.FName<<" "<<x.LName<<endl;
	out<<" Mobile: "<<dec<<x.Mobile<<endl;
	out<<" Email ID: "<<x.Email<<endl;
	out<<" Destination: "<<x.Country<<endl;
	out<<" Package Duration: "<<x.Duration<<" Days "<<x.Duration-1<<" Nights"<<endl;
	out<<" Package cost: Rs "<<x.Package_price*x.Duration<<endl;
	return out;
}

//Package details like countries and price are mentioned here.
void Package::Display()
{
	Customer x;
	string ctry[] = {"Australia", "France", "Switzerland", "Singapore", "Canada", "Japan"};
	int price[] = {10000, 9000, 7500, 7000, 9500, 8000};
	cout<<resetiosflags(ios::left)<<endl<<setfill('*')<<setw(24)<<" PACKAGE DETAILS "<<setw(7)<<""<<endl;
	cout.fill(' ');
	cout<<setiosflags(ios::left)<<setw(8)<<" S.No"<<setw(15)<<"Country"<<"Price per day"<<endl;
	for(int i = 0; i < 6; i++)
	{
		cout<<"  "<<setw(6)<<i+1<<setw(18)<<ctry[i]<<price[i]<<endl;
	}
	num: cout<<" Enter number corresponding to the desired country: ";
    cin>>CNo;
    if (CNo < 1 || CNo > 6)
	{
		cout<<" Please enter valid a number!"<<endl;
		goto num;
	}
    cout<<" Enter days of stay: ";
    cin>>Duration;
    cout<<" Booking successful!"<<endl<<endl;
    int i = CNo - 1;
    //To print the final cost using bill function
    x.bill(CNo, Duration, price[i]);
    Package_price = price[i];
    strcpy(Country, ctry[i].c_str());
}

//Prints the records of all existing bookings.
 void details::record()
{
	cout<<resetiosflags(ios::left)<<endl<<setfill('*')<<setw(23)<<" CUSTOMER DETAILS "<<setw(5)<<""<<endl;
	for(j=0; j < BookNum ;j++)
	{
		cout<<" CUSTOMER "<<j+1<<Cust[j]<<endl;
	}
	cout<<" PRESS ANY KEY TO RETURN TO MENU ";
	getch();
	system("CLS");
}

//To cancel the necessary bookings as per the customer
inline void Customer::cancel()
{
	int i;
	int x;
	HERE: cout<<" Total number of customers: "<<j<<endl;
	cout<<" Enter Customer number of the booking you wish to cancel: ";
	cin>>x;
	if(x<0 || x>j)
	{
		cout<<" Cancellation Failed!"<<endl<<" Enter a valid customer number!"<<endl;
		goto HERE;
	}
	else
	{
		for(i=x;i<j;i++)
		{
			Cust[i-1]=Cust[i];
			strcpy(Cust[i].FName, ""); 
			strcpy(Cust[i].LName, ""); 
			Cust[i].Mobile = '\0';       
			strcpy(Cust[i].Email, "");	
		}
		cout<<" Cancellation Done!"<<endl;
	}
	//Method to clear screen and return to menu afer performing an action
	cout<<" PRESS ANY KEY TO RETURN TO MENU ";
	getch();
	system("CLS");
}

int main()
{
	Package x;
	int choice;
	LOOP: 
	cout<<resetiosflags(ios::left)<<endl<<setfill('*')<<setw(19)<<" SYMBI AGENCY "<<setw(5)<<""<<endl;
	cout<<"\n Select the action you wish to perform: "<<endl;
	cout<<" 1. Book a ticket"<<endl;
	cout<<" 2. View Records"<<endl;
	cout<<" 3. Cancel Booking"<<endl;
	cout<<" 4. Exit"<<endl;
	cout<<" Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			//Booking
			Cust[BookNum].booking(x);
			Cust[BookNum].Display();
			//Every time a booking is carried out the count is incremented by 1
			BookNum++;
			goto LOOP;
			break;
			
		case 2:
			//Details
			Cust[BookNum].record();
			goto LOOP;
			break;
			
		case 3:
			//Cancellation
			Cust[BookNum].cancel();
			//Every time a booking is cancelled the count is decremented by 1
			BookNum--;
			goto LOOP;
			break;
			
		case 4:
			//Exit the program
			cout<<endl<<" THANK YOU FOR USING OUR SERVICES!"<<endl<<" PLEASE VISIT AGAIN!"<<endl;
			exit(0);
			break;
			
		default:
			//Any other input
			cout<<"\n Invaid Input!";
			cout<<"\n Please enter a number between 1 and 4!"<<endl;
			goto LOOP;
	}
	return 0;
}
