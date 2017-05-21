#include <IRremote.h>
#include <toneAC.h>
#include <pitches.h>
#define power 0x61A0F00F
#define tv 0x61A0F20D
#define video 0x61A032CD
#define hdmi 0x61A00AF5
#define acc 0x61A01DE2
#define one 0x61A000FF
#define two 0x61A0807F
#define three 0x61A040BF
#define four 0x61A0C03F
#define five 0x61A020DF
#define six 0x61A0A05F
#define seven 0x61A0609F
#define eight 0x61A0E01F
#define nine 0x61A010EF
#define period 0x61A0827D
#define zero 0x61A0906F
#define arrows 0x61A008F7
#define menu 0x61A028D7
#define exit 0x61A0D827
#define Home 0x61A09D62
#define info 0x61A0E817
#define enter 0x61A018E7
#define up 0x61A042BD
#define down 0x61A0C23D
#define left 0x61A06897
#define right 0x61A0A857
#define input 0x61A0B847
#define chlist 0x61A0619E
#define favorite 0x61A0D22D
#define cdd 0x61A038C7
#define volumeUp 0x61A030CF
#define volumeDown 0x61A0B04F
#define mute 0x61A0708F
#define channelUp 0x61A050AF
#define channelDown 0x61A0D02F
#define sleep 0x61A0C837
#define zoom 0x61A022DD
#define mtssap 0x61A08877
#define picture 0x61A0926D
#define play 0x61A00EF1
#define pause 0x61A0817E
#define square 0x61A08E71
#define audio 0x61A012ED
#define backward 0x61A07E81
#define forward 0x61A0BE41
#define fastForward 0x61A001FE
#define rewind 0x61A0FE01

IRrecv irrecv(11);
decode_results results;
int Simple[] = { 62, 196, 196, 220, 196, 0, 247, 262};
int SimpleDurations[] = { 4, 8, 8, 4, 4, 4, 4, 4 };
int DancingQueenNotes[] = {NOTE_CS5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_B4,
                           NOTE_CS5, NOTE_CS5, NOTE_CS5, NOTE_A5, NOTE_A5, NOTE_GS5, NOTE_GS5,
                           NOTE_FS5, NOTE_FS5,
                          };
int DancingQueenDurations[] = {1500, 500, 1500, 125, 250, 125, 375, 125, 500, 375, 125, 375,
                               125, 375, 125, 1500,
                             };
int meglovaniaNotes[] {294, 294, 587, 440, 415, 0, 392, 349, 294, 349, 392};
float meglovaniaDurations[] {125, 125, 250, 375, 125, 131.25, 250, 250, 125, 125, 125};
int allnotes[52] {
  31, 33, 37, 41, 44, 49, 55, 62, 65, 73, 
  82, 87, 98, 110, 123, 131, 147, 165, 175, 196,
  220, 247, 262, 294, 330, 349, 392, 440, 494, 523,
  587, 659, 698, 784, 880, 988, 1047, 1175,1319, 1397,
  1568, 1760, 1976, 2093, 2349, 2637, 2794, 3136, 3520, 3951,
  4186, 4699
};
int allnotesPostistions[] {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
int t = 150;
int v = 10;

void setup()
{

  irrecv.enableIRIn(); // Start the receiver
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
   pinMode(A4, OUTPUT);
  digitalWrite(A4, LOW); 
Serial.begin(9600);



}

void loop() {
  notes();
  variables();
  songs();
  if (irrecv.decode(&results)) {
delayMicroseconds(10);
  Serial.println(results.value, HEX);

    irrecv.resume(); // Receive the next value


  }
}
void notes() {
  if (results.value == one) {
    toneAC(allnotes[allnotesPostistions[0]], v, t);
    results.value = 0xF;
  }
  if (results.value == two) {
    toneAC(allnotes[allnotesPostistions[1]], v, t);
    results.value = 0xF;
  }
  if (results.value == three) {
    toneAC(allnotes[allnotesPostistions[2]], v, t);
    results.value = 0xF;
  }
  if (results.value == four) {
    toneAC(allnotes[allnotesPostistions[3]], v, t);
    results.value = 0xF;
  }
  if (results.value == five) {
    toneAC(allnotes[allnotesPostistions[4]], v, t);
    results.value = 0xF;
  }
  if (results.value == six) {
    toneAC(allnotes[allnotesPostistions[5]], v, t);
    results.value = 0xF;
  }
  if (results.value == seven) {
    toneAC(allnotes[allnotesPostistions[6]], v, t);
    results.value = 0xF;
  }
  if (results.value == eight) {
    toneAC(allnotes[allnotesPostistions[7]], v, t);
    results.value = 0xF;
  }
  if (results.value == nine) {
    toneAC(allnotes[allnotesPostistions[8]], v, t);
    results.value = 0xF;
  }
  if (results.value == zero) {
    toneAC(allnotes[allnotesPostistions[9]], v, t);
    results.value = 0xF;
  }
}
void variables() {
  if (results.value == up && allnotesPostistions[9] < 40 ) {
    for (int addition = 0; addition < 11; addition++) {
      allnotesPostistions[addition] += 10;

    }
    results.value = 0xF;
  }
  if (results.value == down && allnotesPostistions[9] > 10) {
    for (int subtraction = 0; subtraction < 11; subtraction++) {
      allnotesPostistions[subtraction] -= 10;
    }
    results.value = 0xF;
  }

  if (results.value == right && t < 251) {
    t = t + 50;
    results.value = 0xF;
  }

  if (results.value == left && t > 51) {
    t = t - 50;
    results.value = 0xF;
  }

  if (results.value == Home) {
    for (int Reset = 0; Reset < 11; Reset++) {
      allnotesPostistions[Reset] = Reset + 20;
    }

    t = 150;
    v = 8;
    results.value = 0xF;
  }
  if (results.value == volumeUp && v < 10) {
    v = v + 1;
    results.value = 0xF;
  }
  if (results.value == volumeDown && v > 0) {
    v = v - 1;
    results.value = 0xF;
  }
}
void songs() {
  if (results.value == input) {
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      int noteDuration = 1000 / SimpleDurations[thisNote];
      toneAC(Simple[thisNote], v, noteDuration, true);
      delay(noteDuration * 4 / 3);
    }
    results.value = 0xF;
  }
  if (results.value == chlist) {
    for (int thisNotetwo = 0; thisNotetwo < 16; thisNotetwo++) {
      int noteDurationtwo = DancingQueenDurations[thisNotetwo];
      toneAC(DancingQueenNotes[thisNotetwo], v, noteDurationtwo, true);
      delay(noteDurationtwo);
    }
    results.value = 0xF;
  }
  if (results.value == favorite) {
    for (int thisNotethree = 0; thisNotethree < 12; thisNotethree++) {
      int noteDurationthree = meglovaniaDurations[thisNotethree] - (meglovaniaDurations[thisNotethree] * 0.3);
      toneAC(meglovaniaNotes[thisNotethree], v, noteDurationthree, true);
      delay(meglovaniaDurations[thisNotethree] - (meglovaniaDurations[thisNotethree] * 0.05));
    }
    results.value = 0xF;
  }
  if (results.value == mute) {
    v = 0;
    results.value = 0xF;
  }
}

