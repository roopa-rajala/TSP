#pragma once
#include <string>
ref class Simple
{
//	int *cities = new int[];
	
public:
	  Simple();
	  float costfunction1(int city1, int city2);
	  float Simple::costfunction2(int city1, int city2);
	  float Simple::costfunction3(int city1, int city2);
	  char* calDistance(int numOfCities, int costFunctionValue,int InitialSeed,int MEB);
};

