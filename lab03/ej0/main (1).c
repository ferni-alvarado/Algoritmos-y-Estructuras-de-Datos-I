#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 1000


char *parse_filepath(int argc, char *argv[]) {
    char *result = NULL;
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size)
    {
    FILE* puntero;
    puntero = fopen(path, "r");
    if (!puntero){
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    unsigned int p;
    int i = 0;
    while(i < max_size && !feof(puntero)){
        int lector;
        char lec;
        fscanf(puntero, "%d %c\n", &lector, &lec );
        indexes[i] = lector;
        letters[i] = lec;
        ++i;
        }
    p = length(indexes) + length(letters);
    fclose(puntero);
    return p;
}




int main(int argc, char *argv[]) {
    char *filepath = NULL;
    filepath = parse_filepath(argc, argv);

    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length = 0;
    length = data_from_file(filepath, indexes, letters, MAX_SIZE); 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    
    /* -- completar -- */

    dump(sorted, length);

    return EXIT_SUCCESS;
}

