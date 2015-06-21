#include <iostream>
#include <iterator>
#include <set>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <math.h>

using namespace std;

template <typename T>
struct PrintIt {
	void operator() (const T& val) {
		cout << val << " ";
	}
};

template <typename Arg1, typename Arg2>
struct Multiply : public binary_function<Arg1, Arg2, Arg1> {
	Arg1 operator() (Arg1 base, Arg2 exponent) const {
		return base * exponent;
	}
};

template <typename Arg1, typename Arg2>
struct Power : public binary_function<Arg1, Arg2, Arg1> {
	Arg1 operator() (Arg1 base, Arg2 exponent) const {
		return pow(base, exponent);
	}
};

int main()
{
	set<long, less<long>> mySet;
	for (long j = 1; j <= 4; ++j)
		mySet.insert(j);

	for_each(mySet.begin(), mySet.end(), PrintIt<long>());
	cout << endl;

	transform(mySet.begin(), mySet.end(), 
				ostream_iterator<long>(cout, ", "), 
				negate<long>());
	cout << endl;

	transform(mySet.begin(), mySet.end(), 
				ostream_iterator<long>(cout, ", "), 
				bind1st(Power<long, long>(), 3));	// 3^1, 3^2, 3^3, 3^4
	cout << endl;

	transform(mySet.begin(), mySet.end(), 
				ostream_iterator<long>(cout, ", "), 
				bind2nd(Power<long, long>(), 3)); // 1^3, 2^3, 3^3, 4^3 
	cout << endl;

	return 0;
}
