/*Q1. Write a menu driven program to calculate volume of the box(length * width * height). 
Provide parameterless, parameterized(with 3 parameters) and single paramaterized constructor. 
Create the local objects in respective case and call the function to caluclate area. 
Menu options ->  
1. Calculate Volume with default values 
2. Calculate Volume with length,breadth and height with same value 
3. Calculate Volume with different length,breadth and height values.*/

#include<iostream>
using namespace std;

class Volume
{
    private:
    float length;
    float breath;
    float height;

    public:
    Volume()
    {
        this->length = 1;
        this->breath = 4;
        this->height = 7;
    }

    Volume(float length)
    {   
        this->length = length;
    }

    Volume(float length, float breath, float height)
    {
        this->length = length;
        this->breath = breath;
        this->height = height;
    }

    float volumeWithDefault()
    {
        float result;
        result = this->length * this->breath * this->height;
        return result;
    }

    float volumeEithSameValue(float length)
    {
        float result;
        result = length * length * length;
        return result;
    }

    float volumeWithParameter(float length, float breath, float height)
    {
        float result;
        result = length * breath * height;
        return result;
    }

    int menuList()
    {
        int choice;
        cout<<"0.Exit"<<endl;
        cout<<"1.Calculate Volume with default values"<<endl;
        cout<<"2.Calculate Volume with length,breadth and height with same value"<<endl;
        cout<<"3.Calculate Volume with different length,breadth and height values"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        return choice;
    }
};

int main()
{
    Volume v1;
    int choice;

    int l, b, h;

    while ((choice=v1.menuList()) != 0)
    {
       switch (choice)
       {
       case 1:
            cout<<"Volume : "<<v1.volumeWithDefault()<<endl;
            
            break;
       
        case 2:
            cout<<"Enter Length : ";
            cin>>l;
            cout<<"Volume : "<<v1.volumeEithSameValue(l)<<endl;
            break;

        case 3:
            cout<<"Enter Length, breath, height : ";
            cin>>l>>b>>h;
            cout<<"Volume : "<<v1.volumeWithParameter(l,b,h)<<endl;
            break;
       }
    }
    
    return 0;
}



