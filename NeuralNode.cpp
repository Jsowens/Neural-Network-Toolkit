
#include "NeuralNode.h"


NNode::NNode(bool isInput){
	active = 0.0;
	prevNodes = new vector<NNode*>();
	prevWeights = new vector<double>();
	bias = 0.0;
	inputNode = isInput;
}

void NNode::setActivation(bool isOn){
	if(isInput){
		if(isOn) active = 1.0;
		else active = 0.0;
	}	
}

float NNode::getActivation() {
	return active;
}

void NNode::addNode(NNode* node){
	if (!inputNode){
		prevNodes->add(node);
		prevWeights->add(1.0);
	}	
}

int NNode::getNodeIndex(NNode* node){
	int index = 0;
	for (int i = 0; i < prevNodes->size(); i++){
		if (prevNodes[i] = node){
			index = i;
			break;
		}
	}
	return index;
}

void NNode::removeNode(NNode* node){
	if (!inputNode){
		removeNode(getNodeIndex(node));
	}
}
	

void NNode::removeNode(int index){
	prevNodes->erase(index);
	prevWeights->erase(index);
}

void NNode::replaceNode(NNode* newNode, NNode* oldNode){
	if(!inputNode){
		int index = getNodeIndex(oldNode);
		replaceNode(newNode, index);
	}
}

void NNode::replaceNode(NNode* node, int index){
	removeNode(index);
	prevNodes->insert(index, node);
	prevWeights->insert(index, 0.0);
}

vector<double> NNode::getWeights(){
	return prevWeights;
}

double NNode::getBias(){
	return bias;
}

float NNode::sigmoid(double input){
	float output = 1 / (1 + exp(-input));
	return output;
}

float NNode::calcActivation(){
	int nodeCount = prevNodes->size();
	double total = 0;
	if (!inputNode){
		for (int i = 0; i < nodeCount; i++){
			total += prevNodes[i]->calcActivation() * prevWeights[i];
		}
		total += bias;
		return sigmoid(total);
	}
	return active;	
}

double NNode::calcCost(vector<float>* desired, int numExamples){
	int numNodes = desired->size();
	if (prevNodes->size() != numNodes) return -1.0;
	if (inputNode) return -1.0;
	if (numExamples <= 0) return -1.0;
	double total = 0;
	for (int i = 0; i < numNodes; i++){
		total += pow(prevNodes->getActivation() * prevWeights[i] - desired[i],2); 
	}
	return total / (2.0 * numExamples);
}

vector<float>* NNode::nodeInfluence(float adjustment){
	vector<float>* nodeAdjust = new vector<float>();
	int elements = prevNodes->size();
	if(inputNode || adjustment->size() != elements){
		return nodeAdjust; 
	}
	for (int i = 0; i < elements; i++){
		double expVal = exp(prevNodes[i]->getActivation() * prevWeights[i] + bias);
		double numerator = 2 * prevWeights[i] * expVal * (adjustment * expVal + adjustment - expVal);
		double denominator = pow(expVal + 1, 3);
		nodeAdjust->add(float(numerator / denominator));
	}
	return nodeAdjust;
}

vector<double>* NNode::weightInfluence(float adjustment){
	vector<double>* weightAdjust = new vector<double>();
	int elements = prevNodes->size();
	if(inputNode || adjustment->size() != elements){
		return weightAdjust; 
	}
	for (int i = 0; i < elements; i++){
		double expVal = exp(prevNodes[i]->getActivation() * prevWeights[i] + bias);
		double numerator = 2 * prevNodes[i]->getActivation() * expVal * (adjustment * expVal + adjustment - expVal);
		double denominator = pow(expVal + 1, 3);
		weightAdjust->add(numerator / denominator);
	}
	return weightAdjust;
}

double NNode::biasInfluence(float adjustment){
	double biasAdjust = 0;
	int elements = prevNodes->size();
	if(inputNode){
		return biasAdjust; 
	}
	for (int i = 0; i < elements; i++){
		double expVal = exp(prevNodes[i]->getActivation() * prevWeights[i] + bias);
		double numerator = 2 * expVal * (adjustment * expVal + adjustment - expVal);
		double denominator = pow(expVal + 1, 3);
		biasAdjust += (numerator / denominator);
	}

	biasAdjust = biasAdjust / elements;

	return biasAdjust;
}

void NNode::backProp(float adjustment){
	int elements = prevNodes->size();
	if(inputNode){
		return; 
	}

	vector<float>* nodeAdjust = nodeInfluence(adjustment);
	vector<double>* weightAdjust = weightInfluence(adjustment);
	bias += biasInfluence(adjustment);
	for (int i = 0; i < elements; i++){
		prevWeights[i] += weightAdjust[i];
	}
	return nodeAdjust;
}