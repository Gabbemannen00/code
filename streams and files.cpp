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
int main(){
//In order to swap betwwen fstream and without fstream i use #if,#endif:
   #if 1
   //without fstream 
   //using fopen() to open the file
   FILE *fp1; //making fp1 points to FILE object.
   fp1 = fopen("file.txt", "w"); //(name of file, file access mode) "w" opens the file in write mode.
   char sentence[50]= "Hello C++, im Gabriel.\n"; //a character array that stores the content of the file with max 50 chars.
   if (fp1) //if the file exists:
   { //using a for loop that loops over the elements in char sentence.
     //Aslong as the loop hasnt reached the end of the sentence, keep iterate.
       for(int index = 0; index < strlen(sentence); index++)
       putc(sentence[index],fp1); 
       
   }
   fclose(fp1);
   
   //Opening same file again, this time using fgets function.
   //fgets makes the program read one line from the file until its end \n.

   int count = 50; //max numbers of characters to write.
   int num_lines = 0; 
   
   fp1 = fopen("file.txt", "w+"); 
   fputs("This is one line of text.\n", fp1);
   fputs("This is another line of text.\n", fp1);

   rewind(fp1); //repositions fp1.

   while(feof(fp1)==0) //using a while-loop.
   {

       fgets(sentence, count, fp1);
       num_lines++;
      
   }
   cout << "Lines: "<<num_lines<<endl;
   
   fclose(fp1);

   //using fgetc to read specific characters.
   int character; //creating an int variable to read characters.
   int num_ch = 0;
   
   fp1 = fopen("file.txt","r"); 

   if (fp1)
   {
       while(feof(fp1)==0)
       {
           character = fgetc(fp1);
           putchar(character);
           num_ch++;
       }
       cout <<"number of characters: "<<num_ch<<endl;
       
   }
   else perror("Failed to open the file");
   fclose(fp1);



   #else
   //using fstream:
   fstream file; 
   file.open("file2.txt", ios::out);//creating a txt(text)file and using ios::out (output) so i can write in the text file.
   if (file.is_open()){ //the if-statement controlls whether the file has been opened.
       file << "Greetings from Gabriels first text-file\n";
       file << "and this is the second line of his text.\n";
       file << "and this is the third line of his text.\n";
       file.close();
   }

   file.open("file2.txt", ios::in);//opens the file in read mode.
   if (file.is_open()){
       string read_line; //using a string variable to store every line that is going to be read.
       int count_lines = 0; //int variable to count the number of lines.
       while(getline(file,read_line)){
           cout <<"Read line: "<<read_line<<endl;
           count_lines++;
       }
       //displaying total number of lines after exiting the loop.
       cout <<"Number of lines: "<<count_lines<<endl;
       file.close(); //closing file.
   }

   //Opens the file again to read character by character.
   file.open("file2.txt", ios::in);
   if(file.is_open()){
       
       int sum_ch = 0; //variable for counting chars. Starts with 0.

       while((file.get())!='\n') //While loop that iterates as long as there is characters left.
       {
           sum_ch++; //every counted character will end up in the sum variable.
       }
       cout <<"number of characters: "<<sum_ch<<endl;
       file.close(); //closed the file.
   }
   file.open("file2.txt", ios::in); //opens the file again, this time to print out the characters in the file.
   if(file.is_open()){

       char ch; //variable for storing chars.

       while(file.get(ch))//while loop used for output each character.
       {
           cout<<ch<<" ";//outputing character one by one with some space between them " ".
       }
   file.close();
   }
   


   #endif



return 0;

}

