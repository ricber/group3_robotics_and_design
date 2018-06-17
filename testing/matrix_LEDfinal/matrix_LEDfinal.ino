#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_GFX.h>

//we define the pin that our NeoPixel panel is plugged into
#define PIN 2

//define constants 
int DELAY_EYE = 1; // in ms

//define variables
int emotion_prec=0; //we define it on neutral
int emot=0;

//we initialize our 8×8 matrix using the NeoMatrix library
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
  NEO_MATRIX_BOTTOM + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB + NEO_KHZ800);

struct RGB {
  byte r;
  byte g;
  byte b;
};

typedef struct Eye_ { int v1; int v2; int v3; int v4; int v5; int v6; int v7; int v8;} Eye; // some struct


 
// Define some colors we'll use frequently
RGB vanillia = { 225, 246, 201 }; //neutral 254,254,226

RGB red1 = { 255, 201, 177 };
RGB red2 = { 255, 145, 133 };
RGB red3 = { 255, 112, 97 };
RGB red4 = { 254, 27, 0 }; // angry

RGB yellow1= { 255, 240, 183 };
RGB yellow2= { 255, 236, 143 };
RGB yellow3= { 255, 231, 113 };
RGB yellow4= { 255, 215, 0 }; //happy

RGB blue1 = { 180, 254, 198 };
RGB blue2 = { 137, 224, 255 };
RGB blue3 = { 91, 212, 255 };
RGB blue4 = { 0, 176, 240 }; //sadness

RGB green1 = {189, 224, 128};
RGB green2 = {180, 214, 86 };
RGB green3 = {159, 198 , 48 };
RGB green4 = {112, 141, 35 }; //disgust

RGB purple1 = { 221, 175, 255 };
RGB purple2 = { 165, 45, 255 };
RGB purple3 = { 136, 0, 238 };
RGB purple4 = { 75, 0, 130 }; //fair

RGB off = { 0, 0, 0 };


//define emotions
bool const angry3[8][8] = {  // The first 2 matrix are the same as sadness1 and sadness2
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {1, 1, 0, 0, 0, 0, 1, 1},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {0, 0, 1, 1, 1, 1, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}
            };
bool const angry4[8][8] = {  
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 1, 0, 0, 0, 0, 1, 0},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {0, 0, 1, 0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}
            };

  bool const happy1[8][8] = {  
             {0, 0, 1, 1, 1, 1, 0, 0},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
            };
  bool const happy2 [8][8] = {  
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 1, 1, 1, 1, 0, 0},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
            };        
  bool const happy3 [8][8] = {  
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 1, 1, 1, 1, 0, 0},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {1, 0, 0, 0, 0, 0, 0, 1},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
            };         
  bool const happy4[8][8] = {  
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 1, 1, 1, 1, 0, 0},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {1, 1, 0, 0, 0, 0, 1, 1},
             {1, 0, 0, 0, 0, 0, 0, 1},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}
            };

  bool const sadness1[8][8] = {  
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {0, 0, 1, 1, 1, 1, 0, 0}
            };

  bool const sadness2[8][8] = {  
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {0, 0, 1, 1, 1, 1, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}
            };
  bool const sadness3[8][8] = {  
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {1, 0, 0, 0, 0, 0, 0, 1},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {0, 0, 1, 1, 1, 1, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}
            };
            
  bool const sadness4[8][8] = {  
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {1, 0, 0, 0, 0, 0, 0, 1},
             {1, 1, 0, 0, 0, 0, 1, 1},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {0, 0, 1, 1, 1, 1, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
            };

  bool const fear3[8][8] = {  // the first and second matric correspond to neutral2 and neutral3
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {1, 1, 0, 0, 0, 0, 1, 1},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {1, 1, 0, 0, 0, 0, 1, 1},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}
            };

  bool const fear4[8][8] = {  
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 1, 0, 0, 0, 0, 1, 0},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {0, 1, 0, 0, 0, 0, 1, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}
            };


  bool const disgust4[8][8] = {        // TO DEFINE
             {0, 1, 0, 0, 0, 0, 1, 0},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {0, 0, 1, 0, 0, 1, 0, 0},
             {0, 0, 1, 0, 0, 1, 0, 0},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {0, 1, 0, 0, 0, 0, 1, 0}
            };
            
  bool const disgust3[8][8] = {        // TO DEFINE
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0, 1, 0, 0},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {0, 0, 1, 0, 0, 1, 0, 0},
             {0, 0, 1, 0, 0, 1, 0, 0},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {0, 0, 1, 0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}
            };
  bool const disgust2[8][8] = {        // TO DEFINE
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 0, 0, 0},
            {0, 0, 1, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 1, 0, 0},
            {0, 0, 0, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0}
            };
   bool const disgust1[8][8] = {  
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 1, 1, 0, 0, 0},
             {0, 0, 0, 1, 1, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}
            };

   bool const neutral1[8][8] = {  
             {0, 0, 1, 1, 1, 1, 0, 0},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {0, 0, 1, 1, 1, 1, 0, 0}
            };

   bool const neutral2[8][8] = {  
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {0, 1, 1, 1, 1, 1, 1, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}
            };

   bool const neutral3[8][8] = {  
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {1, 1, 1, 0, 0, 1, 1, 1},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}
            };

    bool const neutral4[8][8] = {  
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {1, 1, 1, 1, 1, 1, 1, 1},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}
            };   

            
   bool const turned_off[8][8] = {  
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}
            };



