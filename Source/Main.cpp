/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "../../zpd/xpd/xpd.hpp"
#include "Peanut/Peanut.hpp"


class PeanutApplication : public JUCEApplication
{
public:
    //==============================================================================
    PeanutApplication() {}

    const String getApplicationName() override       { return ProjectInfo::projectName; }
    const String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override       { return true; }

    void initialise(const String& commandLine) override
    {
        xpd::environment::initialize();
        mainWindow = new MainWindow (getApplicationName());
    }

    void shutdown() override
    {
        xpd::environment::clear();
        mainWindow = nullptr;
    }

    void systemRequestedQuit() override
    {
        quit();
    }

    void anotherInstanceStarted(const String& commandLine) override
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }


    class MainWindow : public DocumentWindow
    {
    public:
        MainWindow(String name)  : DocumentWindow(name, Colours::lightgrey, DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar(true);
            component = new peanut::Instance();
            component->setSize(getWidth(), getHeight());
            setContentNonOwned(component, true);
            setVisible(true);
            setFullScreen(true);
        }

        void closeButtonPressed() override
        {
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

    private:
        ScopedPointer<Component>  component;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };

private:
    ScopedPointer<MainWindow> mainWindow;
};


START_JUCE_APPLICATION (PeanutApplication)
