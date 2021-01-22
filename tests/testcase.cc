#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Partie.hh"
#include "PartieADeux.hh"
#include "PartieAvecResume.hh"
#include "Parametres.hh"
#include "Jeu.hh"

using namespace std;



// TEST_CASE("Partie: detection diagonale"){
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
// 	cout<<"VerifieDiagoBH:"<<p.VerifieDiagoBH()<<endl;
// 	p(2,6)=1;
// 	p(3,5)=1;
// 	p(4,4)=1;
// 	p(5,3)=1;
// 	p.majAffichage();
// 	cout<<endl;
// 	cout<<"VerifieDiago:"<<p.VerifieDiago(5,3,2,6)<<endl;
// 	cout<<"VerifieDiagoBH:"<<p.VerifieDiagoHB()<<endl;
// 	cout<<"------------------"<<endl;
// }

// TEST_CASE("maj ligneRemplieMax"){
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



// TEST_CASE("PionsAlignes compte3Pions"){
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
// 	cout<<p.compte3Pions(0)<<endl;
// 	cout<<p.compte3Pions(1)<<endl;
// 	cout<<"------------------"<<endl;
// }

// TEST_CASE("PartieAvecResume comptageUnitaire"){
// 	Parametres param;
// 	PartieAvecResume p(param);
// 	p.grilleTest();
// 	p.majAffichage();
// 	cout<<"ligne 0 pour j1:"<<p.comptageUnitaire(0,0,0,6,0)<<endl;
// 	cout<<"colonne pr j2:"<<p.comptageUnitaire(0,5,2,5,1)<<endl;
// 	cout<<"diago 2,1-0,3:"<<p.comptageUnitaire(2,1,0,3,1)<<endl;
// 	cout<<"diago 0,3-2,5:"<<p.comptageUnitaire(0,3,2,5,1)<<endl;
// 	cout<<"------------------"<<endl;

// }
// TEST_CASE("comptage 3 pions alignes"){
// 	Parametres param;
// 	PartieAvecResume p(param);
// 	p.grilleTest();
// 	p.majAffichage();
// 	p.comptage3Pions(0);
// 	p.comptage3Pions(1);
// 	cout<<"J1 pion :"<<p.getnb3Pions(0)<<endl;
// 	cout<<"J2 pion :"<<p.getnb3Pions(1)<<endl;
// 	cout<<"------------------"<<endl;
// }

// TEST_CASE("departage egalite sur pions"){

// 	Parametres param;
// 	PartieAvecResume p(param);
// 	p.grilleEgalite();
// 	p.majAffichage();
// 	REQUIRE(p.VerifieFin()==1);
// 	cout<<"------------------"<<endl;

// }
TEST_CASE("calcul temps joueurs"){
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

TEST_CASE("egalite:meme nombre d'alignement de 3 pions+critereEgalite=pions"){
	Parametres param;
	PartieAvecResume p(param);
	p.grilleMemePions();
	p.majAffichage();
	cout<<"joueur1 temps:"<< p.getTpsJoueur(0)<<" secondes"<<endl;
	cout<<"joueur2 temps:"<< p.getTpsJoueur(1)<<" secondes"<<endl;
	REQUIRE(p.VerifieFin()==0);
}

//tester PionsAlignes et
// tester differents cas de departagement d'égalité
//tester Jeu.cc classe créée en fonction de decision Joueur