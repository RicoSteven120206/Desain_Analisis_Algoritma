#include <iostream>
using namespace std;

class test {
	public:
		test () {cout<< "\n Constructor Executed";}
		
		~test () {cout<< "\n Destructor Executed";}
};

main () {
	test t;
	return 0;
}
