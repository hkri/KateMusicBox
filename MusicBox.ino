
/*

  Music box project for Kate chaaan~
  Coded by: John Espiritu
  Date: February 5, 2016
  
  Playing:
  Like I'm Gonna Lose You
  
*/

/* Prepare tones */

int tones[] = {
  3830,     //c =    0
  3400,     //d =    1
  3038,     //e =    2   
  2864,     //f =    3
  2550,     //g =    4
  2272,     //a =    5
  2028,     //b =    6
  
  1912,     //C =    7
  1803,     //CsDb = 8
  1720,     //D =    9
  1517,     //E =    10
  1431,     //F =    11
  1275,     //G =    12
  1136,     //A =    13
  1012,     //B =    14
  956,      //C6 =   15
  
  0,        //R = 16
  
  //Below the normal staff.
  4050,    //b3 = 17
  4545,    //a3 = 18
  
};

byte a3 = 18;
byte b3 = 17;

byte c = 0;
byte d = 1;
byte e = 2;
byte f = 3;
byte g = 4;
byte a = 5;
byte b = 6;

byte C = 7;
byte CsDb = 8;
byte D = 9;
byte E = 10;
byte F = 11;
byte G = 12;
byte A = 13;
byte B = 14;
byte C6 = 15;

byte R = 16;

/* function declaration */
int getTemp(int bpm);

/* Variables and stuff */
int output = 4;
int tempo = getTemp(70, 60);

float b4b = 0.275f;
float b4 = 0.25f;
float b8 = 0.125f;
float b16 = 0.0625f;


/* Player head info */
byte head_tone = R;
int head_pointer = 0;
long current_time = 0;
int npb = 12;
long interval = (long)((double)tempo / (double)npb);

/*
  
  4. = 0.3750
  4  = 0.2500
  8  = 0.1250
  16 = 0.0625

*/

/* Melody Composition */
byte seq = 0;
byte total_seq = 64; 

//////////////////////////////////////////////


//Codes on Arduino initialize.
void setup() {                
  // initialize pins
  pinMode(output, OUTPUT);   
  pinMode(2, INPUT);  
  Serial.begin(9600);  
}


//play tone functionality
void playTone(){

  int ton = tones[head_tone];

  if(ton > 0){
    digitalWrite(output, HIGH);   // turn the LED on (HIGH is the voltage level)
    delayMicroseconds((double)ton / (double)2);
    digitalWrite(output, LOW);   // turn the LED on (HIGH is the voltage level)
    delayMicroseconds((double)ton / (double)2);
  }
  
}

int _BEAT(int measure){
 if(measure == 1)
   return tempo;
}

int getTemp(int bpm, int note){
  return (int)(((double)note / (double)bpm) * 1000); 
}


