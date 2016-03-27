/*
Morse Translator v0.1 beta
 
Copyright 2016 boozeCoder under MIT license.
*/

//This is the the on-board test LED (labelled 'L')
//that is connected to pin 13.
char pinToLight = 13;

//Length of the dit/dot 100ms
int ditLength = 100;

//Length of dah/dash is 3 times the length of
//a dit/dot.
int dahLength = ditLength * 3;

//The time between letters in Morse code the
//same length as a dit/dot. We don't need this,
//it wastes 2bytes of memory but it helps for 
//clarification of the functioning we are trying
//to mimic.
int letterSpace = ditLength;

//The wait length between words is the length of a
//dit/dot times 7, however since we the letterSpace
//happens after each letter that counts as the first
//and all we need is 6 more.
int wordSpace = ditLength * 6;

//This is our own made up blink to represent characters
//that aren't a letter of the alphabet or a space.
//Example: $@!^$#&()-_+={}|'" etc...
int specialChar = ditLength * 5;

//The string to translate to morse.
//99 CHARACTERS MAX!!!!!!!!!!
char ourMessage[100] = "sos !sos!";

//Here is the function to blink the light for the
//specified length then turn of for the length of
//a dit/dot.
void makeBlink(int blinkLength)  
{
  digitalWrite(pinToLight, HIGH);
  delay(blinkLength);
  digitalWrite(pinToLight, LOW);
  delay(letterSpace);
}

//This just pauses the light for the length of a wordspace.
void spaceBar()
{
  delay(wordSpace);
}

//This is our function that filters the character
//into either a lowecase, space or special character.
char filterCharacter(char currentChar)
{
  
  //97 is ascii value for a and 122 ascii value for z.
  //This if statement checks to see if its in the range
  //for the lowercase.
  if(currentChar >= 97 && currentChar <= 122)
  {
    currentChar += 0;
  }
  
  //This range is for Capital letters.
  else if(currentChar >= 65 && currentChar <= 90)
  {
    currentChar += 32;  //Adds 32 to get the lowercase.
  }
  
  //Checks for a space. Space is character 32 not to
  //be confused with the 32 above.  That is the lowercase
  //letters are 32 values higher than the capital letters
  //the 32's arte not related, just pure coincidence.
  else if(currentChar == 32)
  {
    currentChar = 32;    
  }
  
  //Or else its a special character.
  else
  {
    currentChar = 0;
  }
  return currentChar;
}

//This is my hurried method of making a functioning
//translator... It's ugly and I'm not proud of it, but it
//works. It's pretty self explanatory, lots of repitition.
void makeMorseLetter(char letterToConvert)
{
  switch(letterToConvert)
  {
    case 97:    //a
      makeBlink(ditLength);
      makeBlink(dahLength);
      break;
    case 98:    //b
      makeBlink(dahLength);
      makeBlink(ditLength);
      makeBlink(ditLength);
      makeBlink(ditLength);
      break;
    case 99:     //c
      makeBlink(dahLength);
      makeBlink(ditLength);
      makeBlink(dahLength);
      makeBlink(ditLength);
      break;
    case 100:    //d
      makeBlink(dahLength);
      makeBlink(ditLength);
      makeBlink(ditLength);
      break;
    case 101:    //e
      makeBlink(ditLength);
      break;
    case 102:    //f
      makeBlink(ditLength);
      makeBlink(ditLength);
      makeBlink(dahLength);
      makeBlink(ditLength);
      break;
    case 103:    //g
      makeBlink(dahLength);
      makeBlink(dahLength);
      makeBlink(ditLength);
      break;
    case 104:    //h
      makeBlink(ditLength);
      makeBlink(ditLength);
      makeBlink(ditLength);
      makeBlink(ditLength);
      break;
    case 105:    //i
      makeBlink(ditLength);
      makeBlink(ditLength);
      break;
    case 106:    //j
      makeBlink(ditLength);
      makeBlink(dahLength);
      makeBlink(dahLength);
      makeBlink(dahLength);
      break;
    case 107:    //k
      makeBlink(dahLength);
      makeBlink(ditLength);
      makeBlink(dahLength);
      break;
    case 108:    //l
      makeBlink(ditLength);
      makeBlink(dahLength);
      makeBlink(ditLength);
      makeBlink(ditLength);
      break;
    case 109:    //m
      makeBlink(dahLength);
      makeBlink(dahLength);
      break;
    case 110:    //n
      makeBlink(dahLength);
      makeBlink(ditLength);
      break;
    case 111:    //o
      makeBlink(dahLength);
      makeBlink(dahLength);
      makeBlink(dahLength);
        break;
    case 112:    //p
      makeBlink(ditLength);
      makeBlink(dahLength);
      makeBlink(dahLength);
      makeBlink(ditLength);
      break;
    case 113:    //q
      makeBlink(dahLength);
      makeBlink(dahLength);
      makeBlink(ditLength);
      makeBlink(dahLength);
      break;
    case 114:    //r
      makeBlink(ditLength);
      makeBlink(dahLength);
      makeBlink(ditLength);
      break;
    case 115:    //s
      makeBlink(ditLength);
      makeBlink(ditLength);
      makeBlink(ditLength);
      break;
    case 116:    //t
      makeBlink(dahLength);
      break;
    case 117:    //u
      makeBlink(ditLength);
      makeBlink(ditLength);
      makeBlink(dahLength);
      break;
    case 118:    //v
      makeBlink(ditLength);
      makeBlink(ditLength);
      makeBlink(ditLength);
      makeBlink(dahLength);
      break;
    case 119:    //w
      makeBlink(ditLength);
      makeBlink(dahLength);
      makeBlink(dahLength);
      break;
    case 120:    //x
      makeBlink(dahLength);
      makeBlink(ditLength);
      makeBlink(ditLength);
      makeBlink(dahLength);
      break;
    case 121:    //y
      makeBlink(dahLength);
      makeBlink(ditLength);
      makeBlink(dahLength);
      makeBlink(dahLength);
      break;
    case 122:    //z
      makeBlink(dahLength);
      makeBlink(dahLength);
      makeBlink(ditLength);
      makeBlink(ditLength);
      break;
    case 32:     //a space
      spaceBar();
      break;
    default:    //special character.
      makeBlink(specialChar);
  }
}

//This function is for Bringing the whole message together.
//It translates the characters until it reaches a null byte.
void makeMorseMessage()
{
  for(char letter = 0;letter < sizeof(ourMessage);letter++)
  {
    char thisLetter = ourMessage[letter];
    if((thisLetter + 0) != 0)
    {
      thisLetter = filterCharacter(thisLetter);
      makeMorseLetter(thisLetter);
    }
    else
    {
      break;
    }
  }
}

void setup()
{
  pinMode(pinToLight, OUTPUT);
}
void loop()
{
  makeMorseMessage();
  delay(2000);
}
