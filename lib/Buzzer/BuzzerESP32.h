#include <Arduino.h>

using namespace std;
// *********************************
///\brief class that handles sounds
class Buzzer
{
private:
    void tone(uint16_t pin, uint16_t freq, uint16_t msDur)
    {
        // configure LED PWM functionalitites
        uint16_t channel = 0;
        ledcSetup(channel, freq, 8);

        // attach the channel to the GPIO to be controlled
        ledcAttachPin(pin, channel);

        //output a Middle C
        ledcWriteTone(channel, freq);
        delay(msDur);

        ledcDetachPin(pin);
    }

public:
    uint32_t pinBuzzer;

    Buzzer(uint32_t pin)
    {
        pinBuzzer = pin;
        pinMode(pinBuzzer, OUTPUT); //
    }
    // *****************************  interface init
    /// \brief types of tones that can be played
    enum class ToneType
    {
        ok,
        wrong,
        middle
    };
    // *****************************  interface init
    void beep(ToneType toneType)
    {
        switch (toneType)
        {
        case ToneType::ok:
            tone(pinBuzzer, 2200, 100);
            delay(100);
            break;
        case ToneType::wrong:
            tone(pinBuzzer, 220, 100);
            // tone(pinBuzzer, 440, 100);
            delay(100);
            break;
        case ToneType::middle:
            tone(pinBuzzer, 1800, 100);
            delay(100);
            break;
        }
    }
};
