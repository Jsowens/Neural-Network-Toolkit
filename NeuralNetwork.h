//NuralNetwork.h - This is the main networking system. 
//Author: Joseph Owens	Creation Date: 8/16/18
//Version: 1.0			Last Updated: 8/16/18

#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "NeuralNode.h"
#include "NodeLayer.h"

class NNetwork(){
private:
	NLayer* outLayer;
	vector<NLayer*> layers;
	void addLayer();
	void removeLayer(int)
public:

};

#endif