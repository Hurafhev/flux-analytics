
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstddef>

#include "field.hpp"
#include "vector.cpp"
#include "routine.hpp"

using namespace std;

void routine::save(const int& i, const double& t) const{
      
      ofstream o(folder + "/tr" + to_string(i) + ".dat", ios_base::app);
      
      //saves time [t], r-comonent of position, z-component of position, r-component of interpolation, z-component of interpolation
      if(o.is_open()){ 
	o << t << ' ' << markers.at(i).r << ' ' << markers.at(i).z << ' ' 
	  << fld.interpolate(markers[i]).r << ' ' << fld.interpolate(markers[i]).z << '\n';
	o.close();
      }
      
      else{cerr << "\nerror! couldn't open file " << folder << "/tr" << i << '\n'; exit(-1);}
}

void routine::setup(const string& setup_file){
  
  //resets to default values
  fld.clear(); markers.clear(); time = 0; folder = ""; adapt_dt = 1; progress = 0; conversion = 100; 
  
  //declares local variables used below
  string line, word, r_comp = "", z_comp = "";  double r_min = 0, r_max = 0, z_min = 0, z_max = 0, cell_size = 0; int markerc = 0;
  ifstream in(setup_file);
  
  //securing file is open
  if(!in.is_open()){ cerr << "\ncan't open file " << setup_file << endl; exit(-1); }
  
  //reading setup_file line by line
  while(getline(in, line)){
    
    //skips comments
    if(line[0]=='#') continue;
    
    //gets first word in line
    stringstream istr(line); istr >> word;
      
//Sorry for huge if-clause. Tried switch first, but somehow didn't work, so I gave in after half an hour.

    //reads folder name
      if(word=="folder:"){ istr >> folder; continue; }
      
    //initializing count of markers to use 
      if(word=="markerc:"){ istr >> markerc; continue; } 
      
    //initializing a bunge of values
      if(word=="r_min:"){ istr >> r_min; continue; }
      if(word=="r_max:"){ istr >> r_max; continue; }
      if(word=="z_min:"){ istr >> z_min; continue; }
      if(word=="z_max:"){ istr >> z_max; continue; }
      if(word=="time:"){ istr >> time; continue; }
      if(word=="cell_size:"){ istr >> cell_size; continue; }
      if(word=="conversion:"){ istr >> conversion; continue; }

    //paths to the files containing data for r_ and z_component
      if(word=="r_comp:"){ istr >> r_comp; continue; }
      if(word=="z_comp:"){ istr >> z_comp; continue; }
      
    //options for adapt_dt and progress
      if(word=="set_adapt_dt:"){ adapt_dt = 1; continue; }
      if(word=="unset_adapt_dt"){ adapt_dt = 0; continue; }
      if(word=="set_progress"){ progress = 1; continue; }
      if(word=="unset_progress"){ progress = 0; continue; }
  }
  
  //some security checks
  if(r_min < 0 || r_max < 0 || z_min < 0 || z_max < 0){ cerr << "\nerror! boundary coordinates negative\n"; exit(-1); }
  if(folder == ""){ cerr << "\nerror! no name for folder.\n"; exit(-1); }
  if(r_comp == ""){ cerr << "\nerror! no name for r_comp.\n"; exit(-1); }
  if(z_comp == ""){ cerr << "\nerror! no name for z_comp.\n"; exit(-1); }
  if(cell_size <= 0){ cerr << "\nerror! cell_size invalid.\n"; exit(-1); }
  if(markerc <= 0){ cerr << "\nerror! markerc invalid.\n"; exit(-1); }
  if(time <= 0){ cerr << "\nerror! time invalid.\n"; exit(-1); }
  
  //closing setup_file
  in.close();

  //initializing all markers as (0, 0)
  markers = vector<vec>(markerc, vec());
  //initializing field using given data
  fld = field(r_comp, z_comp, cell_size);
  //randomizing markers in given boundaries
  for( auto& e : markers ){ e.r = rnd(r_min*cell_size, r_max*cell_size); e.z = rnd(z_min*cell_size, z_max*cell_size); }
}

void routine::run(){
  
  //creates folder for data
  string s="mkdir "; s+=folder; system(s.c_str());
  
  //adjust dt for having a accuracy of minimum 5 steps per cell; wouldn't recommend this, it's veeeeeeeeeeeery slow
  double dt = fld.getCellSize()/fld.maximum()*conversion/5; 
  
  //declaring some variables used below
  vec v; double t = 0; 
  
  //iterating over all markers    
  for(size_t i = 0; i < markers.size(); i++){ 
    //saving time, position and interpolated field values for t = 0    
    save(i, t);
    
    //simulating until time limit is reached
    while(t <= time){
      //updating interpolated vector
      v = fld.interpolate(markers[i])*conversion;
      //if v == 0, marker won't move any more and next one will be simulated
      if(v == vec()) break;
      //if option adapt_dt is true, dt is chosen localy giving a big performance boost
      if(adapt_dt) dt = fld.getCellSize()/v.len()/5;
      //t is incremented
      t += dt;
      //moving currently simulated marker
      markers[i] += v*dt;
      //saving data
      save(i, t);
    }
    
    //if option progress is true, printing progress in percent to the console
    if(progress){
      system("clear");
      //no error here, but direct output [no buffer fore cerr]
      cerr << static_cast<int>(static_cast<double>(i+1)/static_cast<double>(markers.size())*100) << " %";
    }
    
    //resetting t for next marker
    t = 0;
  }
}

routine::routine(const string& setup_file){ setup(setup_file); }

