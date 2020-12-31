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


void Partie::majAffichageMorpionIndex(){

	int i,j;
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
		
		cout<<"|"<<endl<<"		|-----------------------|"<<std::endl;
	}
	cout<<"		# 0  1  2  3  4  5  6  #"<<endl;
}

void Partie::majAffichageMorpion(){
	int i,j;
	for(i=5;i>=0;i--){
		cout<<endl;
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
		
		cout<<"|"<<endl<<"		|-----------------------|"<<std::endl;
	}
}

void Partie::majAffichageChiffresIndex(){
	int i,j;
	for(i=5;i>=0;i--){
		cout<<i<<"		| ";
		for (j=0;j<7;j++){
			if (grille[i][j]==-1) 
				cout<<"0";
			if (grille[i][j]==0) 
				cout<<"1";
			if (grille[i][j]==1) 
				cout<<"2";
			cout<<"  ";
		}
		
		cout<<"|"<<endl<<"		|-----------------------|"<<std::endl;
	}
	cout<<"		# 0  1  2  3  4  5  6  #"<<endl;
}

void Partie::majAffichageChiffres(){
	int i,j;
	for(i=5;i>=0;i--){
		cout<<endl;
		cout<<"		| ";
		for (j=0;j<7;j++){
			if (grille[i][j]==-1) 
				cout<<"0";
			if (grille[i][j]==0) 
				cout<<"1";
			if (grille[i][j]==1) 
				cout<<"2";
			cout<<"  ";
		}
		
		cout<<"|"<<endl<<"		|-----------------------|"<<std::endl;
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