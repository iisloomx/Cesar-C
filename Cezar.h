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
*  Nom du fichier :  Cezar.h                                                  *
*                                                                             *
******************************************************************************/



#include <wchar.h>
#include <stdbool.h>



bool verificationAlphanumMessage(wchar_t *Message);
void ChiffreLeMessage(wchar_t *message, int cle);
void DechiffreLeMessage(wchar_t *message, int cle);
void ConvertirAccents(wchar_t *message);
void clear_stdin(void);
void sauvegarderDansUnFichier(wchar_t message[]);

