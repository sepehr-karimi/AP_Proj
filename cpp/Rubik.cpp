#include"Rubik.h"
//Rubik constructor
Rubik::Rubik(std::array<int,24> ini) 
{
    initial = ini;
}
// this function gets 4 inputs and rotation if  Clockwise(C) & CounterClockwise(I)
void Rubik::swap(int &a0,int &a1,int &a2,int &a3,char &direction)
{
    if (direction == 'C' )
    {
    int t=a3;
    a3=a2;
    a2=a1;
    a1=a0;
    a0=t;
    }
    else if (direction == 'I' )
    {
    int t=a0;
    a0=a1;
    a1=a2;
    a2=a3;
    a3=t;
    }
}

//faces are U D L R F B
//MEANS     1 2 3 4 5 6
//as Up Down Right Left Front Back
Rubik Rubik::Rotaion(int Face,char direction)
{
    //direction is clockwise what are the faces?
    std::array<int,24 > initial_backup = initial;
    //Face = Up
    if(Face == 3)
    {
        //std::cout<<"here \n";
        swap(initial[8],initial[9],initial[11],initial[10],direction);
        swap(initial[5],initial[3],initial[14],initial[16],direction);
        swap(initial[2],initial[12],initial[17],initial[7],direction);

    }
    //Face = Down
    else if(Face == 6)
    {
        swap(initial[23],initial[22],initial[20],initial[21],direction);
        swap(initial[13],initial[0],initial[6],initial[19],direction);
        swap(initial[1],initial[4],initial[18],initial[15],direction);
    }
    //Face = Left
    else if(Face == 2)
    {
        swap(initial[5],initial[7],initial[6],initial[4],direction);
        swap(initial[2],initial[10],initial[18],initial[22],direction);
        swap(initial[8],initial[16],initial[20],initial[0],direction);
    }
    //Face = Right
    else if(Face == 4)
    {
        swap(initial[14],initial[12],initial[13],initial[15],direction);
        swap(initial[17],initial[9],initial[1],initial[21],direction);
        swap(initial[11],initial[3],initial[23],initial[19],direction);
    }
    //Face = Front
    else if(Face == 5)
    {
        swap(initial[16],initial[17],initial[19],initial[18],direction);
        swap(initial[7],initial[11],initial[15],initial[20],direction);
        swap(initial[10],initial[14],initial[21],initial[6],direction);
    }
    //Face = Back
    else if(Face == 1)
    {
        swap(initial[3],initial[2],initial[0],initial[1],direction);
        swap(initial[12],initial[8],initial[4],initial[23],direction);
        swap(initial[9],initial[5],initial[22],initial[13],direction);
    }
    initial.swap(initial_backup);
    return Rubik(initial_backup);
}

