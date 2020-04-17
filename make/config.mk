# Compilation
CC				=			gcc
CFLAGS			=			-Wall -Wextra -Werror -Iincludes -I./minilibx -Ilibft/includes
HT				=			Linux

# Output names
NAME			=			minirt
DEV_NAME		=			minirt_dev
LIBFT			=			libft/libft.a
MLX_ARGS		=			minilibx/libmlx.a -lXext -lX11 -lm

# Srcs
SRCFILE			=			make/srcs.mk

# Dirs
SRCDIR			=			./srcs/
OUTDIR			=			./out/

# Makefiles
MK_PRD			=			make/Makefile.prod
MK_DEV			=			make/Makefile.dev
MK_LFT			=			libft
