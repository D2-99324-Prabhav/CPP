/*Q2. Write a menu driven program for Date in a CPP language using structure and also using class.
Date is having data members day, month, year. Implement the following functions.
void initDate();
void printDateOnConsole();
void acceptDateFromConsole();
bool isLeapYear();*/

#include <iostream>

using namespace std;

struct Date{
   int date ;
   int month;
   int year;
};

void initDate(struct Date* ptrDate){

        ptrDate->date=10;
        ptrDate->month=5;
        ptrDate->year=2004;
}

void acceptDateFromConsole(struct Date* ptrDate)
{
          cout<<"Enter a date : ";
          cin>>ptrDate->date;
          cout<<"Enter a month :";
          cin>>ptrDate->month ;
          cout<<"Enter a year : ";
          cin>>ptrDate->year;

}
void printDateOnConsole(struct Date* ptrDate){

       cout<<"date : "<<ptrDate->date<<endl;
       cout<<"month : "<<ptrDate->month<<endl;
       cout<<"year : "<<ptrDate->year<<endl;
}
bool isLeapYear(struct Date* ptrDate){

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
cout<<"0.Exit \n ";
cout<<"1.Enter a date \n ";
cout<<"2.Display a date \n ";
cout<<"3.Initialize a date \n ";
cout<<"4.Check leap year \n ";
cin>>ch;
return ch;
}

int main(){
    struct Date date{};
   int ch;
   while((ch=choice()) !=0){

   switch(ch){
        case 1:
          acceptDateFromConsole(&date);
          break;
        case 2:
          printDateOnConsole(&date);
        break;
        case 3:
          initDate(&date);
         break;
         case 4:
             if(isLeapYear(&date)){
                 cout<<"year is leap year\n";
             }
             else{
                 cout<<"year is not leap year\n";
             }
             break;
        default:
             cout << "Invalid choice\n";
      }





}


}
