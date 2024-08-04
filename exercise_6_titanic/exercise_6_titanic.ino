int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
int const instrumento = 7;
int const ledDO = 13;
int const ledMI = 12;
int const ledFA = 11;
int const ledSOL = 10;
int const ledLA = 9;
int const ledRE = 8;

void configure_note(int note) {
  pinMode(note, OUTPUT);
  digitalWrite(note, LOW);
}
void make_sound(int nota, int led, int duracion) {
  digitalWrite(led, HIGH);
  tone(instrumento, nota, duracion-100);
  delay(duracion-100);
  digitalWrite(led, LOW);
  delay(100);
}

void setup() {
  // put your setup code here, to run once:
  configure_note(ledDO);
  configure_note(ledMI);
  configure_note(ledFA);
  configure_note(ledSOL);
  configure_note(ledLA);
}

void loop() {
  delay(5000);
  // put your main code here, to run repeatedly:
  long DO=523.25, 
       DoS=554.37,
       RE=587.33,
       RES=622.25,
       MI=659.26,
       FA=698.46,
       FAS=739.99,
       SOL=783.99,
       SOLS=830.61,
       LA=880,
       LAS=932.33,
       SI=987.77,
       RE2=1174.66,
       FAS2=1479.98,
       PAU=30000;
  int tiempo = 800;
  make_sound(FA, ledFA, tiempo);
  make_sound(FA, ledFA, tiempo/2);
  make_sound(FA, ledFA, tiempo);
  make_sound(FA, ledFA, tiempo);
  make_sound(MI, ledMI, tiempo);
  make_sound(FA, ledFA, tiempo*2);
  make_sound(FA, ledFA, tiempo);
  make_sound(MI, ledMI, tiempo);
  make_sound(FA, ledFA, tiempo*2);
  make_sound(SOL, ledSOL, tiempo);
  make_sound(LA, ledLA, tiempo*2);
  make_sound(SOL, ledSOL, tiempo*2);
  
  make_sound(FA, ledFA, tiempo);
  make_sound(FA, ledFA, tiempo/2);
  make_sound(FA, ledFA, tiempo);
  make_sound(FA, ledFA, tiempo);
  make_sound(MI, ledMI, tiempo);
  make_sound(FA, ledFA, tiempo*2);
  make_sound(FA, ledFA, tiempo);
  make_sound(DO, ledDO, tiempo*2);
}
