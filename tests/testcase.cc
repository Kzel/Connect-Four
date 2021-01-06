#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Partie.hh"
#include "PartieADeux.hh"
#include "Parametres.hh"
#include "Jeu.hh"

using namespace std;



TEST_CASE("Partie: detection diagonale"){
	Parametres param;
	PartieADeux p(param);
	p(0,0)=1;
	p(1,1)=1;
	p(2,2)=1;
	p(3,3)=1;
	p.majAffichage();
	cout<<endl;
	cout<<"VerifieDiago:"<<p.VerifieDiago(0,0,5,5)<<endl;

}