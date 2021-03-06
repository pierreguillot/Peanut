/*
 // Copyright (c) 2016 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#include "Peanut.hpp"

namespace peanut
{
    Toggle::Toggle(xpd::gui const& gui) : Interface(gui)
    {
        
    }
    
    void Toggle::paint(Graphics& g)
    {
        g.fillAll(Env::getColorBg());
        g.setColour(Env::getColorBd());
        g.drawRect(getLocalBounds(), Env::getBorderSize());
        if(getValue() != 0.f)
        {
            g.drawLine(0, 0, getWidth(), float(getHeight()), Env::getBorderSize());
            g.drawLine(getWidth(), 0, 0, getHeight(), Env::getBorderSize());
        }
    }
    
    void Toggle::mouseDown(const MouseEvent& event)
    {
        setValue(1.f - getValue());
    }
}


