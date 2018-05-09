
#include <cmath>
#include <cstddef>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include "vector.hpp"

using namespace std;

   double rnd(const double& d1, const double& d2){
    return (max(d1, d2) - min(d1, d2))*static_cast<double>(rand())/static_cast<double>(RAND_MAX) + min(d1, d2);
   }
    
   double vec::len() const { return sqrt(r*r + z*z); }    

   void vec::set(const vec& v) { r = v.r; z = v.z; }
   void vec::randomize(const double& d1, const double& d2) { r = rnd(d1, d2); z = rnd(d1, d2); }
  
   vec::vec(const double& R, const double& Z){ r = R; z = Z; } vec::vec(const vec& v) { set(v); }

   void vec::operator=(const vec& v){ set(v); }
   vec vec::operator+(const vec& v) const { vec w(*(this)); w.r+=v.r; w.z+=v.z; return w; }
   vec vec::operator-(const vec& v) const { return *(this) + v * (-1); }
   vec vec::operator*(const double& d) const { vec w(*(this)); w.r*=d; w.z*=d; return w; }
   vec vec::operator/(const double& d)const { return *(this) * (1/d); }
   void vec::operator+=(const vec& v) { *(this) = *(this) + v; }
   void vec::operator-=(const vec& v) { *(this) += v*(-1); }
   void vec::operator*=(const double& d) { *(this) = *(this) * d; }
   void vec::operator/=(const double& d) { *(this) += (1/d); }
   bool vec::operator==(const vec& v) const { return (r==v.r && z==v.z) ? 1:0; }
   bool vec::operator!=(const vec& v) const { return !(*(this) == v); }

