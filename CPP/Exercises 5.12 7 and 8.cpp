#include <iostream>
#include <cstring> 
using namespace std;


//Övning 8: 
  /*Skapar en void som kan lagra parametrarna dest och src.
  */
  void my_own_strcat(char *destination, const char *source)
  {
   //
   while (*destination != '\0'){   

       destination ++; //ökar med 1
   }
   /*Denna while loop kommer vid varje iteration kopiera ett element
   i taget från variabeln source till variabeln destination. Men kommer
   bara göra det så länge loopen inte har nått '\0' (slutet av strängen).
   */
                                       
   while (*source != '\0'){ 

       *destination = *source; //*source kopieras nu till *destination.
       destination++; //
       source++;//

   }
   *destination = '\0'; 

   //--------------------------------------------------------------------------------------//

}
   void copied_string(char *dest, char const *src){

       while(*src != '\0'){ /*så länge det finns kvar element i src att 
                            kopiera fortsätt iteration i whileloop.*/ 
       *dest = *src; //src kommer fortsätta bli kopierad av dest.
       dest++; //fortsätter gå igenom elementen en för en.
       src++; 
   }
   *dest = '\0';

}

int main(){
//Uppgift 8 fortsättning: Tilldelar variablerna sina värden i main.
   char destination[50] = "Denna sträng är ";
   //source variabeln blir konstant eftersom den inte ska modifieras.
   char const *source = "ihopsatt med en hemmagjord strcat().";

   cout <<"Första strängen: "<<source<<endl;
   cout<<""<<endl;
   cout <<"Andra strängen: "<<destination<<endl;
   cout<<""<<endl;

   my_own_strcat(destination, source); //kallar på void-funktionen i main.

   //skriver ut nya strängen.
   cout << "Konkatenerad sträng: " <<destination<<endl; 
   cout<<""<<endl;
   
//Övning 7: 


   char const src[] = "En mening som är skriven i variabel src."; //Konstant variabel som ej modifieras vid exekvering.

   char dest[100];// storlek 100, men tar in max 100 karaktärer.

   copied_string(dest,src); // kallar på void-funktionen i main.
   
   cout<< "Den här strängen finns i variabel src: "<< src <<endl;
   cout<<""<<endl;
   cout << "Men som nu också finns i variabeln dest: "<< dest <<endl;
   cout<<""<<endl;

   return 0;

}