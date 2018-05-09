
#pragma once

#include <cmath>

using namespace std;

//returns random double from the closed set [d1, d2]
double rnd(const double& d1, const double& d2);

//class for 2D-vectors (position, velocity, ...)
class vec{
  public:
  //r and z component of vector
  double r, z;

  double len() const;	//returns sqrt(r²+z²)

   void set(const vec& v);				//sets *(this) = v
   void randomize(const double& d1, const double& d2);	//sets r = rnd(d1, d2), z = rnd(d1, d2)
  
   vec(const double& R = 0, const double& Z = 0);	//constructor: r = R, z = Z
   vec(const vec& v);					//constructor: *(this) = v

   //syntax: v = w
   void operator=(const vec& v);			//*(this) = v
   //syntax for vector addition/subtraction: u = v + w, u = v - w
   vec operator+(const vec& v) const;			//returns sum of *(this) and v
   vec operator-(const vec& v) const;			//returns difference of *(this) and v
   //syntax for scalar multiplication/division: v = w*d, v = w/d, not: v = d*w, The scalar must follow after the vector!
   vec operator*(const double& d) const;		//returns scalar product of *(this) and d
   vec operator/(const double& d)const;			//returns scalar product of *(this) and 1/d
   //syntax: v += w, v -= w, v *= d, v /= d
   void operator+=(const vec& v);			//*(this) = *(this) + v  
   void operator-=(const vec& v);			//*(this) = *(this) - v
   void operator*=(const double& d);			//*(this) = *(this) * d
   void operator/=(const double& d);			//*(this) = *(this) / d
   
   //syntax: v == w, v != w
   bool operator==(const vec& v) const;	//returns 1, if r = v.r() && z = v.z, else 0
   bool operator!=(const vec& v) const;	//returns !(*(this) == v)
   
};

