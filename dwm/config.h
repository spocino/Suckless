/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 4;   /* border pixel of windows */
static const unsigned int snap     = 0;   /* screen edge snap pixel */
static const unsigned int minwsz   = 80;  /* minimum height of a client for smfact */
static const unsigned int gappx    = 8;   /* pixel gap between windows */
static const unsigned int maxgap   = 100; /* maximum pixel gap between windows */
static const unsigned int barpx    = 0;   /* space for external top bar */
static const unsigned int toffset  = 0;   /* tag text left offset, 0 is original */
static const int showbar           = 1;   /* 0 means no bar */
static const int bartitle          = 0;   /* 0 means no bar title */
static const int topbar            = 1;   /* 0 means bottom bar */
static const int floatborder       = 0;   /* 0 means no floating client borders */

static const char *fonts[]         = { "SauceCodePro Nerd Font:size=11" };
static const char dmenufont[]      = "SauceCodePro Nerd Font:size=11";

static const char col_backgr[]     = "#1D1F21";
static const char col_foregr[]     = "#C5C8C6";
static const char col_active[]     = "#81A2BE";
static const char col_dimmed[]     = "#8C8C8C";
static const char col_black[]      = "#000000";
static const char *colors[][3]     = {
	/* scheme           fg          bg         border */
	[SchemeNorm] = { col_dimmed, col_black, col_black },
	[SchemeSel]  = { col_active, col_black, col_active },
};

/* tags */
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1): */
	//	WM_CLASS(STRING) = instance, class
	//	WM_NAME(STRING) = title
	/* class         instance    title    tags mask   isfloating   monitor */
	{ "Gimp",         NULL,      NULL,     0,            0,          -1 },
	{ "Steam",        NULL,      NULL,     1 << 6,       0,          -1 },
	{ "Firefox",      NULL,      NULL,     1 << 8,       0,          -1 },
        { "mpv",          NULL,      NULL,     1 << 4,       0           -1 },
};

