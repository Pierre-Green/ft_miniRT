# Compilation
CC				=			gcc
CFLAGS			=			-Wall -Wextra -Werror -Iincludes -I./minilibx -Ilibft/includes
MLX_ARGS		=			minilibx/libmlx.a -lXext -lX11 -lm

# Output names
NAME			=			miniRT
DEV_NAME		=			miniRT_dev
LIBFT			=			libft/libft.a

# Srcs
SRCFILE			=			make/srcs.mk

# Dirs
SRCDIR			=			./srcs/
OUTDIR			=			./out/

# Makefiles
MK_PRD			=			make/Makefile.prod
MK_DEV			=			make/Makefile.dev
MK_LFT			=			libft
