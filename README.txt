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
*  Nom du fichier :  README.txt                                               *
*                                                                             *
******************************************************************************/


liens vers git : https://gitlab.info.iut-tlse3.fr/lns4403a/mini-projet-c.git


-Description de l'algorithme de Cesar: 
L'algorithme de César décale chaque lettre d'un message d'un nombre fixe de positions dans l'alphabet.
Par exemple, avec un décalage de 3, A devient D, B devient E, etc. Le déchiffrement inverse ce décalage.




-Les sources qu'on a utilisé : 
https://www.asciitable.com/
https://fr.wikipedia.org/wiki/Chiffrement_par_d%C3%A9calage




-Explications : 
-On a utilisé le type wchar_t pour pouvoir créer les fonctions verificationAlphanumMessage et ConvertirAccents
pour pouvoir convertir les accents dans les messages.
-Le programme comprend aussi les espaces dans les messages à crypter mais les espaces ne sont pas cryptés.
-Le programme s'arrête lorsqu'il y a une mauvaise saisie (pas de boucle while pour cela).
-On a également crée une fonction sauvegarderDansUnFichier qui stocke le resultat à la fin du code dans le fichier resultat.txt
-On a utilisé aussi la fonction clear_stdin pour éviter les problèmes causés par des entrées inattendues dans le buffer 
et aussi pour pouvoir contenir des espaces lorsqu'on chiffre/déchiffre un message.
-Les lettres majiscules et miniscules sont autorisés mais pas les chiffres.





-Les fonctions qui se trouvent dans le fichier Cezar.c :
// Procedure "clear_stdin"
// Vide le buffer d'entrée standard (stdin)
// Paramètres : Aucun
// Retour : Aucun
void clear_stdin(void);

// Procedure "verificationAlphanumMessage"
// Vérifie si le message ne contient que des caractères alphanumériques
// Paramètres : un pointeur vers un tableau de wchar_t qui constitue le message
// Retour : true si le message est alphanumérique, false sinon
bool verificationAlphanumMessage(wchar_t *Message);

// Procedure "ChiffreLeMessage"
// Chiffre un message en utilisant l'algorithme de César
// Paramètres : un pointeur vers un tableau de wchar_t qui constitue le message, et un entier représentant la clé de chiffrement 
// Retour : Aucun
void ChiffreLeMessage(wchar_t *message, int cle);

// Procedure "DechiffreLeMessage"
// Déchiffre un message chiffré avec l'algorithme de César
// Paramètres : un pointeur vers un tableau de wchar_t qui constitue le message, et un entier représentant la clé de déchiffrement
// Retour : Aucun
void DechiffreLeMessage(wchar_t *message, int cle);

// Procedure "ConvertirAccents"
// Convertit les caractères accentués en leurs équivalents non accentués
// Paramètres : un pointeur vers un tableau de wchar_t qui constitue le message
// Retour : Aucun
void ConvertirAccents(wchar_t *message);

// Procedure "sauvegarderDansUnFichier"
// Permet de stocker le message chiffré/déchiffré dans un fichier resultat.txt
// Paramètres : un tableau de wchar_t qui constitue le message
// Retour : Aucun
void sauvegarderDansUnFichier(wchar_t message[]);


