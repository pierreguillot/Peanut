/*
 // Copyright (c) 2015 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#ifndef PEANUT_INTERFACE_HEADER
#define PEANUT_INTERFACE_HEADER

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../../zpd/xpd/xpd.hpp"

namespace peanut
{
    class Interface : public virtual Component
    {
    public:
        Interface(xpd::gui const& gui);
        ~Interface() {}
        inline xpd::gui::type_t getType() const noexcept {return m_type;}
        inline float getMaximum() const noexcept {return m_maximum;}
        inline float getMinimum() const noexcept {return m_minimum;}
        inline float getValue() const noexcept {return m_value;}
        float getValueNormalized() const noexcept;
        
    protected:
        
        void startEdition() noexcept;
        void stopEdition() noexcept;
        void setValue(float value, bool redraw = true);
        void setValueNormalized(float value, bool redraw = true);
        
    private:
        const xpd::gui::type_t  m_type;
        const float             m_minimum;
        const float             m_maximum;
        float                   m_value;
        bool                    m_edited;
    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Interface)
    };
}

#endif // PEANUT_INTERFACE_HEADER
