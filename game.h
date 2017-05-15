#ifndef GAME_H
#define GAME_H
#include "widgets.hpp"
#include "graphics.hpp"
#include "examplecheckbox.hpp"
#include <vector>

using namespace std;
using namespace genv;

class Game :public Widget {
    protected:
        int _xo;
        vector<ExampleCheckBox*> _mezok;
        int _sor;
        int _oszlop;
    public:
        Game(int x, int y, int sx, int sy, int sor, int oszlop);
        virtual void fulldraw();
        virtual void draw() const ;
        /*virtual void handle(genv::event ev);
        virtual bool is_checked() const ;*/


};

#endif // GAME_H
