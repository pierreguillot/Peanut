/*
 // Copyright (c) 2015 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#ifndef PEANUT_TOGGLE_HEADER
#define PEANUT_TOGGLE_HEADER

#include "PeanutInterface.hpp"

namespace peanut
{
    class Toggle : public Interface
    {
    public:
        Toggle(xpd::gui const& gui);
        void paint(Graphics& g) final;
        void mouseDown(const MouseEvent& event) final;
    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Toggle)
    };
}

#endif // PEANUT_TOGGLE_HEADER
