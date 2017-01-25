#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "AES.h"

using namespace std;

int copiefichier(char* srce, char* dest) { 	// copie le fichier srce dans dest
						// renvoie 1 si ok, 0 sinon
	cout << "\t --- Cipher AES ---" << endl;
	cout << "Ouverture du fichier d'entree: " << srce << "\n" ;
	ifstream fi(srce, ios::in|ios::binary);

     	if (!fi)  {
		cout << "PB Ouverture fichier source " << srce << "\n" ;
		return 0;        // srce impossible a lire
	}

	cout << "Ouverture du fichier de sortie: " << dest << "\n" ;
     	ofstream fo(dest, ios::out|ios::binary);

     	if (!fo) {
		cout << "PB Ouverture fichier destination " << dest << "\n" ;
	return 0;
	}

	

     	unsigned char bloc[16];
     	char tampon;
     	int i=0; 
     	int j;
	unsigned char k[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
    	unsigned char *output = new unsigned char[16];
    	
	AES *aes;
    	aes = new AES(k);
	


     	while ( fo && fi.get(tampon) ) {
		// chargement du bloc
		bloc[i++]=tampon;
		if (i==16) {
			// crypto du bloc
			aes->SetInput(bloc);
    			aes->InvCipher();
			i=0;
			// ecriture dans fo
			for (j=0;j<16;j++)
				fo.put(bloc[j]);		
		}
	}
     	return fo.good() && fi.eof();
}

int main(int argc, char** argv){
	copiefichier(argv[1], argv[2]);
	return 0;

 };

