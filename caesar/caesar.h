#ifndef _CAESAR_H_
#define _CAESAR_H_

/* Function to encrypt the msg using a key */
char *caesar_encrypt(char *msg, int key);

/* Function to decrypt the msg using a key */
char *caesar_decrypt(char *msg, int key);

/* Function to print all the permutations of plaintext
 * given ciphertext */
void caesar_brute_force_decrypt(char *msg);

#endif
