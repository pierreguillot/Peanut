/*
 // Copyright (c) 2016 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#include "Peanut.hpp"

namespace peanut
{
    class Laf : public LookAndFeel_V1
    {
    public:
        Laf()
        {
            setColour(TextEditor::backgroundColourId, Env::getColorBg());
            setColour(TextEditor::textColourId, Env::getColorTxt());
            setColour(TextEditor::highlightColourId, Env::getColorBd().withAlpha(0.25f));
            setColour(TextEditor::highlightedTextColourId, Env::getColorBd());
            setColour(TextEditor::outlineColourId, Env::getColorBd());
            setColour(TextEditor::focusedOutlineColourId, Env::getColorBd());
            setColour(CaretComponent::caretColourId, Env::getColorBd());
            
            setColour(Label::backgroundColourId, Env::getColorBg());
            setColour(Label::textColourId, Env::getColorTxt());
            setColour(Label::outlineColourId, Env::getColorInv());
            setColour(Label::backgroundWhenEditingColourId, Env::getColorBg());
            setColour(Label::textWhenEditingColourId, Env::getColorBg());
            setColour(Label::outlineWhenEditingColourId, Env::getColorInv());
            
            setColour(ListBox::backgroundColourId, Env::getColorBg());
            setColour(ListBox::outlineColourId, Env::getColorBd());
            
            setColour(ComboBox::backgroundColourId, Env::getColorBg());
            setColour(ComboBox::textColourId, Env::getColorTxt());
            setColour(ComboBox::outlineColourId, Env::getColorBd());
            setColour(ComboBox::buttonColourId, Env::getColorBd());
            setColour(ComboBox::arrowColourId, Env::getColorBd());
            
            setColour(PopupMenu::backgroundColourId, Env::getColorBg());
            setColour(PopupMenu::textColourId, Env::getColorTxt());
            setColour(PopupMenu::headerTextColourId, Env::getColorTxt());
            setColour(PopupMenu::highlightedBackgroundColourId, Env::getColorTxt());
            setColour(PopupMenu::highlightedTextColourId, Env::getColorBg());
        }
        
        void fillTextEditorBackground(Graphics& g, int, int, TextEditor&) final
        {
            g.fillAll(Env::getColorBg());
        }
        
        void drawTextEditorOutline(Graphics& g, int width, int height, TextEditor&) final
        {
            g.setColour(Env::getColorBd());
            g.drawRect(0, 0, width, height, Env::getBorderSize());
        }
        

        Font getComboBoxFont(ComboBox& box) final
        {
            return Env::getFont();
        }
        
        void positionComboBoxText(ComboBox& box, Label& label) final
        {
            label.setBounds(0, 0, box.getWidth() + 3 - box.getHeight(), box.getHeight());
            label.setFont(Env::getFont());
        }
        
        
        
        void drawPopupMenuBackground(Graphics& g, int width, int height)
        {
            g.fillAll(Env::getColorBg());
            g.setColour(Env::getColorBd());
            g.drawRect(0, 0, width, height, Env::getBorderSize());
        }
        
        Font getPopupMenuFont()
        {
            return Env::getFont();
        }
        
        void getIdealPopupMenuItemSize(const String& text, bool isSeparator, int standardMenuItemHeight, int& idealWidth, int& idealHeight)
        {
            idealHeight = Env::getFont().getHeight() + 4;
            idealWidth  = Env::getFont().getStringWidth (text) + idealHeight * 2;
        }
        
        void drawPopupMenuItem (Graphics& g, const Rectangle<int>& area,
                                                const bool isSeparator, const bool isActive,
                                                const bool isHighlighted, const bool isTicked,
                                                const bool hasSubMenu, const String& text,
                                                const String& shortcutKeyText,
                                                const Drawable* icon, const Colour* const textColourToUse)
        {
            Rectangle<int> r(area.reduced(1));
            if(isHighlighted)
            {
                g.setColour(Env::getColorTxt());
                g.fillRect(r);
                g.setColour(Env::getColorBg());
            }
            else
            {
                g.setColour(Env::getColorTxt());
            }
            g.setFont(Env::getFont());
            Rectangle<float> iconArea(r.removeFromRight((r.getHeight() * 5) / 4).reduced(3).toFloat());
        
            if(isTicked)
            {
                const Path tick (getTickShape (1.0f));
                g.fillPath(tick, tick.getTransformToScaleToFit (iconArea, true));
            }
            g.drawFittedText(text, 4, 1, area.getWidth() - 4, area.getHeight() - 1, Justification::centredLeft, 1);
        }
    };
    
    LookAndFeel& Env::getLookAndFeel()
    {
        static Laf laf;
        return laf;
    }
}


