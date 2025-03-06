#include <iostream>
using namespace std;

int main(){

//while loop version:
int x = 12;

  while(x>=0){
    if (x == 6){
      x-=2;
    }
    else{
      x--;
  
    }

  }

cout<<x<<endl;

for(int x=12; x>=0;x--){
  if (x==6){
    x-=2;
  }
  else{
    x--;
  }

cout <<x<<endl;

}



  // Deklarera en 3x3-array
  int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Loopar igenom rader och kolumner
    for (int i = 0; i < 3; i++) { // Loopar över rader
        for (int j = 0; j < 3; j++) { // Loopar över kolumner
            std::cout << matrix[i][j] << " "; // Skriv ut element
        }
        std::cout << "\n"; // Ny rad efter varje rad
    }

  













    return 0;

}