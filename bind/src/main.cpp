#include <iostream>
#include <boost/bind.hpp>

using namespace std;

double func(double a, double b) 
{
	return a - b;
}

int main() 
{
	double result = (boost::bind(&func, _1, _2))(1.0, 2.0);
	cout << "a: " << result << endl;

	result = (boost::bind(&func, _2, _1))(1.0, 2.0);
	cout << "b: " << result << endl;

	result = (boost::bind(&func, _2, boost::bind(&func, _1, _2)))(1.0, 2.0);
	cout << "b: " << result << endl;

	return 0;
}
