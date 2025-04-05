#include <iostream> //working with user input such as cout, cin.
#include <cstdlib> //gives the access to work with random number generation.
#include <ctime> //Tracking the current time.
#include <cstring> //gives me access to work with string operations.
#include <cctype> //In order to convert letters to lower- or uppercase.
#include <limits> //checking for invalid inputs from the user.


const int BOARD_SIZE = 9; //Board size will be used as a global variable so all functions can access it.

//creating a struct for storing the gamestats.

struct gamestats{

    //tracking the stats of the player.

    int player_total_wins = 0, player_total_loss = 0, player_score = 0;

    int player_easy_wins = 0, player_normal_wins = 0, player_hard_wins = 0 ;

    int player_easy_loss = 0, player_normal_loss = 0, player_hard_loss = 0;


    //tracking the stats of the pc.

    int pc_total_wins = 0, pc_total_loss = 0, pc_score = 0;

    int pc_easy_wins = 0, pc_normal_wins = 0, pc_hard_wins = 0;

    int pc_easy_loss = 0, pc_normal_loss = 0, pc_hard_loss = 0;

    //tracking the total amount of different games played.

    int total_games = 0, gameties = 0;
    
    int easy_games = 0, normal_games = 0, hard_games = 0;


};

//Declaring the functions.

void welcome(); //Displays welcome message.
void menu(); //Displays the menu.
void difficulty(); //Displays each difficulty.
void easy(gamestats &stats); //game on chill mode, laughable easy.
void normal(gamestats &stats); //game with some chill but fun and with more resistance.
void hard(gamestats &stats); //game with no chill, frustrating and challening, requires more tactical thinking.
void gameboard(char *spaces); //Displays the board with all its spaces.
void scoreboard(gamestats &stats);
void playermove(char *spaces, char player); //letting the player to interact with the board.
void computermove_easy(char *spaces, char computer, char player);//computer's skill level on easy mode.
void computermove_normal(char *spaces, char computer, char player);//computer's skill level on normal mode.
void computermove_hard(char *spaces, char computer, char player);//computer's skill level on hard mode.
bool checkwinner(char *spaces, char &winner);//checking if there is a winner detected.
bool checkdraw(char *spaces);//checking if there is a draw detected.

int main(){

   srand(time(0)); //initialize random generator.

   gamestats stats; //calling the gamestats in main.

   memset(&stats, 0, sizeof(stats));  //setting up the memory of the stats.

   welcome();//displaying welcome message

   while(true) {//This loop will keep displaying the menu until the user chooses to exit.

        menu(); //The menu is shown with user input.

        int menu_selection;
        std::cout<<"What do you want to do?: ";
        std::cin >> menu_selection;

        //first if-statement in the menu selection is handling invalid input from the user.
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout <<"Error...You cannot enter letters or symbols.\n";
            continue;

    }
 
    if (menu_selection == 1){
        difficulty(); //display the difficulties.
        int level_selection;

        while(true) {                           
            std::cout<<"Choose the computer's skill level: ";
            std::cin >> level_selection;

            //first handling invalid input such as letter/symbol-inputs or incorrect numbers.
            if (std::cin.fail() || level_selection < 1 || level_selection > 3){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout <<"Error...You can only enter 1,2 or 3.\n";
                continue;

            }
      
            if (level_selection == 1) {
                std::cout<<"\n";
                std::cout<<"The computer is being set to chill mode...\n";
                easy(stats); // Call easy difficulty
                break; // Exit the loop after valid selection
            } 
            else if (level_selection == 2) {
                std::cout<<"\n";
                std::cout<<"The computer is being set to test some of your limits...\n";
                normal(stats); // Call normal difficulty
                break; // Exit the loop after valid selection
            }
            else {
                std::cout<<"\n";
                std::cout<<"The computer is being set to warrior mode and make you wanna rage quit...\n";
                hard(stats); // Call hard difficulty
                break; // Exit the loop after valid selection
            } 
   

        }

    }

    else if(menu_selection == 2){
     scoreboard(stats);
    }
    else if (menu_selection == 3){
        std::cout<<"\n";
        std::cout<<"Exiting the program...\n";
        std::cout<<"\n";
        std::cout<<"The program ended successfully.\n";
        std::cout<<"\n";
     break;
    }

  }


   return 0;

}


