# Entendendo a Eliza

A escolha da frase da Eliza é bem simples, tomando esse 
[trecho](https://github.com/fedps/paradigmas/blob/61262ad457eb50e0e971835d02239e983859d275/extras/eliza/eliza.pl#L324-L329) 
como exemplo. Nele pode-se observar que toda vez que a palavra *no* é escrita, a Eliza irá falar alguma das frases:
> *are you saying no just to be negative ?*

> *you are being a bit negative.*

> *why not ?*

> *why no ?*

Esse tipo de abordagem pode gerar uma conversa sem nexo, como pode ser visto no chat, nas linhas 
[10-16](https://github.com/fedps/paradigmas/blob/61262ad457eb50e0e971835d02239e983859d275/extras/eliza/chat#L10-L16).

Basicamente todas as regras se mantém dessa forma, a única diferença é que algumas palavras tem maior prioridade, como é o caso
de *computer* com um valor de 50. Nesse caso quando aparecem 2 palavras que tem nas regras, será escolhido a frase da 
palavra com maior prioridade.


Nas linhas [441-450](https://github.com/fedps/paradigmas/blob/61262ad457eb50e0e971835d02239e983859d275/extras/eliza/eliza.pl#L441-L450)
é feita a divisão dos caracteres a partir da tabela ASCII. Na regra `X >= 65, X =< 90`, é definido as letras maiúsculas, na regra 
`X >= 97, X =< 123` é as letras minúsculas e na regra `X >= 48, X =< 57` são os números de 0 a 9. Já as outras regras se dividem
em espaço em branco `X =< 32` e demais símbolos da tabela ASCII.
