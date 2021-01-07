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
	void debutPartie();
	void remplitGrille();
	void reinitialisePartie();
	void debutPartie();
	int VerifieFin();
	int departageTemps();
	int departagePions();
	void afficheResume();
	int finPartie(int issue);

};