void welcome(){

   std::cout<<"\n";
   std::cout<<"WELCOME\n";
   std::cout<<"            TO\n";
   std::cout<<"                  TIC\n";
   std::cout<<"                          TAC\n";
   std::cout<<"                                   TOE\n";
   std::cout<<"\n";

}

void menu(){

    std::cout<<"-_-_-_MAIN MENU-_-_-_-\n";
    std::cout<<"\n";
    std::cout<<"       PLAY(1)\n";
    std::cout<<"\n";
    std::cout<<"       STATS(2)\n";
    std::cout<<"\n";
    std::cout<<"       EXIT(3)\n";
    std::cout<<"\n";



}

void difficulty(){

    std::cout<<"\n";
    std::cout<<"_______DIFFICULTY_______\n";
    std::cout<<"\n";
    std::cout<<"        EASY(1)\n";
    std::cout<<"\n";
    std::cout<<"        NORMAL(2)\n";
    std::cout<<"\n";
    std::cout<<"        HARD(3)\n";
    std::cout<<"\n";

}

void easy(gamestats &stats){
    char restart; //restart variable
    
    do { //do while loop that will at the end of the game ask the user if he/she wants to play again. 

        char spaces[BOARD_SIZE] = {' ',' ',' ',' ',' ',' ',' ',' ',' '}; //array of empty spaces

        char player, computer;

        char winner = ' ';
                                 
        bool gameRunning = true; //Variable that keeps the game running as long as it's set to true.

        //The user gets the opportunity to choose which marker he/she wants to play as.
        std::cout<<"\n";
        std::cout<<"_____CHARACTERS_____\n";
        std::cout<<"Choose your marker (X or O):";
        while(true){
            std::cin >> player;
            player = toupper(player); //if the user enters x or o, convert to uppercase.
            if(player == 'X' || player == 'O'){
                computer = (player == 'X') ? 'O' : 'X';
                break;
        }else {
            std::cout << "You can only choose X or O as playername, try again: ";

        }

    }

    //Displaying the board with each cells number on it so the player gets to know how the board looks like before starting the game.

    std::cout<<"-----------------------------\n";
    std::cout<<"       LEVEL: EASY\n";
    std::cout<<"-----------------------------\n";
    std::cout << '\n';
    std::cout << "     |     |     " << '\n'; 
    std::cout << "  " <<     1     << "  |  " <<     2     << "  |  "<<     3     << "  " <<"       Here you can see the board with it's cell's. You make the first move.\n";
    std::cout << "_____|_____|_____" << '\n';                                                          
    std::cout << "     |     |     " << '\n'; 
    std::cout << "  " <<     4     << "  |  " <<     5     << "  |  "<<     6     << "  " <<"                 You are playing as '"<<player<<"' and the computer as '"<<computer<<"'.\n";
    std::cout << "_____|_____|_____" << '\n'; 
    std::cout << "     |     |     " << '\n'; 
    std::cout << "  " <<     7     << "  |  " <<     8     << "  |  "<<     9     << "  " <<"                      Three marks in a row = Victory.\n";                
    std::cout << "     |     |     " << '\n';
    std::cout <<'\n'; 

    while(gameRunning){

        playermove(spaces, player); 

        if(checkwinner(spaces, winner)){ //if it becomes true:
            gameboard(spaces);//displaying the board with the winning result.
            if(winner == player) {
                std::cout<<"You won an easy game, congratulations!\n";
                stats.player_total_wins++;
                stats.player_easy_wins++;
                stats.player_score++;
                stats.pc_easy_loss++;
                stats.pc_total_loss++;
            }else{
                std::cout<<"You lost an easy game, that's not ok bro.\n";
                stats.pc_total_wins++;
                stats.pc_easy_wins++;
                stats.pc_score++;
                stats.player_easy_loss++;
                stats.player_total_loss++;
            }
            stats.total_games++;
            stats.easy_games++;
            gameRunning = false; //stop the game.
            break;//exit the loop.
        }
        if(checkdraw(spaces)){ //when there is a draw the loop breaks and its game over.
            gameboard(spaces); //displaying the board with the draw result.
            std :: cout <<"\n";
            std :: cout <<"Game ended in a draw.\n";
            stats.easy_games++;
            stats.total_games++;
            stats.gameties++;
            gameRunning = false;
            break;//exit the loop.
        }
        
        computermove_easy(spaces, computer, player); //Function that is being called for the player.
        gameboard(spaces);

        //check if there is a winner or a draw and calling the checkwinner and checkdraw functions another time.
        if(checkwinner(spaces, winner)){
            if(winner == player) {
                std::cout<<"You won an easy game, congratulations!\n";
                stats.player_total_wins++;
                stats.player_easy_wins++;
                stats.player_score++;
                stats.pc_easy_loss++;
                stats.pc_total_loss++;
            }else{
                std::cout<<"You lost an easy game, that's not ok bro.\n";
                stats.pc_total_wins++;
                stats.pc_easy_wins++;
                stats.pc_score++;
                stats.player_easy_loss++;
                stats.player_total_loss++;

            }
            stats.easy_games++;
            stats.total_games++;
            gameRunning = false; 
            break;
        }
        if(checkdraw(spaces)){
            gameboard(spaces);
            std :: cout <<"\n";
            std :: cout <<"Game ended in a draw.\n";
            stats.easy_games++;
            stats.total_games++;
            stats.gameties++;
            gameRunning = false;
            break; 
            
        }

    }

    //asking the user for restarting the program.

    std::cout <<"Would you like to play again? (y/n): ";
    
    //a while loop for handling invalid inputs from the user.

    while(true){
        std :: cin >> restart; 
        if (restart == 'y' || restart == 'Y') 
        {   
            std::cout <<"\n";
            std::cout<<"restarting...\n";
            std::cout <<"\n";
            std::cout<<"New game on easy level created.\n";
            break;
           
            
        }

        else if(restart == 'n' || restart == 'N') 
        {   
            std::cout <<"\n";
            std::cout<<"Returning to main menu...\n";
            std::cout <<"\n";
            //menu();
            break;
        
        }

        else
        {
            std::cout<<"Invalid input, enter 'y' or 'n': ";

        }
        
    }
   
}while (restart == 'y' || restart == 'Y'); 


}

