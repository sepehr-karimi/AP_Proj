#include"main.h"
int main()
{
    std::array<int,24 > Input =   GetInputs();
    std::cout << "\033[34m" << "DO YOU WANT TO DO DLS ALGORITHM OR IDS? (0 or 1)>>>>>" <<"\033[0m"<<std::endl;
    std::cout << "\033[34m" << "<<<<<[IDS algorithm = 1] , [DLS algorithm = 0 (default limit = 8) ]>>>>>" <<"\033[0m"<<std::endl;
    bool algorithm{};
    std::cin>>algorithm; //inputs the algorithm ids or dfs
    Rubik input(Input);
    std::cout << "Your input Cube is :"<<std::endl<<std::endl;
    input.showColored();
    RubikSolver A(input,algorithm); //solve the Rubik

    //////////////////////////////////////        Test              ///////////////////////////////////////
    //[(1, 'clockwise')] --->test1
    std::array<int,24 > Test1 = {1,1,1,1   ,6,6,2,2   ,2,2,3,3   ,3,3,4,4    ,5,5,5,5   ,6,6,4,4}; 

    //[(2, 'clockwise'), (2, 'clockwise')] --->test2
    std::array<int,24 > Test2 = {4,2,4,2   ,6,6,6,6   ,1,5,1,5   ,3,3,3,3    ,2,4,2,4   ,5,1,5,1};

    //[(1, 'clockwise'), (3, 'clockwise'), (3, 'clockwise')] --->test3
    std::array<int,24 > Test3 = {1,5,1,5   ,6,6,2,4   ,2,4,3,3   ,3,3,2,4    ,1,1,5,5   ,6,6,4,2};

    //[(2, 'anticlockwise'), (3, 'anticlockwise'), (1, 'anticlockwise'), (2, 'anticlockwise'), (1, 'anticlockwise')] --->test4
    std::array<int,24 > Test4 = {5,6,3,4   ,2,1,5,4   ,2,6,3,6   ,1,5,1,4    ,1,2,3,5   ,4,6,3,2};
    //////////////////////////////////////         Test           ///////////////////////////////////////
    return 0;
}
//Get Inputs by seperation of faces
std::array<int,24 > GetInputs()
{
    std::array<int,24 > Input; //to store the faces
    size_t i{};
    std::cout << "\033[31m" << "<<<<<Please Enter Cube Face colors as numbers like: 1,2,3,4 >>>>>" <<"\033[0m"<<std::endl;
    while(i<6) //while for each face Cin seperately
    {
        std::string Temp; 
        //getting the input
        std::cout<<"Surface " <<i+1 <<":  ";
        std::cin>>Temp; //store in a stirng Temp
        std::cout<<std::endl;
        //seperate inputs by <,>
        std::stringstream ss(Temp); 
        size_t num{i*4};
        while( ss.good() )
        {
            std::string substr;
            getline( ss, substr, ',' );
            Input[num] = std::stoi(substr);
            num++;
        }
        //if the Face was insertet correct???
        std::array<int,4> surface;
        for (size_t s{}; s < 4; s++)
        {
            surface[s] = Input[4*i + s];
        }
        if(Correct_surface(surface))
            i++;
        else
        {
            std::cout<<"Bad input!!! please reEnter your numbers!" <<std::endl <<std::endl;
        }
            
    }
    //If the hole cube was inserted correct???
    if(Correct_input(Input))
    {
        return Input;
    }
    else
    {
        std::cout<<"<<<<<<<<Bad Cube!! this cube doesn't exist!!!!>>>>>>>>" <<std::endl <<std::endl;
        exit (EXIT_FAILURE); //Terminate Program
    }
}
//if each 4 number of Face are Correct
bool Correct_surface(std::array<int,4> surface)
{
    size_t temp{}; //to store the CNT of the correctly inserted numbers
    for (size_t i{} ;i<4 ; i++)
    {
        if (surface[i] < 7 && surface[i] > 0)
            temp++;
    }
    //if all the numbers were right temp equals 4
    if (temp == 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//This is to see if Rubik numbers Are Correct Or Not!
bool Correct_input(std::array<int,24> input)
{
    int cnt[7] = {0,0,0,0,0,0,0};
    int cnt_num_faces{};
    //how many of each color are there?
    for (size_t i{}; i < 24; i++)
    {
        for (size_t j{1}; j < 7; j++)
        {
           if (j==input[i])
           {
               cnt[j]++;
           }
           
        }
        
    }
    //what colors are inserted right?
    for (size_t i = 1; i < 7; i++)
    {
        if (cnt[i] == 4)
        {
            cnt_num_faces++;
        }
    }
    //if inserted right : good!
    if (cnt_num_faces==6)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}