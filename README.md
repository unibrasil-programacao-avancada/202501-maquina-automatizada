# 202501-maquina-automatizada

Este é o projeto para a solução do problema de verificação de compatibilidade entre conectores elétricos para a Internet Computer Parts Company (ICPC). A máquina de verificação automatizada (ACM) é responsável por garantir que os conectores enviados aos clientes sejam compatíveis, evitando erros de embalagem e reduzindo as devoluções.

## Descrição do Problema

A ICPC vende conectores elétricos com cinco pontos de conexão numerados de 1 a 5. Cada ponto pode ser um "plugue" ou uma "tomada", representados por 1 (plugue) e 0 (tomada). Dois conectores são compatíveis se, para cada ponto de conexão com o mesmo rótulo, um ponto é um plugue e o outro ponto é uma tomada.

### Entrada

A entrada consiste em duas linhas:

- A primeira linha contém cinco inteiros Xi (0 ≤ Xi ≤ 1 para i = 1,2, ..., 5), representando os pontos de conexão do primeiro conector.
- A segunda linha contém cinco inteiros Yi (0 ≤ Yi ≤ 1 para i = 1,2, ..., 5), representando os pontos de conexão do segundo conector.

Cada valor `0` representa uma tomada e `1` representa um plugue.

### Saída

Retorne uma string representando se os conectores são compatíveis ou não:

- Se forem compatíveis, retorne a letra maiúscula **"Y"**.
- Caso contrário, retorne a letra maiúscula **"N"**.

### Explicação

Os conectores são compatíveis, pois para cada ponto de conexão, um é um plugue e o outro é uma tomada.

## Exemplo

### Entrada

1 0 1 0 1 

0 1 0 1 0

### Saída

Y


### Testes
50 Sucessos
2 Falhas




