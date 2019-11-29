#include "chiffrage.h"

#include <string.h>

int main()
{
    // Pour chaque test qui échoue, cette variable sera incrémentée de 1.
    // Le but est de la garder à 0.
    int resultat = 0;

#define TEST_STR(a, b) if((a == NULL) || (strcmp(a, b) != 0))    \
                       {                        \
                           resultat += 1;       \
                       }

    char clair[128];
    
    // Tests chiffre_ROT13
    strcpy(clair, "a");
    TEST_STR(chiffre_ROT13(clair), "n");
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST_STR(chiffre_ROT13(clair), "nopqrstuvwxyzabcdefghijklm");
    strcpy(clair, "aA");
    TEST_STR(chiffre_ROT13(clair), "nN");
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST_STR(chiffre_ROT13(clair), "nOpqRStuvWXYzabcDEFGhIjKlM");
    strcpy(clair, "A, a.");
    TEST_STR(chiffre_ROT13(clair), "N, n.");
    strcpy(clair, "Je laisse mes biens à ma soeur ? Non ! À mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    TEST_STR(chiffre_ROT13(clair), "Wr ynvffr zrf ovraf à zn fbrhe ? Aba ! À zba arirh. Wnznvf fren cnlé yr pbzcgr qh gnvyyrhe. Evra nhk cnhierf.");

    // Tests dechiffre_ROT13.
    strcpy(clair, "n");
    TEST_STR(dechiffre_ROT13(clair), "a");
    strcpy(clair, "nopqrstuvwxyzabcdefghijklm");
    TEST_STR(dechiffre_ROT13(clair), "abcdefghijklmnopqrstuvwxyz");
    strcpy(clair, "nOpqRStuvWXYzabcDEFGhIjKlM");
    TEST_STR(dechiffre_ROT13(clair), "aBcdEFghiJKLmnopQRSTuVwXyZ");
    strcpy(clair, "N, n.");
    TEST_STR(dechiffre_ROT13(clair), "A, a.");
    strcpy(clair, "Wr ynvffr zrf ovraf à zn fbrhe ? Aba ! À zba arirh. Wnznvf fren cnlé yr pbzcgr qh gnvyyrhe. Evra nhk cnhierf.");
    TEST_STR(dechiffre_ROT13(clair), "Je laisse mes biens à ma soeur ? Non ! À mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");

    return resultat;

}
