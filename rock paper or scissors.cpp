#include <iostream> //makes the user work with input and output.
#include <cstdlib>//means standard library, and is a headerfile that generates random numbers.
#include <ctime>  //tracking the current time.
#include <cstring> //Makes me to work with scpecific string-operations.
using namespace std;

//Creating a sructure where i declare all the variables that will be used later in the game.
struct gamestruct  
{
    
   int player_score, pc_score;

   int pc_game_lost, pc_game_win; 
   
   int player_game_lost, player_game_win, gameties;

   int ties_rounds, player_loss, player_wins;
   
   int pc_loss, pc_wins;
   
   int current_round, total_rounds, total_games; 


};

void get_menu(){

   cout<<"      ROCK, PAPER OR SCISSORS   "<<endl;
   cout<<""<<endl;
   cout<<"       ______MAIN MENU_____  "<<endl;  
   cout<<""<<endl;                               
   cout<<"Play the game(1) "<<endl;
   cout<<"Show leaderboard(2) "<<endl;
   cout<<"Quit main menu(3)"<<endl;
   cout<<"--------------------------------------"<<endl;
   cout<<"Please choose what you want to do: ";
   
  
}

void get_leaderboard(gamestruct stats){

   cout<<"______________________________________________________________________"<<endl;
   cout<<"|                                LEADERBOARD                         |"<<endl;
   cout<<"----------------------------------------------------------------------"<<endl;
   cout<<"PARTICIPANTS:        Player                            PC            | "<<endl;
   cout<<"----------------------------------------------------------------------"<<endl;
   cout<<"TOTAL SCORE:           "<<stats.player_score<<"               |                "<<stats.pc_score<<"            |"<<endl;
   cout<<"----------------------------------------------------------------------"<<endl;
   cout<<"ROUNDS WON:            "<<stats.player_wins<<"               |                "<<stats.pc_wins<<"            |"<<endl;
   cout<<"----------------------------------------------------------------------"<<endl;
   cout<<"ROUNDS LOST:           "<<stats.player_loss<<"               |                "<<stats.pc_loss<<"            |"<<endl;
   cout<<"----------------------------------------------------------------------"<<endl;
   cout<<"GAMES WON:             "<<stats.player_game_win<<"               |                "<<stats.pc_game_win<<"            |"<<endl;
   cout<<"----------------------------------------------------------------------"<<endl;
   cout<<"GAMES LOST:            "<<stats.player_game_lost<<"               |                "<<stats.pc_game_lost<<"            |"<<endl;
   cout<<"----------------------------------------------------------------------"<<endl;
   cout<<""<<endl;
   cout<<"Total Games played:  "<<stats.total_games<<"    Sum of ties per round: "<<stats.ties_rounds<<endl;
   cout<<""<<endl;
   cout<<"Total Rounds played: "<<stats.total_rounds<<"   Sum of ended games in a tie: "<<stats.gameties<<endl;
   cout<<""<<endl;
   cout<<"----------------------------------------------------------------------"<<endl;

   if(stats.player_score > stats.pc_score)
   {   
      
       cout<<"You are the one who has taken the lead with "<<stats.player_score - stats.pc_score<<" points!. Keep smashing it :D.";
   }
   else if(stats.player_score < stats.pc_score)
   {   
       cout<<"At the time your pc has taken the lead with "<<stats.pc_score - stats.player_score<<" points!. Keep playing and improve :D.";
   }
   else if(stats.player_score == 0 || stats.pc_score == 0)
   {
    cout<<"No games played yet, lets play? (=";  
   }
   else
   {  
    cout <<"You are at the moment in a tie with your computer,time to change that?";
    
   }

   cout<<""<<endl;
   cout<<"----------------------------------------------------------------------"<<endl;
   cout<<""<<endl;

}

