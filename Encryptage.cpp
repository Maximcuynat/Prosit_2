#include <iostream>
#include <string>
#include "Encryptage.h"
#include "Cesar.h"
#include "XOR.h"
#include "gestionFile.h"

short Niveau;
string mes;
std::string Encryptage::Cryptage(){
	cout << " # Entrez le message a envoyer.\n**> ";
	cin >> mes;
	cout << " # Entrez le niveau de cryptage 1, 2 ou 3 :";
	cin >> Niveau;
	// ----------------- //
	switch (Niveau){
	case 1:
		Cesar * Mes;
		gestionFile* File;
		Mes = new Cesar();
		File = new gestionFile();
		File->openFileAndSave(Mes->Crypt_message(mes));
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		cout << " ! Niveau incorect entrer, veuillez recommencer !" << endl;
		break;
	}
	return string();
}
