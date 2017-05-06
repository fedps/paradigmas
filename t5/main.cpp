#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "score_atividades.hpp"
#include "score_total.hpp"

int main(){
    ifstream data("score.csv");
    string line;
    string cell[3];
    vector<ScoreAtividades> vAtiv;
    vector<ScoreTotal> vTot;
    bool existe = false;

    /*Obtém os dados do arquivo csv*/
    while (getline(data, line)) {
        stringstream linestream(line);
        getline(linestream, cell[0], ',');
        getline(linestream, cell[1], ',');
        getline(linestream, cell[2], ',');
        vAtiv.push_back(ScoreAtividades(cell[0], cell[1], stoi(cell[2])));
    }

    /*Lista as atividades conforme o csv*/
    cout <<"Pontuação por atividade não ordenada:"<<endl;

    vector<ScoreAtividades>::iterator it;
    for (it = vAtiv.begin(); it != vAtiv.end(); it++)
        cout<< it->getName() <<","<<it->getAtividade()<<","<<it->getPontos()<<endl;

    sort(vAtiv.begin(), vAtiv.end()); /*Ordena por pontuação, da maior para a menor*/

    /*Lista as atividades ordenada por pontos*/
    cout <<"\n\n" <<"Pontuação por atividade ordenada por pontos:"<<endl;
    for (it = vAtiv.begin(); it != vAtiv.end(); it++)
        cout<< it->getName() <<","<<it->getAtividade()<<","<<it->getPontos()<<endl;

    /*Adiciona as pontuações da atividade para a Classe total*/
    vector<ScoreTotal>::iterator it2;
    for (it = vAtiv.begin(); it != vAtiv.end(); it++){
        for (it2 = vTot.begin(); it2 != vTot.end(); it2++){
            if(it->getName() == it2->getName()){ /*Se existir o nome já no vector, adiciona os pontos*/
                it2->addPontos(it->getPontos());
                existe = true;
            }
        }
            if(!existe){/*Se não existir o nome, cria ele*/
                vTot.push_back(ScoreTotal(it->getName(),it->getPontos()));
            }
        existe = false;
    }

    /*Lista o total não ordenado*/
    cout <<"\n\n" <<"Pontuação por total não ordenada:"<<endl;

    for (it2 = vTot.begin(); it2 != vTot.end(); it2++)
        cout<< it2->getName() <<","<<it2->getPontos()<<endl;

    sort(vTot.begin(), vTot.end(), cmpNameScore); /*Ordena por nome*/

    /*Lista o total ordenado por nome*/
    cout <<"\n\n" <<"Pontuação por total ordenada pelo nome:"<<endl;

    for (it2 = vTot.begin(); it2 != vTot.end(); it2++)
        cout<< it2->getName() <<","<<it2->getPontos()<<endl;

    sort(vTot.begin(), vTot.end());/*Ordena por pontos, do menor para o maior*/

    /*Lista o total ordenado por ponto*/
    cout <<"\n\n" <<"Pontuação por total ordenada pelos pontos:"<<endl;

    for (it2 = vTot.begin(); it2 != vTot.end(); it2++)
        cout<< it2->getName() <<","<<it2->getPontos()<<endl;
}
