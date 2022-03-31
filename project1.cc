#include <iostream>
using namespace std;
#include "project1.h"

// INSTRUCTION: The following code can be used to clear the screen before the initial board is displayed.
static const char ESC = 27;

void Project1::initial() {
    // set the value of all locations in the board equal to 0 first
    for (int row = 0; row < totalRows; row++) {
        for (int column = 0; column < totalCols; column++) {
            board[row][column] = 0;
        }
    }
    
    // read the inputs of the user
    // set the value of the locations in the board with living organism equal to 1
    int organismNumber;
    int x;
    int y;
    cout << "How many organisms initially?" << endl;
    cin >> organismNumber;
    cout << "Locations?" << endl;
    for (int i = 0; i < organismNumber; i++) {
        cin >> x;
        cin >> y;
        board[x][y] = 1;
    }
    cout << "Generations?" << endl;
    cin >> generation;
}

void Project1::display() {
    // print the first row of the board
    for (int column = 0; column < totalCols; column++) {
        if (column == 0 || column == totalCols - 1) {
            cout << "+";
        } else {
            cout << "-";
        }
    }
    cout << "\n";

    // print the second to the penultimate row of the board
    for (int row = 1; row < activeRows + 1; row++) {
        cout << "|";
        for (int column = 1; column < activeCols + 1; column++) {
            if (board[row][column] == 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "|\n";
    }

    // print the last row of the board
    for (int column = 0; column < totalCols; column++) {
        if (column == 0 || column == totalCols - 1) {
            cout << "+";
        } else {
            cout << "-";
        }
    }
    cout << "\n";
}

void Project1::update() {
    // create a new board
    int newBoard[totalRows][totalCols];
    // set the value of all locations in the new board equal to 0
    for (int row = 0; row < totalRows; row++) {
        for (int column = 0; column < totalCols; column++) {
            newBoard[row][column] = 0;
        }
    }

    // go through each generation
    for (int i = 0; i < generation; i++) {
        // go through each location
        for (int row = 1; row < activeRows + 1; row++) {
            for (int column = 1; column < activeCols + 1; column++) {
                int countNeighbor = 0;

                // find the location with living organism
                if (board[row][column] == 1) {
                    // go though the neighbors
                    for (int smallRow =  row - 1; smallRow <= row + 1; smallRow++) {
                        for (int smallCol =  column - 1; smallCol <= column + 1; smallCol++) {
                            if (board[smallRow][smallCol] == 1) {
                                countNeighbor++;
                            }
                        }
                    }
                    // remove itself
                    countNeighbor--;
                    // decide if the organism is still alive in the next generation
                    if (countNeighbor == 2 || countNeighbor == 3) {
                        newBoard[row][column] = 1;
                    } else {
                        newBoard[row][column] = 0;
                    }
                }

                // find the location with no living organism
                else {
                    // go though the neighbors
                    for (int smallRow =  row - 1; smallRow <= row + 1; smallRow++) {
                        for (int smallCol =  column - 1; smallCol <= column + 1; smallCol++) {
                            if (board[smallRow][smallCol] == 1) {
                                countNeighbor++;
                            }
                        }
                    }
                    // decide if the organism will be born in the next generation
                    if (countNeighbor == 3) {
                        newBoard[row][column] = 1;
                    } else {
                        newBoard[row][column] = 0;
                    }
                }
            }
        }
        // update the original board
        for (int row = 1; row < activeRows + 1; row++) {
            for (int column = 1; column < activeCols + 1; column++) {
                board[row][column] = newBoard[row][column];
            }
        }
        // INSTRUCTION: The following code can be used to give the appearance of animation. 
        cout << ESC << "[H" << "Generation " << i + 1 << ":" << endl;
        // display the board for each generation
        display();
        // INSTRUCTION: The following code can be used to prompt the user to press Return after each generation.
        cout << ESC << "[23;1H" << ESC << "[K" << "Press RETURN to continue"; 
        while (cin.get() != '\n') { }
    }
}

int main() {
    Project1 p = Project1();
    cout << "Welcome to Arabella Ji and Andrew Wang's game of life!" << endl;
    p.initial();
    // INSTRUCTION: The following code should be used to flush the input buffer after reading input from the user.
    while (cin.get() != '\n') { } 
    // INSTRUCTION: The following code can be used to clear the screen before the initial board is displayed.
    cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;
    p.display();
    // INSTRUCTION: The following code can be used to prompt the user to press Return after each generation.
    cout << ESC << "[23;1H" << ESC << "[K" << "Press RETURN to continue"; 
    while (cin.get() != '\n') { }
    p.update();
    return 0;
}