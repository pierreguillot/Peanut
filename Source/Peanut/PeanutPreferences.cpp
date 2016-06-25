/*
 // Copyright (c) 2016 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#include "Peanut.hpp"

namespace peanut
{
    class TextEntry : public TextEditor
    {
    public:
        TextEntry()
        {
            setFont(Env::getFont());
            setMultiLine(false, false);
            setReturnKeyStartsNewLine(false);
            setTabKeyUsedAsCharacter(false);
            setEscapeAndReturnKeysConsumed(true);
            setPopupMenuEnabled(false);
            setIndents(4, 1);
            setBorder(BorderSize<int>(Env::getBorderSize()));
            setLookAndFeel(&Env::getLookAndFeel());
        }
    };
    
    class PopupEntry : public ComboBox
    {
    public:
        PopupEntry()
        {
            setEditableText(false);
            setJustificationType(Justification::centredLeft);
            setLookAndFeel(&Env::getLookAndFeel());
            Array<File> files;
            File folder = File::getSpecialLocation(File::userDocumentsDirectory);
            if(folder.exists())
            {
                folder.findChildFiles(files, File::findFiles, true, "*.pd");
                for(int i = 0; i < files.size(); ++i)
                {
                    addItem (files[i].getFileNameWithoutExtension(), i+1);
                }
            }
        }
    };
    
    Preferences::Option::Option(String const& name, Component* entry) :
    m_entry(entry)
    {
        m_title.setFont(Env::getFont());
        m_title.setText(name, NotificationType::dontSendNotification);
        m_title.setLookAndFeel(&Env::getLookAndFeel());
        addAndMakeVisible(m_title);
        addAndMakeVisible(m_entry);
    }
    
    void Preferences::Option::resized()
    {
        const int width = getWidth() - 8;
        m_title.setBounds(0, 0, width / 4.f, getHeight());
        m_entry->setBounds(width / 4.f + 8, 0, width * 3.f / 4.f, getHeight());
    }
    
    Preferences::Preferences()
    {
        m_options.add(new Option("Adress", new TextEntry()));
        m_options.add(new Option("Port", new TextEntry()));
        m_options.add(new Option("Message", new TextEntry()));
        m_options.add(new Option("Patch", new PopupEntry()));
        for(int i = 0; i < m_options.size(); ++i)
        {
            addAndMakeVisible(m_options[i]);
        }
    }
    
    Preferences::~Preferences()
    {
        
    }
    
    
    void Preferences::resized()
    {
        const int width  = getWidth() - 16;
        const int height = Env::getFont().getHeight() + 4;
        for(int i = 0; i < m_options.size(); ++i)
        {
            m_options[i]->setBounds(4, 8 + (height+8) * i, width, height);
        }
    }
}


