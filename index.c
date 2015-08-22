#include <Conceptinetics.h>
#define DMX_MASTER_CHANNELS 512 
#define RXEN_PIN 2
DMX_Master dmx_master ( DMX_MASTER_CHANNELS, RXEN_PIN );

const int buttonPin = 4; 

int buttonState = 0;
bool buttonPressed = false;
int listening = true;
int codeStarted = false;
int code = 0;
unsigned long codeEnd = millis();

int hotPower = 0;

bool fading = false;

byte dmxStates[365] = {};
byte newState[365] = {};

void setup() {
//  Serial.begin(9600);
  dmx_master.enable (); 
  pinMode(buttonPin, INPUT);
  
}

void loop(){
  if(listening==true){
    buttonState = digitalRead(buttonPin);
    if(buttonState==HIGH && buttonPressed==false){
      //debounce button
      unsigned long debounce = millis() + 150;
      unsigned long now = millis();
      while(now < debounce){
        now = millis();
        if(now>=debounce){
          buttonPressed = false;
        }
      }
      if(code==0){
        //start this is the first part of the code
        codeEnd = millis() + 1000;
      }
      code++;
    }
    unsigned long nnow = millis();
    if(codeEnd<=nnow && code!=0){
      //stop listening for code
      if(code==1){
        setScene1();
      }else if(code==2){
        setScene2();
      }else if(code==3){
        setScene3();
      }else if(code==4){
        setScene4();
      }
      code = 0;
    }
 
 }
}

void setScene1(){
  //everything off
  if(fading==false){
    fading = true;
    
    int i = 1;
    while(i < 360){
      newState[i] = 0;
      i++;
    }
    setScene(2000, 2000);
    if(hotPower==1){
      hotpowerOff();
    }
    unsigned long debounce = millis() + 5000;
    unsigned long now = millis();
    while(now < debounce){
      now = millis();
      if(now>=debounce){
        fading = false;
      }
    }
  }
}
void setScene2(){
  if(fading==false){
    fading = true;
    //set all channels to off mode first
    int i = 1;
    while(i < 360){
      newState[i] = 0;
      i++;
    }
    newState[1] = 61;
    newState[4] = 61;
    newState[25] = 153;
    newState[26] = 153;
    newState[27] = 141;
    newState[28] = 153;
    newState[29] = 153;
    newState[30] = 153;
    newState[32] = 153;
    newState[33] = 153;
    newState[34] = 153;
    newState[35] = 153;
    newState[36] = 153;
    
    setScene(2000, 2000);
    
    unsigned long debounce = millis() + 5000;
    unsigned long now = millis();
    while(now < debounce){
      now = millis();
      if(now>=debounce){
        fading = false;
      }
    }
  }
}

void setScene3(){
  //blackout
  if(fading==false){
    fading = true;
    
    int i = 1;
    while(i < 360){
      newState[i] = 0;
      i++;
    }
    newState[1] = 61;
    newState[4] = 72;
    newState[27] = 168;
    
    setScene(2000, 2000);
    unsigned long debounce = millis() + 5000;
    unsigned long now = millis();
    while(now < debounce){
      now = millis();
      if(now>=debounce){
        fading = false;
      }
    }
  }
}

