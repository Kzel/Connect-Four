#pragma once

#include <iostream>
#include <string>
#include <map>
#include <time.h>
#include "Parametres.hh"

//classe abstraite Partie
class Partie{
public:
	Partie(Parametres p);
	virtual int jeu() = 0;
	int nbPionPresentDiago(int l,int c,int l2, int c2);
	int nbPionPresentLig(int l);
	int nbPionPresentCol(int c);
	int VerifieFin();
	void majAffichage();
	void reinitialisePartie(int choixNom);
	virtual void debutPartie()=0;
	virtual int finPartie(int issue)=0;

protected:
	int ligneRemplieMax;
	int grille[7][6];
	int JoueurCourant;
	int compteurTour;
	int demandeNom;
	map<int,int> nbParColonne;
	Parametres par;

};