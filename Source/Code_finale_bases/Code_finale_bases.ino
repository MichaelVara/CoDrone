// Nom: Code finale Bases
// Auteur: Michael Vara
// Date: 21/09/2017
// Description: Controle du drone a l'aide de des joysticks
//              Lors de la connexion au drone, un petit bruitage est joue
//              La telecommande continue a chercher le drone tant qu'elle n'a pas etablie la connexion


#include <CoDrone.h>

void setup() {
  // Tant que la connexion n'est pas etablie, on continue de chercher un drone
  while(PAIRING == false)
  {
    // Connexion avec le drone
    CoDrone.begin(115200);
    byte droneAddress[6] = {0x14, 0xB9, 0x60, 0x78, 0xD5, 0xA4};
    CoDrone.AutoConnect(AddressInputDrone, droneAddress);
  
    if(PAIRING == true){
        // Petit bruitage lorsque la connexion avec le drone est etablie
        CoDrone.Buzz(2000,15);
        CoDrone.Buzz(1500,10);
      
        // Demarrer les moteurs
        CoDrone.FlightEvent(TakeOff);
    }
  }
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
        // Deplacements lateraux
        ROLL = 0 - CoDrone.AnalogScaleChange(analogRead(22));
    CoDrone.Control();

    if(digitalRead(11))
    {
      // Atterrissage du drone
      CoDrone.FlightEvent(Landing);
    }
  }
}

