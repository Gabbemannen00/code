#include <isotream>
#include <vector>
#include <string>
using namespace std;


class Item{
   public:
   string title; //title of the object
   string author; //Author
   int year; //publicationyear
   bool borrowed; //checks if the book is borrowed or not.

   Item(string title,string author, int year, bool borrowed){

       this->title = title;
       this-> author= author;
       this->year = year;
       this->borrowed = borrowed(false);
   }

   virtual void display_info() = 0; //virtual void for the sub-classes.
   
};

class Book : public Item{ //Book is childclass to Item.
   public:
   int pages;
   //constructor for the book class:
   Book(string title, string author, int year, int pages){

   void display_info()override{
       cout <<"Book title: "<<title<<'\n';
       cout <<"Book author: "<<author<<'\n';
       cout <<"Published year: "<<year<<'\n';
       cout <<"Total pages: "<<pages<<'\n';

   
   }

   }

};

class Magazine : public Item{ //Magazine is childclass to Item.
   public:
   int issue;

   Magazine(string title, string author, int year, int issue){

   void display_info()override{
       cout <<"Magazine title: "<<title<<'\n';
       cout <<"Book author: "<<author<<'\n';
       cout <<"Published year: "<<year<<'\n';
       cout <<"Total pages: "<<issue<<'\n';

   }

   }

};

class LibraryUser{
   string borrower;
   vector<Item*>borrowed_items;

};


int main(){














return 0;

}
