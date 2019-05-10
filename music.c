#include <string.h>
#include <cs50.h>
#include <math.h>



//converts a fraction formatted as x/y to eights
int duration (string fraction);
int main (void)
{
    float fraction[3];
    float numerator = (int) fraction[0]-'0';
    float denominator = (int) fraction[2]-'0';
    float length = (numerator * 8)/denominator;
    return length;
}
// calculates frequency(in Hz) of a note
int frequency(string note)
{
    int octive = note[strlen(note)-1]-'0';
    //base frequency of A4 is 440hz
    double freq = 440.0;

    //adjust  letter
    switch(note[0])
{
    case 'C':
    freq /= pow(2.0, 9.0 / 12.0000);
    break;

    case 'D':
    freq /= pow(2.0, 7.0 / 12.0000 );
    break;

    case 'E':
    freq /= pow(2.0, 5.0 / 12.0000);
    break;

    case 'F':
    freq /= pow(2.0, 4.0 / 12.0000);
    break;

    case 'G':
    freq /= pow(2.0, 2.0 / 12.0000);
    break;

    case 'A':
    break;

    case 'B':
    freq *= pow(2.0, 2.0 / 12.0000);
    break;
}


//Adjust octave
if(octive > 4)
{
    freq *= pow(2.0, octive - 4);

}

else if(octive < 4)
{
    freq /= pow(2.0, 4 - octive);
}
// Adjust for accidental
  if (note[1]=='b')
  {
    freq /=pow(2.0,1.0 / 12.0000);

  }
   else if (note[1]=='#')
  {
    freq *= pow(2.0,1.0 / 12.0000);
  }
  return round(freq);
}
//determines whether  a string represents a rest
bool is_rest(string s)
{
    if(s == '\0')
    {
        return true;
    }

    return false;

}
