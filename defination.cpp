#include"airline.h"

using namespace std;

void gotoxy(int x, int y)  //To Set the text Position On console
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}


AIRLINE::	AIRLINE()
	{
		AIRLINEum=0;
		PremiumSeat=0;
		EconomySeat=0;
		strcpy(AIRLINEname, "/0");
		strcpy(startingpoint, "/0");
		strcpy(destination, "/0");
	}
int AIRLINE:: GetAIRLINENumber()const
	{
		return AIRLINEum;
	}		
int AIRLINE::GetPremiumSeats()const
	{
		return PremiumSeat;
	}
int AIRLINE::GetEconomyseats()const {
		return EconomySeat;
	}

	
ostream & operator << (ostream & out,const AIRLINE & obj)						//OPERATOR OVERLOADING
{
	system("cls");
	gotoxy(10, 10);
	out << "AIRLINE NUMBER "; 
	gotoxy(47, 10);
	out << obj.AIRLINEum;
	gotoxy(10, 12); 
	out << "AIRLINE NAME "; 
	gotoxy(47, 12);
	puts(obj.AIRLINEname);
	gotoxy(10, 14);
	out << "NO OF PREMIUM SEATS ";
	gotoxy(47, 14);
	out << obj.PremiumSeat;
	gotoxy(10, 16);
	out << "NO OF ECONOMY SEATS ";
	gotoxy(47, 16);
	out << obj.EconomySeat;
	gotoxy(10, 18);
	out<<"STARTING POINT ";
	gotoxy(47, 18);
	out<<obj.startingpoint;
	gotoxy(10, 20);
	out<<"DESTINATION  ";
	gotoxy(47, 20);
	out<<obj.destination;
	gotoxy(10,24);
	out << "PRESS ANY KEY TO CONTINUE ";
	
	getch();	
}
void AIRLINE::input()
{
	system("CLS");
	Box("ENTER THE AIRLINE NUMBER: ",0);
    gotoxy(45, 3);
	cin>>AIRLINEum;
	Box("ENTER THE NUMBER OF PREMIUM SEATS : ",5,20);
	gotoxy(65, 8);
	cin >> PremiumSeat; 
	Box("ENTER THE NUMBER OF ECONOMY SEATS : ",10,25);
	gotoxy(65, 13);
	cin >> EconomySeat;
	Box("ENTER THE AIRLINE NAME",15,25);
	gotoxy(45,18);
	cin>>AIRLINEname;
	Box("ENTER THE STARTING POINT",20,20);
	gotoxy(50,23);
	cin>>startingpoint;
	Box("ENTER DESTINATION",25,20);
	gotoxy(45,28);
	cin>>destination;
}


tickets::tickets() 
	{
		srand(time(NULL));
		ReservationNumber = rand()%1000;
		TotalPremiumSeats = 0;
		PremiumSeat = 0;
		TotalEconomySeats = 0;
		EconomySeat = 0;
		age = 0;
		strcpy(status, "/0"); strcpy(name, "/0");
	}
	int tickets:: ret()
	{
		return ReservationNumber;
	}
	void tickets::calculatefare()
	{
	}
