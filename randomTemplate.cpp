#include<cstdlib>
#include<random>
#include <fstream>
#include<iostream>


using namespace std;

int main() {
	default_random_engine p;
	normal_distribution <double> d(0, 1);
	double number = 0;

	ofstream myfile;
	myfile.open("values.txt");

	for (int i = 0; i < 1000000; i++) {
		number = d(p);
		printf("%f ,", number);
		myfile << number << " ";
	}
	myfile.close();

	
	
	
	return 0;

}
