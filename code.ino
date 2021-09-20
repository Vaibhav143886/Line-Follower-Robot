// Define IR Sensor Pin
const int Sensor_L = 10;
const int Sensor_R = 9;

// Define Motor Pin
const int Motor_L_F = 2; //Left Motor In FORWARD Direction Pin
const int Motor_L_B = 3; //Left Motor In BACKWARD Direction Pin
const int Motor_R_F = 4; //Right Motor In FORWARD Direction Pin
const int Motor_R_B = 5; //Right Motor In BACKWARD Direction Pin

void Forward(){
  // Run Left Motor In Forward Direction
  digitalWrite(Motor_L_F, HIGH);
  digitalWrite(Motor_L_B, LOW);

  //Run Right Motor in Forward Direction
  digitalWrite(Motor_R_F, HIGH);
  digitalWrite(Motor_R_B, LOW);
  }

void Left(){
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, LOW);
  digitalWrite(Motor_L_F, HIGH);
  digitalWrite(Motor_L_B, LOW);
  }

void Right(){
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, LOW);
  digitalWrite(Motor_R_F, HIGH);
  digitalWrite(Motor_R_B, LOW);
  }
  
void setup() {
  // put your setup code here, to run once:

  // Define Motor Pin as output
  pinMode(Motor_L_F, OUTPUT);
  pinMode(Motor_L_B, OUTPUT);
  pinMode(Motor_R_F, OUTPUT);
  pinMode(Motor_R_B, OUTPUT);

  // Define IR Sensor pin as input

  pinMode(Sensor_L, INPUT);
  pinMode(Sensor_R, INPUT);
  }

void loop() {
  //Follow White Line
  if(digitalRead(Sensor_L) == HIGH  &&  digitalRead(Sensor_R) == LOW){
    
    Left();
    
    }
  else if(digitalRead(Sensor_R) == HIGH && digitalRead(Sensor_L) == LOW){

    Right();
    
    }
  else if(digitalRead(Sensor_R) == LOW && digitalRead(Sensor_L) == LOW)
  { //Stop both Motor
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, LOW);
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, LOW);
    }
   else
  Forward();

}
