# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.4

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ismarc/kumonosu/core/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ismarc/kumonosu/core/src/build

# Include any dependencies generated for this target.
include server/CMakeFiles/kumonosu_server.dir/depend.make

# Include the progress variables for this target.
include server/CMakeFiles/kumonosu_server.dir/progress.make

# Include the compile flags for this target's objects.
include server/CMakeFiles/kumonosu_server.dir/flags.make

server/CMakeFiles/kumonosu_server.dir/depend.make.mark: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/depend.make.mark: ../server/main.cpp

server/CMakeFiles/kumonosu_server.dir/main.o: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/main.o: ../server/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ismarc/kumonosu/core/src/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/CMakeFiles/kumonosu_server.dir/main.o"
	/usr/bin/c++   $(CXX_FLAGS) -o server/CMakeFiles/kumonosu_server.dir/main.o -c /home/ismarc/kumonosu/core/src/server/main.cpp

server/CMakeFiles/kumonosu_server.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to server/CMakeFiles/kumonosu_server.dir/main.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /home/ismarc/kumonosu/core/src/server/main.cpp > server/CMakeFiles/kumonosu_server.dir/main.i

server/CMakeFiles/kumonosu_server.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly server/CMakeFiles/kumonosu_server.dir/main.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /home/ismarc/kumonosu/core/src/server/main.cpp -o server/CMakeFiles/kumonosu_server.dir/main.s

server/CMakeFiles/kumonosu_server.dir/main.o.requires:

server/CMakeFiles/kumonosu_server.dir/main.o.provides: server/CMakeFiles/kumonosu_server.dir/main.o.requires
	$(MAKE) -f server/CMakeFiles/kumonosu_server.dir/build.make server/CMakeFiles/kumonosu_server.dir/main.o.provides.build

server/CMakeFiles/kumonosu_server.dir/main.o.provides.build: server/CMakeFiles/kumonosu_server.dir/main.o

server/CMakeFiles/kumonosu_server.dir/depend.make.mark: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/depend.make.mark: ../InternalMessageProcessor.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.o: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.o: ../InternalMessageProcessor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ismarc/kumonosu/core/src/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.o"
	/usr/bin/c++   $(CXX_FLAGS) -o server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.o -c /home/ismarc/kumonosu/core/src/InternalMessageProcessor.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /home/ismarc/kumonosu/core/src/InternalMessageProcessor.cpp > server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.i

server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /home/ismarc/kumonosu/core/src/InternalMessageProcessor.cpp -o server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.s

server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.o.requires:

server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.o.provides: server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.o.requires
	$(MAKE) -f server/CMakeFiles/kumonosu_server.dir/build.make server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.o.provides.build

server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.o.provides.build: server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.o

server/CMakeFiles/kumonosu_server.dir/depend.make.mark: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/depend.make.mark: ../kumonosu_server_constants.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.o: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.o: ../kumonosu_server_constants.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ismarc/kumonosu/core/src/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.o"
	/usr/bin/c++   $(CXX_FLAGS) -o server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.o -c /home/ismarc/kumonosu/core/src/kumonosu_server_constants.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /home/ismarc/kumonosu/core/src/kumonosu_server_constants.cpp > server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.i

server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /home/ismarc/kumonosu/core/src/kumonosu_server_constants.cpp -o server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.s

server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.o.requires:

server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.o.provides: server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.o.requires
	$(MAKE) -f server/CMakeFiles/kumonosu_server.dir/build.make server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.o.provides.build

server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.o.provides.build: server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.o

server/CMakeFiles/kumonosu_server.dir/depend.make.mark: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/depend.make.mark: ../kumonosu_server_types.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.o: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.o: ../kumonosu_server_types.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ismarc/kumonosu/core/src/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.o"
	/usr/bin/c++   $(CXX_FLAGS) -o server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.o -c /home/ismarc/kumonosu/core/src/kumonosu_server_types.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /home/ismarc/kumonosu/core/src/kumonosu_server_types.cpp > server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.i

server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /home/ismarc/kumonosu/core/src/kumonosu_server_types.cpp -o server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.s

server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.o.requires:

server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.o.provides: server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.o.requires
	$(MAKE) -f server/CMakeFiles/kumonosu_server.dir/build.make server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.o.provides.build

server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.o.provides.build: server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.o

server/CMakeFiles/kumonosu_server.dir/depend.make.mark: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/depend.make.mark: ../LocalRequestManager.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.o: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.o: ../LocalRequestManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ismarc/kumonosu/core/src/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.o"
	/usr/bin/c++   $(CXX_FLAGS) -o server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.o -c /home/ismarc/kumonosu/core/src/LocalRequestManager.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /home/ismarc/kumonosu/core/src/LocalRequestManager.cpp > server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.i

