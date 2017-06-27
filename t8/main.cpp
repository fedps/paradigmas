#include <string>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <FL/fl_ask.H>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "window.h"



class Data {
private:
  std::string type;
  std::string name;
  float price;
public:
  Data(std::string type, std::string name, float price) {
    this->type = type;
    this->name = name;
    this->price = price;
  }
  std::string getType() {
    return type;
  }
  std::string getName() {
    return name;
  }
  std::string getPrice(){
    return std::to_string(price);
  }
  void setName(std::string name) {
    this->name = name;
  }  
  void setType(std::string type) {
    this->name = type;
  }  
  void setPrice(std::string price){
    this->price = std::stof(price);
  }
};


class View : public UserInterface {

private:
  std::vector<Data> data; 
   
public:
  
  View() {
    btnClear->callback((Fl_Callback*) cbBtnClear, (void*)(this));
    btnUpdate->callback((Fl_Callback*) cbBtnUpdate, (void*)(this)); 
    btnDelete->callback((Fl_Callback*) cbBtnDelete, (void*)(this)); 
    btnInsert->callback((Fl_Callback*) cbBtnInsert, (void*)(this)); 
    browser->callback((Fl_Callback*) cbBrowser, (void*)(this));
    btnImport->callback((Fl_Callback*) cbBtnImport, (void*)(this));
    btnExport->callback((Fl_Callback*) cbBtnExport, (void*)(this));
  }
  
  void show() {
    // Mostra janela
    w->show();
  }
  
  static void cbBtnImport(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    std::ifstream file("combustivel.csv");
    std::string line;
    std::string cell[3];

    while (std::getline(file, line)) {
      std::stringstream linestream(line);
      std::getline(linestream, cell[0], ',');
      std::getline(linestream, cell[1], ',');
      std::getline(linestream, cell[2], ',');
      gui->data.push_back(Data(cell[1], cell[0], std::stof(cell[2])));
      gui->browser->add((cell[0]+ " : " +cell[1]+ " : "+ cell[2]).c_str());
    }
  }
  static void cbBtnExport(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    std::ofstream file ("combustivel.csv");
    if(file.is_open()){
      //file<<"Ipiranga,Etanol,50.0\n";
      int linhas = gui->browser->size();
      int index=1;
      while (index <= linhas) {
        file<<gui->data[index-1].getName().c_str();
        file<<",";
        file<<gui->inputType->text(gui->inputType->find_index(gui->data[index-1].getType().c_str()));
        file<<",";
        file<<gui->data[index-1].getPrice().c_str();
        file<<"\n";
        index++;
      }
      file.close();
    }
    else std::cout<<"Não é possível abrir o arquivo";
  }
  // Funcao callback chamada quando pressionado botao 'Clear'
  static void cbBtnClear(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    gui->inputName->value("");
    gui->inputPrice->value("");
  }

  // Funcao callback chamada quando pressionado botao 'Insert'
  static void cbBtnInsert(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    std::string inputName(gui->inputName->value());
    std::string inputPrice(gui->inputPrice->value());
    gui->data.push_back(Data(gui->inputType->text(), inputName, std::stof(inputPrice)));
    gui->browser->add((inputName+" : "+ gui->inputType->text() +" : "+inputPrice).c_str());
  }

  // Funcao callback chamada quando selecionada uma linha no Fl_Browser
  static void cbBrowser(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    int index = gui->browser->value(); // 1-based index
    //gui->inputType->value(gui->data[index-1].getType().c_str());
    gui->inputType->value(gui->inputType->find_index(gui->data[index-1].getType().c_str()));
    gui->inputName->value(gui->data[index-1].getName().c_str());
    gui->inputPrice->value(gui->data[index-1].getPrice().c_str());
  }

  // Funcao callback chamada quando pressionado botao 'Update'
  static void cbBtnUpdate(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    int index = gui->browser->value(); // 1-based index
    std::cout << index << std::endl;
    if (index > 0) {
      std::string inputName(gui->inputName->value());
      std::string inputPrice(gui->inputPrice->value());      
      gui->data[index-1].setName(inputName);
      gui->data[index-1].setPrice(inputPrice);
      std::cout << inputName << std::endl;
      gui->browser->text(index,(inputName+" : "+ gui->inputType->text() + " : " + inputPrice).c_str());
    }
  }

  // Funcao callback chamada quando pressionado botao 'Delete'
  static void cbBtnDelete(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    int index = gui->browser->value(); // 1-based index
    std::cout << index << std::endl;
    if (index > 0) {
      std::string inputName(gui->inputName->value());
      std::string inputPrice(gui->inputPrice->value()); 
      std::string inputType(gui->inputType->text());
      gui->data.erase(gui->data.begin() + index-1);
      gui->browser->remove(index);
    }
  }
};

int main() {
  View gui;
  gui.show();
  return Fl::run();
}