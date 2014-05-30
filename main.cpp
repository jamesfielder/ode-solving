#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "MFunction.hpp"
#include "MVector.hpp"
#include "solvers.hpp"
#include "odes.hpp"

MVector shooting(double g, MVector &y, MVector d){
	double phi, phidash, lower, upper;
	MVector out(2);
	lower = d[0]; upper = d[1];
	phi = y[0] - upper; // check the boundary conditions
	phidash = y[2];
	g = g - phi/phidash;
	out[0] = g; out[1] = phi;
	return out;
}

int main(int argc, char* argv[]){
	int j = 0; 
	int steps, n;
	double tol, guess;
	string method, flag1, flag4;
	method = argv[2]; // allow us to check this is given correctly later
	tol = 0.00000000001; // set the tolerance
	if (argc < 4){
		std::cout << "Usage: ode [-b1/-b2/-i] [method] [steps] -f" << std::endl;
		return 0; // the minimum number of arguements is 3
	}
	if (argc == 5){
		flag4 = argv[4];
		if (flag4.compare("-f") == 0){
			j = 1;
		}
		else{
			std::cout << "Assuming not writing into file" << std::endl;
			j = 0;
		}
	}
	if (method.compare("euler") != 0 && method.compare("midpoint") != 0 && method.compare("runge-kutta") != 0) {
		std::cout << "Please choose either the euler, midpoint or runge-kutta method" << endl;
		return 0;
	}
	if (argc > 3){ // so long as we have more than 2 arguments we are good to go
		std::string flag1 = argv[1];
		steps = std::stoi(argv[3]); // c++11 way to change a string to an int
		if (flag1.compare("-b1") == 0){
			MVector d(2); // set the boundary conditions
			MVector y(4); // to contain the problem
			MVector temp(2); // keep the output from shooting
			d[0] = 0; d[1] = 1;
			guess = 5.;
			bvp1 f;
			ivp_solvers solv (steps, 0, 1);
				for (n = 0; n < 500; n++){
					y[0] = 0.; y[1] = guess; y[2] = 0.; y[3] = 1.;
					solv.euler(y, f, j);
					temp = shooting(guess, y, d);
					guess = temp[0];
					if (abs(temp[1])<tol){ // finish the loop when sufficently close
						break;
					}
				}
			if (method.compare("midpoint") == 0){
				for (n = 0; n < 500; n++){
					y[0] = 0.; y[1] = guess; y[2] = 0.; y[3] = 1.;
					solv.midpoint(y, f, j);
					temp = shooting(guess, y, d);
					guess = temp[0];
					if (abs(temp[1])<tol){
						break;
					}
				}
			}
			if (method.compare("runge-kutta") == 0){
				for (n = 0; n < 500; n++){
					y[0] = 0.; y[1] = guess; y[2] = 0.; y[3] = 1.;
					solv.runge(y, f, j);
					temp = shooting(guess, y, d);
					guess = temp[0];
					if (abs(temp[1])<tol){
						break;
					}
				}
			}
			if(abs(temp[1])>1.){ // deal with being unable to find the root
				std::cout << "A root was not found during the shooting method. Something is probably wrong." << std::endl;
			}
			std::cout << "y(x): " << y[0] << std::endl; // output the important values
			std::cout << "y'(x): " << y[1] << std::endl;
			}
		if (flag1.compare("-b2") == 0){
			MVector d(2); // set the boundary conditions
			MVector y(4); // to contain the problem
			MVector temp(2); // keep the output from shooting
			d[0] = 17.; d[1] = (43./3.);
			guess = 2.;
			bvp2 f;
			ivp_solvers solv (steps, 1., 3.);
			if (method.compare("euler") == 0){
				for (n = 0; n < 500; n++){
					y[0] = 17.; y[1] = guess; y[2] = 0.; y[3] = 1.;
					solv.euler(y, f, j);
					temp = shooting(guess, y, d);
					guess = temp[0];
					if (abs(temp[1])<tol){ // finish the loop when sufficently close
						break;
					}
				}
			}
			if (method.compare("midpoint") == 0){
				for (n = 0; n < 500; n++){
					y[0] = 17.; y[1] = guess; y[2] = 0.; y[3] = 1.;
					solv.midpoint(y, f, j);
					temp = shooting(guess, y, d);
					guess = temp[0];
					if (abs(temp[1])<tol){
						break;
					}
				}
			}
			if (method.compare("runge-kutta") == 0){
				for (n = 0; n < 500; n++){
					y[0] = 17.; y[1] = guess; y[2] = 0.; y[3] = 1.;
					solv.runge(y, f, j);
					temp = shooting(guess, y, d);
					guess = temp[0];
					if (abs(temp[1])<tol){
						break;
					}
				}
			}
			if(abs(temp[1])>1.){ // deal with being unable to find the root
				std::cout << "A root was not found during the shooting method. Something is probably wrong." << std::endl;
			}
			std::cout << "y(x): " << y[0] << std::endl; // output the important values
			std::cout << "y'(x): " << y[1] << std::endl;
			return 0;
			}
		if (flag1.compare("-i") == 0){
			MVector d(2); 
			d[0] = 17; d[1] = 1;
			MVector y(2);
			y = d;
			ivp f;
			ivp_solvers solv (steps, 1., 3.);
			if (method.compare("euler") == 0){
				solv.euler(y, f, j);
			}
			if (method.compare("midpoint") == 0){
				solv.midpoint(y, f, j);
			}
			if (method.compare("runge-kutta") == 0){
				solv.runge(y, f, j);
			}
			std::cout << "y(x): " << y[0] << std::endl; 
			std::cout << "y'(x): " << y[1] << std::endl;
			return 0;
		}
	}
	else{
		return 1; // return 1 after unexpected input, as per unix rules
	} // at least, I think it's a unix thing.
	return 1;
}
