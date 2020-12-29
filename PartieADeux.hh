#include "Parametres.hh"
#include "Partie.hh"

class PartieADeux: public Partie{
public:
	PartieADeux(Parametres param);
	int jeu();
	void debutPartie();
	int finPartie(int issue);

protected:

	string tab2Joueurs[2];

};