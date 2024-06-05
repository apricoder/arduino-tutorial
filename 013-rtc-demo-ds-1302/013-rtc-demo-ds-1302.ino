// Instalacja biblioteki "Rtc by Makuna"

#include <ThreeWire.h>  
#include <RtcDS1302.h>

//Stworzenie obiektu Rtc

ThreeWire myWire(A0,A1,A2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

void setup() {

    //Ustawienie portu szeregowego
    Serial.begin(9600);

    //Wydrukowanie daty systemowej 
    Serial.print("Data systemowa: ");
    Serial.println(__DATE__);
    Serial.print("Godzina systemowa: ");
    Serial.println(__TIME__);

    Rtc.Begin();
    
    //Serial.print("Zmieniamy datę zegara: ");
    //RtcDateTime czasWlasny = RtcDateTime("Feb 21 2010","00:00:00");
    //Rtc.SetDateTime(czasWlasny);
    //Serial.println(czasWlasny);
    //Serial.println(Rtc.GetDateTime());
    //printDateTime(Rtc.GetDateTime());
    //delay(3000);
    
    RtcDateTime czas = RtcDateTime(__DATE__, __TIME__);
    Rtc.SetDateTime(czas);
    printDateTime(Rtc.GetDateTime());

}

void loop() {
    Serial.print("Data pobrana z zegara RTC: ");
    printDateTime(Rtc.GetDateTime());
    //Serial.println(Rtc.GetDateTime());
    delay(1000);
    
}

#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt) {
    char datestring[20];
    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Month(), dt.Day(), dt.Year(),
            dt.Hour(), dt.Minute(), dt.Second() );
    Serial.println(datestring);
}
