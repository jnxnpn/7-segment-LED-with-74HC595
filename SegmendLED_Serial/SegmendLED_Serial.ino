
/*clock=SH_CP
data=DS
store=OE
LATCH=ST_CP*/


byte data;
boolean dot; 
byte rece;
byte dispArray;
byte DATApin = 2;
byte LATCHpin = 3;
byte CLOCKpin = 4;
boolean cmd;

 byte digitSeg[10] = 
                                 { B00000010 ,  // 0
                                   B10011110 ,  // 1
                                   B00100100  ,  // 2
                                   B00001100  ,  // 3
                                   B10011000  ,  // 4
                                   B01001000  ,  // 5
                                   B01000000 ,  // 6
                                   B00011110 ,  // 7
                                   B00000000  ,  // 8
                                   B00011000 }   // 9
                                                           ;
void setup() {

dot = false;
Serial.begin(9600);
pinMode(DATApin, OUTPUT);
pinMode(CLOCKpin, OUTPUT);
pinMode(LATCHpin, OUTPUT);

}

void loop() {



while(Serial.available()>0){
   rece = Serial.read();
  delay(10);
  if (rece >=48 && rece <=57){
    dispArray = rece - 48;}
    cmd = true;
  if (rece ==68 || rece == 100){
  dot = true; 
cmd = true;}
}
if(cmd == true){
   digitalWrite(LATCHpin, LOW);//telling the chip to start receivinh date
//  digitalWrite(STOREpin, HIGH);//temporarily disable data from bring activated
//for( int i=0;i<8;i++){
  
 
 if(dot == true){
   data = digitSeg[dispArray];}
   else{
  
  data = digitSeg[dispArray];}

    
  shiftOut (DATApin,CLOCKpin,MSBFIRST, data);
  
  
 
Serial.println(data);
 

digitalWrite(LATCHpin, HIGH); 
// digitalWrite(STOREpin, LOW);//activate the data
 cmd = false;
}
}

