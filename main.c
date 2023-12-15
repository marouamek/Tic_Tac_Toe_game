#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
const char COMPUTER = 'O';
int answer;

void reset_board()
{
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         board[i][j] = ' ';
      }
   }
}

void print_board()
{
   printf("                                               |          |                           \n");
   printf("                                        %c      |   %c      |   %c                      \n", board[0][0], board[0][1], board[0][2]);
   printf("                                     __________|__________|__________                 \n");
   printf("                                               |          |                           \n");
   printf("                                        %c      |   %c      |   %c                      \n", board[1][0], board[1][1], board[1][2]);
   printf("                                     __________|__________|__________                 \n");
   printf("                                               |          |                           \n");
   printf("                                        %c      |   %c      |   %c                      \n", board[2][0], board[2][1], board[2][2]);
   printf("                                               |          |                           \n");
}

int empty_spots()
{
   int empty = 9; // since we have 9 squares 3*3 //

   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (board[i][j] != ' ')
         {
            empty--;
         }
      }
   }
   return empty;
}

void player1()
{
   int R, C;

   do
   {
      printf("Player 1 enter your move :\n");

      printf(" Row number :\n");
      scanf("%d", &R);
      R--;

      printf(" Column number: \n");
      scanf("%d", &C);
      C--;

      if (board[R][C] != ' ')
      {
         printf("Invalid move!\n");
      }
      else
      {
         board[R][C] = PLAYER1;
         break;
      }
   } while (board[R][C] != ' ');
}

void player2()
{
   int M, N;

   do
   {
      printf("Player 2 enter your move :\n");

      printf(" Row number :\n");
      scanf("%d", &M);
      M--;

      printf(" Column number: \n");
      scanf("%d", &N);
      N--;

      if (board[M][N] != ' ')
      {
         printf("Invalid move!\n");
      }
      else
      {
         board[M][N] = PLAYER2;
         break;
      }
   } while (board[M][N] != ' ');
}

void Computer()
{
   // creates a seed based on current time
   srand(time(0));
   int R;
   int C;

   if (empty_spots() > 0)
   {
      do
      {
         R = rand() % 3;
         C = rand() % 3;
      } while (board[R][C] != ' ');

      board[R][C] = COMPUTER;
   }
   else
   {
      print_winner(' ');
   }
}

char winner()
{
   // check row --- horizontally//
   for (int i = 0; i < 3; i++)
   {
      if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }

   // check column--- vertically//
   for (int i = 0; i < 3; i++)
   {
      if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }
   // check axes --- diagonally//

   if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }

   if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }
   return ' ';
}

void print_winner(char Winner)
{
   if (Winner == PLAYER1)
   {
      printf("Player1 WINS!");
   }
   else if (Winner == PLAYER2)
   {
      printf("Player2 WINS�");
   }
   else if (Winner == COMPUTER)
   {
      printf("YOU LOSE!");
   }
   else
   {
      printf("IT'S A TIE!");
   }
}

int main()
{
   int i1 = 1;
   char Winner = ' ';
   char response = ' ';

   while (i1 != 0)
   {

      printf(" \n\n                                                             ********************** Welcome! *********************\n");
      printf("                                                             *                Tic Tac Toe game                   *\n");
      printf("                                                             * 1.Start playing                                   *\n");
      printf("                                                             * 2.Instructions                                    *\n");
      printf("                                                             * 3.Quit                                            *\n");
      printf("                                                             *****************************************************\n");
      printf("Please choose one from 1-3:\n");
      scanf("%d", &i1);

      switch (i1)
      {
      case 1:
         printf(" \n Start the game:\n\n");

         i1 = 0;
         break;
      case 2:
         printf("  Instructions:\n\n");
         printf("      * It's a 3*3 squares game .\n");
         printf("      * Take turn putting 'X' or 'O' in empty squares .\n");
         printf("      * The first to get 3 of the marks in a row wins .\n");
         // i1 = 0;
         break;
      case 3:
         printf("Quit:\n");
         // i1 = 0;
         break;
      }
   }

   printf("                                                             * Welcome once again to the classical game TIC TAC TOE!!!!\n\n");

   printf(" YOU WANNA PLAY AGAINST A FRIEND OR COMPUTER ?\n");
   printf("\n Type 0 for a friend \n Type 1 for a computer \n");
   scanf("%d", &answer);

   if (answer == 0)
   {
      do
      {
         Winner = ' ';
         response = ' ';
         reset_board();

         while (Winner == ' ' && empty_spots() != 0)
         {
            print_board();

            player1();
            Winner = winner();
            if (Winner != ' ' || empty_spots() == 0)
            {
               break;
            }
            print_board(); // here //

            player2();
            Winner = winner();
            if (Winner != ' ' || empty_spots() == 0)
            {
               break;
            }
         }

         print_board();
         print_winner(Winner);

         printf("\nWould you like to play again ? (Y/N): ");
         scanf("%c");
         scanf("%c", &response);
         response = toupper(response); // toupper is a function to convert lowercase alphabets to upper case//
      } while (response == 'Y');
   }

   else if (answer == 1)
   {
      do
      {
         Winner = ' ';
         response = ' ';
         reset_board();

         while (Winner == ' ' && empty_spots() != 0)
         {
            print_board();

            player1();
            Winner = winner();
            if (Winner != ' ' || empty_spots() == 0)
            {
               break;
            }

            Computer();
            Winner = winner();
            if (Winner != ' ' || empty_spots() == 0)
            {
               break;
            }
         }

         print_board();
         print_winner(Winner);

         printf("\nWould you like to play again? (Y/N): ");
         scanf("%c");
         scanf("%c", &response);
         response = toupper(response); // toupper is a function to convert lowercase alphabets to upper case//
      } while (response == 'Y');
   }

   return 0;
}
