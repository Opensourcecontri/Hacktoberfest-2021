# when using DEV C++ compiler :- 

#include<windows.h>
#include<iostream>
#include<stdlib.h> //for system("cls");
using namespace std;

int main()
{
 int i;
 char h=3;
 system("cls");
 system("color f5"); //f->white background, 5->purple text
 cout<<"\t\t\tFrom: Dharmendra Agrawal\n";
 Sleep(2000);
 cout<<"\t\t\tTo  : Person's name\n\n";
 Sleep(2000);
 cout<<"\t\t";
 for(i=0;i<42;i++)
 cout<<"_";
 cout<<"\n\n";
 system("color f9"); //f->white background, 9->light blue text

 Sleep(2000);
 cout<<"\t\t\t\ti i i i i\n";
 
 Sleep(2000);
 cout<<"\t\t\t\ti i i i i\n";
 
 Sleep(2000);
 cout<<"\t\t\t      __i_i_i_i_i__\n";
 
 Sleep(2000);
 cout<<"\t\t\t     |"<<h<<"           "<<h<<"|\n";
 
 Sleep(2000);
 cout<<"\t\t\t   __| "<<h<<"  dd/mm  "<<h<<" |__\n";
 
 Sleep(2000);
 cout<<"\t\t\t  | "<<h<<"   "<<h<<"       "<<h<<"   "<<h<<" |\n";

 Sleep(2000);
 cout<<"\t\t\t__|"<<h<<"   HAPPY     "<<h<<"   "<<h<<"|__\n";

 Sleep(2000);
 cout<<"\t\t       | "<<h<<"   "<<h<<"     BIRTHDAY    "<<h<<" |\n";

 Sleep(2000);
 cout<<"\t\t       |"<<h<<"  "<<h<<"     "<<h<<"    "<<h<<"     "<<h<<"   "<<h<<"|\n"; 
 
 
 Sleep(2000);
 cout<<"\t\t       | "<<h<<" "<<h<<" "<<h<<" "<<h<<" N A M E "<<h<<" "<<h<<" "<<h<<" "<<h<<" |\n";
    
 Sleep(2000);
 cout<<"\t\t       |_________________________|\n";    
    
 cout<<"\n\n\n\n\n"; 
 system("pause");
 return 0;
}




# When using TURBO C++ compiler :-

#include<iostream.h> //for I/O in dos based compiler's
#include<conio.h>
#include<dos.h>  //for delay();

int main()
{
 char h=3;
 clrscr();
 cout<<"\t\t\tFrom: Dharmendra Agrawal\n";
 delay(2000);
 cout<<"\t\t\tTo  : Person's name\n\n";
 delay(2000);
 cout<<"\t\t";
 for(int i=0;i<42;i++)
 cout<<"_";
 cout<<"\n\n";

 delay(2000);
 cout<<"\t\t\t\ti i i i i\n";

 delay(2000);
 cout<<"\t\t\t\ti i i i i\n";

 delay(2000);
 cout<<"\t\t\t      __i_i_i_i_i__\n";

 delay(2000);
 cout<<"\t\t\t     |"<<h<<"           "<<h<<"|\n";

 delay(2000);
 cout<<"\t\t\t   __| "<<h<<"  dd/mm  "<<h<<" |__\n";

 delay(2000);
 cout<<"\t\t\t  | "<<h<<"   "<<h<<"       "<<h<<"   "<<h<<" |\n";

 delay(2000);
 cout<<"\t\t\t__|"<<h<<"   HAPPY     "<<h<<"   "<<h<<"|__\n";

 delay(2000);
 cout<<"\t\t       | "<<h<<"   "<<h<<"     BIRTHDAY    "<<h<<" |\n";

 delay(2000);
 cout<<"\t\t       |"<<h<<"  "<<h<<"     "<<h<<"    "<<h<<"     "<<h<<"   "<<h<<"|\n";


 delay(2000);
 cout<<"\t\t       | "<<h<<" "<<h<<" "<<h<<" "<<h<<" N A M E "<<h<<" "<<h<<" "<<h<<" "<<h<<" |\n";

 delay(2000);
 cout<<"\t\t       |_________________________|\n";

 cout<<"\n\n\n\n\n";
 getch();
 return 0;
}
