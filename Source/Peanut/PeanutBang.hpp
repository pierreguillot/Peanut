/*
 // Copyright (c) 2016 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#ifndef PEANUT_BANG_HEADER
#define PEANUT_BANG_HEADER

#include "PeanutInterface.hpp"

namespace peanut
{
    class Bang : public Interface
    {
    public:
        Bang(xpd::gui const& gui);
        void paint(Graphics& g) final;
        void mouseDown(const MouseEvent& event) final;
    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Bang)
    };
}

#endif // PEANUT_TOGGLE_HEADER
