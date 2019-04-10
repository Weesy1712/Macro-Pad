/*-------------------------------------------------------------------------------------
 * Sketch written by Karim Tayari
 * It only works with an Arduino Pro Micro, Micro or Leonardo. 
 * You can Personalize this code
 * The Oled display is just for stats
 * Fastest way to find the Right Function-Button : CTRL + F 
 * Then just look for your right layer or button.
 *-------------------------------------------------------------------------------------*/
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Keyboard.h>


// OLED display TWI address
#define OLED_ADDR   0x3C

// reset pin not used on 4-pin OLED module
Adafruit_SSD1306 display(-1);  // -1 = no reset pin

// 128 x 64 pixel display
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

//define macro Buttons
#define btn1 5
#define btn2 4
#define btn3 6
#define btn4 7
#define btn5 8
#define btn6 9
#define btn7 15
#define btn8 14
#define btn9 16
#define btn10 10

//Define description of the buttons 

String str1 = "Home"; //Button 1 
String str2 = "Mute"; //Button 2 
String str3 = "Launcher"; //Button 3 
String str4 = "Tools"; //Button 4 
String str5 = "Record"; //Button 5
String str6 = "Email"; //Button 6
String str7 = "Switch"; //Button 7
String str8 = "New"; //Button 8
String str9 = "Copy"; //Button 9
String str10 = "Paste"; //Button 10


//proof integer 
int layint1 = 0;
int layint2 = 0; 
int layint3 = 0; 
int layint4 = 0;

void setup() {
  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  
  //For the buttons we use INPUT_PULLUP because of the pullup resistor in the arduino
  pinMode(btn1, INPUT_PULLUP);
    pinMode(btn2, INPUT_PULLUP);
      pinMode(btn3, INPUT_PULLUP);
        pinMode(btn4, INPUT_PULLUP);
          pinMode(btn5, INPUT_PULLUP);
            pinMode(btn6, INPUT_PULLUP);
              pinMode(btn7, INPUT_PULLUP);
                pinMode(btn8, INPUT_PULLUP);
                  pinMode(btn9, INPUT_PULLUP);
                    pinMode(btn10, INPUT_PULLUP);

          
//here is the Booting of the OLED
  display.clearDisplay();
  display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(15,20);
  display.print("Hello!");
  display.display(); 
  delay(1000);
  display.clearDisplay();
  display.drawRect(0,0,127,63,WHITE);
  display.setCursor(20,10);
  display.print("Macro");
  display.setCursor(40,35); 
  display.print("Pad");
  display.display();
  delay(500); 
  display.clearDisplay();
  display.drawRect(0,0,127,63,WHITE);
  display.setCursor(20,20);
  display.print("V: 2");
  display.display(); 
  delay(500); 
   display.fillRect(1,1,125,61,BLACK);
   display.display();
   
stand(); 
 
}

