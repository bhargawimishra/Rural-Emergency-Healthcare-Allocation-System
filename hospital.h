
#include<iosstream>
#include<string>
#include<hospital.h>
using namespace std;

class Hospital
{
private:
    string hospitalid;
    string name;
    string location;
    int availablebeds;
    int totalbeds;
    string emergency;
public:
    Hospital();
    string getid();
    string getname();
    string getlocation();
    int availablebeds;
    bool emergencyavailableornot();
    void sethospital(string id, string nam, string loc, int avail, int total, bool emer);
    void display();

};
#endif // hospital_h
