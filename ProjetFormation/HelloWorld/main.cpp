#include <iostream>
#include <string>

using namespace std;

int main() 
{
	int userAge;
	string caract;
	bool raciste;

	// On pose les questions à l'utilisateur et on lui permet d'entrer une réponse.
	cout << "Quel est votre age ?" << endl;
	cin >> userAge;
	cout << "Quel est votre principal trait de caractère ?" << endl;
	cin >> caract;
	cout << "Etes-vous raciste ?" << endl;
	cin >> raciste;

	cout << "Votre age est de " << userAge << endl;

	cout << "Votre trait de caractère est: " << caract << endl;

	if (raciste) {
		cout << "Et vous êtes raciste ! Malheureux !" << endl;
	}
	else {
		cout << "Et vous avez du respect pour les autres races !" << endl;
	}
	return 0;
}