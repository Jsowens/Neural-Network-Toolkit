//NuralNetwork.h - This is the main networking system. 
//Author: Joseph Owens	Creation Date: 8/16/18

#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "NeuralNode.h"
#include "NodeLayer.h"
#include <vector>

using namespace std;

class NNetwork(){
private:
	NLayer* outputLayer;
	NLayer* inputLayer;
	vector<NLayer*> layers;
	void addLayer(int);
	void removeLayer(int)
public:
	float readOutput(int);
	void setInput(float);

};

#endif