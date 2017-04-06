1 - Considere a seguinte base de fatos e regras:

```prolog
pai(roberto,joao).
pai(joao, jose).
pai(roberto,julio).
pai(julio,marcos).
pai(julio,mario).
avo(X,Z) :- pai(X,Y), pai(Y,Z).
```


|trace        | Comentário|
|-------------|-----------|
|[trace]  ?- avo(joao,Y).|Chama avo |
|Call: (8) avo(joao, _10934) ? creep|Substitui Y por uma variável| 
|Call: (9) pai(joao, _11152) ? creep|Seguindo a predicado avo, procura quem é o pai de joao|
|Exit: (9) pai(joao, jose) ? creep|Descobre que jose é pai de joao|
|Call: (9) pai(jose, _10934) ? creep|Agora vai buscar quem é o pai de jose|
|Fail: (9) pai(jose, _10934) ? creep|Falha em achar, pois jose não tem pai definido|
|Fail: (8) avo(joao, _10934) ? creep|retorna para a consulta com falha|
|false.|Não teve sucesso na busca|

|trace        | Comentário|
|-------------|-----------|
|[trace]  ?- avo(roberto,Y).|Chama avo|
|Call: (8) avo(roberto, _7440) ? creep|Substitui Y por uma variável|
|Call: (9) pai(roberto, _7658) ? creep|Segue o predicado avo e busca o pai de roberto|
|Exit: (9) pai(roberto, joao) ? creep|Descobre que o pai de roberto é joao|
|Call: (9) pai(joao, _7440) ? creep|Busca quem é o pai de joao|
|Exit: (9) pai(joao, jose) ? creep|Acha jose como pai de joao|
|Exit: (8) avo(roberto, jose) ? creep|Retorna para a consulta, substituindo a variável por jose|
|Y = jose ;|Retorna que o avo de roberto é jose| 
|Redo: (9) pai(roberto, _7658) ? creep|Busca outra solução para a mesma consulta, usando outra variável|
|Exit: (9) pai(roberto, julio) ? creep|Acha que julio também é pai de roberto|
|Call: (9) pai(julio, _7440) ? creep|Procura o pai de julio|
|Exit: (9) pai(julio, marcos) ? creep|Descobre que marcos é pai de julio|
|Exit: (8) avo(roberto, marcos) ? creep|substitui a variável por marcos|
|Y = marcos ;|retorna marcos como avo de roberto|
|Redo: (9) pai(julio, _7440) ? creep|Novamente faz outra busca para o mesmo problema, começa a partir do julio que tinha dois caminhos a seguir|
|Exit: (9) pai(julio, mario) ? creep|Descobre que o mario é pai de julio|
|Exit: (8) avo(roberto, mario) ? creep|mario substitui a variável da consulta inicial|
|Y = mario.|retorna mario como outro avo de roberto|


2 - Considere o predicado definido abaixo, que resolve um problema de uma prova da Olimpíada Brasileira de Informática.

```prolog
azulejos(0,0).
azulejos(Na,Nq) :-
   Na > 0,
   Q is floor(sqrt(Na)),
   R is Na - Q*Q,
   azulejos(R,C),
   Nq is 1 + C.
```  
   
|trace        | Comentário|
|-------------|-----------|
|[trace]  ?- azulejos(120,A).|
|Call: (8) azulejos(120, _7448) ? creep|
|Call: (9) 120>0 ? creep|
|Exit: (9) 120>0 ? creep|
|Call: (9) _7674 is floor(sqrt(120)) ? creep|
|Exit: (9) 10 is floor(sqrt(120)) ? creep|
|Call: (9) _7686 is 120-10*10 ? creep|
|Exit: (9) 20 is 120-10*10 ? creep|
|Call: (9) azulejos(20, _7688) ? creep|
|Call: (10) 20>0 ? creep|
|Exit: (10) 20>0 ? creep|
|Call: (10) _7694 is floor(sqrt(20)) ? creep|
|Exit: (10) 4 is floor(sqrt(20)) ? creep|
|Call: (10) _7706 is 20-4*4 ? creep|
|Exit: (10) 4 is 20-4*4 ? creep|
|Call: (10) azulejos(4, _7708) ? creep|
|Call: (11) 4>0 ? creep|
|Exit: (11) 4>0 ? creep|
|Call: (11) _7714 is floor(sqrt(4)) ? creep|
|Exit: (11) 2 is floor(sqrt(4)) ? creep|
|Call: (11) _7726 is 4-2*2 ? creep|
|Exit: (11) 0 is 4-2*2 ? creep|
|Call: (11) azulejos(0, _7728) ? creep|
|Exit: (11) azulejos(0, 0) ? creep|
|Call: (11) _7732 is 1+0 ? creep|
|Exit: (11) 1 is 1+0 ? creep|
|Exit: (10) azulejos(4, 1) ? creep|
|Call: (10) _7738 is 1+1 ? creep|
|Exit: (10) 2 is 1+1 ? creep|
|Exit: (9) azulejos(20, 2) ? creep|
|Call: (9) _7448 is 1+2 ? creep|
|Exit: (9) 3 is 1+2 ? creep|
|Exit: (8) azulejos(120, 3) ? creep|
|A = 3 .|

3. Escolha algum predicado recursivo que esteja nos slides ou em qualquer outra fonte. Faça a execução passo-a-passo de uma consulta com o predicado escolhido. Lembre-se de mostrar o código do predicado no seu arquivo t3parte1.md
