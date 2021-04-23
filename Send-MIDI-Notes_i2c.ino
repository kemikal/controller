/**
 * Example showing how to send MIDI Note messages.
 * 
 * @boards  AVR, AVR USB, Nano Every, Due, Nano 33, Teensy 3.x, ESP32
 */

#include <Control_Surface.h>
#include "Wire.h"

// Instantiate the MIDI over USB interface
USBMIDI_Interface midi;

// Push button connected between pin 2 and ground.
// Note message is sent when pressed.
Button pushbutton = {2};
Button pushbutton2 = {3};

// MCP23018 PIN - WORK IN PROGRESS
Button pushbutton3 = {B0};

using namespace MIDI_Notes;

// MIDI address of the note to send
const MIDIAddress noteAddress = {note(C, 4), CHANNEL_1};
const MIDIAddress noteAddress2 = {note(D, 4), CHANNEL_1};
const MIDIAddress noteAddress3 = {note(A, 4), CHANNEL_1};
// The velocity of the note events
const uint8_t velocity = 0x7F;

void setup() {
  pushbutton.begin(); // enables internal pull-up
  midi.begin();       // initialize the MIDI interface

    pushbutton2.begin(); // enables internal pull-up
    midi.begin();       // initialize the MIDI interface
    
    pushbutton3.begin(); // enables internal pull-up
    midi.begin();       // initialize the MIDI interface
}

void loop() {
  midi.update(); // read and handle or discard MIDI input

  pushbutton.update();                              // read the button state
  if (pushbutton.getState() == Button::Falling)     // if the button is pressed
    midi.sendNoteOn(noteAddress, velocity);         // send a note on event
  else if (pushbutton.getState() == Button::Rising) // if the button is released
    midi.sendNoteOff(noteAddress, velocity);        // send a note off event

    pushbutton2.update();                              // read the button state
  if (pushbutton2.getState() == Button::Falling)     // if the button is pressed
    midi.sendNoteOn(noteAddress2, velocity);         // send a note on event
  else if (pushbutton2.getState() == Button::Rising) // if the button is released
    midi.sendNoteOff(noteAddress2, velocity);        // send a note off event

    pushbutton3.update();                              // read the button state
  if (pushbutton3.getState() == Button::Falling)     // if the button is pressed
    midi.sendNoteOn(noteAddress3, velocity);         // send a note on event
  else if (pushbutton3.getState() == Button::Rising) // if the button is released
    midi.sendNoteOff(noteAddress3, velocity);        // send a note off event

    
}
