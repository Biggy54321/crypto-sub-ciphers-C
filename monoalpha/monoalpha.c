#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "./monoalpha.h"

/**
 * @brief Checks if the input key table is valid
 *
 * @param[in] key Key table
 * @return 1 if valid
 * @return 0 if not valid
 */
static int monoalpha_is_valid_key(int *key) {

    int occurred[NO_ALPHA_CHARS];

    /* Set all zeros in occurred array */
    memset(occurred, 0, NO_ALPHA_CHARS * sizeof(int));

    /**
     * Check if the key array contains numbers
     * which are modulo 26 and each element
     * occurs only once
     */
    for (int i = 0; i < NO_ALPHA_CHARS; i++) {

        if ((key[i] < 0) ||
            (key[i] >= NO_ALPHA_CHARS)) {

            return 0;
        }

        if (occurred[key[i]]) {

            return 0;
        }

        occurred[key[i]] = 1;
    }

    return 1;
}

/**
 *@brief Encrypts the #msg using the #key table
 *       and returns the encrypted string
 *
 * @param[in] msg Plain text
 * @param[in] key Key table
 * @return Cipher text
 */
char *monoalpha_encrypt(char *msg, int *key) {

    /* If the key is not valid */
    if (!monoalpha_is_valid_key(key)) {
        return NULL;
    }

    /* Create an encrypted string */
    char *enc_msg = (char *)malloc(strlen(msg) * sizeof(char));

    int i;

    /* Encrypt char by char */
    for (i = 0; msg[i] != '\0'; i++) {

        if (isupper(msg[i])) {        /* For upper case letter */

            enc_msg[i] = 'A' + key[msg[i] - 'A'];
        } else if (islower(msg[i])) {          /* For lower case letter */

            enc_msg[i] = 'a' + key[msg[i] - 'a'];
        } else {                /* For rest characters */

            enc_msg[i] = msg[i];
        }
    }

    enc_msg[i] = '\0';

    return enc_msg;
}

/**
 *@brief Decrypts the #msg using the #key table
 *       and returns the decrypted string
 *
 * @param[in] msg Cipher text
 * @param[in] key Key table
 * @return Plain text
 */
char *monoalpha_decrypt(char *msg, int *key) {

    /* If the key is not valid */
    if (!monoalpha_is_valid_key(key)) {
        return NULL;
    }

    /* Create a decrypted string */
    char *dec_msg = (char *)malloc(strlen(msg) * sizeof(char));

    int i;

    /* Create an inverted key table */
    int ivt_key[NO_ALPHA_CHARS];

    /* Initialize the inverted key table */
    for (int i = 0; i < NO_ALPHA_CHARS; i++) {

        ivt_key[key[i]] = i;
    }

    /* Decrypt char by char */
    for (i = 0; msg[i] != '\0'; i++) {

        if (isupper(msg[i])) {        /* For upper case letter */

            dec_msg[i] = 'A' + ivt_key[msg[i] - 'A'];
        } else if (islower(msg[i])) {          /* For lower case letter */

            dec_msg[i] = 'a' + ivt_key[msg[i] - 'a'];
        } else {                /* For rest characters */

            dec_msg[i] = msg[i];
        }
    }

    dec_msg[i] = '\0';

    return dec_msg;
}

/**
 * @brief Generate all the permutations of the key
 *        table of the monoalphabetic cipher and
 *        decrypt for each key permutation
 *
 * @param[in] msg Cipher text
 * @param[in] key Key table
 * @param[in] chosen Chosen array
 * @param[in] idx Current index in the key table for
 *                which the element is to be selected
 */
static void generate_key_permutations(
    char *msg,
    int *key,
    int *chosen,
    int idx) {

    /* If the current permutation is complete */
    if (idx == NO_ALPHA_CHARS) {

        char *dec_msg;

        /* Decrypt the message using the current key */
        dec_msg = monoalpha_decrypt(msg, key);

        /* Print the plaintext message */
        printf("%s\n\n", dec_msg);

        free(dec_msg);

        return;
    }

    /* Fill the current index with non-chosen characters */
    for (int i = 0; i < NO_ALPHA_CHARS; i++) {

        /* Skip the number if already taken in the permutation */
        if (chosen[i]) continue;

        /* Mark the current number chosen */
        chosen[i] = 1;

        /* Add it to the key table */
        key[idx] = i;

        /* Set the element for the next key table position */
        generate_key_permutations(msg, key, chosen, idx + 1);

        /* Mark the current element is not chosen */
        chosen[i] = 0;
    }
}

/**
 * @brief Prints all the possible plaintexts of the
 *        given ciphertext #msg on the standard output
 *
 * @param[in] msg Cipher text
 */
char *monoalpha_brute_force_decrypt(char *msg) {

    int key[NO_ALPHA_CHARS];
    int chosen[NO_ALPHA_CHARS];

    /* Set all the numbers as zero */
    memset(chosen, 0, NO_ALPHA_CHARS * sizeof(int));

    /**
     * Perform decryption for every permutation of the
     * key table
     */
    generate_key_permutations(msg, key, chosen, 0);
}
