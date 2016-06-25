/*
 // Copyright (c) 2016 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#include "Peanut.hpp"

namespace peanut
{
    Instance::Instance()
    {
        m_internal = new Preferences();
        addAndMakeVisible(m_internal);
    }
    
    Instance::~Instance()
    {
        ;
    }
    
    void Instance::resized()
    {
        m_internal->setBounds(getBounds());
    }
}


