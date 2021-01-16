#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Partie.hh"
#include "PartieADeux.hh"
#include "PartieAvecResume.hh"
#include "Parametres.hh"
#include "Jeu.hh"

using namespace std;



TEST_CASE("Partie: detection diagonale"){
	//on teste diagonales dans les 2 sens
	//et pour les 2 joueurs
	Parametres param;
	PartieADeux p(param);
	p(0,0)=0;
	p(1,1)=0;
	p(2,2)=0;
	p(3,3)=0;
	p.majAffichage();
	cout<<endl;
	cout<<"VerifieDiago:"<<p.VerifieDiago(0,0,5,5)<<endl;
	cout<<"VerifieDiagoBH:"<<p.VerifieDiagoBH()<<endl;
	p(2,6)=1;
	p(3,5)=1;
	p(4,4)=1;
	p(5,3)=1;
	p.majAffichage();
	cout<<endl;
	cout<<"VerifieDiago:"<<p.VerifieDiago(5,3,2,6)<<endl;
	cout<<"VerifieDiagoBH:"<<p.VerifieDiagoHB()<<endl;

}

// TEST_CASE("maj ligneRemplieMax"){
// 	Parametres param;
// 	PartieADeux p(param);
// 	for(int i=0;i<=20;i++){
		
// 		p.remplitGrille();
// 		p.majAttributs();
// 		p.majAffichage();
// 		cout<<"ligne remplie max: "<<p.getLigneRemplieMax()<<endl;
// 	}
// }

TEST_CASE("comptage 3 pions alignes"){
	Parametres param;
	PartieAvecResume p(param);
	p.grilleTest();
	p.majAffichage();
	cout<<"J1 pion :"<<p.comptage3Pions(0)<<endl;
	cout<<"J2 pion :"<<p.comptage3Pions(1)<<endl;
}

TEST_CASE("PionsAlignes compte3Pions"){
	PionsAlignes p;
	p.ajouterPion(0);
	p.ajouterPion(0);
	p.ajouterPion(0);
	p.ajouterPion(1);
	p.ajouterPion(1);
	p.ajouterPion(0);
	p.ajouterPion(0);
	p.ajouterPion(0);
	p.afficheVecteur();
	cout<<p.compte3Pions(0)<<endl;
	cout<<p.compte3Pions(1)<<endl;
}

TEST_CASE("PartieAvecResume comptageUnitaire"){
	Parametres param;
	PartieAvecResume p(param);
	p.grilleTest();
	p.majAffichage();
	cout<<"ligne 0 pour j1:"<<p.comptageUnitaire(0,0,0,6,0)<<endl;
	cout<<"colonne pr j2:"<<p.comptageUnitaire(0,5,2,5,1)<<endl;
	cout<<"diago j2:"<<p.comptageUnitaire(2,1,0,3,1)<<endl;
	cout<<"diago:"<<p.comptageUnitaire(0,3,2,5,1)<<endl;

}
//tester PionsAlignes et
// tester differents cas de departagement d'égalité