## KentonKontrol v1.0

KentonKontrol is a third-party MIDI Sysex tool for the Kenton D-Link MIDI DinSync interface. 
See:- [kentonuk.com/product/d-sync/](http://kentonuk.com/product/d-sync/)

The D-Sync has 3 settings, changeable via MIDI system exclusive messages...
    1. DIN Sync clock, 24 or 48 pulses per quarter note. The default is 24
       The KentonKontrol has a button for each clock speed, Pressing one sends a
       MIDI Sysex message to the D-Sync setting the desired clock standard, 
    2. It's default MIDI START message is CONT (continue) but there is a button
       for each, setting the D-Sync to your preferred START or CONT message, 
    3. There is aslso a pair of buttons to set The MIDI "soft thru" feature
       to on or off.

When one of these buttons is pressed, the appropriate System Exclusive message is sent via
a MIDI connection to the D-Sync, changing the D-Sync's operation mode for that parameter.

While Kenton provide a web app for this purpose but it's not really convenient to rip the 
device out of its "pozzi" in the studio to change a setting. So, using the sysex information 
in the D-Sync manual, I created KentonKontrol, a box that can sit next to the D-Sync and a 
MIDI merge device (such as my CME U6MIDI Pro router), taking either MIDI sync from my drum 
machine or sysex commands from KentonKontrol.

This firmware is confirmed compatible with Arduino Nano R3 and R4, I haven't run it on any 
other 'Duino boards. Your mileage may vary. It uses the Control Surface library, available 
from the Arduino Library Manager or via the repo at... 
    https://github.com/tttapa/Control-Surface 

Use of my code or design for training commercial large language models is strictly 
forbidden, as is commercial manufacture of devices based wholy on my code. This licence 
condition does not apply to any libraries or systems used in the creation of these designs 
and code. Non-commercial, non-AI use is allowed under an MIT Licence. As I live in 
Australia, where copyright law does not allow me to waive my moral copyright, I remain 
the owner of this work insofar as the components created by me are concerned, other's moral 
rights may apply in regard to the owners of tools used in the creation of this work, such 
as information, media, libraries, IDEs or CAD software and the components, plugins and 
extensions, thereof. I make no claim on any rights of these third parties.`
