#include "Neuron.h"

float sigm(float x)  // standart Activation Function
{
	return (1.0f / (1.0f + float(pow(e, -x))));
}

Neuron::Neuron()
{
	this->data = 0.0f;
	this->activationFunction = &sigm;
}

Neuron::~Neuron()
{
	this->edges.clear();
}

void Neuron::setInput(float input)
{
	this->data = input;
}

void Neuron::activate()
{
	for (auto it = this->edges.begin(); it != this->edges.end(); ++it)
	{
		(*it)->son->increase(((*it)->weight) * (this->data));
	}
}

inline void Neuron::increase(float value)
{
	this->data += value;
}

float Neuron::activateFunction()
{
	this->data = (this->activationFunction)(this->data);
	return this->data;
}

void Neuron::setActivationFunction(float(*f)(float))
{
	this->activationFunction = f;
}

void Neuron::createLink(Neuron & connectWith)
{
	TEdge *newEdge = new TEdge();
	newEdge->son = &connectWith;
	newEdge->weight = 0.0f;
	this->edges.push_back(newEdge);
}

float Neuron::getData()
{
	return (this->data);
}

