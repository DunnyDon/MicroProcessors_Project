# MicroProcessors_Project
This Arduino code combines the input of an LED matrix to the output of a Floppy Drive

Requirements:
  1. Arduino Board (MEGA ADK was used as it has numerous pins on the board)
  2. Floppy Drive
  3. Ribbon Cable
  4. Arduino Libraries (See Code)

Description:
  The input, an LED Matrix, defines and changes the output of the Floppy Drive. The noise outputted from the floppy drive can be changed by altering the speed of the motor in the floppy drive. The speed was calculated based on a value passed from the LED Matrix. The LED Matrix consisted of a light 'bouncing' around and the value passed to the Floppy drive is calculated based on where the LED hits one of the x/y axises
  
  Please Note:
  
  Apologies for the redundant code. This is an old project and needs to be tidied up. I also can not claim responsibilty for the functions which print out the smiley face or the number 17 along with the formula defined in the pitch function. I did write the code and debug that function along with the rest of the project.
