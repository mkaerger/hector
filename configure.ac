#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([hector], [1.0.0], [marco.kaerger@gmail.com])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([include])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX


# Checks for drivers.
AC_ARG_ENABLE([mongodb],
[  --enable-mongodb    Enable MongoDB],
[case "${enableval}" in
  yes) 
	AC_LANG_PUSH([C++])
	AC_CHECK_HEADERS([mongo/client/dbclient.h],
		[],[AC_MSG_ERROR(
		[Could not find or include dbclient.h])],
	)
	AC_LANG_POP([C++])
	mongodb=true ;;
  no)  mongodb=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-mongodb]) ;;
esac],[mongodb=false])
AM_CONDITIONAL([MONGODB], [test x$mongodb = xtrue])


AC_ARG_ENABLE([pgsql],
[  --enable-pgsql    Enable PostgreSQL],
[case "${enableval}" in
  yes) 
	AC_LANG_PUSH([C++])
	AC_CHECK_HEADERS([postgresql/libpq-fe.h],
		[],
		[AC_MSG_ERROR(
		[Could not find or include libpq-fe.h])],
	)
	AC_LANG_POP([C++])
    pgsql=true ;;
  no)  pgsql=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-pgsql]) ;;
esac],[pgsql=false])
AM_CONDITIONAL([POSTGRESQL], [test x$pgsql = xtrue])


AC_ARG_ENABLE([mysql],
[  --enable-mysql    Enable MySQL],
[case "${enableval}" in
  yes) 
	AC_LANG_PUSH([C++])
	AC_CHECK_HEADERS([mysql_connection.h],
		[],
		[AC_MSG_ERROR(
		[Could not find or include mysql_connection.h])],
	)
	AC_LANG_POP([C++])
    mysql=true ;;
  no)  mysql=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-mysql]) ;;
esac],[mysql=false])
AM_CONDITIONAL([MYSQL], [test x$mysql = xtrue])


AC_ARG_ENABLE([elasticsearch],
[  --enable-elasticsearch    Enable Elasticsearch],
[case "${enableval}" in
  yes) 
	AC_LANG_PUSH([C++])
	AC_CHECK_HEADERS([curl/curl.h],
		[],
		[AC_MSG_ERROR(
		[Could not find or include curl.h])],
	)
	AC_LANG_POP([C++])
    elasticsearch=true ;;
  no)  elasticsearch=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-elasticsearch]) ;;
esac],[elasticsearch=false])
AM_CONDITIONAL([ELASTICSEARCH], [test x$elasticsearch = xtrue])


# Check headers.
AC_LANG_PUSH([C++])
# Checks for header files.
AC_CHECK_HEADERS([ \
arpa/inet.h \
fcntl.h \
netdb.h \
netinet/in.h \
string.h \
sys/socket.h \
sys/time.h \
unistd.h \
boost/thread.hpp \
boost/regex.hpp \
boost/foreach.hpp \
boost/algorithm/string.hpp \
boost/lexical_cast.hpp \
boost/filesystem.hpp \
boost/unordered_map.hpp \
boost/property_tree/xml_parser.hpp \
boost/program_options.hpp \
])
AC_LANG_POP([C++])

AC_SUBST([AM_CXXFLAGS])
AC_SUBST([AM_LDFLAGS])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
AC_CHECK_FUNCS([memset socket])

AC_CONFIG_FILES([ \
Makefile \
src/Makefile \
scripts/Makefile \
ressources/Makefile \
plpgsql/Makefile \
])

AC_OUTPUT
