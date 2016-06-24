/*
 // Copyright (c) 2016 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#include "Peanut.hpp"

namespace peanut
{
    class PatcherLoader : public Component, public ListBoxModel
    {
    public:
        PatcherLoader(Instance& instance) : m_instance(instance)
        {
            File folder = File::getSpecialLocation(File::userDocumentsDirectory);
            if(folder.exists())
            {
                folder.findChildFiles(m_files, File::findFiles, true, "*.pd");
            }
            m_table.setColour(ListBox::backgroundColourId, Env::getColorBg());
            m_table.setColour(ListBox::outlineColourId, Env::getColorBd());
            m_table.setOutlineThickness(Env::getBorderSize());
            m_table.setMultipleSelectionEnabled(false);
            m_table.setModel(this);
            addAndMakeVisible(m_table);

        }
        
        int getNumRows() final
        {
            return m_files.size();
        }
        
        void paintListBoxItem(int index, Graphics& g, int width, int height, bool selected) final
        {
            if(selected)
            {
                g.fillAll(Env::getColorBd());
                g.setColour(Env::getColorBg());
            }
            else
            {
                g.fillAll(Env::getColorBg());
                g.setColour(Env::getColorTxt());
            }
            g.setFont(Env::getFont());
            g.drawText(m_files[index].getFileNameWithoutExtension(), 2, 0, width - 4, height, Justification::centredLeft, true);
        }
        
        void listBoxItemDoubleClicked(int index, const MouseEvent&) final
        {
            m_instance.load(m_files[index]);
        }
        
        void resized() override
        {
            m_table.setBounds(8, 8, getWidth() - 16, getHeight() - 16);
        }
        
    private:
        Instance&   m_instance;
        Array<File> m_files;
        ListBox     m_table;
    };
    
    Instance::Instance() : TabbedComponent(TabbedButtonBar::TabsAtTop)
    {
        setTabBarDepth(24);
        setOutline(Env::getBorderSize());
        addTab(juce::String("+"), Env::getColorBg(), new PatcherLoader(*this), true);
    }
    
    Instance::~Instance()
    {
        ;
    }
    
    void Instance::load(File patch)
    {
        xpd::patch p = xpd::instance::load(patch.getFileName().toStdString(), patch.getParentDirectory().getFullPathName().toStdString());
        if(bool(p))
        {
            int const index = getNumTabs() - 1;
            addTab(juce::String(p.name()), Env::getColorBg(), new Patcher(p), true, index);
            setCurrentTabIndex(index);
        }
    }
}


