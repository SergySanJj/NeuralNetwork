#pragma once
#include <fstream>
#include "Neuron.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iterator>

using namespace std;

#define ID_ALREADY_EXISTS 1

struct Layer
{
private:
	vector<Neuron> *neurons = nullptr;
	string id = "";
	float(*activationFunction)(float);
	unsigned int size = 0;
public:
	

	Layer(int n, string id);

	~Layer();

	string getID();
	unsigned int getSize();
	void setActivationFunction(float(*f)(float));
	void activateFunction();
	float getNeuronData(unsigned int n);
	void setLayerData(float mas[]);
	void linkWithLayer(Layer *linkWith);
};

#define layerPair pair< string, Layer* >

class NeuralNetwork
{
public:
	NeuralNetwork();
	~NeuralNetwork();

	void addLayer(unsigned int neuronQuantity, const string &layerID);
	bool connectLayers(const string &ID1, const string &ID2);

private:
	inline bool checkLayerExist(const string &ID);
	unordered_map<string, Layer*> layers; // key, point to the layer of nodes
};
