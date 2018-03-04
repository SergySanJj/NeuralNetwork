#include "Neuron.h"



Neuron::Neuron()
{
	this->data = 0;
}


Neuron::~Neuron()
{
}

void Neuron::setInput(float input)
{
	this->data = input;
}

void Neuron::activate()
{
}

void Neuron::increase(float value)
{
}

float Neuron::activationFunction(float * f(float))
{
	return 0.0f;
}
