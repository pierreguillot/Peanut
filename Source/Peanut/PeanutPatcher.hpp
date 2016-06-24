/*
 // Copyright (c) 2016 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#ifndef PEANUT_PATCHER_HEADER
#define PEANUT_PATCHER_HEADER

#include "PeanutInterface.hpp"

namespace peanut
{    
    class Patcher : public Component
    {
    public:
        Patcher(xpd::patch const& patch);
        ~Patcher();
    private:
        xpd::patch const&     m_patch;
        OwnedArray<Interface> m_interfaces;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Patcher)
    };
}

#endif // PEANUT_PATCHER_HEADER
