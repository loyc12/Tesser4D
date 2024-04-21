#------------------------------------------------------------------------------#
#                              PROJECT VARIABLES                               #
#------------------------------------------------------------------------------#

# Executable name
NAME		=	TESSER4D

# Source file names (prefix their subdir if needed)
SRCFILES	=	main \
				Ray \
				Tile \
				Screen \
				Entity \
				Coords \
				Position \

# Include directory paths
INCDIRS		=	include/ \
				include/classes/ \

# Directory names
SRCDIR		=	src/
OBJDIR		=	bin/
#TSTDIR		=	test/
#SUBDIRS	=	example/

# Libraries (.a files) to include for compilation
LIBS		=	./MLX42/build/libmlx42.a \
				-lglfw -L "/Users/$$USER/homebrew/opt/glfw/lib/" \

# Arguments to call the command with
ARGS		=

#------------------------------------------------------------------------------#
#                                    FLAGS                                     #
#------------------------------------------------------------------------------#

# Use "export XFLAGS= {flags} " to add extra compilation flags

# Flags for gcc, valgrind and leaks
CFLAGS	=	-Wall \
			-Werror \
			-Wextra \
			-Wshadow \
			-std=c++98 \
			$(XFLAGS) \

LFLAGS	=	-atExit \

VFLAGS	=	--leak-check=full \
			--show-leak-kinds=all \
			--trace-children=yes \
			--track-fds=yes \
			--error-exitcode=42 \


# Comment the line bellow to have verbose cmds:
HIDE	=	@

# Potential xflags to use :
# -g					for debug mode compilation (lldb)
# -fsanitize=thread		to see race conditions