void get_the_game(gamestruct & stats){

   /*Both player and the pc starts with 5 lifes each, and 
   for every lost round the lifes will be subtracted by 1.
   For every winning round the points will be added by 1.
   When a player runs out of all his lifes the player with
   the highest score at the end wins the whole game. */

   int player_lifes = 5, pc_lifes = 5;
     
   //variables for counting the score are initiated.

   int player_score = 0, pc_score = 0;

   //rounds played, storing amount of winning and losing rounds for each player:

   int ties_rounds = 0, player_loss = 0, player_wins = 0, pc_loss = 0, pc_wins = 0;
   
   /*Variable 'current_rounds' keeps track of wich round the players are currently playing on,
   while the variable 'total_rounds' gathers all the rounds that have been played with. Thats
   why current round starts with 1 and not 0 for instance.*/

   int current_round = 1, total_rounds = 0;  

   const string choices[3]= {"rock","paper","scissors"}; //an array of three strings that is meant for the pc to use.
  
   cout<<"-----------------------------------------------------------------------"<<endl;
   cout<<""<<endl;
   cout<<"The game is about to launch, you can exit the game anytime by pressing 'q'. "<<endl;
   cout<<"If you want to see the current status of your latest progress press 's'. "<<endl;

   //The while loop will continue to iterate as long as the players lifes are greater than 0.*/

   while(player_lifes > 0 && pc_lifes > 0){
        
    string pc_choice = choices[rand() %3]; //A string variable that will store the pc's random answer 

    string player_choice;  //A string variable that will store the players answer as a string.

       
   
       cout<<""<<endl;
       cout<<"-----------------------------------------------------------------------"<<endl;
       cout<<"End game: 'q'"<<endl;
       cout<<"Show status: 's'"<<endl;
       cout<<"ROUND "<<current_round<<" HAS STARTED :D"<<endl;
       cout<<"---------------------------------------------------------------------"<<endl;
       cout<<"Enter rock, paper or scissors: ";
       cin >> player_choice;
       cout<<""<<endl;
       cout<<""<<endl;
       cout<<""<<endl;
       cout <<"------------------MADE BY GABBEMANNEN FROM SWEDEN----------------------"<<endl;

       if(player_choice == "q") //By pressing 'q' the player can end the game anytime when needed.
       {   

           cout<<""<<endl;
           cout<<""<<endl;
           cout <<"You ended the game. Hope you come back soon! (="<<endl;
           cout<<""<<endl;
           cout<<""<<endl;
           break; 

       }

       if(player_choice == "s") 
       {
           cout <<" __________________________"<<endl; 
           cout <<"|Scoreboard: "<<"you: "<<player_score<<" | pc: "<<pc_score<<"|"<<endl;
           cout <<"|Lifes left: "<<"you: "<<player_lifes<<" | pc: "<<pc_lifes<<"|"<<endl;
           cout <<" --------------------------"<<endl;                           
           cout <<""<<endl;
       
           continue; 
       }
          

       if(player_choice != "rock" && player_choice != "paper" && player_choice != "scissors")
       {
           cout <<""<<endl;
           cout<< "Invalid input, try again."<<endl;
           continue;
           
       }

       else if(player_choice == pc_choice){
           cout<<""<<endl;
           cout<<"The computer also choosed "<<pc_choice<<", TIE!"<<endl;
           cout<<"No lifes lost, no points added, game continues. "<<endl;
           

           ties_rounds++;
           total_rounds++;
           current_round++;

           stats.ties_rounds++;
           stats.total_rounds++;
           

       }
                                         
       /*This code block goes through all the winning situations that the player can have
       for a typical round. And if none of them are true then the pc has won that round. */

       else if ((player_choice == "rock" && pc_choice == "scissors") ||  
           (player_choice == "paper" && pc_choice == "rock") ||         
           (player_choice == "scissors" && pc_choice == "paper"))
                 
       {   cout<<""<<endl;
           cout<<"ROUND "<<current_round<<" VICTORIOUS!"<<endl;
           cout<< "The computer choosed "<<pc_choice<<"."<<endl;
           cout<<"Good job! you won round "<<current_round<<" ,and got one point."<<endl;
           cout<<"The computer lost one life."<<endl;
           
               player_score++; 
               player_wins++;
               pc_loss++;      
               total_rounds++;
               pc_lifes--;
               current_round++;


               stats.player_score++;
               stats.player_wins++; //The stats.variables are 
               stats.pc_loss++;
               stats.total_rounds++;
               
       }

       else

       {   cout<<""<<endl;
           cout<<"ROUND "<<current_round<<" LOST...."<<endl;
           cout<<"The computer choosed "<<pc_choice<<"."<<endl;
           cout<<"The computer won round "<<current_round<<" ,and got one point."<<endl;
           cout<<"You lost one life, but you can still win this."<<endl;
           cout<<"----------------------------------------------------------------"<<endl;

           pc_score++;
           pc_wins++;
           player_loss++;
           player_lifes--; //player lost 1 life in player_lifes
           total_rounds++;
           current_round++; // moving on to next round using the '++' sign.



           stats.pc_score++;      //1 point is added to pc_score
           stats.pc_wins++;       // 1 winning round is added to pc_wins
           stats.player_loss++; //1 lost round added to player_loss
           stats.total_rounds++; //a finished round is added in total_rounds
           
   
       }
   }
   cout<<"__--__--__--__---____----____FINAL STATS OF TODAYS GAMEPLAY_ -_ -_ -_ -_ -_ -_ -_ -_-_-"<<endl;
   cout<<"                                                                                       "<<endl;
   cout<<" Total score (Player):       "<<player_score<<"       |      (PC): "<<pc_score<<"        |"<<endl;
   cout<<" --------------------------------------------------------------------------------------"<<endl;
   cout<<" Remaining lifes (Player):   "<<player_lifes<<"       |      (PC): "<<pc_lifes<<"        |"<<endl;
   cout<<" --------------------------------------------------------------------------------------"<<endl;       
   cout<<" Won rounds (Player):       "<<player_wins<<"       |      (PC): "<<pc_wins<<"        |"<<endl;
   cout<<" --------------------------------------------------------------------------------------"<<endl;
   cout<<" Lost rounds (Player):     "<<player_loss<<"       |      (PC): "<<pc_loss<<"        |"<<endl;
   cout<<"                                                                                       "<<endl;
   cout<<"--___---  ----------- ___ ---___---- -----____--- -------- ---______------------_ _____"<<endl;
   cout<<""<<endl;
   cout<<"Number of ties: "<<ties_rounds<<endl;
   cout<<""<<endl;
   cout<<"Rounds played: "<<total_rounds<<endl;
   cout<<""<<endl;


   if (player_score > pc_score)
   {
       cout <<"Congratulations! You won the game with "<<player_score - pc_score<<" more points than your pc."<<endl;
       cout<<""<<endl;

       stats.player_game_win++;
       stats.pc_game_lost++;
       stats.total_games++;
   }

   else if(player_score < pc_score)
   {
       cout<<"Today the winner is your pc who successfully gained "<<pc_score - player_score<<" more points than you."<<endl;
       cout<<""<<endl;

       stats.pc_game_win++;
       stats.player_game_lost++;
       stats.total_games++;

   }   
  
   else
   {
       cout<<"In the end you and your pc had the same amount of points when the game ended, its a tie!."<<endl;
       cout<<""<<endl;

       stats.gameties++;
       stats.total_games++;
   }


}

