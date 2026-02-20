#include <dt-bindings/zmk/keys.h>

// PC / Mac

#ifdef MACOS
#define CMD RG // Mac: Cmd key as main modifier
#else
#define CMD RC // PC: Ctrl key as main modifier
#endif

// Keyboard Layout

#ifdef KB_LAYOUT_ERGOL
#include "aliases/ergol.h"

#elifdef KB_LAYOUT_AZERTY
#define SHIFTED_NUMBERS
#include "aliases/azerty.h"

#elifdef KB_LAYOUT_QWERTY_LAFAYETTE
#include "aliases/qwerty_lafayette.h"

#else
#include "aliases/qwerty.h"

#endif

// Numbers

#ifdef SHIFTED_NUMBERS
  #define S_N0  LS(N0)
  #define S_N1  LS(N1)
  #define S_N2  LS(N2)
  #define S_N3  LS(N3)
  #define S_N4  LS(N4)
  #define S_N5  LS(N5)
  #define S_N6  LS(N6)
  #define S_N7  LS(N7)
  #define S_N8  LS(N8)
  #define S_N9  LS(N9)
#else
  #define S_N0  N0
  #define S_N1  N1
  #define S_N2  N2
  #define S_N3  N3
  #define S_N4  N4
  #define S_N5  N5
  #define S_N6  N6
  #define S_N7  N7
  #define S_N8  N8
  #define S_N9  N9
#endif

// Non-Alpha Actions

#define X_SHTAB &kp RS(TAB)
#define X_PREV  &kp LA(LEFT)
#define X_NEXT  &kp LA(RIGHT)
