/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "NotoSans Nerd Font:size=10","SourceHanSansCN:size=9" ,"JoyPixels:pixelsize=18:antialias=true:autohint=true" };
/* static const char *fonts[]          = {"NotoSans Nerd Font:size=10"}; */

static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */

static const char dmenufont[]       = { "NotoSans Nerd Font:size=10" };
static char normbgcolor[]           = "#3c3836";
static char normbordercolor[]       = "#3c3836";
static char normfgcolor[]           = "#ebdbb2";
static char selbgcolor[]            = "#ebdbb2";
static char selbordercolor[]        = "#3c3836";
static char selfgcolor[]            = "#3c3836";
static char *colors[][3] = {
       /*               fg           bg           border   */
      [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
      [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
      [SchemeStatus]  = { normfgcolor, normbgcolor, normbordercolor }, // Statusbar right {text,background,not used but cannot be empty}
      [SchemeTagsSel]  = { selfgcolor,  selbgcolor,  selbordercolor  }, // Tagbar left selected {text,background,not used but cannot be empty}
      [SchemeTagsNorm]  = { normfgcolor, normbgcolor, normbordercolor }, // Tagbar left unselected {text,background,not used but cannot be empty}
      [SchemeInfoSel]  = { normfgcolor, normbgcolor, normbordercolor }, // infobar middle  selected {text,background,not used but cannot be empty}
      [SchemeInfoNorm]  = { normfgcolor, normbgcolor, normbordercolor }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

/* tagging */
static const char *tags[] = { "???", "???", "???", "???", "???", "???", "???", "???", "???" };
/* static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" }; */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            0,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "??? ",      tile },    /* first entry is default */
	{ "??? ",      NULL },    /* no layout function means floating behavior */
	{ "??? ",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };

#include <X11/XF86keysym.h>

static Key keys[] = {
	/* modifier                     key        function        argument */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY,			                  XK_0,		   view,		       {.ui = ~0 } },
/* para q sirve? */
	/* { MODKEY|ShiftMask,		          XK_0,		   tag,		         {.ui = ~0 } }, */
	{ MODKEY,			                  XK_q,		   killclient,	   {0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {1} }, 
	{ MODKEY,			                  XK_w,		   spawn,		       SHCMD("$BROWSER") },
	{ MODKEY,			                  XK_e,		   spawn,		       SHCMD("tmux-workspace") },
	{ MODKEY|ShiftMask,			        XK_e,		   spawn,		       SHCMD("tmux-old") },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
  { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,			                  XK_a,		   togglegaps,	   {0} },
	{ MODKEY|ShiftMask,		          XK_a,		   defaultgaps,	   {0} },
	{ MODKEY,			                  XK_z,		   incrgaps,	     {.i = +3 } },
	{ MODKEY,			                  XK_x,		   incrgaps,	     {.i = -3 } },
	{ MODKEY,			                  XK_Return, spawn,		       {.v = termcmd } },
	{ MODKEY,			                  XK_s,		   togglesticky,	 {0} },
	{ MODKEY|ShiftMask,             XK_s,      spawn,		       SHCMD("maim -so | xclip -selection clipboard -t image/png") },
	{ MODKEY,			                  XK_b,		   togglebar,	     {0} },
/* patch scrachpad, para tener una terminal q sale flotante */
	/* { MODKEY|ShiftMask,		          XK_Return, togglescratch,	 {.ui = 0} }, */
	{ MODKEY,                       XK_f,      togglefullscr,  {0} },
	{ MODKEY,			                  XK_grave,	 spawn,	         SHCMD("dmenuunicode") }, /*emoji*/
	{ MODKEY,			                  XK_space,	 zoom,		       {0} },
/* modo ventana flotante */
	{ MODKEY|ShiftMask,		          XK_space,	 togglefloating, {0} },
	{ MODKEY,			                  XK_minus,	 spawn,		       SHCMD("pamixer --allow-boost -d 5; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		          XK_minus,	 spawn,		       SHCMD("pamixer --allow-boost -d 15; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			                  XK_equal,	 spawn,		       SHCMD("pamixer --allow-boost -i 5; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		          XK_equal,	 spawn,		       SHCMD("pamixer --allow-boost -i 15; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,		                    XK_m,		   spawn,		       SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,			        XK_m,		   spawn,		       SHCMD(TERMINAL " -e ncmpcpp") },
	{ MODKEY,			                  XK_BackSpace,	spawn,		   SHCMD("sysact") },
	{ MODKEY,			                  XK_r,		   spawn,		       SHCMD(TERMINAL " -e lf-image") },
	{ MODKEY|ShiftMask,		          XK_r,		   spawn,		       SHCMD(TERMINAL " -e htop") },
	{ MODKEY,			                  XK_p,			 spawn,		       SHCMD("mpc toggle") },
	{ MODKEY|ShiftMask,		          XK_p,			 spawn,		       SHCMD("mpc pause ; pauseallmpv") },
	{ MODKEY,			                  XK_bracketleft,		spawn,	 SHCMD("mpc seek -10") },
	{ MODKEY|ShiftMask,		          XK_bracketleft,		spawn,	 SHCMD("mpc seek -60") },
	{ MODKEY,			                  XK_bracketright,	spawn,	 SHCMD("mpc seek +10") },
	{ MODKEY|ShiftMask,		          XK_bracketright,	spawn,	 SHCMD("mpc seek +60") },
	{ MODKEY,			                  XK_backslash,		  view,		 {0} },
	/* { MODKEY,			                  XK_d,		   spawn,          SHCMD("dmenu_run") }, */
	/* { MODKEY,			                  XK_d,		   spawn,          {.v = roficmd } }, */
	{ MODKEY,			                  XK_d,		   spawn,          SHCMD("rofi-test") },
	{ MODKEY|ShiftMask,		          XK_d,		   spawn,		       SHCMD("passmenu") },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_y,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,			                  XK_F1,		 spawn,		       SHCMD("groff -mom /usr/local/share/dwm/larbs.mom -Tpdf | zathura -") },
	{ MODKEY,			                  XK_F2,		 spawn,		       SHCMD("tutorialvids") },
	{ MODKEY,			                  XK_F3,		 spawn,		       SHCMD("displayselect") },
	{ MODKEY,			                  XK_F4,		 spawn,		       SHCMD(TERMINAL " -e pulsemixer; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			                  XK_F5,		 xrdb,		       {.v = NULL } },
	{ MODKEY,			                  XK_F6,		 spawn,		       SHCMD("torwrap") },
	{ MODKEY,			                  XK_F7,		 spawn,		       SHCMD("td-toggle") },
	{ MODKEY,			                  XK_F8,		 spawn,		       SHCMD("mw -Y") },
	{ MODKEY,			                  XK_F9,		 spawn,		       SHCMD("dmenumount") },
	{ MODKEY,			                  XK_F10,		 spawn,		       SHCMD("dmenuumount") },
	{ MODKEY,			                  XK_F11,		 spawn,		       SHCMD("mpv --no-cache --no-osc --no-input-default-bindings --profile=low-latency --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
	{ MODKEY,			                  XK_F12,		 spawn,		       SHCMD("remaps & notify-send \\\"?????? Keyboard remapping...\\\" \\\"Re-running keyboard defaults for any newly plugged-in keyboards.\\\"") },
	{ 0, XF86XK_AudioMute,		                 spawn,		       SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioRaiseVolume,	             spawn,          SHCMD("pamixer --allow-boost -i 3; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioLowerVolume,	             spawn,          SHCMD("pamixer --allow-boost -d 3; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioPrev,		                 spawn,          SHCMD("mpc prev") },
	{ 0, XF86XK_AudioNext,		                 spawn,          SHCMD("mpc next") },
	{ 0, XF86XK_AudioPause,		                 spawn,          SHCMD("mpc pause") },
	{ 0, XF86XK_AudioPlay,		                 spawn,          SHCMD("mpc play") },
	{ 0, XF86XK_AudioStop,		                 spawn,          SHCMD("mpc stop") },
	{ 0, XF86XK_AudioRewind,	                 spawn,          SHCMD("mpc seek -10") },
	{ 0, XF86XK_AudioForward,	                 spawn,          SHCMD("mpc seek +10") },
	{ 0, XF86XK_AudioMedia,		                 spawn,          SHCMD(TERMINAL " -e ncmpcpp") },
	{ 0, XF86XK_AudioMicMute,	                 spawn,          SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
	{ 0, XF86XK_PowerOff,		                   spawn,          SHCMD("sysact") },
	{ 0, XF86XK_Calculator,		                 spawn,          SHCMD(TERMINAL " -e bc -l") },
	{ 0, XF86XK_Sleep,		                     spawn,          SHCMD("sudo -A zzz") },
	{ 0, XF86XK_WWW,		                       spawn,          SHCMD("$BROWSER") },
	{ 0, XF86XK_DOS,		                       spawn,          SHCMD(TERMINAL) },
	{ 0, XF86XK_ScreenSaver,	                 spawn,          SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
	{ 0, XF86XK_TaskPane,		                   spawn,          SHCMD(TERMINAL " -e htop") },
	{ 0, XF86XK_Mail,		                       spawn,          SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
	{ 0, XF86XK_MyComputer,		                 spawn,          SHCMD(TERMINAL " -e lf /") },
	{ 0, XF86XK_Battery,		                   spawn,          SHCMD("") },
	{ 0, XF86XK_Launch1,		                   spawn,          SHCMD("xset dpms force off") },
	{ 0, XF86XK_TouchpadToggle,	               spawn,          SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
	{ 0, XF86XK_TouchpadOff,                   spawn,          SHCMD("synclient TouchpadOff=1") },
	{ 0, XF86XK_TouchpadOn,                    spawn,          SHCMD("synclient TouchpadOff=0") },
	{ 0, XF86XK_MonBrightnessUp,               spawn,          SHCMD("xbacklight -inc 1") },
	{ 0, XF86XK_MonBrightnessDown,             spawn,          SHCMD("xbacklight -dec 1") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
