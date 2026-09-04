/*Q2. Write a menu driven program for Date in a CPP language using structure and also using class. 
Date is having data members day, month, year. Implement the following functions. 
void initDate(); 
void printDateOnConsole(); 
void acceptDateFromConsole(); 
bool isLeapYear();*/

#include<stdio.h>

struct Date{
   int date ;
   int month;
   int year;
};

void initDate(struct Date* ptrDate){
     
        ptrDate->date=10;
        ptrDate->month=05;
        ptrDate->year=2004;
}

void acceptDateFromConsole(struct Date* ptrDate)
{
          printf("Enter a date : ");
          scanf("%d",&ptrDate->date);
          printf("Enter a mont :");
          scanf("%d",&ptrDate->month );
          printf("Enter a year : ");
          scanf("%d",&ptrDate->year);
          
}
void printDateOnConsole(struct Date* ptrDate){
      
       printf("date : %d \n",ptrDate->date);
       printf("month: %d \n",ptrDate->month);
       printf("year : %d \n",ptrDate->year);
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
printf("0.Exit \n ");
printf("1.Enter a date \n ");
printf("2.Display a date \n ");
printf("3.current a date \n ");
scanf("%d",&ch);
return ch;
}

int main(){
   struct Date date;
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
                 printf("year is leap year\n");
             }
             else{
                 printf("year is not leap year\n");
             }
      }
          
          
         

    
}

        
}



