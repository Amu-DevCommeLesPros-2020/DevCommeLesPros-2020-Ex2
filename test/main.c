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


    // Test chiffre_Cesar.
    strcpy(clair, "a");
    TEST_STR(chiffre_Cesar(clair, 'a'), "a");
    strcpy(clair, "a");
    TEST_STR(chiffre_Cesar(clair, 'c'), "c");
    strcpy(clair, "a");
    TEST_STR(chiffre_Cesar(clair, 'z'), "z");
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST_STR(chiffre_Cesar(clair, 'a'), "abcdefghijklmnopqrstuvwxyz");
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST_STR(chiffre_Cesar(clair, 'c'), "cdefghijklmnopqrstuvwxyzab");
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST_STR(chiffre_Cesar(clair, 'z'), "zabcdefghijklmnopqrstuvwxy");
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST_STR(chiffre_Cesar(clair, 'a'), "aBcdEFghiJKLmnopQRSTuVwXyZ");
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST_STR(chiffre_Cesar(clair, 'c'), "cDefGHijkLMNopqrSTUVwXyZaB");
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST_STR(chiffre_Cesar(clair, 'z'), "zAbcDEfghIJKlmnoPQRStUvWxY");
    strcpy(clair, "A, a.");
    TEST_STR(chiffre_Cesar(clair, 'a'), "A, a.");
    strcpy(clair, "A, a.");
    TEST_STR(chiffre_Cesar(clair, 'c'), "C, c.");
    strcpy(clair, "A, a.");
    TEST_STR(chiffre_Cesar(clair, 'z'), "Z, z.");
    strcpy(clair, "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    TEST_STR(chiffre_Cesar(clair, 'a'), "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    strcpy(clair, "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    TEST_STR(chiffre_Cesar(clair, 'c'), "Lg nckuug ogu dkgpu à oc uqgwt. Pqp à oqp pgxgw. Lcocku ugtc rcaé ng eqorvg fw vcknngwt. Tkgp cwz rcwxtgu.");
    strcpy(clair, "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    TEST_STR(chiffre_Cesar(clair, 'z'), "Id kzhrrd ldr ahdmr à lz rndtq. Mnm à lnm mdudt. Izlzhr rdqz ozxé kd bnlosd ct szhkkdtq. Qhdm ztw oztuqdr.");

    // Tests dechiffre_Cesar.
    strcpy(clair, "a");
    TEST_STR(dechiffre_Cesar(clair, 'a'), "a");
    strcpy(clair, "c");
    TEST_STR(dechiffre_Cesar(clair, 'c'), "a");
    strcpy(clair, "z");
    TEST_STR(dechiffre_Cesar(clair, 'z'), "a");
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST_STR(dechiffre_Cesar(clair, 'a'), "abcdefghijklmnopqrstuvwxyz");
    strcpy(clair, "cdefghijklmnopqrstuvwxyzab");
    TEST_STR(dechiffre_Cesar(clair, 'c'), "abcdefghijklmnopqrstuvwxyz");
    strcpy(clair, "zabcdefghijklmnopqrstuvwxy");
    TEST_STR(dechiffre_Cesar(clair, 'z'), "abcdefghijklmnopqrstuvwxyz");
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST_STR(dechiffre_Cesar(clair, 'a'), "aBcdEFghiJKLmnopQRSTuVwXyZ");
    strcpy(clair, "cDefGHijkLMNopqrSTUVwXyZaB");
    TEST_STR(dechiffre_Cesar(clair, 'c'), "aBcdEFghiJKLmnopQRSTuVwXyZ");
    strcpy(clair, "zAbcDEfghIJKlmnoPQRStUvWxY");
    TEST_STR(dechiffre_Cesar(clair, 'z'), "aBcdEFghiJKLmnopQRSTuVwXyZ");
    strcpy(clair, "A, a.");
    TEST_STR(dechiffre_Cesar(clair, 'a'), "A, a.");
    strcpy(clair, "C, c.");
    TEST_STR(dechiffre_Cesar(clair, 'c'), "A, a.");
    strcpy(clair, "Z, z.");
    TEST_STR(dechiffre_Cesar(clair, 'z'), "A, a.");
    strcpy(clair, "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    TEST_STR(dechiffre_Cesar(clair, 'a'), "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    strcpy(clair, "Lg nckuug ogu dkgpu à oc uqgwt. Pqp à oqp pgxgw. Lcocku ugtc rcaé ng eqorvg fw vcknngwt. Tkgp cwz rcwxtgu.");
    TEST_STR(dechiffre_Cesar(clair, 'c'), "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    strcpy(clair, "Id kzhrrd ldr ahdmr à lz rndtq. Mnm à lnm mdudt. Izlzhr rdqz ozxé kd bnlosd ct szhkkdtq. Qhdm ztw oztuqdr.");
    TEST_STR(dechiffre_Cesar(clair, 'z'), "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");


    return resultat;

}