server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /home/ismarc/kumonosu/core/src/LocalRequestManager.cpp -o server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.s

server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.o.requires:

server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.o.provides: server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.o.requires
	$(MAKE) -f server/CMakeFiles/kumonosu_server.dir/build.make server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.o.provides.build

server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.o.provides.build: server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.o

server/CMakeFiles/kumonosu_server.dir/depend.make.mark: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/depend.make.mark: ../LocalRequestManagerHandler.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.o: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.o: ../LocalRequestManagerHandler.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ismarc/kumonosu/core/src/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.o"
	/usr/bin/c++   $(CXX_FLAGS) -o server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.o -c /home/ismarc/kumonosu/core/src/LocalRequestManagerHandler.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /home/ismarc/kumonosu/core/src/LocalRequestManagerHandler.cpp > server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.i

server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /home/ismarc/kumonosu/core/src/LocalRequestManagerHandler.cpp -o server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.s

server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.o.requires:

server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.o.provides: server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.o.requires
	$(MAKE) -f server/CMakeFiles/kumonosu_server.dir/build.make server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.o.provides.build

server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.o.provides.build: server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.o

server/CMakeFiles/kumonosu_server.dir/depend.make.mark: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/depend.make.mark: ../OutgoingClient.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.o: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.o: ../OutgoingClient.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ismarc/kumonosu/core/src/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.o"
	/usr/bin/c++   $(CXX_FLAGS) -o server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.o -c /home/ismarc/kumonosu/core/src/OutgoingClient.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /home/ismarc/kumonosu/core/src/OutgoingClient.cpp > server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.i

server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /home/ismarc/kumonosu/core/src/OutgoingClient.cpp -o server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.s

server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.o.requires:

server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.o.provides: server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.o.requires
	$(MAKE) -f server/CMakeFiles/kumonosu_server.dir/build.make server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.o.provides.build

server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.o.provides.build: server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.o

server/CMakeFiles/kumonosu_server.dir/depend.make.mark: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/depend.make.mark: ../RemoteRequestManager.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.o: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.o: ../RemoteRequestManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ismarc/kumonosu/core/src/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.o"
	/usr/bin/c++   $(CXX_FLAGS) -o server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.o -c /home/ismarc/kumonosu/core/src/RemoteRequestManager.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /home/ismarc/kumonosu/core/src/RemoteRequestManager.cpp > server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.i

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /home/ismarc/kumonosu/core/src/RemoteRequestManager.cpp -o server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.s

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.o.requires:

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.o.provides: server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.o.requires
	$(MAKE) -f server/CMakeFiles/kumonosu_server.dir/build.make server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.o.provides.build

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.o.provides.build: server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.o

server/CMakeFiles/kumonosu_server.dir/depend.make.mark: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/depend.make.mark: ../RemoteRequestManagerHandler.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.o: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.o: ../RemoteRequestManagerHandler.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ismarc/kumonosu/core/src/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.o"
	/usr/bin/c++   $(CXX_FLAGS) -o server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.o -c /home/ismarc/kumonosu/core/src/RemoteRequestManagerHandler.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /home/ismarc/kumonosu/core/src/RemoteRequestManagerHandler.cpp > server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.i

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /home/ismarc/kumonosu/core/src/RemoteRequestManagerHandler.cpp -o server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.s

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.o.requires:

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.o.provides: server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.o.requires
	$(MAKE) -f server/CMakeFiles/kumonosu_server.dir/build.make server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.o.provides.build

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.o.provides.build: server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.o

server/CMakeFiles/kumonosu_server.dir/depend.make.mark: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/depend.make.mark: ../RemoteServer.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.o: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.o: ../RemoteServer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ismarc/kumonosu/core/src/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.o"
	/usr/bin/c++   $(CXX_FLAGS) -o server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.o -c /home/ismarc/kumonosu/core/src/RemoteServer.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /home/ismarc/kumonosu/core/src/RemoteServer.cpp > server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.i

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /home/ismarc/kumonosu/core/src/RemoteServer.cpp -o server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.s

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.o.requires:

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.o.provides: server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.o.requires
	$(MAKE) -f server/CMakeFiles/kumonosu_server.dir/build.make server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.o.provides.build

server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.o.provides.build: server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.o

server/CMakeFiles/kumonosu_server.dir/depend.make.mark: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/depend.make.mark: ../RequestQueue.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.o: server/CMakeFiles/kumonosu_server.dir/flags.make
server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.o: ../RequestQueue.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ismarc/kumonosu/core/src/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.o"
	/usr/bin/c++   $(CXX_FLAGS) -o server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.o -c /home/ismarc/kumonosu/core/src/RequestQueue.cpp

