
#include "lib/routine.hpp"
#include "lib/field.hpp"
#include "lib/vector.hpp"

int main(int argc, char * argv[]){

  //giving the routine the path to the setup_file  
  routine r(argv[1]);
  r.run();

  return 0; 
  
}

