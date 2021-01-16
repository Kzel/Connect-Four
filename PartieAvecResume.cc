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
 	// on affiche le resume si il y a lieu
 	if(par.getAvecResume())
 		afficheResume();
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

void PartieAvecResume::afficheResume(){
	cout<<"----------------------------------"<<endl;
	cout<<"RESUME DE LA PARTIE:"<<endl;
	cout<<endl;
	cout<<"Nombre de tours de la partie: "<<compteurTour<<endl;
	cout<<"Joueur 1: "<<tabJoueurs[0]<<endl;
	if (par.getAffichageSymboles())
		cout<<"Symbole pions: 1"<<endl;
	else
		cout<<"Symbole pions: X"<<endl;
	cout<<"Nombre de 3 pions alignes: "<<nb3Pions[0]<<endl;
	cout<<endl;
	cout<<"Joueur 2: "<<tabJoueurs[1]<<endl;
	if (par.getAffichageSymboles())
		cout<<"Symbole pions: 2"<<endl;
	else
		cout<<"Symbole pions: O"<<endl;
	cout<<"Nombre de 3 pions alignes: "<<nb3Pions[1]<<endl;
	cout<<"----------------------------------"<<endl;
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
	Comptage3Pions(0);
	Comptage3Pions(1);
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
void PartieAvecResume::Comptage3Pions(int joueur){
	//c'est dans cette fonction qu'on change nb3Pions
	int somme;
	int i;
	//nombre de 3 pions dans les lignes
	//on rajoute ce nombre a somme
	for(i=0;i<=5;i++)
		somme+=ComptageUnitaire(i,0,i,6,joueur);
	//nombre de 3 pions dans les colonnes
	for(i=0;i<=6;i++)
		somme+=ComptageUnitaire(0,i,5,i,joueur);
	
	//nombre de 3 pions dans les diagonales
	//diagonales coin bas gauche vers coin haut droit
	for(i=0;i<=3;i++)
		somme+=ComptageUnitaire(3-i,0,5,2+i,joueur);
	
	for(i=0;i<=3;i++)
		somme+=ComptageUnitaire(0,1+i,5-i,6,joueur);

	//diagonales coin haut gauche vers coin bas droit
	for(i=0;i<=3;i++)
		somme+=ComptageUnitaire(2+i,0,0,2+i,joueur);
	for(i=0;i<=3;i++)
		somme+=ComptageUnitaire(5,1+i,0+i,6,joueur);

	nb3Pions[joueur]=somme;
}

int PartieAvecResume::ComptageUnitaire(int l1,int c1,int l2,int c2,int joueur){
	PionsAlignes pions;
	int i;
	//on compte pour une ligne
	if(l1==l2){
		for (i=c1;i<=c2;i++){
			pions.ajouterPion(grille[l1][i]);
		}
	}
	//on compte pour une colonne
	else if(c1==c2){
		for (i=l1;i<=l2;i++){
			pions.ajouterPion(grille[i][c1]);
		}
		
	}
	//on compte pour une diagonale
	else{
		if(l2>l1){
			for(i=0;i<=l2-l1;i++){
				pions.ajouterPion(grille[l1+i][c1+i]);
			}
		}
		else{
			for(i=0;i<=l1-l2;i++){
				pions.ajouterPion(grille[l1-i][c1+i]);
			}		
		}

	}
	return pions.compte3Pions(joueur);
}

int PartieAvecResume::VerifieFin(){


	int retour=-1;
	//on verifie les lignes
	retour=VerifieLignes();
	if(retour!=-1)
		return retour;
	
	//on verifie les colonnes
	retour=VerifieColonnes();
	if(retour!=-1)
		return retour;

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
