# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 18:58:06 by pguthaus          #+#    #+#              #
#    Updated: 2019/10/08 17:16:41 by pguthaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include make/config.mk

PRODFILE	=	make/Makefile.prod
DEVFILE		=	make/Makefile.dev

$(NAME): lib

$(DEV_NAME): dev

all: lib

lib:
	@echo "Making the static library..."
	@$(MAKE) -f $(PRODFILE)
	@echo "Static library has been created"

dev:
	@echo "Making the debugable static library..."
	@$(MAKE) -f $(DEVFILE)
	@echo "Debugable static library has been made"

devre: fclean dev

re: fclean lib

clean:
	@echo "Cleaning object files"
	@$(MAKE) -f $(PRODFILE) clean
	@$(MAKE) -f $(DEVFILE) clean
	@rm -rf objs/

fclean: clean
	@echo "Cleaning everything"
	@$(MAKE) -f $(PRODFILE) fclean
	@$(MAKE) -f $(DEVFILE) fclean

getsources:
	@rm -f $(SOURCEMAP)
	@touch $(SOURCEMAP)
	@find src/ -name "*.c" | sed  "s/src\//FT_SRCS+=/g" >> $(SOURCEMAP)