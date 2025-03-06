#include <iostream>
using namespace std;
int main() {

/* 1.Skriv ett program som beräknar och skriver ut hur många mil en bil gått
under det senaste året. När programmet körs skall det fråga efter dagens
mätarställning och mätarställningen för ett år sedan. De två mätarställningarna
skall anges som hela antal mil*/

    int current_meter;
    int previous_meter;
    float distance;
    float miles_to_kilomoters;
    float dik; //variable dik = distance in kilometers
    float fuel_consumtion;
    float year_fuel_cons;
    float fuel_in_liters;
    float gallon_to_liters;
    float gas;
    
    
    cout << "Enter what your meter shows now:  ";
    cin >> current_meter;
    cout << "Enter what your meter showed one year ago: ";
    cin >> previous_meter; 
    
    
   
/* 2. Komplettera programmet i föregående i övning så att det dessutom beräknar
bilens genomsnittliga bensinförbrukning per mil. Förutom de två mätarställningarna
skall programmet läsa in hur många liter benisn som förbrukats under året (anges
som ett reellt tal). Utskriften från programmet skall se ut som i följande exempel:

Antal körda mil: 1487
Antal liter benisn: 1235.4
Förbrukning per mil: 0.83 */


    cout << "Enter how many gallons of fuel you refill your car with per month:  ";
    cin >> fuel_consumtion;

    //Böjar med att räkna ut hur många mil/km bilen gått på ett år.

    distance = current_meter - previous_meter; //räknar ut antal mil på ett år.
    
    miles_to_kilomoters = 2; //Avrundar uppåt och det blir 2 kilometer per mil.

    dik = distance * miles_to_kilomoters; //tar sträckan i mil och multiplicerar med två för att få fram antalet km.

    
    //Räknar sedan ut bränsleförbrukningen i liter.

   
    year_fuel_cons = fuel_consumtion * 12; // förbrukad gallon bensin på 12 månader.

    gallon_to_liters = 4; //för varje gallon är det nästan 4 liter

    fuel_in_liters = year_fuel_cons * gallon_to_liters; //gör om gallon till liter.

    gas = year_fuel_cons / distance; //räknar ut bensinförbruk, per mil under ett år.



    //skriver ut resultaten nedanför.

    cout << "Antal körda mil: " << distance << ", i km: ("<< dik<<")." << endl;  

    cout << "Antal liter bensin: " << fuel_in_liters << endl; 
    
    cout << "Förbrukning per mil: " << gas << endl;



    return 0;

}