#include "data.h"

//volatile unsigned char *first_player_n = calloc(9, sizeof(char));
//volatile unsigned char *second_player_n = calloc(9, sizeof(char));

/* Board

    [_]    [_]    [_]


    [_]    [_]    [_]


    [_]    [_]    [_]
*/
unsigned char table[3][3] = {{'_','_','_'},
                             {'_','_','_'},
                             {'_','_','_'}};

// End of board definition
                             
                             
unsigned int turn=0, moves=0;
                     
                     
// Function to draw Board, That only make it and no logic are implemented here.
void draw_table( void )
{

  register  unsigned int x=0,
                         y=0;
  
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

  if( (table[0][0] == 'O' and table[1][0] == 'O' and table[2][0] == 'O') ||
      (table[0][1] == 'O' and table[1][1] == 'O' and table[2][1] == 'O') ||
      (table[0][2] == 'O' and table[1][2] == 'O' and table[2][2] == 'O') ||
      
      (table[0][0] == 'O' and table[0][1] == 'O' and table[0][2] == 'O') ||
      (table[1][0] == 'O' and table[1][1] == 'O' and table[1][2] == 'O') ||
      (table[2][0] == 'O' and table[2][1] == 'O' and table[2][2] == 'O') ||
       
      (table[0][0] == 'O' and table[1][1] == 'O' and table[2][2] == 'O') ||
      (table[2][0] == 'O' and table[1][1] == 'O' and table[0][2] == 'O')
    )
      return true;
  
  if( (table[0][0] == 'X' and table[1][0] == 'X' and table[2][0] == 'X') ||
      (table[0][1] == 'X' and table[1][1] == 'X' and table[2][1] == 'X') ||
      (table[0][2] == 'X' and table[1][2] == 'X' and table[2][2] == 'X') ||
     
      (table[0][0] == 'X' and table[0][1] == 'X' and table[0][2] == 'X') ||
      (table[1][0] == 'X' and table[1][1] == 'X' and table[1][2] == 'X') ||
      (table[2][0] == 'X' and table[2][1] == 'X' and table[2][2] == 'X') ||
     
      (table[0][0] == 'X' and table[1][1] == 'X' and table[2][2] == 'X') ||
      (table[2][0] == 'X' and table[1][1] == 'X' and table[0][2] == 'X')
    )
      return false;

}


int player_turn( int player )
{

  unsigned int x,
               y;
  
  if(player == 0)
  {
    write_screen("Computer will start playing");
    AI();
    moves++;
    player = 1;
  }
  
  if(player == 1)
  {
    write_screen("You will start to play");
    
    puts("Insert the cordinates like this: x y");
    scanf("%d %d", &x, &y);
    
    if(table[y][x] == 'O' || table[y][x] == 'X') 
    {
      
      do {
        
        write_screen("This position is already checked, please choose another.");
        scanf("%d %d", &x, &y);
        
        if(table[y][x] != 'O' || table[y][x] != 'X')
        {
          table[y][x] = 'O';
          return false;
        }
      } while(true);
      
    } else { table[y][x] = 'O'; }
    
    moves++;
    
    player = 0;
  }
  
  return player;
  
}

void AI( void )
{

  register unsigned int x=0,
                        y=0;
  
  for( y; y<(strlen(*table)/3); y++ )
  {
    for( x; x<(strlen(*table)/3); x++ )
    {
      volatile unsigned int c = 0;
      for(c=0;c<190000000; c++);
    
      if( table[y][x] != 'O' && table[y][x] != 'X' )
      {
        table[y][x] = 'X';
        //system("tput reset");
        draw_table();
        printf("Computer plays in : %d %d\n", x, y);
        return;
      }
      else{ continue; }
    }
  }

}

unsigned int random_number()
{
  time_t seconds;
  time(&seconds);
  srand((unsigned int) seconds);
  
  return ( rand()%2 );
}