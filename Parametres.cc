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
		cout<<"L'option de l'affichage d'Index est ferme"<<endl;
	}else{
		cout<<"L'option de l'affichage d'Index est ouverte"<<endl;
	}

	if(getCritereEgalite()==0){
		cout<<"L'option de la critere d'egalite est ferme"<<endl;
	}else{
		cout<<"L'option de la critere d'egalite est ouverte"<<endl;
	}

	switch (getNivDifficulte())
	{
	case 1:
		cout<<"Le niveau est facile"<<endl;
		break;

	case 2:
		cout<<"Le niveau est moyen"<<endl;
		break;

	case 3:
		cout<<"Le niveau est difficile"<<endl;
		break;

	default:
		break;
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

void Parametres::afficherTous(){
	cout<<"Parametre"<<endl;
	if(getAffichageSymboles()){
		cout<<"1: Affichage les symboles :O"<<endl;
	}else{
		cout<<"1: Affichage les symboles :X"<<endl;
	}

	if(getAffichageIndex()){
		cout<<"2: Affichage les indexs :Oui"<<endl;
	}else{
		cout<<"2: Affichage les indexs :Non"<<endl;
	}

	if(getCritereEgalite()){
		cout<<"3: Egalite :Oui"<<endl;
	}else{
		cout<<"3: Egalite :Non"<<endl;
	}

	switch (getNivDifficulte())
	{
	case 1:
		cout<<"4: Niveau :facile"<<endl;
		break;

	case 2:
		cout<<"4: Niveau :moyen"<<endl;
		break;

	case 3:
		cout<<"4: Niveau :Difficile"<<endl;
		break;
	default:
		break;
	}

	if(getSansEgalite()){
		cout<<"5: Sans egalite :Oui"<<endl;
	}else{
		cout<<"5: Sans egalite :Non"<<endl;
	}
		
	if(getAvecResume()){
		cout<<"6: Avec resume :Oui"<<endl;
	}else{
		cout<<"6: Avec resume :Non"<<endl;
	}
	cout<<"Tapez le numero du parametre que vous voulez changer"<<endl;

}

void Parametres::Changer(int num){
	int x1,x2,x3,x4,x5,x6;
	cout<<"Comment vous voulez changer ce parametre?";
	cout<<"Tapez ce que vous voulez";
	switch (num)
	{
	case 1:
		cout<<"0: Affichage les symboles :O "<<endl;
		cout<<"1: Affichage les symboles :X "<<endl;
		cin>>x1;
		if(cin){
			setAffichageSymboles(x1);
		}else{
			setAffichageSymboles(x1);
		}
		break;

	case 2:
		cout<<"0: N'afficher pas d'index"<<endl;
		cout<<"1: Afficher les indexs"<<endl;
		cin>>x2;
		if(cin){
			setAffichageIndex(x2);
		}else{
			setAffichageIndex(x2);
		}
		break;

	case 3:
	
		cout<<"0: Avec critere Egalite"<<endl;
		cout<<"1: Sans critere Egalite"<<endl;
		cin>>x3;
		if(cin){
			setCritereEgalite(x3);
		}else{
			setCritereEgalite(x3);
		}
		break;

	case 4:
		cout<<"1: Le niveau facile"<<endl;
		cout<<"2: Le niveau moyen"<<endl;
		cout<<"3: Le niveau difficile"<<endl;
		cin>>x4;
		if(cin){
			setNivDifficulte(x4);
		}else{
			setNivDifficulte(x4);
		}
		break;

	case 5:
		cout<<"0: Sans Egalite"<<endl;
		cout<<"1: Avec Egalite"<<endl;
		cin>>x5;
		if(cin){
			setSansEgalite(x5);
		}else{
			setSansEgalite(x5);
		}
		break;

	case 6:
		cout<<"0: Sans resume"<<endl;
		cout<<"1: Avec resume"<<endl;
		cin>>x6;
		if(cin){
			setAvecResume(x6);
		}else{
			setAvecResume(x6);
		}
		break;

	default:
		break;
	}

}