#include "tofconfig.h"
#include "indication.h"

VL6180X sensor1;  // Define the sensor objects here
VL6180X sensor2;
VL6180X sensor3;
VL6180X sensor4;
VL6180X sensor5;

int leftWallAvailable = 0;
int rightWallAvailable = 0;
int frontWallAvailable = 0;

int tof[5];
int wallAvailable[3];
int cellWalls[3];

int elapsedTime = 0;   // Define elapsedTime
int xk = 0;             // Define x
int yk = 0;             // Define y
bool frontWallState = false;  // Define frontWallState
bool leftWallState = false;   // Define leftWallState
bool rightWallState = false;  // Define rightWallState

void initializeSensor(VL6180X &sensor, uint8_t address) {
    sensor.init();
    sensor.configureDefault();
    sensor.writeReg(VL6180X::SYSRANGE__MAX_CONVERGENCE_TIME, 30);
    sensor.writeReg16Bit(VL6180X::SYSALS__INTEGRATION_PERIOD, 50);
    sensor.setTimeout(500);
    sensor.stopContinuous();
    delay(300);
    sensor.startInterleavedContinuous(100);
    sensor.setAddress(address); // Set new I2C address for the sensor
}

void powerOnSensor(int pin) {
    digitalWrite(pin, HIGH);  // Enable the PCA9517 channel
    delay(10);                // Small delay for the sensor to power up
}

void powerOffSensors() {
    digitalWrite(T1_L, LOW);
    digitalWrite(T2_LF, LOW);
    digitalWrite(T3_F, LOW);
    digitalWrite(T4_RF, LOW);
    digitalWrite(T5_R, LOW);
}

void powerallSensors() {
    digitalWrite(T1_L, HIGH);
    digitalWrite(T2_LF, HIGH);
    digitalWrite(T3_F, HIGH);
    digitalWrite(T4_RF, HIGH);
    digitalWrite(T5_R, HIGH);
}

void addresschange(){
    
    pinMode(T1_L, OUTPUT);
    pinMode(T2_LF, OUTPUT);
    pinMode(T3_F, OUTPUT);
    pinMode(T4_RF, OUTPUT);
    pinMode(T5_R, OUTPUT);
    Wire.setClock(400000);
    Wire.begin();
    powerOffSensors();

    // Initialize sensor 1
    // Initialize sensor 1
    Serial.println("Initializing Sensor 1");
    Serial1.println("Initializing Sensor 1");
    powerOnSensor(T1_L);
    initializeSensor(sensor1, SENSOR1_ADDRESS);
    sensor1.startRangeContinuous(10);
    powerOffSensors();  // Turn off after configuration
    Serial.println("Sensor 1 initialized");
    Serial1.println("Sensor 1 initialized");
 
    // Initialize sensor 2
    Serial.println("Initializing Sensor 2");
    Serial1.println("Initializing Sensor 2");
    powerOnSensor(T2_LF);
    initializeSensor(sensor2, SENSOR2_ADDRESS);
    sensor2.startRangeContinuous(10);
    powerOffSensors();  // Turn off after configuration
    Serial.println("Sensor 2 initialized");
    Serial1.println("Sensor 2 initialized");

    // Initialize sensor 3
    //powerOnSensor(T3_F);
    //initializeSensor(sensor3, SENSOR3_ADDRESS);
    //powerOffSensors();  // Turn off after configuration
    // Initialize sensor 3
    Serial.println("Initializing Sensor 3");
    Serial1.println("Initializing Sensor 3");
    powerOnSensor(T3_F);
    initializeSensor(sensor3, SENSOR3_ADDRESS);
    sensor3.startRangeContinuous(10);
    powerOffSensors();  // Turn off after configuration
    Serial.println("Sensor 3 initialized");
    Serial1.println("Sensor 3 initialized");


    // Initialize sensor 4
    Serial.println("Initializing Sensor 4");
    Serial1.println("Initializing Sensor 4");
    powerOnSensor(T4_RF);
    initializeSensor(sensor4, SENSOR4_ADDRESS);
    sensor4.startRangeContinuous(10);
    powerOffSensors();  // Turn off after configuration
    Serial.println("Sensor 4 initialized");
    Serial1.println("Sensor 4 initialized");

    // Initialize sensor 5
    Serial.println("Initializing Sensor 5");
    Serial1.println("Initializing Sensor 5");
    powerOnSensor(T5_R);
    initializeSensor(sensor5, SENSOR5_ADDRESS);
    sensor5.startRangeContinuous(10);
    powerOffSensors();  // Turn off after configuration
    Serial.println("Sensor 5 initialized");
    Serial1.println("Sensor 5 initialized");

}

