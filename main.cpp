#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "AES.h"

using namespace std;

int main() {

    cout << "\t --- Test AES ---" << endl;

    unsigned char k[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
    unsigned char *output = new unsigned char[16];
    AES *aes;

    aes = new AES(k);

    unsigned char input[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};

    cout <<"\nText before encryption:\n";
	for(int i=0;i<Nk*4;i++)	{
		printf("%02x ",input[i]);
	}
	cout <<"\n\n";

    aes->SetInput(input);
    aes->Cipher();
    output = aes->GetOutput();

    cout << "\nText after encryption:\n";
	for(int i=0;i<Nk*4;i++) {
		printf("%02x ",output[i]);
	}
	cout <<"\n\n";

	for(int i=0;i<Nk*4;i++) {
		input[i] = output[i];
	}
	aes->SetInput(input);
    aes->InvCipher();
    output = aes->GetOutput();

    cout << "\nText after decryption:\n";
	for(int i=0;i<Nk*4;i++)	{
		printf("%02x ",output[i]);
	}
	cout <<"\n\n";

    return 0;
}
