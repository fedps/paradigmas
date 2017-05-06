#ifndef SCORETOTAL_H
#define SCORETOTAL_H
#include <string>

using namespace std;

class ScoreTotal{
    private:
        string name;
        int pontos;

    public:
    ScoreTotal(string name, int pontos);
    string getName() const;
    int getPontos();
    void addPontos(int pontos);
    bool operator<(const ScoreTotal& tot)const;
};
bool cmpNameScore(const ScoreTotal& tot1,const ScoreTotal& tot2);
#endif
