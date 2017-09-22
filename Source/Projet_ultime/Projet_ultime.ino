// Nom: Projet ultime
// Auteur: Michael Vara
// Date: 22/09/2017
// Description: Le drone s'envole depuis la main de quelqu'un, fait le tour de sa main et se repose dessus


#include <CoDrone.h>

void setup() {
  // Connexion avec le drone
  CoDrone.begin(115200);
  byte droneAddress[6] = {0x14, 0xB9, 0x60, 0x78, 0xD5, 0xA4};
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);


  // Demarrer les moteurs
  CoDrone.FlightEvent(TakeOff);

  // Attendre trois secondes en l'air
  delay(2000);

  // Faire avancer le drone de quelques centimetres
  PITCH = 70;
  CoDrone.Control();
  delay(1200);
  PITCH = 0;
  
  // Faire redescendre le drone
  THROTTLE = -40;
  CoDrone.Control();
  delay(1000);
  THROTTLE = 0;

  // Faire reculer le drone de quelques centimetres
  PITCH = -15;
  CoDrone.Control();
  delay(1000);
  PITCH = 0;

  // Faire monter le drone de quelques centimetres
  THROTTLE = 40;
  CoDrone.Control();
  delay(2000);
  THROTTLE = 0;

  // Faire avancer le drone de quelques centimetres
  PITCH = 50;
  CoDrone.Control();
  delay(1200);
  PITCH = 0;
  CoDrone.Control();
  
  // Atterrissage du drone
  CoDrone.FlightEvent(Landing);
}

void loop() {
  
}

