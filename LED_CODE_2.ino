  #include <IRremote.h>      //including infrared remote header file

int RECV_PIN = 11; // the pin where you connect the output pin of receiver
int led1 = 1;
int led2 = 2;     // these are the pins where you connect the led's
int led3 = 3;
int led4 = 4;
int led5 = 5;
int led6 = 6;
int led7 = 0;
int itsONled[] = {0,0,0,0,0,0,0,0,0,0}; /* the initial state of LEDs is OFF (zero) 
                                         the first zero must remain zero but you can 
                                         change the others to 1's if you want a certain
                                         led to light when the board is powered */
#define code1  00000000
#define code2  00000000 
#define code3  00000000                 // change the 00000000's to the "serials" you wrote down
#define code4  00000000                // each of the 00000000's should be a different number
#define code5  00000000
#define code6  00000000
#define code7  00000000

 
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);   
  irrecv.enableIRIn();  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    switch(value) {
       case code1:
         if(itsONled[1] == 1) {
            digitalWrite(led7, LOW);
            itsONled[1] = 0;
         } else {
             digitalWrite(led7, HIGH);
             itsONled[1] = 1;
         }
          break; 
       case code2:
         if(itsONled[2] == 1) {
            digitalWrite(led2, LOW);
            itsONled[2] = 0;
         } else {
             digitalWrite(led2, HIGH);
             itsONled[2] = 1;
         }
          break;
       case code3:
         if(itsONled[3] == 1) {
            digitalWrite(led3, LOW);
            itsONled[3] = 0;
         } else {
             digitalWrite(led3, HIGH);
             itsONled[3] = 1;
         }
          break;          
        case code4:
         if(itsONled[4] == 1) {
            digitalWrite(led4, LOW);
            itsONled[4] = 0;
         } else {
             digitalWrite(led4, HIGH);
             itsONled[4] = 1;
         }
          break;
        case code5:
         if(itsONled[5] == 1) {
            digitalWrite(led5, LOW);
            itsONled[5] = 0;
         } else {
             digitalWrite(led5, HIGH);
             itsONled[5] = 1;
         }
          break;
        case code6:
         if(itsONled[6] == 1) {
            digitalWrite(led6, LOW);
            itsONled[6] = 0;
         } else {
             digitalWrite(led6, HIGH);
             itsONled[6] = 1;
         }
          break;
            case code7:
         if(itsONled[7] == 1) {
            digitalWrite(led7, LOW);
            itsONled[7] = 0;
         } else {
             digitalWrite(led7, HIGH);
             itsONled[7] = 1;
         }
         break;
    }
    Serial.println(value); 
    irrecv.resume(); 
  }
}
