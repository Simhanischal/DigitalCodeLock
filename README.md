# DigitalCodeLock
This is the code for digital code lock using Arduino Uno.

## COMPONENTS USED :
 -> Arduino Uno
 -> 4*4 Keypad Module
 -> Breadboard
 -> LEDs
 -> Buzzer
 
### WORKING : Digital code lock refers to a digital locker which unlocks whenever a correct password is entered in the keypad module.
We have used the serial monitor option in the Arduino IDE to display the password and the state of the lock(LOCKED/UNLOCKED).The password stored is actually stored in the EEPROM of the Arduino. 
    WHenever the lock is in LOCKED position and we enter the right password, the state is changed to UNLOCKED and a green LED glows but when the password entered is incorrect, it remains in the LOCKED state and indicates the password entered is wrong by the beep of Buzzer for specified time and a red LED glows whenever incorrect password is entered.
    
***CODE :
      The code we have written is used to store the original password enttered by the user and also is used to compare the password entered through th keypad module with the passcode stored in the EEPROM of the Arduino. 
