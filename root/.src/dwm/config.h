/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Dejavu Sans Mono:size=12" };
static const char white[]           = "#FFFFFF";
static const char black[]           = "#000000";
static const char red[]             = "#bf616a";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { white, black, black },
	[SchemeSel]  = { black, white,  red  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
  { NULL,       NULL,       NULL,       0,            False,       -1 }
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define CHLANG "xkb-switch -s us;"
#define CHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", CHLANG cmd, NULL } }
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static char *dmenucmd[] = {NULL};
static const char *termcmd[]  = { "sh", "-c", CHLANG "st", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	/* Start Application */
	{ MODKEY,    		                XK_Return,  spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_t,       spawn,          SHCMD("telegram-desktop")},
	{ MODKEY,                       XK_f,       spawn,          SHCMD("firefox")},
	{ MODKEY,                       XK_s,       spawn,          SHCMD("steam")},
	{ MODKEY,                       XK_p,       spawn,          SHCMD("prismlauncher")},

	/* Light */
	{ MODKEY,                       XK_F2,      spawn,          SHCMD("light -A 20")},
	{ MODKEY,                       XK_F1,      spawn,          SHCMD("light -U 20")},

	/* Video */
	{ MODKEY|ShiftMask,             XK_o,       spawn,          SHCMD("xrandr --output eDP --auto --output HDMI-A-0 --left-of eDP --auto; hsetroot -solid '#FFFFFF'")},
	{ MODKEY,			XK_o,       spawn,          SHCMD("xrandr --output eDP --off --output HDMI-A-0 --rate 75 --mode 1920x1080")},
	{ MODKEY|ShiftMask|ControlMask,	XK_o,       spawn,          SHCMD("xrandr --output eDP --off")},

	/* Sound */
	{ MODKEY,                       XK_F5,      spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5%")},
	{ MODKEY,                       XK_F6,      spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5%")},
	{ MODKEY,                       XK_F4,      spawn,          SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle")},

	/* Music */
	{ MODKEY,                       XK_F7,      spawn,          SHCMD("mpc toggle")},
	{ MODKEY,                       XK_F8,      spawn,          SHCMD("mpc prev")},
	{ MODKEY,                       XK_F9,      spawn,          SHCMD("mpc next")},

	/* Screenshot */
	{ MODKEY,                       XK_s,       spawn,          SHCMD("fullscreenshot")},
	{ MODKEY|ShiftMask,             XK_s,       spawn,          SHCMD("areascreenshot")},

	/* Power */
	{ MODKEY|ShiftMask|ControlMask, XK_l,       spawn,          SHCMD("reboot")},
	{ MODKEY|ControlMask,           XK_l,       spawn,          SHCMD("poweroff")},
	{ MODKEY|ShiftMask,             XK_l,       spawn,          SHCMD("[ -z \"$(pgrep suspendtoram)\" ] && suspendtoram")},

	{ MODKEY,                       XK_z,       togglebar,      {0}},
	{ MODKEY,                       XK_Tab,     focusstack,     {.i = +1 }},
	{ MODKEY|ShiftMask, 	          XK_Tab,     focusstack,     {.i = -1 }},
	{ MODKEY,                       XK_j,       setmfact,       {.f = -0.05}},
	{ MODKEY,                       XK_k,       setmfact,       {.f = +0.05}},
	{ MODKEY,                       XK_space,   zoom,           {0}},
	{ MODKEY|ShiftMask,             XK_q,       killclient,     {0}},
	{ MODKEY|ShiftMask,             XK_space,   togglefloating, {0}},
	{ MODKEY,                       XK_comma,   focusmon,       {.i = -1}},
	{ MODKEY,                       XK_period,  focusmon,       {.i = +1}},
	{ MODKEY|ShiftMask,             XK_comma,   tagmon,         {.i = -1}},
	{ MODKEY|ShiftMask,             XK_period,  tagmon,         {.i = +1}},
	TAGKEYS(                        XK_1,                       0)
	TAGKEYS(                        XK_2,                       1)
	TAGKEYS(                        XK_3,                       2)
	TAGKEYS(                        XK_4,                       3)
	TAGKEYS(                        XK_5,                       4)
	TAGKEYS(                        XK_6,                       5)
	TAGKEYS(                        XK_7,                       6)
	TAGKEYS(                        XK_8,                       7)
	TAGKEYS(                        XK_9,                       8)
  TAGKEYS(                        XK_0,                       9)
	{ MODKEY|ShiftMask,             XK_e,       quit,           {0}},

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

