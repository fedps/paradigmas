1. Considere a seguinte base de fatos e regras:

```prolog
pai(roberto,joao).
pai(joao, jose).
pai(roberto,julio).
pai(julio,marcos).
pai(julio,mario).
avo(X,Z) :- pai(X,Y), pai(Y,Z).
```
Trace de `avo(joao,Y)`
```prolog
[trace]  ?- avo(joao,Y). %Chama o predicado avo
Call: (8) avo(joao, _10934) ? creep.  %Substitui Y por uma variável _10934
Call: (9) pai(joao, _11152) ? creep.  %Seguindo a predicado avo, procura quem é o pai de joao
Exit: (9) pai(joao, jose) ? creep.  %Descobre que jose é pai de joao
Call: (9) pai(jose, _10934) ? creep.  %Agora vai buscar quem é o pai de jose
Fail: (9) pai(jose, _10934) ? creep.  %Falha em achar, pois jose não tem pai definido
Fail: (8) avo(joao, _10934) ? creep.  %Retorna para a consulta com falha
false. %Não teve sucesso na busca
```

Trace de `avo(roberto,Y)`
```prolog
[trace]  ?- avo(roberto,Y). %Chama o predicado avo
Call: (8) avo(roberto, _7440) ? creep. %Substitui Y por uma variável _7440
Call: (9) pai(roberto, _7658) ? creep. %Segue o predicado avo e busca o pai de roberto
Exit: (9) pai(roberto, joao) ? creep. %Descobre que o pai de roberto é joao
Call: (9) pai(joao, _7440) ? creep. %Busca quem é o pai de joao
Exit: (9) pai(joao, jose) ? creep. %Acha jose como pai de joao
Exit: (8) avo(roberto, jose) ? creep. %Retorna para a consulta, substituindo a variável _7440 por jose
Y = jose ; %Retorna que o avo de roberto é jose
Redo: (9) pai(roberto, _7658) ? creep. %Busca outra solução para a mesma consulta, usando outra variável
Exit: (9) pai(roberto, julio) ? creep. %Acha que julio também é pai de roberto
Call: (9) pai(julio, _7440) ? creep. %Procura o pai de julio
Exit: (9) pai(julio, marcos) ? creep. %Descobre que marcos é pai de julio
Exit: (8) avo(roberto, marcos) ? creep. %substitui a variável por marcos
Y = marcos ; %retorna marcos como avo de roberto
Redo: (9) pai(julio, _7440) ? creep. %Novamente faz outra busca para o mesmo problema, começa a partir do julio que tinha dois caminhos a seguir
Exit: (9) pai(julio, mario) ? creep. %Descobre que o mario é pai de julio
Exit: (8) avo(roberto, mario) ? creep. %mario substitui a variável da consulta inicial
Y = mario. %Retorna mario como outro avo de roberto
```


2. Considere o predicado definido abaixo, que resolve um problema de uma prova da Olimpíada Brasileira de Informática.

```prolog
azulejos(0,0).
azulejos(Na,Nq) :-
   Na > 0,
   Q is floor(sqrt(Na)),
   R is Na - Q*Q,
   azulejos(R,C),
   Nq is 1 + C.
```  
   
