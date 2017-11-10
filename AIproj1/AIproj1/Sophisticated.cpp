#include "Sophisticated.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <map>
#include <functional>
#include <vector>
#include "Simple.h"
bool containsCity(int pos, int loc,int numCity);
#define CLOCKS_PER_SEC ((clock_t)1000)
int cities_distances[200][200];
void generate(int numCity,int costfunc);
float cal_Dist(int city1[], int numCity);
void newGeneration(int *citycopy[], float fitness[],int numCity);
void mutate(int citycopy[], float mutationRate,int numCity);
float recordDistance = INFINITY;
void swap(int citycopy[], int pos1, int pos2);
float distance;
int HighestFit, leastFitIndex, HighestFitIndex;
int populationSize = 100;
int  *order, *population, *bestEver;
int **citycopy, **city, **newPopulation;
float *fitness,*dist;
float *minFitValue, *maxFitValue;
int funct;
int finaldist;
int maxBound1;
//std::vector<int> city;
std::map<float, int*> m;
void CalcualteFitnessProbabilities(int numCity);
int* crossOver(int citycopy[], int citycopy1[], int loc,int numCity);
int* shuffle(int order[], int numCity);
Sophisticated::Sophisticated()
{
}
char* Sophisticated::GeneticAlgorithm(int numOfCities, int costFunctionValue, int MEB) {
	char *cstr;
	clock_t tStart = clock();
	funct = costFunctionValue;
	int location;
	int numCity = numOfCities;
	maxBound1 = MEB;
	city = new int*[populationSize];
	order = new int[numCity];
	citycopy = new int*[populationSize];
	newPopulation = new int*[populationSize];
	fitness = new float[populationSize];
	bestEver = new int[numCity];
	dist = new float[populationSize];
	generate(numCity,funct);
	for (int i = 0; i < numCity; i++) {
		order[i] = i;
	}
	//Initial Population
	for (int i = 0; i < populationSize; i++) {
		citycopy[i] = new int[numCity];
		citycopy[i] = shuffle(order, numCity);

	}
	CalcualteFitnessProbabilities(numCity);

	//10 Generations
	for (int r = 0; r < 1; r++) {
		newGeneration(citycopy, fitness,numCity);
		CalcualteFitnessProbabilities(numCity);
	}
	finaldist = dist[HighestFitIndex];
	std::string path="";
	for (int i = 0; i < numCity; i++) {
		path=path+std::to_string(citycopy[HighestFitIndex][i])+"->";
	}
	std::string output = "";
	std::string dist = std::to_string(finaldist);
	output = output + "ShortestDistace:" + dist + "\n";
	output = output + "Path:" + path;
	output = output + "\n" + "Time taken in Seconds:";
	//myfile << "endOfPath" << std::endl;
	//std::cout << "Time taken in Seconds:" << 
	float t = ((float)(clock() - tStart) / CLOCKS_PER_SEC);
	std::string time = std::to_string(t);
	output = output + time;
	cstr = new char[output.length() + 1];
	strcpy(cstr, output.c_str());
	return cstr;


}
//finding distance matrix
void generate(int numCity,int costfunc)
{
	int i, j;
	Simple e;
	for (i = 0; i < numCity; i++) {
		for (j = 0; j < numCity; j++) {
			if (costfunc == 1)
			cities_distances[i][j] = e.costfunction1(i, j);
			else if (costfunc == 2)
				cities_distances[i][j] = e.costfunction2(i, j);
			else if (costfunc == 3)
				cities_distances[i][j] = e.costfunction3(i, j);
		}

	}

}
//shuffle for intital population of 200
int* shuffle(int order[], int numCity) {
	std::random_shuffle(&order[0], &order[numCity]);
	population = new int[numCity];
	for (int i = 0; i < numCity; i++) {
		population[i] = order[i];
		//std::cout << population[i]<<" ";
	}
	//std::cout << std::endl;

	return population;
}