void normal(gamestats &stats){

    char restart; //variable for storing the users yes 'y' or no 'n' answer.
    
    do { //do while loop that will at the end of the game ask the user if he/she wants to play again. 

    char spaces[BOARD_SIZE] = {' ',' ',' ',' ',' ',' ',' ',' ',' '}; //array of empty spaces

    char player, computer;

    char winner = ' ';
                                 
    bool gameRunning = true; //Variable that keeps the game running as long as its set to true.

    //The user gets the opportunity to choose wich marker he/she wants to play as.
    std::cout<<"\n";
    std::cout<<"_____CHARACTERS_____\n";
    std::cout<<"Choose your marker (X or O):";
    while(true){
        std::cin >> player;
        player = toupper(player); //if the user enters x or o, convert to uppercase.
        if(player == 'X' || player == 'O'){
            computer = (player == 'X') ? 'O' : 'X';
            break;
        }
        else 
        {
            std::cout << "You can only choose X or O as playername, try again: ";

        }

    }

    //Displaying the board with each cells number on it so the player gets to know how the board looks like before starting the game.

    std::cout<<"-----------------------------\n";
    std::cout<<"       LEVEL: NORMAL\n";
    std::cout<<"-----------------------------\n";
    std::cout << '\n';
    std::cout << "     |     |     " << '\n'; 
    std::cout << "  " <<     1     << "  |  " <<     2     << "  |  "<<     3     << "  " <<"      Here you can see the board with it's cell's, computer makes the first move.\n";
    std::cout << "_____|_____|_____" << '\n';                                                          
    std::cout << "     |     |     " << '\n'; 
    std::cout << "  " <<     4     << "  |  " <<     5     << "  |  "<<     6     << "  " <<"          You are playing as '"<<player<<"' and the computer as '"<<computer<<"'.\n";
    std::cout << "_____|_____|_____" << '\n'; 
    std::cout << "     |     |     " << '\n'; 
    std::cout << "  " <<     7     << "  |  " <<     8     << "  |  "<<     9     << "  " <<"                   Three marks in a row = Victory, good luck!.\n";                
    std::cout << "     |     |     " << '\n';
    std::cout <<'\n'; 

    while(true){ //In normal mode the computer makes the first move.

        int computer_choice; //variable that will store the computers choice.
        computer_choice = rand() % BOARD_SIZE; //generates a random number between 0 and 8.
        
        if(spaces[computer_choice] == ' ') {

          spaces[computer_choice] = computer; 
          computer_choice++; 
          std::cout << "Player "<<computer<<" selected cell "<<computer_choice<<'\n'; 
          break;

        }

    }
   
    while(gameRunning){

        playermove(spaces, player); 

        if(checkwinner(spaces, winner)){ //if it becomes true:
            gameboard(spaces);//displaying the board with the winning result.
            if(winner == player) {
                std::cout<<"You won a normal game!, hope you enjoyed it (; \n";
                stats.player_total_wins++;
                stats.player_normal_wins++;
                stats.player_score+=3;
                stats.pc_normal_loss++;
                stats.pc_total_loss++;
            }else{
                std::cout<<"You lost a normal game...maybe next time you get it.\n";
                stats.pc_total_wins++;
                stats.pc_normal_wins++;
                stats.pc_score+=3;
                stats.player_normal_loss++;
                stats.player_total_loss++;
            }
            stats.normal_games++;
            stats.total_games++;
            gameRunning = false; //stop the game.
            break;//exit the loop.
        }
        if(checkdraw(spaces)){ //when there is a draw the loop breaks and its game over.
            gameboard(spaces); //displaying the board with the draw result.
            std :: cout <<"Game ended in a draw.\n";
            stats.normal_games++;
            stats.total_games++;
            stats.gameties++;
            gameRunning = false;
            break;//exit the loop.
        }
        
        computermove_normal(spaces,computer, player); //Function that is being called for the player.
        gameboard(spaces);

        //check if there is a winner or a draw and calling the checkwinner and checkdraw functions another time.
        if(checkwinner(spaces, winner)){
            if(winner == player) {
                std::cout<<"You won a normal game!, hope you enjoyed it (; \n";
                stats.player_total_wins++;
                stats.player_normal_wins++;
                stats.player_score+=3;
                stats.pc_normal_loss++;
                stats.pc_total_loss++;
            }else{
                std::cout<<"You lost a normal game...maybe next time you get it.\n";
                stats.pc_total_wins++;
                stats.pc_normal_wins++;
                stats.pc_score+=3;
                stats.player_normal_loss++;
                stats.player_total_loss++;
            }
            stats.normal_games++;
            stats.total_games++;
            gameRunning = false; //if checkwinner becomes true, gamerunning will be executed as false and its game over.
            break;
        }
        if(checkdraw(spaces)){
            gameboard(spaces);
            std::cout <<"\n";
            std::cout <<"Game ended in a draw.\n";
            stats.normal_games++;
            stats.total_games++;
            stats.gameties++;
            gameRunning = false;
            break; 
            
        }

    }

    //asking the user for restarting the program.

    std::cout <<"Would you like to play again? (y/n): ";
    
    //a while loop for handling user input and invalid inputs from the user.

    while(true){
        std :: cin >> restart; 
        if (restart == 'y' || restart == 'Y') 

        {   
            std::cout <<"\n";
            std::cout <<"restarting...\n";
            std::cout <<"\n";
            std::cout <<"New game with normal difficulty created.\n";
            std::cout <<"\n";
            break;
           
            
        }

        else if(restart == 'n' || restart == 'N') 
        {   
            std::cout <<"\n";
            std::cout<<"Returning to main menu...\n";
            std::cout <<"\n";
            break;
        
        }

        else
        {
            std::cout<<"Invalid input, enter 'y' or 'n': ";

        }
        
    }
   
}while (restart == 'y' || restart == 'Y'); 

}

