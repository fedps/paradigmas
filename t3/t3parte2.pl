%1. Defina um predicado somaQuad(X,Y,Q) que seja verdadeiro se Q for a soma dos quadrados de X e Y. Exemplos de uso:
%   ?- somaQuad(3,4,25).
%      true.
%   ?- somaQuad(3,4,Q).
%      Q = 25.
%   ?- somaQuad(3,4,10).
%      false.
somaQuad(X,Y,Q) :- Q is X^2+Y^2.


%2. Defina um predicado zeroInit(L) que é verdadeiro se L for uma lista que inicia com o número 0 (zero). Exemplo de uso:
%   ?- zeroInit([9,6,7]).
%      false.
%   ?- zeroInit([0,6,7]).
%      true.
zeroInit(L) :- nth0(0,L,0).


%3. Defina um predicado hasEqHeads(L1,L2) que seja verdadeiro se as listas L1 %  e L2 possuírem o mesmo primeiro elemento. Exemplos de uso:
%  ?- hasEqHeads([a,b,c],[b,c,a]).
%     false.
%  ?- hasEqHeads([a,b,c],[a,c,a]).
%     true.
hasEqHeads(L1,L2) :- L1 = [H|_], L2 = [G|_], H = G.


%4. Defina um predicado has5(L) que seja verdadeiro se L for uma lista de 5 elementos. Lembre de como funciona a unificação em Prolog e resolva este exercício 
%   sem usar o predicado pré-definido length. Exemplos de uso:
%   ?- has5([a,b,c]).
%      false.
%   ?- has5([a,b,c,d,e]).
%      true.
has5(L) :- L = [_,_,_,_,_].


%5. Defina um predicado hasN(L,N) que seja verdadeiro se L for uma lista de N elementos. Agora você pode usar um predicado pré-definido.
%   ?- hasN([a,b,c],3).
%      true.
%   ?- hasN([a,b,c,d,e],3).
%      false.
hasN(L,N) :- length(L,N).


%6. Defina um predicado isBin(L) que seja verdadeiro se L for uma lista contendo somente elementos 0 e 1. Use recursão. Exemplo:
%   ?- isBin([0]).
%      true.
%   ?- isBin([1]).
%      true.
%   ?- isBin([]).
%      false.
%   ?- isBin([0,1,0,1]).
%      true.
%   ?- isBin([0,1,2,3]).
%      false.
isBin([1]).
isBin([0]).
isBin(L) :- L = [H|T],
	    H >= 0, H =< 1,	    
            isBin(T).


%7. Defina um predicado mesmaPosicao(A,L1,L2) para verificar se um elemento A está na mesma posição nas listas L1 e L2. Assuma que L1 e L2 sejam permutações de uma 
%   lista de elementos distintos, sem repetições. Dica: procure auxílio em predicados pré-definidos. Exemplo de uso:
%   ?­ mesmaPosicao(c,[a,b,c,d,e],[e,d,c,b,a]).
%     true
%   ?­ mesmaPosicao(b,[a,b,c,d,e],[e,d,c,b,a]).
%     false
mesmaPosicao(A,L1,L2) :- nth0(X,L1,A),nth0(Y,L2,A), X=Y.


%8. Defina um predicado repete5(E,L) que seja verdadeiro se a lista L for composta por exatamente 5 repetições do elemento E. Não use recursão. Exemplos:
%   ?- repete5(a,L).
%      L = [a, a, a, a, a].
%   ?- repete5(a,[a,a]).
%      false.
%   ?- repete5(b,[b,b,b,b,b]).
%      true.
%   ?- repete5(E,[b,b,b,b,b]).
%      E = b.
repete5(E,L) :- permutation([E,E,E,E,E], L).


%9. Defina um predicado recursivo sumQuads(L,S) que seja verdadeiro se S for o somatório dos quadrados dos elementos da lista L.
%   ?- sumQuads([2,2],S).
%      S = 8 .
%   ?- sumQuads([2,2,2],S).
%      S = 12 .
%   ?- sumQuads([],S).
%      S = 0 .
sumQuads([],0).
sumQuads(L,S) :- L = [H|T],
		 sumQuads(T, AUX),
		 S is H^2 + AUX.


%10. Defina um predicado recursivo repete(N,E,L) que seja verdadeiro se a lista L for composta por exatamente N repetições do elemento E.
repete(0,_,[]).
repete(N,E,L) :- L = [H|T],
		 length(L,N),
		 H = E,
		 AUX is N-1,
                 repete(AUX,E,T).	         


%11. Defina um predicado recursivo mapop(L1,L2) que seja verdadeiro se a lista L2 for formada aplicando-se a operação 2*x+1 a cada elemento x da lista L1.
%    ?- mapop([1,2,3],L).
%       L = [3, 5, 7] .
%    ?- mapop([],L).
%       L = [] .
mapop([],[]).
mapop(L1,L2) :- L1 = [H|T],
		mapop(T,AUX),		
		D is 2*H+1,
                L2 = [D|AUX].	
                

%12. Defina um predicado positivos(L1,L2), de forma que L2 seja uma lista só com os elementos positivos de L1, conforme o exemplo abaixo:
%    ?­ positivos([­-1,0,1,-­2,9],L).
%      L = [1, 9]
positivos([],[]).
positivos(L1,L2) :- L1 = [H|T],
		    H =< 0,
		    positivos(T,L2).
positivos(L1,L2) :- L1 = [H|T],
		    L2 = [H|U],
		    H > 0,
		    positivos(T,U).
