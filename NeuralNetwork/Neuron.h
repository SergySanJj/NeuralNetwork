#pragma once
#include <vector>

class Neuron;

struct TEdge
{
	Neuron *son = nullptr;
	float weight = 0;

};

class Neuron
{
public:
	Neuron();
	~Neuron();

	void setInput(float input);
	void activate();
	void increase(float value);
	float activationFunction(float *f(float));
private:
	float data = 0;
	std::vector<TEdge> edges;

};

