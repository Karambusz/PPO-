#ifndef robots_h
#define robots_h
#define max_robots 5


#include <cstdlib>
#include<iostream>
#include<string>

struct Position{
    int x;
    int y;
};

typedef struct {
   const char *name;
   Position pos;


}Robot;

typedef void (*Operation)(Robot *, int );

Robot **tab = new Robot *[max_robots];
int number_robots = 0;


Robot *InitializeRobot(const char *name, Position pos){
    Robot *robot = new Robot;
    robot->name = name;
    robot->pos = pos;
    for(int i=0; i<number_robots; i++){
        if( robot->pos.x == tab[i]->pos.x && robot->pos.y == tab[i]->pos.y){
            std::cout << "InitializeRobot: Two robots cannot be placed in the same position."<<std::endl;
            delete robot;
            return nullptr;
        }
    }
    if(number_robots >= 5){
         std::cout << "InitializeRobot: No space for an additional robot."<<std::endl;
        delete robot;
        return nullptr;
    }

    tab[number_robots]=robot;
    number_robots++;
    return robot;
}

Robot *InitializeRobot(Position pos){
    return InitializeRobot("noname",pos);
}

void EchoRobot(Robot *robot){
if(robot!=nullptr){
        std::cout << "> Hello, I'm robot "<<robot->name<<" at x="<<robot->pos.x<<", y="<<robot->pos.y<<"."<<std::endl;
    }else{
        std::cout << "EchoRobot: No such robot."<<std::endl;
    }


}


void MoveX(Robot* robot,int dx){
    int licznik = 0;
    for(int i = 0; i < number_robots; i++){
        if(robot->pos.x + dx == tab[i]->pos.x && robot->pos.y == tab[i]->pos.y){
            licznik++;
            std::cout<<"MoveX: Cannot place robots in the same position."<<std::endl;
        }
    }
    if(licznik == 0)
    robot->pos.x += dx;
    
}


void MoveY(Robot* robot,int dy){
    int licznik = 0;
    for(int i = 0; i < number_robots; i++){
        if(robot->pos.x == tab[i]->pos.x && robot->pos.y + dy == tab[i]->pos.y){
            licznik++;
            std::cout<<"MoveY: Cannot place robots in the same position."<<std::endl;
        }
    }
    if(licznik == 0)
    robot->pos.y += dy;
}

void DeleteRobots(){
for(int i =0; i< number_robots; i++){
        delete tab[i];
    }
    delete [] tab;
}

#endif
