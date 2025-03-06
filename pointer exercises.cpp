#include <iostream> 
#include <cstdlib> //(stdlib.h)
using namespace std;

/*Uppgift 1: Vad är ett dynamsikt minne i C++?
Svar: Ett dynamiskt minne i C++ är ett minne som kan
allokeras eller avallokeras av operativsystemet under
körtiden av kod. Det dynamiska minnet i C++ är mer 
effektivare än det statiska minnet, föramförallt för att
man kan avallokera och återanvända minnet under körtiden
av ett C++ program.

Hur fungerar ett dynamiskt minne i C++?
Svar: När vi ska använda oss utav dynamisk minnesallokering
använder programmeraren operatörerna "new" och "delete".
new = allokerar ett nytt minnesblock. delete = avallokerar
minnesblcoket som allokeras genom användandet av en ny operator.

Det dynamiska minnet i C++ fungerar på det sättet att
det allokerade minnet avallokeras inte förrän programmet
avslutas. Detta innebär att programmeraren måste manuellt
avallokera minnet när det inte längre behövs. Och Om detta inte
görs kan minnesläckor uppstå. 

*/

int main(){

 //Uppgift 2:

   //1.Deklaration:
/*
   int *p; 

   //2.Initialisering:

   int a = 10; 

   p = &a;

   //3.Dereferering:

   cout <<*p<<endl;
*/
   /*Uppgift 3:
   Vad heter online verktyget som du kan köra ditt C++ program
   med användandet av det dynamiska minnet?
   Prova köra program i uppgift 2.
   Svar: Använder mig utav new och delete.
   */

  //Exempel på kod där new och delete används:
/*
  int *p = new int; //allokerar minne för en int.

  *p = 5; //det allokerade minnet får värdet 5.

  delete p; //frigör minnet som pekaren 'p' refererar till.

  */

  
/*


*/







  //Uppgift 4:
  //Minneshanteringsproblem

  //1. Minnesläckor: 



  //2. Dubbel frigöring: 



  //3. Dangling pointers:
  
return 0;


}