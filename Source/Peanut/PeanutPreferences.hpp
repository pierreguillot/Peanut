/*
 // Copyright (c) 2016 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#ifndef PEANUT_PREFERENCES_HEADER
#define PEANUT_PREFERENCES_HEADER

#include "PeanutInstance.hpp"

namespace peanut
{
    class Preferences : public Component
    {
    public:
        Preferences();
        ~Preferences();
        void resized() final;
    private:
        //Instance& m_instance;
        class Option : public Component
        {
        public:
            Option(String const& name, Component* entry);
            void resized() final;
        private:
            Label                    m_title;
            ScopedPointer<Component> m_entry;
        };
        
        OwnedArray<Option> m_options;
        Array<File>        m_files;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Preferences)
    };
}

#endif // PEANUT_PREFERENCES_HEADER
