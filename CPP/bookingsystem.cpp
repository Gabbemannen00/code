#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Booking{ //En klass med attribut för ett bokningssystem.
    private: //private ser till att klassmedlemarna inte ändras utanför klasserna.
    int bookingID; //Bokningens identifikation.
    string customerName; //namnet på kunden som gjort bokningen.
    string contactInfo; //Kontaktinfo, till exempel e-post.
    string bookingDate; //Datumet då bokningen gjordes.
    string bookingStatus;//checkar av om bokningen är bekräftad, väntande eller avbokad.
    
    public:
    //En konstruktor som använder en initieringslista där attributen från klassen Booking tilldelas sina värden.
    Booking(int id, string name, string contacts, string date, string status)
    :bookingID(id), customerName(name), contactInfo(contacts), bookingDate(date), bookingStatus(status) {}

    //för att komma åt dem privata värdena i klassen utan att bryta inkapslingen används getter-metod.
    int getbookingID()const{
        return bookingID; 
    }
    string getcustomerName()const{
        return customerName;
    }
    string getContactInfo()const{
        return contactInfo;
    }
    string getbookingDate()const{
        return bookingDate;
    }
    string getbookingStatus()const{
        return bookingStatus;
    }

    //metod för att sätta ny status för bokning, detta görs eftersom i och med att attributet är privat så går det från början inte att uppdatera det.
    //Därför jag använder setter metod för att göra uppdatering av värdet i bookingStatus möjlig.
    void set_bookingStatus(string new_status){ //tar in en sträng som parameter.
        if(new_status == "bekräftad" || new_status == "avbokad" || new_status == "väntande"){
           bookingStatus = new_status; //bookingStatus får ny status.
        }

        else 
        {
            cout<<"Ogiltig status"<<endl;
           
        }
           
        }
        
    
    void showBooking()const{//metod som ska skriva ut information om kunden.
        cout<<"_______________________________"<<endl;
        cout<<"                               "<<endl;
        cout <<"BokningsID: "<<bookingID<<endl;
        cout <<"Kund: "<<customerName<<endl;
        cout <<"Kontaktinfo: "<<contactInfo<<endl;
        cout <<"Datum: "<<bookingDate<<endl;
        cout <<"Status: "<<bookingStatus<<endl;
        cout<<"_______________________________"<<endl;

    }


};

//klass som ska hantera alla bokningar. 
class BookingManager{
    private: //för säkerhetsskull gör jag den privat.
    vector<Booking> list_of_bookings; //Vector som ska lagra alla regristrerade bokningar.

    public:
    //Denna metod tar in alla argument som behövs för att skapa en bokning.
    void createBooking(int id, string name, string contacts, string date, string status){ //Metod för att skapa en bokning.
        Booking new_Booking(id, name, contacts, date, status); //new_Booking objektet av klassen Booking skapat.
        list_of_bookings.push_back(new_Booking); //Lägger till objektet i vektorn.
        cout <<"Bokning med id: "<<id<<" tillagd."<<endl; //bekräftelsemeddelande på att bokning skapades.

    }
//för att välja och ta bort en bokning räcker det med att föra in kundens id som argument i metoden.
    void deleteBooking(int id){
        //en for loop som går igenom alla bokningar som finns i vektorn från första index till sista index.
        for(auto i = list_of_bookings.begin(); i != list_of_bookings.end(); i++ ){
            if(i ->getbookingID() == id){ //om det införda ID från användaren stämmer överens med objektets ID.
               list_of_bookings.erase(i); //ta bort bokningen på det angivna indexet i vektorn.
               cout<<"Bokning med id: "<<id<<" har tagits bort."<<endl;
               return; //avsluta 

            }

        }
        //ifall bokningen inte hittades. Skriv ut ett meddelande om att den inte fanns.
        cout<<"Bokning med id: "<<id<<" som du försöker ta bort hittades inte."<<endl;
    }

    void showAllBookings()const{
        for(const auto& booking : list_of_bookings){//const är för att se till att inget värde ändras under iterationen.
            booking.showBooking(); //kallar på funktionen showBooking för att skriva ut alla bokningar.
            
        } 
    }
    //När jag ska söka efter en bokning så använder jag mig av liknande metod som när jag ska radera en bokning.
    void searchBooking(int id)const{//tar in användarens svar i sökandet efter bokningens ID.
        for(const auto &booking :list_of_bookings){ //konstanta variablen booking i for loopen går igenom vektorn.
            if(booking.getbookingID() == id){
                booking.showBooking();
                return;


            }

        }

        cout<<"Bokning med ID: "<<id<<" som du sökte efter hittades ej."<<endl;

    }

  
};

int main(){

    BookingManager start; //skapar ett objekt till bokningshanteraren.

    //Skapar min första bokning:
    start.createBooking(00, "Gabriel Carlsson", "gabriel-carlsson@hotmail.se", "2024-5-11", "väntande");
    //Skapar en bokning åt min pappa
    start.createBooking(01, "Janne Carlsson", "jan.carlzzon@hotmail.com", "2024-10-1", "väntande");
    //Skapar en bokning åt min mamma
    start.createBooking(02, "Susanne Carlsson", "susanne-carlsson@gmail.com", "2024-6-10", "avbokad");
    
    //Visa alla bokningar 
    cout <<""<<endl;
    cout <<"Skriver ut alla bokningar..."<<endl; 
    cout <<""<<endl;
    start.showAllBookings();//Alla bokningar ska skrivs ut.

    //ta bort bokning
    start.deleteBooking(01);

    //sök efter bokning 01 för att säkerhetställa att den är borttagen.
    cout <<""<<endl;
    cout <<"Söker efter bokning 01..."<<endl;
    cout <<""<<endl;
    start.searchBooking(01); //skriver i mitt id av min bokning.

    //Visa alla bokningar 
    cout <<""<<endl;
    cout <<"Skriver ut alla bokningar igen..."<<endl; 
    cout <<""<<endl;
    start.showAllBookings();//Alla bokningar ska skrivs ut.

    return 0;

}

