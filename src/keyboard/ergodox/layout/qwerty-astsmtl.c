/* ----------------------------------------------------------------------------
* ergoDOX layout : QWERTY (modified from the Kinesis layout)
* -----------------------------------------------------------------------------
* Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
* Released under The MIT License (MIT) (see "license.md")
* Project located at <https://github.com/benblazak/ergodox-firmware>
* -------------------------------------------------------------------------- */


#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // layout: layer 0: default
// unused
0,
// left hand
   _grave,  _1,     _2,    _3,    _4,   _5,   _esc,
_capsLock,  _Q,     _W,    _E,    _R,   _T, _equal,
     _tab,  _A,     _S,    _D,    _F,   _G,
  _shiftL,  _Z,     _X,    _C,    _V,   _B,      0,
   _ctrlL,   1, _lang1, _guiL, _altL,
                                         0,      0,
                                   0,    0,  _home,
                                 _bs, _del,   _end,
// right hand
         2,      _6,     _7,      _8,      _9,         _0, _bracketR,
     _dash,      _Y,     _U,      _I,      _O,         _P, _bracketL,
                 _H,     _J,      _K,      _L, _semicolon,    _quote,
_backslash,      _N,     _M,  _comma, _period,     _slash,   _shiftR,
                      _altR,   _guiR,  _lang2,          1,    _ctrlR,
     _menu, _insert,
    _pageU,       0,      0,
    _pageD,  _enter, _space ),


	KB_MATRIX_LAYER(  // layout: layer 1: function, arrow and special keys
// unused
0,
// left hand
   0, _F1,     _F2,     _F3,     _F4, _F5, _F11,
   0,   0,       0, _arrowU,       0,   0,    0,
   0,   0, _arrowL, _arrowD, _arrowR,   0,
   0,   0,       0,       0,       0,   0,    0,
   0,   0,       0,       0,       0,
                                        0,    0,
                                   0,   0,    0,
                                   0,   0,    0,
// right hand
_F12,     _F6,      _F7,      _F8,      _F9, _F10,   0,
   0,       0,        0,        0,        0,    0,   0,
      _arrowL,  _arrowD,  _arrowU,  _arrowR,    0,   0,
   0,   _mute, _volumeD, _volumeU,        0,    0,   0,
                      0,        0,        0,    0,   0,
   0,       0,
   0,       0,        0,
   0,       0,        0 ),


	KB_MATRIX_LAYER(  // layout: layer 2: numpad
// unused
0,	
// left hand
   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,
                            0,   0,
                       0,   0,   0,
                       0,   0,   0,
// right hand
    2,     0, _numLock_kp, _div_kp,     _mul_kp, _sub_kp,   0,
    0,     0,       _7_kp,   _8_kp,       _9_kp, _add_kp,   0,
           0,       _4_kp,   _5_kp,       _6_kp, _add_kp,   0,
    0,     0,       _1_kp,   _2_kp,       _3_kp,  _enter,   0,
                    _0_kp,   _0_kp, _dec_del_kp,  _enter,   0,
    0,     0,
    0,     0,           0,
    0,     0,           0 )

};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// aliases

// basic
#define  kprrel  &kbfun_press_release
#define  ktog    &kbfun_toggle
#define  ktrans  &kbfun_transparent
// --- layer push/pop functions
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush5   &kbfun_layer_push_5
#define  lpush6   &kbfun_layer_push_6
#define  lpush7   &kbfun_layer_push_7
#define  lpush8   &kbfun_layer_push_8
#define  lpush9   &kbfun_layer_push_9
#define  lpush10  &kbfun_layer_push_10
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop5    &kbfun_layer_pop_5
#define  lpop6    &kbfun_layer_pop_6
#define  lpop7    &kbfun_layer_pop_7
#define  lpop8    &kbfun_layer_pop_8
#define  lpop9    &kbfun_layer_pop_9
#define  lpop10   &kbfun_layer_pop_10
// ---

// device
#define  dbtldr  &kbfun_jump_to_bootloader

