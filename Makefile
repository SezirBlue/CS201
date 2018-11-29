.PHONY: clean All

All:
	@echo "----------Building project:[ classes - Debug ]----------"
	@cd "classes" && "$(MAKE)" -f  "classes.mk"
clean:
	@echo "----------Cleaning project:[ classes - Debug ]----------"
	@cd "classes" && "$(MAKE)" -f  "classes.mk" clean
