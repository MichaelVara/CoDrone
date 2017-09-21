// Nom: Projet 2
// Auteur: Michael Vara
// Date: 21/09/2017
// Description: 


#include <CoDrone.h>

void setup() {
  // Connexion avec le drone
  CoDrone.begin(115200);
  byte droneAddress[6] = {0x14, 0xB9, 0x60, 0x78, 0xD5, 0xA4};
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);


  // Demarrer les moteurs
  CoDrone.FlightEvent(TakeOff);

  // Attendre trois secondes en l'air
  delay(3000);

  // Faire monter le drone de quelques centimetres
  THROTTLE = 50;
  CoDrone.Control();
  delay(2500);
  THROTTLE = 0;

  // Faire tourner le drone vers la droite
  YAW = 50;
  CoDrone.Control();
  delay(1500);

  // Faire tourner le drone vers la gauche
  YAW = -50;
  CoDrone.Control();
  delay(2500);
  YAW = 0;

  // Faire avancer le drone de quelques centimetres
  PITCH = 20;
  CoDrone.Control();
  delay(2500);

  // Faire reculer le drone de quelques centimetres
  PITCH = -20;
  CoDrone.Control();
  delay(2000);
  PITCH = 0;

  // Deplacer le drone vers la droite de quelques centimetres
  ROLL = 20;
  CoDrone.Control();
  delay(2000);

  // Deplacer le drone vers la gauche de quelques centimetres
  ROLL = -20;
  CoDrone.Control();
  delay(2000);
  ROLL = 0;
  
  // Faire redescendre le drone
  THROTTLE = -50;
  CoDrone.Control();
  delay(2500);
  THROTTLE = 0;
  CoDrone.Control();
  
  // Atterrissage du drone
  CoDrone.FlightEvent(Landing);
}

void loop() {
  
}