void hard(gamestats &stats){

    char restart; 
    
    do {  

    char spaces[BOARD_SIZE] = {' ',' ',' ',' ',' ',' ',' ',' ',' '}; //array of 9 empty spaces.

    char player, computer;

    char winner = ' ';
                                 
    bool gameRunning = true; 

    //The user gets the opportunity to choose wich marker he/she wants to play as.
    std::cout<<"\n";
    std::cout<<"_____CHARACTERS_____\n";
    std::cout<<"Choose your marker (X or O):";
    while(true){
        std::cin >> player;
        player = toupper(player); //if the user enters x or o, convert to uppercase.
        if(player == 'X' || player == 'O'){
            computer = (player == 'X') ? 'O' : 'X';
            break;
        }
        else 
        {
            std::cout << "You can only choose X or O as playername, try again: ";

        }

    }

    //Displaying the board with each cells number on it so the player gets to know how the board looks like before starting the game.
    std::cout <<'\n'; 
    std::cout<<"-----------------------------\n";
    std::cout<<"       LEVEL: HARD\n";
    std::cout<<"-----------------------------\n";
    std::cout << '\n';
    std::cout << "     |     |     " << '\n'; 
    std::cout << "  " <<     1     << "  |  " <<     2     << "  |  "<<     3     << "  " <<"      Here you can see the board with it's cell's. Computer makes the first move\n";
    std::cout << "_____|_____|_____" << '\n';                                                          
    std::cout << "     |     |     " << '\n'; 
    std::cout << "  " <<     4     << "  |  " <<     5     << "  |  "<<     6     << "  " <<"           You are playing as '"<<player<<"' and the computer as '"<<computer<<"'.\n";
    std::cout << "_____|_____|_____" << '\n'; 
    std::cout << "     |     |     " << '\n'; 
    std::cout << "  " <<     7     << "  |  " <<     8     << "  |  "<<     9     << "  " <<"                   Three marks in a row = Victory, good luck!.\n";                
    std::cout << "     |     |     " << '\n';
    std::cout <<'\n'; 
    
    while(true){ 
        int computer_choice; //variable that will store the computers choice.
        computer_choice = rand() % BOARD_SIZE; //generates a random number between 0 and 8.
        
        if(spaces[computer_choice] == ' ') //if-statement checks if the computer's choise is equal to an empty space in the array.
        {
          spaces[computer_choice] = computer; //Adding the computer's marker to that spot.
          computer_choice++; //Because the computer choose a number between 0 and 8 and the board's cells has it's numbers from 1 to 9, we add 1 in order to match the board's index.
          std::cout << "Player "<<computer<<" selected cell "<<computer_choice<<'\n'; 
          break;

        }

    }
    
        
    while(gameRunning){

        playermove(spaces, player); 

        if(checkwinner(spaces, winner)){ //if it becomes true:
            gameboard(spaces);//displaying the board with the winning result.
            if(winner == player) {
                std::cout<<"You won a hard game!, YOU are the legend (; \n";
                stats.player_total_wins++;
                stats.player_hard_wins++;
                stats.player_score+=5;
                stats.pc_hard_loss++;
              
            }else{
                std::cout<<"You lost a Hard game...maybe next time you get it.\n";
                stats.pc_total_wins++;
                stats.pc_hard_wins++;
                stats.pc_score+=5;
                stats.player_hard_loss++;
                stats.player_total_loss++;
              
            }
            stats.hard_games++;
            stats.total_games++;
            gameRunning = false; //stop the game.
            break;//exit the loop.
        }
        if(checkdraw(spaces)){ //when there is a draw the loop breaks and its game over.
            gameboard(spaces); //displaying the board with the draw result.
            std::cout <<"Game ended in a draw.\n";
            stats.hard_games++;
            stats.total_games++;
            stats.gameties++;
            gameRunning = false;
            break;//exit the loop.
        }
        
        computermove_hard(spaces, computer, player); //Function that is being called for the player.
        gameboard(spaces);

        //check if there is a winner or a draw and calling the checkwinner and checkdraw functions another time.
        if(checkwinner(spaces, winner)){
            if(winner == player) {
                std::cout<<"You won a hard game!, YOU are the legend ():!!!!! \n";
                stats.player_total_wins++;
                stats.player_hard_wins++;
                stats.player_score+=5;
                stats.pc_hard_loss++;
            }else{
                std::cout<<"You lost a hard game...maybe this is too hard for you )=.\n";
                stats.pc_total_wins++;
                stats.pc_hard_wins++;
                stats.pc_score+=5;
                stats.player_hard_loss++;
                stats.player_total_loss++;
            }
            stats.hard_games++;
            stats.total_games++;
            gameRunning = false; //if checkwinner becomes true, gamerunning will be executed as false and its game over.
            break;
        }
        if(checkdraw(spaces)){
            gameboard(spaces);
            std::cout<<"\n";
            std::cout<<"Game ended in a draw.\n";
            stats.hard_games++;
            stats.total_games++;
            stats.gameties++;
            gameRunning = false;
            break; 
            
        }

    }

    //asking the user for restarting the program.

    std::cout <<"Would you like to play again? (y/n): ";
    
    //a while loop for handling invalid inputs from the user.

    while(true){
        std :: cin >> restart; 
        if (restart == 'y' || restart == 'Y') 

        {  
            std::cout <<"\n";
            std::cout <<"restarting...\n";
            std::cout <<"\n";
            std::cout <<"New game on hard mode created.\n";
            std::cout <<"\n";
            break;
           
            
        }

        else if(restart == 'n' || restart == 'N') 
        {   
            std::cout <<"\n";
            std::cout<<"Returning to main menu.....\n";
            std::cout <<"\n";
            break;
        
        }

        else
        {
            std::cout<<"Invalid input, enter 'y' or 'n': ";

        }
        
    }
   
}while (restart == 'y' || restart == 'Y'); 



}