// Check the pixel one after another and fill them if necessary
void drawEye(bool eye[8][8], RGB color) {
  for(uint16_t row=0; row < 8; row++) {
    for(uint16_t column=0; column < 8; column++) {
      if (eye[row][column] == 1) { 
          matrix.drawPixel(column, row, matrix.Color(color.r, color.g, color.b));
          matrix.show();
        }
      else
      {
          matrix.drawPixel(column, row, matrix.Color(0, 0, 0));
          matrix.show();
      }
    }
  }
}

void eyesInlight(int emotion)
{
  /*##########
   * 0 neutral
   * 1 happy
   * 2 angry
   * 3 sadness
   * 4 fear
   * 5 disgust
   ##########*/
  if (emotion!=emotion_prec) { 
     switch(emotion_prec) {
        case 0:
          drawEye(neutral1, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral2, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral3, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral4, vanillia);
          delay(DELAY_EYE);
          drawEye(turned_off, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral4, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral3, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral2, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral1, vanillia);
          break;
          
        case 1:
          drawEye(happy4, yellow4);
          delay(DELAY_EYE);
          drawEye(happy3, yellow3);
          delay(DELAY_EYE);
          drawEye(happy2, yellow2);
          delay(DELAY_EYE);
          drawEye(happy1, yellow1);
          delay(DELAY_EYE);
          drawEye(neutral1, vanillia);
          delay(DELAY_EYE);
          break;
          
        case 2:
          drawEye(angry4, red4);
          delay(DELAY_EYE);
          drawEye(angry3, red3);
          delay(DELAY_EYE);
          drawEye(sadness2, red2);
          delay(DELAY_EYE);
          drawEye(sadness1, red1);
          delay(DELAY_EYE);
          drawEye(neutral1, vanillia);
          delay(DELAY_EYE);
          break;
          
        case 3:
          drawEye(sadness4, blue4);
          delay(DELAY_EYE);
          drawEye(sadness3, blue3);
          delay(DELAY_EYE);
          drawEye(sadness2, blue2);
          delay(DELAY_EYE);
          drawEye(sadness1, blue1);
          delay(DELAY_EYE);
          drawEye(neutral1, vanillia);
          delay(DELAY_EYE);
          break;
          
        case 4:
          drawEye(fear4, purple4);
          delay(DELAY_EYE);
          drawEye(fear3, purple3);
          delay(DELAY_EYE);
          drawEye(neutral3, purple2);
          delay(DELAY_EYE);
          drawEye(neutral2, purple1);
          delay(DELAY_EYE);
          drawEye(neutral1, vanillia);
          delay(DELAY_EYE);            
          break;
          
        case 5:
          drawEye(disgust4,green4);
          delay(DELAY_EYE);
          drawEye(disgust3,green3);
          delay(DELAY_EYE);
          drawEye(disgust2,green2);
          delay(DELAY_EYE);
          drawEye(disgust1,green1);
          delay(DELAY_EYE);
          drawEye(neutral1, vanillia);
          delay(DELAY_EYE);                 
          break;
          
        default:
          drawEye(turned_off, vanillia);                
          break;
     }
 
    switch(emotion) {
        case 0:
          drawEye(neutral1, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral2, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral3, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral4, vanillia);
          delay(DELAY_EYE);
          drawEye(turned_off, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral4, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral3, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral2, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral1, vanillia);
          break;
          
        case 1:
          drawEye(neutral1, vanillia);
          delay(DELAY_EYE);
          drawEye(happy1, yellow1);
          delay(DELAY_EYE);
          drawEye(happy2, yellow2);
          delay(DELAY_EYE);
          drawEye(happy3, yellow3);
          delay(DELAY_EYE);
          drawEye(happy4, yellow4);
          delay(DELAY_EYE);
          break;
          
        case 2:
          drawEye(neutral1, vanillia);
          delay(DELAY_EYE);
          drawEye(sadness1, red1);
          delay(DELAY_EYE);
          drawEye(sadness2, red2);
          delay(DELAY_EYE);
          drawEye(angry3, red3);
          delay(DELAY_EYE);
          drawEye(angry4, red4);
          delay(DELAY_EYE);
          break;
          
        case 3:
          drawEye(neutral1, vanillia);
          delay(DELAY_EYE);
          drawEye(sadness1, blue1);
          delay(DELAY_EYE);
          drawEye(sadness2, blue2);
          delay(DELAY_EYE);
          drawEye(sadness3, blue3);
          delay(DELAY_EYE);
          drawEye(sadness4, blue4);
          delay(DELAY_EYE);
          break;
          
        case 4:
          drawEye(neutral1, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral2, purple1);
          delay(DELAY_EYE);
          drawEye(neutral3, purple2);
          delay(DELAY_EYE);
          drawEye(fear3, purple3);
          delay(DELAY_EYE);
          drawEye(fear4, purple4);
          delay(DELAY_EYE);
          break;
          
        case 5:
          drawEye(neutral1, vanillia);
          delay(DELAY_EYE); 
          drawEye(disgust1,green1);
          delay(DELAY_EYE);
          drawEye(disgust2,green2);
          delay(DELAY_EYE);
          drawEye(disgust3,green3);
          delay(DELAY_EYE);
          drawEye(disgust4,green4);
          delay(DELAY_EYE);   
          break;
          
        default:
          drawEye(turned_off, vanillia);                
          break;
       }
       emotion_prec=emotion;
       Serial.println(emotion_prec);
  
     }
  
   else
     {
       switch(emotion) {
        case 0:
          drawEye(neutral1, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral2, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral3, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral4, vanillia);
          delay(DELAY_EYE);
          drawEye(turned_off, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral4, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral3, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral2, vanillia);
          delay(DELAY_EYE);
          drawEye(neutral1, vanillia);
          emotion_prec=emotion;  
          break;
          
        case 1:
          drawEye(happy4, yellow4);
          emotion_prec=emotion;
          break;
          
        case 2:
          drawEye(angry4, red4);
          emotion_prec=emotion;
          break;
          
        case 3:
          drawEye(sadness4, blue4);
          emotion_prec=emotion;
          break;
          
        case 4:
          drawEye(fear4, purple4);
          emotion_prec=emotion;  
          break;
          
        case 5:
          drawEye(disgust4, green4);
          emotion_prec=emotion;
          break;
          
        default:
          drawEye(turned_off, vanillia);            
          break;
       }
     }
    
}    


