#pragma once
#include <vector>
#include <cmath>

#define e 2.71828f
typedef float(*floatFunc)(float);

class Neuron;

struct TEdge
{
	Neuron *son = nullptr;
	float weight = 0.0f;
};

class Neuron
{
public:
	Neuron();
	~Neuron();

	void setInput(float input);
	void activate();
	inline void increase(float value);
	float activateFunction();
	void createLink(Neuron &connectWith)
	{
		TEdge *newEdge = new TEdge();
		newEdge->son = &connectWith;
		newEdge->weight = 0.0f;
		this->edges.push_back(newEdge);
	}
	float standartActivationFunction(float x);
private:
	float data = 0.0f;
	std::vector< TEdge* > edges;
	float (Neuron::*activationFunction)(float) = &Neuron::standartActivationFunction;
};
