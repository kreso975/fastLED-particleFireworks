#include <FastLED.h>
#include <vector>
#include "Font6x8.h"

#define DEBUG 0

#define LED_PIN 0
#define COLOR_ORDER GRB
#define CHIPSET WS2812B
#define BRIGHTNESS 10

const uint8_t kMatrixWidth = 32;
const uint8_t kMatrixHeight = 8;

// Param for different pixel layouts
const bool kMatrixSerpentineLayout = true;
const bool kMatrixVertical = true;

#define NUM_LEDS (kMatrixWidth * kMatrixHeight)
CRGB leds_plus_safety_pixel[NUM_LEDS + 1];
CRGB* const leds(leds_plus_safety_pixel + 1);


// Global variables for initial velocity, gradual deceleration, and other parameters
const float INITIAL_VELOCITY = 1.5;
const float DECELERATION_FACTOR = 0.75;
const int PARTICLE_LIFE = 70;
const int PARTICLE_COUNT = 20;
const int EXPLOSION_FREQUENCY = 1;
const int UPDATE_RATE = 50;

const char* message = "MERRY CHRISTMAS";

CRGB tempBufferText[NUM_LEDS];
CRGB tempBufferParticles[NUM_LEDS];
CRGB tempBufferMessage[NUM_LEDS];

unsigned long previousMillisText = 0;
unsigned long previousMillisParticles = 0;
unsigned long previousMillisMessage = 0;
const long intervalText = 20; // Update rate for drawText in milliseconds
const long intervalParticles = UPDATE_RATE; // Update rate for addParticles in milliseconds
const long intervalMessage = 20; // Update rate for displayMessage in milliseconds

unsigned long previousMillisSwitch = 0;
const long switchInterval = 20000; // Switch interval in milliseconds (20 seconds)
bool showText = true;

uint16_t XY(uint8_t x, uint8_t y)
{
	uint16_t i;
	if (kMatrixSerpentineLayout == false)
	{
		if (kMatrixVertical == false)
			i = (y * kMatrixWidth) + x;
		else
			i = kMatrixHeight * (kMatrixWidth - (x + 1)) + y;
	}

	if (kMatrixSerpentineLayout == true)
	{
		if (kMatrixVertical == false)
		{
			if (y & 0x01)
			{
				// Odd rows run backwards
				uint8_t reverseX = (kMatrixWidth - 1) - x;
				i = (y * kMatrixWidth) + reverseX;
			}
			else
			{
				// Even rows run forwards
				i = (y * kMatrixWidth) + x;
			}
		}
		else
		{ // vertical positioning
			if (x & 0x01)
				i = kMatrixHeight * (kMatrixWidth - (x + 1)) + y;
			else
				i = kMatrixHeight * (kMatrixWidth - x) - (y + 1);
		}
	}

	return i;
}

uint16_t XYsafe(uint8_t x, uint8_t y)
{
	if (x >= kMatrixWidth)
		return -1;
	if (y >= kMatrixHeight)
		return -1;
	if (x < 0)
		return -1;
	if (y < 0)
		return -1;
	return XY(x, y);
}

class Particle
{
public:
	float x, y;
	CRGB color;
	float xvel, yvel;
	int life;

	Particle(float x, float y, CRGB color)
	{
		this->x = x;
		this->y = y;
		this->color = color;
		this->xvel = random(-100, 100) / (100.0 / INITIAL_VELOCITY); // Use global initial velocity
		this->yvel = random(-100, 100) / (100.0 / INITIAL_VELOCITY); // Use global initial velocity
		this->life = PARTICLE_LIFE;									 // Use global particle life
	}

	void update(CRGB* buffer)
	{
		draw(buffer);
		slowDown();
		life -= 5;
	}


	void draw( CRGB* buffer )
	{
		// Ensure particles stay within bounds
		if ( x >= 0 && x < kMatrixWidth && y >= 0 && y < kMatrixHeight )
		{
			int index = XYsafe(static_cast<uint8_t>(x), static_cast<uint8_t>(y));
			if ( index != -1 )
				buffer[index] += color; // Use additive blending
		}
		x += xvel;
		y += yvel;

		// Mark particle as dead if out of bounds
		if ( x < 0 || x > kMatrixWidth || y < 0 || y > kMatrixHeight )
			life = -1;
	}

	bool isDead() {
		return life < 0;
	}

	void slowDown() {
		xvel *= DECELERATION_FACTOR; // Use global deceleration factor
		yvel *= DECELERATION_FACTOR; // Use global deceleration factor
	}
};

std::vector<Particle> particles;

void setup()
{
  #if ( DEBUG == 1 )
	Serial.begin ( 9600 );
	delay(1000);
	//Serial.setDebugOutput(true);
	#endif
  
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 700); // cap on 700mA
  FastLED.setBrightness(BRIGHTNESS);    
  //FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.setBrightness(BRIGHTNESS);
}
unsigned long previousMillis = 0;
void loop()
{
    unsigned long currentMillis = millis();
		FastLED.clear();

    // Switch between drawText and displayMessage every 20 seconds
    if ( currentMillis - previousMillisSwitch >= switchInterval )
    {
      previousMillisSwitch = currentMillis;
      showText = !showText; // Toggle between true and false
    }
		
		if ( showText )
    {
      // Update drawText at its own interval
      if ( currentMillis - previousMillisText >= intervalText )
      {
        previousMillisText = currentMillis;
        memset( tempBufferText, 0, sizeof(tempBufferText) ); // Clear temp buffer
        drawText(tempBufferText); // Update temp buffer
      }
      memset( tempBufferMessage, 0, sizeof(tempBufferMessage) ); // Clear temp buffer for displayMessage
    }
    else
    {
      // Update displayMessage at its own interval
      if ( currentMillis - previousMillisMessage >= intervalMessage )
      {
        previousMillisMessage = currentMillis;
        memset( tempBufferMessage, 0, sizeof(tempBufferMessage) ); // Clear temp buffer
        displayMessage( tempBufferMessage, CRGB::Red, message, 6); // Update temp buffer
      }
      memset( tempBufferText, 0, sizeof(tempBufferText) ); // Clear temp buffer for drawText
    }
		// Update addParticles at its own interval
		if ( currentMillis - previousMillisParticles >= intervalParticles )
		{
			previousMillisParticles = currentMillis;
			memset( tempBufferParticles, 0, sizeof(tempBufferParticles) ); // Clear temp buffer
			addParticles( tempBufferParticles ); // Update temp buffer
		}
		
		// Combine buffers
		for (int i = 0; i < NUM_LEDS; i++)
		{
			leds[i] = tempBufferText[i] + tempBufferMessage[i] + tempBufferParticles[i]; // Combine buffers - tempBufferText[i] + tempBufferMessage
		}
		FastLED.show();
}



void addParticles( CRGB* buffer )
{
	//  Continuously generate explosion particles, concentrating between rows 3 and 6
	if (random(10) < EXPLOSION_FREQUENCY)
	{
		int x = random(kMatrixWidth);
		int y = random(1, 6); // Concentrate explosions between rows 1 and 6
		CRGB color = CRGB(random(256), random(256), random(256));

		for (int i = 0; i < PARTICLE_COUNT; i++)
			particles.push_back(Particle(x, y, color));
	}

	for (size_t i = 0; i < particles.size(); i++)
	{
		particles[i].update(buffer); // Update each particle

		if (particles[i].isDead())
		{
			particles.erase(particles.begin() + i);
			i--;
		}
	}
}

