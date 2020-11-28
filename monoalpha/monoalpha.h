#ifndef _MONOALPHA_H_
#define _MONOALPHA_H_

/* Number of alphabets */
#define NO_ALPHA_CHARS (26u)

/* Function to encrypt using monoalphabetic
 * substitution cipher */
char *monoalpha_encrypt(char *msg, int *key);

/* Function to decrypt using monoalphabetic
 * substitution cipher */
char *monoalpha_decrypt(char *msg, int *key);

/* Function to print all the possible plaintexts
 * given the ciphertext */
char *monoalpha_brute_force_decrypt(char *msg);

#endif
