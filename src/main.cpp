#include <Arduino.h>
#include <ThingifyEsp.h>

ThingifyEsp thing("Shelly1");


const int RelayPin = 4;
const int SwitchPin = 5;

bool OnBoolChanged(void*_, Node *node)
{
    digitalWrite(RelayPin, node->Value.AsBool());
  	return true;
}

void setup()
{
	Serial.begin(500000);	
	thing.AddDiagnostics();

  pinMode(RelayPin, OUTPUT);

  thing.AddBoolean("Switch")->OnChanged(OnBoolChanged);
	thing.Start();
}

void loop()
{
	thing.Loop();
}
