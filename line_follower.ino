//**** Documenation Section **********
//This is the program for line_follower_bot
//Author : Harshit Srivastava
// Date : 23rd Jan 2017

/* pin on Arduino generates signal which goes to Motor_Driver to 
 *  change the direction of rotation of motor of the robot. 
 */
#define rigthWheel_Front 6  
#define rigthWheel_Back 5
#define leftWheel_Front 4
#define leftWheel_Back 3

/* pin on Arduino to read the value of IR_sensor_modules 
 *  on the Line_follower robot reading Will be integer value
 *  lie in range of 0 ~ 1023.
 */
 // A1 , A2 , A3 are the analog input pin on Arduino
 
#define irSensor_1 A1 
#define irSensor_2 A2
#define irSensor_3 A3

// threshold value to differenciate between black line and other part of the surface
// Value threshold should be change accordingly depending on the track.
#define threshold 500

// variable to store the values genetated by IR_SENSOR_MODULES attached to the robot
volatile int IRsens_val_1;
volatile int IRsens_val_2;
volatile int IRsens_val_3;

//  subroutine section

void setup() {
  // put your setup code here, to run once:
  // By default the pin are off so we have to set value on control register to switch it on
  
  pinMode(rigthWheel_Front ,OUTPUT); // sets the value on register so that GPIO acts as output pin
  pinMode(rigthWheel_Back ,OUTPUT);  
  pinMode(leftWheel_Front ,OUTPUT);  
  pinMode(leftWheel_Back ,OUTPUT);

  pinMode(irSensor_1 , INPUT);// set the value of the register so that the GPIO acts as input pin
  pinMode(irSensor_2 , INPUT);
  pinMode(irSensor_3 , INPUT);
      
 IRsens_val_1 = analogRead(irSensor_1 ); // reads the value and stores in volatile int Variable 
 IRsens_val_2 = analogRead(irSensor_2 );
 IRsens_val_3 = analogRead(irSensor_3 );  
 
}

void loop() {
  // put your main code here, to run repeatedly:
 if ( IRsens_val_1 < threshold && IRsens_val_2 > threshold && IRsens_val_3 < threshold  )
 {
    // vehical is aligned with the black line 
    // robot has to move forward
    digitalWrite(rigthWheel_Front , HIGH );
    digitalWrite(rigthWheel_Back , LOW );
    digitalWrite(leftWheel_Front ,HIGH);
    digitalWrite(leftWheel_Back , LOW);

      delay(100);
  }

  else if (IRsens_val_1 > threshold && IRsens_val_2 < threshold && IRsens_val_3 < threshold  )
  {
    // vehical is deviated rightwards from the line
    // robot needs to move leftwards to align itself with line
    digitalWrite(rigthWheel_Front , HIGH );
    digitalWrite(rigthWheel_Back , LOW );
    digitalWrite(leftWheel_Front ,LOW);
    digitalWrite(leftWheel_Back , HIGH);

    delay(100);
    
    }

  else if  ( IRsens_val_1 < threshold && IRsens_val_2 < threshold && IRsens_val_3 > threshold  )
  {
    // vehical is deviated leftwards from the line
    // robot needs to move rightwards to align itself with the line
    
    digitalWrite(rigthWheel_Front , LOW );
    digitalWrite(rigthWheel_Back , HIGH );
    digitalWrite(leftWheel_Front ,HIGH);
    digitalWrite(leftWheel_Back , LOW);

    delay(100);
    }

    else if ( IRsens_val_1 > threshold && IRsens_val_2 > threshold && IRsens_val_3 > threshold  )
    {
      // all the sensor sens black line
      // move forward
      
     digitalWrite(rigthWheel_Front , HIGH );
     digitalWrite(rigthWheel_Back , LOW );
     digitalWrite(leftWheel_Front ,HIGH);
     digitalWrite(leftWheel_Back , LOW);

     delay (100);
     }

     else if ( IRsens_val_1 < threshold && IRsens_val_2 < threshold && IRsens_val_3 < threshold  )
     {
      // none of the sensors detect black line
      // move forward for some time and then stop

      digitalWrite(rigthWheel_Front , HIGH );
      digitalWrite(rigthWheel_Back , LOW );
      digitalWrite(leftWheel_Front ,HIGH);
      digitalWrite(leftWheel_Back , LOW);

      delay(3000);

      digitalWrite(rigthWheel_Front , LOW );
      digitalWrite(rigthWheel_Back , LOW );
      digitalWrite(leftWheel_Front , LOW );
      digitalWrite(leftWheel_Back , LOW );
      }
}
