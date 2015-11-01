#include "data.h"

#ifdef TEST
  #define MSG "Lol, the message is cool"
#endif

/*
*  0 = COMPUTER
   1 = YOU
 */

int main( int argc, char **argv)
{

  int player = random_number(); // Player that will start playing

  #ifdef __linux
    system("tput reset");
  #elif __POSIX
    system("tput reset");
  #elif __WIN32
    system("cls");
  #endif
  
  
  while(true)
  {
    
    write_screen("\n==[ Welcome to the SUPER TIC-TAC-TOE 2015/2016 ]============");
    
    draw_table();
    
    if(player == 1)
    {
      player_turn(player);
    }
    
    if(player == 0)
    {
      player_turn(player);
    }
    
    /*
    *
    *   Only will check if the number of moves >= 3
    *   This prevent waste of time checkin if someone
    *   wins.
    *
     */
    if(moves >= 3)
    {
      system("tput reset"); draw_table();
    
      if(check_winner() == 0)
      {
        puts("The computer Wins!\n**********GAME OVER************");
        return 1;
      }
      if(check_winner() == 1)
      {
        puts("Congratulations you win!\n**********GAME OVER************");
        return 1;
      }
    } system("tput reset");
  }
  
  
  return 0;

}