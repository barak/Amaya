# -*- RPM-SPEC -*-
# Note that this is NOT a relocatable package
%define name    redland
%define version 0.9.16
%define release SNAP
%define prefix  /usr

%define perlinstallsitearch /usr/lib/perl5/site_perl/5.8.0/i386-linux-thread-multi
%define perlman3dir /usr/share/man/man3

Summary:   Redland RDF Application Framework
Name:      %{name}
Version:   %{version}
Release:   %{release}
Prefix:    %{_prefix}
Copyright: LGPL/MPL
Group:     Development/Libraries
Source:    http://www.redland.opensource.ac.uk/dist/source/%{name}-%{version}.tar.gz
URL:       http://www.redland.opensource.ac.uk/
BuildRoot: /tmp/%{name}-%{version}
BuildRequires: libxml2-devel >= 2.4.0
BuildRequires: curl-devel
BuildRequires: raptor-devel >= 1.2.0
BuildRequires: perl >= 5.8.0
BuildRequires: python >= 2.2.0 python-devel
BuildRequires: mysql-devel
Packager:  Dave Beckett <Dave.Beckett@bristol.ac.uk>
Docdir: %{prefix}/doc
Requires:  libxml2
Requires:  curl
Requires:  raptor
Requires:  mysql

%description

Redland is a library that provides a high-level interface for RDF
(Resource Description Framework) implemented in an object-based API.
It is modular and supports different RDF/XML parsers, storage
mechanisms and other elements. Redland is designed for applications
developers to provide RDF support in their applications as well as
for RDF developers to experiment with the technology.

%package devel
Summary: Libraries and header files for programs that use Redland.
Group: Development/Libraries
Requires: redland
Requires: raptor >= 1.0.0

%description devel
Header files for development with Redland

%package perl
Summary: Perl modules for the Redland RDF library
Group: Development/Libraries
Requires: redland = %{version}

%description perl
The redland-perl package contains the parts of Redland that provide
an interface to Perl.

%package python
Summary: Python modules for the Redland RDF library
Group: Development/Libraries
Requires: redland = %{version}

%description python
The redland-python package contains the parts of Redland that provide
an interface to Python.

%prep
%setup

%build
# Force use of default python even if 2.0 is present
PYTHON=python
export PYTHON

if [ ! -f configure ]; then
  CFLAGS="$RPM_OPT_FLAGS" ./autogen.sh --prefix=%{prefix} --enable-release --sysconfdir=/etc --mandir=%{_mandir} --libdir=%{_libdir} --with-raptor=system --with-threestore=no
else
  CFLAGS="$RPM_OPT_FLAGS" ./configure --prefix=%{prefix} --enable-release --sysconfdir=/etc --mandir=%{_mandir} --libdir=%{_libdir} --with-raptor=system --with-threestore=no
fi

%{__make} OPTIMIZE="$RPM_OPT_FLAGS"

cd perl

%{__perl} Makefile.PL PREFIX=$RPM_BUILD_ROOT/%{_prefix} SYSCONFDIR=$RPM_BUILD_ROOT/%{_sysconfdir} INST_PREFIX=%{_prefix} INST_SYSCONFDIR=%{_sysconfdir}
make

cd ..


cd python

%{__make}

cd ..


%install
[ "$RPM_BUILD_ROOT" != "/" ] && rm -rf $RPM_BUILD_ROOT

%makeinstall prefix=$RPM_BUILD_ROOT%{prefix} sysconfdir=$RPM_BUILD_ROOT/etc libdir=$RPM_BUILD_ROOT%{_libdir} mandir=$RPM_BUILD_ROOT%{_mandir}

find $RPM_BUILD_ROOT -print | xargs chmod u+w


cd perl

make prefix=$RPM_BUILD_ROOT%{prefix} exec_prefix=$RPM_BUILD_ROOT%{prefix} bindir=$RPM_BUILD_ROOT%{prefix}/bin sbindir=$RPM_BUILD_ROOT%{prefix}/sbin sysconfdir=$RPM_BUILD_ROOT/etc datadir=$RPM_BUILD_ROOT%{prefix}/share includedir=$RPM_BUILD_ROOT%{prefix}/include libdir=$RPM_BUILD_ROOT%{_libdir} libexecdir=$RPM_BUILD_ROOT%{prefix}/libexec localstatedir=$RPM_BUILD_ROOT/var sharedstatedir=$RPM_BUILD_ROOT%{prefix}/com mandir=$RPM_BUILD_ROOT%{_mandir} infodir=$RPM_BUILD_ROOT%{prefix}/share/info install

