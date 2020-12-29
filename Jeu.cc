#include "Jeu.hh"

using namespace std;

Jeu::Jeu() {
	param=Parametres();

}

void Jeu::menu(){
	int entree;
	cout<<"----------------------------------------------"
	cout<<"Bonjour, ceci est un jeu de puissance 4."<<endl;
	cout<<"Tape l'un des chiffres indiques pour aller vers ce qui t'interesse!"<<endl;
	cout<<"1: Jouer	contre IA		2: Jouer a 2		3: Parametres"<<endl;
	cin>>entree;
	decisionMenu(entree);


}

//suivant la decision du joueur, on initialise l'attribut partie
void Jeu::decisionMenu(int entree){
	switch(entree){

		case 1:
			if (param.nivDifficulte==0){
				partie=PartieIAfacile(param);

			}
			else if(param.nivDifficulte==1){
				partie=PartieIAmoyen(param);

			}
			else{
				partie=PartieIAdifficile(param);

			}
			lancePartie();
			break;


		case 2:
			//avecResume=0, on crée une partie sans recap a la fin
			if (!param.getAvecResume()){
				partie=PartieADeux(param);

			}
			//sinon on crée une partie avec recap
			else{
				partie=PartieAvecResume(param);

			}
			lancePartie();
			break

		case 3:
			lancerParam();
			break;
	}

}

//a lancer apres decisionMenu()!!
void Jeu::lancePartie(){
	//si le joueur veut rejouer alors partie.jeu()=0
	while(partie.jeu()!=3)
	menu();
}

void Jeu::lancerParam(){
	while(!param.consulteParam());
	menu();
}