void setScene4(){
  if(fading==false){
    fading = true;
    if(hotPower==0){
      hotpowerOn();
    }
    
    int i = 1;
    while(i < 360){
      newState[i] = 0;
      i++;
    }
    newState[1] = 61;
    newState[4] = 72;
    newState[7] = 132;
    newState[8] = 139;
    newState[10] = 139;
    newState[11] = 157;
    newState[12] = 164;
    newState[25] = 148;
    newState[26] = 163;
    newState[27] = 169;
    newState[28] = 163;
    newState[29] = 148;
    newState[30] = 134;
    newState[32] = 134;
    newState[33] = 148;
    newState[34] = 148;
    newState[35] = 163;
    newState[36] = 164;
    newState[38] = 170;
    newState[39] = 170;
    newState[40] = 170;
    newState[41] = 170;
    
    newState[67] = 255;
    newState[79] = 255;
    
    newState[95] = 143;
    newState[98] = 143;
    
    
    newState[101] = 143;
    newState[104] = 143;
    newState[107] = 143;
    newState[110] = 143;
    newState[113] = 143;
    newState[116] = 143;
    newState[119] = 143;
    newState[122] = 143;
    newState[125] = 143;
    newState[128] = 143;
    newState[129] = 143;
    newState[131] = 143;
    newState[132] = 143;
    newState[134] = 143;
    newState[135] = 143;
    newState[137] = 143;
    newState[138] = 143;
    newState[140] = 143;
    newState[141] = 143;
    newState[143] = 143;
    newState[144] = 143;
    newState[146] = 143;
    newState[147] = 143;
    newState[149] = 143;
    newState[150] = 143;
    newState[152] = 143;
    newState[153] = 143;
    newState[155] = 143;
    newState[156] = 143;
    newState[158] = 143;
    newState[159] = 143;
    newState[161] = 143;
    newState[162] = 143;
    newState[164] = 143;
    newState[215] = 143;
    newState[218] = 143;
    newState[221] = 143;
    newState[224] = 143;
    newState[227] = 143;
    newState[230] = 143;
    newState[233] = 143;
    newState[236] = 143;
    newState[239] = 143;
    newState[242] = 143;
    newState[245] = 143;
    newState[248] = 143;
    newState[251] = 143;
    newState[254] = 143;
    newState[257] = 143;
    newState[260] = 143;
    newState[263] = 143;
    newState[266] = 143;
    newState[269] = 143;
    newState[272] = 143;
    newState[275] = 143;
    newState[278] = 143;
    newState[281] = 143;
    newState[284] = 143;
    newState[285] = 143;
    newState[287] = 143;
    newState[288] = 143;
    newState[290] = 143;
    newState[291] = 143;
    newState[293] = 143;
    newState[294] = 143;
    newState[296] = 143;
    newState[297] = 143;
    newState[299] = 143;
    newState[300] = 143;
    newState[302] = 143;
    newState[303] = 143;
    newState[305] = 143;
    newState[306] = 143;
    newState[308] = 143;
    newState[309] = 143;
    newState[311] = 143;
    newState[312] = 143;
    newState[314] = 143;
    newState[315] = 143;
    newState[317] = 143;
    newState[318] = 143;
    newState[320] = 143;
    newState[323] = 143;
    newState[326] = 143;
    newState[329] = 143;
    newState[332] = 143;
    newState[335] = 143;
    newState[338] = 143;
    newState[341] = 143;
    newState[344] = 143;
    newState[347] = 143;
    newState[350] = 143;
    newState[353] = 143;
    newState[356] = 143;

    
    setScene(2000, 2000);
    unsigned long debounce = millis() + 5000;
    unsigned long now = millis();
    while(now < debounce){
      now = millis();
      if(now>=debounce){
        fading = false;
      }
    }
  }
}


void hotpowerOn(){
    //hot power
  hotPower = 1;
  int i = 502;
  while(i < 512){
    dmx_master.setChannelValue ( i, 1 );
    i++;
  }

  
}
void hotpowerOff(){
    //hot power
  hotPower = 0;
  
  int i = 502;
  while(i < 512){
    dmx_master.setChannelValue ( i, 0 );
    i++;
  }
  
}



void setScene(int duration, int totalDuration){
  //how long are the jumps, we use a max of 20
   double tmpJumpLength = totalDuration/10;
   int jumpLength = (int) tmpJumpLength;
   int newDuration = duration - jumpLength;
   bool goAgain = false;

  int tmpTravel = 0;
  double tmpTick = 0;
  double tmpNewValue = 0;
   
   for(int chan = 0; chan < 360; chan++){
    int destination = newState[chan];
    int current = dmxStates[chan];
    if(destination!=current){
      goAgain = true;
      tmpTravel = (int) destination - (int) current;
      tmpTick= (double) tmpTravel/ (double) duration * 100;
      tmpNewValue = current;
      tmpNewValue = current + tmpTick;
      if(destination>current){
        if(tmpNewValue>destination){
          tmpNewValue = destination;
        }
      }else{
        if(tmpNewValue<destination){
          tmpNewValue = destination;
        }
      }
      int SetTo = (int) tmpNewValue;
      dmxStates[chan] = SetTo;
    }
    
   }

   
   flushDmx();
   if(goAgain==true){
    unsigned long debounce = millis() + jumpLength;
    unsigned long now = millis();
    while(now < debounce){
      now = millis();
      if(now>=debounce){
        setScene(newDuration, totalDuration);
      }
    }
   }
}

void flushDmx(){

  int i = 1;
  while(i < 360){
    /*Serial.print("chan ");
    Serial.print(i);
    Serial.print(" @ ");
    Serial.println(dmxStates[i]);
    */
    dmx_master.setChannelValue ( i, dmxStates[i] );
    i++;
  }

}
