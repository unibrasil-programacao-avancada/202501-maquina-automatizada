#include "../include/warmup_solver.h"

const char OUTPUT_DIR[] = "output/";
const char SOLUTION_FILE[] = "solution.txt";

void solve_warmup(FILE* ptr_in_file, char* file_name, const char* warmup_instance) {

    FILE *froutptr, *fwsolptr;
    char line[100];
    char out_file[100];

    out_file[0] = '\0';
    strcat(out_file, warmup_instance);
    strcat(out_file, OUTPUT_DIR);
    strcat(out_file, file_name);
    
    // Creating solution file
    fwsolptr = fopen(SOLUTION_FILE, "w");
    if (fwsolptr == NULL) {
        printf("File '%s' can't be opened\n", SOLUTION_FILE);
        exit(1);
    }

    //===================================Solucao===================================================================
    int linha1[5], linha2[5];
    fscanf(ptr_in_file, " %d %d %d %d %d", &linha1[0], &linha1[1], &linha1[2], &linha1[3], &linha1[4]);
    fscanf(ptr_in_file, " %d %d %d %d %d", &linha2[0], &linha2[1], &linha2[2], &linha2[3], &linha2[4]);
    bool diferentes = true;
    for (int i = 0; i < 5; i++)
    {
        if (linha1[i] == linha2[i])
        {
            fprintf(fwsolptr, "N\n");
            diferentes = false;
            break;
        }
    }
    if (diferentes)
    {
        fprintf(fwsolptr, "Y\n");
    }
    //=======================================================================================================

    // Opening answer file
    froutptr = fopen(out_file, "r");
    if (froutptr == NULL) {
        printf("File '%s' can't be opened\n", out_file);
        exit(1);
    }

    // Reading from the answer file and writing to the solution file
    while (fgets(line, 100, froutptr)) {
        fputs(line, fwsolptr);
    }

    fclose(froutptr);

    /* *************************************** */

    fclose(fwsolptr);
}

int check_warmup_solution(const char* file_name, const char* warmup_instance) {

    FILE *fanswer, *fsolution;
    char answer_line[100], solution_line[100], answer_file[100];
    int is_correct = 1;

    answer_file[0] = '\0';
    strcat(answer_file, warmup_instance);
    strcat(answer_file, OUTPUT_DIR);
    strcat(answer_file, file_name);

    // Opening answer file
    fanswer = fopen(answer_file, "r");
    if (fanswer == NULL) {
        printf("File '%s' can't be opened\n", answer_file);
        exit(1);
    }

    // Opening solution file
    fsolution = fopen(SOLUTION_FILE, "r");
    if (fsolution == NULL) {
        printf("File '%s' can't be opened\n", SOLUTION_FILE);
        exit(1);
    }

    // Reading from the answer file and comparing with the solution file
    while (fgets(answer_line, 100, fanswer)) {

        fgets(solution_line, 100, fsolution);

        if (strcmp(answer_line, solution_line)) {
            is_correct = 0;
            break;
        }
    }

    fclose(fanswer);
    fclose(fsolution);

    return is_correct;
}