#include <iostream>
#include <string>

using namespace std;

int main() 
{
	int userAge;
	string caract;
	bool raciste;

	// On pose les questions � l'utilisateur et on lui permet d'entrer une r�ponse.
	cout << "Quel est votre age ?" << endl;
	cin >> userAge;
	cout << "Quel est votre principal trait de caract�re ?" << endl;
	cin >> caract;
	cout << "Etes-vous raciste ?" << endl;
	cin >> raciste;

	cout << "Votre age est de " << userAge << endl;

	cout << "Votre trait de caract�re est: " << caract << endl;

	if (raciste) {
		cout << "Et vous �tes raciste ! Malheureux !" << endl;
	}
	else {
		cout << "Et vous avez du respect pour les autres races !" << endl;
	}
	return 0;
}