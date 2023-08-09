//Mark Negus
//Battleship Game Project 
//In this game, the program randomly sets up each ship without them running into each other or off the edge of the board. The user guesses spaces until every ship has been sunk. 
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <unistd.h>
using namespace std;

int board[10][10] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

int displayBoard[10][10] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
void printDisplayBoard (){
      for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
	{
	  cout << displayBoard[i][j] << " ";
	}
      cout << endl;
    }
  return;
    
}

void
printBoard ()
{
  for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
	{
	  cout << board[i][j] << " ";
	}
      cout << endl;
    }
  return;
}

//Sets up an individual ship on the board
void setUp(int length){
  srand (time (NULL));
   
  int shipPosition;		//  The vertical or horizontal orientation of the ship,determined by the rand function
  int shipCol;
  int shipRow;
  int randStartPoint = rand() % (10-length); //Ensures that the ship never goes off the board

  shipPosition = rand () % 2;	// Either 0 or 1 

    if (shipPosition == 0)        
     {
        shipCol = rand () % 10;
      
      for (int i = randStartPoint; i <(randStartPoint + length); i++)
	    {
    	  if(board[i][shipCol] != 1)
    	  {
    	    board[i][shipCol] = 1;
    	  }
    	   else
    	  {
    	      setUp(length); //Recursion ensures that the ships dont run into each other
    	  }
	    }

    }
  else
    {
      shipRow = rand () % 10;
      for (int j = randStartPoint; j <(randStartPoint + length); j++)
	{
      if(board[shipRow][j] != 1)
      {
      board[shipRow][j] = 1;
      }
      else
      {
          setUp(length);
      }
	}

    }
}

int
main ()
{ 
  int row; 
  int column;
  int hits = 0; 
  int carrier    = 5;  
  int destroyer  = 4;
  int submarine  = 3;
  int battleship = 3;
  int tugBoat    = 2; 

  setUp(carrier);
  sleep(1);             //Delay so that the rand function generates a new value each time
  setUp(destroyer);
  sleep(1);
  setUp(submarine);
  sleep(1);
  setUp(battleship);
  sleep(1);
  setUp(tugBoat);
  
  printDisplayBoard();
  
  //The total length of the ships is 5+4+3+3+2 = 17      
  while(hits <= 17){                               
  cout << "A '1' indicates a hit, a '8' indicates a miss"<< endl;   
  cout << "Enter the i coordinate (0-9) of the space: " << endl;
  cin >> row; 
  cout << "Enter the j coordinate (0-9) of the space: " << endl;
  cin >> column; 
 
     if(board[row][column] == 1){
         cout << "Hit"<< endl;
         hits++;
         displayBoard[row][column] = 1;
         printDisplayBoard();
     }else{
         cout << "Miss" << endl;
         displayBoard[row][column] = 8;
         printDisplayBoard();

     }
 }
 

}








