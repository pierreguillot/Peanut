/*
 // Copyright (c) 2016 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#include "Peanut.hpp"

namespace peanut
{
    Patcher::Patcher(xpd::patch const& patch) :
    m_patch(patch)
    {
        assert(bool(patch) && "Patcher is invalid.");
        setBounds(0, 20, 600, 400);
        setInterceptsMouseClicks(false, true);
        
        std::vector<xpd::object> objects(patch.objects());
        for(size_t i = 0; i < objects.size(); ++i)
        {
            xpd::gui gui;
            try
            {
                gui = objects[i];
            }
            catch(...)
            {
                ;
            }
            if(bool(gui))
            {
                if(gui.type() == xpd::gui::bang)
                {
                    m_interfaces.add(new Toggle(gui));
                    addAndMakeVisible(m_interfaces.getLast());
                }
                else if(gui.type() == xpd::gui::toggle)
                {
                    m_interfaces.add(new Toggle(gui));
                    addAndMakeVisible(m_interfaces.getLast());
                }
                /*
                 if(gui.type() == xpd::gui::number)
                 {
                 m_parameters.add(new GuiNumbox(processor, gui));
                 addAndMakeVisible(m_parameters.getLast());
                 }
                 else if(gui.type() == xpd::gui::radio_horizontal ||
                 gui.type() == xpd::gui::radio_vertical)
                 {
                 m_parameters.add(new GuiRadio(processor, gui));
                 addAndMakeVisible(m_parameters.getLast());
                 }
                 else if(gui.type() == xpd::gui::slider_horizontal ||
                 gui.type() == xpd::gui::slider_vertical)
                 {
                 m_parameters.add(new GuiSlider(processor, gui));
                 addAndMakeVisible(m_parameters.getLast());
                 }
                 else if(gui.type() == xpd::gui::toggle)
                 {
                 m_parameters.add(new GuiToggle(processor, gui));
                 addAndMakeVisible(m_parameters.getLast());
                 }
                 */
            }
        }
        
    }
    
    Patcher::~Patcher()
    {
        
    }
}