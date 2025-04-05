#include <iostream>
using namespace std;

//Övning: 16. 

int main(){
   int f[5] = {10, 20, 30, 40, 50}; //Ett heltalsfält med namn "f" som har 5 st heltalskomponenter.

   int tal;  /*int variabel som tar in avändarens svar och som sen ska användas för att 
              jämföra med dem talen som finns i heltalsfältet "f". */

   int k; /*variabeln "k" har i uppgift att söka och gå igenom alla 5 element i fältet 
           tills den hittar talet som användaren matade in, eller tills den har sökt 
           igenom hela fältet utan att ha hittat användarens sökta tal. */

   cout << "Vilket tal letar du efter?: "; 

   cin >> tal; //tar in användarens sökta tal.

   /*initierar en for-loop där k har startvärdet 0 och villkoret: k< 5 kollar 
   om indexet k ligger innanför fältet "f". Om det villkoret uppfylls så kommer
   villkoret: f[k] ! = tal att köras, och den i sin tur kollar om k inte stämmer
   överens med användarens sökta tal, om så är fallet kommer villkoret k++ köras.
   k++ gör att värdet på k ökar med 1 för varje gång k-talet inte finns i fältet.
   */

   for (k = 0; k < 5 && f[k] != tal; k++);

   //Men om talet k skulle vara densamma som användarens sökta tal kommer if-villkoret att köras.

   if (tal == f[k])   

   //Detta i sin tur kommer i utskriften ange vilket index i fältet som det sökta talet ligger på. 

   cout << "Talet finns på index: " << k << endl;

   //Om inte talet k skulle stämma överens med användarens sökta tal körs else-satsen.
  
   else cout << "Talet finns ej" << endl;
  

//Övning 18:

   int array[10] = {5, 10, 3, 1, 6, 90, 55, 33, 44, 20}; //ett int-fält med 10 integers/element.

   int counter; //en variabel som går igenom fältet array's element, 

   int second_num; //en variabel som ska fungera som en jämförare med dem andra variablerna.

   int smallest; //en variabel som ska lagra det element med lägst värde längst fram i fältet.

   int temporary;//en variabel som tillfäligt ska stora en annan variabel som byter plats med en annan.

   int sorted_array; //en variabel som ska stora och printa ut det nya fältet i slutet av koden.

   cout << "Osorterat fält: array[10] = {5, 10, 3, 1, 6, 90, 55, 33, 44, 20}"<<endl;
   cout << "Sorterat fält: "; //denna utmatning + det nya fältet kommer skrivas ut i slutet av koden.

  /*sorterar fältet array i en outer for loop. Denna for loop kommer fortsätta
  så länge det första  */

   for(counter = 0; counter <= 10; counter++) //counter går igenom varje element.
   {
   // letar reda på minsta talet i fältet array.
   
   //skapar då en inner-for-loop som ska utföra den uppgiften.

       smallest = counter; //utgår först ifrån att counter är lägst.

       //kollar om det andra numret bredvid counter är mindre än counter.
   
       for (second_num = counter+1; second_num < 10; second_num++) 

       //om det stämmer att numret bredvid är lägre, byter plats.

       if (array[second_num] < array[smallest])

       /*andra numret hamnar längst fram i fältet på index 0 
        och counter hamnar på plats 1.*/


       smallest = second_num;

       //Talet lagrade i variabeln counter och i variablen smallest ska byta plats
       //För att göra detta kommer nu variabeln temporary användas tillfäligt.

       temporary = array[counter];  
       array[counter] = array[smallest];
       array[smallest] = temporary;
   }
       //Skriver ut det uppdaterade fältet.

       for (sorted_array = 0; sorted_array < 10; sorted_array++)

   {

       cout<<sorted_array[array]<<' '; 

   }

return 0;


}





