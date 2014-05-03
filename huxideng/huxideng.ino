float dianya_out = 0;
float step_dianya = 0.05;
float max_dianya = 5;
float min_dianya = 0;
int interval = 1000;
void setup()
{
  Serial.begin(9600);
  dianya_out = 0;
}

void loop()
{
  while ( dianya_out  < max_dianya )
  {
    dianya_out += step_dianya  ;
    if(dianya_out > max_dianya){
      dianya_out = max_dianya;
    }
    analogWrite(3, ( ( dianya_out / 5 ) * 255 ));
    delay( 10 );
  }
  while ( dianya_out > min_dianya )
  {
    dianya_out -= step_dianya;
    if(dianya_out < min_dianya){
      dianya_out = min_dianya;
    }
    analogWrite(3, ( ( dianya_out / 5 ) * 255 ));
    delay( 10 );
  }
  delay( interval );
}







