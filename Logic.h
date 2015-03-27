#include <vector>
#include "Behaviour.h"
#include "Vehicle.h"

class Logic {

private:
vector<Vehicle*> cars;
vector<Layout*> roads;

public:
    Logic();
    Logic(vector<Vehicle*> cars, vector<Layout*> roads );
    ~Logic();
    vector<Vehicle*> getCars();
    void setCars(vector<Vehicle*> cars);
    vector<Layout*> getRoads();
    void setRoads(vector<Vehicle*> roads);
    void scan(Layout *road);

   // int recordAverageSpeed(Vehicle vehicle);
};

