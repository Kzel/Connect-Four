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
	int comptage3Pions(int joueur);
	int comptageUnitaire(int l1,int c1,int l2,int c2,int joueur);
	int jeu();
	void debutPartie();
	void remplitGrille();
	void reinitialisePartie();
	int VerifieFin();
	int departageTemps();
	int departagePions();
	void afficheResume();
	int finPartie(int issue);

};