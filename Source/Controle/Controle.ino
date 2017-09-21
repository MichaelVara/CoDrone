// Nom: Projet 2
// Auteur: Michael Vara
// Date: 21/09/2017
// Description: Controle du drone a l'aide de des joysticks


#include <CoDrone.h>

void setup() {
  // Connexion avec le drone
  CoDrone.begin(115200);
  byte droneAddress[6] = {0x14, 0xB9, 0x60, 0x78, 0xD5, 0xA4};
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);

  // Demarrer les moteurs
  CoDrone.FlightEvent(TakeOff);
}

void loop() {
  if(PAIRING == true){
    // Joystick droit
        // Monter / descendre
        THROTTLE = CoDrone.AnalogScaleChange(analogRead(25));
        // Tourner
        YAW = 0 - CoDrone.AnalogScaleChange(analogRead(24));

    // Joystick gauche
        // Avance / reculer
        PITCH = CoDrone.AnalogScaleChange(analogRead(23));
        ROLL = 0 - CoDrone.AnalogScaleChange(analogRead(22));
    CoDrone.Control();

    if(digitalRead(11))
    {
      // Atterrissage du drone
      CoDrone.FlightEvent(Landing);
    }
  }
}

