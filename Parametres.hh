#pragma once

#include <iostream>
#include <string>

class Parametres{
public:
	Parametres();
	int consulteParam();
	void Changer(int num);
	void affsymbole();
	void affindex();
	void affcritere();
	void affdiff();
	void affsansegal();
	void affresume();
	void changeaffsym(int x1);
	void changeaffind(int x2);
	void changeaffrap(int x3);
	void changediff(int x4);
	void changeegal(int x5);
	void changeresum(int x6);
	//getters
	int getAvecResume(){return avecResume;};
	int getNivDifficulte(){return nivDifficulte;};
	int getAffichageSymboles(){return affichageSymboles;};
	int getAffichageIndex(){return affichageIndex;};
	int getSansEgalite(){return sansEgalite;};
	int getCritereEgalite(){return critereEgalite;};
	//setters
	void setAffichageSymboles(int affichageSymb)
	{affichageSymboles=affichageSymb;};
	void setAffichageIndex(int affichageInd)
	{affichageIndex=affichageInd;};
	void setCritereEgalite(int critereEgal)
	{critereEgalite=critereEgal;};
	void setNivDifficulte(int nivDiff)
	{nivDifficulte=nivDiff;};
	void setSansEgalite(int sansEga)
	{sansEgalite=sansEga;};
	void setAvecResume(int avecResum)
	{avecResume=avecResum;};
	void affsym();

private:
	int affichageSymboles;
	int affichageIndex;
	int critereEgalite;
	int nivDifficulte;
	int sansEgalite;
	int avecResume;
};