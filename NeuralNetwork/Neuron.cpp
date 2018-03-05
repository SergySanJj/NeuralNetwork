#include "Neuron.h"

Neuron::Neuron()
{
	this->data = 0.0f;
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
	this->data = (this->*activationFunction)(this->data);
	return this->data;
}

float Neuron::standartActivationFunction(float x)
{
	return (1.0f / (1.0f + float(pow(e, -x))));
}