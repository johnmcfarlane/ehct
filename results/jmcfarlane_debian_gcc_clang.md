# Results

All results gathered from a Debian 9.4 system running in VirtualBox:

> Linux debian 4.9.0-6-amd64 #1 SMP Debian 4.9.82-1+deb9u3 (2018-03-02) x86_64 GNU/Linux

The toolchains tested are the ones that happened to be installed on the system.
Additional data points greatfully received.

## GCC

### 7.3.0

#### Pass 1

    Compiler:
    c++ (GCC) 7.3.0
    Copyright (C) 2017 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    --------
    With Exceptions and RTTI Enabled
    8344	enabled

    real	0m13.244s
    user	0m13.220s
    sys	0m0.012s
    --------
    With Exceptions and RTTI Disabled
    7936	disabled

    real	0m13.181s
    user	0m13.164s
    sys	0m0.000s

#### Pass 2

    Compiler:
    c++ (GCC) 7.3.0
    Copyright (C) 2017 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    --------
    With Exceptions and RTTI Enabled
    8344	enabled

    real	0m13.346s
    user	0m13.296s
    sys	0m0.008s
    --------
    With Exceptions and RTTI Disabled
    7936	disabled

    real	0m13.596s
    user	0m13.468s
    sys	0m0.044s

### 6.3.0

#### Pass 1

    Compiler:
    c++ (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
    Copyright (C) 2016 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    --------
    With Exceptions and RTTI Enabled
    8992	enabled

    real	0m13.183s
    user	0m13.156s
    sys	0m0.004s
    --------
    With Exceptions and RTTI Disabled
    8616	disabled

    real	0m13.190s
    user	0m13.160s
    sys	0m0.008s

#### Pass 2

    Compiler:
    c++ (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
    Copyright (C) 2016 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    --------
    With Exceptions and RTTI Enabled
    8992	enabled

    real	0m13.353s
    user	0m13.320s
    sys	0m0.012s
    --------
    With Exceptions and RTTI Disabled
    8616	disabled

    real	0m13.320s
    user	0m13.300s
    sys	0m0.008s

## Clang

### 6.0.0

#### Pass 1

    Compiler:
    clang version 6.0.0 (tags/RELEASE_600/final)
    Target: x86_64-unknown-linux-gnu
    Thread model: posix
    InstalledDir: /usr/bin
    --------
    With Exceptions and RTTI Enabled
    8760	enabled

    real	0m16.455s
    user	0m16.428s
    sys	0m0.004s
    --------
    With Exceptions and RTTI Disabled
    8264	disabled

    real	0m13.289s
    user	0m13.272s
    sys	0m0.000s

    Compiler:
    
#### Pass 2

    Compiler:
    clang version 6.0.0 (tags/RELEASE_600/final)
    Target: x86_64-unknown-linux-gnu
    Thread model: posix
    InstalledDir: /usr/bin
    --------
    With Exceptions and RTTI Enabled
    8760	enabled

    real	0m16.621s
    user	0m16.600s
    sys	0m0.008s
    --------
    With Exceptions and RTTI Disabled
    8264	disabled

    real	0m13.336s
    user	0m13.312s
    sys	0m0.004s

### 3.9.1

#### Pass 1

    Compiler:
    clang version 3.9.1-9 (tags/RELEASE_391/rc2)
    Target: x86_64-pc-linux-gnu
    Thread model: posix
    InstalledDir: /usr/bin
    --------
    With Exceptions and RTTI Enabled
    8792	enabled

    real	0m16.523s
    user	0m16.500s
    sys	0m0.004s
    --------
    With Exceptions and RTTI Disabled
    8296	disabled

    real	0m13.145s
    user	0m13.120s
    sys	0m0.008s

#### Pass 2

    Compiler:
    clang version 3.9.1-9 (tags/RELEASE_391/rc2)
    Target: x86_64-pc-linux-gnu
    Thread model: posix
    InstalledDir: /usr/bin
    --------
    With Exceptions and RTTI Enabled
    8832	enabled

    real	0m17.116s
    user	0m17.016s
    sys	0m0.040s
    --------
    With Exceptions and RTTI Disabled
    8336	disabled

    real	0m13.535s
    user	0m13.520s
    sys	0m0.000s

### 3.8.1

#### Pass 1

    Compiler:
    clang version 3.8.1-24 (tags/RELEASE_381/final)
    Target: x86_64-pc-linux-gnu
    Thread model: posix
    InstalledDir: /usr/bin
    --------
    With Exceptions and RTTI Enabled
    8896	enabled

    real	0m16.589s
    user	0m16.568s
    sys	0m0.000s
    --------
    With Exceptions and RTTI Disabled
    8400	disabled

    real	0m16.547s
    user	0m16.528s
    sys	0m0.000s

#### Pass 2

    Compiler:
    clang version 3.8.1-24 (tags/RELEASE_381/final)
    Target: x86_64-pc-linux-gnu
    Thread model: posix
    InstalledDir: /usr/bin
    --------
    With Exceptions and RTTI Enabled
    8944	enabled

    real	0m16.638s
    user	0m16.572s
    sys	0m0.008s
    --------
    With Exceptions and RTTI Disabled
    8448	disabled

    real	0m16.679s
    user	0m16.624s
    sys	0m0.008s
