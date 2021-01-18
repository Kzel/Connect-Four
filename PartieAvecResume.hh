#pragma once


#include "Parametres.hh"
#include "Partie.hh"
#include "PartieADeux.hh"
#include <time.h>

class PartieAvecResume:public PartieADeux{

private: 
	int nb3Pions[2];
	double tpsJoueur[2];


public:
	PartieAvecResume(Parametres param);
	void comptage3Pions(int joueur);
	int comptageUnitaire(int l1,int c1,int l2,int c2,int joueur);
	int jeu();
	double getTpsJoueur(int joueur){return tpsJoueur[joueur];};
	void debutPartie();
	void remplitGrille();
	void affichageTour();
	void reinitialisePartie();
	int VerifieFin();
	int departageTemps();
	int departagePions();
	void afficheResume();
	int getnb3Pions(int joueur){return nb3Pions[joueur];};
	int finPartie(int issue);

};