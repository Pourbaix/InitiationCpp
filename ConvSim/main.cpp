#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <fstream>

using namespace std;
const string negativeWords[] = {"ne", "pas", "rien"};

void compareSentence(vector<string> sentenceTable) {
	cout << "L'adresse du tableau dynamique est " << &sentenceTable << endl;
	cout << sentenceTable[0] << endl;
	vector<string> testTab;
	testTab.push_back("Oui");
	testTab.push_back("de");
	testTab.push_back("ouf");
	int compareScore = 0;
	for (int x = 0; x < sentenceTable.size(); x++) {
		cout << "La valeur de x est de " << x << endl;
		for (int y = 0; y < testTab.size(); y++) {
			if (sentenceTable[x] == testTab[y]) {
				cout << "Verif sur " << testTab[y] << endl;
				cout << "X vaut " << sentenceTable[x] << endl;
				cout << "compareScore incrémenté !" << endl;
				compareScore++;
			}
		}
	}
	cout << "Le score de comparaison est de " << compareScore << endl;


}

bool isNotGoodToEnter(string startMode) {
	// Ici on check si l'entrée de l'utilisateur convient par rapport à ce qui lui est demandé (1 ou 2)

	if (startMode == "2" || startMode == "1" ){
		return false;
	}
	else {
		return true;
	}
}

int slicer(string* sentence) {

	// On compte le nombre de mots dans la phrase et on ajoute chaque mot dans un tableau de taille dynamique 
	// VERIF SI LA PHRASE EST CORRECTE

	cout << "Ceci est la phrase: " << *sentence << endl;
	int count = 0;
	string word = "";
	vector<string> wordList;

	// IMPORTANT: Créer un pointeur sur un tableau dynamique.
	// vector<string>* ptnSentenceTable = &wordList;
	cout << "----------------------------" << endl;
	for (auto x: *sentence) {
		if (x == ' ') {
			wordList.push_back(word);
			cout << "Mot: " << word << " ajouté à l'array" << endl;
			count++;
			word = "";
		}
		else{
			word = word + x;
		}
	}
	if (word != "") {
		wordList.push_back(word);
		cout << "Mot: " << word << " ajouté à l'array" << endl;
		count ++;
	}
	cout << "Elle est composée de " << count << " mots." << endl;
	cout << "La taille de l'array qui contient les mots est de " << wordList.size() << endl;
	for (int x = 0; x < wordList.size(); x++) {
		cout << "Le mot numéro " << x << " est " << wordList[x] << endl;
	}
	cout << "-----------------------------" << endl;
	compareSentence(wordList);

	return 0;
}

int main() {
	cout << "ConvSim" << endl;
	cout << "Version 0.0.1 " << "by Pourbaix M." << endl;

	cout << "Bienvenue dans convSim! Voullez-vous entrez en mode apprentissage (tappez 1) ou en mode test (tappez 2)?" << endl;
	string startMode;
	cin >> startMode;
	while (isNotGoodToEnter(startMode)) {
		cout << "Veuillez entrer 1 ou 2 !" << endl;
		cin >> startMode;
		cin.ignore();
	}
	cin.ignore();

	if (startMode == "1") {
		cout << endl << "Bienvenue dans le mode d'apprentissage ! Ici, vous allez pouvoir apprendre de nouvelles chôses à notre programme." << endl << "Mais d'abord, comment vous appellez-vous ?" << endl;
		string userName;

		getline(cin, userName);

		cout << endl << "Bien le bonjour " << userName << "!" << endl;
		string sentns;
		cout << "Veuillez entrer la phrase utilisateur que vous voullez enregistrer dans le système ainsi que la phrase rendue par le programme" << endl;
		cout << "Le format est le suivant:" << endl << "---Phrase de l'utilisateur---" << ":" << "---Phrase rendue par le programme---" << endl;
		cout << "Exemple: Oui je vais bien:Parfait! Qu'avez-vous fait aujourd'hui?" << endl << endl;
		getline(cin, sentns);
		int colonNumber = 0;
		for (auto x : sentns) {
			if (x == ':') {
				colonNumber++;
			}
		}
		while (colonNumber != 1) {
			cout << "Veuillez respectez ce format: " << endl << "---Phrase de l'utilisateur---" << ":" << "---Phrase rendue par le programme---" << endl;
			getline(cin, sentns);
			colonNumber = 0;
			for (auto x : sentns) {
				if (x == ':') {
					colonNumber++;
				}
			}
		}
		cout << "La phrase qui sera enregistrée est: " << sentns << endl;
		ofstream monFlux("C:/Users/micha/Documents/ConvSim/ConvSim/test.txt");
		monFlux << sentns << endl;
	}
	else {
		cout << "Bienvenue dans le mode de test ! Ici on peut observer et tester le comportement de l'application." << endl;
		cout << "Êtes-vous prêt à commencer ?" << endl;
		string sentns;
		getline(cin, sentns);
		while (sentns == "") {
			getline(cin, sentns);
		}
		string* ptnSentns = &sentns;
		slicer(ptnSentns);
		return 0;
	}
}