find $RPM_BUILD_ROOT -name perllocal.pod -exec rm -v {}  \;

cd ..

cd python

make install DESTDIR=$RPM_BUILD_ROOT
find $RPM_BUILD_ROOT%{prefix} -name "*.py[co]" -exec rm -f {} \;

cd ..

%clean
[ "$RPM_BUILD_ROOT" != "/" ] && rm -rf $RPM_BUILD_ROOT

%files
%defattr(0555, bin, bin)

%{_libdir}/librdf*.so.*
%{prefix}/bin/rdfproc
%{prefix}/bin/redland-db-upgrade

%defattr (0444, bin, bin, 0555)

%doc AUTHORS COPYING COPYING.LIB ChangeLog
%doc README NEWS LICENSE.txt

%doc *.html

%doc %{_mandir}/man1/redland-config.1*
%doc %{_mandir}/man1/redland-db-upgrade.1*
%doc %{_mandir}/man1/rdfproc.1*
%doc %{_mandir}/man3/redland.3*

%files devel
%defattr(-, root, root)

%{prefix}/bin/redland-config
%{_libdir}/librdf*.a
%{_libdir}/librdf*.la
%{_libdir}/librdf*.so
%{_libdir}/pkgconfig/redland.pc

%{prefix}/include/redland.h
%{prefix}/include/librdf.h 
%{prefix}/include/rdf_*.h

%doc AUTHORS COPYING COPYING.LIB ChangeLog
%doc README NEWS LICENSE.txt

%doc docs/README.html
%doc docs/java.html docs/perl.html docs/php.html
%doc docs/python.html docs/ruby.html docs/tcl.html
%doc docs/api

%files perl
%defattr(-, bin, bin)

%{perlinstallsitearch}/auto
%{perlinstallsitearch}/RDF/Redland
%{perlinstallsitearch}/RDF/Redland.pm

%doc %{perlman3dir}/RDF::Redland*.3pm*
%doc perl/example.pl

%files python
%defattr(-, bin, bin)

%{_libdir}/python*/site-packages/RDF.py
%{_libdir}/python*/site-packages/Redland.so*

%doc AUTHORS COPYING COPYING.LIB ChangeLog
%doc README NEWS LICENSE.txt

%doc docs/pydoc/RDF.html python/example.py

%post
/sbin/ldconfig

%postun
/sbin/ldconfig

%changelog
* Fri Jan 30 2004  Dave Beckett <dave.beckett@bristol.ac.uk>
- require raptor 1.2.0
- update for removal of python distutils
- require python 2.2.0+
- require perl 5.8.0+
- build and require mysql
- do not build and require threestore

* Sun Jan 4 2004  Dave Beckett <dave.beckett@bristol.ac.uk>
- added redland-python package
- export some more docs

* Mon Dec 15 2003 Dave Beckett <dave.beckett@bristol.ac.uk>
- require raptor 1.1.0
- require libxml 2.4.0 or newer
- added pkgconfig redland.pc
- split redland/devel package shared libs correctly

* Mon Sep 8 2003 Dave Beckett <dave.beckett@bristol.ac.uk>
- require raptor 1.0.0
 
* Thu Sep 4 2003 Dave Beckett <dave.beckett@bristol.ac.uk>
- added rdfproc
 
* Thu Aug 28 2003 Dave Beckett <dave.beckett@bristol.ac.uk>
- patches added post 0.9.13 to fix broken perl UNIVERSAL::isa
 
* Thu Aug 21 2003 Dave Beckett <dave.beckett@bristol.ac.uk>
- Add redland-db-upgrade.1
- Removed duplicate perl CORE shared objects

* Sun Aug 17 2003 Dave Beckett <dave.beckett@bristol.ac.uk>
- Updates for new perl module names.

* Tue Apr 22 2003 Dave Beckett <dave.beckett@bristol.ac.uk>
- Updated for Redhat 9, RPM 4

* Fri Feb 12 2003 Dave Beckett <dave.beckett@bristol.ac.uk>
- Updated for redland 0.9.12

* Fri Jan 4 2002 Dave Beckett <dave.beckett@bristol.ac.uk>
- Updated for new Perl module names

* Fri Sep 14 2001 Dave Beckett <dave.beckett@bristol.ac.uk>
- Added shared libraries