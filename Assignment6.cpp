#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;

double charLat = 35.2060;
double charLong = -80.8290;
double const radEarth = 3959;
double const pi = 3.14159265358979323846;

class Distance{
    private:
    double latitude;
    double longitude;
    public:
    Distance();
    Distance(string ci, string st, string lat, string lon);
    string city;
    string state;
    double d;
    void Calculate(); 
};

Distance :: Distance(){
    latitude = 0.0;
    longitude = 0.0;
    city = "Unknown";
    state = "Unknown";
}

Distance :: Distance(string ci, string st, string lat, string lon){
    city = ci;
    state = st;
    latitude = atof(lat.c_str());
    longitude = atof(lon.c_str());
}

void Distance :: Calculate(){
    double delta_phi = latitude - charLat;
    double delta_lambda = longitude - charLong;
    delta_phi = delta_phi * (pi/180);
    delta_lambda = delta_lambda * (pi/180);
    charLat = charLat * (pi/180);
    latitude = latitude * (pi/180);
    double a = pow((sin(delta_phi/2)),2) + cos(latitude)*cos(charLat)*pow((sin(delta_lambda/2)),2);
    double c = (2)*atan2(sqrt(a),sqrt(1-a));
    d = radEarth * c;
}

int main(){
    map<pair<string,string>, double> sortedInfo;

    ifstream theFile("cities.txt");

    ofstream test("dist_clt.txt");

    string line;
    string s;
    string lc;
    string lon;
    string lat;

    while(theFile){
        getline(theFile,lc,',');
        getline(theFile,s,',');
        getline(theFile,lat,',');
        getline(theFile,lon);
        Distance test1(lc,s,lat,lon);
        test1.Calculate();
        sortedInfo.insert(make_pair(make_pair(lc,s),test1.d));
        test << lc << "," << s << "," << test1.d << endl;
    }



return 0;
}