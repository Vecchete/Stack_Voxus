# Stack_Voxus

O exercício é o seguinte: 

Implemente uma classe de pilha de inteiros que possui os métodos
push , pop e min , onde min retorna o menor inteiro na pilha e todos os
métodos são executados em O(1) .

Resolução:

As operações push e pop ja possuem complexidade O(1) em comparações, pois sempre possui um apontador no topo da pilha. Portanto não precisamos criar um projeto arrojado para isso. Ao pensar em descobrir o menor inteiro, automaticamente pensa-se em buscar por toda a pilha, mas como é para esse método ter O(1) então precisamos de uma estrutura auxiliar para guardar os valores(geralmente em projetos de algoritmo, quando queremos que a execução seja em O(1), temos que a estrutura aonde nossos dados estão guardados é uma pilha ou uma tabela hash). Portanto seguimos para o projeto do algortmo min().

Base: Se a pilha está vazia então retorna o menor valor inteiro possivel.

Hipótese: Sabemos encontrar o menor elemento da pilha a cada push(), e usando uma estrutura auxiliar podemos armazenar em ordem cada menor valor de cada iteração.

Passo de como seria a inserção de cada elemento na pilha:
    se (min<=chave) então
        MINIMOS = MINIMOS U {min};
    senão
        MINIMOS = MINIMOS U {chave}
    
Passo do método:
    min = ultimo elemento de MINIMOS.
    
Logo, nosso conjunto minimos tem que ser uma estrutura no qual a busca pelo ultimo elemento seja em O(1), portanto a melhor estrutura para isso é uma pilha.

Temos então o seguinte algoritmo de inserção na pilha, usando uma pilha MINIMOS auxiliar.

    se a pilha for vazia então
        Empilha a chave.
    senão se(topo de de MINIMOS menor ou igual a chave) então
              Empilha o mesmo valor do topo em MINIMOS.
          senão
              Empilha o valor da chave em MINIMOS.

E para o minimo valor da pilha, basta retornarmos o menor valor do conjunto MINIMOS.

A implementação foi feita em C++:
-Foi criada um strut com codinome "pilha". Nessa estrutura apresenta uma chave inteira denominada "reg", e um ponteiro para apontar para o elemento de baixo da pilha.
- Foi criada uma classe Stack, com dois ponteiros de pilha, que inicializa em NULL.


Porque tudo roda em O(1)?

pop(): T(n) = 1 + 1 + 3 + 1 = 6.

       T(n)<c.1, para todo c>=6 e n>0 logo T(n) é O(1).
       
push():T(n) = 4 (pois possui if, else) + 1 + 1 + 1 + 1 = 8.

       T(n)<c.1, para todo c>=8 e n>0, logo T(n) é O(1).
       
min():T(n) = 1;

      T(n)<c.1, para todo c>=1 e n>0, logo T(n) é O(1).

Obviamente, com essa modificação, a estrutura total terá sempre 2n espaços de memória.
        
