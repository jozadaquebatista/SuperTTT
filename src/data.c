#include "data.h"

//volatile unsigned char *first_player_n = calloc(9, sizeof(char));
//volatile unsigned char *second_player_n = calloc(9, sizeof(char));

// Board
unsigned char table[3][3] = {{'_','_','_'},
                             {'_','_','_'},
                             {'_','_','_'}};


unsigned int turn=0, moves=0;
                             
// Function to draw Board
void draw_table( void )
{

  register  unsigned int x, y;
  
  puts("\n");
  for( y=0; y<(strlen(*table)/3); y++ )
  { 
    // printf("-[%d]", y); -> number rows
    
    for( x=0; x<(strlen(*table)/3); x++ )
    {
      draw(table, x, y);
    }
    line_break;
  }

}

_Bool check_winner(  ) // unsigned int *foo
{

  if( (table[0][0] == 'O' && table[1][0] == 'O' && table[2][0] == 'O') ||
      (table[0][1] == 'O' && table[1][1] == 'O' && table[2][1] == 'O') ||
      (table[0][2] == 'O' && table[1][2] == 'O' && table[2][2] == 'O') ||
      
      (table[0][0] == 'O' && table[0][1] == 'O' && table[0][2] == 'O') ||
      (table[1][0] == 'O' && table[1][1] == 'O' && table[1][2] == 'O') ||
      (table[2][0] == 'O' && table[2][1] == 'O' && table[2][2] == 'O') ||
       
      (table[0][0] == 'O' && table[1][1] == 'O' && table[2][2] == 'O') ||
      (table[2][0] == 'O' && table[1][1] == 'O' && table[0][2] == 'O')
    )
      return true;
  
  if( (table[0][0] == 'X' && table[1][0] == 'X' && table[2][0] == 'X') ||
      (table[0][1] == 'X' && table[1][1] == 'X' && table[2][1] == 'X') ||
      (table[0][2] == 'X' && table[1][2] == 'X' && table[2][2] == 'X') ||
     
      (table[0][0] == 'X' && table[0][1] == 'X' && table[0][2] == 'X') ||
      (table[1][0] == 'X' && table[1][1] == 'X' && table[1][2] == 'X') ||
      (table[2][0] == 'X' && table[2][1] == 'X' && table[2][2] == 'X') ||
     
      (table[0][0] == 'X' && table[1][1] == 'X' && table[2][2] == 'X') ||
      (table[2][0] == 'X' && table[1][1] == 'X' && table[0][2] == 'X')
    )
      return false;

}


void player_turn( int player )
{

  unsigned int x, y;
  
  if(player == 0)
  {
    write_screen("Computer will start playing");
    AI();
  }
  
  if(player == 1)
  {
    write_screen("You will start to play");
    
    puts("Insert the cordinates like this: x y");
    scanf("%d %d", &x, &y);
    
    table[y][x] = 'O';
    moves++;
  }
  
}

void AI( void )
{

  register unsigned int x,y;
  
  for( x=0; x<(strlen(*table)/3); x++ )
  {
    for( x=0; x<(strlen(*table)/3); x++ )
    {
      if( table[y][x] != 'O' || table[y][x] != 'X' )
      {
        table[y][x] = 'X';
        break;
      }
      break;
    }
    break;
    
  }

}

unsigned int random_number()
{
  time_t seconds;
  time(&seconds);
  srand((unsigned int) seconds);
  
  return ( rand()%2 );
}