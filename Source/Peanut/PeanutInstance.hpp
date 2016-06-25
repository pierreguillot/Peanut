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
    class Instance : public xpd::instance, public Component
    {
    public:
        Instance();
        ~Instance();
        void resized() final;
    private:
        OSCSender                m_sender;
        ScopedPointer<Component> m_internal;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Instance)
    };
}

#endif // PEANUT_INSTANCE_HEADER
