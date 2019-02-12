/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar  = 1; // -b option; if 0, dmenu appears at bottom
static int fuzzy   = 1; // -F option; if 0, dmenu wont use fuzzy matching
static int instant = 1; // select item when only one left

/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = { "monospace:size=11" };

/* -p  option; prompt to the left of input field */
static const char *prompt = ">>";

static const char *colors[SchemeLast][2] = {
	/*              foreground  background */
	[SchemeNorm] = { "#8C8C8C", "#1A1A1A" },
	[SchemeSel]  = { "#457EBC", "#1A1A1A" },
	[SchemeOut]  = { "#1A1A1A", "#457EBC" },
};

// -l option; if nonzero, dmenu uses vertical list with given number of lines
static unsigned int lines = 0;

// -h option; minimum height of a menu line
static unsigned int lineheight = 24;

// Characters not considered part of a word while deleting words
// for example: " /?\"&[]"
static const char worddelimiters[] = " ";
