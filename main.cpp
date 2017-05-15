#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include <vector>
#include "game.h"
#include "window.hpp"
using namespace std;
using namespace genv;

int XX = 800;
int YY = 640;

void event_loop(vector<Widget*>& widgets) {
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && (ev.button==btn_left || ev.button==btn_right)) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (size_t i=0;i<widgets.size();i++) {
            widgets[i]->draw();
        }
        gout << refresh;
    }
}





int main()
{
    gout.open(XX,YY);
    vector<Widget*> w;

    gout << move_to(640,40)<< color(255,255,255)<<text("X - bal gomb");
    gout << move_to(640,60)<< color(255,255,255)<<text("O - jobb gomb");


    int _oszlop = 20;
    int _sor = 20;

    int j=0;
    for (int i=0; i<_oszlop ;i++)
    {
        for(j=0; j<_sor;j++)
        {
            ExampleCheckBox * seged = new ExampleCheckBox(10+j*30, 10+i*30, 30, 30);
            w.push_back(seged);
        }
        j=0;
    }




    event_loop(w);

    return 0;
}
