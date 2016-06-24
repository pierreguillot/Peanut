/*
 // Copyright (c) 2015 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#include "GuiParameter.hpp"

namespace peanut
{
    Interface::Interface(xpd::gui const& gui) :
    m_type(gui.type()),
    m_minimum(gui.minimum()),
    m_maximum(gui.maximum()),
    m_value(0.f),
    m_edited(false)
    {
        setBounds(gui.x(), gui.y(), gui.width(), gui.height());
        setOpaque(true);
        setValue(gui.value());
    }
    
    void Interface::setValue(float value, bool redraw)
    {
        if(m_minimum < m_maximum)
        {
            m_value = std::max(std::min(value, m_maximum), m_minimum);
        }
        else
        {
            m_value = std::max(std::min(value, m_minimum), m_maximum);
        }
        if(m_index)
        {
            int todo;
            //m_processor.setParameterNonNormalizedNotifyingHost(int(m_index)-1, m_value);
        }
        if(redraw)
        {
            repaint();
        }
    }
    
    float Interface::getValueNormalized() const noexcept
    {
        if(getMinimum() < getMaximum())
        {
            return (getValue() - getMinimum()) / (getMaximum() - getMinimum());
        }
        return 1.f - (getValue() - getMaximum()) / (getMinimum() - getMaximum());
    }
    
    void Interface::setValueNormalized(float value, bool redraw)
    {
        value = std::max(std::min(value, 1.f), 0.f);
        if(getMinimum() < getMaximum())
        {
            setValue(value * (getMaximum() - getMinimum()) + getMinimum());
        }
        else
        {
            setValue((1.f - value) * (getMinimum() - getMaximum()) + getMaximum());
        }
    }
    
    void Interface::startEdition() noexcept
    {
        int todo;
        //m_value = m_processor.getParameterNonNormalized(int(m_index)-1);
        m_edited = true;
    }
    
    void Interface::stopEdition() noexcept
    {
        m_edited = false;
    }
    
    void Interface::update()
    {
        if(m_index && m_edited == false)
        {
            int todo;
            const float value = 0.;//m_processor.getParameterNonNormalized(int(m_index)-1);
            if(value != m_value)
            {
                m_value = value;
                repaint();
            }
        }
    }
}

