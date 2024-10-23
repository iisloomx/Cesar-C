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
*  Nom du fichier :  Cezar.c                                                  *
*                                                                             *
******************************************************************************/





#include "Cezar.h"
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <stdio.h>





void clear_stdin(void) {
    wchar_t ch;
    while ((ch = getwchar()) != L'\n' && ch != WEOF); 
}



bool verificationAlphanumMessage(wchar_t *Message) {
    wchar_t SpecialCharactersWIDE[] = {
        L'!', L'"', L'#', L'$', L'%', L'&', L'\'',
        L'(', L')', L'*', L'+', L',', L'-', L'.', L'/',
        L':', L';', L'<', L'=', L'>', L'?', L'@',
        L'[', L'\\', L']', L'^', L'_', L'`',
        L'{', L'|', L'}', L'~'
    };
    int specialCharsCount = sizeof(SpecialCharactersWIDE) / sizeof(SpecialCharactersWIDE[0]);

    for (int i = 0; i < wcslen(Message); i++) {
        for (int k = 0; k < specialCharsCount; k++) {
            if (Message[i] == SpecialCharactersWIDE[k]) {
                return false; 
            }
        }
    }
    return true; 
}



void ChiffreLeMessage(wchar_t *message, int cle) {
    int i = 0;
    while (message[i] != L'\0') {
        if (iswalpha(message[i])) {
            wchar_t base = iswlower(message[i]) ? L'a' : L'A';
            int adjustedCle = (cle % 26 + 26) % 26;
            message[i] = base + (message[i] - base + adjustedCle) % 26;
        }
        i++;
    }
}




void DechiffreLeMessage(wchar_t *message, int cle) {
    int i = 0;
    while (message[i] != L'\0') {
        if (iswalpha(message[i])) {
            wchar_t base = iswlower(message[i]) ? L'a' : L'A';
            int adjustedCle = (cle % 26 + 26) % 26; 
            message[i] = base + (message[i] - base - adjustedCle + 26) % 26;
        }
        i++;
    }
}





void ConvertirAccents(wchar_t *message) {
    const wchar_t Accented[] = {
        L'À', L'à', L'Â', L'â', L'Ä', L'ä', L'Ç', L'ç', L'É', L'é', L'È', L'è', L'Ê', L'ê', L'Ë', L'ë', 
        L'Î', L'î', L'Ï', L'ï', L'Ô', L'ô', L'Œ', L'œ', L'Ù', L'ù', L'Û', L'û', L'Ü', L'ü', L'Æ', L'æ', L'Ÿ', L'ÿ'
    };
    const wchar_t NonAccented[] = {
        L'A', L'a', L'A', L'a', L'A', L'a', L'C', L'c', L'E', L'e', L'E', L'e', L'E', L'e', L'E', L'e',
        L'I', L'i', L'I', L'i', L'O', L'o', L'O', L'e', L'U', L'u', L'U', L'u', L'U', L'u', L'A', L'a', L'Y', L'y'
    };
    size_t numAccents = sizeof(Accented) / sizeof(wchar_t);

    for (int i = 0; message[i] != L'\0'; i++) {
        for (size_t j = 0; j < numAccents; j++) {
            if (message[i] == Accented[j]) {
                message[i] = NonAccented[j];
                wprintf(L"Remplacement %lc avec %lc\n", Accented[j], NonAccented[j]);
                break;
            }
        }
    }
}



void sauvegarderDansUnFichier(wchar_t message[]) {
    setlocale(LC_ALL, "");
    FILE *fichier = fopen("resultat.txt", "w, ccs=UTF-8");
    if (fichier == NULL) {
        wprintf(L"Erreur lors de l'ouverture du fichier\n");
        return;
    }
    fputws(message, fichier);
    fclose(fichier);
    wprintf(L"Le message a été sauvegardé dans le fichier resultat.txt\n");
}