void tofPid()
{
    powerOnSensor(T2_LF);
    sensor2.setAddress(SENSOR2_ADDRESS); // Ensure the correct address is set
   // int ambient1 = sensor1.readAmbientContinuous();
    int range1 = sensor2.readRangeContinuousMillimeters();
    tof[0] = range1;

    powerOnSensor(T3_F);
    sensor3.setAddress(SENSOR3_ADDRESS); // Ensure the correct address is set
   // int ambient5 = sensor3.readAmbientContinuous();
    int range5 = sensor3.readRangeContinuousMillimeters();
    tof[2] = range5;

    powerOnSensor(T4_RF);
    sensor4.setAddress(SENSOR4_ADDRESS); // Ensure the correct address is set
  //  int ambient4 = sensor5.readAmbientContinuous();
    int range4 = sensor4.readRangeContinuousMillimeters();
    tof[4] = range4;
}

void tofStart()
{
    powerOnSensor(T1_L);
    sensor1.setAddress(SENSOR1_ADDRESS); // Ensure the correct address is set
  //  int ambient2 = sensor2.readAmbientContinuous();
    int range2 = sensor1.readRangeContinuousMillimeters();
    tof[1] = range2;
    
    powerOnSensor(T3_F);
    sensor3.setAddress(SENSOR3_ADDRESS); // Ensure the correct address is set
  //  int ambient5 = sensor3.readAmbientContinuous();
    int range5 = sensor3.readRangeContinuousMillimeters();
    tof[2] = range5;
    
    powerOnSensor(T5_R);
    sensor5.setAddress(SENSOR5_ADDRESS); // Ensure the correct address is set
  //  int ambient3 = sensor4.readAmbientContinuous();
    int range3 = sensor5.readRangeContinuousMillimeters();
    tof[3] = range3;
}

void toffront(){
    powerOnSensor(T3_F);
    sensor3.setAddress(SENSOR3_ADDRESS); // Ensure the correct address is set
  //  int ambient5 = sensor3.readAmbientContinuous();
    int range5 = sensor3.readRangeContinuousMillimeters();
    tof[2] = range5;
}

void cerberusstart(){
    while(true){
        tofStart();
       // if (tof[0] <= 120 && tof[2] <= 120 && tof[4] <= 120){
        if (tof[2] <= 60){
            break;
        }
    }
    delay(1000);
    buzzTwice();

}   //mazestart in picoola

void printTof()
{ 
    Serial1.print(tof[0]);
    Serial1.print(",  ");
    Serial1.print(tof[1]);
    Serial1.print(",  ");
    Serial1.print(tof[2]);
    Serial1.print(",  ");
    Serial1.print(tof[3]);
    Serial1.print(",  ");
    Serial1.print(tof[4]); 
    Serial1.println();
}

void checkWallsCell()
{
    if (xk == 0 && yk == 0)
    {
        elapsedTime = 0;
        while(elapsedTime <2)   // check and update after running
        {
            tofStart();
            if (tof[2] <= 180)
            {
            frontWallAvailable = frontWallAvailable + 1;
            }
            else
            {
            frontWallAvailable = frontWallAvailable - 1;
            }
            if (tof[1] <= 150)
            {
            leftWallAvailable= leftWallAvailable + 1;
            }
            else
            {
            leftWallAvailable= leftWallAvailable - 1;
            }
            if (tof[3] <= 150)
            {
            rightWallAvailable= rightWallAvailable + 1;
            }
            else
            {
            rightWallAvailable= rightWallAvailable - 1;
            }
            elapsedTime = elapsedTime + 1;
        }
    }
    if (frontWallAvailable >=0 )
    {
        cellWalls[1] =  1;
        frontWallState = true;
    }
    else
    {
        cellWalls[1] =  0;
        frontWallState = false;
    } 
    if (leftWallAvailable >= 0)
    {
        cellWalls[0] = 1;
        leftWallState = true;
    }
    else
    {
        cellWalls[0] = 0;
        leftWallState = false;
    }
    if (rightWallAvailable >= 0)
    {
        cellWalls[2] = 1;
        rightWallState = true;
    }
    else
    {
        cellWalls[2] = 0;
        rightWallState = false;
    }
    frontWallAvailable = 0;
    leftWallAvailable =0;
    rightWallAvailable =0;

}

void printWallState()
{
    for (int i=0; i<3; i++)
    {
        Serial.print(cellWalls[i]);
        Serial.print("   ");
    }
    Serial.println("");
}