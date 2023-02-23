[Retour](../../)

# Installer le compilateur GCC pour compiler du code C

## Qu'est-ce que GCC ?

**GCC** est un compilateur de code de [GNU Compiler Collection](https://fr.wikipedia.org/wiki/GNU_Compiler_Collection) capable de compiler du **C** dans sa version **12.2**.

## Vérifier l'installation du compilateur GCC

Comme il est probable que vous votre environnement le possède déjà, il est nécessaire de vérifier la présence du compilateur de GCC dans votre environement.

Voici la commande pour effectuer cela :

```
gcc -v
```

### Sur Linux

**[EN COURS]**

### Sur MacOS

**[EN COURS]**

### Sur Windows

Ci-dessous, le résultat pour la présence d'une installation de GCC contenu dans le kit de développement [MinGW](https://fr.wikipedia.org/wiki/MinGW), disponible en **32** et **64** bits.

```
Using built-in specs.
COLLECT_GCC=C:\MinGW\bin\gcc.exe
COLLECT_LTO_WRAPPER=c:/mingw/bin/../libexec/gcc/mingw32/6.3.0/lto-wrapper.exe
Target: mingw32
Configured with: ../src/gcc-6.3.0/configure --build=x86_64-pc-linux-gnu --host=mingw32 --target=mingw32 --with-gmp=/mingw --with-mpfr --with-mpc=/mingw --with-isl=/mingw --prefix=/mingw --disable-win32-registry --with-arch=i586 --with-tune=generic --enable-languages=c,c++,objc,obj-c++,fortran,ada --with-pkgversion='MinGW.org GCC-6.3.0-1' --enable-static --enable-shared --enable-threads --with-dwarf2 --disable-sjlj-exceptions --enable-version-specific-runtime-libs --with-libiconv-prefix=/mingw --with-libintl-prefix=/mingw --enable-libstdcxx-debug --enable-libgomp --disable-libvtv --enable-nls
Thread model: win32
gcc version 6.3.0 (MinGW.org GCC-6.3.0-1)
```

## Installer le compilateur GCC

### Pour Linux

Pour linux, l'installation est simple, il suffit d'effectuer la commande ci-dessous.

```
apt install gcc
```

### Pour MacOS

**[EN COURS]**

### Pour Windows

Ici, nous allons installer le compilateur GCC contenu dans le kit de développement [MinGW](https://fr.wikipedia.org/wiki/MinGW), disponible en **32** et **64** bits.

Noter que celui-ci est développement pour divers OS.
Afin d'offrir une grande flexibilité,  nous allons tlélécharger et installer le kit Windows de WinLibs.com [ici *(<-- section inérieure sources)*](https://www.mingw-w64.org/downloads/#winlibscom).
Ce kit permet d'inclur des compilateurs pour **Ada**, **C**, **C++**, **Fortran**, **Obj-C**, **Obj-C++** et **Assembler**.