void gameboard(char *spaces){

    std :: cout << '\n';
    std :: cout << "     |     |     " << '\n'; 
    std :: cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  "<< spaces[2] << "  " <<'\n';
    std :: cout << "_____|_____|_____" << '\n';
    std :: cout << "     |     |     " << '\n'; 
    std :: cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  "<< spaces[5] << "  " <<'\n';
    std :: cout << "_____|_____|_____" << '\n'; 
    std :: cout << "     |     |     " << '\n'; 
    std :: cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  "<< spaces[8] << "  " <<'\n';
    std :: cout << "     |     |     " << '\n';
    std :: cout <<'\n'; 


}

void scoreboard(gamestats &stats){

    std::cout<<"______________________________________________________________________\n";
    std::cout<<"|                                SCOREBOARD                           |\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"PARTICIPANTS:        Player            |                PC            | \n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"TOTAL SCORE:           "<<stats.player_score<<"                       |                "<<stats.pc_score<<"             |\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"GAMES WON:             "<<stats.player_total_wins<<"                  |                "<<stats.pc_total_wins<<"        |\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"GAMES LOST:            "<<stats.player_total_loss<<"                  |                "<<stats.pc_total_loss<<"        |\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"EASY GAMES WON:        "<<stats.player_easy_wins<<"                         |                "<<stats.pc_easy_wins<<"         |\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"EASY GAMES LOST:       "<<stats.player_easy_loss<<"                        |                "<<stats.pc_easy_loss<<"         |\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"NORMAL GAMES WON:      "<<stats.player_normal_wins<<"                     |                "<<stats.pc_normal_wins<<"       |\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"NORMAL GAMES LOST:     "<<stats.player_normal_loss<<"                    |                "<<stats.pc_normal_loss<<"       |\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"\n";
    std::cout<<"HARD GAMES WON:        "<<stats.player_hard_wins<<"                         |                "<<stats.pc_hard_wins<<"         |\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"HARD GAMES LOST:       "<<stats.player_hard_loss<<"                        |                "<<stats.pc_hard_loss<<"         |\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"\n";
    std::cout<<"\n";
    std::cout<<"\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"                 ***********  TYPES OF GAMES PLAYED ***********               \n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"Total games played:                    "<<stats.total_games<<"\n";
    std::cout<<"----------------------------------------------------------------------\n";    
    std::cout<<"Total games ended in a tie:            "<<stats.gameties<<"\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"Easy games played:                     "<<stats.easy_games<<"\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"Normal games played:                   "<<stats.normal_games<<"\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"Hard games played:                     "<<stats.hard_games<<"\n";
    std::cout<<"----------------------------------------------------------------------\n";


    if(stats.total_games == 0){

        std::cout<<"No games played yet )=.\n"; 
        std::cout<<"\n"; 
    }
 
    if(stats.player_score > stats.pc_score)
    {   
       
        std::cout<<"You are the one who has taken the lead with "<<stats.player_score - stats.pc_score<<" points!. Keep smashing it :D.\n";
    }
    else if(stats.player_score < stats.pc_score)
    {   
        std::cout<<"At the time your pc has taken the lead with "<<stats.pc_score - stats.player_score<<" points!. Keep playing and improve :D.\n";
    }
    else
    {  
        std::cout <<"At the moment you guys have the same amount of points.";
     
    }
 
    std::cout<<"\n";
    std::cout<<"----------------------------------------------------------------------\n";
    std::cout<<"\n";
 
 }

