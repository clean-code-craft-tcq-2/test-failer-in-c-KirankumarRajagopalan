#include <stdio.h>
#include <assert.h>

const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

//Finding the number of minor and major colors
int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

//Define Color Pair structure
typedef struct {
    int pairNumber;
    const char* majorColor;
    const char* minorColor;
} ColorPair;

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    colorPair.pairNumber = pairNumber;
    colorPair.majorColor = MajorColorNames[(pairNumber / numberOfMajorColors)];
    colorPair.minorColor = MinorColorNames[(pairNumber % numberOfMinorColors)];
    return colorPair;
}

//Test function to assert the major and minor color obtained from pair number.
void testNumberToPair(int pairNumber, const char* expectedMajor, const char* expectedMinor){
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    assert(colorPair.pairNumber == pairNumber);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

//Print and test the color map information
int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
            testNumberToPair( i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
