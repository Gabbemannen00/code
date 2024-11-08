
#include <iostream> 

using namespace std;

int main() {

    /*initierar tre variabler där användaren får mata in priset och betalningen, den tredje variabeln
    ska inte användaren mata in något i eftersom det är där summan växel kommer räknas ut.*/  

    int price;
    int payment;
    int change;

    cout << "Enter the price on the product that you want to buy: "; //user input
    cin >> price;
    cout << "Enter how much money you want to pay with: "; //user input 
    cin >> payment;
    change = payment - price; // räknar ut hur mycket personen får i växel i variabeln change.
    cout << "You will get back: " << change << " kr" << ". Wich will be:"<< endl; 
    
    //för att dela in summan växel i enkronor, tiokronor, hundralappar och tusenlappar:

    int units; //lagrar entalen i variabeln units.
    int tens; //lagrar tiotalen i variabeln tens.
    int hundreds; //lagrar hundratalen i variabeln hundreds.
    int thousands; //lagrar tusentalen i variabeln thousands.

    
   
    units = change % 10; //räknar ut hur många ental som finns i växeln.
    change /= 10; //change = change / 10

    tens = change % 10; //räknar ut hur många tiotal som finns i växeln.
    change /= 10;

    hundreds = change % 10; // räknar ut hur många hundratal som finns i växeln. 
    change /= 10;

    thousands = change % 10; // räknar ut hur många tusental som finns i växeln.
    change /= 10;


    cout << units << " enkronor." << endl; //skriver ut entalen till enkronor.

    cout << tens << " tiokronor." << endl; //skriver ut tiotalen till tiokronor.

    cout << hundreds << " hundralappar." << endl; //skriver ut hundratalen till hundralappar.

    cout << thousands << " tusenlappar." << endl; //skriver ut tusentalen till tusenlappar.

    
    return 0;

}