void playermove(char *spaces, char player){ 

    int player_choice;
    
    do { //Do while loop that checks the players input and will only stop when player enters valid input.
        std::cout <<"\n";
        std::cout <<"Your turn to select a cell (1-9): ";
        std::cin >> player_choice;
        std::cout <<"\n";

        //First check if the player enters anything but numbers:
        if(std::cin.fail()){//if failure occurs in the user input, .
           std::cin.clear();//clear the error flag in order to re-enable input operations for the user.
           std::cin.ignore(std :: numeric_limits<std::streamsize>::max(), '\n'); //clear
           std::cout <<"Thats not a number, please try again.\n"; 
           std::cout <<"\n";
           continue; //restarting the loop
        }
        //if no errors were found in the input:

        player_choice--; //Subtracting the players input number with 1 in order to convert to zero-based index.

        if (player_choice >= 0 && player_choice < BOARD_SIZE && spaces[player_choice] == ' ') 
        {
            spaces[player_choice] = player; // Place player's marker
            break; // Exit the loop

        } 
        //if the player enters a number between 1 and 9 but at an non-empty spot.
        else if (player_choice >= 0 && player_choice < BOARD_SIZE) 
        
        {
            std::cout << "That cell is already occupied, choose an empty cell.\n";
            std::cout <<"\n";
        } 
        
        else 
        
        {
            std::cout << "The number must be between 1 and 9.\n";
            std::cout <<"\n";
        }
        
    } while(true); //keep running this loop as long as one of the conditions were true.

}