```prolog
[trace]  ?- azulejos(120,A). %Chama predicado azulejos
Call: (8) azulejos(120, _7448) ? creep. %Substitui A por uma variável de nome _7448
Call: (9) 120>0 ? creep. %Testa se o número de azulejos(Na = 120) é maior que 0
Exit: (9) 120>0 ? creep. %Teste deu verdadeiro
Call: (9) _7674 is floor(sqrt(120)) ? creep. %Nomeia Q como _7674 e assume que é igual a raiz de 120 arredondada
Exit: (9) 10 is floor(sqrt(120)) ? creep. %Q = 10
Call: (9) _7686 is 120-10*10 ? creep. %Coloca R como _7686 e define que é o resultado da equação
Exit: (9) 20 is 120-10*10 ? creep. %R = 20
Call: (9) azulejos(20, _7688) ? creep. %Recursivamente chama novamente azulejos
Call: (10) 20>0 ? creep. %Testa se 20 > 0
Exit: (10) 20>0 ? creep. %Teste deu verdadeiro
Call: (10) _7694 is floor(sqrt(20)) ? creep. %Procura raiz de 20 arredondada
Exit: (10) 4 is floor(sqrt(20)) ? creep. %Q = 4
Call: (10) _7706 is 20-4*4 ? creep. %Procura resultado da equação
Exit: (10) 4 is 20-4*4 ? creep. %R = 4
Call: (10) azulejos(4, _7708) ? creep. %Chama mais uma vez azulejos
Call: (11) 4>0 ? creep. %Testa se 4 > 0
Exit: (11) 4>0 ? creep. %É verdadeiro
Call: (11) _7714 is floor(sqrt(4)) ? creep. %Raiz quadrada de 4 arredondada
Exit: (11) 2 is floor(sqrt(4)) ? creep. %Q = 2
Call: (11) _7726 is 4-2*2 ? creep. %Resultado da equação
Exit: (11) 0 is 4-2*2 ? creep. %R = 0
Call: (11) azulejos(0, _7728) ? creep. %Mais uma vez chama azulejos
Exit: (11) azulejos(0, 0) ? creep. %Retorna da chamada pois não é maior que 0
Call: (11) _7732 is 1+0 ? creep. %Recursivamente começa a resolver a última equação para achar os números dos quadrados
Exit: (11) 1 is 1+0 ? creep. %Último número foi o zero, então acrescenta na soma de Nq
Exit: (10) azulejos(4, 1) ? creep. %Da equaço anterior foi calculado 1, esse 1 é usado para a repetição seguinte
Call: (10) _7738 is 1+1 ? creep. %Acha valor de Nq
Exit: (10) 2 is 1+1 ? creep. %Nq = 2
Exit: (9) azulejos(20, 2) ? creep. %Novamente retorna para a outra chamada, só que com o valor de 2
Call: (9) _7448 is 1+2 ? creep. %Acha valor de Nq
Exit: (9) 3 is 1+2 ? creep. %Nq = 3
Exit: (8) azulejos(120, 3) ? creep. %Como já foram feitas todas recursões termina a execução
A = 3 . %Resultado do programa
```
3. Escolha algum predicado recursivo que esteja nos slides ou em qualquer outra fonte. Faça a execução passo-a-passo de uma consulta com o predicado escolhido. Lembre-se de mostrar o código do predicado no seu arquivo t3parte1.md

```prolog
sum([],0).
sum(L,S) :- L = [H|T],
	    sum(T,AUX),
	    S is H + AUX.
```
```prolog
[trace]  ?- sum([1,2,3],L). % Chama o predicado sum
Call: (8) sum([1, 2, 3], _7268) ? creep. % Substitui L por uma variável _7268
Call: (9) [1, 2, 3]=[_7488|_7490] ? creep. % Divide L em 2 variáveis H|T
Exit: (9) [1, 2, 3]=[1, 2, 3] ? creep. % Define o que é H e o que é T
Call: (9) sum([2, 3], _7510) ? creep. % Começa a recursão chamando novamente sum
Call: (10) [2, 3]=[_7494|_7496] ? creep. % Divide a lista em H|T
Exit: (10) [2, 3]=[2, 3] ? creep. % Define quem é H e quem é T
Call: (10) sum([3], _7516) ? creep. % Chama novamente sum
Call: (11) [3]=[_7500|_7502] ? creep. % Divide em H|T
Exit: (11) [3]=[3] ? creep. % Define o H
Call: (11) sum([], _7522) ? creep. % Chama sum pela última vez
Exit: (11) sum([], 0) ? creep. % Como é lista vazia, retorna 0
Call: (11) _7526 is 3+0 ? creep. % Recursivamente continua a execuço, fazendo H + AUX
Exit: (11) 3 is 3+0 ? creep. % S = 3
Exit: (10) sum([3], 3) ? creep. % Define AUX como 3
Call: (10) _7532 is 2+3 ? creep. % Volta para a próxima execução
Exit: (10) 5 is 2+3 ? creep. % S = 5
Exit: (9) sum([2, 3], 5) ? creep. % AUX = 5
Call: (9) _7268 is 1+5 ? creep. % Próxima execução recursiva
Exit: (9) 6 is 1+5 ? creep. % S = 6
Exit: (8) sum([1, 2, 3], 6) ? creep. % Termina a execução
L = 6. % Resposta final
```
