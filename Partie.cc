#include "Partie.hh"


using namespace std;

Partie::Partie(Parametres p){
	par=p;
	ligneRemplieMax=-1;
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


void Partie::majAffichageMorpionIndex(){

	int i,j;
	cout<<"		# 0  1  2  3  4  5  6  #"<<endl;
	for(i=5;i>=0;i--){
		cout<<i<<"		| ";
		for (j=0;j<7;j++){
			if (grille[i][j]==-1) 
				cout<<" ";
			if (grille[i][j]==0) 
				cout<<"X";
			if (grille[i][j]==1) 
				cout<<"O";
			cout<<"  ";
		}
		
		cout<<"|"<<endl<<"		|----------------------|"<<std::endl;
	}

}

void Partie::majAffichageMorpion(){
	int i,j;
	cout<<endl;
	for(i=5;i>=0;i--){
		
		cout<<"		| ";
		for (j=0;j<7;j++){
			if (grille[i][j]==-1) 
				cout<<" ";
			if (grille[i][j]==0) 
				cout<<"X";
			if (grille[i][j]==1) 
				cout<<"O";
			cout<<"  ";
		}
		
		cout<<"|"<<endl<<"		|----------------------|"<<std::endl;
	}
}

void Partie::majAffichageChiffresIndex(){
	int i,j;
	cout<<"		# 0  1  2  3  4  5  6  #"<<endl;
	for(i=5;i>=0;i--){
		cout<<i<<"		| ";
		for (j=0;j<7;j++){
			if (grille[i][j]==-1) 
				cout<<" ";
			if (grille[i][j]==0) 
				cout<<"1";
			if (grille[i][j]==1) 
				cout<<"2";
			cout<<"  ";
		}
		
		cout<<"|"<<endl<<"		|----------------------|"<<std::endl;
	}

}

void Partie::majAffichageChiffres(){
	int i,j;
	cout<<endl;
	for(i=5;i>=0;i--){
		
		cout<<"		| ";
		for (j=0;j<7;j++){
			if (grille[i][j]==-1) 
				cout<<" ";
			if (grille[i][j]==0) 
				cout<<"1";
			if (grille[i][j]==1) 
				cout<<"2";
			cout<<"  ";
		}
		
		cout<<"|"<<endl<<"		|----------------------|"<<std::endl;
	}
}

void Partie::majAffichage(){
	//appelle la bonne fonction d'affichage de la grille
	// selon le réglage des parametres
	if (par.getAffichageSymboles()==0 && par.getAffichageIndex()==0){
		majAffichageMorpion();
	}
	else if(par.getAffichageSymboles()==0 && par.getAffichageIndex()==1){
		majAffichageMorpionIndex();
	}
	else if(par.getAffichageSymboles()==1 && par.getAffichageIndex()==0){
		majAffichageChiffres();
	}
	else{
		majAffichageChiffresIndex();
	}
}

void Partie::majAttributs(){
	//on change le joueur courant
	if (JoueurCourant==1)
		JoueurCourant--;
	else
		JoueurCourant++;
	compteurTour++;
	map<int,int>::iterator  it ;

	//on remet a jour ligneRemplieMax en parcourant la map contenant
	//le nombre de pions par colonne
	for(map<int,int>::iterator it=nbParColonne.begin();it!=nbParColonne.end();it++){
		if(it->second>ligneRemplieMax){
			ligneRemplieMax=it->second; //ligneRemplieMax contient le nb de pions dans colonne plus remplie
		}
	}

}
int Partie::VerifieDiago(int l1,int c1,int l2,int c2){
	PionsAlignes pions;
	int i;
	int j=c1;
	//cas où c'est une diagonale haut gauche vers bas droit
	if (l1<l2){
		for (i=l1;i<=l2;i++){
			pions.ajouterPion(grille[i][j]);
			j++;
		}
	
	}
	//cas où c'est une diagonale bas gauche vers haut droit
	else{
		for (i=l1;i>=l2;i--){
			pions.ajouterPion(grille[i][j]);
			j++;
		}

	}
	return pions.estGagnant();

}


int Partie::VerifieDiagoBH(){
	//on verifie chaque diagonale susceptible d'avoir 4 pions alignes
	if (VerifieDiago(0,3,3,6)!=-1)
		return VerifieDiago(0,3,3,6);

	if (VerifieDiago(0,2,4,6)!=-1)
		return VerifieDiago(0,2,4,6);

	if (VerifieDiago(0,1,5,6)!=-1)
		return VerifieDiago(0,1,5,6);

	if (VerifieDiago(0,0,5,5)!=-1)
		return VerifieDiago(0,0,5,5);

	if (VerifieDiago(1,0,5,4)!=-1)
		return VerifieDiago(1,0,5,4);

	if (VerifieDiago(2,0,5,3)!=-1)
		return VerifieDiago(2,0,5,3);
	return -1;

}

//verifie les diagonales possibles ayant une orientation bas gauche vers haut droite
int Partie::VerifieDiagoHB(){
	//on verifie chaque diagonale susceptible d'avoir 4 pions alignes
	if (VerifieDiago(3,0,0,3)!=-1)
		return VerifieDiago(3,0,0,3);

	if (VerifieDiago(4,0,0,4)!=-1)
		return VerifieDiago(4,0,0,4);

	if (VerifieDiago(5,0,0,5)!=-1)
		return VerifieDiago(5,0,0,5);

	if (VerifieDiago(5,1,0,6)!=-1)
		return VerifieDiago(5,1,0,6);

	if (VerifieDiago(5,2,1,6)!=-1)
		return VerifieDiago(5,2,1,6);

	if (VerifieDiago(5,3,2,6)!=-1)
		return VerifieDiago(5,3,2,6);
	return -1;
}
