//NodeLayer.h - This is medium level structure that holds all the nodes. 
//Author: Joseph Owens	Creation Date: 8/15/18
#ifndef NODELAYER_H
#define NDOELAYER_H

#include "NeuralNode.h"
#include <vector>

using namespace std;

class NLayer(){
private:
	vector<NNode*>* nodes;
	NLayer* parentLayer;
	NLayer* childLayer;
	void addNode();
	void removeNode()
public:
	NLayer();
	~NLayer();
	void setSize(int);
	NNode* getNode(int);
	void setParent(NLayer*);
	NLayer* getParent();
	void setChild(NLayer*);
	NLayer* getChild();
	void backProp(vector<float>*);
	int length();
	void addChildNode(NNode*);
	void removeChildNode(NNode*);
};

#endif