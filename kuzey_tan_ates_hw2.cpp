#include<iostream>
using namespace std;
class Hours{
	public:
		int hour,minutes;
		
		friend ostream &operator << (ostream &output, Hours &h);
		friend istream &operator >> (istream &input, Hours &h);
		
};
ostream &operator << (ostream &output, Hours &h){
	output << h.hour<<":"<<h.minutes;
	return output;
}
istream &operator >> (istream &input, Hours &h){
	input >> h.hour >> h.minutes;
	return input;
}

class Animals{
	protected:
		string id,animalName,ownerName,ownerSurname;
		Hours totalHours;
		int totalMins;
	public:
		Animals(string i,string an,string on, string os){
			id=i;
			animalName=an;
			ownerName=on;
			ownerSurname=os;
			}
		int calculateMinutes(Hours checkIn, Hours checkOut){
			if(checkIn.hour<checkOut.hour && checkIn.minutes<checkOut.minutes){
				return (checkOut.hour-checkIn.hour)*60+(checkOut.minutes-checkIn.minutes);
			}
			else if(checkOut.hour>=checkIn.hour && checkOut.minutes<checkIn.minutes){
				return ((checkOut.hour-1)-checkIn.hour)*60+((checkOut.minutes+60)-checkIn.minutes );
			}
			else{
				cout<<"Please enter appropriate time."<<endl;
				return 0;
			}
			
		}	
};

class Cat: public Animals{
	protected:
		string type;
	public:
	Cat(string t,string i,string an,string on, string os):Animals(i,an,on,os){
		type=t;
	}	
	void printInfo(){
		cout<<"Id of the animal is "<<id<<endl<<"Name of the animal is "<<animalName<<endl<<"Name of the animal's owner is "<<ownerName<<endl<<"Surname of the animals owner is "<<ownerSurname<<endl<<"Type of the animal is "<<type<<endl;
	}	
	
};
int main(){
	Cat obj1("Cat","123456","Goofy","Kobe","Bryant");
	obj1.printInfo();
	Hours checkIn,checkOut;
	cout<<"Enter the check in time of the animal : "<<endl;
	cin>>checkIn;
	cout<<"Enter the check out time of the animal : "<<endl;
	cin>>checkOut;
	cout<<"Check in and check out times are "<<checkIn<<"/"<<checkOut<<endl;
	if(obj1.calculateMinutes(checkIn,checkOut)){	
	cout<<"The total time animal stays in the clinic is "<<obj1.calculateMinutes(checkIn,checkOut)<<" minutes";
}
	return 0;}
