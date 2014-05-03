void setup()
{
  pinMode( 8 , OUTPUT);
  pinMode( 9 , OUTPUT);
  pinMode( 10 , OUTPUT);

}
int num[] = {
  1+2+4+8+16+32,
  2+4,
  1+2+64+16+8,
  1+2+4+8+64,
  2+4+32+64,
  1+32+64+4+8,
  1+32+16+8+4+64,
  1+2+4,
  1+2+4+8+16+32+64,
  1+2+4+8+32+64
};
void show() {
  digitalWrite( 10 , LOW );
  digitalWrite( 10 , HIGH );
}
void sendBit(bool b) {
  digitalWrite( 8 , b );
  digitalWrite( 9 , LOW );
  digitalWrite( 9 , HIGH );
}
void sendInt(int l, int n) {
  int i;
  for (i = 0; i < 8; i++) {
    sendBit(l & 0x01);
    l >>= 1;
  }
  for (i = 0; i < 8; i++) {
    sendBit(n & 0x80);
    n <<= 1;
  }
  show();
}
void sendLong(long num){

}
void loop()
{
  while (1) {
    sendInt(0xFF - 1,num[5]);
    show();
  }
}


