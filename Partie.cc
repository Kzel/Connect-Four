#include "Partie.hh"

using namespace std;

Partie::Partie(Parametres p){
	par=p;
	ligneRemplieMax=0;
	compteurTour=0;
	map<int,int>::iterator it;
	//on remet le nb de jetons par colonne à 0 partout
	for (it = nbParColonne.begin(); it  !=  nbParColonne.end(); ++it){
		it->second=0;

	}

	 for (int i=0; i<6; i++)  

	{

		for (int j=0; j<7; j++)
		{
			grille[i][j]=-1;
		}
	}
	srand(time(NULL));
	JoueurCourant=rand()%2;
	demandeNom=1;


}


 void Partie::reinitialisePartie(int choixNom) {
 	//on remet tous les attributs a leur état de base
	ligneRemplieMax=0;
	compteurTour=0;
	srand(time(NULL));
	JoueurCourant=rand()%2;
	map<int,int>::iterator it;
	//on remet le nb de jetons par colonne à 0 partout
	for (it = nbParColonne.begin(); it  !=  nbParColonne.end(); ++it){
		it->second=0;

	}


 	for (int i=0; i<6; i++)  
	{
		for (int j=0; j<7; j++)
		{
			grille[i][j]=-1;
		}
	}


 }