server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /home/ismarc/kumonosu/core/src/RequestQueue.cpp > server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.i

server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /home/ismarc/kumonosu/core/src/RequestQueue.cpp -o server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.s

server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.o.requires:

server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.o.provides: server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.o.requires
	$(MAKE) -f server/CMakeFiles/kumonosu_server.dir/build.make server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.o.provides.build

server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.o.provides.build: server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.o

server/CMakeFiles/kumonosu_server.dir/depend: server/CMakeFiles/kumonosu_server.dir/depend.make.mark

server/CMakeFiles/kumonosu_server.dir/depend.make.mark:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --magenta --bold "Scanning dependencies of target kumonosu_server"
	cd /home/ismarc/kumonosu/core/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ismarc/kumonosu/core/src /home/ismarc/kumonosu/core/src/server /home/ismarc/kumonosu/core/src/build /home/ismarc/kumonosu/core/src/build/server /home/ismarc/kumonosu/core/src/build/server/CMakeFiles/kumonosu_server.dir/DependInfo.cmake

# Object files for target kumonosu_server
kumonosu_server_OBJECTS = \
"CMakeFiles/kumonosu_server.dir/main.o" \
"CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.o" \
"CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.o" \
"CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.o" \
"CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.o" \
"CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.o" \
"CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.o" \
"CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.o" \
"CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.o" \
"CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.o" \
"CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.o"

# External object files for target kumonosu_server
kumonosu_server_EXTERNAL_OBJECTS =

server/kumonosu_server: server/CMakeFiles/kumonosu_server.dir/main.o
server/kumonosu_server: server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.o
server/kumonosu_server: server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.o
server/kumonosu_server: server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.o
server/kumonosu_server: server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.o
server/kumonosu_server: server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.o
server/kumonosu_server: server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.o
server/kumonosu_server: server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.o
server/kumonosu_server: server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.o
server/kumonosu_server: server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.o
server/kumonosu_server: server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.o
server/kumonosu_server: /usr/local/lib/libthrift.so
server/kumonosu_server: /usr/local/lib/libthriftnb.so
server/kumonosu_server: /usr/lib/libevent.so
server/kumonosu_server: server/CMakeFiles/kumonosu_server.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable kumonosu_server"
	cd /home/ismarc/kumonosu/core/src/build/server && $(CMAKE_COMMAND) -P CMakeFiles/kumonosu_server.dir/cmake_clean_target.cmake
	cd /home/ismarc/kumonosu/core/src/build/server && /usr/bin/c++      -fPIC $(kumonosu_server_OBJECTS) $(kumonosu_server_EXTERNAL_OBJECTS)  -o kumonosu_server -rdynamic -L/usr/local/lib -lthrift -lthriftnb -levent -Wl,-rpath,/usr/local/lib 

# Rule to build all files generated by this target.
server/CMakeFiles/kumonosu_server.dir/build: server/kumonosu_server

server/CMakeFiles/kumonosu_server.dir/requires: server/CMakeFiles/kumonosu_server.dir/main.o.requires
server/CMakeFiles/kumonosu_server.dir/requires: server/CMakeFiles/kumonosu_server.dir/__/__/InternalMessageProcessor.o.requires
server/CMakeFiles/kumonosu_server.dir/requires: server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_constants.o.requires
server/CMakeFiles/kumonosu_server.dir/requires: server/CMakeFiles/kumonosu_server.dir/__/__/kumonosu_server_types.o.requires
server/CMakeFiles/kumonosu_server.dir/requires: server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManager.o.requires
server/CMakeFiles/kumonosu_server.dir/requires: server/CMakeFiles/kumonosu_server.dir/__/__/LocalRequestManagerHandler.o.requires
server/CMakeFiles/kumonosu_server.dir/requires: server/CMakeFiles/kumonosu_server.dir/__/__/OutgoingClient.o.requires
server/CMakeFiles/kumonosu_server.dir/requires: server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManager.o.requires
server/CMakeFiles/kumonosu_server.dir/requires: server/CMakeFiles/kumonosu_server.dir/__/__/RemoteRequestManagerHandler.o.requires
server/CMakeFiles/kumonosu_server.dir/requires: server/CMakeFiles/kumonosu_server.dir/__/__/RemoteServer.o.requires
server/CMakeFiles/kumonosu_server.dir/requires: server/CMakeFiles/kumonosu_server.dir/__/__/RequestQueue.o.requires

server/CMakeFiles/kumonosu_server.dir/clean:
	cd /home/ismarc/kumonosu/core/src/build/server && $(CMAKE_COMMAND) -P CMakeFiles/kumonosu_server.dir/cmake_clean.cmake
