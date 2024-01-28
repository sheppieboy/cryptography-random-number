#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEYSIZE 16

//function to generate the key
void generate_key(unsigned long timestamp, char key[KEYSIZE]) {
    srand((unsigned int)timestamp);
    for (int i = 0; i < KEYSIZE; i++) {
        key[i] = rand() % 256;
    }
}

//a function to write a key to the a text file to be used later to crack the key
void write_key_to_file(const char key[KEYSIZE]) {
    FILE *file = fopen("all_possible_keys.txt", "a");
    if (file != NULL) {
        for (int i = 0; i < KEYSIZE; i++) {
            fprintf(file, "%.2x", (unsigned char)key[i]);
        }
        fprintf(file, "\n");
        fclose(file);
    } else {
        perror("Error opening file");
    }
}

//main function generate keys and write them to the file
int main() {
    unsigned long start_timestamp = 1705370929- 60 * 60 * 2; //two hours 
    unsigned long end_timestamp = 1705370929;

    char key[KEYSIZE];

    //loop through all possible timestamp and generate a key then write to the file 
    for (unsigned long timestamp = start_timestamp; timestamp < end_timestamp; timestamp++) {
        generate_key(timestamp, key);
        write_key_to_file(key);
    }

    return 0;
}

