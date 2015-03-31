#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <vector>
#include "Vehicle.h"
#include "Layout.h"

class Behaviour
{
public:
    Behaviour(void);

    ~Behaviour(void);

    bool scanYourSide(std::vector<Vehicle*> cars , Layout *road, Vehicle *car);
    void reduceSpeed(Vehicle *car,std::vector<Layout*> roads);
    void increaseSpeed(Vehicle *car,std::vector<Layout*> roads);
    bool isOnThisRoad(Vehicle *car, Layout *road);
    void setNewCoOrdiantes(Vehicle *car, string inc_dec,int newSpeed);

private:

};


#endif // BEHAVIOUR_H

