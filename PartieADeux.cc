#include "PartieADeux.hh"


 void PartieADeux::debutPartie(){
 	if (demandeNom){
 		cout	<< "Quel est le nom du premier joueur ?" << endl;
		cin>>tabJoueurs[0];
		cout<<std::endl<<std::endl <<"Quel est le nom du second joueur ?" <<endl;
		cin>>tabJoueurs[1];  
 	}
 	if(joueurCourant==0){
 		cout<<"C'est " << tabJoueurs[0] << " qui commence"<<endl;
 	}
 	else{
 		cout<<"C'est " << tabJoueurs[1] << " qui commence"<<endl;
 	}
 }

//selon l'issue, on envoie le resultat au joueur
 //
 int PartieADeux::finPartie(int issue){
 	int choixFin;
 	cout<<"----------------------------------";
 	switch (issue){
 		case 1:
 			cout<<"Felicitations ! Tu as gagne "<<tabJoueurs[0]<<endl;
 			break;
 		case 2:
 			cout<<"Felicitations ! Tu as gagne "<<tabJoueurs[1]<<endl;

 			break;
 		case 3:
 			cout<<"Match nul. Un coude à coude VREUMENT"<<endl; 
 			break;
 	}
 	 cout<<"Tu veux faire quoi maintenant?"<<endl;
 	cout<<"1:Recommencer		2:Recommencer en changeant les noms			3:Menu"<<endl;
 	cin>>choixFin;
 	//si le choix n'est pas le menu, on recommence une partie
 	if (choixFin!=3)
 		reinitialisePartie(choixFin);
 	return choixFin;
 }


 int PartieADeux::jeu(){

 	while(!VerifieFin()){

 	}
 	return finPartie(VerifieFin());

 }