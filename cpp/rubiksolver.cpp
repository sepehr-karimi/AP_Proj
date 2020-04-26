#include"rubiksolver.h"


RubikSolver::RubikSolver(Rubik a,bool algorithm)
{
    this->algorithm = algorithm;
    //if the user wants IDS or DLS algorithm
    if(algorithm)
    {
        answer = IDS(a); //default depth ==10
    }
    else
    {
        std::stack <Rubik> stack;
        answer = DLS(a,8,stack); //Default dls depth ===8
    }
    //if we have an answer Print All the info
    if(answer)
    {
    //seperating between parts
    for (size_t i = 0; i < 100; i++)
    {
        std::cout<<"-";
    }
    std::cout<<std::endl;
    //Printing Rotations
    PrintRotations();
    //Printing nodes
    size_t num{};
    while (!Explored.empty())
    {
        num++;
        Explored.pop();
    }
    std::cout<<"Number Of Explored Nodes : "<<num<<std::endl;

    for (size_t i = 0; i < 100; i++)
    {
        std::cout<<"-";
    }
    std::cout<<std::endl;
    //Print If we have an answer
    std::cout<<"The Cube is :  solved" <<std::endl;

    for (size_t i = 0; i < 100; i++)
    {
        std::cout<<"-";
    }
    std::cout<<std::endl;
    }
    else
    {
    //Print If we dont have an answer
    std::cout<<"The Cube is not solved"<<std::endl;
    for (size_t i = 0; i < 100; i++)
    {
        std::cout<<"-";
    }
    std::cout<<std::endl;
    }
}
//Heart of the Pogram :) : Recursive ALGORITHM TO GET TO THE ASNWER
bool RubikSolver::DLS(Rubik a , int limit,std::stack <Rubik> &stack)
{
    Explored.push(a);
    stack.push(a);
    bool if_solved{};
    //if we reached The Goal!
    if (a.goal_test())
    {
        std::cout<<"Your solved Cube is :" <<std::endl;
        a.showColored();
        size_t R = a.get_parent_rotation();
        actions.push_back(R);
        return 1;
    }
    ///if we reach end of Tree
    if (limit<2)
        return 0;
    limit--;
    //creates Every Child state
    for (size_t i{} ;i<12 ; i++)
    {
        //create child node
        size_t parent_rotation = i+1;   //save Parent Rotation of every node
        Rubik b = solver_rotation(a,i+1); //Rotates parent node & makes a child from 
        b.set_parent_rotation(parent_rotation);  //save parent rotation to the node
        if(algorithm) //this is because we want to get to the answers given to us , thats why in IDS we dont withdraw the seen nodes
        {
                if_solved = DLS(b,limit,stack);
        }
        else if (algorithm == false)
        {
            if(!searchExploredByState(b)) //dont go into what its seen
            {
                if_solved = DLS(b,limit,stack);
            }
        }
        if(if_solved)
        {
            //a.showColored();  //If you want to show every rotation
            size_t R = a.get_parent_rotation();
            actions.push_back(R);
            break;
        }
    }
    
    if(if_solved)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//Translates 1-12 to Rotaion between 1-6 and (Clockwise , Counterclockwise)
Rubik RubikSolver::solver_rotation(Rubik a, int num)
{
    if (num<7)
    {
        Rubik b = a.Rotaion(num,'C');
        return b;
    }
    else
    {
        int face{num%6};
        Rubik b = a.Rotaion(face,'I');
        return b;
    }
}
//Solve The Cube Using IDS Algo byd iteratively ++ limit and call DLS
bool RubikSolver::IDS(Rubik problem){
    int limit = 1;
    int max_limit = 10; //Set as TA said
    while (limit < max_limit){
        std::vector<int> actions;
        std::stack <Rubik> stack;
        if(DLS(problem, limit,stack)){
            std::cout<<"limit: "<<limit <<" -> Successful" <<std::endl;
            return true;
        }
        else{
            std::cout<<"limit: "<<limit << " -> UnSuccessful" <<std::endl;
            limit++;
        }
            
    }
    return false;
}

bool RubikSolver::searchExploredByState(Rubik &a){
    std::stack temp = Explored;
    while(!temp.empty())
    {
        if(a == temp.top())
            return true;

        temp.pop();
    }
    return false;
}
//
void RubikSolver::PrintRotations()
{
    std::cout<<"Rotations Are :"<<std::endl;
    std::string clock;
    std::string rotation;
    actions.pop_back();
    while(!actions.empty())
    {
        
        if (actions.back() <7)
        {
            clock = "Clockwise";
        }
        else
        {
            clock = "CounterClockwise";
        }
        int temp = actions.back()%6;
        switch (temp)
        {
        case 1:
            rotation = "Back";
            break;
        case 2:
            rotation = "Left";
            break;
        case 3:
            rotation = "Up";
            break;

        case 4:
            rotation = "Right";
            break;
        case 5:
            rotation = "Front";
            break;
        case 6:
            rotation = "Buttom";
            break;
        default:
            break;
        }

        std::cout<<"[("<<rotation<<"," <<temp << ")] , [(" << clock << ")]" <<std::endl ;
        actions.pop_back();
    }

    for (size_t i = 0; i < 100; i++)
    {
        std::cout<<"-";
    }
    std::cout<<std::endl;
}