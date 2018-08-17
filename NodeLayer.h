//NuralNode.h - This is medium level structure that holds all the nodes. 
//Author: Joseph Owens	Creation Date: 8/15/18
//Version: 1.0			Last Updated: 8/15/18

#ifndef NODELAYER_H
#define NDOELAYER_H

#include "NeuralNode.h"

class NLayer(){
private:
	vector<NNode*> nodes;
	NLayer* prevLayer;
	NLayer* postLayer;
	void addNode(NNode*);
	void removeNode()
public:
	NLayer();
	~NLayer();
	void setSize();
	NNode* getNode(int);
};

#endif