bool checkwinner(char *spaces, char &winner){
    //2 dimensional array for checking the winning conditions:
        int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, //horizontal lines
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, //vertical lines
        {0, 4, 8}, {2, 4, 6} //Diagonal lines
    };
    
    //in this case we have three columns in each row to iterate over.
    for(auto &win : wins){
        if(spaces[win[0]] != ' ' && spaces[win[0]] == spaces[win[1]] && spaces[win[1]] == spaces[win[2]]){
            winner = spaces[win[0]];
            return true;
            }
        }
    
        return false; 
    
    }
       
    bool checkdraw(char *spaces){
        
        for (int i= 0; i < BOARD_SIZE; i++){ //looping through the array of spaces.
            if(spaces[i] == ' '){ 
                
                return false; //return false and continue game if there is any empty spaces left. 
    
            }
    
            
        }
    
        return true; //if a draw is detected and the board is full of marks with no loser or winner.
    
    }
    
void computermove_easy(char *spaces, char computer, char player){
//easy level: The computer is only picking random spots on the board, cannot see winning conditions, nor do block it's opponent.
    while(true){ 

        int computer_choice; //variable that will store the computers choice.
        computer_choice = rand() % BOARD_SIZE; //generates a random number between 0 and 8.
        
        if(spaces[computer_choice] == ' ') {

          spaces[computer_choice] = computer; 
          computer_choice++; 
          std::cout << "Player "<<computer<<" selected cell "<<computer_choice<<'\n'; 
          std::cout <<"\n";
          break;

        }

    }

}

