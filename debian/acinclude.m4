dnl This came from the libwww dir of Amaya's source with a bunch
dnl of macros removed (they redefined macros found elsewhere and
dnl caused autoconf to choke)

dnl AC_STRUCT_GMTOFF
dnl If struct tm contains tm_gmtoff, define HAVE_TM_GMTOFF. Otherwise,
dnl  if timezone and/or altzone exist, define HAVE_TIMEZONE and/or
dnl  HAVE_ALTZONE respectively.  Finally, if the timezone value is
dnl  backwards, define NEGATIVE_TIMEZONE.
AC_DEFUN(AC_STRUCT_GMTOFF,
[ AC_REQUIRE([AC_STRUCT_TM])dnl
  AC_MSG_CHECKING([for tm_gmtoff in struct tm])
  AC_CACHE_VAL(ac_cv_struct_gmtoff,
  [ AC_TRY_COMPILE([#include <sys/types.h>
#include <$ac_cv_struct_tm>], [struct tm tm; tm.tm_gmtoff;],
  ac_cv_struct_gmtoff=yes, ac_cv_struct_gmtoff=no)])
  AC_MSG_RESULT($ac_cv_struct_gmtoff)
if test $ac_cv_struct_gmtoff = yes; then
  AC_DEFINE(HAVE_TM_GMTOFF)
fi

AC_MSG_CHECKING(for time.h that defines timezone)
AC_CACHE_VAL(ac_cv_extern_timezone,
[AC_TRY_COMPILE([#include <time.h>], [return timezone;],
  ac_cv_extern_timezone=yes,
  ac_cv_extern_timezone=no)])
AC_MSG_RESULT($ac_cv_extern_timezone)
if test $ac_cv_extern_timezone = yes; then
  AC_DEFINE(HAVE_TIMEZONE)
fi

dnl Borrowed from the Python distribution...
AC_MSG_CHECKING(for time.h that defines altzone)
AC_CACHE_VAL(ac_cv_extern_altzone,
[AC_TRY_COMPILE([#include <time.h>], [return altzone;],
  ac_cv_extern_altzone=yes,
  ac_cv_extern_altzone=no)])
AC_MSG_RESULT($ac_cv_extern_altzone)
if test $ac_cv_extern_altzone = yes; then
  AC_DEFINE(HAVE_ALTZONE)
fi

AC_MSG_CHECKING(for time.h that defines daylight)
AC_CACHE_VAL(ac_cv_extern_daylight,
[AC_TRY_COMPILE([#include <time.h>], [return daylight;],
  ac_cv_extern_daylight=yes,
  ac_cv_extern_daylight=no)])
AC_MSG_RESULT($ac_cv_extern_daylight)
if test $ac_cv_extern_daylight = yes; then
  AC_DEFINE(HAVE_DAYLIGHT)
fi

if test $ac_cv_extern_timezone = yes; then
  AC_REQUIRE([AC_ISC_POSIX])dnl
  AC_MSG_CHECKING(if timezone is backwards)
  AC_CACHE_VAL(ac_cv_backwards_timezone,
  dnl Bletcherosity alert!  This will work for the USA and Europe, and 
  dnl countries sharing their timezones.  It will be exactly wrong for
  dnl the Atlantic ocean, bits of Russia, and minor third-world
  dnl countries.  The far East will default to "no," regardless of
  dnl platform.  If you can come up with something better, great --
  dnl Please let me know!
  [ AC_TRY_RUN([main(){
extern long timezone;
switch( timezone/3600 )
{
    /* OK: */
    case 5: case 6: case 7: case 8:	/* USA */
    case 0: case -1: case -2:		/* Europe */
        exit(0);
    /* Backwards: */
    case -5: case -6: case -7: case -8:	/* USA */
    case 1: case 2:			/* Europe */
        exit(1);
    /* Other country -- default to ok: */
    default:
        exit(0);
} return 0;}], ac_cv_backwards_timezone=no, ac_cv_backwards_timezone=yes,
  ac_cv_backwards_timezone=cross-compiling)])
  AC_MSG_RESULT($ac_cv_backwards_timezone)
if test $ac_cv_backwards_timezone = yes; then
  AC_DEFINE(NEGATIVE_TIMEZONE)
fi
fi
])dnl

dnl AC_STRUCT_WINSIZE
AC_DEFUN(AC_STRUCT_WINSIZE, 
[ AC_CACHE_CHECK(for winsize structure, ac_cv_struct_winsize,
  [ AC_TRY_COMPILE([
#ifdef HAVE_TERMIOS_H
#include <termios.h>
#endif
#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif
], [struct winsize foo;], 
    ac_cv_struct_winsize=yes, ac_cv_struct_winsize=no)])
  if test $ac_cv_struct_winsize = yes ; then
    AC_DEFINE(HAVE_WINSIZE)
  fi
])

dnl AC_CHECK_SIZEOF_TYPE_T
AC_DEFUN(AC_CHECK_SIZEOF_TIME_T,
[AC_CACHE_CHECK(for whether time_t is long, ac_cv_c_long_time_t,
[AC_TRY_RUN([
#include <time.h>
int main() { exit(sizeof(time_t) == sizeof(long)); }],
ac_cv_c_long_time_t=no, ac_cv_c_long_time_t=yes)
])
if test $ac_cv_c_long_time_t = yes; then
  AC_DEFINE(HAVE_LONG_TIME_T)
fi
])

dnl AC_CHECK_SIZEOF_SIZE_T
AC_DEFUN(AC_CHECK_SIZEOF_SIZE_T,
[AC_CACHE_CHECK(for whether size_t is long, ac_cv_c_long_size_t,
[AC_TRY_RUN([
#include <stddef.h>
int main() { exit(sizeof(size_t) == sizeof(int)); }],
ac_cv_c_long_size_t=yes, ac_cv_c_long_size_t=no)
])
if test $ac_cv_c_long_size_t = yes; then
  AC_DEFINE(HAVE_LONG_SIZE_T)
fi
])

dnl AC_ADDLIB
AC_DEFUN(AC_ADDLIB,
[ AC_MSG_CHECKING([for $1])
  LP=`dirname $1`
  LN=`basename $1 | sed 's/lib\(.*\)\.a/\1/g'`
  AC_MSG_RESULT([-L$LP -l$LN])
  LIBS="$LIBS -L$LP -l$LN"
])
