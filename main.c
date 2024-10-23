/******************************************************************************
*  ASR => 4R2.04                                                               *
*******************************************************************************
*                                                                             *
*  N° de Sujet : Sujet 3                                                      *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé :    Chiffrement de messages                                      *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : AL-NAAIMI Salim     Groupe A                                 *
*                                                                             *
*  Nom-prénom2 : Tsinjo Mirantsoa RANDRIANARISON RATSIANDAVANA    Groupe A    *
*                                                                             *
* 				                                                              *
*                                                                             *
*				                                                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier :  main.c                                                   *
*                                                                             *
******************************************************************************/



#include "Cezar.h"
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, ""); 

    wchar_t message[1024];
    int key;
    wchar_t input[256];
    wchar_t option[10];

    // Entrer le message à crypter
    wprintf(L"Veuillez entrer votre message à crypter : ");
    if (!fgetws(message, 1024, stdin)) {
        wprintf(L"Échec de la lecture de l'entrée.\n");
        return 1;
    }

    size_t len = wcslen(message);
    if (len > 0 && message[len - 1] == L'\n') {
        message[len - 1] = L'\0'; // Effacer la nouvelle ligne
    }

    ConvertirAccents(message); 

    if (!verificationAlphanumMessage(message)) {
        wprintf(L"Le message contient des caractères spéciaux ou non alphanumériques.\n");
        return 1;
    }

    // Entrer la clé de chiffrement
    bool cle_valide = false;
    do {
        wprintf(L"Entrez la clé de chiffrement (un entier entre 1 et 25) : ");
        if (!fgetws(input, 256, stdin)) {
            wprintf(L"Échec de la lecture de l'entrée.\n");
            return 1;
        }
        input[wcslen(input) - 1] = L'\0';
        wchar_t *fin_ptr;
        key = wcstol(input, &fin_ptr, 10); 
        if (*fin_ptr == L'\0' && key >= 1 && key <= 25) {
            cle_valide = true;
        } else {
            wprintf(L"Clé invalide. Veuillez entrer un nombre entre 1 et 25.\n");
        }
    } while (!cle_valide);

    ChiffreLeMessage(message, key); 
    wprintf(L"Message chiffré : %ls\n", message);

    // Demander si l'utilisateur veut décrypter un message
    wprintf(L"Voulez-vous décrypter un message ? (yes/no) : ");
    if (!fgetws(option, 10, stdin)) {
        wprintf(L"Échec de la lecture de l'entrée.\n");
        return 1;
    }
    option[wcslen(option) - 1] = L'\0'; 

    if (wcscmp(option, L"yes") == 0) {
        wprintf(L"Entrez le message à décrypter : ");
        if (!fgetws(message, 256, stdin)) {
            wprintf(L"Échec de la lecture de l'entrée.\n");
            return 1;
        }
        message[wcslen(message) - 1] = L'\0'; 

        cle_valide = false;
        do {
            wprintf(L"Entrez la clé de décryptage (un entier entre 1 et 25) : ");
            if (!fgetws(input, 256, stdin)) {
                wprintf(L"Échec de la lecture de l'entrée.\n");
                return 1;
            }
            input[wcslen(input) - 1] = L'\0'; 
            wchar_t *fin_ptr;
            key = wcstol(input, &fin_ptr, 10); 
            if (*fin_ptr == L'\0' && key >= 1 && key <= 25) {
                cle_valide = true;
            } else {
                wprintf(L"Clé invalide. Veuillez entrer un nombre entre 1 et 25.\n");
            }
        } while (!cle_valide);

        DechiffreLeMessage(message, key); 
        wprintf(L"Message décrypté : %ls\n", message);
    }
    sauvegarderDansUnFichier(message);

    return 0;
}
