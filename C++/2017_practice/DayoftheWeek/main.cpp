#include<iostream>
using namespace std;

bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int month,int year);
void output(int remainder);
int main(void)
{
	int year,month,day;
	while(cin>>year>>month>>day)
	{
		output((day+getMonthValue(month,year)+getYearValue(year)+getCenturyValue(year))%7);
	}
	return 0;
}





bool isLeapYear(int year)
{
	if((year % 400 ==0) || ((year%4 ==0) && (year%100 !=100)))
		return true;
	else 
		return false;
}

int getCenturyValue(int year)
{
	int temp;
	temp=year%100;
	temp=(year-temp)/100;
	temp=temp%4;
	temp=3-temp;
	return temp*2;
}

int getYearValue(int year)
{
	int temp;
	temp=year%100;
	return temp+(temp/4); 

}

int getMonthValue(int month,int year)
{
	if((month==1 &&isLeapYear(year))||month==4||month==7)
		return 6;
	if((month==1 && !isLeapYear(year))||month==10)
		return 0;
	if(month==5)
		return 1;
	if((month==2 && isLeapYear(year))||month==8)
		return 2;
	if((month==2 && !isLeapYear(year))||month==3||month==11)
		return 3;
	if(month==6)
		return 4;
	if(month==9||month==12)
		return 5;

}

void output(int remainder)
{
	switch(remainder)
	{
		case 0: cout<<"Sunday"<<endl; break;
		case 1: cout<<"Monday"<<endl; break;
		case 2: cout<<"Tuesday"<<endl; break;
		case 3: cout<<"Wednesday"<<endl; break;
		case 4: cout<<"Thursday"<<endl; break;
		case 5: cout<<"Friday"<<endl; break;
		case 6: cout<<"Saturday"<<endl; break;
	}
	return;
}
