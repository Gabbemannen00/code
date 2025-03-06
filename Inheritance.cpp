#include <iostream>
#include <string>
using namespace std;


/*Arv i c++ handlar om att en eller flera klasser kan ta del av attribut och metoder
från andra klasser. Barnklasser ärver attribut och metoder från förälderklassen. Med
hjälp av arvet från föräldern kan man återanvända kod när man ska skriva en ny klass. */

/*Jag börjar med att skapa förälderklassen. Jag har valt att använda mig utav animal och dog.
I det här fallet är klassen Animal själva basklassen och klassen Dog är den ärvande klassen.*/

class Animal{
   public:
   string animal;
   string species;
   string name;
   int age;
   int speed;

   //Skapar en konstruktör till klassen Animal med dess attributer.
   Animal(string animal, string species,string name  ,int age, int speed)
   {
      //initierar medlemsvariabler till parametrarna i konstruktorn.
      this->animal = animal;
      this->species = species;
      this->name = name;
      this->age = age;
      this->speed = speed;

   }

   //Skapar en metod för Animal klassen som ska visa informationen om djuret.
   void displayInfo(){
      
      cout<<"Animal: "<<animal<<endl;
      cout<<"Species: "<<species<<endl;
      cout<<"Name: "<<name<<endl;
      cout<<"Age: "<<age<<endl;
      cout<<"speed: "<<speed<<endl;
   }

   void makeSound(){
      cout <<"Animal is making a sound!"<<endl;
   }

};

class Dog : public Animal{
   public:
   //lägger till attributet dog race.
   string dog_race; 
   //skapar en konstruktor för Dog klassen och låter den ärva attribut från basklassen Animal's konstrukor.
   Dog(string name, int age, int speed, string race)
      : Animal("Dog", "subspecies of wolf",name, age, speed), dog_race(race){}

   //Överskrider metoden displayInfo för att inkludera dog_race.
      void displayInfo(){
         Animal::displayInfo(); //Använder basklassens metod displayInfo.
         cout <<"Dog race: "<<dog_race<<endl;

      }
     

};


int main(){
   //för att skriva ut klassen Dog, skapar jag ett objekt med namnet min_hund.
   Dog min_hund("Nicke",9, 30,"Malteser & Yorkshireterrier");

   min_hund.displayInfo(); 
   min_hund.makeSound();

   


return 0;

}




