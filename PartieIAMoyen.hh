#pragma once
#include <iostream>
#include <string>
#include <map>
#include <time.h>
#include <stdlib.h>
#include "Partie.hh"
#include "Parametres.hh"

class PartieIAMoyen: public Partie{
public:
	PartieIAMoyen(Parametres param);
    public:
    void debutPartie();
    int finPartie(int issue);
    void reinitialisePartie();
    void remplitGrille();
    int verifieLigne();
    int verifieColonne();
    void tourOrdi();
    int jeu();

protected:
    string joueurnom;



}