#include <iostream>
#include <fstream>
#include <string>
#include "Encryptage.h"
#include "gestionFile.h"
#include "Cesar.h"
#include "XOR.h"

using namespace std;
short Choice;
string message;

string Message() {
	cout << "Entrez votre message a envoyer sans espace ou utilier des '_' \n**> ";
	cin >> message;
	return message;
}

void Error() {
	system("cls");
	cout << " ! Entrez un choix valide !" << endl;
	system("pause");
}

int main(){
	while (true) {
		system("cls");
		cout << " ? Envoyer un messsage ou lire un message ?\n 1-Envoyer\n 2-Recevoir\n**> ";
		cin >> Choice;
		switch (Choice){
		case 1:// ----------------------------------------------------------------- Crytpage
			system("cls");
			cout << " # Choisir un niveau de securite 1, 2 ou 3\n**> ";
			cin >> Choice;
			switch (Choice){
			case 1:
				system("cls");
				Cesar*       MesEncr;
				gestionFile* File;
				MesEncr =    new Cesar();
				File =       new gestionFile();
				File->openFileAndSave(MesEncr->Crypt_message(Message()));
				break;
			case 2:
				system("cls");
				XOR *        MesXor;
				gestionFile* FileXor;
				MesXor =     new XOR();
				FileXor =    new gestionFile();
				FileXor->openFileAndSave(MesXor->EncryptageXor(Message()));
				break;
			case 3:
				system("cls");
				Cesar*       MessEncr;
				XOR*         MessXor;
				gestionFile* FileDouble;
				MessEncr =   new Cesar();
				MessXor =    new XOR();
				FileDouble = new gestionFile();
				FileDouble->openFileAndSave(MessXor->EncryptageXor(MessEncr->Crypt_message(Message())));
				break;
			default:
				Error();
				break;
			}
			break;
		case 2:
			system("cls");
			cout << " # Choisir un niveau de securite 1, 2 ou 3\n**> ";
			cin >> Choice;
			switch (Choice) {
			case 1:
				gestionFile *   FileReadCesar;
				Cesar*          MesDecrCesar;
				FileReadCesar = new gestionFile();
				MesDecrCesar =  new Cesar();
				cout << "> " << MesDecrCesar->Decrypt_message(FileReadCesar->ReadFile()) << endl;
				system("pause");
				break;
			case 2:
				gestionFile * FileReadXor;
				XOR*          MesDecrXor;
				FileReadXor = new gestionFile();
				MesDecrXor =  new XOR();
				cout << "> " << MesDecrXor->EncryptageXor(FileReadXor->ReadFile()) << endl;
				system("pause");
				break;
			case 3:
				Cesar *			 MessDecr;
				XOR*			 MessXorDecr;
				gestionFile*	 FileDoubleRead;
				MessDecr =		 new Cesar();
				MessXorDecr =	 new XOR();
				FileDoubleRead = new gestionFile();
				cout << "> " << MessDecr->Decrypt_message(MessXorDecr->EncryptageXor(FileDoubleRead->ReadFile())) << endl;
				system("pause");
				break;
			default:
				Error();
				break;
			}
			// ----------------------------------------------------------------- Decrytpage
			
			break;
		default:
			Error();
			break;
		}
	}
}