void computermove_normal(char *spaces, char computer, char player){
//normal level: The computer has the ability to see if its about to win and make that move, however it is not programmed to block its opponent on this level.

    for (int i = 0; i < BOARD_SIZE; i++){
        if (spaces[i] == ' '){ //if the cell is empty:
            spaces[i] = computer; //temporary place computer's marker in that cell.
            char temp;
            if (checkwinner(spaces, temp) && temp == computer){ //if this move makes the computer to win:
                i++; 
                std::cout << "Player "<<computer<<" selected cell "<<i<<'\n'; 
                std::cout <<"\n";
                return; //make this move and exit.
            }
            spaces[i] = ' '; //otherwise make the cell empty again if the move is not a winning move.
        }

    }
       
        //if the player is not about to win then pick a random cell.
        while(true){ 
    
            int computer_choice; //variable that will store the computers choice.
            computer_choice = rand() % BOARD_SIZE; //generates a random number between 0 and 8.
            
            if(spaces[computer_choice] == ' ') {
    
              spaces[computer_choice] = computer; 
              computer_choice++; 
              std::cout << "Player "<<computer<<" selected cell "<<computer_choice<<'\n'; 
              std::cout <<"\n";
              break;
    
            }
    
        }
    
    

}


void computermove_hard(char *spaces, char computer, char player){

//hard level: the computer can check winning conditions before making a move, also block the opponent if the opponent is about to win.

    //function for the computer to check if it can win with this move.
    for (int i = 0; i < BOARD_SIZE; i++){
        if (spaces[i] == ' '){ //if the cell is empty:
            spaces[i] = computer; //temporary place computer's marker in that cell.
            char temp;
            if (checkwinner(spaces, temp) && temp == computer){ //if this move makes the computer to win:
                i++; 
                std::cout << "Player "<<computer<<" selected cell "<<i<<'\n'; 
                std::cout <<"\n";
                return; //make this move and exit.
            }
            spaces[i] = ' '; //otherwise make the cell empty again if the move is not a winning move.
        }

    }
       //fucntion that is meant for blocking the player.   
       for (int i = 0; i < BOARD_SIZE; i++){ 
        if (spaces[i] == ' '){
            spaces[i] = player;
            char temp;
            if (checkwinner(spaces, temp) && temp == player){ //if this move makes the player to win:
                spaces[i] = computer; //block the player.
                i++; 
                std::cout << "Player "<<computer<<" selected cell "<<i<<'\n';
                std::cout <<"\n";
                return; //exit 
            }
        spaces[i] = ' '; //otherwise if the selected cell is not blocking the player from winning the game, make it empty again and continue.
        }

    }
    //if the player or the computer is not about to win, the computer selects a cell randomly.
    while(true){ 
        int computer_choice; //variable that will store the computers choice.
        computer_choice = rand() % BOARD_SIZE; //generates a random number between 0 and 8.
        
        if(spaces[computer_choice] == ' ') //if-statement checks if the computer's choise is equal to an empty space in the array.
        {
          spaces[computer_choice] = computer; //Adding the computer's marker to that spot.
          computer_choice++; //Because the computer choose a number between 0 and 8 and the board's cells has it's numbers from 1 to 9, we add 1 in order to match the board's index.
          std::cout << "Player "<<computer<<" selected cell "<<computer_choice<<'\n'; 
          std::cout <<"\n";
          break;

        }

    }

}

