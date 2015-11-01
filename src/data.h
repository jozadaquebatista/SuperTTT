#ifndef DATA_H
#define DATA_H

#pragma once

#ifdef BUFSIZ
  #undef BUFSIZ
  #define BUFSIZ 64
#else
  #define BUFSIZ 64
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#ifdef nullptr
  #undef nullptr
  #define nullptr (void*)0
#else
  #define nullptr (void*)0
#endif

// stdbool.h
#ifdef true
  #undef true
  #define true 1
#endif
#ifdef false
  #undef false
  #define false 0
#endif

#define and &&

#define write_screen(str)(puts(str))
#define draw(ptr,x,y)(printf("    [%c]", ptr[y][x]))
#define line_break (puts("\n\n"))

// 0 1
extern const unsigned char *first_player_n;
extern const unsigned char *second_player_n;

extern unsigned int turn, moves;

// Where table[0][0] is the winner
extern unsigned char table[3][3];

extern void draw_table( void );

// If someone wins, then print the winner and return 0
extern _Bool check_winner( void ); // unsigned int *foo

extern int player_turn( int );

extern void AI( void );

extern unsigned int random_number( void );

#endif