void Request();	
ostream & operator <<(ostream & out, const tickets ti)						//OPERATOR OVERLOADING
{
	int retry=1, f = 0; system("cls");;
	ifstream fn("Ticket1.txt", ios::out); fn.seekg(0);
	if (!fn)
	{
		cout << "ERROR IN THE FILE ";
	}
    while(retry)
    {
	gotoxy(10, 10);
	cout << "ENTER THE RESERVATION NO "; gotoxy(10, 12);
	int n; cin >> n;
	while (!fn.eof())
	{
		fn.read((char*)&tick, sizeof(tick));
		gotoxy(10, 10);
		if (n == tick.ReservationNumber)
		{
			system("CLS");
			f = 1;
			gotoxy(10, 10);
			cout<<"NAME "; 
			gotoxy(30, 10); 
			cout << tick.name; 
			gotoxy(10, 12);
			cout << "AGE "; 
			gotoxy(30, 12);
			cout << tick.age;
			gotoxy(10, 14);
			cout << "PRESENT STATUS ";
			gotoxy(30, 14);
			cout << tick.status; gotoxy(10, 16);
			cout << "RESERVATION NUMBER ";
			gotoxy(30, 16);
			cout << tick.ReservationNumber;
			gotoxy(10, 18);
			cout << "PRESS ANY KEY TO CONTINUE ";
			getch();
			Request();
		}
	}
	if (f == 0)
	{
		system("CLS");
		gotoxy(10, 10);
		cout << "UNRECOGINIZED RESERVATION NO !!! WANNA RETRY ?(Y/N) "; char a;
		gotoxy(10, 12);
		cin >> a;
		if (a == 'y' || a == 'Y')
		{
			
			system("cls");
			
		}
		else
		{
			retry=0;
			gotoxy(10, 12);
			cout << "PRESS ANY KEY TO CONTINUE"; 
			getch();
		}
	}
	fn.close();
	}
	return out;
}


	template <class T>
	void Bill::CalcBill()													//TEMPLATE USED
	{
		T t;
		totalCost+=t.showCost();
	}
	
	void Bill::setZero()
	{
		totalCost;
	}
	void Bill::DispBill()
	{
		system("cls");
		Box("YOUR BILL: \n",0); 
		gotoxy(32, 3);
		cout<<totalCost;
		getch();
	}
	void economy::calculatefare()
	{		cost=300;
			cout<<endl<<endl<<"\t  YOUR FARE: "<<cost<<endl;
	}
		
	float economy::showCost()
	{
			return cost;
	}

	void premium::calculatefare()
	{
		cost=500;
		cout<<endl<<endl<<"\t  YOUR FARE: "<<cost<<endl;
	}
	float  premium::showCost()
	{
		return cost;
	}


void tickets::reservation()
{
	system("cls");;
	gotoxy(10, 10); cout << "RESERVATION "; 
	gotoxy(10, 12);
	cout << "ENTER THE AIRLINE NO: ";
	int AIRLINENo, f = 0; cin >> AIRLINENo;
	ofstream file;
	ifstream fin("AIRLINE1.txt", ios::out); 
	fin.seekg(0);
	
	{
		system("cls");
		gotoxy(10, 10); cout<<"ERROR IN THE FILE ";
		system("cls");
		while (!fin.eof())
		{
			fin.read((char*)&tr, sizeof(tr));
			int z;
			z = tr.GetAIRLINENumber();
			if (AIRLINENo == z)
			{
				f = 1;
				PremiumSeat = tr.GetPremiumSeats();
				EconomySeat = tr.GetEconomyseats();
			}
		}
		if (f == 1)
		{
			file.open("Ticket1.txt", ios::app);
			system("cls");;
			gotoxy(10, 10);
			Box("NAME:",0);
			gotoxy(30, 3);
			cin>>name;
			Box("AGE:",5);
			gotoxy(30, 8);
			cin >> age; 
			system("cls");;
			gotoxy(10, 10);
			cout << "SELECT THE CLASS WHICH YOU WISH TO TRAVEL"; 
			gotoxy(10, 12);
			cout << "1. PREMIUM "; 
			gotoxy(10, 14);
			cout << "2. ECONOMY ";
			gotoxy(10, 16);
			cout << "ENTER YOUR CHOICE "; 
			gotoxy(30, 22);
			int c;
			cin >> c;
			switch (c)
			{
			case 1:
				TotalPremiumSeats++;
				ReservationNumber = rand()%1000;
//				ReservationNumber++;
				if ((PremiumSeat - TotalPremiumSeats)>0)
				{
					strcpy(status, "confirmed");
					gotoxy(10, 24);
					cout << "STATUS";
					gotoxy(30, 24);
					puts(status);
					gotoxy(10, 26);
					cout << "RESERVATION NO";
					gotoxy(30, 26);
					cout << ReservationNumber;
					
					
					premium *pr=(premium*)&tick;                		//POLYMERISTAION:Down casting
					
					
					pr->calculatefare();
					bil.CalcBill<premium>();
					getch();
					file.write((char*)&tick, sizeof(tick)); 
					
					break;
					strcpy(status, "pending");
					gotoxy(10, 24);
					cout << "STATUS";
					gotoxy(30, 24);
					puts(status);
					gotoxy(10, 26);
					cout << "RESERVATION NO";
					gotoxy(30, 26);
					cout << ReservationNumber;
					
					
					premium *pro=(premium*)&tick;						//POLYMERISTAION:Down casting
					pro->calculatefare();
					bil.CalcBill<premium>();
	
					getch();
					file.write((char*)&tick, sizeof(tick));
	 
					break;
				}
			case 2:
				TotalEconomySeats++;
				ReservationNumber = rand()%1000;
//				ReservationNumber++;
				if ((EconomySeat - TotalEconomySeats)>0)
				{
					strcpy(status, "confirmed");
					gotoxy(10, 24);
					cout << "STATUS";
					gotoxy(30, 24);
					puts(status);
					gotoxy(10, 26);
					cout << "RESERVATION NO";
					gotoxy(30, 26);
					cout << ReservationNumber;
					
					economy *ec=(economy*)&tick;						//POLYMERISTAION:Down casting
					ec->calculatefare();
					bil.CalcBill<economy>();
					getch();
					file.write((char*)&tick, sizeof(tick));
					break;
				}
				else
				{	
					strcpy(status, "pending");
					gotoxy(10, 24);
					cout << "STATUS";
					gotoxy(30, 24);
					puts(status);
					gotoxy(10, 26);
					cout << "RESERVATION NO";
					gotoxy(30, 26);
					cout << ReservationNumber;
					
					economy *eco=(economy*)&tick;						//POLYMERISTAION:Down casting
					eco->calculatefare();
					bil.CalcBill<economy>();
					getch();
					file.write((char*)&tick,sizeof(tick)); 
					
					break;
				}
				}
		}
		}

	if (f == 0)
	{
		system("CLS");
		gotoxy(10, 10);
		cout<<"ERROR IN THE AIRLINE NUMBER ENTERED !!!"; 
		getch();
	}
	file.close();
}

