 
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

#include "vector.hpp"
#include "field.hpp"

size_t field::pos(const int& i, const int& j)const{ return i * columns + j; }

//get() functions
vec field::get(const int& i, const int& j)const{ return data.at(pos(i, j)); }

vector<vec> field::getData() const { return data; }

int field::getLines() const { return lines; }

int field::getCols() const { return columns; }

double field::getCellSize() const { return cell_size; }

double field::maximum() const {
  double max = 0;
  for(auto e : data ) if(e.len() > max) max = e.len();
  return max; 
}
   
vec field::interpolate(const vec& v) const{
  
  //returns 0 vector if v out of bounds
  if(!(v.r >= 0 && v.r <=static_cast<double>(lines)*cell_size && v.z>= 0 && v.z <= static_cast<double>(columns)*cell_size)) return vec();
  
  vec res;
  
  //getting point down-left on the grid
  int i = static_cast<int>(v.r/cell_size);
  int j = static_cast<int>(v.z/cell_size);
  if(i == lines-1) i--;
  if(j == columns-1) j--;

  //bilinear interpolation
  res += (get(i,j)*((j+1)*cell_size-v.z)+get(i,j+1)*(v.z-j*cell_size))*((i+1)*cell_size-v.r);
  res += (get(i+1,j)*((j+1)*cell_size-v.z)+get(i+1,j+1)*(v.z-j*cell_size))*(v.r-i*cell_size);
  
  return res;

}
  
//constructors
void field::set(const int& i, const int& j, const vec& v){ data.at(pos(i, j)) = v; }
void field::set(const vec& v){ for(auto& e : data) e = v; }
void field::set(const field& f){ data.clear(); data = f.getData(); cell_size = f.getCellSize(); lines = f.getLines(); 
	  columns = f.getCols(); }
void field::randomize(const double& d1, const double& d2){ for(auto& e : data) e.randomize(d1, d2); }

field::field(const int& l, const int& c, const double& cs, const vec& v){
  lines = l; columns = c; cell_size = cs;
  data = vector<vec>(lines * columns, v);
}
field::field(const string& rcomponent, const string& zcomponent, const double& c){
  *(this) = field();
  load(rcomponent, zcomponent);
  cell_size = c;
}

//loading data form give files
void field::load(const string& rcomponent, const string& zcomponent){
  
  //resetting to default values
  data.clear();
  lines = 0;

  //input filestream
  ifstream ir(rcomponent);
  ifstream iz(zcomponent);
  if(!ir.is_open()) { cerr << "error: can't open file " << rcomponent << "\n"; exit(-1); }
  if(!iz.is_open()) { cerr << "error: can't open file " << zcomponent << "\n"; exit(-1); }
  
  //temporary variables used below
  string rline, zline;
  vec tmp;

  //reading both files line by line assuming same number of lines in each file and constant number of columns per line
  while (getline(ir, rline) && getline(iz,zline))
  {
    columns = 0;
    
    //reading lines word by word
    stringstream rstream(rline);
    stringstream zstream(zline);
    while(rstream.good() && zstream.good()){ 
      columns++;
      //saving data
      rstream >> tmp.r; zstream >> tmp.z;
      data.push_back(tmp);
    }
    lines++;
  }
}


void field::operator=(const field& f){ set(f); }

