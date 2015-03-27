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

private:

};


#endif // BEHAVIOUR_H
