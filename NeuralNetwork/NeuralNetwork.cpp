#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork()
{
}

NeuralNetwork::~NeuralNetwork()
{
}

void NeuralNetwork::addLayer(unsigned int neuronQuantity, string layerID)
{

		Layer * newLayer = new Layer(neuronQuantity, layerID);
		if (this->layers.find(layerID) == this->layers.cend())
		{
			this->layers.insert(layerPair(layerID, newLayer));
		}
		else
			throw ID_ALREADY_EXISTS; // DO SOMETHING


}

bool NeuralNetwork::connectLayers(string ID1, string ID2)
{
	if (this->layers.find(ID1) != this->layers.cend() && this->layers.find(ID2) != this->layers.cend())
	{
		//(*(this->layers.find(ID1))).second.linkWithLayer((*this->layers.find(ID2)).second);
		
	}

	return false;
}

Layer::Layer(int n, string id)
{
	this->neurons = new vector<Neuron>(n);
	this->id = id;
	this->size = n;
}

Layer::~Layer()
{
	delete this->neurons;
}

string Layer::getID()
{
	return this->id;
}

void Layer::linkWithLayer(Layer * linkWith)
{
	for (auto layer1 = this->neurons->begin(); layer1 != this->neurons->end(); ++layer1)
	{
		for (auto layer2 = linkWith->neurons->begin(); layer2 != linkWith->neurons->end(); ++layer2)
		{
			(*layer1).createLink(*layer2);
		}
	}
}