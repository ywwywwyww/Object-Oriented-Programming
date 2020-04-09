#include "OptRouter.h"

#include <iostream>
#include <vector>

const static int X[4] = { 1,-1,0,0 };
const static int Y[4] = { 0,0,1,-1 };

void OptRouter::mazeBacktrace(int nowIndex, std::vector <int> NowPath, int NowTurn, bool Vertical) {
    if (nowIndex == m_sourceIndex) {                        //reach the source point
        if (NowTurn < MinTurn) {
            MinTurnPath = NowPath;
            MinTurn = NowTurn;
        }
        if (NowTurn > MaxTurn) {
            MaxTurnPath = NowPath;
            MaxTurn = NowTurn;
        }
    }

    int x, y;
    this->compXYIndex(nowIndex, x, y);

    for (int i = 0; i < 4; ++i) {
        int newX = x + X[i], newY = y + Y[i];
        if (newY >= 0 && newY < this->m_row && newX < this->m_col && newX >= 0)
        {
            int newIndex = this->compIndex(newX, newY);
            if (m_grids[newIndex] == m_grids[nowIndex] - 1) {       //if newIndex is the privious node
                bool NewVertical = false;                           //initialize
                int NewTurn = NowTurn;
                if (Y[i] != 0) NewVertical = true;                  //whether the move is vertical or not
                if (NewVertical != Vertical) NewTurn += 1;
                NowPath.push_back(newIndex);
                mazeBacktrace(newIndex, NowPath, NewTurn, NewVertical);
                NowPath.pop_back();
            }
        }
    }
}
bool OptRouter::route(void)
{
    if (this->m_sourceIndex < 0 || this->m_targetIndex < 0 || this->m_row <= 0 || this->m_col <= 0)
        return false;

    this->m_path.clear();

    //initialize the cost of the source grid
    m_grids[this->m_sourceIndex] = 0;

    //maze expansion
    if (mazeSearch())
    {
        mazeBacktrace();
        return true;
    }
    else
        return false;
}
  
void OptRouter::showMaxPath() {                             //show the path with most turn
    printf("Found MaxTurn path: ");
    for (unsigned i = 0; i < this->MaxTurnPath.size(); ++i)
    {
        int index = this->MaxTurnPath[i];
        int x, y;
        this->compXYIndex(index, x, y);
        printf("[%d,%d] ", x, y);
    }
    printf("\n");
}
void OptRouter::shoeMinPath()                               //show the path with least turn
{
    printf("Found MinTurn path: ");
    for (unsigned i = 0; i < this->MinTurnPath.size(); ++i)
    {
        int index = this->MinTurnPath[i];
        int x, y;
        this->compXYIndex(index, x, y);
        printf("[%d,%d] ", x, y);
    }
    printf("\n");
}
void OptRouter::showMaxTurn()                               //show the turnNum
{
    std::cout << "The Max TurnNum is:\t" << MaxTurn << std::endl;
}
void OptRouter::showMinTurn()                               //show the turnNum
{
    std::cout << "The Min TurnNum is:\t" << MinTurn << std::endl;
}
;

