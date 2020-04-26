#ifndef RUBIKSOLVER_H
#define RUBIKSOLVER_H

#include<iostream>
#include<array>
#include <iomanip>
#include<vector>
#include"Rubik.h"
#include<sstream>
#include<stack>

class RubikSolver
{
    private:
        bool answer;
        std::vector <int> actions;
        std::stack <Rubik> Explored;
        bool algorithm ;

    public:
        //constructor
        RubikSolver(Rubik,bool = true);
        RubikSolver() = default;

        //functions
        bool DLS(Rubik a , int limit,std::stack <Rubik> &stack);
        bool IDS(Rubik problem);
        Rubik solver_rotation(Rubik, int);
        bool searchExploredByState(Rubik &a);
        void PrintRotations();
};

#endif   /* defined(RUBIKSOLVER_H) */