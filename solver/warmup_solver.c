// Inclui o cabeçalho que contém a definição da função solve_warmup
#include "../include/warmup_solver.h"

const char OUTPUT_DIR[] = "output/"; // Define uma constante com o caminho para o diretório de saída
const char SOLUTION_FILE[] = "solution.txt"; // Define uma constante com o nome do arquivo onde será escrita a solução

// Função que resolve o problema de warmup
void solve_warmup(FILE* ptr_in_file, char* file_name, const char* warmup_instance) {

    FILE *froutptr, *fwsolptr; // Ponteiros para arquivos: resposta esperada (froutptr) e solução gerada (fwsolptr)
    char line[100];            // Buffer para leitura de linhas do arquivo
    char out_file[100];        // Buffer para armazenar o caminho completo do arquivo de resposta esperada

    out_file[0] = '\0';        // Inicializa out_file com string vazia
    strcat(out_file, warmup_instance);  // Concatena o nome da instância
    strcat(out_file, OUTPUT_DIR);       // Concatena o diretório de saída
    strcat(out_file, file_name);        // Concatena o nome do arquivo, formando o caminho final

    // Cria (ou sobrescreve) o arquivo onde será escrita a solução
    fwsolptr = fopen(SOLUTION_FILE, "w");
    if (fwsolptr == NULL) {
        // Se o arquivo não pôde ser aberto, imprime erro e termina o programa
        printf("File '%s' can't be opened\n", SOLUTION_FILE);
        exit(1);
    }

    //============================ Lógica da Solução ===================================

    int linha1[5], linha2[5]; // Vetores para armazenar as duas linhas lidas do arquivo de entrada

    // Lê cinco inteiros da primeira linha do arquivo de entrada
    fscanf(ptr_in_file, " %d %d %d %d %d", &linha1[0], &linha1[1], &linha1[2], &linha1[3], &linha1[4]);
    // Lê cinco inteiros da segunda linha do arquivo de entrada
    fscanf(ptr_in_file, " %d %d %d %d %d", &linha2[0], &linha2[1], &linha2[2], &linha2[3], &linha2[4]);

    int diferentes = 1;  // Flag que indica se todas as posições são diferentes

    // Loop para comparar cada elemento correspondente das duas linhas
    for (int i = 0; i < 5; i++) {
        if (linha1[i] == linha2[i]) {  // Se encontrar algum valor igual
            fprintf(fwsolptr, "N\n");  // Escreve "N" no arquivo de solução
            diferentes = 0;           // Define flag como 0 (não são totalmente diferentes)
            break;                    // Encerra o loop
        }
    }

    // Se todas as posições forem diferentes, escreve "Y" no arquivo de solução
    if (diferentes == 1) {
        fprintf(fwsolptr, "Y\n");
    }

    //===============================================================================

    // Abre o arquivo de resposta esperada (gerado pela ferramenta/validador)
    froutptr = fopen(out_file, "r");
    if (froutptr == NULL) {
        printf("File '%s' can't be opened\n", out_file);  // Caso não consiga abrir, erro
        exit(1);
    }

    // Copia o conteúdo do arquivo de resposta esperada para o arquivo de solução
    while (fgets(line, 100, froutptr)) {
        fputs(line, fwsolptr);
    }

    fclose(froutptr);   // Fecha o arquivo de resposta esperada
    fclose(fwsolptr);   // Fecha o arquivo de solução
}

// Função que verifica se a solução gerada está correta, comparando com o arquivo resposta
int check_warmup_solution(const char* file_name, const char* warmup_instance) {

    FILE *fanswer, *fsolution; // Ponteiros para os arquivos de resposta esperada e solução
    char answer_line[100], solution_line[100], answer_file[100]; // Buffers para leitura de linhas
    int is_correct = 1; // Flag que indica se a solução está correta

    answer_file[0] = '\0';              // Inicializa a string com valor vazio
    strcat(answer_file, warmup_instance); // Concatena o nome da instância
    strcat(answer_file, OUTPUT_DIR);      // Concatena o diretório de saída
    strcat(answer_file, file_name);       // Concatena o nome do arquivo

    // Abre o arquivo de resposta esperada
    fanswer = fopen(answer_file, "r");
    if (fanswer == NULL) {
        printf("File '%s' can't be opened\n", answer_file);
        exit(1);
    }

    // Abre o arquivo de solução gerado pela função solve_warmup
    fsolution = fopen(SOLUTION_FILE, "r");
    if (fsolution == NULL) {
        printf("File '%s' can't be opened\n", SOLUTION_FILE);
        exit(1);
    }

    // Compara linha a linha os dois arquivos
    while (fgets(answer_line, 100, fanswer)) {
        fgets(solution_line, 100, fsolution); // Lê a linha correspondente da solução

        // Se as linhas forem diferentes
        if (strcmp(answer_line, solution_line)) {
            is_correct = 0; // Define como incorreto
            break;          // Encerra a verificação
        }
    }

    // Fecha os arquivos
    fclose(fanswer);
    fclose(fsolution);

    return is_correct; // Retorna se está correto (1) ou incorreto (0)
}
