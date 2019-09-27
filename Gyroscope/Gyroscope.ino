#include<Wire.h>

// Address of the MPU6050. Can be changed to 0x69 by ADO pin
#define MPU6050_ADDR 0x68

int16_t accX, accY, accZ, temp, gyroX, gyroY, gyroZ;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B); // PWR_MGMT_1 register (the sleep register), 1 at power-up
  Wire.write(0); // set to zero to wake up the MPU-6050
  Wire.endTransmission(true);

  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);

  Wire.requestFrom(MPU6050_ADDR, 14, true); // request a total of 14 registers
  accX = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  accY = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  accZ = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  temp = Wire.read() << 8 | Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  gyroX = Wire.read() << 8 | Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  gyroY = Wire.read() << 8 | Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  gyroZ = Wire.read() << 8 | Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  Serial.print("aX: "); Serial.print(accX);
  Serial.print("\t aY: "); Serial.print(accY);
  Serial.print("\t aZ: "); Serial.print(accZ);
  Serial.print("\t t: "); Serial.print(temp/340.00+36.53); // equation in datasheet
  Serial.print("\t gX: "); Serial.print(gyroX);
  Serial.print("\t gY: "); Serial.print(gyroY);
  Serial.print("\t gZ: "); Serial.println(gyroZ);

  delay(500);
}
