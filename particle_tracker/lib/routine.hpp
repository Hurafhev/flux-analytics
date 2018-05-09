
#pragma once

#include <string>
#include <vector>

#include "field.hpp"
#include "vector.hpp"

using namespace std;

//class for initializing a tracking routine
class routine{
  private:
    //field containing data (velocities, energy flux, heat flux, ...)
    field fld;
    //array containing the tracking particles positions
    vector<vec> markers;
    //time in secs to be simulated, conversion factor from given data to cm/s
    double time, conversion;
    //name of the folder designated for data output
    string folder;
    //if(adapt_dt != 0), the timestep will be chosen localy to ensure an accuracy of about 5 datapoints per cell;
    //if(progress != 0), the simulation progress in % will be printed to the console
    int adapt_dt, progress;
    //saves the position of marker with index i and the time t to 'folder/i.dat'
    void save(const int& i, const double& t) const;
    
  public:
    //requires a setup_file (exmaple given as setup.xmpl) and sets up the routine
    void setup(const string& setup_file);
    //runs the simulation and outputs to the given folder
    void run();

    //initializes a new routine and directly runs setup(setup_file)
    routine(const string& setup_file);

};

