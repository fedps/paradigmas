#include <string>
#include <stdexcept>
#include <FL/fl_ask.H>
#include "window.h"
#include <Fl/Fl_PNG_Image.H>
#include <vector>
#include <algorithm>
#include <ctime>


class RandomView : public UserInterface {

public:
  
  RandomView() {
    btnRst->callback((Fl_Callback*) cbBtnRst, (void*)(this));
    btnSort->callback((Fl_Callback*) cbBtnSort, (void*)(this)); 
    /*
      Cria objeto do tipo png, seleciona o aquivo e adiciona na box
    */
    Fl_PNG_Image *img;
    img = new Fl_PNG_Image("logo.png");
    boxImg->image(img);
    boxImg->redraw();
  }
  
  void show() {
    // Mostra janela    
    w->show();
  }
  
  // Funcao callback chamada quando pressionado botao Reset
  static void cbBtnRst(Fl_Widget* btn, void* userdata) {
    RandomView* gui = static_cast<RandomView*>(userdata);
    gui->boxResult->label("");
    gui->inputValue->value("");
    gui->boxNum->label("");
    gui->index = 0;
    gui->numSort.clear();
  }

  // Funcao callback chamada quando pressionado botao Sortear
  static void cbBtnSort(Fl_Widget* btn, void* userdata) {
    try {
      RandomView* gui = static_cast<RandomView*>(userdata);
     
      int participantes = std::stoi(gui->inputValue->value()); //Le o número de participantes digitado
      
      if(gui->index == 0){        
        /*
          Se index = 0, significa que é a primeira vez que é sorteado, então precisa criar o vetor de números e embaralhar eles.
        */

        for (int i=1; i<=participantes; ++i) //preenche o vetor com números
          gui->numSort.push_back(i);

        std::random_shuffle (gui->numSort.begin(), gui->numSort.end()); //embaralha o vetor
        
        gui->boxResult->copy_label(std::to_string(*gui->numSort.begin()).c_str()); //pega o primeiro elemento do vetor e coloca na box

        std::string str = std::to_string(gui->index+1).c_str() + std::string("º ganhador"); //adiciona na string str a posição do ganhador junto com outra string
        gui->boxNum->copy_label(str.c_str()); //mostra a string str na box

      }
      else{

        gui->boxResult->copy_label(std::to_string(*(gui->numSort.begin()+gui->index)).c_str()); 
        //pega o elemento indicado por index

        std::string str = std::to_string(gui->index+1).c_str() + std::string("º ganhador");
        gui->boxNum->copy_label(str.c_str());
      }
      if(gui->index<participantes-1) //se não chegou ao final do vetor, incrementa index
        gui->index++;
      else{
        fl_alert("A lista chegou ao final!");
      }
    }  catch(std::invalid_argument&){
      fl_alert("ERRO: Adicione o número de participantes");
    }
  }

};

int main() {
  std::srand (unsigned(std::time(0))); //seed para o shuffle
  RandomView gui;
  gui.show();
  return Fl::run();
}