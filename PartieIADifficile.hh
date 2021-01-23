#pragma once
#include "Parametres.hh"
#include "Partie.hh"


class PartieIADifficile: public Partie{
public:
	PartieIADifficile(Parametres param);
    void debutPartie();
    int finPartie(int issue);
    void reinitialisePartie();
    void remplitGrille();
    int VerifieFin();
    void tourOrdi();
    int jeu();

protected:
   string tabJoueurs[2];
};