/* layout(s) */
static const float mfact     = 0.61; /* factor of master area size [0.05..0.95] */
static const float smfact    = 0.20; /* factor of tiled clients [0.00..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizes */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "c><",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "[+]",      grid },
	{ "-_-",      bstack },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY, view,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY, toggleview, {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY, tag,        {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY, toggletag,  {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* spawn commands */
static const char *termcmd[] = { "st", NULL };
static const char *scrotcmd[] = { "scrot", "%a-%H%M%S.png", "-e", "mv $f ~/scrots/", NULL };

/* component of dmenucmd, manipulated in spawn() */
static char dmenumon[2] = "0";

/* dmenu command */
static const char *dmenucmd[] = { "dmenu_run", "-i", "-fn", dmenufont, "-m", dmenumon,
	"-p", ">>", "-nb", col_black, "-nf", col_dimmed, "-sb", col_black, "-sf", col_active, NULL };

/* logout dmenu */
static const char *logoutcmd[] = { "dmenu_logout", "-i", "-fn", dmenufont,
	"-W", "300", "-l", "4", "-m", dmenumon, "-p", ">>", "-nb", col_black,
	"-nf", col_dimmed, "-sb", col_black, "-sf", col_active, NULL };

/* XF86Audio keys */
static const char *voltogg[] = { "pamixer", "-t", NULL };
static const char *volincr[] = { "pamixer", "-i", "2", NULL };
static const char *voldecr[] = { "pamixer", "-d", "2", NULL };

static Key keys[] = {
	/* modifier(s)          key                   function                                argument */
	{ 0,                  XF86XK_AudioMute,        spawn,                             {.v = voltogg} },
	{ 0,                  XF86XK_AudioRaiseVolume, spawn,                             {.v = volincr} },
	{ 0,                  XF86XK_AudioLowerVolume, spawn,                             {.v = voldecr} },

	{ 0,                  XK_Print,                spawn,                            {.v = scrotcmd} },
	{ 0,                  XK_Pause,                spawn,                           {.v = logoutcmd} },
	{ MODKEY,             XK_p,                    spawn,                            {.v = dmenucmd} },
	{ MODKEY,             XK_F1,                   spawn,                            {.v = dmenucmd} },
	{ MODKEY,             XK_Return,               spawn,                             {.v = termcmd} },

	{ MODKEY|ShiftMask,   XK_e,                    quit,                                         {0} },
	{ MODKEY,             XK_q,                    killclient,                                   {0} },


	{ MODKEY,             XK_equal,                incgappx,                                     {0} },
	{ MODKEY|ShiftMask,   XK_equal,                incgappx,                               {.i = +2} },
	{ MODKEY,             XK_minus,                incgappx,                               {.i = -2} },

	{ MODKEY,             XK_i,                    incnmaster,                             {.i = +1} },
	{ MODKEY,             XK_d,                    incnmaster,                             {.i = -1} },

	{ MODKEY|ShiftMask,   XK_j,                    movestack,                              {.i = +1} },
	{ MODKEY|ShiftMask,   XK_k,                    movestack,                              {.i = -1} },
	{ MODKEY,             XK_j,                    focusstack,                             {.i = +1} },
	{ MODKEY,             XK_k,                    focusstack,                             {.i = -1} },

	{ MODKEY|ShiftMask,   XK_h,                    setsmfact,                           {.f = -0.02} },
	{ MODKEY|ShiftMask,   XK_l,                    setsmfact,                           {.f = +0.02} },
	{ MODKEY,             XK_h,                    setmfact,                            {.f = -0.02} },
	{ MODKEY,             XK_l,                    setmfact,                            {.f = +0.02} },

	{ MODKEY,             XK_b,                    togglebar,                                    {0} },
	{ MODKEY|ShiftMask,   XK_space,                togglefloat,                                  {0} },
	{ MODKEY,             XK_space,                setlayout,                                    {0} },
	{ MODKEY,             XK_t,                    setlayout,                     {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,   XK_f,                    setlayout,                     {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,   XK_m,                    setlayout,                     {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,   XK_g,                    setlayout,                     {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,   XK_b,                    setlayout,                     {.v = &layouts[4]} },

	{ MODKEY,             XK_comma,                focusmon,                               {.i = -1} },
	{ MODKEY,             XK_period,               focusmon,                               {.i = +1} },
	{ MODKEY|ShiftMask,   XK_comma,                tagmon,                                 {.i = -1} },
	{ MODKEY|ShiftMask,   XK_period,               tagmon,                                 {.i = +1} },

	{ MODKEY,             XK_Tab,                  zoom,                                         {0} },
	{ MODKEY|ShiftMask,   XK_Tab,                  view,                                         {0} },
	{ MODKEY,             XK_0,                    view,                                  {.ui = ~0} },
	{ MODKEY|ShiftMask,   XK_0,                    tag,                                   {.ui = ~0} },
	TAGKEYS(XK_1, 0)
	TAGKEYS(XK_2, 1)
	TAGKEYS(XK_3, 2)
	TAGKEYS(XK_4, 3)
	TAGKEYS(XK_5, 4)
	TAGKEYS(XK_6, 5)
	TAGKEYS(XK_7, 6)
	TAGKEYS(XK_8, 7)
	TAGKEYS(XK_9, 8)
};

/* Mouse button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click        event mask   button      function                 argument */
	{ ClkLtSymbol,    0,         Button1,    setlayout,                  {0} },
	{ ClkLtSymbol,    0,         Button3,    setlayout,   {.v = &layouts[2]} },
	{ ClkStatusText,  0,         Button2,    spawn,           {.v = termcmd} },
	{ ClkWinTitle,    0,         Button2,    zoom,                       {0} },
	{ ClkTagBar,      0,         Button1,    view,                       {0} },
	{ ClkTagBar,      0,         Button3,    toggleview,                 {0} },
	{ ClkTagBar,      MODKEY,    Button1,    tag,                        {0} },
	{ ClkTagBar,      MODKEY,    Button3,    toggletag,                  {0} },
	{ ClkClientWin,   MODKEY,    Button1,    movemouse,                  {0} },
	{ ClkClientWin,   MODKEY,    Button2,    togglefloat,                {0} },
	{ ClkClientWin,   MODKEY,    Button3,    resizemouse,                {0} },
};

