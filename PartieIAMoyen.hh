#pragma once
#include "Parametres.hh"
#include "Partie.hh"


class PartieIAMoyen: public Partie{
public:
	PartieIAMoyen(Parametres param);
    void debutPartie();
    int finPartie(int issue);
    void reinitialisePartie();
    void remplitGrille();
    int VerifieFin();
    void veriligne(int colonne,int sym);
    void tourOrdi();
    int jeu();

protected:
   string tabJoueurs[2];
};