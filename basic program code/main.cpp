
//Saydullay Fayzullo
//02/15/2022
//project - RSA encryption and decryption system

#include<iostream>
#include<ctime>
#include<conio.h>
#include<stdio.h>
#include <windows.h>
#include <string.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

/*************************/
random()                 //
{                        //
int x;                   //
                         //
srand(time(0));          //
                         //random number detection function
x = (rand()%(99)) + 1;   //
                         //
return x;                //
}                        //
/************************/



int main() //main application body
{

int p, q, n, phi, e, d, option;
char text[500];

/***************************************************************************/
system("color 02");

cout << "\n\t\t\t\tWelcome to RSA encryption and decryption system\n";

SetConsoleTextAttribute(hConsole, 4);                                       //interface design before the program is run
cout << "\n\t\t\t\t\t\t<<ENTER>>\n" << endl;

getchar();
system("cls");
system("color 02");
/***************************************************************************/

cout << "\n\t\t\t\t\tCHOOSE WHAT YOU WANT TO DO\n\n";
cout << " Encryption -> 1\n";
cout << " Decryption -> 2\n";

switch (_getch())
  {
  case '1':
   option = 1;
   break;
  case '2':
   option = 2;
   break;
  }
/***************************************************************************/

if(option == 1)
{
    system("cls");
    cout << "\n\t\t\t\t\t\tENTER THE TEXT\n";

    gets(text);

     cout << text;
}

   return 0;
}
