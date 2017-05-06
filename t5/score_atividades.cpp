#include "score_atividades.hpp"
#include "score_total.hpp"

ScoreAtividades:: ScoreAtividades(string name, string atividade, int pontos){
    this->name = name;
    this->atividade = atividade;
    this->pontos = pontos;
}

string ScoreAtividades::getName(){
    return this->name;
}

string ScoreAtividades::getAtividade(){
    return this->atividade;
}

int ScoreAtividades::getPontos(){
    return this->pontos;
}

bool ScoreAtividades::operator<(const ScoreAtividades& ativ)const{
      return this->pontos > ativ.pontos;
}


