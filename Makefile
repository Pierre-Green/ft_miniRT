include make/config.mk

all: $(NAME)

$(NAME): bin

bin:
	@echo "Making ./$(NAME)..."
	@$(MAKE) -f $(MK_PRD)
	@echo "DONE: you may run './$(NAME)'."

dev:
	@echo "Making ./$(DEV_NAME)..."
	@$(MAKE) -f $(MK_DEV)
	@echo "DONE: you may run './$(DEV_NAME)'."

clean:
	@echo "Cleaning object files..."
	@$(MAKE) -f $(MK_PRD) clean
	@$(MAKE) -f $(MK_DEV) clean
	@echo "DONE: object files has been cleaned."

fclean: clean
	@echo "Cleaning binary executables..."
	@$(MAKE) -f $(MK_PRD) fclean
	@$(MAKE) -f $(MK_DEV) fclean
	@echo "DONE: binary executables has been cleaned."

re: fclean bin

getsources:
	@echo "Listing source files..."
	@rm -f $(SRCFILE) && touch $(SRCFILE)
	@find ./srcs -name "*.c" | sed  "s/\.\/srcs\//SRCS+=/g" >> $(SRCFILE)
	@echo "DONE: source files has been listed under '$(SRCFILE)'"
