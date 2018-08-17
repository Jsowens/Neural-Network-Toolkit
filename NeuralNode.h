//NuralNode.h - This is the base unit for a nural network. 
//Author: Joseph Owens	Creation Date: 8/15/18

#ifndef NEURALNODE_H
#define NEURALNODE_H

//Include Section
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

//Class Def
class NNode(){
private:
	//Parameters
	float active;
	vector<NNode*> *prevNodes;
	vector<double> *prevWeights;
	double bias;
	bool inputNode;

	//Methods
	int getNodeIndex(NNode*);
	void removeNode(int);
	void replaceNode(NNode*,int);
	float sigmoid(double);
	vector<float>* nodeInfluence(float);
	vector<double>* weightInfluence(float);
	double biasInfluence(float);
	
public:
/*
	Pre: A boolean indicating if the node is an input or an internal node.
			true: input
			false: internal
	Post: Default Constructor
*/
	NNode(bool);
/*
	Pre: boolean value for active or inactive. Only works on an input node.
	Post: N/A
*/
	void setActivation();
/*
	Pre: N/A
	Post: Returns the activation of the current node as a value between 1 and 0.
*/
	float getActiviation();
/*
	Pre: A new NNode that will influence the activity of this node. Does not work for an input node.
	Post: N/A
*/
	void addNode(NNode*);
/*
	Pre: Remove the influence of a node. Does not work for an input node.
	Post: N/A
*/
	void removeNode(NNode*);
/*
	Pre: Remove the influece of one node and add the influence of another at
		 the same location. Order does not matter computationally. Does not work for an input node.
	Post: N/A
*/	
	void replaceNode(NNode*,NNode*);
/*
	Pre: N/A
	Post: Returns a vector of weights
*/	
	vector<double> getWeights();
/*
	Pre: N/A
	Post: returns the bias of the node
*/
	double getBias();
/*
	Pre: N/A
	Post: Calculates the activation of the node and causes any previous nodes to calculate their activation as well. If the node is an input, it returns the set activation.
*/
	float calcActivation();

	double calcCost(vector<float>*, int);

	vector<float>* backProp(float);
};

#endif