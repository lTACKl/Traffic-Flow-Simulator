#include <iostream>
#include <vector>
#include "behaviour.h"
#include "layout.h"
#include "vehicle.h"

#include "Logic.h"

using std::vector;

using namespace std;

int main() //Used Collin's code(line 15-31) to test Logic
{
       Vehicle *  v1 = new Vehicle(50,2.0,50,60,2,2,"North");  //Speed Aggressiveness x y w h direction
       Vehicle * v2 = new Vehicle(25,1.5,50,64,2,2,"North");
       Vehicle * v3 = new Vehicle(50,0.1,50,90,2,2,"North");  //Distance between v3 and v1 = 10 which is 5 car lengths ahead


       vector<Vehicle*> vehicles;
       vehicles.push_back(v1);  //pass the pointer
       vehicles.push_back(v2);
       vehicles.push_back(v3);



       Layout * l1 = new Layout (50,50,30,1000,100); //x y w h speedlimit
       Layout * l2 = new Layout (60,50,30,5000,120);   //
       vector<Layout *> roads;
       roads.push_back(l1);
       roads.push_back(l2);

       Logic *log = new Logic(vehicles, roads);
       log->scan();
}

