#include "game.h"
#include "graphics.hpp"
#include "examplecheckbox.hpp"
#include <vector>

#include<iostream>

using namespace std;
using namespace genv;

Game::Game(int x, int y, int sx, int sy, int sor, int oszlop)
    :Widget(x,y,sx,sy)
{
    _xo=2;
    _sor=sor;
    _oszlop=oszlop;
}
void Game::fulldraw()
{
    int j=0;
    for (int i=0; i<_oszlop ;i++)
    {
        for(j=0; j<_sor;j++)
        {
            ExampleCheckBox * seged = new ExampleCheckBox(_x+j*_size_x, _y+i*_size_y, _size_x, _size_y);
            _mezok.push_back(seged);
            seged->ExampleCheckBox::draw();
            cout<<j<<" ";
        }
        cout<<endl;
        j=0;
    }
}
void Game::draw() const
{
    for(int i=0; i<_mezok.size();i++)
    {
        _mezok[i]->ExampleCheckBox::draw();
    }

}

