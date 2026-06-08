## KentonKontrol - A MIDI Sysex Command Sender for the Kenton D-Sync

The Kenton D-Sync is a bi-directional MIDI to DIN Sync Converter, with 3 user settable parameters. 
These parameters are, by default, changed by connecting a computer or phone to a MIDI interface and 
transmitting raw sysex messages from a laptop, via either the [Kenton web app](https://kentonuk.com/apps/dsync-config) or a terminal connection.
Neither of these methods is all that conducive to creative workflows.

As the Kenton D-Sync has only 3 settings, each with only 2 states...
  - DINsync clock speed (24 or 48 pulses per quarter note)
  - Continue or Start on a MIDI Start signal and
  - a "soft Thru" option that can be switched on or off
...it should be easier to change these in situ, rather than having to rip your D-Sync out of your
synth studio and connect it to your computer.

This is where KentonKontrol comes in, providing a 6 button hardware interface to toggle these
settings via a MIDI connection.

<img width="997" height="538" alt="KentonKontrol" src="https://github.com/user-attachments/assets/7a41825d-5d38-43aa-9407-838eb2d6cf9b" />
