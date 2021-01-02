#pragma once

#include <iostream>
#include <string>
#include <map>
#include <time.h>
#include "Parametres.hh"
#include "PionsAlignes.hh"

using namespace std;

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
	void majAffichageMorpion();
	void majAffichageChiffres();
	void majAffichageChiffresIndex();
	void majAffichageMorpionIndex();
	virtual void remplitGrille()=0;
	virtual void reinitialisePartie(int choixNom)=0;
	virtual void debutPartie()=0;
	virtual int finPartie(int issue)=0;

protected:
	int ligneRemplieMax;
	int grille[6][7];
	int JoueurCourant;
	int compteurTour;
	int demandeNom;
	map<int,int> nbParColonne;
	Parametres par;

};