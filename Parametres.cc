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
	int numero;
	cout<<"----------------------------------"<<endl;
	cout<<"Parametres:"<<endl;
	if(getAffichageSymboles()){
		cout<<"1: Affichage les symboles :1/2"<<endl;
	}else{
		cout<<"1: Affichage les symboles :O/X"<<endl;
	}

	if(getAffichageIndex()){
		cout<<"2: Affichage les indexs :Oui"<<endl;
	}else{
		cout<<"2: Affichage les indexs :Non"<<endl;
	}

	if(getCritereEgalite()){
		cout<<"3: Critere egalite : pions"<<endl;
	}else{
		cout<<"3: Critere egalite : rapidite"<<endl;
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
		cout<<"5: Sans egalite :oui"<<endl;
	}else{
		cout<<"5: Sans egalite :non"<<endl;
	}
		
	if(getAvecResume()){
		cout<<"6: Avec resume :Oui"<<endl;
	}else{
		cout<<"6: Avec resume :Non"<<endl;
	}
	cout<<"7: Menu"<<endl;
	cout<<"Tapez le numero du parametre que vous voulez changer"<<endl;
	cin>>numero;
	if(numero!=7){
		Changer(numero);
	}
	return numero;
}


void Parametres::Changer(int num){
	int x1,x2,x3,x4,x5,x6;
	cout<<"Comment vous voulez changer ce parametre?"<<endl;
	cout<<"Tapez ce que vous voulez"<<endl;
	switch (num)
	{
	case 1:
		cout<<"0: Affichage des symboles :O/X "<<endl;
		cout<<"1: Affichage des symboles :1/2 "<<endl;
		cin>>x1;
		if(cin){
			setAffichageSymboles(x1);
		}else{
			setAffichageSymboles(x1);
		}
		break;

	case 2:
		cout<<"0: Ne pas afficher pas d'index"<<endl;
		cout<<"1: Afficher les indexs"<<endl;
		cin>>x2;
		if(cin){
			setAffichageIndex(x2);
		}else{
			setAffichageIndex(x2);
		}
		break;

	case 3:
	
		cout<<"0: rapidite"<<endl;
		cout<<"1: 3 pions alignes"<<endl;
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
		cout<<"0: Avec Egalite"<<endl;
		cout<<"1: Sans Egalite"<<endl;
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