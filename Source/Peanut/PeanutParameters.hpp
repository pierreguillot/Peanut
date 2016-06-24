/*
 // Copyright (c) 2016 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#ifndef PEANUT_PARAMETERS_HEADER
#define PEANUT_PARAMETERS_HEADER

#include "PeanutInterface.hpp"

namespace peanut
{
    class Parameters : public Component
    {
    public:
        Parameters();
        ~Parameters();
    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Parameters)
    };
}

#endif // PEANUT_PARAMETERS_HEADER
