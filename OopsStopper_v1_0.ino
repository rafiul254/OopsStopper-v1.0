const int ENA = 5;   
const int IN1 = 6;  
const int IN2 = 7; 
const int IN3 = 8;  
const int IN4 = 9;  
const int ENB = 10;  

const int IR_SENSOR = 2;  

const int MOTOR_SPEED = 150;      
const int TURN_SPEED = 180;     

const int STOP_DELAY = 500;      
const int BACKWARD_TIME = 800;  
const int TURN_TIME = 600;   
const int PAUSE_AFTER_TURN = 300; 


bool edgeDetected = false;

void setup() {

  Serial.begin(9600);
  Serial.println("=====================================");
  Serial.println("   OopsStopper v1.0 Starting...     ");
  Serial.println("   Edge Detection Robot              ");
  Serial.println("=====================================");

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  

  pinMode(IR_SENSOR, INPUT);

  stopMotors();
  
  Serial.println("Pin Configuration: OK");
  Serial.println("Motor Driver: Ready");
  Serial.println("IR Sensor: Ready");
  Serial.println("=====================================");
  Serial.println("System Ready! Robot will start in 2 seconds...");
  Serial.println("Place robot on table surface.");
  Serial.println("=====================================");
  
  delay(2000); 
  
  Serial.println("Starting navigation...");
}

void loop() {
 
  int sensorValue = digitalRead(IR_SENSOR);
  

  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 1000) {  
    Serial.print("Sensor: ");
    Serial.println(sensorValue == LOW ? "EDGE" : "SURFACE");
    lastPrint = millis();
  }
  
  if (sensorValue == LOW) {
 
    Serial.println("");
    Serial.println("**********************************");
    Serial.println("WARNING: EDGE DETECTED!");
    Serial.println("**********************************");
    
    Serial.println("Action 1: STOPPING");
    stopMotors();
    delay(STOP_DELAY);
    

    Serial.println("Action 2: MOVING BACKWARD");
    moveBackward();
    delay(BACKWARD_TIME);
    

    Serial.println("Action 3: STOPPING");
    stopMotors();
    delay(PAUSE_AFTER_TURN);

    Serial.println("Action 4: TURNING RIGHT");
    turnRight();
    delay(TURN_TIME);
    
    Serial.println("Action 5: STOPPING");
    stopMotors();
    delay(PAUSE_AFTER_TURN);
    
    Serial.println("Direction changed successfully!");
    Serial.println("Resuming forward movement...");
    Serial.println("**********************************");
    Serial.println("");
  } 
  else {
    moveForward();
  }
  
  delay(50); 


void moveForward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, MOTOR_SPEED);
  analogWrite(ENB, MOTOR_SPEED);
}

void moveBackward() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, MOTOR_SPEED);
  analogWrite(ENB, MOTOR_SPEED);
}


void turnRight() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
 
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, TURN_SPEED);
  analogWrite(ENB, TURN_SPEED);
}


void turnLeft() {
 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
 
  analogWrite(ENA, TURN_SPEED);
  analogWrite(ENB, TURN_SPEED);
}


void stopMotors() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
 
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
