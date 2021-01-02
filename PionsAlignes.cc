#include "PionsAlignes.hh"

using namespace std;

PionsAlignes::PionsAlignes(){

}

int PionsAlignes::estGagnant(){
	//taille du vecteur doit être supérieure a 2
	int nb=1;
	vector<int>::iterator iter;
	int prec=*(pions.begin());
	for (iter=pions.begin()+1;iter!=pions.end();iter++){
		if(*iter!=-1){
			if(*iter!=prec){
				nb=1;
			}
			else{
				nb++;
			}
		}
		//si on a un enchainement de 4 pions identiques
		//on retourne le chiffre lié au pion
		if(nb==4)
			return *iter;
		
		prec=*iter;
	}
	return -1;

}

void PionsAlignes::ajouterPion(int pion){
	pions.push_back(pion);

}