void tickets::cancellation()
{
	system("cls"); 
	ifstream fin;
	fin.open("Ticket1.txt", ios::out);
	ofstream file;
	file.open("Temp1.txt", ios::app);
	fin.seekg(0);
	gotoxy(10, 10);
	cout << "ENTER THE RESERVATION NO ";
	int r, f = 0;
	cin >> r;
	if (!fin)
	{
		cout<<"ERROR IN THE FILE !!!";
	}
	while (!fin.eof())
	{
		fin.read((char*)&tick, sizeof(tick)); 
		int z;
		z = ret(); if (z != r)
		{
			file.write((char*)&tick, sizeof(tick));
		}
		if (z == r) 
		{
			f = 1;
		}
	}
	file.close();
	fin.close();
	remove("Ticket1.txt"); 
	rename("Temp1.txt", "Ticket1.txt");
	if (f == 0)
	{
		gotoxy(10, 12);
		cout << "NO SUCH RESERVATION IS MADE !!! PLEASERETRY	";
		getch();
	
	}
	else
	{
		gotoxy(10, 12);
		cout << "RESERVATION CANCELLED"; 
		getch();
	}
}
void DisplayList()
{
	system("cls");; gotoxy(25, 8);
	Box("PAKISTAN AIRLINES\n",0); 
	gotoxy(10, 2);
    //Box("==========================",10.0,30.0,3.0);
	gotoxy(20, 15); 
	Box("1.AIRLINE AVAILABLE",3);
	gotoxy(20, 17);
	Box( "2.ADD NEW AIRLINE",6);
	gotoxy(20, 19);
	Box("3.BOOK A SEAT ",9);
	gotoxy(20, 21);
	Box("4.RESERVE A SINGLE TICKET ",12);
	gotoxy(20, 23);
	Box( "5.CANCEL A TICKET",15);
	gotoxy(20, 25);
	Box("6.VIEW MY TICKET ",18);
	gotoxy(20, 27);
	Box("7.VIEW MY COMPATMENT ",21);
	gotoxy(20, 27);
	Box("8.EXIT",24);
	gotoxy(20, 28);
	
	
	cout << "\nENTER YOUR CHOICE: ";
}
		void SEAT:: book()
		{
		tic[0].reservation();
		tic[1].reservation();
		tic[2].reservation();
		tic[3].reservation();
		}
		void SEAT::showC()
	{
	
		for(int i=0;i<4;i++)
		{
			showComp(tic[i]);
		}
	}
	

