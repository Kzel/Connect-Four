#pragma once

#include <iostream>
#include <vector>

using namespace std;

class PionsAlignes{
public:
	PionsAlignes();
	void afficheVecteur();
	int estGagnant();
	int compte3Pions(int i);
	void ajouterPion(int pion);

private:

	vector<int> pions;
};