void setup() {
  //we initialize the matrix and configure its pixel brightness, text color and text wrapping options
  matrix.begin();
  matrix.setBrightness(5);
  matrix.setTextColor( matrix.Color(255, 255, 255) );
  matrix.setTextWrap(false);

  /* TO TEST the consumption of the matrix with all LED turned on I used the following instructions
   *  matrix.fillScreen(matrix.Color(red.r, red.g, red.b));
   *  matrix.show();
  */

}

void loop() {
 for (int i=0; i<5; i++)
  {
     eyesInlight(0);
     delay(8*DELAY_EYE); //time to let the programm fully do the animation
     delay(1500);//to let time before changing
  }
 for (int i=0; i<5; i++)
  {
     eyesInlight(1);
     delay(8*DELAY_EYE); //time to let the programm fully do the animation
     delay(1500);//to let time before changing
  }
  for (int i=0; i<5; i++)
  {
     eyesInlight(3);
     delay(8*DELAY_EYE); //time to let the programm fully do the animation
     delay(1500);//to let time before changing
  }
  for (int i=0; i<5; i++)
  {
     eyesInlight(5);
     delay(8*DELAY_EYE); //time to let the programm fully do the animation
     delay(1500);//to let time before changing
  }
  for (int i=0; i<5; i++)
  {
     eyesInlight(4);
     delay(8*DELAY_EYE); //time to let the programm fully do the animation
     delay(1500);//to let time before changing
  }
  for (int i=0; i<5; i++)
  {
     eyesInlight(0);
     delay(8*DELAY_EYE); //time to let the programm fully do the animation
     delay(1500);//to let time before changing
  }
  for (int i=0; i<5; i++)
  {
     eyesInlight(5);
     delay(8*DELAY_EYE); //time to let the programm fully do the animation
     delay(1500);//to let time before changing
  }
  
  
}