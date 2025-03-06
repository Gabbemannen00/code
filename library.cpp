#include <iostream>
#include <vector>
using namespace std;

class Item {
public:
    string title;   // title of the object
    string author;  // Author
    int year;       // publication year
    bool borrowed;  // checks if the item is borrowed or not, true or false.

    Item(string title, string author, int year, bool borrowed) {
        this->title = title;
        this->author = author;
        this->year = year;
        this->borrowed = borrowed;  // Corrected this line
    }

    virtual void display_info() = 0;  // virtual function for the subclasses
};

class Book : public Item {  // Creating the Book class as a subclass of Item.
public:
    int pages;

    // Constructor for the Book class:
    Book(string title, string author, int year, int pages)
        : Item(title, author, year, false), pages(pages) {}  // Initialize base class and pages

    void display_info() override {
        cout << "Book title: " << title << '\n';
        cout << "Book author: " << author << '\n';
        cout << "Published year: " << year << '\n';
        cout << "Total pages: " << pages << '\n';
    }
};

class Magazine : public Item {
public:
    int issue;

    // Constructor for the Magazine class:
    Magazine(string title, string author, int year, int issue)
        : Item(title, author, year, false), issue(issue) {}  // Initialize base class and issue

    void display_info() override {
        cout << "Magazine title: " << title << '\n';
        cout << "Magazine author: " << author << '\n';  // Corrected "Book author" to "Magazine author"
        cout << "Published year: " << year << '\n';
        cout << "Issue number: " << issue << '\n';
    }
};

class LibraryUser {
public:
    string user_name;
    vector<Item*> borrowed_items;

    LibraryUser(string name) : user_name(name) {}

    void borrow_item(Item* item) {
        borrowed_items.push_back(item);
        item->borrowed = true;  // Mark item as borrowed
    }

    void return_item(Item* item) {
        auto it = find(borrowed_items.begin(), borrowed_items.end(), item);
        if (it != borrowed_items.end()) {
            borrowed_items.erase(it);
            item->borrowed = false;  // Mark item as returned
        }
    }

    void display_borrowed_items() {
        cout << user_name << " has borrowed the following items:\n";
        for (auto item : borrowed_items) {
            item->display_info();
            cout << "-------------\n";
        }
    }
};

int main() {
    // Create some items
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 1925, 218);
    Magazine magazine1("National Geographic", "Various", 2023, 12);

    // Create a user
    LibraryUser user("Alice");

    // User borrows a book and a magazine
    user.borrow_item(&book1);
    user.borrow_item(&magazine1);

    // Display borrowed items
    user.display_borrowed_items();

    // User returns a book
    user.return_item(&book1);

    // Display borrowed items again
    user.display_borrowed_items();

    return 0;
}




