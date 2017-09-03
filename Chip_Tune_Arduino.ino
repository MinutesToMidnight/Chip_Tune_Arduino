/*
   Chip_Tune_Arduino
   Original code by: Dipto Pratyaksa
   http://www.linuxcircle.com/2013/03/31/playing-mario-bros-tune-with-arduino-and-piezo-buzzer/
   Modified for this Arduino class as a personal exercise in de-obscification
   by the instructor
   __    __     __     __   __     __  __     ______   ______     ______
  /\ "-./  \   /\ \   /\ "-.\ \   /\ \/\ \   /\__  _\ /\  ___\   /\  ___\
  \ \ \-./\ \  \ \ \  \ \ \-.  \  \ \ \_\ \  \/_/\ \/ \ \  __\   \ \___  \
   \ \_\ \ \_\  \ \_\  \ \_\\"\_\  \ \_____\    \ \_\  \ \_____\  \/\_____\
    \/_/  \/_/   \/_/   \/_/ \/_/   \/_____/     \/_/   \/_____/   \/_____/
                               ______   ______
                              /\__  _\ /\  __ \
                              \/_/\ \/ \ \ \/\ \
                                 \ \_\  \ \_____\
                                  \/_/   \/_____/
   __    __     __     _____     __   __     __     ______     __  __     ______
  /\ "-./  \   /\ \   /\  __-.  /\ "-.\ \   /\ \   /\  ___\   /\ \_\ \   /\__  _\
  \ \ \-./\ \  \ \ \  \ \ \/\ \ \ \ \-.  \  \ \ \  \ \ \__ \  \ \  __ \  \/_/\ \/
   \ \_\ \ \_\  \ \_\  \ \____-  \ \_\\"\_\  \ \_\  \ \_____\  \ \_\ \_\    \ \_\
    \/_/  \/_/   \/_/   \/____/   \/_/ \/_/   \/_/   \/_____/   \/_/\/_/     \/_/

  MinutesToMidnight
  Now with more fun in every byte!

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#define buzzer_pin 10
#define led_pin 13

void setup()
{
        pinMode(buzzer_pin, OUTPUT);
        pinMode(led_pin, OUTPUT);
        digitalWrite(buzzer_pin, LOW);
        digitalWrite(led_pin, LOW);
}

void loop()
{
        //play music
        sing(1);
        sing(1);
        sing(2);
}

void sing(int song)
{
        source
        if (song == 1)
        {
                //"Main Theme"
                for (int i = 0; i < 78; i++)
                {
                        buzz(main_melody(i), (1000 / main_tempo(i)));
                        delay(1300 / main_tempo(i));
                }
        }
        if (song == 2)
        {
                //"Second Theme"
                for (int i = 0; i < 56; i++)
                {
                        buzz(second_melody(i), (1000 / second_tempo(i)));
                        delay(1300 / second_tempo(i));
                }
        }
}

void buzz(long frequency, long length)
{
        long delayValue = 1000000 / frequency / 2;
        long numCycles = frequency * length / 1000;
        for (long i = 0; i < numCycles; i++)
        {
                digitalWrite(buzzer_pin, HIGH); // write the buzzer pin high to push out the diaphram
                digitalWrite(led_pin, HIGH);
                delayMicroseconds(delayValue); // wait for the delay value
                digitalWrite(buzzer_pin, LOW); // write the buzzer pin low to pull back the diaphram
                digitalWrite(led_pin, LOW);
                delayMicroseconds(delayValue); // wait again for the delay value
        }
}

int main_melody(int index)
{
        const int data[78] PROGMEM =
        {
                2637, 2637, 0, 2637, 0, 2093, 2637, 0,
                3136, 0, 0, 0, 1568, 0, 0, 0,
                2093, 0, 0, 1568, 0, 0, 1319, 0,
                0, 1760, 0, 1976, 0, 1865, 1760, 0,
                1568, 2637, 3136, 3520, 0, 2794, 3136,
                0, 2637, 0, 2093, 2349, 1976, 0, 0,
                2093, 0, 0, 1568, 0, 0, 1319, 0,
                0, 1760, 0, 1976, 0, 1865, 1760, 0,
                1568, 2637, 3136, 3520, 0, 2794, 3136,
                0, 2637, 0, 2093, 2349, 1976, 0, 0
        };
        return data[index];
}

int main_tempo(int index)
{
        const int data[78] PROGMEM =
        {
                12, 12, 12, 12, 12, 12, 12, 12,
                12, 12, 12, 12, 12, 12, 12, 12,
                12, 12, 12, 12, 12, 12, 12, 12,
                12, 12, 12, 12, 12, 12, 12, 12,
                9, 9, 9,
                12, 12, 12, 12, 12, 12, 12, 12,
                12, 12, 12, 12, 12, 12, 12, 12,
                12, 12, 12, 12, 12, 12, 12, 12,
                12, 12, 12, 12,
                9, 9, 9,
                12, 12, 12, 12, 12, 12, 12, 12,
                12, 12, 12, 12,
        };
        return data[index];
}

int second_melody(int index)
{
        const int data[56] PROGMEM =
        {
                262, 523, 220, 440, 233, 466, 0, 0,
                262, 523, 220, 440, 233, 466, 0, 0,
                175, 349, 147, 294, 156, 311, 0, 0,
                175, 349, 147, 294, 156, 311, 0, 0,
                311, 277, 294, 277, 311, 311, 208, 196,
                277, 262, 370, 349, 165, 466, 440, 415,
                311, 247, 233, 220, 208, 0, 0, 0
        };
        return data[index];
}

int second_tempo(int index)
{
        const int data[56] PROGMEM =
        {
                12, 12, 12, 12, 12, 12, 6,
                3,  12, 12, 12, 12,
                12, 12, 6, 3, 12, 12, 12, 12,
                12, 12, 6, 3, 12, 12, 12, 12,
                12, 12, 6, 6, 18, 18, 18,
                6, 6, 6, 6, 6, 6,
                18, 18, 18, 18, 18, 18,
                10, 10, 10, 10, 10, 10,
                3, 3, 3

        };
        return data[index];
}
