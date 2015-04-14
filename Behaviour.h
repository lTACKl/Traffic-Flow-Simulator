#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <vector>
#include "Vehicle.h"
#include "Layout.h"
#include <string>

using namespace std;

class Behaviour
{
public:
    Behaviour(void);

    ~Behaviour(void);

    bool scanYourSide(std::vector<Vehicle*> cars , Layout *road, Vehicle *car);
	bool scanOtherSide(std::vector<Vehicle*> cars , Layout *road , Vehicle * car);
    void reduceSpeed(Vehicle *car,std::vector<Layout*> roads);
    void increaseSpeed(Vehicle *car,std::vector<Layout*> roads);
    bool isOnThisRoad(Vehicle *car, Layout *road);
    void setNewCoOrdiantes(Vehicle *car, string inc_dec,int newSpeed);
	void overTake(std::vector<Vehicle*> cars, Vehicle *car, Layout *road);
	bool oppositeDirection(Vehicle *myCar,Vehicle *car,Layout *road);
	bool areCarsOnOppositeSide(vector<Vehicle*> cars, Vehicle *car);
	bool foundCarInFront(std::vector<Vehicle*> cars , Layout *road , Vehicle * car);
private:
	int leftHandSideOfRoad;
	int rightHandSideOfRoad;
	int middleForOvertaking;

};


#endif // BEHAVIOUR_H