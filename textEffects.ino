
void drawText( CRGB* buffer )
{
	static uint8_t brightness = 30;
	static bool increasing = true;

	// Draw flipped "WIN" in the center with varying brightness
	CRGB color = CRGB(255, 0, 0);
	color.nscale8(brightness);

	// W
	for (int y = 1; y < 7; y++)
	{
		buffer[XYsafe(23, y)] = color;
		buffer[XYsafe(22, y)] = color;
		buffer[XYsafe(18, y)] = color;
		buffer[XYsafe(17, y)] = color;
	}
	buffer[XYsafe(21, 5)] = color;
	buffer[XYsafe(21, 4)] = color;
	buffer[XYsafe(20, 4)] = color;
	buffer[XYsafe(20, 3)] = color;
	buffer[XYsafe(19, 5)] = color;
	buffer[XYsafe(19, 4)] = color;

	// I
	for (int y = 1; y < 7; y++)
	{
		buffer[XYsafe(15, y)] = color;
		buffer[XYsafe(14, y)] = color;
	}

	// N
	for (int y = 1; y < 7; y++)
	{
		buffer[XYsafe(12, y)] = color;
		buffer[XYsafe(11, y)] = color;
		buffer[XYsafe(8, y)] = color;
		buffer[XYsafe(7, y)] = color;
	}
	buffer[XYsafe(10, 3)] = color;
	buffer[XYsafe(10, 4)] = color;
	buffer[XYsafe(9, 4)] = color;
	buffer[XYsafe(9, 5)] = color;

	// Adjust brightness
	if (increasing)
	{
		brightness += 20;
		if (brightness >= 255)
			increasing = false;
	}
	else
	{
		brightness -= 20;
		if (brightness <= 40)
			increasing = true;
	}
}

String convertToSingleByte(String input)
{
	String output = "";
	for (int i = 0; i < input.length(); i++)
	{
		char c = input.charAt(i);
		if (c == 0xC4 || c == 0xC5)
		{
			char nextChar = input.charAt(i + 1);
			switch (nextChar)
			{
				case 0x8D: output += (char)0xE8; i++; break; // č (C4)
				case 0x8C: output += (char)0xC8; i++; break; // Č (C4)
				case 0x87: output += (char)0xE6; i++; break; // ć (C4)
				case 0x86: output += (char)0xC6; i++; break; // Ć (C4)
				case 0xBE: output += (char)0x9E; i++; break; // ž (C5)
				case 0xBD: output += (char)0x8E; i++; break; // Ž (C5)
				case 0xA1: output += (char)0x9A; i++; break; // š (C5)
				case 0xA0: output += (char)0x8A; i++; break; // Š (C5)
				case 0x91: output += (char)0xF0; i++; break; // đ (C5)
				case 0x90: output += (char)0xD0; i++; break; // Đ (C5)
				default: output += c; break;
			}
		}
		else
		{
			output += c;
		}
	}
	return output;
}

void displayMessage( CRGB *buffer, CRGB colorScroll, const char *message, int numSpaces )
{
	static uint8_t brightness = 30;
	static bool bufferInitialized = false;
	static CRGB *displayBuffer = nullptr; // Pointer to store the buffer
	static int bufferSize = 0;
	static String previousMessage = "";
	static int previousNumSpaces = 0;
	static int scrollPosition = 0; // Make scrollPosition static
	colorScroll.nscale8(brightness);

	String convertedMessage = convertToSingleByte(message);

	// Check if the message or number of spaces has changed
	if (previousMessage != convertedMessage || previousNumSpaces != numSpaces)
	{
		// Free the old buffer if it exists
		if  (displayBuffer != nullptr )
		{
			delete[] displayBuffer;
		}

		// Calculate the new buffer size
		bufferSize = (convertedMessage.length() + numSpaces) * 6 * kMatrixHeight;
		displayBuffer = new CRGB[bufferSize]; // Allocate memory for the new buffer

		// Initialize the buffer with the new message and spaces
		for (int i = 0; i < bufferSize; i++)
		{
			displayBuffer[i] = CRGB::Black;
		}

		// Add spaces in front of the message
		for (int i = 0; i < numSpaces; i++)
		{
			int charPosition = i * 6;
			for (int x = 0; x < 6; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					int bufferIndex = (charPosition + x) + (y * (convertedMessage.length() + numSpaces) * 6);
					if (bufferIndex < bufferSize)
					{
						displayBuffer[bufferIndex] = CRGB::Black;
					}
				}
			}
		}

		for (int i = 0; i < convertedMessage.length(); i++)
		{
			char charToDisplay = convertedMessage.charAt(i);
			int charPosition = (i + numSpaces) * 6;
			for (int x = 0; x < 6; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					if (bitRead(pgm_read_byte(&(Font[charToDisplay][x])), y) == 1)
					{
						int bufferIndex = (charPosition + x) + (y * (convertedMessage.length() + numSpaces) * 6);
						if (bufferIndex < bufferSize)
						{
							displayBuffer[bufferIndex] = colorScroll;
						}
					}
				}
			}
		}

		previousMessage = convertedMessage; // Update the previous message
		previousNumSpaces = numSpaces;		// Update the previous number of spaces
		scrollPosition = 0;					// Reset the scroll position
	}

	// Copy the relevant part of the buffer to the LED matrix
	for (int x = 0; x < kMatrixWidth; x++)
	{
		for (int y = 0; y < kMatrixHeight; y++)
		{
			int bufferIndex = (scrollPosition + x) % ((convertedMessage.length() + numSpaces) * 6) + (y * (convertedMessage.length() + numSpaces) * 6);
			if (bufferIndex < bufferSize)
			{
				buffer[XYsafe(kMatrixWidth - 1 - x, y)] += displayBuffer[bufferIndex]; // Use buffer instead of leds
			}
		}
	}

	scrollPosition++;
	if (scrollPosition >= (convertedMessage.length() + numSpaces) * 6)
	{
		scrollPosition = 0;
	}
}
