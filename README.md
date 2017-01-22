![alt text](http://www.firstinspires.org/sites/default/files/uploads/frc/2017-teaser-hero-image.jpg "First Steamworks")

# 2017_Rheumatologist
The 2017 code for the Rheumatologist

**Name** : Rheumatologist  
**Nickname** : Ruby  
**Doctor Description** :  
**Year** : 2017  
**Game** : FRC Steamworks  
**Kick off Date** : January 7, 2017  

## Sensors Potentially Being Used
* Pixy      (Image Recognition)
* Lidar     (Distance Alignment)
* Gyro      (Lineraized Drive)
* Camera    (Driver Sight)
* Encoders  (Position / Speed Control)

## Game Description
To Be Announced ...

## Robot Subsystems
>*Drive*



##Pixy Code

I2C Address set by Pixymon : 0x2
Getting Values from the Roborio Onboard I2C port (I2C::Port::kOnboard)

Sample Readout

raw value : 85  == Frame Start
raw value : 170 
raw value : 85 
raw value : 170 

raw value : 62 == checksum
raw value : 1
 
raw value : 1 == signature
raw value : 0 

raw value : 164 == x Center
raw value : 0 
 
raw value : 67 == y Center
raw value : 0 

raw value : 25 == Width
raw value : 0 

raw value : 61 == Height
raw value : 0 

