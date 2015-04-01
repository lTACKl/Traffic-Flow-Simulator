#include <vector>
#include "Behaviour.h"
#include "Vehicle.h"
using namespace std;

class Logic {

private:
vector<Vehicle*> cars;
vector<Layout*> roads;
bool stop;

public:
    Logic();
    Logic(vector<Vehicle*> cars, vector<Layout*> roads );
    ~Logic();
    vector<Vehicle*> getCars();
    void setCars(vector<Vehicle*> cars);
    vector<Layout*> getRoads();
    void setRoads(vector<Layout*> roads);
    void scan();
	bool simulationOver();

   // int recordAverageSpeed(Vehicle vehicle);
};




