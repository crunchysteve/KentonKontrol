#include <Control_Surface.h> // Include the Control Surface library

// Select the serial port to use.
auto &serial = Serial;
// Instantiate a Serial MIDI interface at the default MIDI baud rate.
SerialMIDI_Interface<decltype(serial)> midi {serial, MIDI_BAUD};

//  sysex messages to be assigned to buttons
uint8_t sysexDIN48[]   {0xF0, 0x00, 0x20, 0x13, 0x16, 0x00, 0x20, 0x00, 0x02, 0x00, 0x01, 0xF7};
uint8_t sysexDIN24[]   {0xF0, 0x00, 0x20, 0x13, 0x16, 0x00, 0x20, 0x00, 0x02, 0x00, 0x00, 0xF7};
uint8_t sysexStart[]   {0xF0, 0x00, 0x20, 0x13, 0x16, 0x00, 0x20, 0x00, 0x02, 0x00, 0x01, 0xF7};
uint8_t sysexCont[]    {0xF0, 0x00, 0x20, 0x13, 0x16, 0x00, 0x20, 0x00, 0x02, 0x00, 0x00, 0xF7};
uint8_t sysexThruOn[]  {0xF0, 0x00, 0x20, 0x13, 0x16, 0x00, 0x20, 0x00, 0x02, 0x00, 0x01, 0xF7};
uint8_t sysexThruOff[] {0xF0, 0x00, 0x20, 0x13, 0x16, 0x00, 0x20, 0x00, 0x02, 0x00, 0x00, 0xF7};
uint8_t sysexRestore[] {0xF0, 0x00, 0x20, 0x13, 0x16, 0x00, 0x20, 0x00, 0x02, 0x00, 0x00, 0xF7};

// Instantiate Button objects
Button sysexDIN48Button   {2};
Button sysexDIN24Button   {3};
Button sysexStartButton   {5};
Button sysexContButton    {6};
Button sysexThruOnButton  {7};
Button sysexThruOffButton {12};
Button sysexRestoreButton {13};

void setup() {
  Control_Surface.begin(); // Initialize the Control Surface
}

void loop() {
  //  Assign MIDI commands to Buttons
  if (sysexDIN48Button.update()   == Button::Falling) midi.sendSysEx(sysexDIN48);
  if (sysexDIN24Button.update()   == Button::Falling) midi.sendSysEx(sysexDIN24);
  if (sysexStartButton.update()   == Button::Falling) midi.sendSysEx(sysexStart);
  if (sysexContButton.update()    == Button::Falling) midi.sendSysEx(sysexCont);
  if (sysexThruOnButton.update()  == Button::Falling) midi.sendSysEx(sysexThruOn);
  if (sysexThruOffButton.update() == Button::Falling) midi.sendSysEx(sysexThruOff);
  if (sysexRestoreButton.update() == Button::Falling) midi.sendSysEx(sysexRestore);

  //  Send selected MIDI command
  midi.update();
}