// special
#define  sshprre  &kbfun_shift_press_release
#define  s2kcap   &kbfun_2_keys_capslock_press_release
#define  slpunum  &kbfun_layer_push_numpad
#define  slponum  &kbfun_layer_pop_numpad

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // press: layer 0: default
// unused
NULL,
// left hand
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
kprrel, lpush1, kprrel, kprrel, kprrel,
                                          NULL,   NULL,
                                  NULL,   NULL, kprrel,
                                kprrel, kprrel, kprrel,
// right hand
lpush2, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                kprrel, kprrel, kprrel, lpush1, kprrel,
kprrel, kprrel,
kprrel,   NULL,   NULL,
kprrel, kprrel,  kprrel ),

	KB_MATRIX_LAYER(  // layout: layer 1: function, arrow and special keys
// unused
NULL,
// left hand
  NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
  NULL,   NULL,   NULL, kprrel,   NULL,   NULL,   NULL,
  NULL,   NULL, kprrel, kprrel, kprrel,   NULL,
ktrans,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
ktrans,   NULL,   NULL,   NULL, ktrans,
                                          NULL,   NULL,
                                  NULL,   NULL,   NULL,
                                  NULL,   NULL,   NULL,
// right hand
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
  NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
        kprrel, kprrel, kprrel, kprrel,   NULL,   NULL,
  NULL, kprrel, kprrel, kprrel,   NULL,   NULL, ktrans,
                ktrans,   NULL,   NULL,   NULL, ktrans,
  NULL,   NULL,
  NULL,   NULL,   NULL,
  NULL,   NULL,   NULL ),

	KB_MATRIX_LAYER(  // press: layer 2: numpad
// unused
NULL,
// left hand
dbtldr, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL,
                                NULL, NULL,
                          NULL, NULL, NULL,
                          NULL, NULL, NULL,
// right hand
 lpop2, NULL, kprrel, kprrel, kprrel, kprrel, NULL,
  NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL,
        NULL, kprrel, kprrel, kprrel, kprrel, NULL,
  NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL,
              kprrel, kprrel, kprrel, kprrel, NULL,
  NULL, NULL,
  NULL, NULL, NULL,
  NULL, NULL, NULL )

};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // release: layer 0: default
// unused
NULL,
// left hand
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
kprrel,  lpop1, kprrel, kprrel, kprrel,
                                          NULL,   NULL,
                                  NULL,   NULL, kprrel,
                                kprrel, kprrel, kprrel,
// right hand
  NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                kprrel, kprrel, kprrel,  lpop1, kprrel,
kprrel, kprrel,
kprrel,   NULL,   NULL,
kprrel, kprrel, kprrel ),

	KB_MATRIX_LAYER(  // layout: layer 1: function, arrow and special keys
// unused
NULL,
// left hand
  NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
  NULL,   NULL,   NULL, kprrel,   NULL,   NULL, NULL,
  NULL,   NULL, kprrel, kprrel, kprrel,   NULL,
ktrans,   NULL,   NULL,   NULL,   NULL,   NULL, NULL,
ktrans,   NULL,   NULL,   NULL, ktrans,
                                          NULL, NULL,
                                  NULL,   NULL, NULL,
                                  NULL,   NULL, NULL,
// right hand
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
  NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
        kprrel, kprrel, kprrel, kprrel,   NULL,   NULL,
  NULL, kprrel, kprrel, kprrel,   NULL,   NULL, ktrans,
                ktrans,   NULL,   NULL,   NULL, ktrans,
  NULL,   NULL,
  NULL,   NULL,   NULL,
  NULL,   NULL,   NULL ),

	KB_MATRIX_LAYER(  // layout: layer 2: numpad
// unused
NULL,
// left hand
NULL, NULL, NULL, NULL, NULL, NULL, NULL,
NULL, NULL, NULL, NULL, NULL, NULL, NULL,
NULL, NULL, NULL, NULL, NULL, NULL,
NULL, NULL, NULL, NULL, NULL, NULL, NULL,
NULL, NULL, NULL, NULL, NULL,
                              NULL, NULL,
                        NULL, NULL, NULL,
                        NULL, NULL, NULL,
// right hand
NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL,
NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL,
      NULL, kprrel, kprrel, kprrel, kprrel, NULL,
NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL,
            kprrel, kprrel, kprrel, kprrel, NULL,
NULL, NULL,
NULL, NULL,   NULL,
NULL, NULL,   NULL )

};