bool played = false;
long last_note = 0;
long melody_size = 48;
void readMelody(){
  current_time = millis();
  if((long)((long)current_time - (long)last_note) > (long)interval) {
    head_pointer++;
    if(head_pointer >= melody_size) {
      seq++;
      head_pointer = 0;
    }
    if(seq > total_seq) {
      seq = 0; 
      played = true;
    }
    
    //Verse
    if(seq == 0 || seq == 4) {
      
      byte melody01[] = {
        
        //I found my self dreaming.
        //We we're walking on moonlight
        R,R,    R,R,    R,R,    R,R,      g,g,    R,R,
        g,g,    R,R,    a,a,    R,R,      C,C,    R,R,
        C,C,    C,C,    C,C,    C,C,      R,R,    R,R,
        a,a,    R,R,    g,g,    g,g,      R,R,    R,R,
      
      };
      head_tone = melody01[head_pointer];
    } 
    if(seq == 1 || seq == 5) {
      
      const byte melody02[] = {
        
        //In silver and gold~
        //And you pulled me close
        R,R,    R,R,    R,R,    R,R,      g,g,    R,R,
        g,g,    R,R,    a,a,    R,R,      C,C,    R,R,
        D,D,    R,R,    C,C,    D,D,      D,D,    D,D,
        D,D,    R,R,    E,E,    E,E,      R,R,    R,R,
      
      };
      head_tone = melody02[head_pointer];
    } 
    if(seq == 2) {
      byte melody03[] = {
  
          //Like a scene from a movie
          R,R,    R,R,    R,R,    R,R,      g,R,    g,R,
          g,g,    R,R,    a,a,    R,R,      C,C,    R,R,
          C,C,    C,C,    C,C,    R,R,      R,R,    R,R,
          a,a,    a,a,    R,R,    R,R,      C,C,    R,R,
        
        };
      head_tone = melody03[head_pointer];
    } 
    if(seq == 3) {
      byte melody04[] = {
  
        //That every broken heart knows
        F,F,    F,F,    R,R,    R,R,      F,F,    R,R,
        E,E,    E,E,    R,R,    R,R,      D,D,    R,R,
        D,D,    D,D,    D,D,    R,R,      R,R,    R,R,
        C,C,    C,C,    C,C,    R,R,      R,R,    R,R,
      
      };
      head_tone = melody04[head_pointer];
    } 
    if(seq == 6) {
      byte melody05[] = {
  
        //Split second and you disappeared and then
        R,R,    R,R,    R,R,    R,R,      E,E,    R,R,
        E,E,    R,R,    D,D,    R,R,      D,D,    R,R,
        D,D,    R,R,    C,C,    R,R,      C,C,    R,R,
        C,C,    R,R,    D,D,    R,R,      D,D,    R,R,
      
      };
      head_tone = melody05[head_pointer];
    } 
    if(seq == 7) {
      byte melody06[] = {
  
        //I was all alone
        F,F,    F,F,    R,R,    R,R,      F,F,    R,R,
        E,E,    E,E,    R,R,    R,R,      D,D,    R,R,
        D,D,    D,D,    D,D,    R,R,      R,R,    R,R,
        C,C,    C,C,    R,R,    R,R,      R,R,    R,R,
      
      };
      head_tone = melody06[head_pointer];
    } 
    if(seq == 8) {
      const byte melody07[] = {
  
        //Woke up in tears, with you by my side, A
        D,D,    R,R,    E,E,    R,R,      D,D,    R,R,
        E,E,    E,E,    R,R,    R,R,      D,D,    R,R,
        D,D,    R,R,    E,E,    R,R,      D,D,    R,R,
        G,G,    G,G,    R,R,    R,R,      R,R,    R,R,
      
      };
      head_tone = melody07[head_pointer];
    } 
    if(seq == 9) {
      byte melody08[] = {
  
        //breath of relief, and I realized
        D,D,    R,R,    E,E,    R,R,      D,D,    R,R,
        E,E,    E,E,    R,R,    R,R,      D,D,    R,R,
        D,D,    R,R,    E,E,    R,R,      D,D,    R,R,
        G,G,    G,G,    A,G,    G,G,      G,G,    R,R,
      
      };
      head_tone = melody08[head_pointer];
    } 
    if(seq == 10) {
      
      byte melody09[] = {
        
        //---- No, we're not
        G,G,    R,R,    A,A,    A,A,      R,R,    R,R,
        A,A,    A,A,    A,A,    R,R,      R,R,    R,R,
        R,R,    R,R,    R,R,    R,R,      E,E,    R,R,
        E,E,    R,R,    E,E,    R,R,      E,E,    R,R,
      
      };
      head_tone = melody09[head_pointer];
    } 
    if(seq == 11) {
      byte melody10[] = {
  
        //promised tomorrow. So I'm gonna
        D,D,    R,R,    D,D,    R,R,      C,C,    R,R,
        D,D,    R,R,    C,C,    C,C,      R,R,    R,R,
        R,R,    R,R,    R,R,    R,R,      G,G,    R,R,
        G,G,    R,R,    A,A,    R,R,      C6,C6,    R,R,
      
      };
      head_tone = melody10[head_pointer];
    }
    
    //Chorus
    if(seq == 12) {const byte melody11[] = {
  
        //Love you, Like I'm gonna
        C6,C6,    C6,C6,    C6,C6,    R,R,      R,R,    R,R,
        A,A,      G,G,      G,G,      G,G,      R,R,    R,R,
        R,R,      R,R,      R,R,      R,R,      E,E,    R,R,
        G,G,      R,R,      A,A,      R,R,      C6,C6,    R,R,
      
      };
      head_tone = melody11[head_pointer];
    } 
    if(seq == 13) {
      
      byte melody12[] = {
        
        //lose you, I'm gonna
        B,B,    B,B,    B,B,    R,R,      R,R,    R,R,
        B,B,    B,R,    A,R,    G,G,      G,G,    G,G,
        G,G,    G,G,    G,G,    R,R,      R,R,    R,R,
        G,G,    R,R,    A,A,    R,R,      B,B,    R,R,
      
      };
      head_tone = melody12[head_pointer];
    } 
    if(seq == 14 || seq == 18) {
      byte melody13[] = {
  
        //hold you, like I'm saying good
        //know when, when we'll run out of
        A,A,    A,A,    A,A,    A,A,      R,R,    R,R,
        A,A,    A,A,    A,A,    A,A,      R,R,    R,R,
        R,R,    R,R,    A,A,    R,R,      A,A,    R,R,
        A,A,    R,R,    G,G,    R,R,      E,E,    R,R,
      
      };
      head_tone = melody13[head_pointer];
    } 
    if(seq == 15) {
      byte melody14[] = {
  
        //bye------------ Wherever we're
        F,F,    F,F,    F,F,    F,F,      E,E,    E,E,
        F,F,    F,F,    F,F,    F,F,      E,E,    E,E,
        G,G,    G,G,    G,G,    R,R,      R,R,    G,R,
        G,G,    R,R,    A,A,    R,R,      C6,C6,    R,R,
      
      };
      head_tone = melody14[head_pointer];
    } 
    if(seq == 16) {
      
      byte melody15[] = {
  
        //standing, I won't take you for
        C6,C6,    C6,C6,    C6,C6,    R,R,      R,R,    R,R,
        A,A,      G,G,      G,G,      G,G,      R,R,    R,R,
        R,R,      R,R,      E,E,      R,R,      E,E,    R,R,
        G,G,      R,R,      A,A,      R,R,      C6,C6,  R,R,
      
      };
      head_tone = melody15[head_pointer];
    } 
    if(seq == 17 || seq == 57) {
      byte melody16[] = {
  
        //granted, Cause we'll never
        B,B,    B,B,    B,B,    R,R,      R,R,    R,R,
        B,B,    B,B,    A,A,    G,G,      G,G,    G,G,
        G,G,    G,G,    R,R,    R,R,      G,R,    E,R,
        G,G,    R,R,    A,A,    R,R,      B,B,    R,R,
      
      };

      head_tone = melody16[head_pointer];
    } 
    if(seq == 19) {
      byte melody17[] = {
  
        //time ------------------ So I'm gonna
        F,F,    F,F,    F,F,    F,F,      E,E,    E,E,
        F,F,    F,F,    F,F,    F,F,      E,E,    E,E,
        G,G,    G,G,    G,G,    R,R,      R,R,    G,R,
        G,G,    R,R,    D,D,    R,R,      C,C,    R,R,
      
      };
      head_tone = melody17[head_pointer];
    } 
    if(seq == 20) {
      byte melody18[] = {
  
        //love you, Like I'm gonna (chorus last part A-1 rhythmic)
        E,E,    R,R,    C,C,    R,R,      C,C,    R,R,
        E,E,    R,R,    C,C,    R,R,      C,C,    R,R,
        C,C,    R,R,    C,C,    R,R,      a,a,    R,R,
        C,C,    R,R,    D,D,    R,R,      E,E,    R,R,
      
      };
      head_tone = melody18[head_pointer];
    } 
    if(seq == 21) {

      byte melody19[] = {
        
        //lose you, I'm gonna (chorus last part A-2 rhythmic)
        D,D,    R,R,    b,b,    R,R,      b,b,    R,R,
        D,D,    R,R,    b,b,    R,R,      b,b,    R,R,
        b,b,    R,R,    b,b,    R,R,      b,b,    R,R,
        E,E,    R,R,    D,D,    R,R,      C,C,    R,R,
      
      };
      head_tone = melody19[head_pointer];
    }
    if(seq == 22) {const byte melody20[] = {
  
        //love you, Like I'm gonna (chorus last part B-1 rhythmic)
        E,E,    R,R,    C,C,    R,R,      C,C,    R,R,
        E,E,    R,R,    C,C,    R,R,      C,C,    R,R,
        C,C,    R,R,    C,C,    R,R,      C,C,    R,R,
        C,C,    R,R,    D,D,    R,R,      D,D,    R,R,
      
      };
      head_tone = melody20[head_pointer];
    }
    
    if(seq == 23) {
      byte melody21[] = {
  
        //lose ---------- you (chorus last part B-2)
        F,F,    F,F,    F,F,    F,F,      R,R,    R,R,
        E,E,    E,E,    E,E,    E,E,      R,R,    R,R,
        D,D,    D,D,    D,D,    D,D,      R,R,    R,R,
        C,C,    C,C,    C,C,    C,C,      R,R,    R,R,
      
      };
      head_tone = melody21[head_pointer];
    }
    
    //Verse 2
    if(seq == 24) {
      byte melody22[] = {
        
        //in a blink of an eye, 
        R,R,    R,R,    R,R,    R,R,      g,R,    g,R,
        g,g,    R,R,    a,a,    R,R,      C,C,    R,R,
        C,C,    C,C,    C,C,    C,C,      C,C,    C,C,
        C,C,    C,C,    C,C,    R,R,      R,R,    R,R,
      
      };
      head_tone = melody22[head_pointer];
    }
    
    if(seq == 25) {
      
      byte melody23[] = {
  
        //just a whisper of smoke
        R,R,    R,R,    R,R,    R,R,      g,R,    g,R,
        g,g,    R,R,    a,a,    R,R,      C,C,    R,R,
        D,D,    D,D,    D,D,    D,D,      D,D,    D,D,
        D,D,    C,C,    a,a,    a,a,      a,a,    R,R,
      
      };
      head_tone = melody23[head_pointer];
    }
    
    if(seq == 26) {
      
      
      byte melody24[] = {
  
        //You could lose everything, the
        R,R,    R,R,    R,R,    R,R,      E,E,    E,E,
        E,E,    R,R,    D,D,    R,R,      C,C,    R,R,
        D,D,    R,R,    C,C,    R,R,      C,C,    C,C,
        C,C,    C,C,    R,R,    R,R,      a,a,    R,R,
      
      };
      head_tone = melody24[head_pointer];
    }
    
    if(seq == 27) {
      byte melody25[] = {
  
        //truth is you never know
        F,F,    F,F,    F,F,    R,R,      R,R,    R,R,
        E,E,    E,E,    R,R,    R,R,      D,D,    R,R,
        D,D,    D,D,    D,D,    R,R,      R,R,    R,R,
        C,C,    C,C,    R,R,    R,R,      a,a,    R,R,
      
      };
      head_tone = melody25[head_pointer];
    }
    
    if(seq == 28) {
      byte melody26[] = {
        
        //So I'll kiss you longer baby,
        g,g,    g,g,    R,R,    R,R,      G,G,    R,R,
        G,G,    R,R,    E,E,    R,R,      D,D,    R,R,
        D,D,    R,R,    C,C,    C,C,      C,C,    C,C,
        C,C,    R,R,    a,a,    R,R,      g,g,    R,R,
      
      };
      head_tone = melody26[head_pointer];
    }
    
    if(seq == 29) {
      
     byte melody27[] = {
  
        //Any chance that I get
        R,R,    R,R,    G,G,    R,R,      G,G,    R,R,
        G,G,    G,G,    G,G,    E,E,      D,D,    R,R,
        E,E,    E,E,    E,E,    E,E,      R,R,    R,R,
        D,D,    D,D,    R,R,    R,R,      C,R,    a,a,
      
      };
      head_tone = melody27[head_pointer];
    }
    if(seq == 30) {
      byte melody28[] = {
  
        //I'll make the most of the minutes and
        a,a,    a,a,    a,a,    a,a,      R,R,    R,R,
        C,C,    R,R,    D,D,    R,R,      C,C,    R,R,
        F,F,    R,R,    E,E,    R,R,      D,D,    R,R,
        C,C,    R,R,    D,D,    R,R,      C,C,    R,R,
      
      };
      head_tone = melody28[head_pointer];
    }
    
    if(seq == 31) {
      byte melody29[] = {
  
        //love with no regrets
        F,F,    F,F,    R,R,    R,R,      F,F,    R,R,
        E,E,    E,E,    R,R,    R,R,      D,D,    R,R,
        D,D,    D,D,    D,D,    D,D,      R,R,    R,R,
        C,C,    C,C,    C,C,    C,C,      R,R,    R,R,
      
      };
      head_tone = melody29[head_pointer];
    }
    
    if(seq == 32) {
      
      byte melody30[] = {
  
        //Let's take our time, To say what we want
        D,D,    R,R,    E,E,    R,R,      D,D,    R,R,
        E,E,    E,E,    R,R,    R,R,      R,R,    g,R,
        D,D,    R,R,    E,E,    R,R,      D,D,    R,R,
        G,G,    G,G,    G,G,    G,G,      R,R,    R,R,
      
      };
      head_tone = melody30[head_pointer];
    }
    
    if(seq == 33) {
      
      byte melody31[] = {
  
        //Use what we got before it's all gone,
        D,D,    R,R,    E,E,    R,R,      D,D,    R,R,
        E,E,    E,E,    R,R,    R,R,      R,R,    D,R,
        D,D,    R,R,    E,E,    R,R,      D,D,    R,R,
        A,A,    A,A,    A,A,    A,A,      A,A,    A,A,
      
      };
      head_tone = melody31[head_pointer];
    }
    
    if(seq == 34) {
      byte melody32[] = {
  
        //Cause no, we're not
        A,A,    G,G,    E,E,    E,E,      E,E,    E,E,
        E,E,    E,E,    R,R,    R,R,      C,C,    R,R,
        E,E,    E,E,    E,E,    R,R,      R,R,    R,R,
        E,E,    R,R,    E,E,    R,R,      E,E,    R,R,
      
      };
      head_tone = melody32[head_pointer];
    }
    
    if(seq == 35) {
      const byte melody33[] = {
  
        //promised tomorrow   So I'm gonna
        D,D,    R,R,    D,D,    R,R,      C,C,    R,R,
        D,D,    R,R,    C,C,    C,C,      C,C,    C,C,
        C,C,    C,C,    R,R,    R,R,      R,R,    G,R,
        G,G,    R,R,    A,A,    R,R,      C6,C6,  R,R,
      
      };
      head_tone = melody33[head_pointer];
    }
    
    //Chorus
    if(seq == 36) {
      byte melody34[] = {
        
        //love you,   Like I'm gonna
        C6,C6,    C6,C6,    C6,C6,    C6,C6,      R,R,    R,R,
        A,R,      G,G,      G,G,      G,G,        R,R,    R,R,
        R,R,      R,R,      R,R,      R,R,        E,E,    R,R,
        G,G,      R,R,      A,A,      R,R,        C6,C6,  R,R,
      
      };
      head_tone = melody34[head_pointer];
    }
    
    if(seq == 37) {
      byte melody35[] = {
  
        //lose you,        I'm gonna
        B,B,    B,B,    R,R,    R,R,      R,R,    R,R,
        B,B,    B,B,    B,B,    A,R,      G,G,    G,G,
        G,G,    G,G,    G,G,    G,G,      R,R,    R,R,
        G,G,    R,R,    A,A,    R,R,      B,B,    R,R,
      
      };
      head_tone = melody35[head_pointer];
    }
    
    if(seq == 38) {
      byte melody36[] = {
        
        //hold you, Like I'm saying good-
        A,A,    A,A,    A,A,    A,A,      R,R,    R,R,
        A,A,    A,A,    A,A,    A,A,      R,R,    R,R,
        R,R,    R,R,    A,A,    R,R,      A,A,    R,R,
        A,A,    R,R,    G,G,    R,R,      E,E,    R,R,
      
      };
      head_tone = melody36[head_pointer];
    }
    
    if(seq == 39) {
      byte melody37[] = {
  
        //bye~~~~~~~~~~~~  Wherever we're
        F,F,    F,F,    F,F,    F,F,      E,E,    E,E,
        F,F,    F,F,    F,F,    F,F,      E,E,    E,E,
        G,G,    G,G,    G,G,    G,G,      R,R,    G,R,
        G,G,    R,R,    A,A,    R,R,      C6,C6,    R,R,
      
      };
      head_tone = melody37[head_pointer];
    }
    
    if(seq == 40) {
      byte melody38[] = {
        //standing, I won't take you for
        C6,C6,    C6,C6,    C6,C6,    C6,C6,      R,R,      R,R,
        A,A,      G,G,      G,G,      G,G,        R,R,      R,R,
        R,R,      R,R,      E,E,      R,R,        E,E,      R,R,
        G,G,      R,R,      A,A,      R,R,        C6,C6,    R,R,
      
      };
      head_tone = melody38[head_pointer];
    }
    
    if(seq == 41) {
      byte melody39[] = {
        //granted~~~~~~~~ Cause we'll never
        B,B,      B,B,      B,B,      B,B,        R,R,      R,R,
        B,B,      B,B,      A,A,      G,G,        G,G,      G,G,
        G,G,      G,G,      G,G,      R,R,        G,R,      E,R,
        G,G,      R,R,      A,A,      R,R,        B,B,      R,R,
      
      };
      head_tone = melody39[head_pointer];
    }
    
    if(seq == 42 || seq == 58) {
      byte melody40[] = {
        //know when, When we'll run out of
        A,A,      A,A,      A,A,      A,A,        R,R,      R,R,
        A,A,      A,A,      A,A,      A,A,        R,R,      R,R,
        R,R,      R,R,      A,A,      R,R,        A,A,      R,R,
        A,A,      R,R,      G,G,      R,R,        E,E,      R,R,
      
      };
      head_tone = melody40[head_pointer];
    }
    
    
    if(seq == 43) {
      byte melody41[] = {
        //time~~~~~~~~~~` So I'm gonna
        F,F,      F,F,      F,F,      F,F,        E,E,      E,E,
        F,F,      F,F,      F,F,      F,F,        E,E,      E,E,
        G,G,      G,G,      R,R,      R,R,        R,R,      G,R,
        E,E,      R,R,      D,D,      R,R,        C,C,      R,R,
      
      };
      head_tone = melody41[head_pointer];
    }
    
    
    
    if(seq == 44) {
      byte melody44[] = {
        //Love you, Like I'm gonna
        E,E,      R,R,      C,C,      R,R,        C,C,      R,R,
        E,E,      R,R,      C,C,      R,R,        C,C,      R,R,
        C,C,      R,R,      C,C,      R,R,        a,a,      R,R,
        C,C,      R,R,      D,D,      R,R,        E,E,      R,R,
      
      };
      head_tone = melody44[head_pointer];
    }
    
    if(seq == 45) {
      byte melody45[] = {
        //lose you, I'm gonna
        D,D,      R,R,      b,b,      R,R,        b,b,      R,R,
        D,D,      R,R,      b,b,      R,R,        b,b,      R,R,
        b,b,      R,R,      b,b,      R,R,        b,b,      R,R,
        E,E,      R,R,      D,D,      R,R,        C,C,      R,R,
      
      };
      head_tone = melody45[head_pointer];
    }
    
    if(seq == 46) {
      byte melody46[] = {
        //love you, Like I'm gonna
        E,E,      R,R,      C,C,      R,R,        C,C,      R,R,
        E,E,      R,R,      C,C,      R,R,        C,C,      R,R,
        C,C,      R,R,      C,C,      R,R,        C,C,      R,R,
        C,C,      R,R,      D,D,      R,R,        D,D,      R,R,
      
      };
      head_tone = melody46[head_pointer];
    }
    
    if(seq == 47) {
      byte melody47[] = {
        //lose~~~~~~~~~~~ you~~~~~~~~~~~~
        F,F,      F,F,      F,F,      F,F,        R,R,      R,R,
        E,E,      E,E,      E,E,      E,E,        R,R,      R,R,
        D,D,      D,D,      D,D,      D,D,        R,R,      R,R,
        C,C,      C,C,      C,C,      C,C,        R,R,      R,R,
      
      };
      head_tone = melody47[head_pointer];
    }
    
    
    
    /* ----------------------- BRIDGE -------------------------------- */
    
    if(seq == 48) {
      byte melody48[] = {
        //BRIDGE01
        R,R,      R,R,      E,E,      R,R,        E,E,      R,R,
        E,E,      R,R,      D,D,      R,R,        E,E,      E,E,
        E,E,      E,E,      E,E,      R,R,        e,e,      R,R,
        e,e,      R,R,      d,d,      R,R,        c,c,      R,R,
      
      };
      head_tone = melody48[head_pointer];
    }
    
    if(seq == 49) {
      byte melody49[] = {
        //BRIDGE02
        b3,b3,      R,R,      E,E,        R,R,        E,E,        R,R,
        E,E,        R,R,      E,E,        R,R,        E,E,        R,R,
        d,d,        d,d,      d,d,        R,R,        c,c,        c,c,
        c,c,        R,R,      b3,b3,      b3,b3,      b3,b3,      R,R,
      
      };
      head_tone = melody49[head_pointer];
    }
    
    if(seq == 50) {
      byte melody50[] = {
        //BRIDGE03
        a3,a3,      R,R,      a,a,        R,R,        a,a,        R,R,
        a,a,        R,R,      a,a,        R,R,        a,a,        a,a,
        a,a,        a,a,      a,a,        a,a,        R,R,        R,R,
        R,R,        R,R,      g,g,        R,R,        C,C,        R,R,
      
      };
      head_tone = melody50[head_pointer];
    }
    
    if(seq == 51) {
      byte melody51[] = {
        //BRIDGE04 lalalala ..... I'm gonna
        E,E,      E,E,      E,E,        R,R,        D,D,        D,D,
        D,D,      R,R,      C,C,        C,C,        C,C,        R,R,
        a,a,      R,R,      g,g,        R,R,        e,e,        R,R,
        g,g,      R,R,      a,a,        R,R,        C,C,        R,R,
      
      };
      head_tone = melody51[head_pointer];
    }
    
    /* --------------------- END BRIDGE -------------------------------- */
    
    if(seq == 52) {
      byte melody52[] = {
        //love you, Like I'm gonna
        C,C,      C,C,      C,C,        C,C,        R,R,        R,R,
        a,a,      g,g,      g,g,        g,g,        g,g,        R,R,
        R,R,      R,R,      R,R,        R,R,        D,D,        R,R,
        D,D,      R,R,      E,E,        R,R,        C,C,        R,R,
      
      };
      head_tone = melody52[head_pointer];
    }
    
    if(seq == 53) {
      byte melody53[] = {
        //lose you, I'm gonna
        D,D,      D,D,      D,D,        D,D,        R,R,        R,R,
        D,D,      D,D,      D,D,        D,D,        D,D,        D,D,
        R,R,      R,R,      R,R,        R,R,        R,R,        R,R,
        C,C,      R,R,      b,b,        R,R,        a,a,        R,R,
      
      };
      head_tone = melody53[head_pointer];
    }
    
    if(seq == 54) {
      byte melody54[] = {
        //hold you, Like I'm saying good
        C,C,      C,C,      C,C,        C,C,        R,R,        R,R,
        C,C,      C,C,      C,C,        C,C,        R,R,        R,R,
        R,R,      R,R,      a,a,        R,R,        a,a,        R,R,
        a,a,      R,R,      g,g,        R,R,        g,g,        R,R,
      
      };
      head_tone = melody54[head_pointer];
    }
    
    if(seq == 55) {
      byte melody55[] = {
        //bye~~~~~~~~~~`  Wherever we're
        g,g,      R,R,      a,a,        R,R,        C,C,        R,R,
        D,D,      D,D,      R,R,        R,R,        C,C,        R,R,
        G,G,      G,G,      R,R,        R,R,        R,R,        G,R,
        G,G,      R,R,      A,A,        R,R,        C6,C6,        R,R,
      
      };
      head_tone = melody55[head_pointer];
    }
    
    if(seq == 56) {
      byte melody56[] = {
        //standing, I won't take your for
        C6,C6,      C6,C6,      C6,C6,        C6,C6,        R,R,          R,R,
        A,A,        R,R,        G,G,          G,G,          G,G,          R,R,
        R,R,        R,R,        E,E,          R,R,          E,E,          R,R,
        G,G,        R,R,        A,A,          R,R,          C6,C6,        R,R,
      
      };
      head_tone = melody56[head_pointer];
    }
    
    if(seq == 59) {
      byte melody59[] = {
        //time~~~~~~~~~ So I'm gonna
        F,F,      F,F,      F,F,        F,F,        E,E,          E,E,
        F,F,      F,F,      F,F,        F,F,        E,E,          E,E,
        G,G,      G,G,      G,G,        R,R,        G,G,          R,R,
        A,A,      R,R,      G,G,        R,R,        E,E,          R,R,
      
      };
      head_tone = melody59[head_pointer];
    }
    
    if(seq == 60) {
      byte melody60[] = {
        //love you, Like I'm gonna
        A,A,      R,R,      G,G,        G,G,        G,G,          R,R,
        G,G,      G,G,      G,G,        G,G,        R,R,          R,R,
        R,R,      R,R,      R,R,        R,R,        E,E,          R,R,
        A,A,      R,R,      A,A,        R,R,        G,G,          R,R,
      
      };
      head_tone = melody60[head_pointer];
    }
    
    if(seq == 61) {
      byte melody61[] = {
        //lose you, I'm gonna
        B,B,      R,R,      A,A,        R,R,        G,G,          G,G,
        G,G,      R,R,      D,D,        D,D,        D,D,          D,D,
        R,R,      R,R,      R,R,        R,R,        R,R,          R,R,
        E,E,      R,R,      D,D,        R,R,        C,C,          R,R,
      
      };
      head_tone = melody61[head_pointer];
    }
    
    if(seq == 62) {
      byte melody62[] = {
        //love you, like I'm gonna
        E,E,      R,R,      C,C,        R,R,        C,C,          R,R,
        E,E,      R,R,      C,C,        R,R,        C,C,          R,R,
        C,C,      C,C,      C,C,        R,R,        a,a,          R,R,
        C,C,      R,R,      D,D,        R,R,        C,C,          R,R,
      
      };
      head_tone = melody62[head_pointer];
    }
    
    if(seq == 63) {
      byte melody63[] = {
        //lose~~~~~~~~` you~~~~~ 
        F,F,      F,F,      F,F,        F,F,        F,F,          R,R,
        E,E,      E,E,      E,E,        E,E,        E,E,          R,R,
        D,D,      D,D,      D,D,        D,D,        D,D,          R,R,
        C,C,      C,C,      C,C,        C,C,        C,C,          R,R,
      
      };
      head_tone = melody63[head_pointer];
    }
    
    if(seq == 64) {
      byte melody64[] = {
        //endiiiing
        e,e,      g,g,      C,C,        C,C,        C,C,          C,C,
        C,C,      C,C,      C,C,        C,C,        C,C,          C,C,
        R,R,      R,R,      R,R,        R,R,        R,R,          R,R,
        R,R,      R,R,      R,R,        R,R,        R,R,          R,R,
      
      };
      head_tone = melody64[head_pointer];
    }
    
    ///////////////////  END OF MELODY ////////////////////////
    
    last_note = current_time;
  }
  
}


// loop forever <3
void loop() {
  if(played == false) {
    
    //Plays the melody, selects the tone required.
    readMelody();
    
    playTone();      //play tone every loop.
    
  }
  
}
