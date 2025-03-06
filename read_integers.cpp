#include <iostream>
#include <vector> //för att kunna skapa vector och använda det.
#include <algorithm> //för att kunna sortera nummer.
#include <set> //för att kunna använda std::set.
#include <regex> //för att kontrollera giltig inmatning av tal.


/*Uppgift 1 (G - 10 poäng)

Skriv ett program som läser in heltal från användaren tills de matar in 0. 
Programmet ska:
 - Lagra talen i en vektor 
 - Beräkna och visa:  
     * Produkten av alla positiva tal  
     * Antalet jämna respektive udda tal  
    * Det näst största talet i inmatningen*/

   

int main(){

    std :: string restart; //Variabel som tar in en sträng från användaren, syfte är att kunna starta om programmet när programmet är slut.
    
    //Börjar med att skriva en kod som ska bygga upp vektorn med nummer i som läggs till av användaren.
    do{
    std :: vector<int>numbers; //skapar en vektor som kommer lagra heltal som matas in av användaren.
    std :: set<int>taken_numbers;
    std :: string user_input; //Tar in användarens svar.
    std :: cout << "\n";
    std :: cout<< "Skriv en serie med tal, skriv talet 0 när som helst för att sluta med tillägningen av tal."<< std :: endl;
    std :: cout<< "Regler: inga negativa tal tillåts, inga dubbletter av tal läggs till i talserien och bara heltal är tillåtna, resten är förbjudet."<< std :: endl;
    while (true){//kör denna loop så länge det är sant.
        std :: cout<<"Skriv ett tal: ";
        std :: cin >> user_input; //tar in användarens svar.
        //Kollar först om användaren matar in något annat än ett heltal.
        std::regex int_pattern("^-?[0-9]+$"); // Regex för heltal (positiva och negativa)
        if (!std::regex_match(user_input, int_pattern)) { 
            std::cout << "Fel! decimaler, tecken, bokstäver eller annat än heltal undanbedes, försök igen.\n";
            continue; // starta
        }

        int num = std::stoi(user_input); //konvertera användarens svar till en int.

        if (num == 0){ //om användaren skriver 0, slutar vi lägga till tal i vektorn.
            break;
        }

        if (num < 0){ //om användaren matar in negativa tal så ska de inte läggas till i vektorn.
            std :: cout <<"Fel! negativa tal är ej tillåtna...försök igen.\n";
            continue;

        }
        //kollar om talet redan har lagts till i vektorn.
        if (taken_numbers.find(num) != taken_numbers.end()){
            std :: cout<<"Talet "<< num <<" finns redan tillagt i talserien, lägg till ett annat tal.\n";
            continue; //starta om loopen.
        }

        numbers.push_back(num); //Om svaret var giltigt läggs talet till i början av vektorn.
        taken_numbers.insert(num); //talet läggs även till i ett set som håller koll på tal som redan lagts till.
        std :: cout<<"Talet "<<num<<" lades till i talserien!."<<std :: endl;

    } //Kollar om vektorn ens fick i sig tal efter input '0' gjorts av användaren.
    if (numbers.empty()){ //om villkoret empty är sant kommer ett felmeddelande skrivas ut.
        std :: cout << "\n";
        std :: cout << "Eftersom du inte matade in ett enda tal innan du skrev '0' avslutades programmet.\n";
        std :: cout << "\n";
        break;
    }
    else {
    std :: cout <<""<<std :: endl;
    std :: cout << "Dem här talen i följande ordning skrev du: ";
    //går igenom alla nummer i vektorn och 
    for (int number:numbers){ //variablen number tar in och lagrar talen som finns i variabeln numbers och skriver ut dem. 
        std ::cout<<number<<", "; //Skriver ut talen en för en så de hamnar bredvid varanndra.
    }

    }
    std :: cout <<""<<std :: endl;
 

    //Tar reda på produkten av alla positiva tal i vektorn:

    int product = 1; //produkten får startvärdet 1.

    for(int numr : numbers){
        if (numr > 0){ //tar alla nummer som är större än 0.
            product *=numr; //räknar ut produkten av alla jämna nummer genom att multiplicera dem med varanndra.
        }
    }

    std :: cout <<""<<std :: endl;

    std :: cout <<"Produkten av alla jämna nummer i talserien: "<<product<< std :: endl;

    std :: cout <<""<<std :: endl;

    //Går igenom och skriva ut antalet vektorns udda och jämna nummer.

    int count_evens = 0; //lagrar antalet jämna nummer.

    int count_odds = 0; //lagrar antalet udda nummer.

    //Lagrar jämna och udda tal i varsinna vektorer.

    std :: vector<int> evens; //vektor för att samla in alla jämna nummer i.
    
    std :: vector<int> odds; //vektor för att samla in alla udda nummer i.


    for(int num : numbers){//går igenom varje enskilt nummer i vektorn 'numbers'.
        if(num % 2 == 0){ //kollar om nummret är jämnt:
            evens.push_back(num); //om det stämmer lagra det i början av vektorn 'evens'.
            count_evens++; //ge variabeln +1 för varje funnet jämnt nummer.
        }
        else{
            odds.push_back(num); //alla andra nummer räknas som udda, lagra dem i vektorn 'odds'.
            count_odds++; //ge variabeln +1 för varje funnet udda nummer.
        }

    }

    std :: cout<<"Antalet jämna nummer i talserien: "<<count_evens<<std :: endl;

    std :: cout <<""<<std :: endl;

    std :: cout<<"Antalet udda nummer i talserien: "<<count_odds<<std :: endl;

    //För att beräkna vad det näst största talet är i vektorn numbers så är det bäst att börja med att sortera alla tal i storleksordning.

    std :: sort(numbers.begin(), numbers.end()); //Sorterar vektorn så minsta talet hamnar först och största sist.
    
    std :: cout <<""<<std :: endl;
    
    //För att komma åt det näst största talet använder jag mig utav indexet i numbers och tar med hela storleken, näst sista talet ligger på index -2.

    std :: cout <<"Det näst största talet i talserien är: "<<numbers[numbers.size()-2] <<std :: endl;
    std :: cout <<""<<std :: endl;
    //Funktion för att starta om programmet om man vill det.

    while(true){
    std :: cout <<"Köra programmet igen? ja eller nej?: ";
    std :: cin >> restart; //tar in användarens svar 'ja' eller 'nej'.
    //För att slippa oroa mig över att användaren matar in svaret 'ja' på andra sätt och som kan orsaka fel vid omstarten så kan jag med hjälp
    // av funktionen std::transform förhindra detta. 
    std ::transform(restart.begin(), restart.end(), restart.begin(), :: tolower); //omvandlar användarens svar till små bokstäver.
    //Förklaring av argumenten: transform(sträng.startposition, sträng.slutposition, destinationen för sträng.slutposition)
    if(restart == "ja"|| restart == "nej"){
        break;
        }

    else{
        std::cout<<"Ogiltigt svar, var god svara ja eller nej.\n";
        }
    }
    //om användaren svarade "nej" i loopen ovan vill jag skriva ut ett meddelande som bekräftar avslutandet av programmet.
    if (restart == "nej"){
        std :: cout <<""<<std :: endl;
        std::cout<<"programmet avslutades framgångsrikt.\n";
        std :: cout <<""<<std :: endl;
    }
}while (restart == "ja"); //kör denna do while loop så länge användaren svarar ja.
    
return 0;

}

