#pragma once
#include <vector>
#include <math.h>

#define e 2.71828
typedef float(*floatFunc)(float);

class Neuron;

float standartActivationFunction(float x)
{
	return (1 / (1 + pow(e, -x)));
}

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
	float activationFunction(floatFunc f);
	void createLink(Neuron *connectWith)
	{
		TEdge *newEdge = new TEdge();
		newEdge->son = connectWith;
		newEdge->weight = 0.0f;
		this->edges.push_back(newEdge);
	}

private:
	float data = 0.0f;
	std::vector<TEdge> edges;
};
