#include "Simple.h"
#include "iostream"
#include "MyForm.h"
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <list>
int func;
#define CLOCKS_PER_SEC ((clock_t)1000)
//int cities_distances[150][150];
//void generate(int numCity,int func);
//float cal_Dist(int city[], int numCity);
//float recordDistance;
//void swap(int city[], int pos1, int pos2);
//int flag = 0;
//float distance;
struct VertexProperty {
	float dist;
	int loc;
};
struct FinalOutput {
	float newDistance;
	std::string path;
};
std::list<int> VisitedCity;
std::list<int> UnVisitedCity;
float city_distances[150][150];
void generateCities(int numCity,int func);
FinalOutput Greedy(int numCity, int InitialSeed);
int maxBound;
int Bound = 0;
VertexProperty calculateNeighbour(int position, int numCity);
Simple::Simple()
{

	
}
// costfunction1
float Simple:: costfunction1(int city1, int city2) {
	if (city1 == city2)
		return 0;
	else if (city1 < 3 && city2 < 3)
		return 1;
	else if (city1 < 3)
		return 200;
	else if (city2 < 3)
		return 200;
	else if ((city1 % 7 == city2 % 7))
		return 2;
	else 
		return (fabs(city1 - city2) + 3);

}
float Simple::costfunction2(int city1, int city2) {
	if (city1 == city2)
		return 0;
	else if (city1 + city2 < 10)
		return (fabs(city1-city2)+4);
	else if (((city1 + city2) % 11) == 0)
		return 3;
	else 
		return (pow(fabs(city1 - city2), 2) + 10);

}
float Simple::costfunction3(int city1, int city2) {
	if (city1 == city2)
		return 0;
	else
		return (pow(city1 + city2, 2));

}
//
char* Simple:: calDistance(int numOfCities,int costFunctionValue,int InitialSeed,int MEB) {
	char *cstr;
	clock_t tStart = clock();
	func = costFunctionValue;
	int numCity = numOfCities;
	float shortestDistance;
	maxBound = MEB;
	//int *city, *citycopy;
	//city = new int[numCity];
	//citycopy = new int[numCity];
	delete[] cstr;
	generateCities(numCity,func);
	FinalOutput fo = Greedy(numCity, InitialSeed);
	
	std::string output = "";
	std::string dist = std::to_string(fo.newDistance);
	output = output + "ShortestDistace:" + dist+"\n";
	output = output + "Path:"+fo.path;
	output = output +"\n"+ "Time taken in Seconds:";
	//myfile << "endOfPath" << std::endl;
	//std::cout << "Time taken in Seconds:" << 
	float t= ((float)(clock() - tStart) / CLOCKS_PER_SEC);
	std::string time = std::to_string(t);
	output = output + time;
	cstr = new char[output.length() + 1];
	strcpy(cstr, output.c_str());
	return cstr;
}

//adjacency matrix
void generateCities(int numCity,int func)
{
	int i, j;
	Simple e;
	int costfunc = func;
	for (int k = 0; k < numCity; k++)
		UnVisitedCity.push_back(k);
	for (i = 0; i < numCity; i++) {
		for (j = 0; j < numCity; j++) {
			if(costfunc == 1)
				city_distances[i][j] = e.costfunction1(i, j);
			else if(costfunc ==2)
				city_distances[i][j] = e.costfunction2(i, j);
			else if(costfunc ==3)
				city_distances[i][j] = e.costfunction3(i, j);
		}
	}

}

//float cal_Dist(int city[], int numCity) {
//	int d = 0;
//
//	for (int i = 0; i <numCity - 1; i++) {
//
//		d = d + cities_distances[city[i]][city[i + 1]];
//	}
//	return d;
//}

//void swap(int city[], int pos1, int pos2) {
//	int temp = city[pos1];
//	city[pos1] = city[pos2];
//	city[pos2] = temp;
//
//}

//void generateCities(int numCity)
//{
//	//city_distances = new float*[numCity];
//	int i, j;
//	Simple e;
//	for (int k = 0; k < numCity; k++)
//		UnVisitedCity.push_back(k);
//	for (i = 0; i < numCity; i++) {
//		for (j = 0; j < numCity; j++) {
//			//city_distances[i] = new float[numCity];
//			city_distances[i][j] = e.costfunction1(i, j);
//			std::cout << city_distances[i][j] << " ";
//		}
//		std::cout << std::endl;
//
//	}
//
//}

VertexProperty calculateNeighbour(int position, int numCity) {
	int FirstElement = UnVisitedCity.front();
	float dist = city_distances[position][FirstElement];
	int loc = FirstElement;

	for (int city : UnVisitedCity) {
		++Bound;
		if (Bound== maxBound)
			break;
		if (city_distances[position][city] < dist && position != city) {
			dist = city_distances[position][city];
			loc = city;
			break;
		}

	}
	std::cout << std::endl;
	return { dist,loc };
}
FinalOutput Greedy(int numCity, int InitialSeed) {
	int location = InitialSeed;
	int d;
	float newDistance = 0;

	std::string path = std::to_string(InitialSeed);
	for (int i = 0; i < numCity - 1; i++) {
		VisitedCity.push_back(location);
		UnVisitedCity.remove(location);
		VertexProperty d = calculateNeighbour(location, numCity);
		location = d.loc;
		newDistance = newDistance + d.dist;
		int newPath = location;
		path = path + " ->  " + std::to_string(newPath);
	}
	return { newDistance,path };
}