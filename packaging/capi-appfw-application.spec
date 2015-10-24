Name:       capi-appfw-application
Summary:    An Application library in SLP C API
Version:    0.3.1.0
Release:    1
Group:		Application Framework/Libraries
License:    Apache-2.0
Source0:    %{name}-%{version}.tar.gz
BuildRequires:  cmake
BuildRequires:  pkgconfig(dlog)
BuildRequires:  pkgconfig(bundle)
BuildRequires:  pkgconfig(appcore-common)
BuildRequires:  pkgconfig(appcore-efl)
BuildRequires:  pkgconfig(aul)
BuildRequires:  pkgconfig(appsvc)
BuildRequires:  pkgconfig(elementary)
BuildRequires:  pkgconfig(alarm-service)
BuildRequires:  pkgconfig(capi-base-common)
BuildRequires:  pkgconfig(sqlite3)
BuildRequires:  pkgconfig(security-privilege-checker)
BuildRequires:  pkgconfig(pkgmgr-info)
BuildRequires:  pkgconfig(vconf-internal-keys)
BuildRequires:  pkgconfig(glib-2.0)
BuildRequires:  pkgconfig(eventsystem)

Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig

%define appfw_feature_process_pool 1

%description
An Application library in SLP C API

%package devel
Summary:  An Application library in SLP C API (Development)
Group:    TO_BE/FILLED_IN
Requires: %{name} = %{version}-%{release}

%description devel
An Application library in SLP C API (DEV)

%prep
%setup -q

%build
%if 0%{?appfw_feature_process_pool}
 _APPFW_FEATURE_PROCESS_POOL=ON
%endif

MAJORVER=`echo %{version} | awk 'BEGIN {FS="."}{print $1}'`
cmake . -DCMAKE_INSTALL_PREFIX=/usr -DFULLVER=%{version} -DMAJORVER=${MAJORVER} \
	-D_APPFW_FEATURE_PROCESS_POOL:BOOL=${_APPFW_FEATURE_PROCESS_POOL}

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install
mkdir -p %{buildroot}/usr/share/license
cp LICENSE %{buildroot}/usr/share/license/%{name}

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig


%files
%{_libdir}/libcapi-appfw-application.so.*
%{_libdir}/libcapi-appfw-app-control.so.*
%{_libdir}/libcapi-appfw-app-common.so.*
%{_libdir}/libcapi-appfw-alarm.so.*
%{_libdir}/libcapi-appfw-preference.so.*
%{_libdir}/libcapi-appfw-event.so.*
%manifest capi-appfw-application.manifest
/usr/share/license/%{name}

%files devel
%{_includedir}/appfw/*.h
%{_libdir}/pkgconfig/*.pc
%{_libdir}/libcapi-appfw-application.so
%{_libdir}/libcapi-appfw-app-control.so
%{_libdir}/libcapi-appfw-app-common.so
%{_libdir}/libcapi-appfw-alarm.so
%{_libdir}/libcapi-appfw-preference.so
%{_libdir}/libcapi-appfw-event.so

