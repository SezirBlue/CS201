.PHONY: clean All

All:
	@echo "----------Building project:[ hellow - Debug ]----------"
	@cd "hellow" && "$(MAKE)" -f  "hellow.mk"
clean:
	@echo "----------Cleaning project:[ hellow - Debug ]----------"
	@cd "hellow" && "$(MAKE)" -f  "hellow.mk" clean
