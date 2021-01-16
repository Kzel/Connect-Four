#pragma once
#include <iostream>
#include <string>
#include <map>
#include <time.h>
#include <stdlib.h>
#include "Partie.hh"
#include "Parametres.hh"

class PartieIAFacile: public Partie{
public:
	PartieIAFacile(Parametres param);
    void debutPartie();
    int finPartie(int issue);
    void reinitialisePartie();
    void remplitGrille();
    int verifieLigne();
    void tourOrdi();
    int jeu();

protected:
    string joueurnom;
};