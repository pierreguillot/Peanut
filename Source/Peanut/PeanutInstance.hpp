/*
 // Copyright (c) 2016 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#ifndef PEANUT_INSTANCE_HEADER
#define PEANUT_INSTANCE_HEADER

#include "PeanutPatcher.hpp"

namespace peanut
{
    class Instance : public Component, public Button::Listener, public xpd::instance
    {
    public:
        Instance();
        ~Instance();
        void paint(Graphics&) final;
        void buttonClicked(Button* button) final;
    private:
        OwnedArray<Patcher> m_patchers;        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Instance)
    };
}

#endif // PEANUT_INSTANCE_HEADER
