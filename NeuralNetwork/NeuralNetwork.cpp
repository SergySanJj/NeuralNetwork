#include "NeuralNetwork.h"

float sigmoidFunction(float x)    // standart Activation Function
{
	return (1.0f / (1.0f + float(pow(e, -x))));
}

NeuralNetwork::NeuralNetwork(const string &name) :networkName(name)
{
}

NeuralNetwork::~NeuralNetwork()
{
	for (auto it = this->layers.begin(); it != this->layers.end(); it++)
	{
		delete (*it).second;
	}
}

void NeuralNetwork::addLayer(unsigned int neuronQuantity, const string &layerID)
{
	if (this->layers.find(layerID) == this->layers.cend())
	{
		Layer * newLayer = new Layer(neuronQuantity, layerID);
		this->layers.insert(layerPair(layerID, newLayer));
	}
	else
		throw ID_ALREADY_EXISTS; // DO SOMETHING
}

bool NeuralNetwork::connectLayers(const string &ID1, const string &ID2)
{
	if (checkLayerExist(ID1) && checkLayerExist(ID2))
	{
		(*(this->layers.find(ID1))).second->linkWithLayer((*(this->layers.find(ID2))).second);
		return 1;
	}
	else
		return 0;
}

inline bool NeuralNetwork::checkLayerExist(const string & ID)
{
	if (this->layers.find(ID) != this->layers.cend())
	{
		return 1;
	}
	return 0;
}

Layer::Layer(int n, string id) :id(id), size(n)
{
	this->activationFunction = &sigmoidFunction;
	this->neurons = new vector<Neuron>(n);
	//this->size = n;
}

Layer::~Layer()
{
	delete this->neurons;
	this->neurons = nullptr;
}

string Layer::getID()
{
	return this->id;
}

unsigned int Layer::getSize()
{
	return (this->size);
}

void Layer::setActivationFunction(float(*f)(float))
{
	for (auto it = this->neurons->begin(); it != this->neurons->end(); ++it)
	{
		(*it).setActivationFunction(f);
	}
}

void Layer::activateFunction()
{
	for (auto it = this->neurons->begin(); it != this->neurons->end(); ++it)
	{
		(*it).activateFunction();
	}
}

float Layer::getNeuronData(unsigned int n)
{
	if (n < this->size)
	{
		return (this->neurons->at(n).getData());
	}
	else
		return 0.0f;
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