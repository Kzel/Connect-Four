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
	 //on maj nb3Pions au cas où on 
 	//ne serait pas rentré dans departagePions	
	comptage3Pions(0);
	comptage3Pions(1);

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
	int colonne;
	cout<<"A ton tour "<<tabJoueurs[JoueurCourant]<<". Tes jetons sont les:";
	if (!(par.getAffichageSymboles())){
		if (!JoueurCourant){
			cout<<"X"<<endl;
		}
		else{
			cout<<"O"<<endl;
		}
	}
	else{
		if (!JoueurCourant){
			cout<<"1"<<endl;
		}
		else{
			cout<<"2"<<endl;
		}

	}
	cout<<"Remplis la colonne de ton choix"<<endl;
	cin>>colonne;
	cout<<endl;
	
	//tant que la colonne choisie est remplie, on redemande au joueur de jouer
	while(nbParColonne[colonne]==6){
			
		majAffichage();
		cout<<"choisis une colonne non remplie"<<endl;
		cin>>colonne;
	} 
	

	grille[nbParColonne[colonne]][colonne]=JoueurCourant;
	nbParColonne[colonne]++; //maj ligneRemplieMax
	
}
void PartieAvecResume::reinitialisePartie(){
 	//on remet tous les attributs a leur état de base
	ligneRemplieMax=-1;
	compteurTour=0;
	srand(time(NULL));
	JoueurCourant=rand()%2;
	for(int i=0;i<=1;i++){
		tpsJoueur[i]=0;
		nb3Pions[i]=0;
	}
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
void PartieAvecResume::debutPartie(){
 	if (demandeNom){
 		cout	<< "Quel est le nom du premier joueur ?" << endl;
		cin>>tabJoueurs[0];
		cout<<std::endl<<std::endl <<"Quel est le nom du second joueur ?" <<endl;
		cin>>tabJoueurs[1];  
 	}
 	if(JoueurCourant==0){
 		cout<<endl;
 		cout<<"C'est " << tabJoueurs[0] << " qui commence"<<endl;
 	}
 	else{
 		cout<<"C'est " << tabJoueurs[1] << " qui commence"<<endl;
 	}
}

int PartieAvecResume::departagePions(){
	//cas où le critere est le nombre d'alignements de 3 pions
	comptage3Pions(0);
	comptage3Pions(1);
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
void PartieAvecResume::comptage3Pions(int joueur){
	//c'est dans cette fonction qu'on change nb3Pions
	int somme=0;
	int i;
	//nombre de 3 pions dans les lignes
	//on rajoute ce nombre a somme
	for(i=0;i<=5;i++)
		somme+=comptageUnitaire(i,0,i,6,joueur);
	//nombre de 3 pions dans les colonnes
	for(i=0;i<=6;i++)
		somme+=comptageUnitaire(0,i,5,i,joueur);

	//nombre de 3 pions dans les diagonales
	//diagonales coin bas gauche vers coin haut droit
	for(i=0;i<=3;i++)
		somme+=comptageUnitaire(3-i,0,5,2+i,joueur);

	for(i=0;i<=3;i++)
		somme+=comptageUnitaire(0,1+i,5-i,6,joueur);

	//diagonales coin haut gauche vers coin bas droit
	for(i=0;i<=3;i++)
		somme+=comptageUnitaire(2+i,0,0,2+i,joueur);

	for(i=0;i<=3;i++)
		somme+=comptageUnitaire(5,1+i,0+i,6,joueur);

	nb3Pions[joueur]=somme;
}

int PartieAvecResume::comptageUnitaire(int l1,int c1,int l2,int c2,int joueur){
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
