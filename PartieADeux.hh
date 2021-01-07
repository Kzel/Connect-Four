#pragma once

#include "Parametres.hh"
#include "Partie.hh"


class PartieADeux: public Partie{
public:
	PartieADeux(Parametres param);
	int jeu();
	void reinitialisePartie();
	void remplitGrille();
	void debutPartie();
	int VerifieFin();
	int finPartie(int issue);


protected:

	string tabJoueurs[2];

};