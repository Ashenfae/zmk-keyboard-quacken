#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>

// clang-format off

/**
 * Home-Row Mods
 */

#ifndef HRM
#define HRM_S &kp S
#define HRM_D &kp D
#define HRM_F &kp F
#define HRM_J &kp J
#define HRM_K &kp K
#define HRM_L &kp L
#else
#define HRM_S &hrm LGUI S
#define HRM_D &hrm LCTL D
#define HRM_F &hrm LALT F
#define HRM_J &hrm LALT J
#define HRM_K &hrm RCTL K
#define HRM_L &hrm RGUI L
#endif

/**
 * Timing is Key!
 */

#ifndef TAPPING_TERM
#define TAPPING_TERM 300
#endif

#define EZ_SL(layer) bsl (layer) (layer)
#define EZ_SK(mod)   bsk (mod) (mod)
&sl{ quick-release; }; // seems useless (works fine without)
&sk{ quick-release; }; // must have (lots of false positives otherwise)

/ {
  behaviors {
    hrm: homerow_mods {
      compatible = "zmk,behavior-hold-tap";
      #binding-cells = <2>;
      tapping-term-ms = <TAPPING_TERM>;
      flavor = "tap-preferred";
      bindings = <&kp>, <&kp>;
    };
    sc: space_cadet { // same as lt, but with hold-preferred
      compatible = "zmk,behavior-hold-tap";
      #binding-cells = <2>;
      tapping-term-ms = <TAPPING_TERM>;
      flavor = "hold-preferred";
      bindings = <&mo>, <&kp>;
    };

    // like ZMK's sticky layer (sl) but with a more robust timing
    osl: one_shot_layer {
      compatible = "zmk,behavior-macro-one-param";
      #binding-cells = <1>;
      tap-ms = <0>;
      wait-ms = <0>;
      bindings = <&macro_param_1to1>, <&macro_tap &sl MACRO_PLACEHOLDER>;
    };
    bsl: better_sticky_layer {
      compatible = "zmk,behavior-hold-tap";
      #binding-cells = <2>;
      tapping-term-ms = <TAPPING_TERM>;
      flavor = "tap-preferred";
      bindings = <&mo>, <&osl>;
    };

    // like ZMK's sticky key (sk) but with a more robust timing
    osm: one_shot_modifier {
      compatible = "zmk,behavior-macro-one-param";
      #binding-cells = <1>;
      tap-ms = <0>;
      wait-ms = <0>;
      bindings = <&macro_param_1to1>, <&macro_tap &sk MACRO_PLACEHOLDER>;
    };
    bsk: better_sticky_key {
      compatible = "zmk,behavior-hold-tap";
      #binding-cells = <2>;
      tapping-term-ms = <TAPPING_TERM>;
      flavor = "tap-preferred";
      bindings = <&kp>, <&osm>;
    };
	
    esc_ralt: escape_ralt {
      compatible = "zmk,behavior-tap-dance";
      #binding-cells = <0>;
	  tapping-term-ms = <TAPPING_TERM>;
      bindings = <&bsk RIGHT_ALT RIGHT_ALT>, <&kp ESCAPE>;
    };	
	capshift: caps_shift {
      compatible = "zmk,behavior-tap-dance";
      #binding-cells = <0>;
	  tapping-term-ms = <TAPPING_TERM>;
      bindings = <&bsk LSHFT LSHFT>, <&kp CAPS>;
    };	
	spacetap: space_tap {
      compatible = "zmk,behavior-tap-dance";
      #binding-cells = <0>;
	  tapping-term-ms = <TAPPING_TERM>;
      bindings = <&mt LEFT_SHIFT RS(SPACE)>, <&kp SPACE>;
    };	

	multap: multiply_tap {
      compatible = "zmk,behavior-tap-dance";
      #binding-cells = <0>;
	  tapping-term-ms = <TAPPING_TERM>;
      bindings = <&kp KP_MULTIPLY>, <&mult>;
    };	
	divtap: divide_tap {
      compatible = "zmk,behavior-tap-dance";
      #binding-cells = <0>;
	  tapping-term-ms = <TAPPING_TERM>;
      bindings = <&kp KP_DIVIDE>, <&div>;
    };
	mintap: minus_tap {
      compatible = "zmk,behavior-tap-dance";
      #binding-cells = <0>;
	  tapping-term-ms = <TAPPING_TERM>;
      bindings = <&hrm DOT KP_MINUS>, <&min>;
    };
	plustap: plus_tap {
      compatible = "zmk,behavior-tap-dance";
      #binding-cells = <0>;
	  tapping-term-ms = <TAPPING_TERM>;
      bindings = <&kp KP_PLUS>, <&plus>;
    };
	zerotap: zero_tap {
	compatible = "zmk,behavior-hold-tap";
	#binding-cells = <2>;
	tapping-term-ms = <TAPPING_TERM>;
	bindings = <&zero>, <&kp>;
	flavor = "tap-preferred";
	};
	euro: euro {
		compatible = "zmk,behavior-macro";
		#binding-cells = <0>;
		tap-ms = <0>;
		wait-ms = <0>;
		bindings = <&kp LS(SPACE) &kp LS(GRAVE)>;
	};	
	zero: zero {
		compatible = "zmk,behavior-macro";
		#binding-cells = <0>;
		tap-ms = <0>;
		wait-ms = <0>;
		bindings = <&kp KP_N0 &kp KP_N0>;
	};
	  div: div {
		compatible = "zmk,behavior-macro";
		#binding-cells = <0>;
		bindings = <&macro_tap>, <&kp RA(X)>, <&macro_tap>, <&kp KP_DIVIDE>;
	};
	plus: plus {
		compatible = "zmk,behavior-macro";
		#binding-cells = <0>;
		bindings = <&macro_tap>, <&kp RA(X)>, <&macro_tap>, <&kp KP_PLUS>;
	};
	mult: mult {
		compatible = "zmk,behavior-macro";
		#binding-cells = <0>;
		bindings =
			<&macro_tap>,
			<&kp RA(X)>,
			<&macro_tap>,
			<&kp KP_MULTIPLY>;
	};
	min: min {
		compatible = "zmk,behavior-macro";
		#binding-cells = <0>;
		bindings = <&macro_tap>, <&kp RA(X)>, <&macro_tap>, <&kp KP_MINUS>;
	};
  };
};