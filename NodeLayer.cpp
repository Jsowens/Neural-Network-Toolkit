
#include "NodeLayer.h"

NLayer::NLayer(){
	nodes = new vector<NNode*>;
	parentLayer = NULL;
	childLayer = NULL;
}

NLayer::~NLayer(){
	delete[] parentLayer;
	delete[] childLayer;
	delete[] nodes;
}

void NLayer::addNode(){
	NNode* temp = new NNode();
	nodes->add(temp);
	if(parentLayer != NULL){
		parentLayer->addChildNode(temp);
	}
	if(childLayer != NULL){
		for(int i = 0; i < childLayer->length(); i++){
			temp->addNode(childLayer->getNode(i));
		}
	}
}

void NLayer::removeNode(){
	if (nodes->size <= 0) return;
	NNode* temp = nodes[nodes->size()-1];
	nodes->remove(nodes->size()-1);
	if (parentLayer == NULL) return;
	for (int i = 0; i < parentLayer->length(); i++){
		parentLayer[i]->removeNode(temp)
	}
}

void NLayer::setSize(int size){
	if (nodes->size() < size){
		for (int i = 0; i < size - nodes->size(); i++){
			addNode();
		}
	}
	else if(nodes->size() > size){
		for (int i = 0; i < nodes->size() - size; i++){
			removeNode();
		}
	}
}

