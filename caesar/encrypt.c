#include <stdio.h>
#include <stdlib.h>
#include "./caesar.h"

int main(int argc, char *argv[]) {

    int key;
    char *msg;
    char *enc_msg;

    /* Check if the command line argument is given */
    if (argc < 2) {

        fprintf(stderr, "Enter the key as a command line argument\n");
        return -1;
    }

    /* Convert the string to integer */
    key = atoi(argv[1]);

    /* Get the input string */
    scanf("%m[^\n]", &msg);

    /* Encrypt the input string */
    enc_msg = caesar_encrypt(msg, key);

    /* Print the encrypted string */
    /* printf("%s\n", enc_msg); */

    return 0;
}
