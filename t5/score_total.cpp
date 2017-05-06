#include "score_total.hpp"
#include "score_atividades.hpp"

ScoreTotal::ScoreTotal(string name, int pontos){
    this->name = name;
    this->pontos = pontos;
}

string ScoreTotal::getName() const{
    return this->name;
}

int ScoreTotal::getPontos(){
    return this->pontos;
}

void ScoreTotal::addPontos(int pontos){
    this->pontos = this->pontos + pontos;
}

bool ScoreTotal::operator<(const ScoreTotal& tot)const{
      return this->pontos < tot.pontos;
}

bool cmpNameScore(const ScoreTotal& tot1, const ScoreTotal& tot2) {
   return tot1.getName() < tot2.getName();
}
