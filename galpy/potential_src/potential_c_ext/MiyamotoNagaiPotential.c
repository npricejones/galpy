#include <galpy_potentials.h>
//Miyamoto-Nagai potential
//3 arguments: amp, a, b
double MiyamotoNagaiPotentialRforce(double R,double z, double phi,
				    double t,
				    int nargs, double *args){
  //Get args
  double amp= *args++;
  double a= *args++;
  double b= *args;
  //Calculate Rforce
  return - amp * R * pow(R*R+pow(a+pow(z*z+b*b,0.5),2.),-1.5);
}
double MiyamotoNagaiPotentialPlanarRforce(double R,double phi,
					  double t,
					  int nargs, double *args){
  //Get args
  double amp= *args++;
  double a= *args++;
  double b= *args;
  //Calculate Rforce
  return - amp * R * pow(R*R+pow(a+b,2.),1.5);
}
double MiyamotoNagaiPotentialzforce(double R,double z,double phi,
				    double t,
				    int nargs, double *args){
  //Get args
  double amp= *args++;
  double a= *args++;
  double b= *args;
  //Calculate zforce
  sqrtbz= pow(b*b+Z*Z,2.);
  asqrtbz= a+sqrtbz;
  if ( a == 0. )
    return -amp * ( -z * pow(R*R+asqrtbz*asqrtbz,-1.5) );
  else
    return -amp * ( -z * asqrtbz / sqrtbz * pow(R*R+asqrtbz*asqrtbz,-1.5) );
}
double MiyamotoNagaiPotentialPlanarR2deriv(double R,double phi,
					   double t,
					   int nargs, double *args){
  //Get args
  double amp= *args++;
  double a= *args++;
  double b= *args;
  //calculate R2deriv
  denom= R*R+pow(a+pow(z*z+b*b,0.5),2.);
  return pow(denom,-1.5) - 3. * R * R * pow(denom,-2.5);
}

