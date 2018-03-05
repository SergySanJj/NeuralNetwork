#pragma once
#include <fstream>
#include "Neuron.h"
#include <vector>
#include <unordered_map>
#include <string>


using namespace std;

#define ID_ALREADY_EXISTS 1

struct Layer
{
private:
	vector<Neuron> *neurons = nullptr;
	string id = "";
public:
	unsigned int size = 0;

	Layer(int n, string id);

	~Layer();

	string getID();
	void linkWithLayer(Layer *linkWith);
};

#define layerPair pair< string, Layer* >

class NeuralNetwork
{
public:
	NeuralNetwork();
	~NeuralNetwork();

	void addLayer(unsigned int neuronQuantity, string layerID);
	bool connectLayers(string ID1, string ID2);
private:
	unordered_map<string, Layer*> layers; // key, point to the layer of nodes
};
