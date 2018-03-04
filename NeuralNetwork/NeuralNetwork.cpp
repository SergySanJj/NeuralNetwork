#include "NeuralNetwork.h"



NeuralNetwork::NeuralNetwork()
{
}


NeuralNetwork::~NeuralNetwork()
{
}

Layer::Layer(int n, int id)
{
	this->neurons = new vector<Neuron>(n);
	this->id = id;
	this->size = n;
}

Layer::~Layer()
{
	delete this->neurons;
}

void Layer::linkWithLayer(Layer * linkWith)
{
	for (auto layer1 = this->neurons->begin(); layer1 != this->neurons->end(); layer1++)
	{
		for (auto layer2 = linkWith->neurons->begin(); layer2 != linkWith->neurons->end(); layer2++)
		{
			(*layer1).createLink(layer2);
		}
	}
}
