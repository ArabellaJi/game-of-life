#ifndef PROJECT1_H
#define PROJECT1_H
using std::cin;
using std::cout;
using std::endl;

class Project1 {
public:
    // initial the board
    void initial();
    // display the board 
    void display();
    // update the information of the board
    void update();

private:
    static const int activeRows = 18; 
    static const int activeCols = 50; 
    static const int totalRows = activeRows + 2; 
    static const int totalCols = activeCols + 2;
    int board[totalRows][totalCols];
    int generation;    
};

#endif