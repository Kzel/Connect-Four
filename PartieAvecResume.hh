#pragma once


#include "Parametres.hh"
#include "Partie.hh"
#include "PartieADeux.hh"

class PartieAvecResume:public PartieADeux{

private: 
	int nb3Pions[2];
	float tpsJoueur[2];
public:
	PartieAvecResume(Parametres param);
	int Verifie3Pions();
	int jeu();
	void reinitialisePartie(int choixNom);
	void debutPartie();
	int finPartie(int issue);

};