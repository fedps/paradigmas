// generated by Fast Light User Interface Designer (fluid) version 1.0302

#include "window.h"

UserInterface::UserInterface() {
  { w = new Fl_Double_Window(620, 565, "Simple CRUD");
    w->user_data((void*)(this));
    { inputIn = new Fl_Input(117, 46, 235, 24, "Nome Entrada");
    } // Fl_Input* inputIn
    { btnClear = new Fl_Button(24, 171, 100, 25, "Clear");
    } // Fl_Button* btnClear
    { btnUpdate = new Fl_Button(147, 171, 100, 25, "Update");
    } // Fl_Button* btnUpdate
    { btnDelete = new Fl_Button(270, 171, 100, 25, "Delete");
    } // Fl_Button* btnDelete
    { btnInsert = new Fl_Button(394, 171, 100, 25, "Insert");
    } // Fl_Button* btnInsert
    { Fl_Box* o = new Fl_Box(132, 16, 255, 16, "Simple CRUD");
      o->labelfont(1);
      o->labelsize(22);
    } // Fl_Box* o
    { browser = new Fl_Browser(24, 218, 470, 277);
      browser->type(2);
    } // Fl_Browser* browser
    { inputOut = new Fl_Input(117, 73, 236, 25, "Nome Sa\303\255""da");
    } // Fl_Input* inputOut
    { btnImport = new Fl_Button(367, 46, 175, 22, "Importar configura\303\247\303\265""es");
    } // Fl_Button* btnImport
    { btnImport = new Fl_Button(367, 75, 175, 22, "Exportar configura\303\247\303\265""es");
    } // Fl_Button* btnImport
    w->end();
  } // Fl_Double_Window* w
}
