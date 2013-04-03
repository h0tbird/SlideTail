Name:         SlideTail
Version:      0.0.1
Release:      1.el6
Summary:      Sliding-window tail.
License:      GPL3
URL:          https://github.com/h0tbird/SlideTail
Source0:      %{name}-%{version}.tar.gz
Packager:     Marc Villacorta Morera <marc.villacorta@gmail.com>
BuildRoot:    %{_tmppath}/%{name}-%{version}-%{release}

%description
Concurrently tails a fixed-width sliding-window of the last 'n' files created in a given directory.
Inotify is used to monitor the directory activity.

%prep
%setup -q

%build
make

%install
make install basedir=$RPM_BUILD_ROOT

%clean
[ "$RPM_BUILD_ROOT" != "/" ] && rm -rf "$RPM_BUILD_ROOT"

%files
%defattr(-,root,root)
/usr/bin/stail
