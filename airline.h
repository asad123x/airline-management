#include<iostream>
#include<conio.h> 
#include<string.h> 
#include<dos.h> 
#include<stdio.h> 
#include<fstream> 
#include<process.h> 
#include<stdlib.h>
#include<systemtopologyapi.h>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#include<time.h>
using namespace std;
void Box(string  ,int,int =0 );
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void Request();

void gotoxy(int x, int y) ;
class AIRLINE;

class AIRLINE {
private:
	int AIRLINEum, PremiumSeat, EconomySeat;
	char AIRLINEname[60], startingpoint[60], destination[60];
public:
	AIRLINE();
	void input();        	//To input
	int GetAIRLINENumber()const;
	int GetEconomyseats()const;//int returnaf();
	int GetPremiumSeats()const ;
	friend ostream & operator << (ostream & out,const AIRLINE & obj);
};
AIRLINE tr;
ostream & operator << (ostream & out,const AIRLINE & obj);
class tickets
{
	int ReservationNumber;
	int  TotalPremiumSeats, PremiumSeat, TotalEconomySeats, EconomySeat,age;
	char status[40], name[40];
public:
	tickets();
	int ret();
	void calculatefare();	
	void reservation();	//For ticket reservation
	void cancellation();        //For ticket cancellation int ret();
	friend ostream & operator <<(ostream & out, const tickets ti);	//To DisplayList reservation details
	friend void showComp(tickets);
}tick;

ostream & operator <<(ostream & out, const tickets ti);

class Bill
{
	protected:
	double totalCost;
	public:
	template <class T>
	void CalcBill();
	void setZero();
	void DispBill();
} bil;

class economy:public tickets
{
	float cost;
	public:
		void calculatefare();
		float showCost();
};

class premium:public tickets
{
	float cost;
	public:
		void calculatefare();
		float  showCost();
};
void DisplayList();
class SEAT
{
	tickets tic[4];
	public:
		void book();
		void showC();
} comp;
void showComp(tickets t);
void gotoxy(double x, double y) ;
void Box(string z,int x1,int defaultsize);

