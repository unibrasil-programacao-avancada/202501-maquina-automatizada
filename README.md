# 202501 - Máquina de Verificação Automatizada

## Descrição do Projeto
Este é o projeto para a solução do problema de verificação de compatibilidade entre conectores elétricos para a Internet Computer Parts Company (ICPC). A máquina de verificação automatizada (ACM) é responsável por garantir que os conectores enviados aos clientes sejam compatíveis, evitando erros de embalagem e reduzindo as devoluções.

## Problema
A ICPC vende conectores elétricos com cinco pontos de conexão numerados de 1 a 5. Cada ponto pode ser um "plugue" ou uma "tomada", representados por 1 (plugue) e 0 (tomada). Dois conectores são compatíveis se, para cada ponto de conexão com o mesmo rótulo, um ponto é um plugue e o outro ponto é uma tomada.

## Entrada
A entrada consiste em duas linhas:
- A primeira linha contém cinco inteiros `Xi` (0 ≤ `Xi` ≤ 1 para `i = 1,2, ..., 5`), representando os pontos de conexão do primeiro conector.
- A segunda linha contém cinco inteiros `Yi` (0 ≤ `Yi` ≤ 1 para `i = 1,2, ..., 5`), representando os pontos de conexão do segundo conector.
- Cada valor 0 representa uma tomada e 1 representa um plugue.

## Saída
O programa deve retornar uma string representando se os conectores são compatíveis ou não:
- Se forem compatíveis, retorne a letra maiúscula **"Y"**.
- Caso contrário, retorne a letra maiúscula **"N"**.

## Exemplo de Entrada e Saída

### Exemplo 1
**Entrada:**  
```
1 0 1 0 1
0 1 0 1 0
```
**Saída:**  
```
Y
```

### Exemplo 2
**Entrada:**  
```
1 1 0 0 1
0 1 0 1 1
```
**Saída:**  
```
N
```

## Testes
O projeto inclui 52 testes automatizados:
- **50 Sucessos** (casos em que a verificação foi correta).
- **2 Falhas** (casos em que a verificação apresentou erro).

## Tecnologias Utilizadas
- Linguagem de programação: C
- Ambiente de desenvolvimento: CodeBlocks
- Metodologia de testes: Testes unitários automatizados
  
