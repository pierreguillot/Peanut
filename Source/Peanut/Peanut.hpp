/*
 // Copyright (c) 2016 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#ifndef PEANUT_HEADER
#define PEANUT_HEADER

#include "PeanutInterface.hpp"
#include "PeanutBang.hpp"
#include "PeanutToggle.hpp"
#include "PeanutPatcher.hpp"
#include "PeanutInstance.hpp"

namespace peanut
{
    class Env
    {
    public:
        static inline Font getFont()
        {
#ifdef __APPLE__
            return Font(String("Monaco"), 13.f, juce::Font::plain).withStyle(Font::bold);
#else
            return Font(String("DejaVu Sans Mono"), 12.f, juce::Font::plain).withStyle(Font::bold);
#endif
        }
        static inline int getBorderSize() noexcept {return 1;}
        static inline Colour const& getColorBg() noexcept {return Colours::lightgrey;}
        static inline Colour const& getColorBd() noexcept {return Colours::darkgrey;}
        static inline Colour const& getColorTxt() noexcept {return Colours::darkgrey;}
        static inline Colour getColorInv() noexcept {return Colour(uint8(0), uint8(0), uint8(0), uint8(0));}
    };
}

#endif // PEANUT_HEADER