void loop() { 
  Keyboard.begin();
  display.clearDisplay();
  
 //you can program every single button with Keyboard.write or keyboard.print

  //Button 2 Action 
  if(digitalRead(btn2) == 0){

     display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print(str2);
  display.display(); 
  
//change code here 
// ******************************************************************************
Keyboard.press(KEY_LEFT_CTRL); 
Keyboard.press('m'); 
delay(100); 
Keyboard.releaseAll(); 


//till here 
// ******************************************************************************
  stand();

  }

  //Button 3 Action (Layout1) 
   if(digitalRead(btn3) == 0 && layint1 == 0 && layint2 == 0 && layint3 ==0 && layint4 == 0){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print(str3);
  display.display(); 
//Change code here
// ******************************************************************************
    layint1 = 1; 
    layer1stand();
 
  
//till here
// ******************************************************************************   
  
  
  }

  //Button 4 Action (Layout2) 
   
   if(digitalRead(btn4) == 0 && layint2 == 0 && layint1 == 0 && layint3 == 0 && layint4 == 0){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print(str4);
  display.display(); 
//Change code here
// ******************************************************************************
    layint2 = 1; 
    layer2stand();
  
//till here
// ******************************************************************************   
  
 
  
  }

  //Button 5 Action (Layout3) 
   
   if(digitalRead(btn5) == 0 && layint3 == 0 && layint1 == 0 && layint2 == 0 && layint4 == 0){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print(str5);
  display.display(); 
//Change code here
// ******************************************************************************
    layint3 = 1; 
    layer3stand();
  
//till here
// ******************************************************************************   
  
  
  
  }

   //Button 6 Action (Layout4) 
   
   if(digitalRead(btn6) == 0 && layint3 == 0 && layint1 == 0 && layint2 == 0 && layint4 == 0){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print(str6);
  display.display(); 
//Change code here
// ******************************************************************************
    layint4 = 1; 
    layer4stand();
  
//till here
// ******************************************************************************   
  
  
  
  }

  
  //Button 7 Action 
  if(digitalRead(btn7) == 0){

     display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print(str7);
  display.display(); 
  
//change code here 
// ******************************************************************************

Keyboard.press(KEY_LEFT_ALT); 
Keyboard.press(KEY_TAB); 
delay(500); 
Keyboard.releaseAll(); 


//till here 
// ******************************************************************************
  stand();
  
  }
  //Button 8 Action 
  if(digitalRead(btn8) == 0){

     display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print(str8);
  display.display(); 
  
// ******************************************************************************  
//change code here 
 
Keyboard.press(KEY_LEFT_CTRL); 
Keyboard.press('n'); 
delay(100); 
Keyboard.releaseAll(); 

//till here 
// ******************************************************************************
  stand();
  
  }
  //Button 9 Action 
  if(digitalRead(btn9) == 0){

     display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print(str9);
  display.display(); 
  
//change code here 
// ******************************************************************************
Keyboard.press(KEY_LEFT_CTRL); 
Keyboard.press('c'); 
delay(100); 
Keyboard.releaseAll();
//till here
// ****************************************************************************** 
  stand();
  
  }
  //Button 10 Action 
  if(digitalRead(btn10) == 0){

     display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print(str10);
  display.display(); 
  
//change code here 
// ******************************************************************************
Keyboard.press(KEY_LEFT_CTRL); 
Keyboard.press('v'); 
delay(100); 
Keyboard.releaseAll();
//till here 
// ******************************************************************************
  stand();
  
  }

  //Layout 1 button 1 Action 
   if(digitalRead(btn3) == 0 && layint1 == 1 ){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print("Steam");
  display.display(); 
//Change code here
// ******************************************************************************
      Keyboard.press(KEY_LEFT_CTRL);
Keyboard.press(KEY_ESC);

delay(100);
Keyboard.releaseAll();
Keyboard.println("Steam"); 
delay(500); 
Keyboard.press(KEY_RETURN);
delay(100);
Keyboard.releaseAll(); 
  
 
  
//till here
// ******************************************************************************   
  
  layer1stand();
   }

 //Layout 1 button 2 Action 
   if(digitalRead(btn4) == 0 && layint1 == 1 ){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print("Battle.net");
  display.display(); 
//Change code here
// ******************************************************************************
     
  Keyboard.press(KEY_LEFT_CTRL);
Keyboard.press(KEY_ESC);

delay(100);
Keyboard.releaseAll();
Keyboard.println("Battle.ne"); 
delay(500); 
Keyboard.press(KEY_RETURN);
delay(100);
Keyboard.releaseAll(); 
  
  
//till here
// ******************************************************************************   
  layer1stand();
   }

 //Layout 1 button 3 Action 
   if(digitalRead(btn5) == 0 && layint1 == 1 ){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print("Origin");
  display.display(); 
//Change code here
// ******************************************************************************
      Keyboard.press(KEY_LEFT_CTRL);
Keyboard.press(KEY_ESC);

delay(100);
Keyboard.releaseAll();
Keyboard.println("Origin"); 
delay(500); 
Keyboard.press(KEY_RETURN);
delay(100);
Keyboard.releaseAll(); 
  
 
  
//till here
// ******************************************************************************   
  
  layer1stand();
   }

 //Layout 1 button 4 Action 
   if(digitalRead(btn6) == 0 && layint1 == 1 ){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print("Uplay");
  display.display(); 
//Change code here
// ******************************************************************************
     
  Keyboard.press(KEY_LEFT_CTRL);
Keyboard.press(KEY_ESC);

delay(100);
Keyboard.releaseAll();
Keyboard.println("Uplay"); 
delay(500); 
Keyboard.press(KEY_RETURN);
delay(100);
Keyboard.releaseAll(); 
  
  
//till here
// ******************************************************************************   
  
  layer1stand();
   }

 //Layout 2 button 1 Action 
   if(digitalRead(btn3) == 0 && layint2 == 1 ){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print("Discord");
  display.display(); 
//Change code here
// ******************************************************************************
     
  Keyboard.press(KEY_LEFT_CTRL);
Keyboard.press(KEY_ESC);

delay(100);
Keyboard.releaseAll();
Keyboard.println("Discord"); 
delay(500); 
Keyboard.press(KEY_RETURN);
delay(100);
Keyboard.releaseAll(); 
  
  
//till here
// ******************************************************************************   
  
  layer2stand();
   }

   //Layout 2 button 2 Action 
   if(digitalRead(btn4) == 0 && layint2 == 1 ){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print("Teamspeak");
  display.display(); 
//Change code here
// ******************************************************************************
     
  Keyboard.press(KEY_LEFT_CTRL);
Keyboard.press(KEY_ESC);

delay(100);
Keyboard.releaseAll();
Keyboard.println("Teamspeak"); 
delay(500); 
Keyboard.press(KEY_RETURN);
delay(100);
Keyboard.releaseAll(); 
  
  
//till here
// ******************************************************************************   
  
  layer2stand();
   }

   //Layout 2 button 3 Action 
   if(digitalRead(btn5) == 0 && layint2 == 1 ){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print("Logitech");
  display.display(); 
//Change code here
// ******************************************************************************
     
  Keyboard.press(KEY_LEFT_CTRL);
Keyboard.press(KEY_ESC);

delay(100);
Keyboard.releaseAll();
Keyboard.println("Logitech"); 
delay(500); 
Keyboard.press(KEY_RETURN);
delay(100);
Keyboard.releaseAll(); 
  
  
//till here
// ******************************************************************************   
  
  layer2stand();
   }

   //Layout 2 button 4 Action 
   if(digitalRead(btn6) == 0 && layint2 == 1 ){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print("GPU-Tweak");
  display.display(); 
//Change code here
// ******************************************************************************
     
  Keyboard.press(KEY_LEFT_CTRL);
Keyboard.press(KEY_ESC);

delay(100);
Keyboard.releaseAll();
Keyboard.println("asus gpu"); 
delay(500); 
Keyboard.press(KEY_RETURN);
delay(100);
Keyboard.releaseAll(); 
  
  
//till here
// ******************************************************************************   
  
  layer2stand();
   }

   //Layout 3 button 1 Action 
   if(digitalRead(btn3) == 0 && layint3 == 1 ){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print("Screen");
  display.display(); 
//Change code here
// ******************************************************************************
     
Keyboard.press(KEY_LEFT_ALT); 
Keyboard.press(KEY_F1); 
delay(100); 
Keyboard.releaseAll(); 

  
//till here
// ******************************************************************************   
  
  layer3stand();
   }

   //Layout 3 button 2 Action 
   if(digitalRead(btn4) == 0 && layint3 == 1 ){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print("Record");
  display.display(); 
//Change code here
// ******************************************************************************
     
Keyboard.press(KEY_LEFT_ALT); 
Keyboard.press(KEY_F9); 
delay(100); 
Keyboard.releaseAll(); 
  
//till here
// ******************************************************************************   
  
  layer3stand();
   }

   //Layout 3 button 3 Action 
   if(digitalRead(btn5) == 0 && layint3 == 1 ){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print("Mic");
  display.display(); 
//Change code here
// ******************************************************************************
Keyboard.press(KEY_LEFT_CTRL);     
Keyboard.press(KEY_LEFT_ALT); 
Keyboard.press('m'); 
delay(100); 
Keyboard.releaseAll(); 
  
//till here
// ******************************************************************************   
  
 layer3stand();
   }

   //Layout 3 button 4 Action 
   if(digitalRead(btn6) == 0 && layint3 == 1 ){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print("Overlay");
  display.display(); 
//Change code here
// ******************************************************************************
     
     
Keyboard.press(KEY_LEFT_ALT); 

Keyboard.press('y'); 
delay(100); 
Keyboard.releaseAll(); 
  
//till here
// ******************************************************************************   
  
 layer3stand();
   }

   
   //Layout 4 button 1 Action 
   if(digitalRead(btn3) == 0 && layint4 == 1 ){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print("mr.moki");
  display.display(); 
//Change code here
// ******************************************************************************
  Keyboard.print("mr.moki111");
 Keyboard.press(KEY_RIGHT_ALT); 
Keyboard.press('q'); 
delay(100); 
Keyboard.releaseAll(); 
Keyboard.print("gmail.com"); 
  
//till here
// ******************************************************************************   
  
 layer4stand();
   }

   //Layout 4 button 2 Action 
   if(digitalRead(btn4) == 0 && layint4 == 1 ){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print("HTL");
  display.display(); 
//Change code here
// ******************************************************************************
     
  Keyboard.print("karim.tazari");
 Keyboard.press(KEY_RIGHT_ALT); 
Keyboard.press('q'); 
delay(100); 
Keyboard.releaseAll(); 
Keyboard.print("htl/klu.at"); 

  
//till here
// ******************************************************************************   
  
 layer4stand();
   }

   //Layout 4 button 3 Action 
   if(digitalRead(btn5) == 0 && layint4 == 1 ){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print("Begin");
  display.display(); 
//Change code here
// ******************************************************************************
     
  Keyboard.print("coc.tazari1");
 Keyboard.press(KEY_RIGHT_ALT); 
Keyboard.press('q'); 
delay(100); 
Keyboard.releaseAll(); 
Keyboard.print("gmail.com"); 
  
//till here
// ******************************************************************************   
  
 layer4stand();
   }

   //Layout 4 button 4 Action 
   if(digitalRead(btn6) == 0 && layint4 == 1 ){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print("Loop");
  display.display(); 
//Change code here
// ******************************************************************************
     Keyboard.press(KEY_LEFT_SHIFT);
 Keyboard.press('q'); 
 delay(100); 
 Keyboard.releaseAll(); 
  
//till here
// ******************************************************************************   
  
 layer4stand();
   }

    //Return Button Action 
   if(digitalRead(btn1) == 0){
    display.fillRect(0,0,127,63,BLACK);
    display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.print(str1);
  display.display(); 
//Change code here
// ******************************************************************************
    layint1 = 0; 
    layint2 = 0; 
    layint3 = 0; 
    layint4 = 0; 
    stand();
 
  
//till here
// ******************************************************************************   
  
  stand(); 
   }
  
Keyboard.end();
}
//This is a Method for the overview 

