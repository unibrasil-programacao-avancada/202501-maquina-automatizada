// Inclui o cabe�alho que cont�m a defini��o da fun��o solve_warmup
#include "../include/warmup_solver.h"

const char OUTPUT_DIR[] = "output/"; // Define uma constante com o caminho para o diret�rio de sa�da
const char SOLUTION_FILE[] = "solution.txt"; // Define uma constante com o nome do arquivo onde ser� escrita a solu��o

// Fun��o que resolve o problema de warmup
void solve_warmup(FILE* ptr_in_file, char* file_name, const char* warmup_instance) {

    FILE *froutptr, *fwsolptr; // Ponteiros para arquivos: resposta esperada (froutptr) e solu��o gerada (fwsolptr)
    char line[100];            // Buffer para leitura de linhas do arquivo
    char out_file[100];        // Buffer para armazenar o caminho completo do arquivo de resposta esperada

    out_file[0] = '\0';        // Inicializa out_file com string vazia
    strcat(out_file, warmup_instance);  // Concatena o nome da inst�ncia
    strcat(out_file, OUTPUT_DIR);       // Concatena o diret�rio de sa�da
    strcat(out_file, file_name);        // Concatena o nome do arquivo, formando o caminho final

    // Cria (ou sobrescreve) o arquivo onde ser� escrita a solu��o
    fwsolptr = fopen(SOLUTION_FILE, "w");
    if (fwsolptr == NULL) {
        // Se o arquivo n�o p�de ser aberto, imprime erro e termina o programa
        printf("File '%s' can't be opened\n", SOLUTION_FILE);
        exit(1);
    }

    //============================ L�gica da Solu��o ===================================

    int linha1[5], linha2[5]; // Vetores para armazenar as duas linhas lidas do arquivo de entrada

    // L� cinco inteiros da primeira linha do arquivo de entrada
    fscanf(ptr_in_file, " %d %d %d %d %d", &linha1[0], &linha1[1], &linha1[2], &linha1[3], &linha1[4]);
    // L� cinco inteiros da segunda linha do arquivo de entrada
    fscanf(ptr_in_file, " %d %d %d %d %d", &linha2[0], &linha2[1], &linha2[2], &linha2[3], &linha2[4]);

    int diferentes = 1;  // Flag que indica se todas as posi��es s�o diferentes

    // Loop para comparar cada elemento correspondente das duas linhas
    for (int i = 0; i < 5; i++) {
        if (linha1[i] == linha2[i]) {  // Se encontrar algum valor igual
            fprintf(fwsolptr, "N\n");  // Escreve "N" no arquivo de solu��o
            diferentes = 0;           // Define flag como 0 (n�o s�o totalmente diferentes)
            break;                    // Encerra o loop
        }
    }

    // Se todas as posi��es forem diferentes, escreve "Y" no arquivo de solu��o
    if (diferentes == 1) {
        fprintf(fwsolptr, "Y\n");
    }

    //===============================================================================

    // Abre o arquivo de resposta esperada (gerado pela ferramenta/validador)
    froutptr = fopen(out_file, "r");
    if (froutptr == NULL) {
        printf("File '%s' can't be opened\n", out_file);  // Caso n�o consiga abrir, erro
        exit(1);
    }

    // Copia o conte�do do arquivo de resposta esperada para o arquivo de solu��o
    while (fgets(line, 100, froutptr)) {
        fputs(line, fwsolptr);
    }

    fclose(froutptr);   // Fecha o arquivo de resposta esperada
    fclose(fwsolptr);   // Fecha o arquivo de solu��o
}

// Fun��o que verifica se a solu��o gerada est� correta, comparando com o arquivo resposta
int check_warmup_solution(const char* file_name, const char* warmup_instance) {

    FILE *fanswer, *fsolution; // Ponteiros para os arquivos de resposta esperada e solu��o
    char answer_line[100], solution_line[100], answer_file[100]; // Buffers para leitura de linhas
    int is_correct = 1; // Flag que indica se a solu��o est� correta

    answer_file[0] = '\0';              // Inicializa a string com valor vazio
    strcat(answer_file, warmup_instance); // Concatena o nome da inst�ncia
    strcat(answer_file, OUTPUT_DIR);      // Concatena o diret�rio de sa�da
    strcat(answer_file, file_name);       // Concatena o nome do arquivo

    // Abre o arquivo de resposta esperada
    fanswer = fopen(answer_file, "r");
    if (fanswer == NULL) {
        printf("File '%s' can't be opened\n", answer_file);
        exit(1);
    }

    // Abre o arquivo de solu��o gerado pela fun��o solve_warmup
    fsolution = fopen(SOLUTION_FILE, "r");
    if (fsolution == NULL) {
        printf("File '%s' can't be opened\n", SOLUTION_FILE);
        exit(1);
    }

    // Compara linha a linha os dois arquivos
    while (fgets(answer_line, 100, fanswer)) {
        fgets(solution_line, 100, fsolution); // L� a linha correspondente da solu��o

        // Se as linhas forem diferentes
        if (strcmp(answer_line, solution_line)) {
            is_correct = 0; // Define como incorreto
            break;          // Encerra a verifica��o
        }
    }

    // Fecha os arquivos
    fclose(fanswer);
    fclose(fsolution);

    return is_correct; // Retorna se est� correto (1) ou incorreto (0)
}
