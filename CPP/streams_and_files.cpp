#include <iostream>//working with standard input and output streams Library.
#include <fstream> //fstream headerfile makes me be able to open and close files, read and write from these files.
#include <cstdio> //cstdio headerfile makes me able to work with streams and files.
#include <cstring> // allows me to perform tasks on arrays and c-style strings.
#include <string>
using namespace std;


/*How to open a text file with c++ and make it count the total number of 
characters and lines that the file contains.

file access modes:

"r" = Opens the file in read mode (if file exists, read the file from start), otherwise error.

"w" = Opens the file in write mode (if file exists, deletes all the contents) otherwise create new file.

"a" = Opens the file in append mode(if file exists, start writing from the end) otherwise create new file.

"open and read" commands:

"r+"= Opens the file in read and write mode(if file exists, read from start) otherwise error.

"w+" = Opens the file in read and write mode(if file exists, deletes all the contents) otherwise create new file.

"a+" = Opens the file in read and write mode(if file exists, start writing from the end) otherwise creat new file.

*/

int main() {
    #if 1
    // Using C-style file handling (stdio.h)
    
    FILE *fp1;
    fp1 = fopen("file.txt", "w"); // Open file in write mode (creates or erases existing content)
    
    if (!fp1) {
        perror("Error opening file");
        return 1;
    }

    // Writing to file
    const char sentence[] = "Hello C++, I'm Gabriel.\n";
    fputs(sentence, fp1);
    fclose(fp1);

    // Open file in read mode
    fp1 = fopen("file.txt", "r");

    if (!fp1) {
        perror("Error opening file for reading");
        return 1;
    }

    char buffer[100];
    int num_lines = 0, num_chars = 0;

    // Count lines and characters
    while (fgets(buffer, sizeof(buffer), fp1)) {
        num_lines++;
        num_chars += strlen(buffer);
    }

    fclose(fp1);

    cout << "Lines: " << num_lines << endl;
    cout << "Characters: " << num_chars << endl;

    #else
    // Using C++ fstream
    fstream file("file2.txt", ios::out); // Open file in write mode

    if (!file) {
        cerr << "Error opening file for writing" << endl;
        return 1;
    }

    // Writing to file
    file << "Greetings from Gabriel's first text file\n";
    file << "And this is the second line of his text.\n";
    file << "And this is the third line of his text.\n";
    file.close();

    file.open("file2.txt", ios::in); // Open file for reading

    if (!file) {
        cerr << "Error opening file for reading" << endl;
        return 1;
    }

    string line;
    int count_lines = 0, count_chars = 0;

    while (getline(file, line)) {
        count_lines++;
        count_chars += line.length() + 1; // +1 for '\n'
    }

    file.close();
    cout << "Number of lines: " << count_lines << endl;
    cout << "Number of characters: " << count_chars << endl;

    #endif

    return 0;
}