float cal_Dist(int city1[], int numCity) {
	float d = 0;

	for (int i = 0; i <numCity-1; i++) {

		d = d + cities_distances[city1[i]][city1[i + 1]];
	}
	return d;
}
void CalcualteFitnessProbabilities(int numCity) {
	float sum = 0;
	//find distance for 1 Tour
	for (int i = 0; i < populationSize; i++) {
		distance = cal_Dist(citycopy[i], numCity);
		dist[i] = distance;
		/*if (distance < recordDistance && distance!=0) {
			recordDistance = distance;
			HighestFit = i;
		}*/
		fitness[i] = 1 / (distance);
	}

	for (int i = 0; i < populationSize; i++) {
		sum = sum + fitness[i];
	}
	//Normalize fitness
	for (int j = 0; j < populationSize; j++) {
		fitness[j] = fitness[j] / sum;
	}
	//find least fitness value of the total generation
	minFitValue = std::min_element(fitness, fitness + populationSize);
	maxFitValue = std::max_element(fitness, fitness + populationSize);
	for (int j = 0; j < populationSize; j++) {
		if (&fitness[j] == minFitValue) {
			leastFitIndex = j;
		}
		if (&fitness[j] == maxFitValue) {
			HighestFitIndex = j;
		}

	}
}





void newGeneration(int *citycopy[], float fitness[],int numCity) {
	for (int i = 0; i < populationSize; i++) {
		city[i] = new int[numCity];
		int RandomParent = rand() % populationSize;
		city[i]=crossOver(citycopy[HighestFitIndex], citycopy[RandomParent],i,numCity);
		//city[i] = crossOver(citycopy[HighestFitIndex], citycopy[leastFitIndex], i,numCity);
		

	}
	for (int i = 0; i < populationSize; i++) {
		citycopy[i] = city[i];
		mutate(citycopy[i], 0.05,numCity);
		/*for (int j = 0; j < numCity; j++)
		std::cout << citycopy[i][j] << " ";

		std::cout << std::endl;*/
	}
	//std::cout << "New Generation"<<std::endl;

}
int* crossOver(int citycopy[], int citycopy1[], int loc, int numCity) {
	int indexA = floor(rand() % numCity);
	int indexB = floor(rand() % numCity);
	//city[0] = new int[numCity];		
	for (int i = 0; i < numCity; i++) {
		city[loc][i] = NULL;
	}
	for (int i = 0; i < numCity; i++) {

		if (indexA<indexB && i>indexA && i < indexB) {

			city[loc][i] = citycopy[i];
		}
		else if (indexA > indexB) {
			if (!(i < indexA && i > indexB)) {
				city[loc][i] = citycopy[i];
			}
		}
	}

	for (int i = 0; i < numCity; i++) {
		// If child doesn't have the city add it
		if (!containsCity(citycopy1[i], loc, numCity)) {
			// Loop to find a spare position in the child's tour
			for (int ii = 0; ii < numCity; ii++) {
				// Spare position found, add city
				if (city[loc][ii] == NULL) {
					city[loc][ii] = citycopy1[i];
					break;
				}
			}
		}
	}

	return city[loc];
}
//To check if the parent2 has the same city in created child 
bool containsCity(int pos, int loc, int numCity) {
	int flag = 1;
	for (int i = 0; i < numCity; i++) {
		if (city[loc][i] == pos) {
			flag = 0;
			break;
		}
	}
	if (flag == 0) {
		return true;
	}
	else
		return false;

}

void mutate(int citycopy[], float mutationRate,int numCity) {
	//for (int k = 0; k < numCity; k++) {
		if (rand() / (RAND_MAX)<mutationRate) {
			int posA = floor(rand() % numCity);
			int posB = floor(rand() % numCity);
			swap(citycopy, posA, posB);
		}

	//}


}
void swap(int citycopy[], int pos1, int pos2) {
	int temp = citycopy[pos1];
	citycopy[pos1] = citycopy[pos2];
	citycopy[pos2] = temp;

}

