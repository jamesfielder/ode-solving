#include "MFunction.hpp"
#include "MVector.hpp"
#include "odes.hpp"

MVector ivp::operator()(const double& x, const MVector& y){
	MVector temp(2);
 	temp[0] = y[1];
 	temp[1] = 4 + (1./4.)*x*x*x - (1./8.)*y[0]*y[1];
	return temp;
}

MVector bvp1::operator()(const double& x, const MVector& y){
	MVector temp(4);
	temp[0] = y[1];
	temp[1] = -k*y[1] - x*y[0];
	temp[2] = y[3];
	temp[3] = -k*y[3] - x*y[2];
	return temp;
}
void bvp1::setk(double j){
	k = j;
}

MVector bvp2::operator()(const double& x, const MVector& y){
	MVector temp(4);
	temp[0] = y[1];
	temp[1] = 4 + (1./4.)*x*x*x - (1./8.)*y[0]*y[1];
	temp[2] = y[3];
	temp[3] = (-1./8.)*(y[1]*y[2] + y[0]*y[3]);
	return temp;
}
