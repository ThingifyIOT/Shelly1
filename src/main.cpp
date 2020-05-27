#include <Arduino.h>
#include <ThingifyEsp.h>

ThingifyEsp thing("Shelly1");


bool OnBoolChanged(void*_, Node *node)
{
  bool value = node->Value.AsBool();
  if(value)
  {
    Serial.printf("Bool node changed to true");
  }
  else
  {
    Serial.printf("Bool node changed to false");
  }
  

	return true;
}

bool OnNodeValueChanged(void*_, Node *node)
{
  Serial.printf("'%s' node changed value to '%s'\n", node->name(), node->Value.toString().c_str());
	return true;
}

void setup()
{
	Serial.begin(500000);	
	thing.AddDiagnostics();

  thing.AddBoolean("bool")->OnChanged(OnNodeValueChanged);
  thing.AddInt("integer", ThingifyUnit::Volt)->SetValue(NodeValue::Int(220));
  thing.AddRange("range", 10, 30, 2, ThingifyUnit::Percent)->OnChanged(OnNodeValueChanged);
  thing.AddColor("Color")->OnChanged(OnNodeValueChanged);
	thing.Start();
}

void loop()
{
	thing.Loop();
}
