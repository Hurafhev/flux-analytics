#pragma once

#include <vector>
#include <string>
#include <cstddef>

#include "vector.hpp"

enum MODE { VEL, P_FLUX, E_FLUX };

using namespace std;

//class for a field of 2D-vectors
class field{
  private:
    vector<vec> data;				    //array containing the data
    int lines, columns;				    //lines (r-direction) and columns (z-direction) of the field
    double cell_size;				    //distance between to points in the (imaginary) grid
    size_t pos(const int& i, const int& j)const;    //returns the index in data referring to the two coordinates

  public:
    vector<vec> getData() const;		    //returns data
    int getLines() const;			    //returns lines
    int getCols() const;			    //returns columns
    double getCellSize() const;			    //returns cell_size
    vec get(const int& i, const int& j) const;	    //returns data.at(pos(i, j))
    double maximum() const;			    //returns the maximum len() of the vecs in data

    vec interpolate(const vec& v) const;	//interpolates data for the position described by the vector v

    void set(const int& i, const int& j, const vec& v);		//sets data.at(pos(i, j)) = v
    void set(const vec& v);					//sets all vecs in data equal to v
    void set(const field& f);					//sets *(this) = f
    void randomize(const double& d1, const double& d2);		//randomizes all vecs in data
     
    field(const int& l = 0, const int& c = 0, const double& cs = 1, const vec& v = vec());  //constructor for l*c field with cell_size = cs and all vecs in data equal to v
    field(const string& rcomponent, const string& zcomponent, const double& cs = 1); //load(rcomponent, zcomponent), cell_size = cs   

    void load(const string& rcomponent, const string& zcomponent);  //loads data from input files and adjusts linnes and columns according to the given matrices

    //syntax f = g
    void operator=(const field& f); //sets *(this) = f
    
    void clear(){ data.clear(); lines = 0; columns = 0; cell_size = 1; }

};  

