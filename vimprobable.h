/* macros */
#define LENGTH(x)                   (sizeof(x)/sizeof(x[0]))

/* enums */
enum { ModeNormal, ModePassThrough, ModeSendKey, ModeInsert, ModeHints };               /* modes */
enum { TargetCurrent, TargetNew };                                                      /* target */
/* bitmask,
    1 << 0:  0 = jumpTo,            1 = scroll
    1 << 1:  0 = top/down,          1 = left/right
    1 << 2:  0 = top/left,          1 = bottom/right
    1 << 3:  0 = paging/halfpage,   1 = line
    1 << 4:  0 = paging,            1 = halfpage aka buffer
*/
enum { ScrollJumpTo, ScrollMove };
enum { OrientationVert, OrientationHoriz = (1 << 1) };
enum { DirectionTop,
        DirectionBottom = (1 << 2),
        DirectionLeft = OrientationHoriz,
        DirectionRight = OrientationHoriz | (1 << 2) };
enum { UnitPage,
        UnitLine = (1 << 3),
        UnitBuffer = (1 << 4) };
/* bitmask:
    1 << 0:  0 = Reload/Cancel      1 = Forward/Back
    Forward/Back:
    1 << 1:  0 = Forward            1 = Back
    Reload/Cancel:
    1 << 1:  0 = Cancel             1 = Force/Normal Reload
    1 << 2:  0 = Force Reload       1 = Reload
*/
enum { NavigationForwardBack = 1, NavigationReloadActions = (1 << 1) };
enum { NavigationCancel,
        NavigationBack = (NavigationForwardBack | 1 << 1),
        NavigationForward = (NavigationForwardBack),
        NavigationReload = (NavigationReloadActions | 1 << 2),
        NavigationForceReload = NavigationReloadActions };
/* bitmask:
    1 << 1:  ClipboardPrimary (X11)
    1 << 2:  ClipboardGTK
    1 << 3:  SourceURL
    1 << 4:  SourceSelection
*/
enum { ClipboardPrimary = 1 << 1, ClipboardGTK = 1 << 2 };
enum { SourceSelection = 1 << 4, SourceURL = 1 << 3 };
/* bitmask:
    1 << 0:  0 = ZoomReset          1 = ZoomIn/Out
    1 << 1:  0 = ZoomOut            1 = ZoomIn
    1 << 2:  0 = TextZoom           1 = FullContentZoom
*/
enum { ZoomReset,
        ZoomOut,
        ZoomIn = ZoomOut | (1 << 1) };
enum { ZoomText, ZoomFullContent = (1 << 2) };
/* bitmask:
    0 = Info, 1 = Warning, 2 = Error
    1 << 2:  0 = AutoHide           1 = NoAutoHide
    relevant for script:
    1 << 3:                         1 = Silent (no echo)
*/
enum { Info, Warning, Error, NoAutoHide = 1 << 2, Silent = 1 << 3 };
enum { NthSubdir, Rootdir };
enum { InsertCurrentURL = 1 };
enum { Increment, Decrement };
/* bitmask:
    1 << 0:  0 = DirectionNext      1 = DirectionPrev       (Relative)
    1 << 0:  0 = DirectionBackwards 1 = DirectionForward    (Absolute)

    1 << 1:  0 = DirectionRelative  1 = DirectionAbsolute

    1 << 2:  0 = CaseInsensitive    1 = CaseSensitive
    1 << 3:  0 = No Wrapping        1 = Wrapping
*/
enum { DirectionRelative, DirectionAbsolute = 1 << 1 };
enum { DirectionNext, DirectionPrev, HideCompletion };
enum { DirectionBackwards = DirectionAbsolute, DirectionForward = (1 << 0) | DirectionAbsolute };
enum { CaseInsensitive, CaseSensitive = 1 << 2 };
enum { Wrapping = 1 << 3 };

/* structs here */
typedef struct {
    int i;
    char *s;
} Arg;

typedef struct {
    guint mask;
    guint modkey;
    guint key;
    gboolean (*func)(const Arg *arg);
    const Arg arg;
} Key;

typedef struct {
    guint mask;
    guint modkey;
    guint button;
    gboolean (*func)(const Arg *arg);
    const Arg arg;
} Mouse;

typedef struct {
    char *cmd;
    gboolean (*func)(const Arg *arg);
    const Arg arg;
} Command;

typedef struct {
    char *handle;
    char *uri;
} Searchengine;

typedef struct {
    char *handle;
    char *handler;
} URIHandler;

typedef struct {
    void *next;
    char element[255];
} Listelement;

/* constants */
#define MOUSE_BUTTON_1 1
#define MOUSE_BUTTON_2 2
#define MOUSE_BUTTON_3 3
#define MOUSE_BUTTON_4 4
#define MOUSE_BUTTON_5 5
#define BUFFERSIZE 255
#define MAXTAGSIZE 200

/* completion list size */
#define             MAX_LIST_SIZE               40
