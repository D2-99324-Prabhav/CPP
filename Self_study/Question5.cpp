#include<iostream>
using namespace std;

int myStrlen(const char *str)
{
    int count = 0;
    while (str[count] != '\0')
        count++;
    return count;
}

void myStrcpy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main()
{
    char source[100];
    cout << "Enter string : ";
    cin >> source;

    cout << "Length : " << myStrlen(source) << endl;

    char dest[100];
    myStrcpy(dest, source);
    cout << "Copied string : " << dest << endl;

    return 0;
}