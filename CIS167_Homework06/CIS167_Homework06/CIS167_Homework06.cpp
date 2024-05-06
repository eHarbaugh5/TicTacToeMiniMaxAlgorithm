// ========================
//  Tic Tac Toe MiniMax Algorithm
//  Evan Harbaugh
// ========================

#include <iostream>
#include "string"
#include "Board.h"

using namespace std;

void displayCurrentBoard(Board);
int aiMinMax(Board, bool);
int startAiMinMax(Board, bool);

int main()
{
    int playAgain = 1;

    //  GAME LOOP ========================================================
    do {



        Board gameBoard;

        bool playerTurn = true;

        int timer = 9;

        int startingTurn;

        system("cls");

        do {
            cout << "Who Goes First? [1->You] or [2->Ai] or [3->Random]" << endl;
            cin >> startingTurn;
        } while (startingTurn < 1 && startingTurn > 3);
        
        if (startingTurn == 3)
        {
            startingTurn = rand() % 2 + 1;
        }

        if (startingTurn == 1)
        {
            playerTurn = true;
        }
        else
        {
            playerTurn = false;
        }
        

        system("cls");

        //  display initial board
        displayCurrentBoard(gameBoard);



        //  Gameplay Loop 
        do {



            if (playerTurn)
            {

                int userInput;
                int inputX;
                int inputY;

                //  ask until a piece is placed

                do {

                    //  ask until proper input is given

                    do {


                        cout << "Choose a location" << endl;

                        cin >> userInput;
                    } while (userInput < 0 || userInput > 8);



                    inputX = userInput % 3;
                    inputY = (userInput - inputX) / 3;




                } while (!gameBoard.canPlacePiece(inputX, inputY));




                gameBoard.addPiece(inputX, inputY, "X");

            }
            else
            {

                cout << "Ai turn" << endl;
                int aiX;
                int aiY;
                int aiPlacement = startAiMinMax(gameBoard, false);

                aiX = aiPlacement % 3;
                aiY = (aiPlacement - aiX) / 3;

                gameBoard.addPiece(aiX, aiY, "O");


            }
            //  display board after each move
            system("cls");
            displayCurrentBoard(gameBoard);
            if (gameBoard.checkForWinner() != "N")
            {
                timer = 0;
            }


            playerTurn = !playerTurn;
            timer--;

        } while (timer > 0);

        cout << "Winner : " << gameBoard.checkForWinner() << endl;



        cout << endl << endl << endl;

        do {
            cout << "Play Again [1-> Yes] or [2-> No]" << endl;
            cin >> playAgain;
        } while (playAgain != 1 && playAgain != 2);
        
        



    } while (playAgain == 1);
    //  GAME LOOP ========================================================


}


int startAiMinMax(Board miniBoard, bool min)
{

    int bestScore = -99;
    int a;
    int b;

    for (int y = 0; y < 3; y++)
    {


        for (int x = 0; x < 3; x++)
        {


            //  Tally all of the possible moves down to the last turn

            if (miniBoard.canPlacePiece(x, y))
            {

                Board boardToPass = miniBoard;
                boardToPass.addPiece(x, y, "O");

                int currScore = aiMinMax(boardToPass, !min);

                if (currScore > bestScore)
                {
                    bestScore = currScore;
                    a = y;
                    b = x;
                }

            }
           


        }

    }

    //  make best move
    //  place move at 

    return (a * 3) + b;
    


}


int aiMinMax(Board miniBoard, bool min)
{

    if (miniBoard.checkForWinner() == "O")
    {
        return 1;
    }
    else if (miniBoard.checkForWinner() == "X")
    {
        return -1;
    }
    else if (miniBoard.checkForWinner() == "C")
    {
        return 0;
    }
    
    
    

    string turn;
    if (min)
    {
        //  MINIMIZING
        //  player turn

        turn = "X";
        int bestScore = 10;

        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {

                if (miniBoard.canPlacePiece(x, y))
                {

                    Board boardToPass = miniBoard;
                    boardToPass.addPiece(x, y, turn);
                    int currScore = aiMinMax(boardToPass, !min);
                    
                    if (currScore < bestScore)
                    {
                        bestScore = currScore;

                    }

                }

            }

        }
        //  once all posible scenarios have been ran
        //  return max
        return bestScore;
    }
    else
    {


        //  MAXIMIZING
        //  ai turn

        turn = "O";
        int bestScore = -10;

        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {

                if (miniBoard.canPlacePiece(x, y))
                {

                    Board boardToPass = miniBoard;
                    boardToPass.addPiece(x, y, turn);
                    int currScore = aiMinMax(boardToPass, !min);
                    if (currScore > bestScore)
                    {
                        bestScore = currScore;

                    }

                }

            }

        }
        //  once all posible scenarios have been ran
        //  return max
        return bestScore;



    }



}



void displayCurrentBoard(Board gameBoard)
{


    //  EXAMPLE SPACES
    for (int i = 0; i < 3; i++)
    {
        cout << "     ";
        for (int j = 0; j < 3; j++)
        {

            cout << gameBoard.getBoardPiece(j, i);
            if (j != 2)
            {
                cout << " | ";
            }

        }
        
        
        if (i != 2)
        {
            cout << endl << "     " << "----------" << endl;

        }
        
    }

    cout << "\n\n\n";

    //  ACTUAL BOARD
    for (int i = 0; i < 3; i++)
    {
        cout << "     ";
        for (int j = 0; j < 3; j++)
        {
            if (gameBoard.getBoardPiece(j, i) == "X" || gameBoard.getBoardPiece(j, i) == "O")
            {
                cout << gameBoard.getBoardPiece(j, i);
            }
            else
            {
                cout << " ";
            }
            if (j != 2)
            {
                cout << " | ";
            }

        }
        if (i != 2)
        {
            
            cout << endl << "     " << "----------" << endl;

        }
        
    }

    cout << "\n\n\n";





}





