#------------------------------------------------------------------------------#
#                              PROJECT VARIABLES                               #
#------------------------------------------------------------------------------#

# Executable name
NAME	=	T4D

# Arguments to call the executable with by default
ARGS	= ./levels/map_none.cub

# Directory names
SRCDIR		=	src/
OBJDIR		=	bin/
#TSTDIR		=	tests/
#SUBDIRS		=

# Source file names (prefix their subdir if needed)
FILES	=	main \
			Tile \
			Coords \

# Libraries (.a files) to include for compilation
LIBS	=	./MLX42/build/libmlx42.a #\
			./include/T4D.hpp \

LIBX	=	-lglfw -L "/Users/$$USER/homebrew/opt/glfw/lib/"