int main(){

  srand(time(0)); //initierar rand() igen för att se till att datorns slumpval är olika mellan körningar.

  //denna struct lägger sig i minnet på "stacken"

  gamestruct stats; //calling the gamestruct function in main.

  /* memset = "set memory to x"

  Denna funktion från <cstring> tar addressen av variablen 'stats',
  och skriver över dens inre värde med 0,
  mellan addressen och adressen + 60 bytes
  där 60 bytes = sizeof(int) gånger 15 == sizeof(stats)
  15 är alla 15 variabler i stats som alla är av typen 'int', storleken av en int är 4 bytes*/

   memset(&stats, 0, sizeof(stats));  

   int menu_selection; // letting the user select his/her choice for the menu.

   while(true){                           
   get_menu();
   cin >> menu_selection;
   switch(menu_selection) //taking the menu selection in a switch statement that goes through each case.
   {
       case 1:
       get_the_game(stats); //If player choose inputs 1 the game will start.
       break;

       case 2:
       get_leaderboard(stats); //The player can press 2 to see the leaderboard. 
       continue;

       case 3:
       cout<<""<<endl;
       cout<<"program shutted down successfully."<<endl; //When the player types 3 the program shuts down.
       cout<<""<<endl;
       exit(0); //In order to end the program we use exit(0), 
                //in this way we execute the program without any error or interruption.

       default:
       cin.clear();
       cin.ignore(10000, '\n' );
       cout<<""<<endl;
       cout<<"Not a valid answer, please try again."<<endl;
       cout<<""<<endl;
         
   }


}


}