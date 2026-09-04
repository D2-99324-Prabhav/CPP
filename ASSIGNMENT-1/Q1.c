
/*Q1. Write a menu driven program for Date in a C. Declare a structure Date having data members 
day, month, year. Implement the following functions. 
void initDate(struct Date* ptrDate); 
void printDateOnConsole(struct Date* ptrDate); 
void acceptDateFromConsole(struct Date* ptrDate); */

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
      }
          
          
         

    
}

        
}



