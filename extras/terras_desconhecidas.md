# Explorando a região de std::chrono

Parti em busca de novos conhecimentos explorando terras desconhecidas, com isso cheguei em um lugar chamado std::chrono, onde tudo
era sobre tempo. Fui em busca de informações para entender o que tinha de especial.

## Definindo std::chrono
A biblioteca chrono foi criada para lidar com o fatos de que os *clocks* podem ser diferentes em diferentes sistemas e melhorar
com o tempo em precisão. Para evitar ter que introduzir um novo tipo de tempo a cada 10 anos, a meta foi providenciar um conceito
preciso e neutro separando duração e ponto de tempo de *clocks* específicos. Assim foi baseado principalmente em três conceitos:

- **Duração**: constituido por espaços de tempo. Por exemplo: 30 segundos são 30 períodos de tempo de 1 segundo.
- **Ponto de Tempo**: referência a um ponto específico no tempo, como o dia de hoje.
- **Relógios**: consiste em um ponto de partida e uma taxa de *tick*. Por exemplo, pode começar a partir do dia 13 de maio de 2017
e contar a cada segundo.

## Exemplos de de códigos
Para entender melhor, fui em em outra jornada, agora procurando por exemplos que utilizem elementos de std::chrono.

```cpp
// high_resolution_clock example
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

int main ()
{
  using namespace std::chrono;

  high_resolution_clock::time_point t1 = high_resolution_clock::now();

  std::cout << "printing out 1000 stars...\n";
  for (int i=0; i<1000; ++i) std::cout << "*";
  std::cout << std::endl;

  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

  std::cout << "It took me " << time_span.count() << " seconds.";
  std::cout << std::endl;

  return 0;
}
```
Obtive essa saída com esse código:
```
printing out 1000 stars...
*******************************************************************************************************************************
*******************************************************************************************************************************
*******************************************************************************************************************************
********************************************************************************************************************************
*******************************************************************************************************************************
*******************************************************************************************************************************
*******************************************************************************************************************************
**************************************************************************************************************
It took me 0.000157018 seconds.
```
Este exemplo utilizou o conceito de *time points*

Outro exemplo obtido, agora utilizando o conceito de *clocks*:
```cpp
#include <iostream>
#include <chrono>
#include <ctime>

int fibonacci(int n)
{
    if (n < 3) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    int result = fibonacci(42);
    end = std::chrono::system_clock::now();

    int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
                             (end-start).count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds << "s\n";
}
```
Com a saída:
```
finished computation at Sat May 13 10:31:58 2017
elapsed time: 1s

```


Com isso terminei minha jornada desbravando essa terra desconhecida até então, adquiri novos conhecimentos que irão me ajudar
no futuro para desvendar novas terras.

## Referências
http://www.cplusplus.com/reference/chrono/

http://pt.cppreference.com/w/cpp/chrono

http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/

http://www.informit.com/articles/article.aspx?p=1881386&seqNum=2

