#
# spec file for package amaya (Version 4.3.1)
# 
# Copyright  (c)  1998  S.u.S.E. GmbH  Fuerth, Germany.
#
# please send bugfixes or comments to feedback@suse.de.
#

# neededforbuild  autoconf automake mmcore mmbase mmslib xpm libz libpng libjpeg

%define version 9.5

Vendor:       W3C World Wide Web Consortium
Distribution: W3C
Name:         amaya_wx
Release:      1
Copyright:    Copyright 1995-2005 (MIT) (INRIA), (L)GPL compatible
Group:        X11/Applications/Networking
URL:          http://www.w3.org/Amaya/
Autoreqprov:  on
Packager:     Irene.Vatton@w3.org
BuildRoot:    /var/tmp/%{name}-buildroot
#BuildRoot:     /usr/src/redhat/BUILD/

Summary:      Web Browser/Editor from the World Wide Web Consortium
Version:      %{version}
Source: ftp://ftp.w3.org/pub/amaya/amaya-fullsrc-%{version}.tgz
# Patch: amaya-src-%{version}.diff
%description

Amaya is a complete Web authoring tool with some browsing 
funtionalities and comes equipped with a WYSIWYG style of
interface, similar to that of the most popular commercial
browsers. With such an interface, users do not need to 
well know the HTML, MathML or CSS languages.

Authors:
--------
    Irene.Vatton@inria.fr, Stephane.Gully@inria.fr,
    Vincent.Quint@inria.fr, Laurent.Carcone@w3.org

%changelog
* Fri Sep 2 2005  Irene Vatton (Irene.Vatton@w3.org>
  and Stephane Gully
  Gnome/Kde integration
* Tue Oct 15 2004 Irene Vatton (Irene.Vatton@w3.org>
  Possibility to install GTK and WX amaya versions
* Tue Jul 06 2004 Irene Vatton (Irene.Vatton@w3.org>
  First WX amaya version
* Tue Feb 24 2004 Irene Vatton (Irene.Vatton@w3.org>
  Updated for amaya-8.3
* Fri Apr 23 2003 Irene Vatton <Irene.Vatton@w3.org> 
  Adaptation to redhat 8.0
* Fri Jan 30 2003 Nabil Layaida (Nabil.Layaida@inria.fr>
  Adaptation to rpmbuild
* Mon Sep 16 2002 Irene Vatton <Irene.Vatton@w3.org>
  GTK options.
* Fri Nov 9 2001  Irene Vatton <Irene.Vatton@w3.org>
  Integration of English and French dictionaries
* Mon Feb 28 2001 Irene Vatton <Irene.Vatton@w3.org>
  updated for amaya-4.2.1
* Mon Jan 8 2001 Irene Vatton <Irene.Vatton@w3.org>
  updated for amaya-4.1
* Sat Nov 11 2000 Daniel Veillard <Daniel.Veillard@w3.org>
  updated for amaya-4.0
* Tue Jul 04 2000 Daniel Veillard <Daniel.Veillard@w3.org>
  Updated for amaya-3.2
  Removed Ramzi Guetari and Daniel Veillard from authors
* Fri Jun 24 1999 Daniel Veillard <Daniel.Veillard@w3.org>
  Updated for amaya-2.1
* Fri Oct 16 1998 Daniel Veillard <Daniel.Veillard@w3.org>
  took the spec file coming from SuSE-1.3 and updated it for RedHat,
  description, license, and version 1.3b

%prep
%setup -n Amaya
# %patch
%build
export CFLAGS=
mkdir -p $RPM_BUILD_ROOT/usr/share/
autoconf
mkdir linux
cd linux
export HOME=`pwd`
../configure --with-wx --prefix=/usr/share --exec=/usr/share 
#cp Options.orig Options
#make all
make
%install
if [ -e /usr/bin/amaya ] ; then
  rm -f /usr/bin/amaya
fi
cd linux
make install prefix=$RPM_BUILD_ROOT/usr/share
# Gnome/Kde integration
./script_install_gnomekde ./bin $RPM_BUILD_ROOT/usr/share /usr/share
%files
%doc README.amaya
/usr/share/pixmaps/
/usr/share/applications/
/usr/share/Amaya-%{version}/
%post
/bin/ln -f -s /usr/share/Amaya-%{version}/wx/bin/amaya /usr/bin/amaya_wx
/bin/ln -f -s /usr/bin/amaya_wx /usr/bin/amaya
%postun
rm -f /usr/bin/amaya