//Every layer has its own overview 
void stand(){
  
  display.fillRect(0,0,127,63,BLACK);
  display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(2,2); 
  display.print("1: "+ str3);
  display.setCursor(2,12);
  display.print("2: "+ str4);
   display.setCursor(2,22);
  display.print("3: "+str5);
   display.setCursor(2,32);
  display.print("4: "+str6);
   display.setCursor(2,42);
  display.print("5: "+str7);
   display.setCursor(2,52);
  display.print("6: "+str8);
  display.display(); 
  
}

//Layer 1 Overview 
void layer1stand(){
  
  display.fillRect(0,0,127,63,BLACK);
  display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(2,2); 
  display.print("1: Steam");
  display.setCursor(2,12);
  display.print("2: Battle.net");
   display.setCursor(2,22);
  display.print("3: Origin");
   display.setCursor(2,32);
  display.print("4: Uplay");
   
  display.display(); 
  
}

//Layer 2 overview 
void layer2stand(){
  
  display.fillRect(0,0,127,63,BLACK);
  display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(2,2); 
  display.print("1: Discord");
  display.setCursor(2,12);
  display.print("2: Teamspeak 3");
   display.setCursor(2,22);
  display.print("3: Logitech");
   display.setCursor(2,32);
  display.print("4: Asus GPU Tweak 2");
   
  display.display(); 
  
}

//Layer 3 Overview
void layer3stand(){
  
  display.fillRect(0,0,127,63,BLACK);
  display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(2,2); 
  display.print("1: Screenshot");
  display.setCursor(2,12);
  display.print("2: Record Toggle");
   display.setCursor(2,22);
  display.print("3: Mic Toggle");
   display.setCursor(2,32);
  display.print("4: Overlay");
   
  display.display(); 
  
}

//Layer 4 overview 
void layer4stand(){
  
  display.fillRect(0,0,127,63,BLACK);
  display.drawRect(0,0,127,63,WHITE);
  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(2,2); 
  display.print("1: mr.moki111");
  display.setCursor(2,12);
  display.print("2: karim.tayari");
   display.setCursor(2,22);
  display.print("3: coc.tayari1");
   display.setCursor(2,32);
  display.print("4: Frei");
   
  display.display(); 
  
}
