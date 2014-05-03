int ledPin = 3;
int val;
String s;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
} 

void loop() {
  val = Serial.read();
  if (-1 != val) {
    /*
    if (0 == val) {
      s = "";
    }else if (4 == val) {
      int i = 0;
      while(i < s.length()){
        Serial.write(s[i++]);
        delay(5);
      }
    }else {
      s += char(val);
    }
    */
    
    
    
    
    if ('J' == val) {
      digitalWrite(ledPin, HIGH);
    }else if ('K' == val) {
      digitalWrite(ledPin, LOW);
    }
    Serial.write(val);
  }
}
