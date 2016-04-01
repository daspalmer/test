#define MAX_DEBUG_LEVEL 1000
#define DBGC_MAX_FIXED		22

#if (__GNUC__ >= 3)
/* the strange !! is to ensure that __builtin_expect() takes either 0 or 1
 *    as its first argument */
#ifndef likely
#define likely(x)   __builtin_expect(!!(x), 1)
#endif
#ifndef unlikely
#define unlikely(x) __builtin_expect(!!(x), 0)
#endif
#else
#ifndef likely
#define likely(x) (x)
#endif
#ifndef unlikely
#define unlikely(x) (x)
#endif
#endif

extern int *DEBUGLEVEL_CLASS;

#define DBGC_CLASS 0

#define CHECK_DEBUGLVL( level ) \
  ( ((level) <= MAX_DEBUG_LEVEL) && \
      unlikely(DEBUGLEVEL_CLASS[ DBGC_CLASS ] >= (level)))

#define DEBUG( level, body ) \
 (void)( ((level) <= MAX_DEBUG_LEVEL) && \
 unlikely(DEBUGLEVEL_CLASS[ DBGC_CLASS ] >= (level))           \
  && (dbgtext body) )

#define DEBUGLVL( level ) \
  ( CHECK_DEBUGLVL(level) )

int dbgtext( const char *, ... );
