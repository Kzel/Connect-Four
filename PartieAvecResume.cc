#include "PartieAvecResume.hh"


PartieAvecResume::PartieAvecResume(Parametres param):PartieADeux(param){
	for(int i=0;i<2;i++){
		nb3Pions[i]=0;
		tpsJoueur[i]=0;
	}
}

int PartieAvecResume::finPartie(int issue){
	 int choixFin;
 	cout<<"----------------------------------"<<endl;
 	switch (issue){
 		case 0:
 			cout<<"Felicitations ! Tu as gagne "<<tabJoueurs[0]<<endl;
 			break;
 		case 1:
 			cout<<"Felicitations ! Tu as gagne "<<tabJoueurs[1]<<endl;

 			break;
 		case 2:
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

int PartieAvecResume::departageTemps(){
		if(tpsJoueur[0]>tpsJoueur[1]){
			return 0;
		}
		else {
			return 1;
		}
}
void PartieAvecResume::remplitGrille(){
	
}
void PartieAvecResume::reinitialisePartie(){

}
// void PartieAvecResume::debutPartie(){
// 	cout<<"rien"<<endl;
// }

int PartieAvecResume::departagePions(){
	//cas où le critere est le nombre d'alignements de 3 pions

		if(nb3Pions[0]>nb3Pions[1]){
			return 0;
		}
		else if(nb3Pions[1]>nb3Pions[0]){
			return 1;
		}
		else{
			return departageTemps();
		}

}
int PartieAvecResume::Comptage3Pions(){
	//c'est dans cette fonction qu'on change nb3Pions
	//int somme;
	return 0;

}

int PartieAvecResume::ComptageUnitaire(int l1,int c1,int l2,int c2,int joueur){
	PionsAlignes pions;
	//on compte pour une ligne
	if(l1==l2){
		for (int i=c1;i<=c2;i++){
			pions.ajouterPion(grille[l1][i]);
		}
		return pions.compte3Pions(joueur);
	}
	//on compte pour une colonne
	else if(c1==c2){
		for (int i=l1;i<=l2;i++){
			pions.ajouterPion(grille[i][c1]);
		}
		return pions.compte3Pions(joueur);
	}
	//on compte pour une diagonale
	else{
		return 0;
	}
}

int PartieAvecResume::VerifieFin(){
	int i,j;

	//on verifie les lignes

	for(i=0;i<ligneRemplieMax;i++){
		PionsAlignes pions;
		for(j=0;j<=6;j++){
			pions.ajouterPion(grille[i][j]);
		}
		if(pions.estGagnant()!=-1)
			return pions.estGagnant();
	}
	//on verifie les colonnes
	for(j=0;j<=6;j++){
		if(!(nbParColonne[j]<4)){
			PionsAlignes pions;
			for(i=0;i<nbParColonne[j];i++){
				pions.ajouterPion(grille[i][j]);
			}
			if(pions.estGagnant()!=-1)
				return pions.estGagnant();
		}
	}

	//on verifie les diagonales
	if (!(ligneRemplieMax<4)){
		if (VerifieDiagoBH()!=-1)
			return VerifieDiagoBH();
		if (VerifieDiagoHB()!=-1)
			return VerifieDiagoHB();
	}

	//on verifie si les joueurs n'ont pas déposé tous leurs pions
	//remplacer lignes suivantes par 1 seule fct
	if (compteurTour==42 && par.getSansEgalite()){
		if(par.getCritereEgalite()){
			return departagePions();
		}
		else{
			return departageTemps();

		}
	}
	else if (compteurTour==42){
		return 2;
	}

	return -1;	
}

 int PartieAvecResume::jeu(){

 	while(VerifieFin()==-1){
 		remplitGrille();
 		majAttributs();
 		majAffichage();

 	}
 	return finPartie(VerifieFin());

 	
 }
