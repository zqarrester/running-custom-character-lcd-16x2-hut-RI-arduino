//----------------------------------
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);           
// select the pins used on the LCD 16x2 panel
//----------------------------------
int Li          = 17;
int Lii         = 1; 
int Ri          = -1;
int Rii         = -1;
//----------------------------------

// for character M
byte hurufm[8]={ 
B10001,
B11011,
B11111,
B11111,
B10101,
B10001,
B10001,
B10001,
};

// for Character E
byte hurufe[8]={ 
B11111,
B11111,
B11000,
B11111,
B11111,
B11000,
B11111,
B11111,
};
    
// for character R 
byte hurufr[8]={ 
B11110,
B11111,
B11001,
B11111,
B11110,
B11111,
B11011,
B11001,
};
    
// For character D
byte hurufd[8]={ 
B11100,
B11110,
B11011,
B11011,
B11011,
B11011,
B11110,
B11100,
};

// for character K
byte hurufk[8]={ 
B11001,
B11011,
B11110,
B11100,
B11100,
B11110,
B11011,
B11001,
};
// For character A
byte hurufa[8]={ 
B01110,
B11111,
B11011,
B11011,
B11111,
B11111,
B11011,
B11011,
};

// For character seru
byte seru[8]={ 
B01110,
B01110,
B01110,
B01110,
B01110,
B00000,
B01110,
B01110,
};
        
void setup()
    {
  
lcd.createChar(0,hurufm);
lcd.createChar(1,hurufe);
lcd.createChar(2,hurufr);
lcd.createChar(3,hurufd);
lcd.createChar(4,hurufk);
lcd.createChar(5,hurufa);
lcd.createChar(6,seru);
    
lcd.begin(16, 2);        
 }
 // start the LCD library
 
void loop(){
  {
    lcd.setCursor(4, 0);
    
//for write text MERDEKA With custom character.
              
lcd.write(byte(0));
 lcd.write(byte(1));
lcd.write(byte(2));
 lcd.write(byte(3));
lcd.write(byte(1));
 lcd.write(byte(4));
lcd.write(byte(5));
 lcd.write(byte(6));


  }
  for (int i = 0; i <= 50; i++) {                                                                         
    lcd.setCursor(0,1);                              
    lcd.print(Scroll_LCD_Left("DIRGAHAYU REPUBLIK INDONESIA KE-75"));   
// So from the start the text appears until the text disappears with a value of 50.
    delay(350);
  }
  Clear_Scroll_LCD_Left();                   
  
  
     Clear_Scroll_LCD_Right();  
  for (int i = 0; i <= 79; i++) {
    lcd.setCursor(0, 1);
    lcd.print(Scroll_LCD_Left("WELCOME TO IBNUWANI OFFICIAL. Like,comment & Subscribe...thanks"));
    delay(350);
  }
Clear_Scroll_LCD_Left();
        
  for (int i = 0; i <= 16; i++) {
    lcd.setCursor(0, 0);
    lcd.print(Scroll_LCD_Right(""));
   }
   
}

//for scrolling left

String Scroll_LCD_Left(String StrDisplay)
{
  String result;
  String StrProcess = "                " + StrDisplay + "                ";
  result = StrProcess.substring(Li,Lii);
  Li++;
  Lii++;
  if (Li>StrProcess.length()){
    Li=16;
    Lii=0;
  }
  return result;
}

void Clear_Scroll_LCD_Left(){
  Li=16;
  Lii=0;
}
    
//For scrolling right

String Scroll_LCD_Right(String StrDisplay){
  String result;
  String StrProcess = "                " + StrDisplay + "                ";
  if (Rii<1){
    Ri  = StrProcess.length();
    Rii = Ri-16;
  }
  result = StrProcess.substring(Rii,Ri);
  Ri--;
  Rii--;
  return result;
}

void Clear_Scroll_LCD_Right(){
  Ri=-1;
  Rii=-1;
}
