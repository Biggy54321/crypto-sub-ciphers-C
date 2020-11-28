#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "./caesar.h"

/* Number of alphabets */
#define NO_ALPHA_CHARS (26u)

/**
 * @brief Returns #a mod #b
 *
 * @param[in] a Dividend
 * @param[in] b Divisor
 * @return #a mod #b
 */
static int mod(int a, int b) {

    if (a < 0) {                /* If first number is negative */

        return (b - (-a) % b) % b;
    } else {                    /* If first number is positive */

        return a % b;
    }
}

/**
 * @brief Encrypts the #msg using the #key and returns
 *        the pointer to the encrypted string
 *
 * @param[in] msg Plain text
 * @param[in] key Key
 * @return Cipher text
 */
char *caesar_encrypt(char *msg, int key) {

    int i;

    /* Create a string */
    char *enc_msg = (char *)malloc(strlen(msg) * sizeof(char));

    /* Create a plaintext to ciphertext mapping table */
    int pt_to_ct_map[NO_ALPHA_CHARS];

    /* Initialize the mapping table */
    for (int i = 0; i < NO_ALPHA_CHARS; i++) {

        pt_to_ct_map[i] = mod(i + key, NO_ALPHA_CHARS);
    }

    /* Encrypt char by char */
    for (i = 0; msg[i] != '\0'; i++) {

        if (isupper(msg[i])) {  /* For upper case letters */

            enc_msg[i] = 'A' + pt_to_ct_map[msg[i] - 'A'];
        } else if (islower(msg[i])) { /* For lower case letters */

            enc_msg[i] = 'a' + pt_to_ct_map[msg[i] - 'a'];
        } else {                /* For rest characters */

            enc_msg[i] = msg[i];
        }
    }

    /* Terminate the string */
    enc_msg[i] = '\0';

    return enc_msg;
}

/**
 * @brief Decrypts the #msg using the #key and returns
 *        the pointer to the decrypted string
 *
 * @param[in] msg Cipher text
 * @param[in] key Key
 * @return Plain text
 */
char *caesar_decrypt(char *msg, int key) {

    int i;

    /* Create a string */
    char *dec_msg = (char *)malloc(strlen(msg) * sizeof(char));

    /* Create a ciphertext to plaintext mapping table */
    char ct_to_pt_map[NO_ALPHA_CHARS];

    /* Initialize the mapping table */
    for (int i = 0; i < NO_ALPHA_CHARS; i++) {

        ct_to_pt_map[i] = mod(i - key, NO_ALPHA_CHARS);
    }

    /* Decrypt char by char */
    for (i = 0; msg[i] != '\0'; i++) {

        if (isupper(msg[i])) {  /* For upper case letters */

            dec_msg[i] = 'A' + ct_to_pt_map[msg[i] - 'A'];
        } else if (islower(msg[i])) { /* For lower case letters */

            dec_msg[i] = 'a' + ct_to_pt_map[msg[i] - 'a'];
        } else {                /* For rest characters */

            dec_msg[i] = msg[i];
        }
    }

    /* Terminate the string */
    dec_msg[i] = '\0';

    return dec_msg;
}

/**
 * @brief Prints all the possible plaintexts of the
 *        given ciphertext #msg on the standard output
 *
 * @param[in] msg Cipher text
 */
void caesar_brute_force_decrypt(char *msg) {

    char *dec_msg;

    /* For all the possible keys */
    for (int key = 0; key < NO_ALPHA_CHARS; key++) {

        /* Decrypt the message */
        dec_msg = caesar_decrypt(msg, key);

        /* Print the plain text */
        printf("For key = %d (mod %d):\n%s\n", key, NO_ALPHA_CHARS, dec_msg);

        free(dec_msg);
    }
}