//goal test 
bool Rubik::goal_test()
{
    size_t res{};
    //if all the 6 faces have the same color
    for(size_t i{} ;i < 6 ;i++)
    {
        if(initial[4*i] == initial[(4*i)+1] && initial[(4*i)] == initial[(4*i)+2] && initial[(4*i)] == initial[(4*i)+3])
        {  
            res++;
        }
    }
    if (res==6)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//first way of showing Cube White color second way at the end of the code
void Rubik::show()
{

    //BACK
    std::cout<<std::setw(19) <<"+--------+"<<std::endl;
    std::cout<<std::setw(12) <<"|  " << initial[0]    <<std::setw(3) << initial[1]  <<"  |"  <<std::endl;
    std::cout<<std::setw(12) <<"|  " << initial[2]    <<std::setw(3) << initial[3]  <<"  |"  <<std::endl;
    std::cout <<"+--------+--------+--------+"<<std::endl;
    //LEFT UP  RIGHT
    //Line 1
    std::cout<<"|  "  << initial[4]   <<std::setw(3) <<initial[5]   <<"  |";
    std::cout <<std::setw(3)  << initial[8]    <<std::setw(3) <<initial[9]  ;
    std::cout <<"  |  "   <<initial[12]    <<std::setw(3) <<initial[13]    <<"  |"<<std::endl;
    //line 2
    std::cout<<"|  "  << initial[6]    <<std::setw(3) <<initial[7]   <<"  |";
    std::cout <<std::setw(3)  << initial[10]    <<std::setw(3) <<initial[11]  ;
    std::cout <<"  |  "  <<initial[14]    <<std::setw(3) <<initial[15]    <<"  |"<<std::endl;

    //Front
    std::cout <<"+--------+--------+--------+"<<std::endl;
    std::cout<<std::setw(12) <<"|  "  << initial[16]    <<std::setw(3) <<initial[17]      <<"  |"  <<std::endl;
    std::cout<<std::setw(12) <<"|  "  << initial[18]    <<std::setw(3) <<initial[19]      <<"  |"  <<std::endl;

    //Down
    std::cout<<std::setw(19) <<"+--------+"<<std::endl;
    std::cout<<std::setw(12) <<"|  " << initial[20]     <<std::setw(3) << initial[21]    <<"  |"  <<std::endl;
    std::cout<<std::setw(12) <<"|  " << initial[22]     <<std::setw(3) << initial[23]    <<"  |"  <<std::endl;
    std::cout<<std::setw(19) <<"+--------+"<<std::endl<<std::endl;
}
//set rotation
void Rubik::set_parent_rotation (int a)
{
    Parent_Rotation = a;
}
//get rotation
int Rubik::get_parent_rotation ()
{
    return Parent_Rotation;
}

//show The Rubik with beautiful colors
void Rubik::showColored()
{
    std::string colors[24];
    for(size_t i{} ;i<24 ; i++)
    {
        if(initial[i] == 1)
            {colors[i] = "\033[34m";}
        if(initial[i] == 2)
            {colors[i] = "\033[31;1m";}
        if(initial[i] == 3)
            {colors[i] = "\033[37m";}
        if(initial[i] == 4)
            {colors[i] = "\033[31m";}
        if(initial[i] == 5)
            {colors[i] = "\033[32m";}
        if(initial[i] == 6)
            {colors[i] = "\033[33;1m";}
    }
    //BACK
    std::cout<<RESET;
    std::cout<<std::setfill(' ')<<std::setw(19) <<"+--------+"<<std::endl;
    std::cout<<std::setfill(' ')<<std::setw(12) <<"|  " << colors[0]<< initial[0]   << colors[1] <<"  " << initial[1] <<RESET  <<"  |"  <<std::endl;
    std::cout<<std::setfill(' ')<<std::setw(12) <<"|  " << colors[2]<< initial[2]   << colors[3] <<"  " << initial[3] <<RESET  <<"  |"  <<std::endl;
    std::cout <<"+--------+--------+--------+"<<std::endl;
    //LEFT UP  RIGHT
    //Line 1
    
    std::cout<<"|  " << colors[4] << initial[4] <<"  "  << colors[5]  <<initial[5] <<RESET <<"  |"
    <<"  " << colors[8]   << initial[8]   <<"  " << colors[9] <<initial[9] <<RESET
    <<"  |  " << colors[12]  <<initial[12]  << colors[13] <<"  " <<initial[13]  <<RESET <<"  |"<<std::endl;
    //line 2
    std::cout<<"|  " << colors[6] << initial[6] <<"  "  << colors[7]  <<initial[7] <<RESET <<"  |"
     <<"  " << colors[10]   << initial[10] <<"  " << colors[11] <<initial[11] <<RESET
    <<"  |  " << colors[14]  <<initial[14]  << colors[15] <<"  " <<initial[15]  <<RESET <<"  |"<<std::endl;

    //Front
    std::cout <<"+--------+--------+--------+"<<std::endl;
    std::cout<<std::setfill(' ') <<std::setw(12) <<"|  " << colors[16] << initial[16]  << colors[17] <<"  " <<initial[17] <<RESET    <<"  |"  <<std::endl;
    std::cout<<std::setfill(' ') <<std::setw(12) <<"|  " << colors[18] << initial[18]  << colors[19] <<"  " <<initial[19] <<RESET    <<"  |"  <<std::endl;

    //Down
    std::cout<<std::setfill(' ') <<std::setw(19) <<"+--------+"<<std::endl;
    std::cout<<std::setfill(' ') <<std::setw(12) <<"|  " << colors[20] << initial[20]  << colors[21] <<"  " << initial[21] <<RESET  <<"  |"  <<std::endl;
    std::cout<<std::setfill(' ') <<std::setw(12) <<"|  " << colors[22] << initial[22]  << colors[23] <<"  " << initial[23] <<RESET  <<"  |"  <<std::endl;
    std::cout<<std::setfill(' ') <<std::setw(19) <<"+--------+"<<std::endl<<std::endl;
}

//operator == to seen if 2 cubes are the same?
bool Rubik::operator ==(Rubik &b) const
{
    size_t CNT{};
    for (size_t i{}; i < 24; i++)
    {
        if(b.initial[i] == this->initial[i])
            CNT++;
    }
    if (CNT==24)
    {
        return true;
    }
    else
    {
        return false;
    }
}
