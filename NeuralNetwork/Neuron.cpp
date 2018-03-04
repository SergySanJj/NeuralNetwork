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
	for (auto it = this->edges.begin(); it != this->edges.end(); it++)
	{
		(*it).son->increase((*it).weight * this->data);
		//(*it).son->data += (*it).weight * this->data;
	}
}

inline void Neuron::increase(float value)
{
	this->data += value;
}

float Neuron::activationFunction(floatFunc f)
{
	this->data = f(this->data);
	return this->data;
}
