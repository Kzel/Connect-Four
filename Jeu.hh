#pragma once

#include <iostream>
#include <string>
#include "Parametres.hh"
#include "Partie.hh"

class Jeu{
public:

	Jeu();
	void menu();
	void decisionMenu(int entree);
	void lancerParam();
	void lancerPartie();

private:
	Parametres param;
	Partie & partie;

};