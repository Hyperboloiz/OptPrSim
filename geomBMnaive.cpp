#include<iostream>
#include<gsl/gsl_rng.h>
#include<gsl/gsl_randist.h>
#include<time.h>


//#include<random>
#include<fstream>
#include <time.h>

using namespace std;

//default_random_engine p{ static_cast<long unsigned int>(time(0)) };

/*
double normal(double sg) {
	normal_distribution <double> d(0, sg);
	double number = 0;
	number = d(p);
	return number; 
}
*/

double normal(gsl_rng* r, double sgm ){
	double jump = 0;
	jump = gsl_ran_gaussian_ziggurat(r,  sgm);
	return jump;
}

int main() {
	gsl_rng* r;
	r = gsl_rng_alloc(gsl_rng_mt19937);
	long unsigned myseed = static_cast<long unsigned int>(time(0));
	gsl_rng_set(r, myseed);


	double s0 = 10, mu = 0.1, sigma = 2, T = 2; 
	double dt1 = 0.5, dt2 = 0.01, dt3 = 0.001; 
	double t = 0, del = 0; 
	double TSeries1[5];
	double path1[5];
	ofstream TS1;
	ofstream Pth1;
	TS1.open("TS1.txt"); Pth1.open("Path1.txt");
	double TSeries2[201];
	double path2[201];
	ofstream TS2; ofstream Pth2; TS2.open("TS2.txt"); Pth2.open("Path2.txt");
	int i = 0; 
	TSeries1[0] = 0;  path1[0] = s0;
	double TSeries3[201]; double path3[201];
	ofstream TS3; ofstream Pth3; TS3.open("TS3.txt"); Pth3.open("Path3.txt");
	double TSeries4[2001];
	double path4[2001];
	ofstream TS4; ofstream Pth4; TS4.open("TS4.txt"); Pth4.open("Path4.txt");
	cout << "generating path1...\n";
	for (i = 1; i <= 4; i++) {
		TSeries1[i] = dt1 * i;
		del = path1[i - 1] * mu * dt1 + sigma * path1[i - 1] * normal(r, dt1);
		path1[i] = path1[i - 1] + del;
	}
	TSeries2[0] = 0;  path2[0] = s0;
	cout << "generating path2...\n";
	for (i = 1; i <= 200; i++) {
		TSeries2[i] = dt2 * i;
		del = path2[i - 1] * mu * dt2 + sigma * path2[i - 1] * normal(r, dt2);
		path2[i] = path2[i - 1] + del;
	}
	cout << "generating path3...\n";
	TSeries3[0] = 0;  path3[0] = s0;
	for (i = 1; i <= 200; i++) {
		TSeries3[i] = dt2 * i;
		del = path3[i - 1] * mu * dt2 + sigma * path3[i - 1] * normal(r, dt2);
		path3[i] = path3[i - 1] + del;
	}
	TSeries4[0] = 0;  path4[0] = s0;
	cout << "generating path4...\n";
	for (i = 1; i <= 2000; i++) {
		TSeries4[i] = dt3 * i;
		del = path4[i - 1] * mu * dt3 + sigma * path4[i - 1] * normal(r, dt3);
		path4[i] = path4[i - 1] + del;
	}
	cout.flush();
	for (i = 0; i <= 4; i++) {
		// cout << "t: " << TSeries1[i] << " S: " << path1[i] << endl;
		TS1 << TSeries1[i] << " ";
		Pth1 << path1[i] << " ";
	}

	for (i = 0; i <= 200; i++) {
		// cout << " t: " << TSeries2[i] << " S: " << path2[i];
		TS2 << TSeries2[i] << " ";
		Pth2 << path2[i] << " ";
	}
	
	for (i = 0; i <= 200; i++) {
		//cout << " t: " << TSeries3[i] << " S: " << path3[i];
		TS3 << TSeries3[i] << " ";
		Pth3 << path3[i] << " ";
	}
	for (i = 0; i <= 2000; i++) {
		//cout << " t: " << TSeries3[i] << " S: " << path3[i];
		TS3 << TSeries4[i] << " ";
		Pth3 << path4[i] << " ";
	}

	TS1.close(); Pth1.close(); TS2.close(); Pth2.close(); TS3.close(); Pth3.close(); TS4.close(); Pth4.close();
	gsl_rng_free(r);
	cout << "done!";
	return 0; 
}