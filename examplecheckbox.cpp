#include "examplecheckbox.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;
ExampleCheckBox::ExampleCheckBox(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    _checked=false;
    _hasznalt=false;
    _jobb=false;
    _bal=false;
    _focused=0;
}

void ExampleCheckBox::draw()
{


    gout << move_to(_x, _y) << color(80,80,80) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(255,255,255) << box(_size_x-4, _size_y-4);


    if (_checked  && _bal)
    {

        gout << color(255,25,25);
        for (int i=3; i<8; i++)
        {
            gout << move_to(_x+i, _y+4) << line(_size_x-8, _size_y-8);

            gout << move_to(_x+_size_x-i, _y+4) << line(-_size_x+8, _size_y-8);

        }


        set_hasznalt(true);


    }
    if (_checked  && _jobb )
    {
        gout << color(25,25,255);
        for (int i=-_size_x; i<_size_x/2-4; i++)
        {
            for (int j=-_size_x; j<_size_x/2-4; j++)
            {
                if(i*i+j*j<(_size_x/2-4)*(_size_x/2-4))
                {
                    gout<<move_to(_x+i+(_size_x/2),_y+j+(_size_x/2))<<dot;
                }
            }
        }

        set_hasznalt(true);


    }

}

void ExampleCheckBox::handle(event ev)
{
    get_hasznalt();
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) &&(ev.button==btn_left || ev.button==btn_right) && _hasznalt==false)
    {
        if( ev.button==btn_left)
        {
            _checked = true;
            _jobb = false;
            _bal=true;


        }
        if( ev.button==btn_right)
        {
            _checked = true;
            _bal = false;
            _jobb=true;
        }

    }

}
bool ExampleCheckBox::is_checked() const
{
    return _checked;
}

bool ExampleCheckBox::focusable() const
{

}

void ExampleCheckBox::focus()
{

}

void ExampleCheckBox::unfocus()
{

}
