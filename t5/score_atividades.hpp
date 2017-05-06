#ifndef SCOREATIVIDADES_H
#define SCOREATIVIDADES_H
#include <string>
#include <iterator>

using namespace std;

class ScoreAtividades{
    private:
        string name;
        string atividade;
        int pontos;

    public:
        ScoreAtividades(string name, string atividade, int pontos);
        string getName();
        string getAtividade();
        int getPontos();
        bool operator<(const ScoreAtividades& ativ)const;
};
#endif
