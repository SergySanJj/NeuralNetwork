#pragma once
#include <fstream>
#include "Neuron.h"
#include <vector>

using namespace std;


struct Layer
{
private:
public:
	vector<Neuron> *neurons = nullptr;
	int id = 0;
	int size = 0;

	Layer(int n, int id);
	
	~Layer();

	void linkWithLayer(Layer *linkWith);
};

class NeuralNetwork
{
public:
	NeuralNetwork();
	~NeuralNetwork();

private:

};

