#############################################################################
# Makefile for building: sudoku.app/Contents/MacOS/sudoku
# Generated by qmake (2.01a) (Qt 4.8.6) on: Wed Aug 5 09:46:35 2015
# Project:  sudoku.pro
# Template: app
# Command: /usr/local/bin/qmake -o Makefile sudoku.pro
#############################################################################

####### Compiler, tools and options

CC            = clang
CXX           = clang++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -mmacosx-version-min=10.7 -O2 -arch x86_64 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -stdlib=libc++ -mmacosx-version-min=10.7 -O2 -arch x86_64 -Wall -W $(DEFINES)
INCPATH       = -I/usr/local/Cellar/qt/4.8.6/mkspecs/unsupported/macx-clang-libc++ -I. -I/usr/local/Cellar/qt/4.8.6/lib/QtCore.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.6/lib/QtCore.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.6/lib/QtGui.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.6/lib/QtGui.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.6/include -I. -I. -I. -F/usr/local/Cellar/qt/4.8.6/lib
LINK          = clang++
LFLAGS        = -headerpad_max_install_names -stdlib=libc++ -mmacosx-version-min=10.7 -arch x86_64
LIBS          = $(SUBLIBS) -F/usr/local/Cellar/qt/4.8.6/lib -L/usr/local/Cellar/qt/4.8.6/lib -framework QtGui -L/usr/local/Cellar/qt/4.8.6/lib -F/usr/local/Cellar/qt/4.8.6/lib -framework QtCore 
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /usr/local/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.7

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = block.cpp \
		difficult.cpp \
		gline.cpp \
		judge.cpp \
		main.cpp \
		mainwindow.cpp \
		mytimer.cpp moc_block.cpp \
		moc_difficult.cpp \
		moc_mainwindow.cpp
OBJECTS       = block.o \
		difficult.o \
		gline.o \
		judge.o \
		main.o \
		mainwindow.o \
		mytimer.o \
		moc_block.o \
		moc_difficult.o \
		moc_mainwindow.o
DIST          = /usr/local/Cellar/qt/4.8.6/mkspecs/common/unix.conf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/common/mac.conf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/common/gcc-base.conf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/common/clang.conf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/qconfig.pri \
		/usr/local/Cellar/qt/4.8.6/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/qt_functions.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/qt_config.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/exclusive_builds.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/default_pre.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/default_pre.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/release.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/default_post.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/default_post.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/x86_64.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/objective_c.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/shared.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/warn_on.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/qt.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/unix/thread.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/moc.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/rez.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/sdk.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/resources.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/uic.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/yacc.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/lex.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/include_source_dir.prf \
		sudoku.pro
QMAKE_TARGET  = sudoku
DESTDIR       = 
TARGET        = sudoku.app/Contents/MacOS/sudoku

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-O2 \
		-arch \
		x86_64 \
		-Wall \
		-W


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile sudoku.app/Contents/PkgInfo sudoku.app/Contents/Resources/empty.lproj sudoku.app/Contents/Info.plist $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) sudoku.app/Contents/MacOS/ || $(MKDIR) sudoku.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: sudoku.pro  /usr/local/Cellar/qt/4.8.6/mkspecs/unsupported/macx-clang-libc++/qmake.conf /usr/local/Cellar/qt/4.8.6/mkspecs/common/unix.conf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/common/mac.conf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/common/gcc-base.conf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/common/clang.conf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/qconfig.pri \
		/usr/local/Cellar/qt/4.8.6/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/qt_functions.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/qt_config.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/exclusive_builds.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/default_pre.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/default_pre.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/release.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/default_post.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/default_post.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/x86_64.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/objective_c.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/shared.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/warn_on.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/qt.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/unix/thread.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/moc.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/rez.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/sdk.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/resources.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/uic.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/yacc.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/lex.prf \
		/usr/local/Cellar/qt/4.8.6/mkspecs/features/include_source_dir.prf \
		/usr/local/Cellar/qt/4.8.6/lib/QtGui.framework/QtGui.prl \
		/usr/local/Cellar/qt/4.8.6/lib/QtCore.framework/QtCore.prl
	$(QMAKE) -o Makefile sudoku.pro
