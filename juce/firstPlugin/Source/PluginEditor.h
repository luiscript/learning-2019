/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class FirstPluginAudioProcessorEditor  : public AudioProcessorEditor
//,public Slider::Listener
{
public:
    FirstPluginAudioProcessorEditor (FirstPluginAudioProcessor&);
    ~FirstPluginAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
   // void sliderValueChanged(Slider* slider) override;

private:
    
    Slider mGainControlSlider;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FirstPluginAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FirstPluginAudioProcessorEditor)
};
