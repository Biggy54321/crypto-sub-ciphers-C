#include <stdio.h>
#include <stdlib.h>
#include "./monoalpha.h"

int main(int argc, char *argv[]) {

    char *msg;

    /* Get the ciphertext message */
    scanf("%m[^\n]", &msg);

    /* Perform a brute force attack */
    monoalpha_brute_force_decrypt(msg);

    return 0;
}
