#include <stdio.h>
#include <stdlib.h>
#include "./caesar.h"

int main(int argc, char *argv[]) {

    char *msg;

    /* Get the input string */
    scanf("%m[^\n]", &msg);

    /* Print all the permutations of the deciphered text */
    caesar_brute_force_decrypt(msg);

    return 0;
}
