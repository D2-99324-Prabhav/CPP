/*Q2. Write a menu driven program for Date in a CPP language using structure and also using class. 
Date is having data members day, month, year. Implement the following functions. 
void initDate(); 
void printDateOnConsole(); 
void acceptDateFromConsole(); 
bool isLeapYear();*/


#include<iostream>
using namespace std;

class Date{
    private:
   int date ;
   int month;
   int year;

   public:

void initDate(Date* ptrDate){
     
        ptrDate->date=10;
        ptrDate->month=05;
        ptrDate->year=2004;
}

void acceptDateFromConsole(Date* ptrDate)
{
          cout<<"Enter a date : "<<endl;
          cin>>ptrDate->date;
          cout<<"Enter a month : "<<endl;
          cin>>ptrDate->month;
          cout<<"Enter a year : "<<endl;
          cin>>ptrDate->year;
          
}
void printDateOnConsole(Date* ptrDate){
      
       cout<<"date : "<<ptrDate->date<<endl;
       cout<<"month: "<<ptrDate->month<<endl;
       cout<<"year : "<<ptrDate->year<<endl;
}
bool isLeapYear(Date* ptrDate){
    
    if(ptrDate->year%4==0 && ptrDate->year%100!=0 || ptrDate->year%400==0)
    {
        return true;
    }
    else{
        return false;
    }
}


int choice (){
int ch;
printf("0.Exit \n ");
printf("1.Enter a date \n ");
printf("2.Display a date \n ");
printf("3.current a date \n ");
printf("4.Check leap year \n ");
scanf("%d",&ch);
return ch;
}
};
int main(){
   Date date;
   int ch;
   while((ch=date.choice()) !=0){
    
   switch(ch){
        case 1:
       date.acceptDateFromConsole(&date);
          break;
        case 2: 
          date.printDateOnConsole(&date);
        break;
        case 3:
          date.initDate(&date);
         break;
         case 4:
            if(date.isLeapYear(&date)){
                cout<<"year is leap year"<<endl;
            }
            else{
                cout<<"year is not leap year"<<endl;
            }
      }
   }
   return 0;
}


