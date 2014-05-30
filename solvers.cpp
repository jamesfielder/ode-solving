#include "MFunction.hpp"
#include <fstream>
#include <iostream>
#include "MVector.hpp"
#include "solvers.hpp"

MVector ivp_solvers::euler(MVector &y, MFunction &f, int j){
	int i;
	double x, h;
	h = (b-a)/steps;
	x = a; // For printing, these are set to their initial values
	y = y; // and the loop started from 1 instead of 0 to get the file right
	if (j == 1){ // when printing
		ofstream output("output_euler.csv");
		output << x << "," << y[0] << "," << y[1] << endl;
		for(i = 1; i < steps+1; i++){
			x = a + i*h;
			y = y + h*f(x, y);
			output << x << "," << y[0] << "," << y[1] << endl;
		}
		output.close();
	}
	else { // not printing
		for(i = 1; i < steps+1; i++){
			x = a + i*h;
			y = y + h*f(x, y);
		}
	}
	// cout << y << endl; // optional print
	return y;
}
MVector ivp_solvers::midpoint(MVector &y, MFunction &f, int j){
	int i;
	double x, h;
	h = (b-a)/steps;
	x = a;
	y = y;
	if (j == 1){ //printing
		ofstream output("output_midpoint.csv");
		output << x << "," << y[0] << "," << y[1] << endl;
		for(i = 1; i < steps+1; i++){
			x = a + i*h;
			y = y + h*f(x + 0.5*h, y + 0.5*h*f(x,y));
			output << x << "," << y[0] << "," << y[1] << endl;
		}
		output.close();
	}
	else { // not printing
		for(i = 1; i < steps+1; i++){
			x = a + i*h;
			y = y + h*f(x + 0.5*h, y + 0.5*h*f(x,y));
		}
	}
	// cout << y << endl; // optional print
	return y;
}
MVector ivp_solvers::runge(MVector &y, MFunction &f, int j){
	int i;
	double x, h;
	MVector k1, k2, k3, k4;
	h = (b-a)/steps;
	x = a;
	y = y;
	k1 = h*f(x,y);
	k2 = h*f(x + 0.5*h, y + 0.5*k1);
	k3 = h*f(x + 0.5*h, y + 0.5*k2);
	k4 = h*f(x + h, y + k3);
	if (j == 1){
		ofstream output("output_runge.csv");
		output << x << "," << y[0] << "," << endl; //<< y[1] << endl;
		for(i = 1; i < steps+1; i++){
			x = a + i*h;
			k1 = h*f(x,y);
			k2 = h*f(x + 0.5*h, y + 0.5*k1);
			k3 = h*f(x + 0.5*h, y + 0.5*k2);
			k4 = h*f(x + h, y + k3);
			y = y + (1./6.)*(k1 + 2*k2 + 2*k3 + k4);
			output << x << "," << y[0] << endl;
		}
		output.close();
	}
	else {
		for(i = 1; i < steps+1; i++){
			x = a + i*h;
			k1 = h*f(x,y);
			k2 = h*f(x + 0.5*h, y + 0.5*k1);
			k3 = h*f(x + 0.5*h, y + 0.5*k2);
			k4 = h*f(x + h, y + k3);
			y = y + (1./6.)*(k1 + 2*k2 + 2*k3 + k4);
		}
	}
	// cout << y << endl; // option print statement
	return y;
}
