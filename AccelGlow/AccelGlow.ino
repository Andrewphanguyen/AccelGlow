#define motor1pin1 8
#define motor1pin2 4
#define motor2pin1 5
#define motor2pin2 6

#define ENA 3
#define ENB 9


// 2x2 matrix
const int rowPins[2] = {10, 11};
const int colPins[2] = {12, 13};


int speedValue = 0;

unsigned long lastIncrease = 0;
const int accelerationDelay = 40;


// ---------------- SETUP ----------------
void setup() {

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);

  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);


  // Matrix setup
  for (int i = 0; i < 2; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
  }

  for (int i = 0; i < 2; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }


  Serial.begin(9600);
}


// ---------------- SPEED ----------------
void setSpeed() {

  analogWrite(ENA, speedValue);
  analogWrite(ENB, speedValue);
}


void accelerate() {

  if (millis() - lastIncrease > accelerationDelay) {

    speedValue += speedValue * 0.07 + 1;

    if (speedValue > 255) {
      speedValue = 255;
    }

    lastIncrease = millis();
  }
}


// ---------------- MOVEMENT ----------------
void stopMotors() {

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);

  speedValue = 0;

  setSpeed();
}


void moveForward() {

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}


void moveBackward() {

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}


void moveLeft() {

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}


void moveRight() {

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}


// ---------------- BUTTON MATRIX ----------------
// Returns 1-4, or 0 if none
int scanMatrix() {

  for (int row = 0; row < 2; row++) {

    digitalWrite(rowPins[row], LOW);

    for (int col = 0; col < 2; col++) {

      if (digitalRead(colPins[col]) == LOW) {

        digitalWrite(rowPins[row], HIGH);

        return row * 2 + col + 1;
      }
    }

    digitalWrite(rowPins[row], HIGH);
  }

  return 0;
}


// ---------------- LOOP ----------------
void loop() {

  bool moving = false;
  const char* direction = "Stopped";

  int button = scanMatrix();


  switch (button) {

    case 1:
      accelerate();
      moveForward();
      direction = "Forward";
      moving = true;
      break;

    case 2:
      accelerate();
      moveBackward();
      direction = "Backward";
      moving = true;
      break;

    case 3:
      accelerate();
      moveLeft();
      direction = "Left";
      moving = true;
      break;

    case 4:
      accelerate();
      moveRight();
      direction = "Right";
      moving = true;
      break;

    default:
      stopMotors();
      button = 0;
      break;
  }


  if (moving) {
    setSpeed();
    // Serial output
    
  } 

  Serial.print("Button: ");
    Serial.print(button);

    Serial.print(" | Direction: ");
    Serial.print(direction);

    Serial.print(" | Speed: ");
    Serial.println(speedValue);


  
}