/usr/local/Cellar/qt/4.8.6/mkspecs/common/unix.conf:
/usr/local/Cellar/qt/4.8.6/mkspecs/common/mac.conf:
/usr/local/Cellar/qt/4.8.6/mkspecs/common/gcc-base.conf:
/usr/local/Cellar/qt/4.8.6/mkspecs/common/gcc-base-macx.conf:
/usr/local/Cellar/qt/4.8.6/mkspecs/common/clang.conf:
/usr/local/Cellar/qt/4.8.6/mkspecs/qconfig.pri:
/usr/local/Cellar/qt/4.8.6/mkspecs/modules/qt_webkit_version.pri:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/qt_functions.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/qt_config.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/exclusive_builds.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/default_pre.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/default_pre.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/release.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/default_post.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/default_post.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/x86_64.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/objective_c.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/shared.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/warn_on.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/qt.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/unix/thread.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/moc.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/rez.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/mac/sdk.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/resources.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/uic.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/yacc.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/lex.prf:
/usr/local/Cellar/qt/4.8.6/mkspecs/features/include_source_dir.prf:
/usr/local/Cellar/qt/4.8.6/lib/QtGui.framework/QtGui.prl:
/usr/local/Cellar/qt/4.8.6/lib/QtCore.framework/QtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile sudoku.pro

sudoku.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) sudoku.app/Contents || $(MKDIR) sudoku.app/Contents 
	@$(DEL_FILE) sudoku.app/Contents/PkgInfo
	@echo "APPL????" >sudoku.app/Contents/PkgInfo
sudoku.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) sudoku.app/Contents/Resources || $(MKDIR) sudoku.app/Contents/Resources 
	@touch sudoku.app/Contents/Resources/empty.lproj
	
sudoku.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) sudoku.app/Contents || $(MKDIR) sudoku.app/Contents 
	@$(DEL_FILE) sudoku.app/Contents/Info.plist
	@sed -e "s,@SHORT_VERSION@,1.0,g" -e "s,@TYPEINFO@,????,g" -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,sudoku,g" -e "s,@TYPEINFO@,????,g" /usr/local/Cellar/qt/4.8.6/mkspecs/unsupported/macx-clang-libc++/Info.plist.app >sudoku.app/Contents/Info.plist
dist: 
	@$(CHK_DIR_EXISTS) .tmp/sudoku1.0.0 || $(MKDIR) .tmp/sudoku1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/sudoku1.0.0/ && $(COPY_FILE) --parents block.h difficult.h gline.h judge.h mainwindow.h mytimer.h .tmp/sudoku1.0.0/ && $(COPY_FILE) --parents block.cpp difficult.cpp gline.cpp judge.cpp main.cpp mainwindow.cpp mytimer.cpp .tmp/sudoku1.0.0/ && $(COPY_FILE) --parents mainwindow.ui .tmp/sudoku1.0.0/ && (cd `dirname .tmp/sudoku1.0.0` && $(TAR) sudoku1.0.0.tar sudoku1.0.0 && $(COMPRESS) sudoku1.0.0.tar) && $(MOVE) `dirname .tmp/sudoku1.0.0`/sudoku1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/sudoku1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r sudoku.app
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_block.cpp moc_difficult.cpp moc_mainwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_block.cpp moc_difficult.cpp moc_mainwindow.cpp
moc_block.cpp: block.h
	/usr/local/Cellar/qt/4.8.6/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ block.h -o moc_block.cpp

moc_difficult.cpp: difficult.h
	/usr/local/Cellar/qt/4.8.6/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ difficult.h -o moc_difficult.cpp

moc_mainwindow.cpp: block.h \
		gline.h \
		mytimer.h \
		difficult.h \
		judge.h \
		mainwindow.h
	/usr/local/Cellar/qt/4.8.6/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ mainwindow.h -o moc_mainwindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui
	/usr/local/Cellar/qt/4.8.6/bin/uic mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

block.o: block.cpp block.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o block.o block.cpp

difficult.o: difficult.cpp difficult.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o difficult.o difficult.cpp

gline.o: gline.cpp gline.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gline.o gline.cpp

judge.o: judge.cpp judge.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o judge.o judge.cpp

main.o: main.cpp mainwindow.h \
		block.h \
		gline.h \
		mytimer.h \
		difficult.h \
		judge.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		block.h \
		gline.h \
		mytimer.h \
		difficult.h \
		judge.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

mytimer.o: mytimer.cpp mytimer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mytimer.o mytimer.cpp

moc_block.o: moc_block.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_block.o moc_block.cpp

moc_difficult.o: moc_difficult.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_difficult.o moc_difficult.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

