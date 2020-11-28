#include <stdio.h>
#include <stdlib.h>
#include "./monoalpha.h"

int main(int argc, char *argv[]) {

    int key[NO_ALPHA_CHARS];
    char *msg;
    char *enc_msg;

    /* Check the command line arguments */
    if (argc < NO_ALPHA_CHARS + 1) {

        fprintf(stderr, "Enter the monoalphabetic cipher table\n");
        return -1;
    }

    /* Get the key table */
    for (int i = 0; i < NO_ALPHA_CHARS; i++) {

        key[i] = atoi(argv[i + 1]);
    }

    /* Get the plaintext message */
    scanf("%m[^\n]", &msg);

    /* Encrypt the message */
    enc_msg = monoalpha_encrypt(msg, key);

    /* Print the encrypted message */
    printf("%s\n", enc_msg);

    return 0;
}
