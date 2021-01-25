#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Partie.hh"
#include "PartieADeux.hh"
#include "PartieAvecResume.hh"
#include "Parametres.hh"
#include "Jeu.hh"

using namespace std;



// TEST_CASE("1:Partie: detection diagonale"){
// 	//on teste diagonales dans les 2 sens
// 	//et pour les 2 joueurs
// 	Parametres param;
// 	PartieADeux p(param);
// 	p(0,0)=0;
// 	p(1,1)=0;
// 	p(2,2)=0;
// 	p(3,3)=0;
// 	p.majAffichage();
// 	cout<<endl;
// 	cout<<"VerifieDiago:"<<p.VerifieDiago(0,0,5,5)<<endl;
// 	REQUIRE(p.VerifieDiagoBH()==0);
// 	REQUIRE(p.VerifieDiagoHB()==-1);
// 	p(2,6)=1;
// 	p(3,5)=1;
// 	p(4,4)=1;
// 	p(5,3)=1;
// 	p.majAffichage();
// 	cout<<endl;
// 	cout<<"VerifieDiago:"<<p.VerifieDiago(5,3,2,6)<<endl;
// 	REQUIRE(p.VerifieDiagoHB()==1);
// 	cout<<"------------------"<<endl;
// }

// TEST_CASE("2:maj ligneRemplieMax"){
// 	Parametres param;
// 	PartieADeux p(param);
// 	for(int i=0;i<=20;i++){
		
// 		p.remplitGrille();
// 		p.majAttributs();
// 		p.majAffichage();
// 		cout<<"ligne remplie max: "<<p.getLigneRemplieMax()<<endl;	
// 	}
// 	cout<<"------------------"<<endl;
// }



// TEST_CASE("3: PionsAlignes compte3Pions"){
// 	PionsAlignes p;
// 	p.ajouterPion(0);
// 	p.ajouterPion(0);
// 	p.ajouterPion(0);
// 	p.ajouterPion(1);
// 	p.ajouterPion(1);
// 	p.ajouterPion(0);
// 	p.ajouterPion(0);
// 	p.ajouterPion(0);
// 	p.afficheVecteur();
// 	cout<<"Joueur0: "<<p.compte3Pions(0)<<endl;
// 	cout<<"Joueur1: "<<p.compte3Pions(1)<<endl;
// 	REQUIRE(p.compte3Pions(0)==2);
// 	REQUIRE(p.compte3Pions(1)==0);
// 	cout<<"------------------"<<endl;
// }

TEST_CASE("4: PartieAvecResume comptageUnitaire"){
	Parametres param;
	PartieAvecResume p(param);
	p.grilleTest();
	p.majAffichage();
	cout<<"ligne 0 pour j1:"<<p.comptageUnitaire(0,0,0,6,0)<<endl;
	cout<<"colonne 5 pour j2:"<<p.comptageUnitaire(0,5,2,5,1)<<endl;
	cout<<"j2 diago 2,1-0,3:"<<p.comptageUnitaire(2,1,0,3,1)<<endl;
	cout<<"j2 diago 0,3-2,5:"<<p.comptageUnitaire(0,3,2,5,1)<<endl;
	cout<<"------------------"<<endl;

}
TEST_CASE("5: comptage 3 pions alignes"){
	Parametres param;
	PartieAvecResume p(param);
	p.grilleTest();
	p.majAffichage();
	p.comptage3Pions(0);
	p.comptage3Pions(1);
	cout<<"J1 3 pions :"<<p.getnb3Pions(0)<<endl;
	cout<<"J2 3 pions :"<<p.getnb3Pions(1)<<endl;
	REQUIRE(p.getnb3Pions(0)==8);
	REQUIRE(p.getnb3Pions(1)==4);
	cout<<"------------------"<<endl;
}

TEST_CASE("6: departage egalite sur pions"){

	Parametres param;
	PartieAvecResume p(param);
	p.grilleEgalite();
	p.majAffichage();
	REQUIRE(p.VerifieFin()==1);
	cout<<"------------------"<<endl;

}
TEST_CASE("7 :calcul temps joueurs"){
	//on pense dans ce testcase
	//a verifier si le temps du joueur se remet a jour lorsqu'il
	//choisit une mauvaise colonne
	Parametres param;
	PartieAvecResume p(param);
	p.debutPartie();
	for(int i=0;i<=3;i++){
		p.remplitGrille();
		cout<<"joueur1 temps:"<< p.getTpsJoueur(0)<<" secondes"<<endl;
		cout<<"joueur2 temps:"<< p.getTpsJoueur(1)<<" secondes"<<endl;
		p.majAttributs();
	}
}

TEST_CASE("8: egalite:meme nombre d'alignement de 3 pions+critereEgalite=pions"){
	Parametres param;
	PartieAvecResume p(param);
	p.grilleMemePions();
	p.majAffichage();
	cout<<"joueur1 temps:"<< p.getTpsJoueur(0)<<" secondes"<<endl;
	cout<<"joueur2 temps:"<< p.getTpsJoueur(1)<<" secondes"<<endl;
	REQUIRE(p.VerifieFin()==0);
}

TEST_CASE("9: changement des parametres"){

	Parametres param;
	cout<<param.consulteParam()<<endl;
    switch(param.consulteParam()) {
    case 1 : 
		param.affsymbole();
        break;    
    case 2 : 
		param.affindex();
        break;
	case 3 : 
		param.affcritere();
        break;
	case 4 : 
		param.affdiff();
        break;
	case 5 :
		param.affsansegal();
        break;
	case 6 : 
		param.affresume();
        break;
	}	

}
