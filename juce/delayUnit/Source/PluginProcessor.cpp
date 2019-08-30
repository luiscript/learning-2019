/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DelayUnitAudioProcessor::DelayUnitAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    addParameter(mDryWetParameter = new AudioParameterFloat("drywet",
                                                            "Dry Wet",
                                                            0.00,
                                                            1.0,
                                                            0.5));
    
    addParameter(mFeedbackParameter = new AudioParameterFloat("feedback",
                                                              "Feedback",
                                                              0,
                                                              0.98,
                                                              0.5));
    addParameter(mDelayTimeParameter = new AudioParameterFloat("delayTime",
                                                               "Delay Time",
                                                               0.01,
                                                               MAX_DELAY_TIME,
                                                               0.5));
    mCircularBufferLeft = nullptr;
    mCircularBufferRight = nullptr;
    mCircularBufferWriteHead = 0;
    mCircularBufferLength = 0;
    mDelayTimeInSamples = 0;
    mDelayReadHead = 0;
    mFeedBackLeft = 0;
    mFeedBackRight = 0;
    mDryWet = 0.5;
    mDelayTimeSmoothed = 0;
}

DelayUnitAudioProcessor::~DelayUnitAudioProcessor()
{
    if(mCircularBufferLeft != nullptr)
    {
        delete [] mCircularBufferLeft;
        mCircularBufferLeft = nullptr;
    }
    if(mCircularBufferRight != nullptr)
    {
        delete [] mCircularBufferRight;
        mCircularBufferRight = nullptr;
    }
}

//==============================================================================
const String DelayUnitAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool DelayUnitAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool DelayUnitAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool DelayUnitAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double DelayUnitAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int DelayUnitAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int DelayUnitAudioProcessor::getCurrentProgram()
{
    return 0;
}

void DelayUnitAudioProcessor::setCurrentProgram (int index)
{
}

const String DelayUnitAudioProcessor::getProgramName (int index)
{
    return {};
}

void DelayUnitAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void DelayUnitAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    mCircularBufferLength = sampleRate * MAX_DELAY_TIME;
    mDelayTimeInSamples = sampleRate * *mDelayTimeParameter;
    
    if(mCircularBufferLeft == nullptr)
    {
        mCircularBufferLeft = new float[mCircularBufferLength];
    }
    zeromem(mCircularBufferLeft, mCircularBufferLength * sizeof(float));
    
    if(mCircularBufferRight == nullptr)
    {
        mCircularBufferRight = new float[mCircularBufferLength];
    }
    zeromem(mCircularBufferRight, mCircularBufferLength * sizeof(float));
    
    
    mCircularBufferWriteHead = 0;
    mDelayTimeSmoothed = *mDelayTimeParameter;
    
}

void DelayUnitAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool DelayUnitAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void DelayUnitAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    
    float* leftChannel = buffer.getWritePointer(0);
    float* rightChannel = buffer.getWritePointer(1);
    
    for (int i = 0; i < buffer.getNumSamples(); i++)
    {
        
        mDelayTimeSmoothed = mDelayTimeSmoothed - 0.001 * (mDelayTimeSmoothed - *mDelayTimeParameter);
        mDelayTimeInSamples = getSampleRate() * mDelayTimeSmoothed;
        
        mCircularBufferLeft[mCircularBufferWriteHead] = leftChannel[i] + mFeedBackLeft;
        mCircularBufferRight[mCircularBufferWriteHead] = rightChannel[i] + mFeedBackRight;
        
        mDelayReadHead = mCircularBufferWriteHead - mDelayTimeInSamples;
        
        if( mDelayReadHead < 0)
        {
            mDelayReadHead += mCircularBufferLength;
        }
        
        int readHead_x = (int) mDelayReadHead;
        int readHead_x1 = readHead_x + 1;
        float readHeadFloat = mDelayReadHead - readHead_x;
        
        if(readHead_x1 >= mCircularBufferLength)
        {
            readHead_x1 -= mCircularBufferLength;
        }
        
        float delay_sample_left = lin_interp(mCircularBufferLeft[readHead_x], mCircularBufferLeft[readHead_x1], readHeadFloat);
        float delay_sample_right = lin_interp(mCircularBufferRight[readHead_x], mCircularBufferRight[readHead_x1], readHeadFloat);
        
        
        
        mFeedBackLeft = delay_sample_left * *mFeedbackParameter;
        mFeedBackRight = delay_sample_right * *mFeedbackParameter;
        
        buffer.addSample(0, i, buffer.getSample(0, i) * (1 - *mDryWetParameter) + delay_sample_left * *mDryWetParameter);
        buffer.addSample(1, i, buffer.getSample(1, i) * (1 - *mDryWetParameter) + delay_sample_right * *mDryWetParameter);
        
        mCircularBufferWriteHead++;
        
        if(mCircularBufferWriteHead >= mCircularBufferLength)
        {
            mCircularBufferWriteHead = 0;
        }
    }
}

//==============================================================================
bool DelayUnitAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* DelayUnitAudioProcessor::createEditor()
{
    return new DelayUnitAudioProcessorEditor (*this);
}

//==============================================================================
void DelayUnitAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void DelayUnitAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DelayUnitAudioProcessor();
}

float DelayUnitAudioProcessor::lin_interp(float sample_x, float sample_x1, float inPhase)
{
    return ( 1 - inPhase ) * sample_x + inPhase * sample_x1;
}
