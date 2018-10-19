// Helper functions for music
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include "helpers.h"
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int X = atoi(&fraction[0]);
    int Y = atoi(&fraction[2]);
    int X_Y = 8 * X / Y;
    return X_Y;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // notes in alphabetic order
    char NOTES[] = {'A', 'B', 'C', 'D',
                    'E', 'F', 'G'
                    };
    // already had it written this way but -12 within same octave, or add bounce for next octave values
    int bounce[] = {0, 2, 3, 5, 7, 8, 10};
    int n;
    // size of array from memory of total divided by that of one value
    for (int i = 0; i < sizeof(NOTES) / sizeof(NOTES[0]); i++)
    {
        if (note[0] == NOTES[i])
        {
            int v = bounce[i];
            // for sharps and flats
            if (note[1] == '#' || note[1] == 'b')
            {
                if (note[0] == 'A' || note[0] == 'B')
                    n = 12 * (atoi(&note[2]) - 4) + v;
                else
                    n = 12 * (atoi(&note[2]) - 4) + v - 12;
                if (note[1] == '#')
                    n += 1;
                else
                    n -= 1;
                return round(pow(2., (n / 12.)) * 440.);
            }
            // for whole notes that are A or B
            else
            {
                if (note[0] == 'A' || note[0] == 'B')
                {
                    n = 12 * (atoi(&note[1]) - 4) + v;
                    return round(pow(2., (n / 12.)) * 440.);
                }

                // all the other notes C, D, E, F, G ; as they are lower within the same octave
                else
                {
                    n = 12 * (atoi(&note[1]) - 4) + v - 12;
                    return round(pow(2., (n / 12.)) * 440.);
                }
            }
        }
    }
    // need this if function return is not void
    return 0;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