void showComp(tickets t)
{
	system("CLS");
			
			gotoxy(10, 10);
			cout<<"NAME "; 
			gotoxy(30, 10); 
			cout << t.name; 
			gotoxy(10, 12);
			cout << "AGE "; 
			gotoxy(30, 12);
			cout << t.age;
			gotoxy(10, 14);
			cout << "PRESENT STATUS ";
			gotoxy(30, 14);
			cout << t.status; gotoxy(10, 16);
			cout << "RESERVATION NUMBER ";
			gotoxy(30, 16);
			cout << t.ReservationNumber;
			gotoxy(10, 18);
			cout << "PRESS ANY KEY TO CONTINUE ";
			getch();
}


void Request()
{

	int ch,n, r = 1000, pass;
	system("cls");	
    DisplayList();
	cin >> ch;
	switch (ch)
	{
	case 1:
	{ 
		ifstream fin("AIRLINE1.txt", ios::out);
		fin.seekg(0);
		system("cls");;
		if (!fin)
		{
			system("cls");;
			gotoxy(10, 10);
			cout<<"ERROR IN THE FILE !!!";
		}
		else 
		{
			system("cls");;
			while (!fin.eof()) 
			{
				fin.read((char*)&tr, sizeof(tr)); 
				cout<<tr;
			}
		}
		fin.close();
		Request();
		}
	case 2:
		system("cls");
		
		Box("ENTER THE PASSWORD: ",0);
		gotoxy(40, 3);
		cin >> pass;
		//gotoxy(20, 30);
		if(pass==1234)
		{
			getch();
		
			
			char y='n';
			//while(y!='n'||y!='N'){
				ofstream fout("AIRLINE1.txt", ios::app); 
				tr.input();
				fout.write((char*)&tr, sizeof(tr));
				fout.close();
				gotoxy(10, 30);
				//cout << "DO YOU WISH TO CONTINUE UPDATING ?(Y/N)";
				//cin >> y;
				getch();

					//Request();
					Request();
				}
				
			//}

		
		else
		{
			cout<<"Wrong Password";
			for(int i=0;i<1000000000;i++)
			{
				
			}
				Request();
		}
		
	case 3:
		bil.setZero();
		comp.book();	
		system("cls");
		bil.DispBill();
		Request();
	case 4:
		bil.setZero();
		tick.reservation(); 
		bil.DispBill();
		Request();
	case 5:
		tick.cancellation(); 
		Request();

	case 6:
		cout<<tick;
		Request();;
	case 7:
		comp.showC();
		Request();
		
	case 8:
		exit(0);
		getch();

	}
}
void gotoxy(short  x, short y) 
{ 
	static HANDLE h = NULL; 
	if(!h) h = GetStdHandle(STD_OUTPUT_HANDLE); 
		COORD c = { x, y }; 
	SetConsoleCursorPosition(h,c); 
}
void Box(string z,int x1,int defaultsize)
{
	int x,y,l,h,n;
	x=20;y=2;l=30+defaultsize;h=2;
	gotoxy(x,y+x1);
	printf("%c",218);
	
	gotoxy(x+l,y+x1);
	printf("%c",191);
	gotoxy(x,y+h+x1);
	printf("%c",192);
	gotoxy(x+l,y+h+x1);
	printf("%c",217);
	for(n=1;n<l;n++)
	{
		gotoxy(x+n,y+x1);
		printf("%c",196);
		gotoxy(x+n,y+h+x1);
		printf("%c",196);
	}
		for(n=1;n<h;n++)
	{
		gotoxy(x,y+n+x1);
		printf("%c",179);
	}
		cout<<z;
	for(n=1;n<h;n++)
	{
		gotoxy(x+l,y+n+x1);
		printf("%c",179);
	}
	
	gotoxy(39,12);

}

