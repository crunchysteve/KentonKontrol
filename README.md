## KentonKontrol - A MIDI Sysex Command Sender for the Kenton D-Sync

The Kenton D-Sync is a bi-directional MIDI to DIN Sync Converter, with 3 user settable parameters. 
These parameters are, by default, changed by connecting a computer or phone to a MIDI interface and 
transmitting raw sysex messages from a laptop, via either the [Kenton web app](https://kentonuk.com/apps/dsync-config) or a terminal connection.
Neither of these methods is all that conducive to creative workflows.

<img width="530" height="286" alt="D-Sync" src="https://github.com/user-attachments/assets/2ff9496b-d236-4cbb-b01c-f4c8d14205c1" />

As the Kenton D-Sync has only 3 settings, each with only 2 states...
  - DINsync clock speed (24 or 48 pulses per quarter note)
  - Continue or Start on a DIN sinal start and  (<-- this feature is especially useful for when there's a tacit in a piece)
  - a "soft Thru" option that can be switched on or off
...it should be easier to change these in situ, rather than having to rip your D-Sync out of your
synth studio and connect it to your computer.

This is where KentonKontrol comes in, providing a 6 button hardware interface to toggle these
settings via a MIDI connection.

<img width="997" height="538" alt="KentonKontrol" src="https://github.com/user-attachments/assets/7a41825d-5d38-43aa-9407-838eb2d6cf9b" />
Prototype PCB fritzing layout.

### What could be improved and what is done
At this stage, while it's verified working, it's not been extensively tested. The simple, readable code is thanks to the Surface Control library. There are 8 buttons in total of 8 buttons, Reset, Restore Defaults, Set DIN48, Set DIN24, Set Start, Set Cont (continue), Set No Thru and Set (soft) Thru. The Fritzing file needs the breadboard and circuit diagram cleaned up, and the PCB could probably use a rearrangement to have the MIDI sockets to the rear.

### The Code
After including Control_Surface.h, a Serial MIDI interface is initiated. Then the D-Sync sysex strings are declared as arrays, named for each function they perform. Next, we instntiate 7 of the 8 buttons (reset exists inherently on an arduino microcontroller and has a dedicated pin), using the Button method, giving each a name and assigning it to a pin. In the setup() function, we start the Control_Surface monitor with the .begin method. As each button is pressed, the falling edge is detected and the midi.sendSysex method queues the chosen command for the next midi.update()

In total, there are 27 lines of easily read code. 

Practical operation has little feedback, relying on the single LED on the D-Sync itself to give feedback on whether it has received a sysex message. A clock speed of 24 has the LED showing green, setting a clock speed of 48 turns the LED red. Other functions quickly flicker the LED as the command loads, showing a yellow light. Soft thru can be tested by playing some nots from a master MIDI controller like a synth or piano keyboard. Playing from the start or from the current song position point can be tested by hitting the master clock device's stop/start button - stop playing, hit play again, and, if set to continue, the song will play from where it was stopped, otherwise, play will pressing play will start the song from the beginning.
