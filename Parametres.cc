#include "Parametres.hh"

using namespace std;

Parametres::Parametres(){
	affichageSymboles=1;
	affichageIndex=1;
	critereEgalite=1;
	nivDifficulte=1;
	sansEgalite=1;
	avecResume=1;

}

int Parametres::consulteParam(){
	if(getAffichageSymboles()==0){
		cout<<"L'option de l'affichage de symbol est ferme"<<endl;
	}else{
		cout<<"L'option de l'affichage de symbol est ouverte"<<endl;
	}

	if(getAffichageIndex()==0){
		cout<<"L'option de l'affichage d'Indice est ferme"<<endl;
	}else{
		cout<<"L'option de l'affichage d'Indice est ouverte"<<endl;
	}

	if(getCritereEgalite()==0){
		cout<<"L'option de la critere d'egalite est ferme"<<endl;
	}else{
		cout<<"L'option de la critere d'egalite est ouverte"<<endl;
	}

	if(getNivDifficulte()==0){
		cout<<"L'option du niveau de difficulte est ferme"<<endl;
	}else{
		cout<<"L'option du difficulte est ouverte"<<endl;
	}

	if(getSansEgalite()==0){
		cout<<"L'option de sans egalite est ferme"<<endl;
	}else{
		cout<<"L'option de sans egalite est ouverte"<<endl;
	}

	if(getAvecResume()==0){
		cout<<"L'option du resume est ferme"<<endl;
	}else{
		cout<<"L'option du resume est ouverte"<<endl;
	}
	return 0;
}

