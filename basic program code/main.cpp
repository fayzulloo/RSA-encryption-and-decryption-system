//Saydullay Fayzullo
//02/15/2022
//project - RSA encryption and decryption system

#include<iostream>
#include<ctime>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<math.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

int isint(char a[])
{
    int len=strlen(a);
    int minus=0;
    int dsum=0;
    for(int i=0;i<len;i++)
    {
        if(isdigit(a[i])!=0)
            dsum++;
        else if(a[i]=='-')
            minus++;
    }
    if(dsum+minus==len)
        return 1;
    else
        return 0;
}
int isfloat(char a[])
{
    int len=strlen(a);
    int dsum=0;
    int dot=0;
    int minus=0;
    for(int i=0;i<len;i++)
    {
        if(isdigit(a[i])!=0)
        {
            dsum++;
        }
        else if(a[i]=='.')
        {
            dot++;
        }
        else if(a[i]=='-')
        {
            minus++;
        }
    }
    if(dsum+dot+minus==len)
        return 1;
    else
        return 0;
}

/*************************/
int random(int a)       //
{                        //
int x;                   //
                         //
srand(time(0));          //
                         //random number detection function
x = (rand()%(a)) + 3;    //
                         //
return x;                //
}                        //
/************************/

int primenum(int b)
{
bool Z;
int son;

sn:
Z = true;
son = random(b);

        for (int j = 2; j < son; j ++)
        {
            if (son % j == 0)
            {
                Z = false;
                goto sn;
                break;
            }
        }
            if(Z)
            return son;

}


int main() //main application body
{

int p, q, n, phi, e, d, option, e2, n2;
int crp[500];
char text[500];

cout << "Please wait, the base numbers are being selected";

pq:
p = primenum(30);  //prime numbers
q = primenum(25);
if(p == q)
    goto pq;

n = p * q;

phi = (p - 1) * (q - 1); //Calculation of the Euler function

e:
e = primenum(60);  //public component

if(e == n)
    goto e;

for(int i = 1; ; i++)
{
    if((i * e) % phi == 1)
    {
        d = i;
        break;
    }
}

if(e == d)
    goto e;


/***************************************************************************/
system("cls");
system("color 02");

cout << "\n\t\t\t\tWelcome to RSA encryption and decryption system\n";

SetConsoleTextAttribute(hConsole, 4);                                       //interface design before the program is run
cout << "\n\t\t\t\t\t\t<<ENTER>>\n" << endl;

getchar();
system("cls");
system("color 02");
cout << "public keys: " << "{" << e << "; " << n << "}\t";
cout << "private keys: " << "{" << d << "; " << n << "}";
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

/*********************************ENCRYPTION*********************************/
if(option == 1)
{
    system("cls");
    cout << "public keys: " << "{" << e << "; " << n << "}\t";
    cout << "private keys: " << "{" << d << "; " << n << "}";
    cout << "\n\t\t\t\t\t\tENTER THE TEXT\n";

    gets(text);

    cout << "\n\nEnter public keys\n";
    cout << "key1 -> "; cin >> e2;
    cout << "key2 -> "; cin >> n2;

int tottext = 0, f = 0;
unsigned long long int m;

  do{

        tottext++;

        f++;
    }while(text[f] != '\0');


for(int i = 0; i < tottext; i++)
{
     m = (pow((text[i] + 0), e2));
    cout << m % n2 << ",";
}


}
/*********************************DECRYPTION*********************************/
if(option == 2)
{
    string a;
    int k;

    system("cls");
    cout << "public keys: " << "{" << e << "; " << n << "}\t";
    cout << "private keys: " << "{" << d << "; " << n << "}";
    cout << "\n\t\t\t\t\t\tENTER THE ENCRYPTED TEXT\n";


    for (k = 0; ; k++)
        {
            if (scanf("%d", crp + k) != 1) /* error */;

            if(cin.get() == '\0') break;
        }

        cout << "\n";

    for(int i = 0; i < k; i++)
    {
        cout << crp[i] << "\n";
    }

}
    return 0;
}
