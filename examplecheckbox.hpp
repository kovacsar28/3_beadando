#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <math.h>

class ExampleCheckBox : public Widget {
protected:
    int _focused;
    bool _checked;
    bool _hasznalt;
    bool _jobb;
    bool _bal;


public:
    ExampleCheckBox(int x, int y, int sx, int sy);
    virtual void draw()  ;
    bool get_hasznalt()
    {
        return _hasznalt;
    }
    void set_hasznalt(bool h)
    {
        _hasznalt = h;
    }

    virtual void handle(genv::event ev);
    virtual bool is_checked() const ;
    virtual bool focusable() const;
    virtual void focus();
    virtual void unfocus();

};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
