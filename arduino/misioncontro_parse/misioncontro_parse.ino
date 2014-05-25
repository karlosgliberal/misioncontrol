long t1;
String st, msgChar, msgInt;
int val;

void setup()
{
   pinMode(13, OUTPUT);
   Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
   t1 = millis();
}

void parseData(){
  
   if(st.indexOf(" ")>=0){
     msgChar = st.substring(0,(st.indexOf(" ")));
     msgInt = st.substring(st.indexOf(" ")+1);
     val = (msgInt.toInt());
   }else{
     msgChar = st;
     val = 0;
   }
}

void parseDataComa(){
  
   if(st.indexOf(",")>=0){
     msgChar = st.substring(0,(st.indexOf(",")));
     msgInt = st.substring(st.indexOf(",")+1);
     val = (msgInt.toInt());
   }else{
     msgChar = st;
     val = 0;
   }
}

void loop(){
  if (Serial.available()){
     st = String("");
     while(Serial.available()){
        st = st + char(Serial.read());
        delay(1);
     }

     parseData();
     Serial.print(st);
     Serial.print("\t");
     Serial.print(msgChar);
     Serial.print("\t");
     Serial.println(val);
     t1 = millis();
  }
  
  if(msgChar.indexOf("LED1ON")>=0) {
    if ((millis() - t1)<(val*1000))
       digitalWrite(13,HIGH);
    else if((millis() - t1) >(val*1000))
       digitalWrite(13,LOW);
  }else
    digitalWrite(13, LOW);
  }
