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


std::string genHtmlMark(std::string str, std::string mark){
  return "<"+mark+">"+str+"</"+mark+">";
}

std::string genHtmlGroup(std::string id,std::string label){
  return"<div class=\"form-group\">\n<label for=\""+id+"\" class=\"col-sm-2 control-label\">"+label+          
        "</label>\n<div class=\"col-sm-6\">\n<input type=\"text\" class=\"form-control validate[required]\" id=\""+
        id+"\" placeholder=\""+label+"\">\n</div>\n</div>\n";
}

class Data {
private:
  std::string label;
  std::string id;
public:
  Data(std::string id, std::string label) {
    this->label = label;
    this->id = id;
  }
  std::string getId() {
    return id;
  }
  std::string getLabel() {
    return label;
  }
  void setId(std::string id) {
    this->id = id;
  }  
  void setLabel(std::string label){
    this->label = label;
  }
};


class View : public UserInterface {

private:
  std::vector<Data> data; 
   
public:
  
  View() {
    /*Setar o nome do arquivo csv direto no inputIn*/ 
    btnClear->callback((Fl_Callback*) cbBtnClear, (void*)(this));
    btnUpdate->callback((Fl_Callback*) cbBtnUpdate, (void*)(this)); 
    btnDelete->callback((Fl_Callback*) cbBtnDelete, (void*)(this)); 
    btnInsert->callback((Fl_Callback*) cbBtnInsert, (void*)(this)); 
    browser->callback((Fl_Callback*) cbBrowser, (void*)(this));
    btnImport->callback((Fl_Callback*) cbBtnImport, (void*)(this));
    btnExport->callback((Fl_Callback*) cbBtnExport, (void*)(this));
    btnGenerate->callback((Fl_Callback*) cbBtnGenerate, (void*)(this));
  }
  
  void show() {
    // Mostra janela
    w->show();
  }
  
  static void cbBtnImport(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    std::string inputIn(gui->inputIn->value());
    std::ifstream file(inputIn);
    std::string line;
    std::string cell[3];
    bool firstLine = true;
    while (std::getline(file, line)) {
      if(firstLine){
        std::stringstream linestream(line);  
        std::getline(linestream, cell[0]);
        gui->inputTitle->value(cell[0].c_str());
        firstLine = false;
      }
      else{
        std::stringstream linestream(line);
        std::getline(linestream, cell[0], ',');
        std::getline(linestream, cell[1], ',');
        gui->data.push_back(Data(cell[0], cell[1]));
        gui->browser->add((cell[0]+ " : " +cell[1]).c_str());}
    }
  }
  static void cbBtnExport(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    std::string inputOut(gui->inputOut->value());
    std::ofstream file (inputOut);
    if(file.is_open()){
      file<<gui->inputTitle->value();
      file<<"\n";
      int linhas = gui->browser->size();
      int index=1;
      while (index <= linhas) {
        file<<gui->data[index-1].getId().c_str();
        file<<",";
        file<<gui->data[index-1].getLabel().c_str();
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
    gui->inputIn->value("");
    gui->inputOut->value("");
    gui->inputTitle->value("");
    gui->inputId->value("");
    gui->inputLabel->value("");
  }

  // Funcao callback chamada quando pressionado botao 'Insert'
  static void cbBtnInsert(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    std::string inputId(gui->inputId->value());
    std::string inputLabel(gui->inputLabel->value());
    gui->data.push_back(Data(inputId, inputLabel));
    gui->browser->add((inputId+" : "+inputLabel).c_str());
    gui->inputId->value("");
    gui->inputLabel->value("");
  }

  // Funcao callback chamada quando selecionada uma linha no Fl_Browser
  static void cbBrowser(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    int index = gui->browser->value(); // 1-based index
    gui->inputId->value(gui->data[index-1].getId().c_str());
    gui->inputLabel->value(gui->data[index-1].getLabel().c_str());
  }

  // Funcao callback chamada quando pressionado botao 'Update'
  static void cbBtnUpdate(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    int index = gui->browser->value(); // 1-based index
    std::cout << index << std::endl;
    if (index > 0) {
      std::string inputId(gui->inputId->value());
      std::string inputLabel(gui->inputLabel->value());      
      gui->data[index-1].setId(inputId);
      gui->data[index-1].setLabel(inputLabel);
      std::cout << inputLabel << std::endl;
      gui->browser->text(index,(inputId+" : "+ inputLabel).c_str());
    }
  }

  // Funcao callback chamada quando pressionado botao 'Delete'
  static void cbBtnDelete(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    int index = gui->browser->value(); // 1-based index
    std::cout << index << std::endl;
    if (index > 0) {
      std::string inputId(gui->inputId->value());
      std::string inputLabel(gui->inputLabel->value()); 
      gui->data.erase(gui->data.begin() + index-1);
      gui->browser->remove(index);
    }
  }
  static void cbBtnGenerate(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    std::ifstream file("template.html");
    std::ofstream fileOut ("index.html");
    std::string line;
    std::string str;
    if(fileOut.is_open()){
      while (std::getline(file, line)) {
        std::stringstream linestream(line); 
        std::getline(linestream, str); 
        std::string inputTitle(gui->inputTitle->value());
        if(line == ">>>1<<<"){
          fileOut<<genHtmlMark(inputTitle,"title");
        } else if(line == ">>>2<<<"){
          fileOut<<genHtmlMark(inputTitle,"h1");
        } else if(line == ">>>3<<<"){
          int size = gui->browser->size();
          int index=1;
          while (index <= size) {
            fileOut<<genHtmlGroup(gui->data[index-1].getId().c_str(),gui->data[index-1].getLabel().c_str());
            index++;
          }
        } else if(line == ">>>4<<<"){
          int size = gui->browser->size();
          int index=1;
          fileOut<<"dataSet[seq]=[index, icons,";
          while (index <= size) {
            std::string inputId(gui->data[index-1].getId().c_str());
            fileOut<<"object."+inputId;
            index++;
            if(index<=size)
              fileOut<<", ";
          }
          fileOut<<"];\n";
        }
        else{
            fileOut<<str;           
        }
        fileOut<<"\n";
      }

      fileOut.close();
    }
    else std::cout<<"Não é possível abrir o arquivo";
    fl_alert("Código Gerado");
  }
};


int main() {
  View gui;
  gui.show();
  return Fl::run();
}