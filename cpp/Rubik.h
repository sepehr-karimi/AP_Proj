#ifndef RUBIK_H
#define RUBIK_H

#include<iostream>
#include<array>
#include <iomanip>
#include<vector>

#define RESET   "\033[0m"

class Rubik
{
    private:
        std::array<int,24 > initial;
        int Parent_Rotation{};
        Rubik parent();

    public:
        //constructors
        Rubik(std::array<int,24 >);
        Rubik() = default;

        //functions
        void swap(int &a0,int &a1,int &a2,int &a3,char &direction);
        Rubik Rotaion(int,char);
        void show();
        void showColored();
        bool goal_test ();
        void set_parent_rotation (int a);
        int get_parent_rotation ();

        //operators
        bool operator ==(Rubik &b) const;
};

#endif   /* defined(RUBIK_H) */