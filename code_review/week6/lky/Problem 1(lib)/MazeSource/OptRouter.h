//////////////////////////////////////////////////////////////////////////
// Description: this is the base implementation of a simple maze router
// Author: YHL
// Date: 20120323
// Note: Modify this file and add OptRouter.cpp file for the
//       implementation of the additional functionalities
//////////////////////////////////////////////////////////////////////////
#ifndef OPT_ROUTER_H_
#define OPT_ROUTER_H_

#include <climits>
#include <cstdio>
#include <vector>
#include <list>

#include "BaseRouter.h"

class OptRouter:public BaseRouter
{
private:
    int MinTurn = 1000000, 
        MaxTurn = 0;
    std::vector <int> MinTurnPath;
    std::vector <int> MaxTurnPath;
public:
    OptRouter(int r, int c, const Point &source, const Point &target, const PointVector &obs)
        : BaseRouter(r, c, source, target, obs) {}
	~OptRouter() {}
    void mazeBacktrace(int nowIndex, std::vector <int> NowPath, int NowTurn, bool Vertical);
    void mazeBacktrace() {
        std::vector <int> tmp;
        tmp.push_back(m_targetIndex);
        mazeBacktrace(m_targetIndex, tmp, 0, 0);
    }
    bool route(void);
    void showMaxPath();
    void shoeMinPath();
    void showMaxTurn();
    void showMinTurn();
};

#endif
