#include <string>
#include <iostream>

//playing with functions 

void greetings(){
    std::string name;
    std::string surname;
    int age;

    std::cout<<"Type your first name: ";
    std::cin>>name;

    std::cout<<"Type your surname: ";
    std::cin>>surname;

    std::cout<<"Type your age: ";
    std::cin>>age;

    std::cout<<"Hello "<<name<<" "<<surname<<"!. You are "<<age<<" years old."<<std::endl;
}



void game(){

    std::cout<<""<<std::endl;
    std::cout<<"Welcome to Gabriels shooting game 2025!!!"<<std::endl;
    std::cout<<"--__--__--__--__--__--__--__--__--__--"<<std::endl;
    std::cout<<"             Main menu                 "<<std::endl;


    

}

int main(){

    std::string answer;

    int score;

    greetings();

    std::cout<<"You just started your c++ programming journey!."<<std::endl;
    std::cout<<""<<std::endl;

    while(true){
    std::cout<<"Would you like to play a shooting game?: ";
    std::cin>>answer;

    if (answer == "Yes" ){
        game();
        break;

    }
    else if (answer == "No"){
        std::cout<<"Ok thats fine, we skip the game!."<<std::endl;



    }








    }

    return 0; 
}