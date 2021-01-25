#pragma once
#include "Parametres.hh"
#include "Partie.hh"
#include "PionsAlignes.hh"


class PartieIADifficile: public Partie{
public:
	PartieIADifficile(Parametres param);
    void debutPartie();
    int finPartie(int issue);
    void reinitialisePartie();
    void remplitGrille();
    int VerifieFin();
    void verifi(int colonne,int sym);
    void tourOrdi();
    int jeu();

protected:
   string nomjoueur;
};