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
|[trace]  ?- avo(joao,Y).|  teste1  |
|Call: (8) avo(joao, _10934) ? creep|
|Call: (9) pai(joao, _11152) ? creep|
|Exit: (9) pai(joao, jose) ? creep|
|Call: (9) pai(jose, _10934) ? creep|
|Fail: (9) pai(jose, _10934) ? creep|
|Fail: (8) avo(joao, _10934) ? creep|
|false.|

|trace        | Comentário|
|-------------|-----------|
|[trace]  ?- avo(roberto,Y).|
|Call: (8) avo(roberto, _7440) ? creep|
|Call: (9) pai(roberto, _7658) ? creep|
|Exit: (9) pai(roberto, joao) ? creep|
|Call: (9) pai(joao, _7440) ? creep|
|Exit: (9) pai(joao, jose) ? creep|
|Exit: (8) avo(roberto, jose) ? creep|
|Y = jose ;|
|Redo: (9) pai(roberto, _7658) ? creep|
|Exit: (9) pai(roberto, julio) ? creep|
|Call: (9) pai(julio, _7440) ? creep|
|Exit: (9) pai(julio, marcos) ? creep|
|Exit: (8) avo(roberto, marcos) ? creep|
|Y = marcos ;|
|Redo: (9) pai(julio, _7440) ? creep|
|Exit: (9) pai(julio, mario) ? creep|
|Exit: (8) avo(roberto, mario) ? creep|
|Y = mario.|


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
