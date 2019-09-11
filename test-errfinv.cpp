// Simple example of using a special function from 
// the BOOST library
//
// Here we use the inverse error function to 
// evaluate the cumulative distribution function of 
// a standardized normal distribution for use in 
// generating standardized normal random variates 
// using the inverse CDF method.
// (there are better ways of achieving this end result).
// The values are written to an output file.
//
//              Graham W. Wilson,  11-Sep-2019
//
#include <iostream>
#include <fstream>
#include <random>
#include <boost/math/special_functions/erf.hpp>
typedef std::mt19937 MersenneTwisterGenerator;
using namespace boost::math;

int main()
{
   std::ofstream out;
   out.open("normal.dat");
   out.precision(16);
   unsigned long int seed = 123456;
   MersenneTwisterGenerator r(seed);
   std::uniform_real_distribution<double> u;
   double x;

   for(unsigned int i=0; i<1000000; i++){
      x=sqrt(2.0)*erf_inv(2.0*u(r) -1.0);//Inverse transformation method
      out << x << std::endl;
   }
   out.close();
}
