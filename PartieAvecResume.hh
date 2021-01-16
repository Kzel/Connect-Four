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
	void Comptage3Pions(int joueur);
	int ComptageUnitaire(int l1,int c1,int l2,int c2,int joueur);
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