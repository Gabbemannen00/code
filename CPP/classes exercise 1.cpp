#include <iostream>

//Creating a car class with its attributs, use functions to drive it and display its info.

class Car{

   public: 
   std::string brand;  //bilmärke
   std::string model;  //bilmodell
   int year; //årsmodell
   double mileage; //mätarställning

   //Skapar en konstruktör som tar in attributen brand, model, year och mileage som argument.

   Car(std::string brand, std::string model, int year, double mileage){

       //initierar medlemsvariablerna.

       this->brand = brand; //för att slippa initiera brand i en ny variabel använder jag metoden 'this'.

       this->model = model;

       this->year = year;

       this->mileage = mileage;

   }


   void drive (double distance){

       mileage += distance; //increasing the cars mileage with the amount of selected distance.
       
       std :: cout<<"You just drove your car "<<brand<<" "<<model<<" with "<<distance<<" miles!"<<'\n';

   }


   void displayInfo(){ 

       std :: cout <<"Brand: "<< brand << '\n';
       std :: cout <<"Model: "<< model << '\n';
       std :: cout <<"Year: "<< year << '\n';
       std :: cout <<"Mileage: "<< mileage<< '\n';
       


   }
   
   int getYear(){
       

       return year;



   }

   double getMileage(){

       
       return mileage;


   }

};

int main(){

   Car my_car("Volvo","V60",2015,2500.777); //Creating an object of the class Car and allocate values to it.

   std :: cout<<"Brand: "<<my_car.brand<<'\n';
   std :: cout<<"Model: "<<my_car.model<<'\n';
   std :: cout<<"Year: "<<my_car.year<<'\n';
   std :: cout<<"Mileage: "<<my_car.mileage<<'\n';

   //Calling the drive function and enters the argument 50 miles. Makes my car drive 50 miles.

   my_car.drive(50);

   //Now i want to know the updated info of my_car so i decide to call the non-void function 'getMileage'

   std :: cout <<"Mileage: "<< my_car.getMileage()<<'\n'; 

   //and you can now see that the milage has increased by 50 miles.

   std :: cout <<"Year: "<< my_car.getYear()<<'\n'; 

   std :: cout <<"Updated info:"<<'\n';

   my_car.displayInfo();



return 0;

}
