/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    ;
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll(Colour (0xff001F36));
    g.setFont(Font (16.0f));
    g.setColour(Colours::white);
    g.drawText("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
    
}
