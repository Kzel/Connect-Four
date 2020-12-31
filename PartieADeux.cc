#include "PartieADeux.hh"


PartieADeux::PartieADeux(Parametres param):Partie(param){

}


 void PartieADeux::debutPartie(){
 	if (demandeNom){
 		cout	<< "Quel est le nom du premier joueur ?" << endl;
		cin>>tabJoueurs[0];
		cout<<std::endl<<std::endl <<"Quel est le nom du second joueur ?" <<endl;
		cin>>tabJoueurs[1];  
 	}
 	if(JoueurCourant==0){
 		cout<<"C'est " << tabJoueurs[0] << " qui commence"<<endl;
 	}
 	else{
 		cout<<"C'est " << tabJoueurs[1] << " qui commence"<<endl;
 	}
 }

//selon l'issue, on envoie le resultat au joueur
 //
 int PartieADeux::finPartie(int issue){
 	int choixFin;
 	cout<<"----------------------------------"<<endl;
 	switch (issue){
 		case 1:
 			cout<<"Felicitations ! Tu as gagne "<<tabJoueurs[0]<<endl;
 			break;
 		case 2:
 			cout<<"Felicitations ! Tu as gagne "<<tabJoueurs[1]<<endl;

 			break;
 		case 3:
 			cout<<"Match nul. Un coude à coude VREUMENT"<<endl; 
 			break;
 	}
 	 cout<<"Tu veux faire quoi maintenant?"<<endl;
 	cout<<"1:Recommencer		2:Recommencer en changeant les noms			3:Menu"<<endl;
 	cin>>choixFin;

 	//on met a jour demandeNom pour savoir si on demande les noms a la prochaine partie
 	if (choixFin==1){
 		demandeNom=0;
 	}
 	else{
 		demandeNom=1;
 	}
 	//si le choix n'est pas le menu, on recommence une partie
 	if (choixFin!=3)
 		reinitialisePartie();
 	return choixFin;
 }

  void PartieADeux::reinitialisePartie() {
 	//on remet tous les attributs a leur état de base
	ligneRemplieMax=0;
	compteurTour=0;
	srand(time(NULL));
	JoueurCourant=rand()%2;
	map<int,int>::iterator it;
	//on remet le nombre de jetons par colonne à 0 partout
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

	//cas où le joueur a choisi de renommer les participants
	if (demandeNom){
		debutPartie();
	}


 }

void PartieADeux::remplitGrille(){
	int colonne;
	cout<<"A ton tour"<<tabJoueurs[JoueurCourant] <<". Remplis la colonne de ton choix"<<endl;
	cin>>colonne;
	if (nbParColonne[colonne]<6){
		grille[nbParColonne[colonne]][colonne]=JoueurCourant;
	}
	else{
		majAffichage();
		cout<<"choisis une colonne non remplie"<<endl;
	}

}


 int PartieADeux::jeu(){

 	// while(!VerifieFin()){

 	// }
 	// return finPartie(VerifieFin());

 	return 0;
 	
 }
