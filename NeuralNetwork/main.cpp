#include <iostream>
#include "NeuralNetwork.h"
#include "FileSystem.h"

using namespace std;

int main()
{
	NeuralNetwork net("testNetwork");
	FileSystem fs;
	net.addLayer(5, "kek");
	net.addLayer(6, "lol");
	net.connectLayers("lol", "kek");
	float mass[5] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f };
	net.setLayerData(mass, "kek");
	wcout << fs.getCurDir();
	system("pause");
	return 0;
}

/// TODO ///
//1 filework (write/read weights from files +++ "interpretator" for network)
//2 optimize file system

// write exeptions
// divide headers and cpp parts of code
/*
FILE SYSTEM:
name of network:
	layer name:
		weights.txt ///

*/