// Nom: Projet 1
// Auteur: Michael Vara
// Date: 21/09/2017
// Description: Le drone decolle de 20cm, reste stable pendant 3 secondes et se 
//              repose ou il a decoller


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

  // Atterrissage du drone
  CoDrone.FlightEvent(Landing);
}

void loop() {
  
}

