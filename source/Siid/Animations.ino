// #### ANIMATIONS ####
enum Animation_enum {LOOKING, SADNESS, EXCITEMENT, JOY, ANGER, FEAR, DISGUST}; // all possible animations of the robot

// ### DEFINITION ###
#define LOOKING_TIME_OUT 800
#define JOY_SERVO_TIME_OUT 200
#define DISGUST_SERVO_TIME_OUT 150
#define JOY_EYE_TIME_OUT 6500
#define SAD_SERVO_TIME_OUT 1500
#define FEAR_SERVO_TIME_OUT 2000

byte current_animation; // current aniamtion of the robot
bool first_time_animation;

// #### TIME ####
unsigned long initial_animation_time;
unsigned long timer_anim_sad;
unsigned long timer_anim1;
unsigned long timer_anim2;
unsigned long timer_anim3;
unsigned long timer_anim4;
unsigned long timer_anim5;
unsigned long timer_anim6;
unsigned long timer_anim7;
bool  case_anim1;
bool  case_anim2;
bool  case_anim3;
bool  case_anim4;
bool  case_anim5;
bool  case_anim6;
bool  case_anim7;

void playAnimation() {
    switch (current_animation) {
        case LOOKING:
            /* LOOKING
            *  Here the robot is moving the eye left and right
            *  Internal petals are closed
            *  External petals are open
            */
            if(first_time_animation){
                first_time_animation = false;
                #if defined(DEVMODE)
                    Serial.print("Animation: ");
                    Serial.println("LOOKING");
                #endif
                sphereLooking();
                setEye(LOOKING);
            }
            else {
                showEyeAnimation();
            }
            break;
        case SADNESS:
            /* SADNESS
            * Open and semi-close petals very slowly
            * Eye with sad patterns
            * Make sound from a set of sad sounds
            * Sphere of blue colors
            */

            if(first_time_animation){
              first_time_animation = false;
              timer_anim1 = millis() - SAD_SERVO_TIME_OUT;
              case_anim1 = true; 
 
              sphereSadness();
              playAudio(SADNESS);
              setEye(SADNESS);

              #if defined(DEVMODE)
                Serial.print("Animation: ");
                Serial.println("SADNESS");
              #endif
            }
            else {
                showEyeAnimation();

                if(millis() - timer_anim1 >= SAD_SERVO_TIME_OUT && case_anim1) {
                    moveServo(0); 
                    case_anim1 = false;
                    case_anim2 = true;
                    timer_anim2 = millis();
                }
                else if (millis() - timer_anim2 >= SAD_SERVO_TIME_OUT && case_anim2){
                    moveServo(45);
                    case_anim2 = false;
                    case_anim3 = true;
                    timer_anim3 = millis();
                }
                else if (millis() - timer_anim3 >= SAD_SERVO_TIME_OUT && case_anim3){
                    moveServo(0);
                    case_anim3 = false;
                    case_anim4 = true;
                    timer_anim4 = millis();
                }
                else if (millis() - timer_anim4 >= SAD_SERVO_TIME_OUT && case_anim4){
                    moveServo(30);
                    case_anim4 = false;
                    case_anim1 = true;
                    timer_anim1 = millis();
                }
            }
            break;
        case EXCITEMENT:
            /* EXCITEMENT
            * 
            */
             if(first_time_animation){
                first_time_animation = false;
                #if defined(DEVMODE)
                    Serial.print("Animation: ");
                    Serial.println("EXCITEMENT");
                #endif
                shpereExcitement();
                setEye(EXCITEMENT);
            }
            else {
                showEyeAnimation();
            }
            break;
        case JOY:
            /* JOY
            *  Open and close rapidly internal
            *  Make a random sound from a set of happy sounds
            *  Eye with happy patterns
            *  Sphere with bright colors
            */
            
            if(first_time_animation){
                first_time_animation = false;
                timer_anim1 = millis() - JOY_SERVO_TIME_OUT;
                case_anim1 = true; 

                sphereJoy();
                playAudio(JOY);
                setEye(JOY);
 
              
                #if defined(DEVMODE)
                    Serial.print("Animation: ");
                    Serial.println("JOY");
                #endif           
            }
            else {
                showEyeAnimation();

                if(millis() - timer_anim1 >= JOY_SERVO_TIME_OUT && case_anim1) {
                    moveServo(45); 
                    case_anim1 = false;
                    case_anim2 = true;
                    timer_anim2 = millis();
                }
                else if (millis() - timer_anim2 >= JOY_SERVO_TIME_OUT && case_anim2){
                    moveServo(15);
                    case_anim2 = false;
                    case_anim3 = true;
                    timer_anim3 = millis();
                }
                else if (millis() - timer_anim3 >= JOY_SERVO_TIME_OUT && case_anim3){
                    moveServo(85);
                    case_anim3 = false;
                    case_anim4 = true;
                    timer_anim4 = millis();
                }
                else if (millis() - timer_anim4 >= JOY_SERVO_TIME_OUT && case_anim4){
                    moveServo(5);
                    case_anim4 = false;
                    case_anim1 = true;
                    timer_anim1 = millis();
                }  
            }
            break;
        case ANGER:
            /* ANGER
            * 
            */
            
            #if defined(DEVMODE)
                Serial.print("Animation: ");
                Serial.println("ANGER");
            #endif
            break;
        
        case FEAR:
            /* FEAR
            * Closed and semi-open petals: internal petals closed and 
            * external open; all petals closed
            * Eye with fear patterns
            * Make sound from a set of fear sounds
            * Sphere of violet colors
            */
            /*
            if(first_time_animation){
              first_time_animation = false;
               #if defined(DEVMODE)
                    Serial.print("Animation: ");
                    Serial.println("FEAR");
                #endif
              sphereFear();
              moveServo(0);
              if(millis() - initial_animation_time > FEAR_SERVO_TIME_OUT){
                moveServo(60);
                 showEyeAnimation(); 
              }
            } 
            */
            break;
        case DISGUST:
            /* DISGUST
            *  Open and semi-closed petals
            *  Eye with disgust patterns
            *  Make sound from a set of disgust sounds
            *  Sphere of green colors
            */
            /*
            if(first_time_animation){
              first_time_animation = false;
              #if defined(DEVMODE)
                Serial.print("Animation: ");
                Serial.println("DISGUST");
                #endif 
              
              moveServo(0);
              if(millis() - initial_animation_time > DISGUST_SERVO_TIME_OUT){
                moveServo(60);
                sphereDisgust();
                showEyeAnimation();
              }             
            }  
            */               
            break;
        default:
            break;
    }
}

void setupAnimation(){
    initial_animation_time = millis();
    current_animation = LOOKING;
    first_time_animation = true;
}

void setAnimation(byte animation) {
    current_animation = animation;
    first_time_animation = true;
    initial_animation_time = millis();
    case_anim1 = false;
    case_anim2 = false;
    case_anim3 = false;
    case_anim4 = false;
    case_anim5 = false;
    case_anim6 = false;
    case_anim7 = false;
}

