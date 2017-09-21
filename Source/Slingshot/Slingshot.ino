// Nom: Code finale Bases
// Auteur: Michael Vara
// Date: 21/09/2017
// Description: Le drone decollera lorsque le joystick gauche sera maintenu en bas puis relaché. 
//              Le drone s'envolera et gagnera de la hauteur aussi longtemps que le joystick bas aura été maintenu,
//              puis il retournera se reposer



#include <CoDrone.h>

unsigned long StartTime, EndTime, Duration, Duration2;
int Flag = 0;

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
    }
  }
}

void loop() {
  if(PAIRING == true){

    // Lorsque le joystick gauche est maintenu en bas
    if(CoDrone.AnalogScaleChange(analogRead(23)) <= -20 && Flag == 0)
    {
        // Instant ou il est maintenu
        StartTime = millis();

        Flag = 1;
    }
    
    // Lorsqu'il est relache
    else if(CoDrone.AnalogScaleChange(analogRead(23)) > -20 && Flag == 1)
    {
        // Instant ou il est relache
        EndTime = millis();

        // Delai entre les deux
        Duration = EndTime - StartTime;

        // Demarrer les moteurs
        CoDrone.FlightEvent(TakeOff);


        // Le drone prends de la hauteur
        THROTTLE = 50;
        CoDrone.Control();

        Duration2 = Duration;

        Flag = 2;
    }

    // Le drone prend de l'altitude pendant le meme delai
    else if(Duration2 > 0 && Flag == 2)
    {
        THROTTLE = 50;
        CoDrone.Control();
        Duration2 --;
    }
    
    // Le drone se repose et se stoppe
    else if(Duration2 <= 0 && Flag == 2)
    {
        Flag = 0;
  
        CoDrone.FlightEvent(Landing);
    }
  }
}



