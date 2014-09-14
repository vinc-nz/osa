 
#define led 13  // led connesso al pin n°13
byte rx = 0;    // variabile per contenere il carattere ricevuto
 
void setup()
	{
	Serial.begin(9600); // imposto la UART per lavorare a 9600

Serial.println("OSNF - Open Sensors Network Framework 0.1 ");
Serial.print("SENSOR NAME:");
Serial.println("OSA2");
Serial.println();

	pinMode(led, OUTPUT); // imposto il pin sul quale è collegato il led come uscita
	Serial.flush(); // svuoto il buffer di ricezione seriale
	}
 
void loop()
	{
	if (Serial.available() > 0) // control buffer
		{
		rx = Serial.read(); // read rx
		Serial.flush();     // flush serial
 
		if (rx=='A' || rx=='a')  
			{
			if (digitalRead(led) == HIGH)  
				{
				//Serial.println("Led già acceso status: ON"); //debug
				}
			else // il led era spento
				{
				digitalWrite(led,HIGH); //lo accendo
				//Serial.println("Led era spento status: ON"); //debug
				}
			}

                if (rx=='S' || rx=='s')  
			{
			if (digitalRead(led) == HIGH)  
				{
                                digitalWrite(led,LOW);
				//Serial.println("Led era acceso e lo spengo status: OFF"); //debug
				}
			else 
				{
				//Serial.println("Led era spento status: OFF"); //debug
				}
			}
 
		else // non ho ricevuto un comando riconosciuto
			{
			Serial.print("Comando non riconosciuto");
			//Serial.print(rx); //debug
			Serial.println();
			}
		}
	}
